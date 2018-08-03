# -*- coding: utf-8 -*-
"""
Spyder Editor

This temporary script file is located here:
C:\Users\lab304b\.spyder2\.temp.py
"""
import cv2
import numpy as np

## 读取图片并显示
#img = cv2.imread("ZhangYX.jpg")   
#cv2.namedWindow("Image")   
#cv2.imshow("Image", img)   
#cv2.waitKey (0)  
#cv2.destroyAllWindows() 


## 键盘监听和保存图像
#img = cv2.imread(r'ZhangYX.jpg',cv2.IMREAD_COLOR)
#cv2.namedWindow('Image',cv2.WINDOW_NORMAL)
#cv2.imshow('Image',img)
#k = cv2.waitKey(0)
#if k == 27:  #27为'ESC'键的ASCII码值
#    cv2.destroyAllWindows()
#elif k == ord('s'): #ord()函数是获取单个字符的ASCII码值
#    cv2.imwrite(r'office.jpg',img)
#    cv2.destroyAllWindows()


##读取摄像头，若想读取视频，参数0换成视频的路径+文件名
##cap = cv2.VideoCapture(0) 
#cap = cv2.VideoCapture('CADDemo.mp4') 
#
#while(True):
#    ret, frame = cap.read()
#    cv2.imshow('frame',frame)
#    if cv2.waitKey(1)== ord('q'):
#        break
#
#cap.release()
#cv2.destroyAllWindows()


### 读取和保存视频 
##cap = cv2.VideoCapture(r'CADDemo.mp4')
#cap = cv2.VideoCapture(0) 
#fourcc = cv2.VideoWriter_fourcc(*'MJPG')   
#out = cv2.VideoWriter('output.avi',\
#fourcc,20.0,(int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)),int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))))
#
#while cap.isOpened():
#    ret,frame = cap.read()
#    if ret:
#        out.write(frame)
#        cv2.imshow('frame',frame)
#        if cv2.waitKey(1) == ord('q'):
#            break
#    else:
#        break
#
#cap.release()
#out.release()
#cv2.destroyAllWindows()



## 拆分和合并彩色图像通道
#img=cv2.imread(r'ZhangYX.jpg')
#b,g,r=cv2.split(img)
#img=cv2.merge([b,g,r])


## 读取视频，从中抽取视频帧
#from matplotlib import pyplot as plt
#frames = []
#cap = cv2.VideoCapture(r'CADDemo.mp4')
#fps = cap.get(5)
#print "Frames per second using video.get(cv2.cv.CV_CAP_PROP_FPS): {0}".format(fps)
#
#for k in xrange(15):
#    ret, frame = cap.read()
#    frame=cv2.resize(frame, (224,224),interpolation=cv2.INTER_AREA)
#    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
#    frames.append(gray)
#
#    plt.imshow(gray, cmap = plt.get_cmap('gray'))
#    plt.xticks([]), plt.yticks([])  # to hide tick values on X and Y axis
#    plt.show()
#    cv2.imshow('frame',gray)
#
#    if cv2.waitKey(1) & 0xFF == ord('q'):
#        break
#cap.release()
#cv2.destroyAllWindows()
#
#input=np.array(frames)
#
#print input.shape
#ipt=np.rollaxis(np.rollaxis(input,2,0),2,0)
#print ipt.shape


# 等间隔提取视频帧
cap = cv2.VideoCapture(r'CADDemo.mp4') #读入视频文件 
c=1 
 
if cap.isOpened(): #判断是否正常打开 
  rval, frame = cap.read() 
else: 
  rval = False 
 
timeF = 100 #视频帧计数间隔频率 
 
while rval:  #循环读取视频帧 
  rval, frame = cap.read() 
  if(c%timeF == 0): #每隔timeF帧进行存储操作 
    cv2.imwrite('./frams/'+str(c) + '.jpg',frame) #存储为图像 
  c = c + 1 
  cv2.waitKey(1) 
cap.release() 













