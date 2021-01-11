:-use_module(eval_state).
:-use_module(list_apps).
:-dynamic(state/4). /* id,type,state,h_value*/
:-dynamic(id/1).
:-dynamic(max_val/1).
:-dynamic(threshold/1).
:-dynamic(restrt_cntr/1).
:-dynamic(list_st/1).

/* Organizing a Menu */
start:- repeat,
	write('\n1. Clear database'),
	write('\n2. Execute hcls'),
	write('\n3. Display states'),
	write('\n4. Save states'),
	write('\n5. Exit'),
	write('\n\nEnter your choice: '),
	read(N), N >0, N < 6,
	do(N), N=5,!.

do(1):- retractall(state(_,_,_,_)),retractall(id(_)), retractall(max_val(_)),
	retractall(threshold(_)), retractall(restrt_cntr(_)).
do(2):- go_hcs.
do(3):- listing(state).
do(4):- write('Enter a new file name:'), read(Flnm),
	tell(Flnm),listing(state),told.
do(5):- abort.

/* Beginning of search */
go_hcs:- write('Enter a state:'), read(S),
	 write('Enter threshold value:'), read(V),
	 assert(threshold(V)),assert(restrt_cntr(0)),
	 getdigits(S,D1,D2,D3,D4,D5,D6,D7,D8),
	 L=[D1,D2,D3,D4,D5,D6,D7,D8],
	 gnrt_sucsr(L).

/* Generating the successors of a 8-queens' state given as a list */
gnrt_sucsr(L):- assert(id(1)), assert(state(1,'c',L,50)),
	incr_id, mk_new(1,L), retract(id(_)), evaluate.

incr_id:-id(V), V1 is V+1, retract(id(_)), assert(id(V1)).

mk_new(9,_):-!.
mk_new(N,L):- nthel(N,L,X), del_el(X,[1,2,3,4,5,6,7,8],L1),
	cng_mk(N,L,L1), N1 is N+1, mk_new(N1,L).

cng_mk(_,_,[]):-!.
cng_mk(N,L,L1):- L1=[H|T], rplc_nthel(N,H,L,L2),id(Id),
	assert(state(Id,'s',L2,50)), incr_id, cng_mk(N,L,T).

/* Evaluating the states */
evaluate:- eval_all, checkall.

eval_all:- state(I,T,L,_), eval(L,V),retract(state(I,_,_,_)),
	assert(state(I,T,L,V)), fail.
eval_all:-!.

/* Determining and displaying the best state */
checkall:- state(_,'c',_,V1), threshold(V2), V1 >= V2, I is 1, dsply(I),!.
checkall:- best(I1,V1), threshold(V2), V1 >= V2, I is I1, dsply(I),!.
checkall:- state(_,'c',_,V1), best(I,V2) ,V2>V1,state(I,_,L,_),
	retractall(state(_,_,_,_)),write_list(['\nIteration max: ',V2]),
	gnrt_sucsr(L),!.
checkall:- rndm_restrt,!.

best(I,Max):- state(_,'s',_,Val), assert(max_val(Val)),
	updt_max, max_val(Max), state(I,_,_,Max), retract(max_val(_)),!.

updt_max:- state(_,_,_,V2),  max_val(V1), V2>V1,
	retract(max_val(_)), assert(max_val(V2)), fail.
updt_max:-!.

dsply(I):-state(I,T,L,V),
	write_list(['\n\nFound! Id:',I,'  ',T,'	 ', L,'	 ','Value:',V,'\n']),!.

rndm_restrt:- retractall(state(_,_,_,_)), restrt_cntr(V), V<5,
	write('\n\nStuckup! Restarting.\n\n'), restart,!.
rndm_restrt:-write('\n\nStuckup once again! Ending.\n\n').

restart:- incr_r_c, restrt_cntr(V), write_list(['\n\nRestart index: ',V]),
	get_rndm_st(L),gnrt_sucsr(L).

incr_r_c:- restrt_cntr(V), V1 is V+1, retract(restrt_cntr(_)),
	assert(restrt_cntr(V1)).

get_rndm_st(L):- assert(list_st([])), lp8(8), list_st(L), retract(list_st(_)).

lp8(0):-!.
lp8(N):- N1 is N-1, X is random(8)+1, list_st(L1),append(L1,[X],L2),
	retract(list_st(L1)),assert(list_st(L2)),lp8(N1).

/* Exercise:

1. Change it to accomodate restarting with a randomly generated state.
   [Note:"X is random(8)+1" - returns a random integer from 1 to 8 in X.]

2. Based on the code above implement a Genetic Algorithm.

*/
