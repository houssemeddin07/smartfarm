
#include <gtk/gtk.h>
typedef struct{
int jour;
int mois;
int annee;
}date;

typedef struct{
char ID[50];
char type[50];
char nombre[10];
date D;
}plante;

int ajout_plante(plante A,char nom_fichier[]);
int modifier_plante(plante *A,char nom_fichier[]);
int supprimer_plante(char ID[],char nom_fichier[]);
void afficher_plante(char nom_fichier[]);
plante* recherche_plante(char ID[],char nom_fichier[]);
void affichage_plante(GtkWidget *liste,int a);
void  afficher_plantes(GtkWidget *liste,GtkWidget *legume, GtkWidget* fruit);
//float annee_plus_seche(char temperature[]);
//float max(float tab[]);
int existe (int annee, int tab_annee[], int n);
int maximum(float tab[],int n);
void remplir_annee(char fichier_temperature[], int tab_annee[], int *n );
int annee_plus_seche(char fichier_temperature[]);




