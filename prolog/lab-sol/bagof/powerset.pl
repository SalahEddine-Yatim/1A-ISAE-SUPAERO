subseteq([], []).
subseteq([], [_ | _]).
subseteq([X | T1], [X | T2]) :- subseteq(T1, T2).
subseteq([X | T1], [_ | T2]) :- append(_, [X | T3], T2), subseteq(T1, T3).

powerset(Sets, Subsets) :- bagof(S, subseteq(S, Sets), Subsets).
