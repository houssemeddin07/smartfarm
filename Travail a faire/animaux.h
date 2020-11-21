typedef struct {
int jour;
int mois;
int annee;

}DateNaissance;

typedef struct {
 char Identifiant[50];
 char sexe[10];
 char type [10];
 DateNaissance D;

} animal;

int ajout_animal (animal m , char nom_fichier[]);
int modifier_animal(animal* m,char nom_fichier[]);
animal* recherche_animal(char identifiant[],char nom_fichier[]);
int supprimer_animal(char Identifiant[], char nom_fichier[]);
void affichage_animaux(char nom_fichier[]);
void afficher_nombre_de_troupeaux(int * v, int * m, int * c, char nom_fichier[]);
