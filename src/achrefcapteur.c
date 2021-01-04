#include "achrefcapteur.h"
#include <gtk/gtk.h>
#include "capteur.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int existeMarque(char marque[200][30], int n, char marq[]){
for (int i=0;i<n;i++)
{
if (strcmp(marque[i],marq)==0)
	return 1;
}

return 0;
}
void remplirmarque(char marque[200][30], int *n,char nomFichierCapteur[]){

(*n)=0;
capteur c1;
FILE *f;
f=fopen(nomFichierCapteur,"r");
if(f!=NULL){
while(fscanf(f,"%s %s %s %d %s\n" , c1.identifiant,c1.type,c1.marque,&c1.reference,c1.etat)!=EOF)
{
int valeur=existeMarque(marque,*n,c1.marque);
if(valeur==0)
	{ strcpy(marque[*n],c1.marque);
	(*n)++;}

}
fclose(f);
}
}
int existeCapteur(char IDcapteur[200][30], int m, char ID[] ){
for (int i=0;i<m;i++)
{if (strcmp(IDcapteur[i],ID)==0)
	return 1;}

return 0;

}



void remplirid (char IDcapteur[200][30], int *m,char marque[200][30], int n, int tab[], int *o, char temperaturefichier[],char nomFichierCapteur[], float min, float max)
{
*m=0;
*o=n;
capteur c1;
FILE *f,*f1;
char ID[20];
int jour;
int mois;
int annee;
float val;
for (int i=0;i<n;i++)
{tab[i]=0;}

f=fopen(temperaturefichier,"r");
if(f!=NULL){
while(fscanf(f,"%s %d %d %d %f\n",
ID,
&jour,
&mois,
&annee,
&val)!=EOF)
{

if (val<min || val >max)
{ 
int exist= existeCapteur(IDcapteur,*m,ID);
if (exist == 0)
{g_print("%s\n",ID); 
strcpy(IDcapteur[*m],ID);
(*m)++;
f1=fopen(nomFichierCapteur,"r");
if (f1!=NULL)
{ while (fscanf(f1,"%s %s %s %d %s\n",c1.identifiant,c1.type,c1.marque,&c1.reference,c1.etat)!=EOF)
{
 if (strcmp(ID,c1.identifiant)==0)
	{  for (int i=0;i<n;i++)
			{if (strcmp(c1.marque,marque[i])==0)
				tab[i]++;
			}
	}
}

fclose(f1);
}


}

}


}
fclose(f);
}

}
int max (int tab[], int o){
int index=0;
 for (int i=1;i<o;i++)
	{ if (tab[index]<tab[i])
		index=i;
	}
//g_print("tab[index]=%d\n",tab[index]);
return index;
}
void marqueCapDeffecteueux(char nomFichierValeurs[], char nomFichierCapteur[] ,char *marq, float min ,float mx)
{
char marque[200][30];
char IDcapteur[200][30];
int n,m,o;
n= 0;
int tab[100];


remplirmarque(marque,&n,nomFichierCapteur);

remplirid (IDcapteur,&m,marque, n,tab,&o, nomFichierValeurs,nomFichierCapteur,min, mx);

int index=max (tab,o);

for (int i=0;i<n;i++)
g_print("%s ", marque[i]);
g_print("\n");
for (int i=0;i<o;i++)
g_print("%d\t", tab[i]);
g_print("\n");

strcpy(marq,marque[index]);
}

/*
int existe(char marque[30][],int *n,char nomMarque[])
{
int i;
for(i=0;i<n;i++)
{
if (strcmp(marque[i],nomMarque)==0)
{
return 1;

}

}
return 0;
}
void ajoutMarque(char nomFichierCapteur[],char marque[30][],int *n)
{
*n=0;
capteur c;
FILE *f;
f=fopen(nomFichierCapteur,"r");
if(f!=NULL){
while(fscanf(f,"%s %s %s %d\n",
c.identifant,
c.type,
c.marque,
c.referance)!=EOF)
{
int valeur=existe(marque,n,c.marque);
if(valeur==0)
{
strcpy(marque[*n],c.marque);
(*n)++;
}

}
fclose(f);
}



int existeCapteur(char cap[200][],int *m,char ID,int *index)
{
int i;

for(i=0;i<m;i++)
{
if (strcmp(cap[i],ID)==0)
{
*index=i;
return 1;

}

}
return 0;
}

void remplirID(char cap[200][],int T[],int *m,char temperature[],float min ,float max)
{
FILE *f;
char ID[20];
int jour;
int mois;
int annee;
float val;
int index;
*m=0;

f=fopen(temperature,"r");
if(f!=NULL){
while(fscanf(f,"%s %d %d %d %f\n",
ID,
jour,
mois,
annee,
val)!=EOF)
{
if(val<min || val>max)
{
int res=existeCapteur(cap,m,ID,&index);
if(res==0)
{
strcpy(cap[*m],ID);

T[*m]=1;
(*m)++;



}
else 
	T[index]++;

}
}
void maxT(int T[],int *m,char cap[200][],char capteur[])
{
int index=0;
for(i=0;i<*m;i++)
{
if(T[index]<T[i])
{
index=i;
strcpy(capteur,cap[i]);
}
}

}
void marqueCapDeffecteueux(char nomFichierValeurs[], char nomFichierCapteur[] ,char *marque, float min ,float max)
{
char cap[200][];
char capteur[50];
int T[200];
int m=0;

remplirID(cap,T,&m,nomFichierValeurs, min ,max);
maxT(T,&m,cap,capteur);
FILE *f;
f=fopen(nomFichierCapteur,"r");
if(f!=NULL){
while(fscanf(f,"%s %s %s %d\n",
c.identifant,
c.type,
c.marque,
c.referance)!=EOF)
{
if(strcmp(c.identifant,capteur)
{
strcpy(marque,c.marque);
}
}
fclose(f);

}

}
*/


