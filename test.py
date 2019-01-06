import  random
f=open('input.txt','w+')
f.write('1000000\n')
for i in  range(0,1000000):
    a=random.randint(1,200000);
    f.write(str(a)+' ')
f.write('\n')
f.flush()
f.close()
