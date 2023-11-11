corridordouble(shed, garage).
corridordouble(garage, cellar).
corridordouble(garage, entrance).
corridordouble(entrance, bathroom).
corridordouble(entrance, attic).
corridordouble(entrance, salon).
corridordouble(bathroom, room1).
corridordouble(salon, kitchen).
corridordouble(salon, room2).
corridordouble(room1, room2).
corridordouble(kitchen, room2).
corridor(cellar, attic).

connected(X, Y) :- corridor(X, Y).
connected(X, Y) :- corridordouble(X, Y).
connected(X, Y) :- corridordouble(Y, X).
