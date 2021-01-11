:-module(eval_state, [do_eval/2, eval/2,
		      getdigits/9  /*, hl/2, di_up/2, di_dn/2,incr_hval/0,
		      chk_incr/3, do_incr/2, chkup_incr/4, doup_incr/3,
		      chkdn_incr/4, dodn_incr/3*/  ]).
:-use_module(list_apps).
:-dynamic(hval/1).


/* Evaluates a 8-queens' state, S given as an 8-digit number  */
do_eval(S,V):-getdigits(S,D1,D2,D3,D4,D5,D6,D7,D8),
	L=[D1,D2,D3,D4,D5,D6,D7,D8],eval(L,V).

eval(L,V):- assert(hval(0)),
	hl(1,L), di_up(1,L),di_dn(1,L),
	hval(V1),V is 28-V1, retract(hval(_)).


getdigits(S,D1,D2,D3,D4,D5,D6,D7,D8):-
	D1 is S div   10000000,
	R1 is S mod   10000000,
	D2 is R1 div  1000000,
	R2 is R1 mod  1000000,
	D3 is R2 div  100000,
	R3 is R2 mod  100000,
	D4 is R3 div  10000,
	R4 is R3 mod  10000,
	D5 is R4 div  1000,
	R5 is R4 mod  1000,
	D6 is R5 div  100,
	R6 is R5 mod  100,
	D7 is R6 div  10,
	D8 is R6 mod  10.

hl(8,_):-!.
hl(I,L):- nthel(I,L,X), chk_incr(I,L,X), I1 is I+1, hl(I1,L).

chk_incr(8,_,_):-!.
chk_incr(I,L,X):- I1 is I+1, nthel(I1,L,Y), do_incr(X,Y),
	chk_incr(I1,L,X).

do_incr(X,Y):- X=Y, incr_hval.
do_incr(_,_).

incr_hval:-hval(V), V1 is V+1, retract(hval(_)), assert(hval(V1)).


di_up(8,_):-!.
di_up(I,L):- nthel(I,L,X), chkup_incr(I,L,X,0), I1 is I+1, di_up(I1,L).

chkup_incr(8,_,_,_):-!.
chkup_incr(I,L,X,K):- I1 is I+1, nthel(I1,L,Y), K1 is K+1,
	doup_incr(X,Y,K1), chkup_incr(I1,L,X,K1).

doup_incr(X,Y,K1):- X1 is X+K1, Y=X1, incr_hval.
doup_incr(_,_,_).


di_dn(8,_):-!.
di_dn(I,L):- nthel(I,L,X), chkdn_incr(I,L,X,0), I1 is I+1, di_dn(I1,L).

chkdn_incr(8,_,_,_):-!.
chkdn_incr(I,L,X,K):- I1 is I+1, nthel(I1,L,Y), K1 is K+1, dodn_incr(X,Y,K1),
	chkdn_incr(I1,L,X,K1).

dodn_incr(X,Y,K1):- X1 is X-K1, Y=X1, incr_hval.
dodn_incr(_,_,_).





