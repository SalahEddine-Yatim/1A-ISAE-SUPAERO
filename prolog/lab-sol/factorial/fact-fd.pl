/* The following import is only used with SWI-Prolog. */
/* A warning will be emitted when using GNU Prolog,   */
/* but nothing harmful :).                            */
:- use_module(library(clpfd)).

fact(0, 1).
fact(N, F) :-
    N #> 0,
    N1 #= N - 1,
    F #= N * F1,
    fact(N1, F1).
