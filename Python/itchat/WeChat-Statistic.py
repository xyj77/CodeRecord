# -*- coding: utf-8 -*-
"""
Created on Sat Jul 28 13:02:34 2018

@author: xyj
"""

#####################
## 统计好友男女比例
## 显示好友签名词云图

import itchat
import re
import jieba


def echart_pie(friends):
    total = len(friends) - 1
    male = female = other = 0

    for friend in friends[1:]:
        sex = friend["Sex"]
        if sex == 1:
            male += 1
        elif sex == 2:
            female += 1
        else:
            other += 1
    from pyecharts import Pie
    pie = Pie('微信好友性别比例', 'from WeChat')
    pie.add("", ['male', 'female', 'others'],\
    [(float(male) / total * 100), (float(female) / total * 100), (float(other) / total * 100)],\
    is_label_show=True)
#    pie.show_config()
    pie.render()


def word_cloud(friends):
    import matplotlib.pyplot as plt
    from wordcloud import WordCloud, ImageColorGenerator
    import PIL.Image as Image
    import numpy as np
    my_coloring = np.array(Image.open("mask.jpg"))
    signature_list = []
    for friend in friends:
        signature = friend["Signature"].strip()
        signature = re.sub("<span.*>", "", signature)
        signature_list.append(signature)
    raw_signature_string = ''.join(signature_list)
    text = jieba.cut(raw_signature_string, cut_all=True)
    target_signatur_string = ' '.join(text)

    my_wordcloud = WordCloud(background_color="white", max_words=2000, mask=my_coloring,
                             max_font_size=40, random_state=42,
                             font_path=r"C:\Windows\Fonts\simhei.ttf").generate(target_signatur_string)
    image_colors = ImageColorGenerator(my_coloring)
    plt.imshow(my_wordcloud.recolor(color_func=image_colors))
    plt.imshow(my_wordcloud)
    plt.axis("off")
    plt.show()
    # 保存图片 并发送到手机
    my_wordcloud.to_file("wechat_cloud.png")
    itchat.send_image("wechat_cloud.png", 'filehelper')


itchat.auto_login(hotReload=True)
itchat.dump_login_status()

friends = itchat.get_friends(update=True)[:]

echart_pie(friends)

word_cloud(friends)