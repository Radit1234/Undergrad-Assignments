sum1(F,_,1,F):-!.
sum1(F,I,N,S):-N1 is N-1, sum1(F, I, N1, S1), S is S1+F+(N-1)*I.
