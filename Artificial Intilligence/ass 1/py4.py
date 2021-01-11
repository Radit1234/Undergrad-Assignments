# Find the grandchildren of X
tupleList1=[('parent', 'Hasib', 'Rakib'),('parent', 'Rakib', 'Sohel'),('parent', 'Rakib', 'Rebeka'),('parent', 'Hasib', 'Rashid'),('parent', 'Hasib', 'Salma')]
maleList=['Hasib','Rakib','Sohel','Rashid']

#find brother
print('Finding Brother...')
X=str(input("Person: "))
print('Brother:', end=' ')
i=0
while(i<=4):
    if ((tupleList1[i][0] == 'parent')&( tupleList1[i][2] == X)):
        for j in range(5):
            if(( tupleList1[i][1] == tupleList1[j][1]) & (tupleList1[i][2] != tupleList1[j][2])):
                for k in range(4):
                    if(tupleList1[j][2] == maleList[k]):
                        print(tupleList1[j][2])
    i=i+1

#find sister
print('\nFinding Sister...')
X=str(input("Person: "))
print('Sister:', end=' ')
i=0
while(i<=4):
    if ((tupleList1[i][0] == 'parent')&( tupleList1[i][2] == X)):
        for j in range(5):
            if(( tupleList1[i][1] == tupleList1[j][1]) & (tupleList1[i][2] != tupleList1[j][2])):
                isSister = True
                for k in range(4):
                    if(tupleList1[j][2] == maleList[k]):
                        isSister = False
                if(isSister):
                    print(tupleList1[j][2])
    i=i+1

print('\nFinding Uncle...')
#find Uncle
X=str(input("Person: "))
print('Uncle:', end=' ')
i=0
while(i<=4):
    if ((tupleList1[i][0] == 'parent')&( tupleList1[i][2] == X)):
        for t in range(5):
            if ((tupleList1[t][0] == 'parent')&( tupleList1[t][2] == tupleList1[i][1])):
                for j in range(5):
                    if(( tupleList1[t][1] == tupleList1[j][1]) & (tupleList1[t][2] != tupleList1[j][2])):
                        for k in range(4):
                            if(tupleList1[j][2] == maleList[k]):
                                print(tupleList1[j][2])
    i=i+1

print('\nFinding Aunt...')
#find Aunt
X=str(input("Person: "))
print('Aunt:', end=' ')
i=0
while(i<=4):
    if ((tupleList1[i][0] == 'parent')&( tupleList1[i][2] == X)):
        for t in range(5):
            if ((tupleList1[t][0] == 'parent')&( tupleList1[t][2] == tupleList1[i][1])):
                for j in range(5):
                    if(( tupleList1[t][1] == tupleList1[j][1]) & (tupleList1[t][2] != tupleList1[j][2])):
                        isSister = True
                        for k in range(4):
                            if(tupleList1[j][2] == maleList[k]):
                               isSister = False
                        if(isSister):
                            print(tupleList1[j][2])
    i=i+1
