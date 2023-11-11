#lang racket

;; Bonjour, voici votre DM Racket 2023, vous allez pouvoir comparer le développement
;; d'un petit solveur en langage fonctionnel avec le projet que vous avez écrit en C...
;;
;; NB: modifiez ce fichier source Racket en écrivant directement vos définitions dedans...
;; Normalement, au fur et à mesure que vous écrivez les définitions, les tests unitaires présents
;; dans le fichier se débloquent pour tester ce que vous avez écrit...
;; Commencez tout de suite par cliquer sur le menu 'Check Syntax' en haut à droite, puis promenez
;; votre souris sur les symbôles... De manière régulière, lancez 'Run' (F5) aussi pour exécuter
;; les tests unitaires...
;;
;; NB2: les commentaires Racket démarrent par un point virgule et se terminent à la fin de la ligne.
;; En écrivant deux point-virgules au lieu d'un, cela permet d'être sûr que lorsqu'on décommente
;; toute une suite de lignes mélangeant lignes de code et lignes de commentaires, les commentaires
;; resteront bien précédés d'un point-virgule...
;;
;; NB3: toutes mes excuses si vous trouvez que le devoir est trop dirigé... J'ai pensé qu'une telle
;; approche permet à chacun d'aller jusqu'au bout en découvrant l'aspect 'batteries included' de
;; Racket.

;;***************************************************************************************
;; La définition qui suit permet de toujours lire le fichier "soko1.dat" pendant la phase de
;; développement. Si vous voulez fabriquer un programme exécutable qui permettra de spécifier
;; le puzzle à résoudre par un argument de la ligne de commande, remplacez la définition de
;; sokoban-puzzle par la ligne suivante :
;(define sokoban-puzzle (command-line #:args (name) name))
;; vous pourrez alors fabriquer un exécutable en compilant votre fichier racket avec la commande
;; raco exe DM2023.rkt
(define sokoban-puzzle "soko1.in")

(define input            (open-input-file sokoban-puzzle))
(define width            (read input)) ; la première ligne mentionne la hauteur du puzzle...
(define height           (read input)) ; ... puis la largeur
(define size             (* height width))
(define _                (read-line input)) ; lit ce qui pourrait encore rester sur la 1e ligne, et la fin de ligne
(define (truncate line)  (take (string->list line) width))  ; la liste des caractères d'une ligne
(define char-list        (flatten (map truncate (port->lines input)))) ; la liste des caractères du puzzle


;; définitions de quelques noms plus lisibles que les caractères correspondants
(define EMPTY            #\space)
(define PUSHER           #\@)
(define PARK             #\.)
(define BOX              #\$)
(define BOX_ON_PARK      #\*)
(define PUSHER_ON_PARK   #\+)
(define WALL             #\#)

(define steps                 (list (- width) width -1 +1))  ; une liste des déplacements...
(define assoc-dirs            (map cons steps (list #\N #\S #\W #\E))) ; ... et une liste associative donnant les directions cardinales
(define (step-name step)      (cdr (assoc step assoc-dirs)))  ; une petite fonction retournant la lettre cardinale associé à un pas
(define (display-steps steps) (displayln (list->string (map step-name steps)))) ; affichage d'une liste de pas


;;************************************************************************************************
;; Allez, on commence gentiment avec l'écriture de quelques prédicats qui simplifieront la lecture.
;; Changez les trois définitions suivantes pour définir des fonctions plutôt que des variables,
;; les trois fonctions prendront un paramètre (caractère) et diront respectivement si ce caractère
;; représente une case où se trouve un parking, une caisse, ou le personnage...

(define (is-park?  caractère)   (or (or (eq? caractère PARK ) (eq? caractère BOX_ON_PARK)) (eq? caractère PUSHER_ON_PARK)))
(define (is-box? caractère)     (or (eq? caractère BOX) (eq? caractère BOX_ON_PARK)))
(define (is-pusher? caractère)  (or (eq? caractère PUSHER) (eq? caractère PUSHER_ON_PARK)))

;; Remarques:
;; 1. il y a aussi un parking quand on lit le caractère BOX_ON_PARK (*) dans le fichier de puzzle
;; et de même quand on rencontre le caractère PUSHER_ON_PARK (+).
;; 2. = est réservé à la comparaison de nombres, utilisez equal? pour comparer toute autre chose,
;; ou eq? pour être efficace dans la comparaison de symboles ou de caractères comme ici.
;; 3. par pitié, n'utilisez pas de 'if' dans les trois définitions ci-dessus...
;; 4. ce qui suit est un test unitaire pour valider vos définitions
(require rackunit) ; importation du système de tests unitaires de Racket

(when is-park?   ; les tests ci-dessous ne sont faits que lorsque is-park? n'est plus false
  (check-true   (procedure? is-park?) "Écrivez une définition de fonction, pas de variable...")
  (check-equal? (procedure-arity is-park?) 1 "gardez un seul paramètre caractère!")
  (check-false (is-park? EMPTY))
  (check-false (is-park? PUSHER))
  (check-true  (is-park? PARK))
  (check-false (is-park? BOX))
  (check-true  (is-park? BOX_ON_PARK))
  (check-true  (is-park? PUSHER_ON_PARK))
  (check-false (is-park? WALL)))

(when is-box?   ; les tests ci-dessous ne sont faits que lorsque is-box? n'est plus false
  (check-true   (procedure? is-box?) "Écrivez une définition de fonction, pas de variable...")
  (check-equal? (procedure-arity is-box?) 1 "gardez un seul paramètre caractère!")
  (check-false (is-box? EMPTY))
  (check-false (is-box? PUSHER))
  (check-false (is-box? PARK))
  (check-true  (is-box? BOX))
  (check-true  (is-box? BOX_ON_PARK))
  (check-false (is-box? PUSHER_ON_PARK))
  (check-false (is-box? WALL)))

(when is-pusher?   ; blablabla...
  (check-true   (procedure? is-pusher?) "Écrivez une définition de fonction, pas de variable...")
  (check-equal? (procedure-arity is-pusher?) 1 "gardez un seul paramètre caractère!")
  (check-false (is-pusher? EMPTY))
  (check-true  (is-pusher? PUSHER))
  (check-false (is-pusher? PARK))
  (check-false (is-pusher? BOX))
  (check-false (is-pusher? BOX_ON_PARK))
  (check-true  (is-pusher? PUSHER_ON_PARK))
  (check-false (is-pusher? WALL)))

;; Définissez maintenant une fonction qui renvoie le caractère spécifié en paramètre,
;; mais "nettoyé" de ce qui pouvait se trouver dessus (personnage ou caisse). Par
;; exemple, le caractère BOX_ON_PARK est "nettoyé" en caractère PARK...

(define (clean caractère)
  (if (is-park? caractère)
      PARK
      (if (eq? caractère WALL)
          WALL
          EMPTY)))

(when clean
  (check-true   (procedure? clean) "Écrivez une définition de fonction, pas de variable...")
  (check-equal? (procedure-arity clean) 1 "gardez un seul paramètre caractère!")
  (check-equal? (clean EMPTY) EMPTY)
  (check-equal? (clean PUSHER) EMPTY)
  (check-equal? (clean PARK) PARK)
  (check-equal? (clean BOX) EMPTY)
  (check-equal? (clean BOX_ON_PARK) PARK)
  (check-equal? (clean PUSHER_ON_PARK) PARK)
  (check-equal? (clean WALL) WALL))

;;*****************************************************************************************
;; Quand vous voulez faire quelque chose sur une liste, il y a de fortes chances pour qu'une
;; fonction existe déjà dans la bibliothèque standard...
;; Définissez les deux variables suivantes (pas des fonctions):
;; - pusher-pos est l'indice du personnage dans la liste des caractères du puzzle (char-list,
;;     définie plus haut lors de la lecture du fichier) : utilisez une fonction de la bibliothèque
;;     qui cherche l'indice du premier élément d'une liste qui vérifie un certain prédicat
;; - boxes est la liste des positions des caisses dans les caractères du puzzle (char-list),
;;     utilisez une fonction de la bibliothèque qui renvoie la liste des indices des éléments
;;     d'une liste qui vérifient un certain prédicat
;; NB: les positions (du personnage ou des caisses) seront donc des indices dans la représentation
;; linéarisée du plan de l'entrepot, compris entre 0 et size-1 (enfin bien sûr certaines de ces
;; positions correspondent à des murs où ni le personnage ni les caisses ne peuvent se trouver...)

(define pusher-pos (index-where char-list is-pusher?))

(define boxes (indexes-where char-list is-box?))

(when pusher-pos
  (check-true (number? pusher-pos))
  (check-true (is-pusher? (list-ref char-list pusher-pos))))

(when boxes
  (check-true (list? boxes))
  (check-true (andmap number? boxes))
  (for ([pos (in-naturals)]
        [c char-list])
    (if (member pos boxes)
        (check-true  (is-box? c))
        (check-false (is-box? c)))))

;;*****************************************************************************************
;; Enfin, nous allons stocker la partie immuable du puzzle (le plan de l'entrepot)
;; dans une variable warehouse de type vector. "Nettoyez" (clean) la liste des caractères et
;; transformez la liste nettoyée en vecteur...
;; NB: pensez aux fonctions d'ordre supérieur

(define warehouse (list->vector (map clean char-list)))

(when warehouse
  (check-true   (vector? warehouse))
  (check-equal? (vector-length warehouse) size)
  (for ([c char-list]
        [pos (in-naturals)])
    (check-equal? (vector-ref warehouse pos)
                  (clean c))))

;; Écrivez deux petits prédicats pour vérifier que vous savez accéder à un élément d'un vecteur :
;; - on-park? indique si la position donnée en paramètre correspond à un parking dans l'entrepot
;; - in-wall? indique si la position donnée en paramètre correspond à un mur de l'entrepot

(define (on-park? pos) (is-park? (vector-ref warehouse pos)))
(define (in-wall? pos) (eq? (vector-ref warehouse pos) WALL))

(when on-park?
  (check-true   (procedure? on-park?))
  (check-equal? (procedure-arity on-park?) 1)
  (for ([c char-list]
        [pos (in-naturals)])
    (check-equal? (on-park? pos) (eq? PARK (clean c)))))

(when in-wall?
  (check-true   (procedure? in-wall?))
  (check-equal? (procedure-arity in-wall?) 1)
  (for ([c char-list]
        [pos (in-naturals)])
    (check-equal? (in-wall? pos) (eq? WALL c))))

;;*****************************************************************************************
;; Définissons maintenant un type structure (config), contenant :
;; - la position courante du personnage : pusher
;; - la liste des positions des caisses : boxes
;; - la pile (liste) des pas (déplacements relatifs) effectués depuis la configuration initiale : steps
(struct config   (pusher boxes steps))

;; Pouvez-vous donner un prédicat indiquant si une config est une solution ?
;; NB: pensez à l'ordre supérieur...
(define (success? config) (andmap on-park? (config-boxes config)))

(when success?
  (check-true   (procedure? success?))
  (check-equal? (procedure-arity success?) 1)
  (define cheat-boxes (for/list ([pos (in-naturals)][c char-list] #:when (is-park? c))  pos))
  (check-not-false (success? (config pusher-pos cheat-boxes empty))))

;;******************************************************************************************
;; Intéressons-nous maintenant à la génération des nouvelles configurations :
;; une fonction configs-issued-from vous est donnée presque entièrement, illustrant un style
;; de programmation Racket recommandé (des petites définitions plutôt que des 'let' qui augmentent
;; davantage l'indentation, un 'cond' plutôt que des if imbriqués (pour la même raison)).
;; Toutefois elle renvoie systématiquement la valeur false finale, au lieu d'une liste des
;; au plus 4 configurations possibles obtenues en déplaçant le personnage suivant les 4 pas possibles
;; (cf. valeurs de la liste steps définie plus haut).
;; Étudiez la fonction interne new-config-from afin de comprendre son fonctionnement et utilisez
;; la pour renvoyer la liste des configurations atteignables depuis la configuration fournie en
;; paramètre.
;; NB: comme d'habitude, pensez aux fonctions d'ordre supérieur

(define (configs-issued-from cfg)
  (define boxes              (config-boxes cfg))  ; la liste des positions courantes des caisses
  (define (new-config-from step)                  ; renvoie une nouvelle config si le déplacement step est possible, false sinon
    (define new-pusher-pos   (+ (config-pusher cfg) step))   ; la nouvelle position du personnage s'il se déplace selon le pas indiqué
    (define updated-path     (cons step (config-steps cfg))) ; la nouvelle pile des pas lorsqu'on ajoute le pas indiqué
    (define behind-new-pos   (+ new-pusher-pos step))        ; un pas de plus dans la même direction: derrière la caisse
    (define (has-box? pos)   (member pos boxes))             ; la position indiquée fait-elle partie des positions des caisses ?
    (define (move-box)       (list-set boxes (index-of boxes new-pusher-pos) behind-new-pos)) ; les positions des caisses mises à jour si une bouge
    (cond  ; cette forme date de Mathusalem mais est bien pratique: le premier test qui est vrai voit sa valeur associée renvoyée
      [(in-wall? new-pusher-pos)       false]            ; passe-muraille interdit...
      [(not (has-box? new-pusher-pos)) (config new-pusher-pos boxes updated-path)] ; test précédent => pas de mur; ce test: pas de caisse => on y va
      [(in-wall? behind-new-pos)       false]            ; tests précédents => une caisse à pousser; ce test: caisse bloquée contre un mur
      [(has-box? behind-new-pos)       false]            ; tests précédents => une caisse à pousser; ce test: caisse bloquée contre une 2e caisse
      [else                            (config new-pusher-pos (move-box) updated-path)])) ; tests précédents => on peut pousser la caisse
 
  (filter-not (lambda (x) (equal? x false)) (map new-config-from steps))) ; remplacez false pour compléter la fonction configs-issued-from

(when (configs-issued-from (config pusher-pos boxes steps))
  (define new-configs (configs-issued-from (config pusher-pos boxes steps)))
  (check-true (list? new-configs))
  (check-true (< 0 (length new-configs) 5)) ; à moins que le personnage soit bloqué dès le départ...
  (check-true (andmap config? new-configs)))

;;*******************************************************************************************
;; Insérez ici votre implémentation d'une file (queue) sans effet de bord :

(struct queue (list stack))
(define (queue-empty? q)
  (and (empty? (queue-list q))
       (empty? (queue-stack q))))

(define (queue-add elmt q)
  (queue (queue-list q) (cons elmt (queue-stack q))))

(define (queue-head   q)
  (if (empty? (queue-list q))
      (last (queue-stack q))
      (first (queue-list q))))

(define (queue-tail   q)
  (if (empty? (queue-list q))
      (queue (rest(reverse (queue-stack q))) empty)
      (queue (rest (queue-list q)) (queue-stack q))))

(when queue-empty?
  (check-true   (procedure? queue-empty?))
  (check-equal? (procedure-arity queue-empty?) 1)
  (check-true   (queue-empty? (queue empty empty)))
  (check-false  (queue-empty? (queue '(a) empty)))
  (check-false  (queue-empty? (queue empty '(a))))
  (check-false  (queue-empty? (queue '(a) '(b)))))

(when queue-add
  (check-true   (procedure? queue-add))
  (check-equal? (procedure-arity queue-add) 2)
  (check-equal? '(a b c) (queue-list (queue-add 'f (queue '(a b c) '(e d)))))
  (check-equal? '(f e d) (queue-stack (queue-add 'f (queue '(a b c) '(e d))))))
  
(when queue-head
  (check-true   (procedure? queue-head))
  (check-equal? (procedure-arity queue-head) 1)
  (check-equal? 'a (queue-head (queue '(a b c) empty)))
  (check-equal? 'a (queue-head (queue empty '(c b a)))))

(when queue-tail
  (check-true   (procedure? queue-head))
  (check-equal? (procedure-arity queue-head) 1)
  (check-equal? '(b c) (queue-list (queue-tail (queue '(a b c) empty))))
  (check-true  (empty? (queue-list (queue-tail (queue '(a) empty)))))
  (check-equal? '(b c) (queue-list (queue-tail (queue empty '(c b a))))))

;;*******************************************************************************************
;; Nous voilà finalement rendu à la dernière étape, la fonction Breadth-First-Search...
;; La fonction bfs(S, Q) où S est l'ensemble des États déjà rencontrés et Q la file des
;; Configurations encore à traiter, renvoie :
;; - false si la file Q est vide (pas de solution)
;; - queue-head(Q) si c'est une solution (c'est donc la première solution rencontrée)
;; - bfs(S',Q') sinon. (i.e récursion terminale = boucle)
;;
;; où : S' = S ∪ S2, et Q' est la file Q augmentée des Configurations de C2,
;; et avec:
;; - C1 l'ensemble des Configurations atteignables depuis queue-head(Q), et S1 l'ensemble
;; des États correspondants
;; - C2 l'ensemble des Configurations C1 dont les États ne sont pas dans S (i.e n'ont pas
;; été déjà rencontrés), et S2 l'ensemble des États correspondants aux configurations de C2
;; 
;; NB: on voit l'introduction d'un type État différent de Configuration :
;; en effet, il ne serait pas judicieux de stocker l'ensemble des configurations déjà rencontrées,
;; puisque les configurations contiennent la pile des déplacements effectuées par le personnage.
;; Ce chemin parcouru par le personnage sera toujours différent pour nos configurations puisqu'il
;; représente le chemin depuis la racine dans l'arbre des déplacements du personnage : le garder
;; dans les États éliminerait la détection d'une situation (position du personnage et des caisses)
;; déjà rencontrée... Pour définir un État, vous pouvez au choix définir une structure etat,
;; ou simplement sans la nommer construire une paire pointée entre la position du joueur et l'ensemble
;; des positions des caisses.

;; => Écrivez une petite fonction (config->state cfg) qui renvoie l'État correspondant à une configuration

(define (config->state cfg)
  (cons (config-pusher cfg) (list->set (config-boxes cfg))))

(when config->state
  (check-true   (procedure? config->state))
  (check-equal? (procedure-arity config->state) 1))

;;
;; NB2: pour les performances, il est intéressant par contre que ce soit bien un ensemble des positions
;; des caisses qui constitue l'État (avec la position du joueur), et non une simple liste :
;; une liste est ordonnée, cela reviendrait à numéroter les caisses, et empêcher l'élimination de
;; situations déjà rencontrées à une permutation de caisses près. Transformez donc votre liste des caisses
;; (config-boxes cfg) en ensemble pour fabriquer votre État.
;;
;; Hints:
;; - n'hésitez pas à écrire des toutes petites fonctions internes pour rendre votre fonction intelligible,
;;    par exemple vous pouvez définir  un prédicat (in-encountered? cfg) qui dira si l'État associé à cfg
;;    a déjà été rencontré (i.e se trouve dans l'ensemble encountered).
;; - regardez dans la bibliothèque les fonctions qui permettent de travailler avec les ensembles
;; - map, filter et leurs variantes sont vos amis...
;; - foldl/foldr permettent d'éviter des récursions, jetez un oeil à for/fold si vous préférez ce style
     
(define (bfs encountered unexplored)
  (define (is-encountered? cfg)
    (set-member? encountered (config->state cfg)))
  
  (define (new-etats S Q)
    (define C1 (configs-issued-from (queue-head Q)))
    (define C2 (filter-not is-encountered? C1))
    (define S2 (list->set (map config->state C2)))
    (define new-S (set-union S S2))
    (define new-Q (queue-tail Q))
    (for/list ([x C2])
      (set! new-Q (queue-add x new-Q)))
    (bfs new-S new-Q))
  
  (if (queue-empty? unexplored)
      false
      (if (success? (queue-head unexplored))
          (queue-head unexplored)
          (new-etats encountered unexplored))))

(define (sokoban-solver puzzle)
  (time (bfs (set (config->state puzzle)) (queue (list puzzle) empty))))

(define solution (sokoban-solver (config pusher-pos boxes empty)))
(if solution
    (display-steps (reverse (config-steps solution)))
    (displayln "No solution!"))