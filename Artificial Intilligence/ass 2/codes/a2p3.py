gtp=[(1,1,1), (2,1,2), (3,1,3), (4,2,3), (5,3,3), (6,3,2), (7,3,1), (8,2,1)]
gblnk = (2,2)
tp=[(1,1,2), (2,1,3), (3,2,1), (4,2,3), (5,3,3), (6,2,2), (7,3,2), (8,1,1)]
blnk = (3,1)

def manhattan():
    cost = 0
    for i in range(8):    
        cost += abs(gtp[i][1] - tp[i][1]) + abs(gtp[i][2] - tp[i][2])
    return cost


#Main
print('Current State: '+str(tp))
print('Goal State: '+str(gtp))

print('Manhattan distance: '+str( manhattan() ))
