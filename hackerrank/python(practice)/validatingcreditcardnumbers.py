# Enter your code here. Read input from STDIN. Print output to STDOUT
T= int(raw_input())
while T>0:
    T+=-1
    s=raw_input()
    digits=0
    l=[]
    isvalid=1
    length=len(s)
    maxc=0
    for k in range(10):
        l.append(0)
        
    for counter in range(10):
        for ind,j in enumerate(s):
            if j==chr(ord('0')+counter):
                #l[counter]+=1
                digits+=1
                runner=ind
                while( runner<length and (s[runner]==j or s[runner]=='-') ):
                    if(s[runner]!='-'):
                        l[counter]+=1
                    runner+=1
                if(maxc<=l[counter]):
                    maxc=l[counter]
                l[counter]=0    
                
                    
    #for counter in l:
        #if(maxc<counter):
            #maxc=counter
        #digits+=counter
    if(digits!=16):
        #print("1")
        isvalid=0
    if(s[0]!='4' and s[0]!='5' and s[0]!='6'):
        #print("2")
        isvalid=0
    if(length!=16 and length!=19):
       # print(length,"3")
        isvalid=0
    if(length==19):
        if(s[4]!='-' or s[9]!='-' or s[14]!='-'):
           # print("4")
            isvalid=0
    if(maxc>3):
        #print maxc,'5'
        isvalid=0
    if(isvalid==0):
        print 'Invalid'
    else:
        print 'Valid'
        
        
            