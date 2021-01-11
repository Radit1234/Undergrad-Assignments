
neighbor = {
        'i':[('a',35),('b',45)],
        'a':[('i',35),('c',22),('d',32)],
        'b':[('i',45),('d',28),('e',36),('f',27)],
        'c':[('a',22),('d',31),('g',47)],
        'd':[('a',32),('b',28),('c',31),('g',30)],
        'e':[('b',36),('g',26)],
        'f':[('b',27)],
        'g':[('c',47),('d',30),('e',26)]
    }

h = {
    'i' : 80,
    'a' : 55,
    'b' : 42,
    'c' : 34,
    'd' : 25,
    'e' : 20,
    'f' : 17,
    'g' : 0
    }

def best_first(start,stop):
    open_list = set([start])
    closed_list = set([])

    g = {}
    g[start] = 0

    parents = {}
    parents[start] = start

    while len(open_list) > 0:
        n = None
        
        for v in open_list:
            if n == None or h[v] < h[n]:
                n = v

        if n == None:
            return None

        if n == stop:
            reconst_path = []
            dist = g[n]
    
            while parents[n] != n:
                reconst_path.append(n)
                n = parents[n]

            reconst_path.append(start)
            reconst_path.reverse()
            
            print("path: {}".format(reconst_path))
            print("path distance: "+str(dist))
            return reconst_path

        for (m,weight) in neighbor[n]:
            if m not in open_list and m not in closed_list:
                open_list.add(m)
                parents[m] = n
                g[m] = g[n] + weight
           
        open_list.remove(n)
        closed_list.add(n)
        
    print('path does not exist')
    return None

#Main
best_first('i','g')















