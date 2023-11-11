fact(0 , 1).
fact(X , X*Y) :- X > 0 , M is X-1 ,fact(M , Y).
