import  random
f=open('input.txt','w+')
f.write('100 100000\n')
for i in  range(0,100):
    a=random.randint(1,100000);
    f.write(str(a)+' ')
for i in  range(0,100):
    a=random.randint(1,1000);
    f.write(str(a)+' ')
f.write('\n')
f.flush()
f.close()
