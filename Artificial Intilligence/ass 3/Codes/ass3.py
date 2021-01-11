
dictn = {}

print('Initial File\n')
f1=open("std.py", "r")       
for l in f1:
        name, dept, cgpa =l.split("\t")
        dictn[name] = [dept,float(cgpa)]
        print(name+' '+dept+' '+str(cgpa),end='')
f1.close

n = int(input('\nhow many data you want to change: '))
for i in range(n):
        name = input('enter name: ')
        cgpa = float(input('enter cgpa: '))
        dictn[name][1] = cgpa 

f1=open("out.py", "w")
for name in dictn:
        dept = dictn[name][0]
        cgpa = dictn[name][1]
        std=name+"\t"+dept+"\t"+str(cgpa)
        print(std,file=f1)
f1.close

print('\nUpdated File\n')
f1=open("std.py", "r")       
for l in f1:
        name, dept, cgpa =l.split("\t")
        print(name+' '+dept+' '+str(cgpa),end='')
f1.close

        
        
