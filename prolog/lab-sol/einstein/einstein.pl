left_of(X, Y, L) :- append(_, [X, Y | _], L).

neighbor(X, Y, L) :- left_of(X, Y, L).
neighbor(X, Y, L) :- left_of(Y, X, L).

einstein(Owns, Street) :-
    Street = [house(_, norvegian, _, _, _),
              house(_, _, _, _, _),
              house(_, _, _, milk, _),
              house(_, _, _, _, _),
              house(_, _, _, _, _)
             ],
    member(house(red, english, _, _, _), Street),
    left_of(house(green, _, _, _, _), house(white, _, _, _, _), Street),
    member(house(_, danish, _, tea, _), Street),
    neighbor(house(_, _, _, _, niels), house(_, _, cat, _, _), Street),
    member(house(yellow, _, _, _, erick), Street),
    member(house(_, german, _, _, albert), Street),
    neighbor(house(_, _, _, _, niels), house(_, _, _, water, _), Street),
    member(house(_, _, bird, _, peter), Street),
    member(house(_, swedish, dog, _, _), Street),
    neighbor(house(_, norvegian, _, _, _), house(blue, _, _, _, _), Street),
    neighbor(house(_, _, horse, _, _), house(yellow, _, _, _, _), Street),
    member(house(_, _, _, beer, alf), Street),
    member(house(green, _, _, coffee, _), Street),
    member(house(_, _, fish, _, Owns), Street).

/* Query

   einstein(Owns, Street), writeln(Owns), nl, maplist(writeln, Street), nl.
   time((einstein(Owns, Street), writeln(Owns), nl, maplist(writeln, Street), nl)).
*/
