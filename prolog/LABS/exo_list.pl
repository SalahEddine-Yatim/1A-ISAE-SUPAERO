/*mylength*/
/*
    -la longueur de la liste vide est 0
    -la longueur d'une liste non vide est 1 + la longueur de la queue de la liste 
*/

my_length([],0).
my_length([_ | T], N) :-  my_length(T,M), N is M+1 .

my_length2([],0).
my_length2(L,N) :- L=[_|T] ,my_length2(T,M) , N is M+1 .


/*my_append*/

my_append([],L,L).
my_append([H|T],L,[H|M] ):- my_append(T,L,M) .

/*my_member*/

my_member(X,[X|_]).
my_member(X,[_|Q]) :- my_member(X,Q).
