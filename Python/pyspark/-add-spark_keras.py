#-*- coding:utf-8 -*-

'''
Requirements:
1.docker
2.spark on docker
3.tensorflow、keras、elephas

单机多CPU集群并行训练CNN实例
跑一个最简单的网络来训练mnist手写字识别，贴一个能够直接运行的代码（要事先下载好mnist.pkl.gz）：
如果你的机器有多个CPU（假设24个）：
    你可以只开一个docker，然后很简单的使用spark结合elephas来并行（利用24个cpu）计算CNN。
如果你的机器有多个GPU（假设4个）：
    你可以开4个docker镜像，修改每个镜像内的~/.theanorc来选择特定的GPU来并行（4个GPU）计算。（需自行安装cuda）

执行以下命令即可运行：
/usr/local/spark/bin/spark-submit mnist_cnn_spark.py

使用24个slave，并行迭代了5次，得到的准确率和运行时间如下：
Test accuracy: 95.68% 
took: 1135s

不使用spark，1次迭代就需要1800s，所以还是快7~8倍的。
'''
from __future__ import print_function
import numpy as np

from keras.datasets import mnist
from keras.models import Sequential
from keras.layers.core import Dense, Dropout, Activation, Flatten
from keras.optimizers import SGD, Adam, RMSprop
from keras.layers.convolutional import Convolution2D, MaxPooling2D
from keras.utils import np_utils

from elephas.spark_model import SparkModel
from elephas.utils.rdd_utils import to_simple_rdd

from pyspark import SparkContext, SparkConf

import gzip
import cPickle

APP_NAME = "mnist"
MASTER_IP = 'local[24]'

# Define basic parameters
batch_size = 128
nb_classes = 10
nb_epoch = 5

# input image dimensions
img_rows, img_cols = 28, 28
# number of convolutional filters to use
nb_filters = 32
# size of pooling area for max pooling
nb_pool = 2
# convolution kernel size
nb_conv = 3

# Load data
f = gzip.open("./mnist.pkl.gz", "rb")
dd = cPickle.load(f)
(X_train, y_train), (X_test, y_test) = dd

X_train = X_train.reshape(X_train.shape[0], 1, img_rows, img_cols)
X_test = X_test.reshape(X_test.shape[0], 1, img_rows, img_cols)

X_train = X_train.astype("float32")
X_test = X_test.astype("float32")
X_train /= 255
X_test /= 255


print(X_train.shape[0], 'train samples')
print(X_test.shape[0], 'test samples')

# Convert class vectors to binary class matrices
Y_train = np_utils.to_categorical(y_train, nb_classes)
Y_test = np_utils.to_categorical(y_test, nb_classes)

model = Sequential()
model.add(Convolution2D(nb_filters, nb_conv, nb_conv,
                        border_mode='full',
                        input_shape=(1, img_rows, img_cols)))
model.add(Activation('relu'))
model.add(Convolution2D(nb_filters, nb_conv, nb_conv))
model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(nb_pool, nb_pool)))
model.add(Dropout(0.25))

model.add(Flatten())
model.add(Dense(128))
model.add(Activation('relu'))
model.add(Dropout(0.5))
model.add(Dense(nb_classes))
model.add(Activation('softmax'))

model.compile(loss='categorical_crossentropy', optimizer='adadelta')

## spark
conf = SparkConf().setAppName(APP_NAME).setMaster(MASTER_IP)
sc = SparkContext(conf=conf)

# Build RDD from numpy features and labels
rdd = to_simple_rdd(sc, X_train, Y_train)

# Initialize SparkModel from Keras model and Spark context
spark_model = SparkModel(sc,model)

# Train Spark model
spark_model.train(rdd, nb_epoch=nb_epoch, batch_size=batch_size, verbose=0, validation_split=0.1, num_workers=24)

# Evaluate Spark model by evaluating the underlying model
score = spark_model.get_network().evaluate(X_test, Y_test, show_accuracy=True, verbose=2)
print('Test accuracy:', score[1])