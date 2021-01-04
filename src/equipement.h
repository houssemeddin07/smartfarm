#include<gtk/gtk.h>

typedef struct {
int jour;
int mois;
int annee;
}Date;
typedef struct {
char ref[15];
char marque[10];
char type[10];
Date D;
}equipement;
int ajouter_equipement(equipement E, char nom_fichier[] );
int modifier_equipement(equipement* E,char nom_fichier[] );
int supp_equipement(char ref[],char nom_fichier[]);
void afficher_equipement(GtkWidget *liste,int a);
equipement* rechreche_equipement(char ref[], char nom_fichier[]);
void afficher_la_marque_le_plus_diffecteux();
void  afficher_equipements(GtkWidget *liste,GtkWidget *mecanique, GtkWidget* manuelle );
