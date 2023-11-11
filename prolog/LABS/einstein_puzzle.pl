 /* la liste representant la rue */

/* albert est allemand*/


left_of(X,Y,L) :- append(_ , [X,Y | _], L ).

neighbor(X, Y, L) :- left_of(X,Y,L).
neighbor(X,Y,L) :- left_of(Y,X,L).

einstein(Owns , Street) :-
    Street = [
        [_,norvegian,_,_,_],
        [_,_,_,_,_],
        [_,_,_,_,milk],
        [_,_,_,_,_],
        [_,_,_,_,_]
    ],
    member([_,english,_,red,_],Street),
    left_of([_,_,_,green,_],[_,_,_,white,_],Street),
    member([_,danish,_,_,tea],Street),
    neighbor([niels,_,_,_,_],[_,_,cat,_,_],Street),
    member([eric,_,_,yellow,_],Street),
    member([albert,german,_,_,_],Street),
    neighbor([niels,_,_,_,_],[_,_,_,_,water],Street),
    member([peter,_,bird,_,_],Street),
    member([_,swedish,dog,_,_],Street),
    neighbor([_,norvegian,_,_,_],[_,_,_,blue,_],Street),
    neighbor([_,_,horse,_,_],[_,_,_,yellow,_],Street),
    member([alf,_,_,_,beer],Street),
    member([_,_,_,green,coffe],Street),
    member([Owns,_,fish,_,_],Street).




