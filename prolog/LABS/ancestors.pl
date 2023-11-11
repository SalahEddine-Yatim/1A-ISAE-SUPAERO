/*la relation parent*/
parent(jack,mary).
parent(louis,jack).
parent(franck,john).
/* la relation ancestor */
ancestor(X,Y) :- parent(X,Y).
ancestor(X,Y) :- parent(Z,Y),ancestor(X,Z).

