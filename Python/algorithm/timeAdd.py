#-*- coding:utf-8 -*- 
''' 
ʵ��ʱ�䣺ʱ:��:��  ��ӣ�Сʱ��24����
���룺
09:00:59
01:01:01 

�����
10:02:00 
'''
def t2s(t):  #��ʱ��ת������ 
    h,m,s = t.strip().split(":")
    return int(h) * 3600 + int(m) * 60 + int(s)
 
st = input() #ʱ��1 
et = input() #ʱ��2 

stn = t2s(st)
etn = t2s(et)

m, s = divmod(stn+etn, 60)
h, m = divmod(m, 60)
h = h % 24
print ("%02d:%02d:%02d" % (h, m, s))
