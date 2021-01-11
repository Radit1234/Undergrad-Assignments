# S = Stentch , B = Breeze , W = Wumpus , P = Pit , G = Gold , A = Players's initial position

grid = [('S',1,2), ('S',1,4), ('S',2,3),('B',2,1), ('B',2,3), ('B',3,2), ('B',3,4), ('B',4,1), ('B',4,3),
                ('W',1,3),('P',3,1), ('P',3,3) , ('G',2,3) ]
KB = [ ('S',1,1,False),('B',1,1,False),('W',1,1,False),('P',1,1,False)]

xx = [1,0]
yy = [0,1]
gd = []

#checking for grid boundary conditions
def in_boundary(x,y):
    if(x>=0 and x<=4 and y>=0 and y<=4):
        return True
    else:
        return False
    

def start(y,x,KB):

    print('Entering into Safe Grid : ('+str(y)+','+str(x)+')')
    pos = ('A',y,x,True)
    KB.append(pos)

    #if gold is found return the grid
    if( ('G', y , x) in grid ):
        global gd
        gd = (y,x)
        return

    if( ('W', y , x) in grid ):
        printf('Killed by Wumpus')
        return

    if( ('P', y , x) in grid ):
        printf('Fell into Pit')
        return    

    for i in range(2):
        p_y = y+yy[i]
        p_x = x+xx[i]

        if( in_boundary(p_y,p_x) ):
            #applying Modus Ponens, And Elimination, Unit Resolution
            
            if( ('S', y , x ) not in grid and ('W',p_y,p_x,False) not in KB):
                if(('W',p_y,p_x,True) in KB):
                    KB.remove( ('W',p_y,p_x,True) )
                KB.append( ('W',p_y,p_x,False) )
            if( ('B', y, x) not in grid and ('P',p_y,p_x,False) not in KB):
                if(('P',p_y,p_x,True) in KB):
                    KB.remove( ('W',p_y,p_x,True) )
                KB.append( ('P',p_y,p_x,False) )
            if( ('S', y , x ) in grid and ('W',p_y,p_x,False) not in KB):
                KB.append( ('W',p_y,p_x,True) )
            if( ('B', y, x ) in grid and ('P',p_y,p_x,False) not in KB):
                KB.append( ('P',p_y,p_x,True) )

    if(pos in KB):
        KB.remove(pos) 

    for i in range(2):
        p_y = y+yy[i]
        p_x = x+xx[i]

        if( in_boundary(p_y,p_x) and gd == [] ):
            if ( ('W',p_y,p_x,False) in KB  and  ('P',p_y,p_x,False) in KB):
                start(p_y,p_x, KB)
    
    
#Main
print('Initial Knowldege Base: ')
print(KB)
print()

start(1,1,KB)
print('\n!! Gold Found in '+str(gd)+' !!\n')

count = 1
print('Knowldege Base After Execution: ')
print(KB)

