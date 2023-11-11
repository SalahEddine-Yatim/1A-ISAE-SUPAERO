:- include('robot-house.pl').

notmember(X, []).
notmember(X, [H | T]) :- X \= H, notmember(X, T).

path(X, X, [X], _).
path(X, Y, [X | P], Visited) :- connected(X, Z),
                                notmember(Z, Visited),
                                path(Z, Y, P, [Z | Visited]).
