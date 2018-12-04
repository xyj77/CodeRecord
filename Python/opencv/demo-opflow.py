# coding:utf-8
from PIL import ImageGrab
import numpy as np
import cv2
import time


lk_params = dict( winSize  = (15, 15),
                  maxLevel = 2,
                  criteria = (cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 10, 0.03))

track_len = 10
detect_interval = 5
tracks = []
frame_idx = 0
#time.sleep(10)
while(True):
    #bbox specifies specific region (bbox= x,y,width,height *starts top-left)
    #把原来的调用摄像头改成屏幕截图了，其实这样子看不出光流的效果，只是我的具体应用里有需求
    img = ImageGrab.grab(bbox=(600,300,800,500))

    #this is the array obtained from conversion
    img_np = np.array(img)#转化为np数组
    frame_gray = cv2.cvtColor(img_np, cv2.COLOR_BGR2GRAY)
    vis = img_np.copy()


    # 原来的goodfeature改成了fastfeature,为了提高效率
    fast = cv2.FastFeatureDetector_create()

    value_x=[]
    if len(tracks) > 0:#检测到角点后进行光流跟踪
        img0, img1 = prev_gray, frame_gray

        p0 = np.float32([tr[-1] for tr in tracks]).reshape(-1, 1, 2)

        #自己写的一段角点筛选代码，具体意义忘了
        for i in range(0,len(p0)):
            temp=10
            for j in range(i+1,len(p0)):
                distance_x=abs(p0[i][0][0]-p0[j][0][0])
                if distance_x<temp:
                    temp=distance_x
            if temp==10:
                value_x.append(p0[i])


        new_value_x=np.float32([tr[-1] for tr in value_x]).reshape(-1, 1, 2)
        new_p1, st, err = cv2.calcOpticalFlowPyrLK(img0, img1, new_value_x, None, **lk_params)
        new_p0r, st, err = cv2.calcOpticalFlowPyrLK(img1, img0, new_p1, None, **lk_params)
        new_d = abs(new_value_x-new_p0r).reshape(-1, 2).max(-1)#得到角点回溯与前一帧实际角点的位置变化关系
        mean=np.mean(new_d)

        p1, st, err = cv2.calcOpticalFlowPyrLK(img0, img1, p0, None, **lk_params)
        p0r, st, err = cv2.calcOpticalFlowPyrLK(img1, img0, p1, None, **lk_params)

        d = abs(p0-p0r).reshape(-1, 2).max(-1)#得到角点回溯与前一帧实际角点的位置变化关系

        good = d <=0.5* mean#判断d内的值是否小于1，大于1跟踪被认为是错误的跟踪点

        new_tracks = []

        for tr, (x, y), good_flag in zip(tracks, p1.reshape(-1, 2), good):#将跟踪正确的点列入成功跟踪点
            if not good_flag:
                continue
            tr.append((x, y))
            if len(tr) > track_len:
                del tr[0]
            new_tracks.append(tr)
            cv2.circle(vis, (x, y), 2, (0, 255, 0), -1)
        tracks = new_tracks
        #cv2.polylines(vis, [np.int32(tr) for tr in tracks], False, (0, 255, 0))

    if frame_idx % detect_interval == 0:#每5帧检测一次特征点
        p = fast.detect(frame_gray,  None)# fast角点检测
        lenght_p=len(p)
        if p is not None:
            for i in range(0,lenght_p):
                tracks.append([ p[i].pt])#将检测到的角点放在待跟踪序列中

    frame_idx += 1
    prev_gray = frame_gray
    cv2.imshow('lk_track', vis)
    ch = 0xFF & cv2.waitKey(1)
    if ch == 27:
        break


cv2.destroyAllWindows()