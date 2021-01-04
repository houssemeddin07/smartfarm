#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "callbacks.h"


int verifier_ouvrier(char o[] , tasnimouvrier * c)
{
tasnimouvrier ov;

int v=0; // 
FILE *f;
f=fopen("ouvrier.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d %s %d %s %s \n",ov.Id,
ov.nom,
ov.prenom,
&ov.ddn.jour,
&ov.ddn.mois,
&ov.ddn.annee,
ov.sexe,
&ov.telephone,
ov.Adressemail,
ov.Adresse)!=EOF)
{if (strcmp(o,ov.Id)==0)
{v=1;
*c=ov;
g_print("%s",c->nom);
}
}
}
fclose(f);

return v;
}


void ajouter_ouvrier(tasnimouvrier o1)
{
FILE *f;
f=fopen("ouvrier.txt","a");
if(f!=NULL)
{
fprintf(f,"%s %s %s %d %d %d %s %d %s %s \n",o1.Id,
o1.nom,
o1.prenom,
o1.ddn.jour,
o1.ddn.mois,
o1.ddn.annee,
o1.sexe,
o1.telephone,
o1.Adressemail,
o1.Adresse);
fclose(f);
}
}


void modifier_ouvrier(tasnimouvrier o)
{

    		    tasnimouvrier o1;
		    char name[20];char sub[50];
   		    FILE* F;
		    FILE* F_temp;
		    F=fopen("ouvrier.txt","r");
		    F_temp=fopen("temp.txt","w+");

		    while(fscanf(F,"%s %s %s %d %d %d %s %d %s %s \n",o1.Id,
o1.nom,
o1.prenom,
&o1.ddn.jour,
&o1.ddn.mois,
&o1.ddn.annee,
o1.sexe,
&o1.telephone,
o1.Adressemail,
o1.Adresse)!=EOF)
		    {

			if (strcmp(o.nom,o1.nom)==0)

			   { fprintf(F_temp,"%s %s %s %d %d %d %s %d %s %s  \n",o.Id,
o.nom,
o.prenom,
o.ddn.jour,
o.ddn.mois,
o.ddn.annee,
o.sexe,
o.telephone,
o.Adressemail,
o.Adresse);}
			else if (strcmp(o.nom,o1.nom)!=0)
 {	    fprintf(F_temp,"%s %s %s %d %d %d %s %d %s %s \n",o1.Id,
o1.nom,
o1.prenom,
o1.ddn.jour,
o1.ddn.mois,
o1.ddn.annee,
o1.sexe,
o1.telephone,
o1.Adressemail,
o1.Adresse);
}
		    }

		    fclose(F);
		    fclose(F_temp);
		    remove("ouvrier.txt");
		    rename("temp.txt","ouvrier.txt");
}
void sup_ouvrier(char Id[])
{

    		    tasnimouvrier o1;
		    char name[20];char sub[50];
   		    FILE* F;
		    FILE* F_temp;
		    F=fopen("ouvrier.txt","r");
		    F_temp=fopen("temp.txt","w+");

		    while(fscanf(F,"%s %s %s %d %d %d %s %d %s %s \n",o1.Id,
o1.nom,
o1.prenom,
&o1.ddn.jour,
&o1.ddn.mois,
&o1.ddn.annee,
o1.sexe,
&o1.telephone,
o1.Adressemail,
o1.Adresse)!=EOF)
		    {

			if (strcmp(o1.Id,Id)!=0)
 {	    fprintf(F_temp,"%s %s %s %d %d %d %s %d %s %s \n",o1.Id,
o1.nom,
o1.prenom,
o1.ddn.jour,
o1.ddn.mois,
o1.ddn.annee,
o1.sexe,
o1.telephone,
o1.Adressemail,
o1.Adresse);
}
		    }

		    fclose(F);
		    fclose(F_temp);
		    remove("ouvrier.txt");
		    rename("temp.txt","ouvrier.txt");
}



tasnimouvrier Get(char o[])
{
tasnimouvrier o1;
tasnimouvrier v; // salle non reserve
FILE *f;
f=fopen("ouvrier.txt","r");
strcpy(v.Id,"");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d %s %d %s %s \n",o1.Id,
o1.nom,
o1.prenom,
&o1.ddn.jour,
&o1.ddn.mois,
&o1.ddn.annee,
o1.sexe,
&o1.telephone,
o1.Adressemail,
o1.Adresse)!=EOF)
{if (strcmp(o,o1.Id)==0)

{v=o1;}
}
}
fclose(f);

return v;
}


absence absenn(int annee){
FILE *f,*f1;
int i,i1,i2,i3,i4;
int id;
int T[10];
int max=0;
absence k;
for (id=1;id<=9;id++){T[id]=0;}
f=fopen("absenteisme.txt","r");
if (f!=NULL){
 
while (fscanf(f,"%d %d %d %d %d\n",&i,&i1,&i2,&i3,&i4)!=EOF) 
 {for (id=1;id<=9;id++){
	if ((i==id) && (i3==annee) && (i4==1)){T[id]++;}
	}
	}
}
for (id=1;id<=9;id++){
	if (T[id]>T[max])
	{
	max=id;
	k.id=id;
	k.heur=T[id]*6;
	}
	}
fclose(f);
return k;
}

int add_abss(int id, int jour, int mois, int annee ,int abs){
int i,i1,i2,i3,i4;
FILE *f;
f=fopen("absenteisme.txt","a+");
int r=0;
if (f!=NULL){
 
while (fscanf(f,"%d %d %d %d %d \n",&i,&i1,&i2,&i3,&i4)!=EOF) 
	{
	if ((i==id) && (i1==jour) && (i2==mois) && (i3==annee)){
	r=1;}
	}
}
if (r==0){fprintf(f,"%d %d %d %d %d \n",id,jour,mois,annee,abs );}
fclose(f);
return r;
}


