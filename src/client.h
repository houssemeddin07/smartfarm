//#include <gtk/gtk.h>

//tache1: gestion des clients
typedef struct{
int Jour;
int Mois;
int Annee;
}OnsDate;


typedef struct{
char Id[30];
char Nom[30];
char Prenom[30];
char sexe [10];
char Adresse[50];
char Mail[50];
OnsDate ddn;
char sat[20];
}Client;

//tache2: taux d'absenteismes des ouvriers par mois 

typedef struct{

char Identifiant[30];
char nom[30];
char prenom[30];
char sexe[30];
char Adressemail;
int telephone;
OnsDate ddn;
}ouvrier;

int ajout_client (Client c);
int Modifier_client(Client c);
int supprimer_client(char Id[]);
void absen(int mois,int annee);
int add_abs(int id, int jour, int mois, int annee,int abs);
float taux(int mois,int annee);
