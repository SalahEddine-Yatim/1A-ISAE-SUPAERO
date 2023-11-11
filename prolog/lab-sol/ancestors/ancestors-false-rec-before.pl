/**************************/
/* Definition of parent/2 */
/**************************/
parent(jack, mary).
parent(louise, jack).
parent(franck, john).

/****************************/
/* Definition of ancestor/2 */
/****************************/
ancestor(X, Y) :- ancestor(X, Z), parent(Z, Y).
ancestor(X, Y) :- parent(X, Y).
