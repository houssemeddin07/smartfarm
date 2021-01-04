#include <stdio.h>
#include "capteur.h"
#include <string.h>
#include <stdlib.h>


/////////////////////////////////////
int ajouter (capteur C){
FILE *f;
capteur c1;
f=fopen("capteur.txt","a+");
	if (f!=NULL){

	while (fscanf(f,"%s %s %s %d %s\n",
	c1.identifiant,
	c1.type,
	c1.marque,
	&c1.reference,
	c1.etat)!=EOF)
 		{
		if ( strcmp(c1.identifiant,C.identifiant)==0)
		{ fclose(f);  return -1; }
  		}
	fclose(f);}

f=fopen("capteur.txt","a+");
if (f!=NULL){
fprintf(f,"%s %s %s %d %s\n",
C.identifiant,
C.type,
C.marque,
C.reference,
C.etat);
fclose(f);
}

return 1;}


void modifier (capteur c){
FILE *f, *f1;
capteur c1;

f=fopen("capteur.txt","a+");
f1=fopen("tamp.txt","a+");
while (fscanf(f,"%s %s %s %d %s\n",c1.identifiant,c1.type,c1.marque,&c1.reference,c1.etat)!=EOF)
{
if ((strcmp(c.identifiant,c1.identifiant)!=0))
{
fprintf(f1,"%s %s %s %d %s\n",c1.identifiant,c1.type,c1.marque,c1.reference,c1.etat);
}
else 
{
fprintf(f1,"%s %s %s %d %s\n",c.identifiant,c.type,c.marque,c.reference,c.etat);
}
}

fclose(f);
fclose(f1);
remove("capteur.txt");
rename("tamp.txt","capteur.txt");
}


//////////////////////////////////////////////////
int supprimer (char identifiant[])
{
FILE *f, *f1;
capteur c1;
int trouve = 0;

f=fopen("capteur.txt","r");
f1=fopen("tamp.txt","a+");
while (fscanf(f,"%s %s %s %d %s\n",c1.identifiant,c1.type,c1.marque,&c1.reference,c1.etat)!=EOF)
{
	if ((strcmp(identifiant,c1.identifiant)!=0))
	{
	fprintf(f1,"%s %s %s %d %s\n",c1.identifiant,c1.type,c1.marque,c1.reference,c1.etat);
	}
	else trouve=1;
}
fclose(f);
fclose(f1);

remove("capteur.txt");
rename("tamp.txt","capteur.txt");
return trouve;
}
/*
int alarment(float min1, float max1){
FILE *f;
int n=0;
int id,jour,mois,annee;
float temp;

f=fopen("temperature.txt","a+");
while (fscanf(f,"%d %d %d %d %f\n",&id,&jour,&mois,&annee,&temp)!=EOF)
{
	if (temp<min1 || temp>max1)
	{
	n++;
	}
	
}
fclose(f);

return n;
}
*/
int alarment(float min1,float max1,float min2 ,float max2){
FILE *f;
int n=0;
int id,jour,mois,annee;
float temp;

f=fopen("temperature.txt","a+");
while (fscanf(f,"%d %d %d %d %f",&id,&jour,&mois,&annee,&temp)!=EOF)
{
	if ((temp>min1 && temp<max1) || (temp>min2 && temp<max2))
	{
	n++;
	}
	
}
fclose(f);

return n;
}

int temper(float min1,float max1,float min2 ,float max2){
FILE *f,*f1;
int n=0;
int id,jour,mois,annee;
float temp;
int id1;
int T[10];
for (id=1;id<=9;id++){T[id]=0;}
remove("rature.txt");
f1=fopen("rature.txt","a+");
f=fopen("temperature.txt","a+");
if (f!=NULL){
 
while (fscanf(f,"%d %d %d %d %f \n",&id1,&jour,&mois,&annee,&temp)!=EOF) 
 {for (id=1;id<=9;id++){
	if ((id1==id) && ((temp>min1 && temp<max1) || (temp>min2 && temp<max2))){T[id]++;}
	}
	}
}
for (id=1;id<=9;id++){
	fprintf(f1,"%d %d \n",id,T[id]);
	}
fclose(f);
fclose(f1);
return 1;

}
/*
int temper(float min1,float max1){
FILE *f,*f1;
int n=0;
int id,jour,mois,annee;
float temp;
int id1;
int T[10];
for (id=1;id<=9;id++){T[id]=0;}
remove("rature.txt");
f1=fopen("rature.txt","a+");
f=fopen("temperature.txt","a+");
if (f!=NULL){
 
while (fscanf(f,"%d %d %d %d %f\n",&id1,&jour,&mois,&annee,&temp)!=EOF) 
 {for (id=1;id<=9;id++){
	if ((id1==id) && (temp<min1 || temp>max1)){T[id]++;}
	}
	}
}
for (id=1;id<=9;id++){
	fprintf(f1,"%d %d \n",id,T[id]);
	}
fclose(f);
fclose(f1);
return 1;

}
*/


