Exercice 2 :


La hauteur h d’un nœud dans un arbre binaire est définie récursivement :
- La hauteur d'un arbre vide est nulle.
- La hauteur d'un arbre non-vide est égale à la hauteur de sa racine.
- La hauteur d'un nœud est égale à 1 plus le maximum des hauteurs de ses sous-arbres.
Ecrire la fonction int hauteur(parbre A) qui retourne la hauteur d'un arbre A.
Exercice 3 :


A tout nœud d’un arbre binaire, on associe une valeur d qu’on appelle le déséquilibre du nœud :
- 0 si le nœud est une feuille,
- la hauteur du nœud si le nœud n’a qu’un fils,
- la différence entre la hauteur du fils gauche et la hauteur du fils droit du nœud sinon.
Ecrire la fonction int max_desequilibre(parbre A) qui retourne le maximum des valeurs absolues
des déséquilibres de ses nœuds.

