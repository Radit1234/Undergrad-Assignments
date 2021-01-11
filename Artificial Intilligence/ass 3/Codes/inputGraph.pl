:-module(inputGraph, [ neighbor/3, h_fn/2 ]).

% Description of the weighted graph

neighbor(i,a,35). neighbor(a,i,35). neighbor(i,b,45). neighbor(b,i,45).
neighbor(a,c,22). neighbor(c,a,22). neighbor(a,d,32). neighbor(d,a,32).
neighbor(b,d,28). neighbor(d,b,28). neighbor(b,e,36). neighbor(e,b,36).
neighbor(b,f,27). neighbor(f,b,27). neighbor(c,d,31). neighbor(d,c,31).
neighbor(c,g,47). neighbor(g,c,47). neighbor(d,g,30). neighbor(g,d,30).
neighbor(e,g,26). neighbor(g,e,26).

% Description of heuristic function values
% Straight line distance from a node to the goal node, g

h_fn(i,80). h_fn(a,55). h_fn(b,42). h_fn(c,34).
h_fn(d,25). h_fn(e,20). h_fn(f,17). h_fn(g,0).


