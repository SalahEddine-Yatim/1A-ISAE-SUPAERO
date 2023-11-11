subset([], []).
subset([],[_|_]).
subset([ H | T1],[H | T2]):- subset(T1 , T2).                                                                                                                     
subset([ H | T1], [ _ | T2 ]) :-  append(_ , [H | T3] , T2) , subset(T1 , T3).

