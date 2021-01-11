qList = [2,5,3,6,6,3,1,4]

def evalState(qList):
    count = 0
    #horizontal check
    for i in range(0,len(qList),1):
        for j in range(i+1,len(qList),1):
            if (qList[i] == qList[j]):
                count = count + 1

    #diagonal_up check
    for i in range(0,len(qList),1):
        x = qList[i]
        for j in range(i+1,len(qList),1):
            x = x + 1
            if (x == qList[j]):
                count = count + 1

    #diagonal_down check
    for i in range(0,len(qList),1):
        x = qList[i]
        for j in range(i+1,len(qList),1):
            x = x - 1
            if (x == qList[j]):
                print(str(i)+" "+str(j))
                count = count + 1
    
    return count

#Main
print('Queen Position: '+str(qList))
print('Total Attacking Pairs: '+str( evalState(qList) ))
