
/* on indique que les faits concernant on/2 et move/2 évoluent */
:- dynamic on/2.
:- dynamic move/2.
/*Une liste qui enregistre les mouvement initialisé comme [] */
:- dynamic list_move/1.
list_move([]).
 
/* Question 1 : representation  de la  situation*/ 

on(c,table).
on(b,c).
on(a,b).

/*Question 2 : placer X sur Y 
Les preconditons : Rien n'est sur X et Y 
(exeption pour la table on peut deposer plusieur objet sur la table )
postconditions : X est sur Y 
                Rien n'est sur l'objet precedant sur lequel était X 
                ou pour la table on supprime l'eta  on(X,table)*/

/*Question 3 et 4*/ 
/*Question 5 : il faut seulement ajouter la ligne assertz(move(X,Y)) pour enregistrer les mouvements des robot*/

put_on(X,table):- not(on(_,X)) , not(on(X,table)),
                  assertz(on(X,table)),
                  retract(on(X,_)),
                  retract(list_move(List)),
                  assertz(move(X,table)),
                  assertz(list_move([move(X,table)|List])). /* Mise a jour de la lise de mouvement*/
                  

put_on(X,Y) :-  not(Y = table) ,
                not(on(X,Y)),not(on(_,Y)) , not(on(_,X)),
                retract(on(X,_)),
                assertz(on(X,Y)),
                retract(list_move(List)),
                assertz(move(X,Y)),
                assertz(list_move([move(X,Y)|List])).  /* Mise a jour de la lise de mouvement*/
                  

/*Question 6 :
- put_on(a,table) : listing(move) -> move(a, table).  
- put_on(c,a) renvoie false : listing(move) -> move(a, table)
- put_on(b,table), put_on(c,a) : listing(move) -> move(a, table). move(b, table). move(c, a). */

/*Question 7*/ 
clear(X) :- on(Y,X) , clear(Y) , put_on(Y,table) , clear(X).

clear(_) . /* Condition d'arret de la reccurtion quand rien n'est sur X */ 

r_put_on(X,table) :- clear(X) , put_on(X,table).

r_put_on(X,Y) :- clear(X) , clear(Y) , put_on(X,Y).



/* Question 8 (a et b) la fonction achieve_beta execute dans l'ordre donné les buts à atteindre 
mais ce qu'on veut dire par achieve([on(a,c), on(c,b)]) c'est qu'il faut avoir dans le meme temps 
c sur b et a sur c par contre le resultat obtenu c'est a sur c puis on enleve a et on pose c sur b*/

achieve_beta([]) :- listing(list_move).  /*afficher la liste de mouvement quant on termine tous les buts*/ 
                  
achieve_beta([on(X,Y)|T]) :- (on(X,Y) -> ! ; r_put_on(X,Y)) , achieve_beta(T).


/*Question 8-c
L'idée pour trier la liste des buts est :
    Si on a une liste comme suite [on(b,c),on(d,table),on(c,d),on(a,b)] le bon ordre sera 
    [on(d,table),on(c,d),on(b,c),on(a,b)] si on inverse cette liste on aura [on(a,b),on(b,c),on(c,d)on(d,table)]
    On remarque que chaque fois on a la meme lettre ((a,b)(b,c)(c,d)(d,table))
    Donc c'est ça l'idée on va parcourir la premier liste et on va prendre le  premier element et l'inserer dans une liste The_right_order
    apres c'est inserer les autre buts dans le bon ordre  */


/*Voici une fonction qui traite le cas simple de 3 objet donc deux buts a satisfait */
execute_in_order([on(X,Y)|[on(A,B)]]) :- 
    (Y = A -> execute_in_order([on(A,B) | [on(X,Y)] ]) ; 
    ( (on(X,Y) -> ! ; r_put_on(X,Y)) ,
     (on(A,B) -> ! ; r_put_on(A,B)) ) ).

achieve([on(X,Y)|[on(A,B)]]) :- 
    execute_in_order([on(X,Y)|[on(A,B)]]),
    listing(list_move).
