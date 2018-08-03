# -*- coding: utf-8 -*-

from PIL import Image
import glob,os

#图片批处理
def timage():
    for files in glob.glob(u'E:\XYJ125\DataSet\BU_3DFE\*.bmp'):
        filepath,filename = os.path.split(files)
        filterame,exts = os.path.splitext(filename)
        #输出路径
        opfile = u'E:\XYJ125\DataSet\BU_3DFEjpg//'
        #判断opfile是否存在，不存在则创建
        if (os.path.isdir(opfile)==False):
            os.mkdir(opfile)
        im = Image.open(files)
        w,h = im.size
        im_ss = im.resize((128,128))
        #im_ss = im.convert('P')
        #im_ss = im.resize((int(w*0.12), int(h*0.12)))
        im_ss.save(opfile+filterame+'.jpg')

if __name__=='__main__':
    timage()
    print u'批量图片处理完成'