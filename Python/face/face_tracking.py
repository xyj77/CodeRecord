import cv2
import dlib
detector=dlib.get_frontal_face_detector()
win=dlib.image_window()
pre=dlib.shape_predictor("shape_predictor_68_face_landmarks.dat")
cap=cv2.VideoCapture(0)
while cap.isOpened():
    ret,img=cap.read()
    if img is None:
        break
    img=cv2.cvtColor(img,cv2.COLOR_RGB2BGR)
    dets=detector(img,0)
    shapes=[]
    for i,d in enumerate(dets):
        shape=pre(img,d)
        shapes.append(shape)

    win.clear_overlay()
    win.set_image(img)
    if len(shapes)!=0:
        for i in range(len(shapes)):
            win.add_overlay(shapes[i])
            win.add_overlay(dets)
cap.release()
