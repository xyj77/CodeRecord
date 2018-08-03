# -*- coding: utf-8 -*-
"""
Created on Thu Jan 26 17:34:36 2018

@author: xyj
"""
# 兼容python显示中文
from __future__ import print_function

'''
itchat工具包基础：
#导入
import itchat 
#登陆微信
itchat.auto_login(hotReload=True) 
#确保一直在登录状态
itchat.run() 
#获取出自己之外的好友信息
itchat.get_friends()[1:] 
#获取自己的信息,第一条是自己
itchat.get_friends()[:1][0]

#发送消息,UID是好友信息中的用UserName段
itchat.send_msg("测试", UID='UserName')

给自己发送消息只需要发出消息，不指定发送者，默认发给自己(登陆者)
itchat.send_msg(‘你好’,ToUser) #发送文本消息
itchat.send_image(path,ToUser) # 发送图片
itchat.send_video(path,ToUser) #发送视频
itchat.send_file(path,ToUser) #发送文件

# 另一种发送消息的方法
itchat.send(msg='Text Message', toUserName=None)
1.msg：消息内容
2.'@fil@文件地址'将会被识别为传送文件，
  '@img@图片地址'将会被识别为传送图片，
  '@vid@视频地址'将会被识别为小视频
3.toUserName：发送对象，如果留空将会发送给自己
例如：
itchat.send('Hello world!')
# 请确保该程序目录下存在：gz.gif以及xlsx.xlsx
itchat.send('@img@%s' % 'gz.gif')
itchat.send('@fil@%s' % 'xlsx.xlsx')
itchat.send('@vid@%s' % 'demo.mp4')



# 接收消息的方法
#coding=utf8
import itchat
from itchat.content import\
    TEXT, MAP, CARD, NOTE, SHARING, PICTURE, RECORDING, ATTACHMENT, VIDEO, FRIENDS

@itchat.msg_register([TEXT, MAP, CARD, NOTE, SHARING])
def text_reply(msg):
  itchat.send('%s: %s' % (msg['Type'], msg['Text']), msg['FromUserName'])

# 以下四类的消息的Text键下存放了用于下载消息内容的方法，传入文件地址即可
@itchat.msg_register([PICTURE, RECORDING, ATTACHMENT, VIDEO])
def download_files(msg):
  msg['Text'](msg['FileName'])
  return '@%s@%s' % ({'Picture': 'img', 'Video': 'vid'}.get(msg['Type'], 'fil'), msg['FileName'])

# 收到好友邀请自动添加好友
@itchat.msg_register(FRIENDS)
def add_friend(msg):
  itchat.add_friend(**msg['Text']) # 该操作会自动将新好友的消息录入，不需要重载通讯录
  itchat.send_msg('Nice to meet you!', msg['RecommendInfo']['UserName'])

# 在注册时增加isGroupChat=True将判定为群聊回复
@itchat.msg_register(TEXT, isGroupChat = True)
def groupchat_reply(msg):
  if msg['isAt']:
    itchat.send(u'@%s\u2005I received: %s' % (msg['ActualNickName'], msg['Content']), msg['FromUserName'])

itchat.auto_login(True)
itchat.run()


# 搜索好友的方法
# 获取自己的用户信息，返回自己的属性字典
itchat.search_friends()
# 获取特定UserName的用户信息
itchat.search_friends(userName='@abcdefg1234567')
# 获取任何一项等于name键值的用户
itchat.search_friends(name='littlecodersh')
# 获取分别对应相应键值的用户
itchat.search_friends(wechatAccount='littlecodersh')
# 三、四项功能可以一同使用
itchat.search_friends(name='LittleCoder机器人', wechatAccount='littlecodersh')




'''

import itchat
Wchat = itchat.auto_login(hotReload=True)


############################################
#friends = itchat.get_friends()[1:]
## 打印好友部分信息
#for i in friends:
#    print(u'昵称:', i['NickName'])
#    print(u'备注:', i['RemarkName'])
#    print(u'个性签名:', i['Signature'])
#    print(u'城市:', i['City'])
#    print(u'性别:', i['Sex'])
#    raw_input(u'任意键继续')

## 给好友发送消息
#friend_Uid = ''
#for i in friends:
#    if i["RemarkName"] == u'王二狗':
#        print(u'已经找到好友的UID...')
#        friend_Uid = i["UserName"]
#        break
#itchat.send_msg(u'这是一条测试消息', friend_Uid)

#######################################
## 接收消息
#@itchat.msg_register(itchat.content.TEXT)
#def text_reply(msg):
#    reply_text = msg['Text']
#    print(reply_text)
#    return reply_text 

#itchat.run ()




#@itchat.msg_register(itchat.content.TEXT)
#def text_reply(msg):
#    print(u"执行")
#    reply_text = msg['Text']
#    itchat.send_image('face_rec/An1.jpg', toUserName=msg['FromUserName'])
#    print(u"发送成功")
#
#itchat.run()




##################################
# 自动回复文字信息

def output_info(msg):
  print('[INFO] %s' % msg)

#Start auto-replying
@itchat.msg_register(itchat.content.TEXT, isGroupChat = False)
def simple_reply(msg):
  userName = msg['FromUserName']
  friends = itchat.get_friends()[0:]
  remarkName = ''
  for i in friends:
    if i['UserName'] == userName:
      remarkName = i['RemarkName']
      break
  output_info('Receive message from %s'%remarkName)
  if msg['Type'] == 'Text':
    itchat.send_msg(u'[Auto Reply] I have received: \" %s \", I will contact you later.'\
                  % msg['Content'], toUserName = userName)
#    itchat.send_msg(u'[Auto Reply] I have received: \" %s \", I will contact you later.'\
#                   % msg['Content'], toUserName='filehelper')
#    return '[Auto Reply] I have received: \" %s \", I will contact you later.'\
#                     % msg['Content']

itchat.run()


# 指定对象自动回复
#
#def output_info(msg):
#  print('[INFO] %s' % msg)

# Start auto-replying
#@itchat.msg_register
#def simple_reply(msg):
#  userName = msg['FromUserName']
#  output_info('Receive message from %S'%userName)
#  friend = itchat.search_friends(userName = userName)
#  if friend["RemarkName"] == u'王二狗':
#    return 'I received: %s' % msg['Content']
#
#itchat.run()




####################################
## 显示撤回的消息
#import itchat
#from itchat.content import TEXT
#from itchat.content import *
#import time
#import re
#import os
#msg_information = {}
#face_bug=None #针对表情包的内容
## 这里的TEXT表示如果有人发送文本消息()
## TEXT  文本  文本内容(文字消息)
## MAP  地图  位置文本(位置分享)
## CARD  名片  推荐人字典(推荐人的名片)
## SHARING  分享  分享名称(分享的音乐或者文章等)
## PICTURE 下载方法    图片/表情
## RECORDING  语音  下载方法
## ATTACHMENT  附件  下载方法
## VIDEO  小视频  下载方法
## FRIENDS  好友邀请  添加好友所需参数
## SYSTEM  系统消息  更新内容的用户或群聊的UserName组成的列表
## NOTE  通知  通知文本(消息撤回等)，那么就会调用下面的方法
## 其中isFriendChat表示好友之间，isGroupChat表示群聊，isMapChat表示公众号
#@itchat.msg_register([TEXT,PICTURE,FRIENDS,CARD,MAP,SHARING,RECORDING,ATTACHMENT,VIDEO],isFriendChat=True,isGroupChat=True)
#def receive_msg(msg):
#  global face_bug
#  # print("消息是："+str(msg))
#  msg_time_rec = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) #接收消息的时间
#  # ActualNickName : 实际 NickName(昵称) 群消息里(msg)才有这个值
#  if 'ActualNickName' in msg:
#    from_user = msg['ActualUserName'] #群消息的发送者,用户的唯一标识
#    msg_from = msg['ActualNickName']#发送者群内的昵称
#    friends = itchat.get_friends(update=True)#获取所有好友
#    for f in friends:
#      if from_user == f['UserName']: #如果群消息是好友发的
#        if f['RemarkName']: # 优先使用好友的备注名称，没有则使用昵称
#          msg_from = f['RemarkName']
#        else:
#          msg_from = f['NickName']
#        break
#    groups = itchat.get_chatrooms(update=True)#获取所有的群
#    for g in groups:
#      if msg['FromUserName'] == g['UserName']:#根据群消息的FromUserName匹配是哪个群
#        group_name = g['NickName']
#        group_menbers = g['MemberCount']
#        break
#    group_name = group_name + "(" + str(group_menbers) +")"
#  #否则的话是属于个人朋友的消息
#  else:
#    if itchat.search_friends(userName=msg['FromUserName'])['RemarkName']:#优先使用备注名称
#      msg_from = itchat.search_friends(userName=msg['FromUserName'])['RemarkName']
#    else:
#      msg_from = itchat.search_friends(userName=msg['FromUserName'])['NickName'] #在好友列表中查询发送信息的好友昵称
#    group_name = ""
#  msg_time = msg['CreateTime'] #信息发送的时间
#  msg_id = msg['MsgId']  #每条信息的id
#  msg_content = None   #储存信息的内容
#  msg_share_url = None  #储存分享的链接，比如分享的文章和音乐
#  # 如果发送的消息是文本或者好友推荐
#  if msg['Type'] == 'Text' or msg['Type'] == 'Friends':
#    msg_content = msg['Text']
#  #如果发送的消息是附件、视频、图片、语音
#  elif msg['Type'] == "Attachment" or msg['Type'] == "Video" \
#      or msg['Type'] == 'Picture' \
#      or msg['Type'] == 'Recording':
#    msg_content = msg['FileName']  #内容就是他们的文件名
#    #msg_content = "F:\\weixininfo\\"+msg['FileName']
#    msg['Text'](str(msg_content))  #下载文件
#  elif msg['Type'] == 'Map':  #如果消息为分享的位置信息
#    x, y, location = re.search(
#      "<location x=\"(.*?)\" y=\"(.*?)\".*label=\"(.*?)\".*", msg['OriContent']).group(1, 2, 3)
#    if location is None:
#      msg_content = r"纬度->" + x.__str__() + " 经度->" + y.__str__()   #内容为详细的地址
#    else:
#      msg_content = r"" + location
#  elif msg['Type'] == 'Sharing':   #如果消息为分享的音乐或者文章，详细的内容为文章的标题或者是分享的名字
#    msg_content = msg['Text']
#    msg_share_url = msg['Url']    #记录分享的url
#  face_bug = msg_content
#  #将信息存储在字典中，每一个msg_id对应一条信息
#  time.sleep(2)
#  msg_information.update(
#    {
#      msg_id: {
#        "msg_from": msg_from,
#        "msg_time": msg_time,
#        "msg_time_rec": msg_time_rec,
#        "msg_type": msg["Type"],
#        "msg_content": msg_content,
#        "msg_share_url": msg_share_url,
#        "group_name":group_name
#      }
#    }
#  )
#  #自动删除130秒之前的消息，避免数据量太大后引起内存不足
#  del_info = []
#  for k in msg_information:
#    m_time = msg_information[k]['msg_time'] #取得消息时间
#    if int(time.time()) - m_time > 130:
#      del_info.append(k)
#  if del_info:
#    for i in del_info:
#      msg_information.pop(i)
##监听是否有消息撤回
#@itchat.msg_register(NOTE,isFriendChat=True,isGroupChat=True,isMpChat=True)
#def information(msg):
#  #如果这里的msg['Content']中包含消息撤回和id，就执行下面的语句
#  if '撤回了一条消息' in msg['Content']:
#    old_msg_id = re.search("\<msgid\>(.*?)\<\/msgid\>", msg['Content']).group(1) #在返回的content查找撤回的消息的id
#    old_msg = msg_information.get(old_msg_id)  #获取到消息原文,类型：字典
#    print(old_msg)
#    if len(old_msg_id)<11: #如果发送的是表情包
#      itchat.send_file(face_bug,toUserName='filehelper')
#    else: #发送撤回的提示给文件助手
#      msg_body = old_msg['group_name'] + old_msg['msg_from'] +"\n" + old_msg['msg_time_rec'] \
#            + "撤回了:" + "\n" + r"" + old_msg['msg_content']
#      #如果是分享的文件被撤回了，那么就将分享的url加在msg_body中发送给文件助手
#      if old_msg['msg_type'] == "Sharing":
#        msg_body += "\n链接是:" + old_msg.get('msg_share_url')
#      #print(msg_body)
#      itchat.send_msg(msg_body, toUserName='filehelper')#将撤回消息发给文件助手
#      #有文件的话也要将文件发送回去
#      if old_msg["msg_type"] == "Picture" \
#          or old_msg["msg_type"] == "Recording" \
#          or old_msg["msg_type"] == "Video" \
#          or old_msg["msg_type"] == "Attachment":
#        file = '@fil@%s' % (old_msg['msg_content'])
#        itchat.send(msg=file, toUserName='filehelper')
#        os.remove(old_msg['msg_content'])
#      msg_information.pop(old_msg_id)# 删除字典旧消息
#itchat.auto_login(hotReload=True,enableCmdQR=1)
#itchat.run()





#import random
#import time
#import sys
#import itchat#需要安装itchat包，可直接 pip install itchat
#from itchat.content import *
#
#def main(): 
#    itchat.auto_login(True)
#    friendList = itchat.get_friends(update=True)[1:]
#    terms=[0]*len(friendList)
#    uns=[]
#    for f in friendList:
#        uns.append(f['UserName'])
#    def autoreply():
#        wishlist=[u'鸡年大吉!',u'[鸡]',u'财源滚滚!',u'[微笑]',u'[红包]',u'谢谢,',u'[强]',u'[呲牙]']
#        @itchat.msg_register(TEXT)
#        def text_reply(msg):
#            if terms[uns.index(msg['FromUserName'])]==0:#第一轮对话
#                print (friendList[uns.index(msg['FromUserName'])]['DisplayName'] or friendList[uns.index(msg['FromUserName'])]['NickName']),'term 0',':',msg['Text']
#                terms[uns.index(msg['FromUserName'])]=1
#                ts=random.randint(5,30)
#                text=u'谢谢![呲牙][强]'#第一轮对话回复文本
#                while ts:
#                    time.sleep(1.)
#                    ts=ts-1
#                    print u'将在%s秒后自动回复内容:%s \r'%(str(ts),text),
#                    sys.stdout.flush()
#                return text
#            elif  terms[uns.index(msg['FromUserName'])]==1:#第二轮对话
#                print (friendList[uns.index(msg['FromUserName'])]['DisplayName'] or friendList[uns.index(msg['FromUserName'])]['NickName']),'term 1',':',msg['Text']
#                terms[uns.index(msg['FromUserName'])]=2
#                ts=random.randint(5,30)
#                text=u'[福][红包][鸡]'
#                while ts:
#                    time.sleep(1.)
#                    ts=ts-1
#                    print u'将在%s秒后自动回复内容:%s \r'%(str(ts),text),
#                    sys.stdout.flush()
#                return text
#            elif terms[uns.index(msg['FromUserName'])]>=2 and terms[uns.index(msg['FromUserName'])]<=4:#第n轮对话，根据wishlist随机组合回复内容,大于5轮就闭嘴
#                terms[uns.index(msg['FromUserName'])]=terms[uns.index(msg['FromUserName'])]+1
#                print 'term N',msg['FromUserName'],':',msg['Text']
#                wish=u''
#                for i in range(random.randint(0,5)):#长度随机
#                    wish=wish+wishlist[random.randint(0,7)]
#                print  wish
#                ts=random.randint(5,30)
#                while ts:
#                    time.sleep(1.)
#                    ts=ts-1
#                    print u'将在%s秒后自动回复内容:%s \r'%(str(ts),wish),
#                    sys.stdout.flush()
#                    
#                return wish
#        
#    autoreply()
#    itchat.run()                
#            
#if __name__=='__main__':
#    main()  


          