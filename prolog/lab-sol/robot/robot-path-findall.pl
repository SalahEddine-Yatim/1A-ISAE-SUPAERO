:- include('robot-house.pl').

path(X, X, [X], _).
path(X, Y, [X | P], Visited) :- connected(X, Z),
                                \+ member(Z, Visited),
                                path(Z, Y, P, [Z | Visited]).

/* find the list of minimum length in a list of lists */
min_length([L], L).
min_length([H | L], M) :- min_length(L, N),
                          length(H, L1), length(N, L2),
                          (L1 < L2 -> M = H ; M = N).

shortest_path(X, Y, ShortestPath, Visited) :- findall(P, path(X, Y, P, Visited), AllPaths),
                                              min_length(AllPaths, ShortestPath).
