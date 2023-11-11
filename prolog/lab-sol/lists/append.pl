myappend([], X, X).
myappend([T|Q], X, [T|R]) :- myappend(Q, X, R).
