occurs(X, [X|_]) :- !.
occurs(X, [_|Q]) :- occurs(X, Q).
