states = []
iteration = 0

def evalState(lst):
    count = 0
    
    #horizontal check
    for i in range( len(lst) ):
        for j in range(i+1,len(lst),1):
            if (lst[i] == lst[j]):
                count = count + 1

    #diagonal_up check
    for i in range( len(lst) ):
        x = lst[i]
        for j in range(i+1,len(lst),1):
            x = x + 1
            if (x == lst[j]):
                count = count + 1

    #diagonal_down check
    for i in range( len(lst) ):
        x = lst[i]
        for j in range(i+1,len(lst),1):
            x = x - 1
            if (x == lst[j]):
                count = count + 1
                
    return count

def eval(L):
    return 28 - evalState(L)


def genarate_successor(L, threshold):

    global states
    global iteration
    states = []
    iteration += 1
    isFound = False
    stuck = True
    hval = eval(L)
    max_val = hval
    current_state = [1,'c',L,hval]
    states.append( current_state )
    first_uphill = []

    if hval >= threshold:
        isFound = True
        checkall(stuck,y,threshold)

    if isFound == False:
        count = 2
        for i in range(1,9):

            for j in range(1,9):
                if(L[i-1] != j):
                    x = L[:]
                    x[i-1] = j
                    hval = eval(x)
                    successor_state = [count,'s',x,hval]
                    states.append( successor_state )
                    if(max_val < hval and stuck == True):
                        first_uphill = successor_state
                        stuck = False
                    count += 1
    
        checkall(stuck , first_uphill , threshold )
        return states


def checkall(stuck , uphill , threshold ):
    
    if stuck == False :
        if (uphill[3] >= threshold) :
            print('\nFound! Id: '+str(uphill[0])+' Type: '+str(uphill[1])+' State: '+str(uphill[2])+' Value: '+str(uphill[3]) )
            return states
        else:
            print('Iteration: '+str(iteration)+' Selected First Uphill State: '+str(uphill[2])+' Value: '+str(uphill[3]) )
            genarate_successor( uphill[2] , threshold)
    else:
        print('Stuckup!\n ')
   

def clear_database():
    global  states
    states = []
    
def execute_hcls():
    
    global iteration
    state = input('Enter a state: ')
    threshold = int(input('enter threshold value: '))
    L = [ int(x) for x in str(state)]
    iteration = 0
    return genarate_successor(L , threshold)

def display_states(states):
    
    for j in range(len(states)):
       print(states[j])

def save_states(states):
    
    f1=open("output.txt", "w")
    for j in range(len(states)):
       print(states[j],file = f1)
    f1.close

    
    
#Main
case = 1
states = []
while(case >= 1 and case < 5):
    print('\n1. Clear database')
    print('2. Execute hcls')
    print('3. Display states')
    print('4. Save states')
    print('5. Exit')
    case = int(input('\n\nEnter your choice: '))
    if(case == 1):
        clear_database()
    elif(case == 2):
        states = execute_hcls()
    elif(case == 3):
        display_states( states )
    elif(case == 4):
        save_states(states)
    else:
        break

