#-*- coding:utf-8 -*- 
''' 
实现时间：时:分:秒  相加，小时用24进制
输入：
09:00:59
01:01:01 

输出：
10:02:00 
'''
def t2s(t):  #将时间转换成秒 
    h,m,s = t.strip().split(":")
    return int(h) * 3600 + int(m) * 60 + int(s)
 
st = input() #时间1 
et = input() #时间2 

stn = t2s(st)
etn = t2s(et)

m, s = divmod(stn+etn, 60)
h, m = divmod(m, 60)
h = h % 24
print ("%02d:%02d:%02d" % (h, m, s))
