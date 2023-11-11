mymember(T, [T|_]).
mymember(X, [_|Q]) :- mymember(X, Q).
