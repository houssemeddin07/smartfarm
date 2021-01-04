
#include <gtk/gtk.h>

typedef struct
{
int jour;
int mois;
int annee;
}TsnimDate;
typedef struct {
char Id [20];
char nom [20];
char prenom [20];
char sexe[10];
TsnimDate ddn;
char Adressemail [30];
int telephone;
char Adresse [20];
}tasnimouvrier;
typedef struct
{
int id;
int heur;
}absence;

int verifier_ouvrier(char o[], tasnimouvrier * c);

void ajouter_ouvrier(tasnimouvrier o);

void modifier_ouvrier(tasnimouvrier o);

void sup_ouvrier(char Id[]);

tasnimouvrier Get(char o[]);

absence absenn(int annee);

int add_abss(int id, int jour, int mois, int annee ,int abs);
