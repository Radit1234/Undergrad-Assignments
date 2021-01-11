import random

threshold = 0
max_val = 0
restart_count = 0
states = []
max_id = 0

def clear_database():
    global threshold 
    global max_val 
    global restart_count 
    global  states 
    global  max_id 
    
    threshold = 0
    max_val = 0
    restart_count = 0
    states = []
    max_id = 0

def execute_hcls():
    global threshold 
    global  states 
    
    state = input('enter a state: ')
    threshold = int(input('enter threshold value: '))
    L = list(state)
    genarate_successor(L)

def display_states():
    global states
    for j in range(len(states)):
       print(states[j])

def save_states():
    global states
    f1=open("std.py", "w")
    for j in range(len(states)):
       print(states[j],file = f1)
    f1.close

def evalState(qList):
    count = 0
    #horizontal check
    for i in range(0,len(qList),1):
        for j in range(i+1,len(qList),1):
            if (qList[i] == qList[j]):
                count = count + 1

    #diagonal_up check
    for i in range(0,len(qList),1):
        x = int(qList[i])
        for j in range(i+1,len(qList),1):
           
            x = x + 1
            if (x == int(qList[j])):
                count = count + 1

    #diagonal_down check
    for i in range(0,len(qList),1):
        x = int(qList[i])
        for j in range(i+1,len(qList),1):
            x = x - 1
            if (x == int(qList[j])):
                count = count + 1
    
    return count

def eval(L):
    return 28 - evalState(L)

def genarate_successor(L):
    global threshold 
    global max_val 
    global restart_count 
    global  states 
    global  max_id 
    
    hval = eval(L)
    y = [1,'c',L,hval]
    #print(y)
    stuck = True
    max_val = hval
    max_id = 1
    states = []
    states.append(y)

    idcount = 2
    for i in range(1,9):
        
        for j in range(1,9):
            if(L[i-1] != str(j)):
                x = L[:]
                x[i-1] = str(j)
                hval = eval(x)
                y = [idcount,'s',x,hval]
                states.append(y)
                if(max_val < hval):
                    max_val = hval
                    max_id = idcount
                    #print(max_val,end =' ')
                    #print(max_id)
                    stuck = False
                idcount += 1
    checkall(stuck)


def checkall(stuck):
    global threshold 
    global max_val 
    global restart_count 
    global  states 
    global  max_id 
    
    if max_val >= threshold:
        print('found! '+str(states[max_id - 1]))
    elif(restart_count >= 5):
        print('Stuckup Again! Stop..\n ')
    elif stuck == True and restart_count < 5:
        print('Stuckup! Restarting..\n ')
        restart_count += 1
        genarate_successor(randomState())
    elif max_val < threshold :
        print('iteration max: '+str(max_val))
        genarate_successor(states[max_id - 1][2])

def randomState():
    rstate = []
    for x in range(8):
        val = str(random.randint(1,9))
        rstate.append(val)

    return rstate
    
#Main
cs = 1

while(cs>=1 and cs<5):
    print('\n1. Clear database')
    print('\n2. Execute hcls')
    print('\n3. Display states')
    print('\n4. Save states')
    print('\n5. Exit')
    cs = int(input('\n\nEnter your choice: '))
    if(cs == 1):
        clear_database()
    elif(cs == 2):
        execute_hcls()
    elif(cs == 3):
        display_states()
    elif(cs == 4):
        save_states()
    else:
        break

