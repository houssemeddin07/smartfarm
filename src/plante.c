#ifdef HAVE_CONFIH_H
#include <config.h>
#endif
#include <gtk/gtk.h>
#include <string.h>
#include "plante.h"
#include <stdlib.h>
#include <stdio.h>


int ajout_plante(plante A, char nom_fichier[])
{
FILE * f;
plante A2;
 
f=fopen(nom_fichier,"r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %d %d %d\n",
A2.ID,
A2.type,
A2.nombre,
&A2.D.jour,
&A2.D.mois,
&A2.D.annee)!=EOF)
{
if ( strcmp(A2.ID,A.ID)==0)
{fclose(f);
return -1;
}
}
fclose(f);
}

f=fopen(nom_fichier,"a+");
if (f!=NULL){
fprintf(f,"%s %s %s %d %d %d\n",
A.ID,
A.type,
A.nombre,
A.D.jour,
A.D.mois,
A.D.annee);
fclose(f);
}
return 1;
}

int modifier_plante(plante * A,char nom_fichier[]){
FILE * f,* f1;
plante A3 ;
int trouve=0;
char temp[20]="tempo.txt";
f=fopen(nom_fichier ,"r");
f1=fopen(temp,"w");
if (f!=NULL && f1!=NULL){
while (fscanf(f,"%s %s %s %d %d %d\n",
A3.ID,
A3.type,
A3.nombre,
&A3.D.jour,
&A3.D.mois,
&A3.D.annee)!=EOF)
{
if (strcmp(A3.ID,A->ID)==0)
{
fprintf(f1,"%s %s %s %d %d %d\n",
A->ID,
A->type,
A->nombre,
A->D.jour,
A->D.mois,
A->D.annee);
trouve=1;
}
else
fprintf(f1,"%s %s %s %d %d %d\n",
A3.ID,
A3.type,
A3.nombre,
A3.D.jour,
A3.D.mois,
A3.D.annee);
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

plante* recherche_plante(char ID[],char nom_fichier[]){
FILE * f1;

plante * A2=malloc(sizeof(plante));
int trouve=0;
char temp[20]="tempo.txt";
f1=fopen(nom_fichier,"r");

if(f1!=NULL)
{
while(fscanf(f1,"%s %s %s %d %d %d\n",
A2->ID,
A2->type,
A2->nombre,
&A2->D.jour,
&A2->D.mois,
&A2->D.annee)!=EOF)
{
if(strcmp(A2->ID,ID)==0)
{
fclose(f1);
return A2;
}
}
fclose(f1);
}
return (NULL);
}


int supprimer_plante(char ID[],char nom_fichier[]){
FILE * f,* f1;
plante A2;
int trouve=0;
char temp[20]="tempo.txt";
f=fopen(nom_fichier,"r");
f1=fopen(temp,"w");
if (f!=NULL && f1!=NULL){
while (fscanf(f,"%s %s %s %d %d %d\n",
A2.ID,
A2.type,
A2.nombre,
&A2.D.jour,
&A2.D.mois,
&A2.D.annee)!=EOF)
{
if (strcmp(A2.ID,ID)==0)
{trouve=1;}
else
fprintf(f1,"%s %s %s %d %d %d\n",
A2.ID,
A2.type,
A2.nombre,
A2.D.jour,
A2.D.mois,
A2.D.annee);
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

enum{
ID,
TYPE,
NOMBRE,
DATEPLANTATION,
COLUMNS
};



void affichage_plante(GtkWidget *liste,int a)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id[40];
char type[10];
char nombre[10];
char DatePlantation[15];
store =NULL;

FILE * f;
plante A2;
char jour[5],mois[5],annee[5],date[15];
store=gtk_tree_view_get_model(liste);
if (store==NULL){
renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
g_print("ligne_1\n");
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nombre",renderer,"text",NOMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("DatePlantation",renderer,"text",DATEPLANTATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("plante.txt","r");
int i=2;
if(f!=NULL){
while (fscanf(f,"%s %s %s %s %s %s\n",id,type,nombre,jour,mois,annee)!=EOF)
{g_print("ligne_%d\n",i);
i++;
strcpy(DatePlantation,jour);
strcat(DatePlantation,"/");
strcat(DatePlantation,mois);
strcat(DatePlantation,"/");
strcat(DatePlantation,annee);

if(a==0 && (strcmp(type,"fruit")==0))
{
	gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,ID,id,TYPE,type,NOMBRE,nombre,DATEPLANTATION,DatePlantation,-1);
}
else if(a==1 && (strcmp(type,"legume")==0))
{	
	gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,ID,id,TYPE,type,NOMBRE,nombre,DATEPLANTATION,DatePlantation,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


else g_print("fichier introuvable\n");


g_print("ligne_%d\n",i+1);
}



void afficher_plante(char nom_fichier[]){
FILE * f;
plante A2;
f=fopen(nom_fichier,"r");
if (f!=NULL){
while(fscanf(f,"%s %s %s %d %d %d\n",
A2.ID,
A2.type,
A2.nombre,
&A2.D.jour,
&A2.D.mois,
&A2.D.annee)!=EOF){

printf("%s %s %s %d %d %d\n",
A2.ID,
A2.type,
A2.nombre,
A2.D.jour,
A2.D.mois,
A2.D.annee);
}
fclose(f);
}
}






/////////////////////////////////////////////////////////////
/*
enum{
ID,
TYPE,
NOMBRE,
DATEPLANTATION,
COLUMNS
};
*/
void  afficher_plantes(GtkWidget *liste,GtkWidget *legume, GtkWidget* fruit )
{
	GtkCellRenderer  *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore  *store;


char id[40];
char type[10];
char nombre[10];
char DatePlantation[15];
store =NULL;

FILE * f;
char jour[5],mois[5],annee[5];

store=gtk_tree_view_get_model(liste);
if (store == NULL){
renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nombre",renderer,"text",NOMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date de Plantation",renderer,"text",DATEPLANTATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);





f=fopen("plante.txt","r");

if (f!=NULL){

while (fscanf(f,"%s %s %s %s %s %s\n",
id,
type,
nombre,
jour,
mois,
annee)!=EOF)
{

  strcpy(DatePlantation,jour);
  strcat(DatePlantation,"/");
  strcat(DatePlantation,mois);
  strcat(DatePlantation,"/");
  strcat(DatePlantation,annee);
// SI LEGUME CHECKBOX EST SELECTIONEE AJOUTER LA LEGUME A LA LISTE SI TYPE EST LEGUME
 if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(legume))&&strcmp(type,"legume")==0)
{	gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,ID,id,TYPE,type,NOMBRE,nombre,DATEPLANTATION,DatePlantation,-1);
}
// SI FRUIT CHECKBOX EST SELECTIONEE AJOUTER LE FRUIT A LA LISTE SI TYPE EST FRUIT
else  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(fruit))&&strcmp(type,"fruit")==0)
{	gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,ID,id,TYPE,type,NOMBRE,nombre,DATEPLANTATION,DatePlantation,-1);
}



	
}

	
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
	
}
else g_print ("fichier introuvable\n");


}


//////////////////////////////////////////////////////////////////////


int existe (int annee, int tab_annee[], int n){

for (int i=0;i<n;i++)
{if (annee == tab_annee[i])
return 1;}

return 0;
}

void remplir_annee(char fichier_temperature[], int tab_annee[], int *n ){


int identifiant;
int i;
int jour;
int mois;
int annee;
int R;
float tmp;
FILE *f ;
*n=0;
f= fopen(fichier_temperature,"r");
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %d %f\n",&identifiant ,&jour ,&mois ,&annee ,&tmp)!=EOF)
{
if (!existe (annee,tab_annee,*n))
{tab_annee[*n]=annee;
(*n)++;}

}

fclose(f);
}

}



/*
char temperature[100]="temperature.txt";
*/

int annee_plus_seche(char fichier_temperature[])
{
int identifiant;
int i;
int jour;
int mois;
int annee;
int R;
float tmp;
float tab_somme_annee[10];
int tab_annee[10];
int n=0;
FILE *f ;
// INIT
for (int i=0;i<10;i++){
tab_somme_annee[i]=0.0;
tab_annee[i]=0;
}

// remplir annee dans tab
remplir_annee(fichier_temperature,tab_annee,&n );

f= fopen(fichier_temperature,"r");
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %d %f\n",&identifiant ,&jour ,&mois ,&annee ,&tmp)!=EOF)
{
if (identifiant==2)

{ for (int i=0;i<n;i++)
	if (annee == tab_annee[i])
		{tab_somme_annee[i]+= tmp;}
 }

}
fclose(f);
int index= maximum(tab_somme_annee,n);
return tab_annee[index];
}

return 0;
}

int maximum(float tab[],int n)
{
int i;
int index=0;
float max=tab[0];
for(i=0;i<n;i++)
{ //g_print("tab[%d]=%f\n",i,tab[i]);
if(tab[i]>max)
{max=tab[i];
index=i;}
}
return index;
}



 











