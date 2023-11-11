fact(0, 1).
fact(N, Y * N) :- N > 0, fact(N - 1, Y).
