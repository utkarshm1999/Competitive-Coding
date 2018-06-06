def minion_game(string):
    # your code goes here
    l=len(string)
    s=0
    k=0
    for index,char in enumerate(string):
        if(char=='A' or char=='E' or char=='I' or char=='O' or char=='U'):
            k=k+(l-index)
        else:
            s=s+(l-index)
    if(s>k):
        print 'Stuart',s
    elif(k>s):
        print 'Kevin',k
    else:
        print 'Draw'
        