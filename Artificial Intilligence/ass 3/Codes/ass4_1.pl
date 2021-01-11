% Including data files
:-use_module(inputGraph).

% Declaration of dynamic data
:-dynamic(t_node/2).
:-dynamic(pq/1).
:-dynamic(pp/1).

% Search begins
search:-write('Enter start node:'),read(S),h_fn(S,HV),
	assert(t_node(S, 'nil')),assert(pq([node(S,HV)])),
	assert(pp([])),generate,find_path_length(L), display_result(L).

% Generating the solution
generate:-pq([H|_]),H=node(N,_),N=g, add_to_pp(g),!.
generate:-pq([H|_]),H=node(N,_),update_with(N), generate.

% Adding a node to possible path
add_to_pp(N):-pp(Lst), append(Lst,[N],Lst1), retract(pp(_)),
	assert(pp(Lst1)).

% Updating data according to selected node.
update_with(N):-update_pq_tr(N), update_pp(N).

% Updating Priority Queue and Tree
update_pq_tr(N):-pq(Lst), delete_1st_element(Lst,Lst1), retract(pq(_)),
	assert(pq(Lst1)), add_children(N).
delete_1st_element(Lst,Lst1):-Lst = [_|Lst1].
add_children(N):- neighbor(N,X,_), not(t_node(X,_)),insrt_to_pq(X),
	assert(t_node(X,N)),fail.
add_children(_).

% Inserting node to Priority Queue
insrt_to_pq(X):- pq(Lst), h_fn(X,V), insert12pq(node(X,V),Lst,Lst1),
	retract(pq(_)), assert(pq(Lst1)).

insert12pq(El,[], [El]):-!.
insert12pq(El, L1, L2):-L1=[H|_], El=node(_,V1), H=node(_,V2),
                            not(V1 > V2), L2 = [El|L1], !.
insert12pq(El, L1, L2):-L1=[H|T], insert12pq(El, T, Lx), L2 = [H|Lx].

% Updating Possible Path
update_pp(N):- retract(pp(_)), assert(pp([])), renew_pp(N).
renew_pp(N):-t_node(N,nil), pp(X), append([N],X,X1),
	retract(pp(_)), assert(pp(X1)), !.
renew_pp(N):- pp(X), append([N],X,X1), retract(pp(_)), assert(pp(X1)),
	t_node(N,N1), renew_pp(N1).

% Finding 'shortest' path length
find_path_length(L):-pp(Lst),path_sum(Lst,L).
path_sum(Lst,0):- Lst=[g|_],!.
path_sum(Lst,L):-Lst=[N|T],T=[N1|_], neighbor(N,N1,D), path_sum(T,L1),L is L1+D.

% Displaying 'shortest' path and its length
display_result(L):- pp(Lst), write('Solution:'), write(Lst),nl,
	write('Length:'), write(L).

















