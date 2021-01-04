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

typedef struct 
{ char  nom[20];
  char  prenom[20];
  char  utilisateur[20];
  char  motdepasse[20];
  int   role;
}
utilisateur;


int ajouter_utilisateur( utilisateur u, char nom_fich[]);
int chercher_utilisateur(char utilis[],char motdepasse[], char nom_fich[], int * role);
void ajoutloginandpassword(char nomutilisateur[],char motdepasse[],char login_fichier[]);
void readData (char nomutilisateur[],char motdepasse[],char login_fichier[] );


void  afficher_animaux(GtkWidget *liste,GtkWidget *VacheCheckBox, GtkWidget* ChevreCheckBox,GtkWidget* MoutonCheckBox);
int ajout_animal (animal m , char nom_fichier[]);
int modifier_animal(animal* m,char nom_fichier[]);
int date_valide(DateNaissance D);
animal* recherche_animal(char identifiant[],char nom_fichier[]);
int supprimer_animal(char Identifiant[], char nom_fichier[]);
void affichage_animaux(char nom_fichier[]);
void afficher_nombre_de_troupeaux(int * v, int * m, int * c, char nom_fichier[]);
