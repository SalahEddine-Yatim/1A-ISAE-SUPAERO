:- include('robot-house.pl').

next_rooms(Room, Next_Rooms) :-
    findall(R, connected(Room, R), Next_Rooms).

append_list([], _, []).
append_list([A | Q], L2, [[A | L2] | R]) :-
    append_list(Q, L2, R).

next_paths([], []).
next_paths(L, Next) :-
    L = [[X | Q] | R],
    next_rooms(X, Next_Rooms),
    append_list(Next_Rooms, [X | Q], First_Paths),
    next_paths(R, Next_Paths),
    append(First_Paths, Next_Paths, Next).

path_to_room(_, [], _) :- fail.
path_to_room(Room, [[R | P1] | P2], Path) :-
    (R = Room -> Path = [R | P1];
                 path_to_room(Room, P2, Path)).

bfs(Paths, Room, Sol_Path) :-
    next_paths(Paths, Next_Paths),
    (path_to_room(Room, Next_Paths, Sol_Path) -> true;
     bfs(Next_Paths, Room, Sol_Path)).

sol_bfs(Start, End, Sol_Path) :-
    bfs([[Start]], End, S),
    reverse(S, Sol_Path).

/* There are shorter solutions! */
