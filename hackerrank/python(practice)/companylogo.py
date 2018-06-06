#!/bin/python

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    s = raw_input()
    list=[]
    
    for i in range(26): 
        list.append(0)
        for alpha in s:
            if alpha==chr(ord('a')+i):
                list[i]+=1
    max=0
    left=3
   
    while(left>0):
        char=[]
        maxc=0
        max=0
        for count in list:
            if (count>max):
                max=count
        for i,count in enumerate(list):
            if(max==count):
                char.append(chr(ord('a')+i))
                maxc+=1
                list[i]=0
      #  left=left-maxc  
        char.sort()
        j=0
      #  print(type(char))
        while j<maxc:
            
            
            if(left>0):
                print char[j],max 
            else:
                break
            left+=-1
            j+=1
            
    
                
                
