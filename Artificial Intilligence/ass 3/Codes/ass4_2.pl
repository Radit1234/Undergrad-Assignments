% Including data files
:-use_module(inputGraph).

% Declaration of dynamic data
:-dynamic(t_node/4).
:-dynamic(t_indx/1).
:-dynamic(pq/1).
:-dynamic(pp/1).

% Search begins
search:-write('Enter start node:'),read(S),h_fn(S,HV),
	assert(t_node(S,0,nil,HV)),assert(pq([node(S,0,'nil',HV)])),assert(t_n_indx(1)),
	assert(pp([])),generate,find_path_length(L), display_result(L).

% Generating the solution
generate:-pq([H|_]),H=node(N,_,_,_),N=g, add_to_pp(g),!.
generate:-pq([H|_]), H=node(N,I,_,_), update_with(N,I),generate.

% Adding a node to possible path
add_to_pp(N):-pp(Lst), append(Lst,[N],Lst1), retract(pp(_)),
	assert(pp(Lst1)).

% Updating data according to selected node.
update_with(N,I):-update_pq_tr(N,I), update_pp(N,I).

% Updating Priority Queue and Tree
update_pq_tr(N,I):-pq(Lst), delete_1st_element(Lst,Lst1), retract(pq(_)),
	assert(pq(Lst1)), add_children(N,I).
delete_1st_element(Lst,Lst1):-Lst = [_|Lst1].
add_children(N,I):- neighbor(N,X,D), t_n_indx(I1), t_node(_,I,_,V),
	h_fn(N,V1), h_fn(X,V2),	FNV is V+D-V1+V2,
	insrt_to_pq(X,I1,I,FNV), assert(t_node(X,I1,I,FNV)),
	incr_indx, fail.

add_children(_,_).
incr_indx:-  t_n_indx(X), Y is X+1, retract(t_n_indx(X)), assert(t_n_indx(Y)).

% Inserting node to Priority Queue
insrt_to_pq(X,I1,I,FNV):- pq(Lst), insert12pq(node(X,I1,I,FNV),Lst,Lst1),
	retract(pq(_)),	assert(pq(Lst1)).

insert12pq(El,[], [El]):-!.
insert12pq(El, L1, L2):-L1=[H|_], El=node(_,_,_,V1), H=node(_,_,_,V2),
                            not(V1 > V2), L2 = [El|L1], !.
insert12pq(El, L1, L2):-L1=[H|T], insert12pq(El, T, Lx), L2 = [H|Lx].

% Updating Possible Path
update_pp(N,I):- retract(pp(_)), assert(pp([])), renew_pp(N,I).
renew_pp(N,I):-t_node(N,I,nil,_), pp(X), append([N],X,X1),
	retract(pp(_)), assert(pp(X1)), !.
renew_pp(N,I):- pp(X), append([N],X,X1), retract(pp(_)), assert(pp(X1)),
	t_node(N,I,I1,_),t_node(N1,I1,_,_), renew_pp(N1,I1).
% Finding 'shortest' path length
find_path_length(L):-pp(Lst),path_sum(Lst,L).
path_sum(Lst,0):- Lst=[g|_],!.
path_sum(Lst,L):-Lst=[N|T],T=[N1|_], neighbor(N,N1,D), path_sum(T,L1),L is L1+D.

% Displaying 'shortest' path and its length
display_result(L):- pp(Lst), write('Solution:'), write(Lst),nl,
	write('Length:'), write(L).





























