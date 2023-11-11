add_wo_dup(X, L, L) :- member(X, L), !.
add_wo_dup(X, L, [X | L]).
