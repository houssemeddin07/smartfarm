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

int ajout_animal (animal m , char nom_fichier[]){
FILE * f;
animal m2;

// CONTROLLE DE SAISIE DATE
if (date_valide(m.D)==0)
	return 0;

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
