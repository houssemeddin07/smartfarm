#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "equipement.h"
#include<gtk/gtk.h>

int ajouter_equipement (equipement E, char nom_fichier[] )
{
FILE * f;
equipement E2;

f=fopen(nom_fichier,"r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d\n",E2.ref,E2.marque,E2.type,&E2.D.jour,&E2.D.mois,&E2.D.annee)!=EOF)
{
if(strcmp(E2.ref,E.ref)==0)
{
fclose(f);
return -1;

}

}
fclose(f);
}
f=fopen(nom_fichier,"a+");
if(f!=NULL){
fprintf(f,"%s %s %s %d %d %d\n",E.ref,E.marque,E.type,E.D.jour,E.D.mois,E.D.annee);
fclose(f);
}
return 1;
}
int modifier_equipement(equipement* E,char nom_fichier[] )
{
FILE * f;
FILE * f1;
equipement E2;
int trouve=0;
char temp[20]="temp.txt";
f=fopen(nom_fichier,"r");
f1=fopen(temp,"w");
if(f!=NULL && f1!=NULL)
{
while (fscanf(f,"%s %s %s %d %d %d\n",E2.ref,E2.marque,E2.type,&E2.D.jour,&E2.D.mois,&E2.D.annee)!=EOF)
{
if (strcmp(E2.ref,E->ref)==0)
{
fprintf(f1,"%s %s %s %d %d %d\n",E->ref,E->marque,E->type,E->D.jour,E->D.mois,E->D.annee);
trouve=-1;}
else
{
fprintf(f1,"%s %s %s %d %d %d\n",E2.ref,E2.marque,E2.type,E2.D.jour,E2.D.mois,E2.D.annee);
}
}
fclose(f1);
fclose(f);
remove(nom_fichier);
rename(temp,nom_fichier);
if(trouve)
{return 1;}
else
{return 0;}

}
return -1;

}
equipement* rechreche_equipement(char ref[], char nom_fichier[]){
FILE * f;
equipement * E2=malloc(sizeof(equipement));
int trouve=0;
char temp[20]="tempo.txt";
f=fopen(nom_fichier,"r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d\n",E2->ref,E2->marque,E2->type,&E2->D.jour,&E2->D.mois,&E2->D.annee)!=EOF)
{printf("referance=%s\n",E2->ref);
if(strcmp(E2->ref,ref)==0)
{
fclose(f);
return E2;
}
}
fclose(f);
}
return NULL;
}
int supp_equipement(char ref[],char nom_fichier[])
{
FILE * f;
FILE * f1;
equipement E2;
int trouve=0;
char temp[20]="temp.txt";
f=fopen(nom_fichier,"r");
f1=fopen(temp,"w");
if(f!=NULL && f1!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d\n",E2.ref,E2.marque,E2.type,&E2.D.jour,&E2.D.mois,&E2.D.annee)!=EOF)
{
if(strcmp(E2.ref,ref)==0)
{
trouve=1;
}
else 
{
fprintf(f1,"%s %s %s %d %d %d\n",E2.ref,E2.marque,E2.type,E2.D.jour,E2.D.mois,E2.D.annee);
}
}
fclose(f1);
fclose(f);
remove(nom_fichier);
rename(temp,nom_fichier);
if (trouve)
{return 1;}
else
{return 0;}

}
return -1;
}
////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
enum {
IDENTIFIANT,
SEXE,
TYPE,
DATENAISSANCE,
COLUMNS
};

/////////////////////////////////////////////////////////////
enum
{
	E_REFERANCE,
	E_MARQUE,
	E_TYPE,
	E_DATE,
	COLUMNS_EQ,
};
void  afficher_equipements(GtkWidget *liste,GtkWidget *mecanique, GtkWidget* manuelle )
{
	GtkCellRenderer  *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore  *store;

char reference[50];
char marque [10];
char type [10];
char date[15];
store =NULL;

FILE * f;
char jour[5],mois[5],annee[5];

store=gtk_tree_view_get_model(liste);
if (store == NULL){
renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",E_REFERANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",E_MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",E_TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",E_DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS_EQ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);





f=fopen("equipement.txt","r");

if (f!=NULL){

while (fscanf(f,"%s %s %s %s %s %s\n",
reference,
marque,
type,
jour,
mois,
annee)!=EOF)
{

  strcpy(date,jour);
  strcat(date,"/");
  strcat(date,mois);
  strcat(date,"/");
  strcat(date,annee);
// SI VACHE CHECKBOX EST SELECTIONEE AJOUTER LA VACHE A LA LISTE SI TYPE EST VACHE
 if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(mecanique))&&strcmp(type,"mecanique")==0)
{	gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,E_REFERANCE,reference,E_MARQUE,marque,E_TYPE,type,E_DATE,date,-1);
}
// SI CHEVRE CHECKBOX EST SELECTIONEE AJOUTER LA CHEVRE A LA LISTE SI TYPE EST CHEVRE
else  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(manuelle))&&strcmp(type,"manuelle")==0)
{	gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,E_REFERANCE,reference,E_MARQUE,marque,E_TYPE,type,E_DATE,date,-1);
}



	
}

	
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
	
}
else g_print ("fichier introuvable\n");


}


//////////////////////////////////////////////////////////////////////
enum
{
	EREFERANCE,
	EMARQUE,
	ETYPE,
	EDATE,
	COLUMNS_ACH,
};
void afficher_equipement(GtkWidget *liste,int a)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

char referance[15];
char marque[10];
char type[10];
char date[10];
store=NULL;
FILE * f;
equipement E2;
char jour[5],mois[5],annee[5],Date[15];

store=gtk_tree_view_get_model(liste);
if (store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("referance",renderer,"text",EREFERANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column =
gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS_ACH,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("equipement.txt","r");

if (f!=NULL){
while (fscanf(f,"%s %s %s %s %s %s\n",referance,marque,type,jour,mois,annee)!=EOF){

strcpy(date,jour);
strcat(date,"/");
strcat(date,mois);
strcat(date,"/");
strcat(date,annee);
if(a==0 && (strcmp(type,"manuelle")==0))
{
	gtk_list_store_append(store,&iter);
fflush(stdin);
gtk_list_store_set(store,&iter,EREFERANCE,referance,EMARQUE,marque,ETYPE,type,EDATE,date,-1);

}
else if(a==1 &&(strcmp(type,"mecanique")==0))
{
	gtk_list_store_append(store,&iter);
fflush(stdin);
gtk_list_store_set(store,&iter,EREFERANCE,referance,EMARQUE,marque,ETYPE,type,EDATE,date,-1);


}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
else g_print("fichier introvable\n");



}
