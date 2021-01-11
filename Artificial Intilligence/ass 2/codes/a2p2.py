neighbor = {
        'i':[('a',35),('b',45)],
        'a':[('c',22),('d',32)],
        'b':[('d',28),('e',36),('f',27)],
        'c':[('d',31),('g',47)],
        'd':[('g',30)],
        'e':[('g',27)]
    }
 
def find_path_length(neighbor, start, end, path =[], cost=0): 
  path = path + neighbor[start]
  if start == end: 
    return cost 
  for (node,weight) in neighbor[start]: 
    if node not in path:
      return find_path_length(neighbor, node, end, path, cost+weight) 
      
  
#Main
s = input('Source: ')
d = input('Destination: ')
print('Destination: '+str( find_path_length(neighbor, s, d) )) 
