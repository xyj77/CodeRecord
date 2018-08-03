#!/usr/bin/env python
# -*- coding: utf-8 -*-

with open('caffe_output.log', 'r') as f1, open('log.txt', 'w') as f2:
    for line in f1.readlines():
        line = line.strip()
        if "accuracy = " in line:
            f2.write(line[(line.index('=')+2):] + ' ')
