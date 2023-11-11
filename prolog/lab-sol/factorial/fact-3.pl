fact(0, 1).
fact(N, Y * N) :- N > 0, M = N - 1, fact(M, Y).
