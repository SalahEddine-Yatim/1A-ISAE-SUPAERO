fact(0, 1).
fact(X, Y) :- X > 0, N is X - 1, fact(N, Z), Y = X * Z.
