#include <gtk/gtk.h>
/*
typedef struct
{
	char identifiant[20];
	char Type[20];
	char marque[20];
	int referance;	
}capteur;




void recherche(int *i,int *j, int *a, char nom_fichier[]);

void marqueCapDeffecteueux(char nomFichierValeurs[], char nomFichierCapteur[] ,char *marque, float min ,float max);
void ajoutMarque(char nomFichierCapteur[],char marque[30][],int *n);
int existe(char marque[30][],int *n,char nomMarque[]);
void remplirID(char cap[200][],int T[],int *m,char temperature[],float min ,float max);
int existeCapteur(char cap[200][],int *m,char ID[],int *index);
int maxT(int T[],int *m,char cap[200][],char capteur[]);
*/


int existeMarque(char marque[200][30], int n, char marq[]);
void remplirmarque(char marque[200][30], int *n,char nomFichierCapteur[]);
int existeCapteur(char IDcapteur[200][30], int m, char ID[] );
void remplirid (char IDcapteur[200][30], int *m,char marque[200][30], int n, int tab[], int *o, char temperaturefichier[],char nomFichierCapteur[], float min, float max);
int max (int tab[], int o);
void marqueCapDeffecteueux(char nomFichierValeurs[], char nomFichierCapteur[] ,char *marq, float min ,float max);


