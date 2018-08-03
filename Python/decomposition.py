# -*- coding: utf-8 -*-
"""
Created on Tue Jul 10 14:43:15 2018

@author: xyj

python code for 【周末AI课堂】非线性降维方法
https://mp.weixin.qq.com/s?__biz=MzI2NjkyNDQ3Mw==&mid=2247487182&idx=1&sn=71883e23bae2c3c6059d6a918ba6a730&chksm=ea87f618ddf07f0eef3918c43604c964e5228e6dc4c21393cf938ecc36d921e00451ad8e9c97&scene=0#rd

"""

import matplotlib.pyplot as plt

from mpl_toolkits.mplot3d import Axes3D
from sklearn import  datasets

X, c = datasets.samples_generator.make_s_curve(1000, random_state=2018)

ax = Axes3D(plt.figure())
ax.scatter(X[:,0], X[:,1], X[:,2], c=c, cmap=plt.cm.hsv)
plt.title('Sample')
plt.show()


from sklearn.decomposition import PCA
X_PCA=PCA(2).fit(X).transform(X)


from sklearn.manifold import Isomap
X_ISO=Isomap(10,2).fit(X).transform(X)

n_points = 1000
X, color = datasets.samples_generator.make_swiss_roll(n_points, 
random_state=2018)
X_PCA=PCA(2).fit(X).transform(X)
X_ISO=Isomap(10,2).fit(X).transform(X)

ax = Axes3D(plt.figure())
ax.scatter(X[:,0],X[:,1],X[:,2],\
c=color,cmap=plt.cm.hsv)
ax.set_title('Sample')

bx=plt.figure()
plt.scatter(X_PCA[:,0],X_PCA[:,1],c=color,cmap=plt.cm.hsv)
plt.title('PCA of Swiss Roll')

cx=plt.figure()
plt.scatter(X_ISO[:,0],X_ISO[:,1],c=color,cmap=plt.cm.hsv)
plt.title('ISOMAP of Swiss Roll')
plt.show()



import numpy as np
from sklearn import datasets
from sklearn.model_selection import cross_validate
from sklearn.manifold import Isomap,MDS
from sklearn.manifold import locally_linear_embedding as LLE
from sklearn.decomposition import PCA
from sklearn.decomposition import KernelPCA
from sklearn.preprocessing import StandardScaler 
from sklearn.neighbors import KNeighborsClassifier as KNC
import seaborn as sns
import matplotlib.pyplot as plt

data=datasets.load_wine()
X=StandardScaler().fit(data['data']).transform(data['data'])
y=data['target']

def dim_reductor(n,X):
    reductor=dict(PCA=PCA(n).fit(X).transform(X),\
    KPCA=KernelPCA(n,'rbf').fit_transform(X),\
    ISOMAP=Isomap(10,n).fit(X).transform(X),\
    MDS=MDS(n).fit_transform(X),\
    LLE=LLE(X,10,n)[0])
    return(reductor)

mse_mat=np.zeros((5,X.shape[1]))
for n in range(1,X.shape[1]+1):
    reductor=dim_reductor(n,X)
    test_mse=[]
    for name, method in reductor.items():
        X_new=reductor[name]
        clf=KNC()
        clf_dict=cross_validate(clf, X_new, y, cv=5, scoring='accuracy')
        test_mse.append(clf_dict['test_score'].mean())
        
    mse_mat[:,n-1]=test_mse

plt.figure()        
for idex,name in enumerate(reductor.keys()):
    plt.plot(range(1,X.shape[1]+1),mse_mat[idex],label=name)
    
plt.xlabel('dimensions')
plt.ylabel('accuracy')
plt.legend()
plt.show()

plt.figure()
sns.set(style='darkgrid')
sns.barplot(mse_mat[:,1],list(reductor.keys()))