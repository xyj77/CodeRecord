import os
import imghdr
import shutil
import matplotlib
from matplotlib import pyplot as plt
from PIL import Image
import PIL 
import numpy as np
import hashlib
import filecmp 
import cv2
import math,csv,sklearn 
import scipy.io as sio
#0.17
from sklearn.cross_validation import train_test_split
#0.18 sklearn.cross_validation.train_test_split
#0.20 sklearn.model_selection.train_test_split
matplotlib.rcParams['font.sans-serif'] = ['SimHei']
matplotlib.rcParams['axes.unicode_minus'] = False
class FileHelper(object):
	def __init__(self):
		self.index=26148
		self.moveindex=0
		self.basepath="G:/pyproject/scrapy/selfie/img/";
		self.movebasepath="G:/pyproject/scrapy/selfie/lastimage/";
		self.duplicatebasepath="G:/pyproject/scrapy/selfie/image/duplicate/";
		self.duplicateindex=0
		self.collection={}

	def retest(self,pattern_text,text):
		pattern=re.compile(pattern_text)
		match=pattern.search(text)
		if match:
			print(match.group())
	def getFilename(self,suffix=".txt"):
		self.index=self.index+1
		filename=self.basepath+str(self.index)+suffix;
		while(os.path.exists(filename)):
			self.index=self.index+1
			filename=self.basepath+str(self.index)+suffix;
		return filename
	def getMoveFilename(self,suffix):
		self.moveindex=self.moveindex+1
		filename=self.movebasepath+str(self.moveindex)+suffix;
		while(os.path.exists(filename)):
			self.moveindex=self.moveindex+1
			filename=self.movebasepath+str(self.moveindex)+suffix;
		return filename
	def getDuplicateFilename(self,suffix):
		self.duplicateindex=self.moveindex+1
		filename=self.duplicatebasepath+str(self.duplicateindex)+suffix;
		while(os.path.exists(filename)):
			self.duplicateindex=self.duplicateindex+1
			filename=self.duplicatebasepath+str(self.duplicateindex)+suffix;
		return filename


	def pathjoin(self,first_path,second_path):
		if first_path[-1]=='/'and second_path[0]=='/':
			return first_path+second_path[1:]
		if first_path[-1]!='/'and second_path[0]!='/':
			return first_path+"/"+second_path
		else:
			return first_path+second_path
	def oswalk(self,fold):
		for parent,dirnames,filenames in os.walk(fold):
			for dirname in  dirnames:
				self.oswalkfold(os.path.join(parent,dirname) )
			for filename in filenames:  
				self.oswalkfile(os.path.join(parent,filename))
	def oswalkfile(self,filename):
		suffix=imghdr.what(filename)
		if(suffix):
			shutil.move(filename,self.getFilename("."+suffix))
		pass
	def oswalkfold(self,fold):
		helper.oswalk(fold);
		pass
	def oswalkmove(self,fold):
		for parent,dirnames,filenames in os.walk(fold):
			for filename in filenames:
				self.filemove(os.path.join(parent,filename))
	def filemove(self,filename):
		suffix=imghdr.what(filename)
		if(suffix):
			shutil.move(filename,self.getMoveFilename("."+suffix))
	def createFold(self,fold):
		if not os.path.exists(fold):
			os.mkdir(fold)
	def oswalkRemoveDemo(self):
		fold="G:/pyproject/scrapy/selfie/image/lastimage"
		destfold="G:/pyproject/scrapy/selfie/image/faceimage"
 		destfoldnouse="G:/pyproject/scrapy/selfie/image/faceimage_no"
 		self.createFold(destfold)
		self.createFold(destfoldnouse)
 		self.oswalkRemove(fold,destfold,destfoldnouse)
 	def oswalkRemove(self,fold,destfold,destfoldnouse):
 		metaFile=os.path.join(destfold,"meta.txt")
 		if os.path.exists(metaFile):
	 		file_object=open(metaFile,"r")
	 		list_of_all_the_lines = file_object.readlines()
	 		for line in list_of_all_the_lines:
	 			lines=line.split(" ")
	 			self.collection[lines[0]]=lines[1]
	 		file_object.close()
	 	else:
	 		file_object=open(metaFile,"w")
	 		file_object.close()
	 	file_object=open(metaFile,"w+")
	 	for parent,dirnames,filenames in os.walk(fold):
			for filename in filenames:  
				image_file = open(os.path.join(parent,filename)).read()
				md5=hashlib.md5(image_file).hexdigest()	
				if self.collection.has_key(md5):
					if filecmp.cmp(os.path.join(parent,filename),  os.path.join(destfold, self.collection[md5])):
						self.moveTo(os.path.join(parent,filename),destfoldnouse)
						self.moveTo(os.path.join(parent,self.collection[md5]),destfoldnouse)	
						print(filename, self.collection[md5])					 
					else:
						self.moveTo(os.path.join(parent,filename),destfold)
				else:
					self.collection[md5]=filename
					file_object.write(md5+" "+filename+"\r\n")
					self.moveTo(os.path.join(parent,filename),destfold)
		file_object.close()
	def oswalkReszieImage(self,fold,destFold,size=(100,100)):
		self.createFold(destFold)
		for parent,dirnames,filenames in os.walk(fold):
			for filename in filenames:  
				image_file = os.path.join(parent,filename)
				self.resizeImage(parent,filename,destFold,size)
	def resizeImage(self,parent,filename,destFold ,size):
		destFilename=os.path.join(destFold,filename)
		im = Image.open(os.path.join(parent,filename))
		im.thumbnail(size)
		im.save(destFilename)
		if(im.size[0]!=size[0] or im.size[1]!=size[1]):
			point=[0,0]
			newImage=Image.new("RGBA",size,(255,255,255))
			if im.size[0]!=size[0]:
				point[0]=(size[0]-im.size[0])/2
			else:
				point[1]=(size[1]-im.size[1])/2
			newImage.paste(im,(point[0],point[1]))
			newImage.save(destFilename)
	def demoOswalkReszieImage(self):
		fold="G:/pyproject/scrapy/selfie/image/last"
		destfold="G:/pyproject/scrapy/selfie/image/result"
		self.oswalkReszieImage(fold,destfold)
	
	def oswalkIndexFile(self,fold,destFold):
		self.createFold(destFold)
		index=1
		for parent,dirnames,filenames in os.walk(fold):
			for filename in filenames: 
				destFilename = os.path.join(destFold,str(index)+os.path.splitext(filename)[1])
				shutil.move(os.path.join(parent,filename),destFilename)
				index=index+1

	def oswalkIndexFileDemo(self):
		fold="G:/pyproject/scrapy/selfie/image/last"
		destFold="G:/pyproject/scrapy/selfie/image/result1"
		self.oswalkIndexFile(fold,destFold)

	def showDemo(self):
		helper=FileHelper()
		index=["1.jpeg","2.jpeg","3.jpeg","4.jpeg","5.jpeg","6.jpeg"]
		baseurl="G:/pyproject/scrapy/selfie/image/result/"
		images=[]
		for filename in index:
			image=Image.open(baseurl+filename)
			images.append(image)
		fig = plt.figure()
		for i in xrange(3):
			for j in xrange(2):
				ax=fig.add_subplot(3,2,i*2+j+1) 
				ax.imshow(images[i*2+j])
		plt.show()  
	def cake(self,labels,X,title):
		flg=plt.figure()
		colors = ['red','yellowgreen' ]
		plt.pie(X,labels=labels,colors=colors,shadow = False, autopct="%1.2f%%")
		plt.title(title)
		plt.axis('equal')
		plt.show()
	def democake(self):
		X=[8812,8812-7329]
		labels=[u"候选样本",u"重复样本"]
		title=u"重复样本比例"
		
		X=[4405, 6810-4405]
		labels=[u"检测有效样本",u"检测无效样本"]
		title=u"人脸检测"
		
		self.cake(labels,X,title)
	def detectFaces(self,img,xml_path):
		face_cascade = cv2.CascadeClassifier(xml_path)
		result = []
		if(img.ndim==3):
			gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
		else:
			gray = img
		faces = face_cascade.detectMultiScale(gray, 1.2, 5)#1.3和5是特征的最小、最大检测窗口，它改变检测结果也会改变

		for (x,y,width,height) in faces:
			result.append((x,y,x+width,y+height))

		return result
	def findFace(self,filename):
		xmls=["haarcascade_frontalface_default.xml","haarcascade_frontalface_alt.xml","haarcascade_frontalface_alt2.xml","haarcascade_frontalface_alt_tree.xml"]
		xmls=["haarcascade_eye.xml"]
		xmls=["haarcascade_mcs_mouth.xml"]
		xmls=["haarcascade_mcs_nose.xml"]
		for xml in xmls:		
			xml_path="./data/"+xml
			img=cv2.imread(filename)
			if img is not None:
				return self.detectFaces(img,xml_path)
			else:
				print("=========="+filename)
		return []
	def detectFacesFold(self,fold,destFold):
		count={}
		self.createFold(destFold)
		for parent,dirnames,filenames in os.walk(fold):
			for dirname in  dirnames:
				self.detectFacesFold(os.path.join(parent,dirname) )
			for filename in filenames:
				l=len(self.findFace(os.path.join(parent,filename)))
				if count.has_key(l):
					count[l]=count[l]+1
				else:
					count[l]=1
				if  l>0:
					self.moveTo(os.path.join(parent,filename),destFold)
					print(filename)
		print(count)
	def moveTo(self,filename,destFold):
		if(os.path.exists(filename)):
			destFilename=os.path.join(destFold,os.path.basename(filename))
			shutil.move(filename,destFilename)
	def filterImage(self,fold,width,height,destFold):
		print("filterImage")
		for parent,dirnames,filenames in os.walk(fold):
			for filename in filenames:
				image=Image.open(os.path.join(parent,filename))
				size=image.size
				image.close()
				if(size[0]>300 and size[1]>300):
					self.moveTo(os.path.join(parent,filename),destFold)

	def filterImageDemo(self):
		fold="G:/pyproject/scrapy/selfie/img"
		destFold="G:/pyproject/scrapy/selfie/lastimage"
		self.filterImage(fold,300,300,destFold)
	def combineImage(self,filenames,scores=None):
		images = map(Image.open,  filenames)
		length=len(filenames)
		if length==0:
			return 
		size=images[0].size
		w=int(math.ceil(math.sqrt(length)))
		h=int(math.ceil(length/w))
		x=0
		y=0
		
		new_im = Image.new('RGB', (w*(size[0]+1)+1, h*(size[1]+1)+1))
		index=0
		for i in xrange(h):
			flag=False
			for j in xrange(w):
				new_im.paste(images[index], (1+(1+size[0])*i , 1+(1+size[1])*j ))
				index=index+1
				if index>=len(images):
					flag=True
					break
			if flag:
				break
		new_im.save('test.jpeg')
		plt.imshow(new_im)
		index=0
		for x in xrange(h):
			for y in xrange(w):
				if scores:
					plt.text(45+x*101,20+101*y,str(scores[index]),color='red',fontsize=20)
					index=index+1
		plt.savefig('test1.jpeg')
		plt.show()

	def combineImageDemo(self):
		images=[]
		scores=[5,3,7,7,6,6,8,5,1,3,2,6,6,8,6,5,6,6,9,9,6,5,8,1,5]
		print(len(scores))
		baseurl="G:/pyproject/HelloWorld/HelloWorld/static/image/result/"
		for x in xrange(25):
			images.append(baseurl+str(x+1)+".jpeg")
		self.combineImage(images,scores)

	def getImageFrom(self,id):
		baseurl="G:/pyproject/HelloWorld/HelloWorld/static/image/result/"
		image_filename=baseurl+id+".jpeg"
		if (os.path.exists(image_filename)):
			return image_filename
		image_filename=baseurl+id+".png"
		if (os.path.exists(image_filename)):
			return image_filename
		return None
	def showImage(self,data):
		plt.imshow(data,cmap=plt.gray());
		plt.show()
	def showbarchart(self,X,Y):
		fig = plt.figure()  
		rects=plt.bar(left=X, height=Y,width=0.5,color="blue",align="center")  
 
		plt.xlabel(u"分数")  
		plt.ylabel(u"自拍图像数量")  
		names=[]
		for i  in X:
			names.append(str(i))
		plt.xticks(X,names)
		def autolabel(rects):
			for rect in rects:
				height = rect.get_height()
				plt.text(rect.get_x()-0.1+rect.get_width()/2., 1.02*height, '%s' %  int(height))
		autolabel(rects)
		plt.title("")
		plt.savefig("barChart.jpg")	  
		plt.show()    
		  
	def showbarchartDemo(self):
		X=[1,2,3]
		Y=[2,3,6]
		self.showbarchart(X,Y)
	def csv2data(self,filename):
		img_size=(100,100)
		data_x=np.zeros((1458,img_size[0]*img_size[1]))
		data_y=np.zeros((1458,))
		with open(filename) as csvfile:
			csvreader=csv.DictReader(csvfile)
			for row in csvreader:
				image_filename=self.getImageFrom(row["image_id"])
				img=Image.open(image_filename).convert('L')
				data = np.asarray(img)
				data_x[csvreader.line_num-2,:]=data.reshape(img_size[0]*img_size[1])
				data_y[csvreader.line_num-2]=np.ceil(float(row["score"]))
		data_x=data_x/255
		print(sklearn.__version__)
		train_x,test_x,train_y,test_y=train_test_split(data_x,data_y,test_size=0.2)
		sio.savemat('selfie.mat', {'train_x': train_x,'train_y': train_y,'test_x': test_x,'test_y': test_y})
		dict={}
		for i in xrange(10):
			dict[i+1]=0
		for i in xrange(1458):
			dict[data_y[i]]=dict[data_y[i]]+1
		print(dict)
		print(dict.keys())
		self.showbarchart(dict.keys(),dict.values())	
	def demoBar(self):
		n_groups = 5

		ACC = (82.88,82.88,82.53,83.22,83.56)
		SENSITIVE = (100.00,100.00,99.17,100.00,100.00)
		SPECIFICITY = (0,0.5,2.00,2.00,4.00)
		P = (82.88,82.88,83.04,83.16,83.45)
		R = (100,100.00,99.27,100.00,100.00)
		F1 = (90.64,90.64,90.40,90.81,90.98)
 

		fig, ax = plt.subplots()

		index = np.arange(n_groups)
		#bar_width = 0.35
		bar_width = 0.14

		opacity = 1.0
		error_config = {'ecolor': '0.2'}

		rects1 = plt.bar(index, ACC, bar_width,
		                 alpha=opacity,
		                 color='b',
		                 #yerr=std_men,
		                 error_kw=error_config,
		                 label='Men')

		rects2 = plt.bar(index + bar_width, SENSITIVE, bar_width,
		                 alpha=opacity,
		                 color='r',
		                 #yerr=std_women,
		                 error_kw=error_config,
		                 label='Women')

		rects3 = plt.bar(index+bar_width*2, SPECIFICITY, bar_width,
		                 alpha=opacity,
		                 color='c',
		                 #yerr=std_men,
		                 error_kw=error_config,
		                 label='Men')

		rects4 = plt.bar(index+bar_width*3, P, bar_width,
		                 alpha=opacity,
		                 color='g',
		                 #yerr=std_men,
		                 error_kw=error_config,
		                 label='Men')
		rects5 = plt.bar(index+bar_width*4, R, bar_width,
		                 alpha=opacity,
		                 color='#fec615',
		                 #yerr=std_men,
		                 error_kw=error_config,
		                 label='Men')
		rects6 = plt.bar(index+bar_width*5, F1, bar_width,
		                 alpha=opacity,
		                 color='#12e193',
		                 #yerr=std_men,
		                 error_kw=error_config,
		                 label='Men')

		#plt.xlabel(u'题号')
		#plt.ylabel(u'人数')
		#plt.title(u'答题结果统计')
		plt.xticks(index + bar_width*3, ('SVM', 'CNN', 'ELM', 'ML-ELM', 'ML-ELM-ELSR'))
		plt.legend((rects1[0], rects2[0], rects3[0], rects4[0], rects5[0], rects6[0]), ('ACC', 'SENSITIVE','SPECIFICITY', 'PRECISION','RECALL', 'F1-SCORE'))
		#plt.legend()
		ax.set_ybound(0, 150)

		plt.tight_layout()
		plt.savefig("bar.jpg")
		plt.show()
	def txt_transfer(self):
		in_filename="1.txt"
		out_filename="out.txt"
		file_object=open(in_filename,'r')
		list_of_all_the_lines = file_object.readlines()
		file_object.close()
		list_of_out_lines=[]
		out_file_object=open(out_filename,"w")
		print(len(list_of_all_the_lines))
		count=0
		for line in list_of_all_the_lines:
			id=line.find("]")
			if(line[0]=='[' and id>0):
				line=line[id+1:]
			list_of_out_lines.append("["+str(count+1)+"] "+line.strip()+"\r")
			count=count+1
		print(len(list_of_out_lines))
		out_file_object.writelines(list_of_out_lines)
		out_file_object.close()




if __name__=="__main__":
	helper=FileHelper()
	fold="G:/pyproject/scrapy/selfie/lastimage"
	fold="G:/pyproject/scrapy/selfie/image/image-nouse"
	destFold=fold
	helper.demoBar()
	string="sdf]234"
	print(string.find("]"))
	print(string[4:])

	#helper.csv2data("C:/Users/lixiaobo/Desktop/result.csv")
	#helper.showbarchartDemo()
	#helper.combineImageDemo()
	#elper.oswalkIndexFileDemo()
	#helper.demoOswalkReszieImage()
	#helper.oswalkRemoveDemo()
	#helper.detectFacesFold("G:/pyproject/scrapy/selfie/image/faceimage",destFold)
	#helper.democake()
	#helper.filterImageDemo();
	helper.txt_transfer()
 
 
 