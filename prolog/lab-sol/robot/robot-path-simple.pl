:- include('robot-house.pl').

path(X, X, [X]).
path(X, Y, [X | P]) :- connected(X, Z), path(Z, Y, P).
