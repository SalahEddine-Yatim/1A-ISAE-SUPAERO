:- include('robot-house.pl').

path(X, X, [X], _).
path(X, Y, [X | P], Visited) :- connected(X, Z),
                                \+ member(Z, Visited),
                                path(Z, Y, P, [Z | Visited]).

better(X, Y, P1, P2, Visited) :- path(X, Y, P1, Visited),
                                 length(P1, L1),
                                 length(P2, L2),
                                 L1 < L2.

shortest_path(X, Y, P, Visited) :- path(X, Y, P, Visited),
                                   \+ better(X, Y, _, P, Visited).
