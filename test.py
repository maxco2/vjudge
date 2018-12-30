import  random
f=open('input.txt','w+')
f.write('200000\n')
for i in  range(0,200000):
    a=random.randint(1,200000);
    f.write(str(a)+' ')
f.write('\n')
for  i  in  range(0,200000):
    f.write(str(i+1)+ ' '+str(i+2)+'\n')
f.close()
