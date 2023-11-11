fact(0, 1).
fact(N, Y * N) :- fact(N - 1, Y).
