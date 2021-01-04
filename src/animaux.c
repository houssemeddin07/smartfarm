#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gtk/gtk.h>
#include <string.h>
#include "animaux.h"
#include <stdlib.h>
#include <stdio.h>

int date_valide (DateNaissance D){
int bisextille=0;

if (D.annee<0 || D.jour<1 || D.jour>31 || D.mois<1 || D.mois>12)
	return 0;

if (D.annee%4==0){

	if (D.annee%100==0){

		if (D.annee%400==0)
			bisextille=1;
		else
			bisextille=0;
	}
	else
		bisextille=1;
		}

else bisextille=0;

switch(D.mois){
case 1:
	return 1;
break;
case 2:
	if(bisextille==0 && D.jour>28)
		return 0;
	else if (bisextille==1 && D.jour>29)
		return 0;
	else
		return 1;
break;
case 3: 	
		return 1;
break;
case 4:
	if (D.jour>30)
		return 0;
	else 	
		return 1;
break;
case 5: 	
		return 1;
break;
case 6:
	if (D.jour>30)
		return 0;
	else 	
		return 1;
break;
case 7: 	
		return 1;
break;
case 8: 	
		return 1;
break;
case 9:
	if (D.jour>30)
		return 0;
	else 	
		return 1;
break;
case 10: 	
		return 1;
break;
case 11:
	if (D.jour>30)
		return 0;
	else 	
		return 1;
break;
case 12: 	
		return 1;
break;	
}


}


void ajoutloginandpassword(char nomutilisateur[],char motdepasse[],char login_fichier[]){

FILE * f;
utilisateur u2;


f=fopen(login_fichier,"w");
if (f!=NULL){
fprintf(f,"%s %s\n",nomutilisateur,motdepasse);
fclose(f);
}


}

void readData (char nomutilisateur[],char motdepasse[],char login_fichier[] ){


FILE * f;


f=fopen(login_fichier,"r");
if (f!=NULL){

while (fscanf(f,"%s %s\n",nomutilisateur,motdepasse)!=EOF)
{ }
fclose(f);}


}

int ajouter_utilisateur( utilisateur u, char nom_fich[])
{

FILE * f;
utilisateur u2;



f=fopen(nom_fich,"r");
if (f!=NULL){

while (fscanf(f,"%s %s %s %s %d\n",
u2.nom,
u2.prenom,
u2.utilisateur,
u2.motdepasse,
&u2.role)!=EOF)
{ 
 if ( strcmp(u2.utilisateur,u.utilisateur)==0)
   { fclose(f); return -1; }
     }
fclose(f);}

f=fopen(nom_fich,"a+");
if (f!=NULL){
fprintf(f,"%s %s %s %s %d\n",
u.nom,
u.prenom,
u.utilisateur,
u.motdepasse,
u.role);
fclose(f);
}

return 1;

}

int chercher_utilisateur(char utilis[],char motdepasse[], char nom_fich[], int * role){

FILE * f;
utilisateur u2;



f=fopen(nom_fich,"r");
if (f!=NULL){

while (fscanf(f,"%s %s %s %s %d\n",
u2.nom,
u2.prenom,
u2.utilisateur,
u2.motdepasse,
&u2.role)!=EOF)
{ 
 if ( strcmp(u2.utilisateur,utilis)==0 && strcmp(u2.motdepasse,motdepasse)==0)
   { fclose(f);*role=u2.role; return 1; }
     }
fclose(f);}

return -1;


}


int ajout_animal (animal m , char nom_fichier[]){
FILE * f;
animal m2;

// CONTROLLE DE SAISIE DATE
//if (date_valide(m.D)==0)
//	return 0;

f=fopen(nom_fichier,"r");
if (f!=NULL){

while (fscanf(f,"%s %s %s %d %d %d\n",
m2.Identifiant,
m2.sexe,
m2.type,
&m2.D.jour,
&m2.D.mois,
&m2.D.annee)!=EOF)
{
 if ( strcmp(m2.Identifiant,m.Identifiant)==0)
   { fclose(f); return -1; }
     }
fclose(f);}

f=fopen(nom_fichier,"a+");
if (f!=NULL){
fprintf(f,"%s %s %s %d %d %d\n",
m.Identifiant,
m.sexe,
m.type,
m.D.jour,
m.D.mois,
m.D.annee);
fclose(f);
}

return 1;}



int modifier_animal(animal * m,char nom_fichier[]){
FILE * f,* f1;
animal m2;
int trouve=0;
char temp[20]="tempo.txt";


f=fopen(nom_fichier,"r");
f1=fopen(temp,"w");
if (f!=NULL && f1!=NULL){

while (fscanf(f,"%s %s %s %d %d %d\n",
m2.Identifiant,
m2.sexe,
m2.type,
&m2.D.jour,
&m2.D.mois,
&m2.D.annee)!=EOF)
{
 if (strcmp(m2.Identifiant,m->Identifiant)==0)
 	
 	{
	g_print("%s\n",m->Identifiant);
	fprintf(f1,"%s %s %s %d %d %d\n",
 	m->Identifiant,
 	m->sexe,
 	m->type,
 	m->D.jour,
 	m->D.mois,
 	m->D.annee);
	trouve=1;}
 else
	fprintf(f1,"%s %s %s %d %d %d\n",
 	m2.Identifiant,
 	m2.sexe,
 	m2.type,
 	m2.D.jour,
 	m2.D.mois,
 	m2.D.annee);
}

	fclose(f1);
	fclose(f);
	remove(nom_fichier);
	rename(temp,nom_fichier);
	if (trouve)
		return 1;
	else
		return 0;
}

return -1;
}
animal * recherche_animal(char identifiant[],char nom_fichier[]){

FILE * f;
animal * m2= malloc(sizeof (animal));
int trouve=0;
char temp[20]="tempo.txt";
f=fopen(nom_fichier,"r");

if (f!=NULL){

while (fscanf(f,"%s %s %s %d %d %d\n",
m2->Identifiant,
m2->sexe,
m2->type,
&m2->D.jour,
&m2->D.mois,
&m2->D.annee)!=EOF)
{
 if (strcmp(m2->Identifiant,identifiant)==0)
 	
 	{fclose(f);
	return m2;}
 
}
fclose(f);
}
	
 return NULL;	
}
int supprimer_animal(char Identifiant[], char nom_fichier[]){
FILE * f,* f1;
animal m2;
int trouve=0;
char temp[20]="tempo.txt";
f=fopen(nom_fichier,"r");
f1=fopen(temp,"w");
if (f!=NULL && f1!=NULL){

while (fscanf(f,"%s %s %s %d %d %d\n",
m2.Identifiant,
m2.sexe,
m2.type,
&m2.D.jour,
&m2.D.mois,
&m2.D.annee)!=EOF)
{
 if (strcmp(m2.Identifiant,Identifiant)==0)
 	
 	{trouve=1;}
 else
	fprintf(f1,"%s %s %s %d %d %d\n",
 	m2.Identifiant,
 	m2.sexe,
 	m2.type,
 	m2.D.jour,
 	m2.D.mois,
 	m2.D.annee);
}

	fclose(f1);
	fclose(f);
	remove(nom_fichier);
	rename(temp,nom_fichier);
	if (trouve)
		return 1;
	else
		return 0;
}

return -1;}
void affichage_animaux(char nom_fichier[]){

FILE * f;
animal m2;


f=fopen(nom_fichier,"r");

if (f!=NULL){

while (fscanf(f,"%s %s %s %d %d %d\n",
m2.Identifiant,
m2.sexe,
m2.type,
&m2.D.jour,
&m2.D.mois,
&m2.D.annee)!=EOF)
{
 
	printf("%s %s %s %d %d %d\n",
 	m2.Identifiant,
 	m2.sexe,
 	m2.type,
 	m2.D.jour,
 	m2.D.mois,
 	m2.D.annee);
}

	
	fclose(f);
	
}

}

void afficher_nombre_de_troupeaux(int *v, int *m, int *c, char nom_fichier[]){
FILE * f;
animal m2;
f=fopen(nom_fichier,"r");

if (f!=NULL){

while (fscanf(f,"%s %s %s %d %d %d\n",
m2.Identifiant,
m2.sexe,
m2.type,
&m2.D.jour,
&m2.D.mois,
&m2.D.annee)!=EOF)
{
 if (strcmp(m2.type,"vache")==0)
 	
 	(*v)++;
 else if (strcmp(m2.type,"chevre")==0)
	(*c)++;

 else if (strcmp(m2.type,"mouton")==0)
	(*m)++;
}

	
	fclose(f);
	
}

}

/////////////////////////////////////////////////////////////
enum {
IDENTIFIANT,
SEXE,
TYPE,
DATENAISSANCE,
COLUMNS
};

/////////////////////////////////////////////////////////////
//void afficher_animaux(GtkWidget *liste)
void  afficher_animaux(GtkWidget *liste,GtkWidget *VacheCheckBox, GtkWidget* ChevreCheckBox,GtkWidget* MoutonCheckBox)
{
	GtkCellRenderer  *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore  *store;

char Identifiant[50];
char sexe [10];
char type [10];
char DateNaissance[15];
store =NULL;

FILE * f;
animal m2;
char jour[5],mois[5],annee[5],date[15];

store=gtk_tree_view_get_model(liste);
if (store == NULL){
renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("DateNaissance",renderer,"text",DATENAISSANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);





f=fopen("animaux.txt","r");

if (f!=NULL){

while (fscanf(f,"%s %s %s %s %s %s\n",
Identifiant,
sexe,
type,
jour,
mois,
annee)!=EOF)
{

  strcpy(DateNaissance,jour);
  strcat(DateNaissance,"/");
  strcat(DateNaissance,mois);
  strcat(DateNaissance,"/");
  strcat(DateNaissance,annee);
// SI VACHE CHECKBOX EST SELECTIONEE AJOUTER LA VACHE A LA LISTE SI TYPE EST VACHE
 if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(VacheCheckBox))&&strcmp(type,"vache")==0)
{	gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,IDENTIFIANT,Identifiant,SEXE,sexe,TYPE,type,DATENAISSANCE,DateNaissance,-1);
}
// SI CHEVRE CHECKBOX EST SELECTIONEE AJOUTER LA CHEVRE A LA LISTE SI TYPE EST CHEVRE
else  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(ChevreCheckBox))&&strcmp(type,"chevre")==0)
{	gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,IDENTIFIANT,Identifiant,SEXE,sexe,TYPE,type,DATENAISSANCE,DateNaissance,-1);
}
// SI MOUTON CHECKBOX EST SELECTIONEE AJOUTER LE MOUTON A LA LISTE SI TYPE EST MOUTON
else  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(MoutonCheckBox))&&strcmp(type,"mouton")==0)
{	gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,IDENTIFIANT,Identifiant,SEXE,sexe,TYPE,type,DATENAISSANCE,DateNaissance,-1);
}


	
}

	
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
	
}
else g_print ("fichier introuvable\n");


}

