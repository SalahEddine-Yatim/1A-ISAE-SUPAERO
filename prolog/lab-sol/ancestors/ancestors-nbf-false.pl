/**************************/
/* Definition of parent/2 */
/**************************/
parent(jack, mary).
parent(louise, jack).
parent(franck, john).

/****************************/
/* Definition of ancestor/2 */
/****************************/
ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(Z, Y), ancestor(X, Z).

/***************************************/
/* Definition of not_direct_ancestor/2 */
/***************************************/
not_direct_ancestor(X, Y) :- \+(parent(X, Y)), ancestor(X, Y).
