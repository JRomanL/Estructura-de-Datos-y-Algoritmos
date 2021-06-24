#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jun 24 15:32:54 2021

@author: honorio
"""
from random import randint
import json

u=100
numero_aleatorios = [randint(1,100) for _ in range(u)]
a = numero_aleatorios
with open('File_100.txt', 'w') as f:
    f.write(json.dumps(a))
u=500
numero_aleatorios = [randint(1,100) for _ in range(u)]
a = numero_aleatorios
with open('File_500.txt', 'w') as f:
    f.write(json.dumps(a))
u=1000
while u < 10000:

  if u>=1000 and u<10000:
    numero_aleatorios = [randint(1,100) for _ in range(u)]
    files="File_"
    num=str(u)
    ext=".txt"
    mi_path = files+num+ext
    with open(mi_path, 'w') as f:
      f.write(json.dumps(numero_aleatorios))
    f.close()
    numero_aleatorios=[]
  u=u+1000

while u <= 100000:
  if u>=10000 and u<=100000:
    numero_aleatorios = [randint(1,100) for _ in range(u)]
    files="File_"
    num=str(u)
    ext=".txt"
    mi_path = files+num+ext
    with open(mi_path, 'w') as f:
      f.write(json.dumps(numero_aleatorios))
    f.close()
    numero_aleatorios=[]
  u=u+10000