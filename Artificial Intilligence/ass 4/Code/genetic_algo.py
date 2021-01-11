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
    n = input('How many parent generation: ')
    
    for i in range(int(n)):
        state = input('enter state '+str(i+1)+' : ')
        L = list(state)
        states.append(L)

    threshold = int(input('enter threshold value: '))
    makeParents()

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

def makeParents():
    global  states
    global threshold
    maxValue = 0
    maxState = []
    isFound = False
    stuck = False

    i = 0
    while i < len(states):
        
        if eval(states[i]) >= threshold:
            maxState = states[i]
            maxValue = eval(states[i])
            isFound = True
            break
        elif eval(states[i]) < 15:
            states.remove(states[i])
        else:
            maxValue = max(maxValue, eval(states[i]))
            i += 1
            
    
    if len(states) == 0:
        stuck = True

    #Chossing parents randomly for crossover
    if isFound == False and stuck == False:
        """
        print('Parent Generations: \n')
        for i in range( len(states) ):
            print(states[i])
        """
        x = random.randint(0,len(states)-1)
        while True:
            y = random.randint(0,len(states)-1)
            if(y != x):
                break
        parent1 = states[x]
        parent2 = states[y]

        crossover(parent1, parent2)
        
        
    if isFound == True:
        print('Found! '+str(maxState)+' '+str(maxValue))
    elif stuck == True:
        print('Stuck! ')
    else:
        print('Iteration Max: '+str(maxValue))
        makeParents()

              
def crossover(parent1, parent2):
    global  states
    
    crossoverPoint = random.randint(0,8)
    offSpring1 = []
    offSpring2 = []
    
    offSpring1[: crossoverPoint] = parent1[ :crossoverPoint ]
    offSpring1[crossoverPoint: ] = parent2[crossoverPoint : ]
    offSpring2[: crossoverPoint] = parent2[ :crossoverPoint ]
    offSpring2[crossoverPoint: ] = parent1[crossoverPoint : ]

    #Mutation
    if random.randint(0,10) > 7:
        x = random.randint(0,7)
        offSpring1[x] = str(random.randint(1,8))

    #print('Offspings: ')
    #print(str(offSpring1)+' '+str(offSpring2)) 
        
    states.append(offSpring1)
    states.append(offSpring2) 


    
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

