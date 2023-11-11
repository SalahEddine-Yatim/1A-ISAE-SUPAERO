fact(0, 1).
fact(N, Y) :-
    integer(N), N > 0, M is N - 1, fact(M, X), Y is X * N.
fact(N, Y) :-
    var(N), Y > 0, Last is ceiling(sqrt(Y)), between(1, Last, N),
    M is N - 1, R is Y mod N, R =:= 0, X is Y div N, fact(M, X).
