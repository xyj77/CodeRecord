# -*- coding: utf-8 -*-
"""
Created on Thu Jul 26 20:59:07 2018
蔡勒（Zeller）公式，是一个计算星期的公式，随便给一个日期，就能用这个公式推算出是星期几
蔡勒公式只适合于1582年（中国明朝万历十年）10月15日之后的情形。
罗马教皇格里高利十三世在1582年组织了一批天文学家，根据哥白尼日心说计算出来的数据，对儒略历作了修改。
将1582年10月5日到14日之间的10天宣布撤销，继10月4日之后为10月15日。
后来人们将这一新的历法称为“格里高利历”，也就是今天世界上所通用的历法，简称格里历或公历。

1582年10月4日后：
    w=y+[y/4]+[c/4]-2c+[26(m+1）/10]+d-1
    w = w MOD 7 如果w为负数，则 w = (w%7 +7) % 7
	 
其中：
w：星期； w对7取模得：0-星期日，1-星期一，2-星期二，3-星期三，4-星期四，5-星期五，6-星期六
c：世纪（注：在公式中取值为已经过的世纪数，也就是年份除以一百的结果，而不是正在进行的世纪，不需要加1）
y：年（后两位数）
m：月（m大于等于3，小于等于14，即在蔡勒公式中，某年的1、2月要看作上一年的13、14月来计算，比如2003年1月1日要看作2002年的13月1日来计算）
d：日
[ ]代表取整，即只要整数部分。

@author: xyj
"""

# 计算星期
def getWeekDate(*args):
    year,month,day = args
    year = int(year)
    year = year - int(year / 100) * 100    
    century = int(year/100)
    month = int(month)
    if month == 1 or month == 2:
        month = month + 12
        if year == 0:
            year = 99
            century = century - 1
        else:
            year = year - 1
    day =int(day)
    week = year + int(year/4) + int(century/4) - 2 * century + int(26 * (month + 1)/10) + day - 1
    if week < 0:
        weekDay = (week % 7 + 7) % 7
    else:
        weekDay = week % 7
    return weekDay
 
d = ["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"] 
date = raw_input(u'输入年份月份天数，以空格分割：')
year,month,day = date.split(' ')
print d[getWeekDate(year,month,day)]