Soient les déclarations suivantes :
typedef char string[80];
typedef struct nœud *ptr ;
struct nœud {string ch; ptr suiv; };
typedef ptr tab_ptr[40];
1. void inser_fin(ptr L, string S) qui permet d'insérer la chaine S à la fin de la liste L.
2. void inser_tete(ptr L, string S) qui permet d'insérer la chaine S à l'entête de la liste L.
3. void affiche_liste(ptr L) qui permet d'afficher la liste L.
4. int nb_noeud(ptr L) qui retourne le nombre de nœuds de la liste L.
5. int recherche_liste(ptr L, string S) qui retourne 1 si la chaîne S se trouve dans la liste L et 0
sinon.
6. int liste_occurrence_car(ptr L, char c) qui retourne le nombre d'occurrence du caractère c
dans toutes les chaines de la liste L.
7. char* concat_chaine_liste(ptr L) qui retourne une chaîne de caractères formée par la
concaténation des chaînes de caractères de la liste L. Les chaînes de caractères concaténées
doivent être séparées par le caractère espace.
8. void tri_liste(ptr L) qui permet de trier la liste dans l'ordre croissant en utilisant le tri à bulles.
9. int liste_egale(ptr L1, ptr L2) qui retourne 1 si les deux listes sont égales et 0 sinon.
10. int palindrome(string S) qui retourne 1 si la chaine S est palindrome et 0.
11. void liste_palindrome(ptr L, ptr LP) qui remplit la liste LP par les chaînes de la liste L qui
sont palindromes.
12. int liste_palindrome(ptr L) qui retourne 1 si toutes les chaînes de la liste L sont palindromes
et 0 sinon.
13. int tab_liste_palindrome(ptr_tab T, int n, ptr_tab TP, int np) qui permet de remplir le tableau
TP par les listes chaînées du tableau T qui contiennent que des chaînes qui sont palindromes.
14. void liste_nombre(ptr L, ptr LN) qui remplit la liste LN par les chaînes de la liste L qui sont
formées que par des caractères "nombres".
15. void liste_identificateu(ptr L, ptr LI) qui remplit la liste LI par les chaînes de la liste L qui
forment des identificateurs.

