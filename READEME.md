Soit la déclaration suivante pour un arbre binaire de recherche:
typedef struct nœud *parbre;
struct struct
{ char nom[20] ; // représente la clé de l’arbre binaire
parbre filsG, filsD;
};
Ecrire les fonctions suivantes :
1. void creation_fichier(char name_file[12]) qui permet de créer un fichier de chaînes de
caractères (une chaîne par ligne) dont le nom est name_file et de remplir ce fichier par des
noms de personnes.
2. void remplir_arbre(char name_file[12], parbre &A) qui permet de lire les mots du fichier
"name_file" et construit au fur et à mesure l’arbre binaire de recherche A avec ces mots.
3. void affiche_trier(parbre A) qui affiche la liste des mots dans l’ordre croissant.
4. int cherche(parbre A, char mot[20]) qui retourne 1 si le mot en paramètre figure dans l’arbre
et 0 sinon.
5. void sauvegarde(parbre A, FILE * f) qui permet de sauvegarder la liste triée des mots dans le
fichier pointé par f.
6. int feuilles(parbre A, FILE *f) qui permet de retourner le nombre de feuilles d’un arbre
binaire A donné et de stocker les informations contenues dans ces feuilles dans le fichier
pointé par F.
7. void inverse(parbre A) qui permet d’inverser le fils gauche et le fils droit de chaque nœud
dans un arbre binaire donné A.
8. void liberer(parbre &A) qui permet de libérer la place mémoire utilisée par l’arbre A.

