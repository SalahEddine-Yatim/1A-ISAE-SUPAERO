mylength([], 0).
mylength([_|Q], N) :- mylength(Q, M), N is M + 1.
