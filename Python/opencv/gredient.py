# coding: utf-8
import cv2
from matplotlib import pyplot as plt
import numpy as np


'''''
18 图像梯度
梯度是求导，三种梯度滤波器，（高通滤波器）:Sobel,Scharr和Laplacian
SobelScharr:求一阶或二阶导数，Scharr是对Sobel(使用小的卷积核求解梯度角度时)的优化。
Laplacian:是求二阶导数
Sobel 算子是高斯平滑u微分操作的结合体，抗噪声能力很好，可以设定求导的方向(xorder或yorder)
还可以设定使用的卷积核的大小(ksize)。如果ksize=-1,会使用3*3的Scharr滤波器，它的效果要
比3*3的Sobel滤波器好，3*3的Scharr滤波器卷积核如下:
        -3  0 3
x方向   -10 0 10
        -3 0 3

        -3 -10 -3
y方向    0  0  0
         3  10 3

Laplacian算子可以使用二阶导数的形式定义，假设其
离散实现类似于二阶Sobel导数，Opencv在计算拉普拉斯算子时
直接调用Sobel算子，计算公式为

△src =∂ 2 src
∂x 2
+
∂ 2 src
∂y 2
△src = ∂2 src / ∂ x2 + ∂2 src / ∂ y2
拉普拉斯滤波器使用的卷积核

        0   1   0
kernel=1    -4  1
        0   1   0
这些算子应该是用于做边缘检测的(高频成分)

注意：使用cv2.CV_64F的原因是从白到黑的边界点导数为负数后，如果
使用的是np.int8则会变成0，把边界地市
'''
def imageGradient_test():
    img = cv2.imread("./pictures/AnYueXi.jpg", 0)

    '''''
    cv2.Laplacian(src,ddepth)
    ddepth:目标图像要求的深度
    '''
    laplacian = cv2.Laplacian(img, cv2.CV_64F)
    '''''
    cv2.Sobel(src,ddepth,dx,dy[,ksize])
    作用：计算Sobel算子
    ddpeth:输出图像的深度，比如CV_8U,CV_64F等
    dx:x的导数，dy:y方向的导数
    ksize:核的代销，必须是1,3,5或7
    '''
    sobelx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=5)
    sobely = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=5)

    plt.subplot(221), plt.imshow(img, cmap="gray"), plt.title("Original"), plt.xticks([]), plt.yticks([])
    plt.subplot(222), plt.imshow(laplacian, cmap="gray"), plt.title("Laplacian"), plt.xticks([]), plt.yticks([])
    plt.subplot(223), plt.imshow(sobelx, cmap="gray"), plt.title("Sobelx"), plt.xticks([]), plt.yticks([])
    plt.subplot(224), plt.imshow(sobely, cmap="gray"), plt.title("Sobely"), plt.xticks([]), plt.yticks([])
    plt.show()

if __name__ == "__main__":
    imageGradient_test()