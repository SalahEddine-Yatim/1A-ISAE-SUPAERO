/* Factorial in Peano arithmetic */

/* Convert integers to Peano numbers */
peano_of_int(0, z) :- !.
peano_of_int(N, s(P)) :- M is N - 1, peano_of_int(M, P).

/* Convert Peano numbers to integers */
int_of_peano(z, 0).
int_of_peano(s(P), N) :- int_of_peano(P, M), N is M + 1.

/* Addition with Peano numbers
   Swap the two "operands" to help solution enumeration and
   avoid only "recursing" on the first operand.
 */
add(z, N, N).
add(s(X), Y, s(Z)) :- add(X, Y, Z).

/* Multiplication with Peano numbers
   Get rid first of simple cases (z * N = z, N * z = z).
   Then use definition with s(...) in the head of the clause
   to help recursion. Use addition first.
 */
mult(z, _, z).
mult(_, z, z).
mult(s(X), s(Y), s(R)) :- add(Z, s(Y), s(R)), mult(X, s(Y), Z).

/* Factorial with Peano numbers */
fact(z, s(z)).
fact(s(N), s(F)) :- mult(s(N), Z, s(F)), fact(N, Z).

fact_i(I, F) :- peano_of_int(I, P), fact(P, Z), int_of_peano(Z, F).
