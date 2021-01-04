#include <string.h>
#include "client.h"
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>



///////////////////////////////////////////////////////////
int ajout_client(Client c){
FILE *f;
Client c2;

f=fopen("client.txt","a+");
if (f!=NULL){
 
while (fscanf(f,"%s %s %s %s %s %s %d %d %d %s\n",
	c2.Id,
	c2.Nom,
	c2.Prenom,  
	c2.sexe,
	c2.Adresse,
	c2.Mail,
	&c2.ddn.Jour,
	&c2.ddn.Mois,
	&c2.ddn.Annee,
	c2.sat)!=EOF) 
 {
if (strcmp (c2.Id,c.Id)==0)
	{ fclose(f); 
	return 0; }
   }

fprintf(f,"%s %s %s %s %s %s %d %d %d %s\n",
	c.Id,
	c.Nom,
	c.Prenom,  
	c.sexe,
	c.Adresse,
	c.Mail,
	 c.ddn.Jour,
	 c.ddn.Mois,
	 c.ddn.Annee,
	c.sat);
fclose(f);
}

return 1;}

int Modifier_client(Client c){
FILE *f,*f1;
Client c2;
int r=0;

f=fopen("client.txt","a+");
f1=fopen("temp.txt","a+");
if (f!=NULL){
 
while (fscanf(f,"%s %s %s %s %s %s %d %d %d %s \n",
	c2.Id,
	c2.Nom,
	c2.Prenom,  
	c2.sexe,
	c2.Adresse,
	c2.Mail,
	&c2.ddn.Jour,
	&c2.ddn.Mois,
	&c2.ddn.Annee,
	c2.sat)!=EOF) 
 {
if (strcmp (c2.Id,c.Id)==0)
	{ fprintf(f1,"%s %s %s %s %s %s %d %d %d %s\n",
	c.Id,
	c.Nom,
	c.Prenom,  
	c.sexe,
	c.Adresse,
	c.Mail,
	 c.ddn.Jour,
	 c.ddn.Mois,
	 c.ddn.Annee,
	c.sat);
	r=1;
	}
else {fprintf(f1,"%s %s %s %s %s %s %d %d %d %s\n",
	c2.Id,
	c2.Nom,
	c2.Prenom,  
	c2.sexe,
	c2.Adresse,
	c2.Mail,
	 c2.ddn.Jour,
	 c2.ddn.Mois,
	 c2.ddn.Annee,
	c2.sat);}
   }

fclose(f);
fclose(f1);
remove("client.txt");
rename("temp.txt","client.txt");
}

return r;
}

int supprimer_client (char Id[]){
FILE *f,*f1;
Client c2;
int r=0;

f=fopen("client.txt","a+");
f1=fopen("temp.txt","a+");
if (f!=NULL){
 
while (fscanf(f,"%s %s %s %s %s %s %d %d %d %s \n",
	c2.Id,
	c2.Nom,
	c2.Prenom,  
	c2.sexe,
	c2.Adresse,
	c2.Mail,
	&c2.ddn.Jour,
	&c2.ddn.Mois,
	&c2.ddn.Annee,
	c2.sat)!=EOF) 
 {
if (strcmp (c2.Id ,Id)==0)
	{ 
	r=1;
	}
else {fprintf(f1,"%s %s %s %s %s %s %d %d %d %s\n",
	c2.Id,
	c2.Nom,
	c2.Prenom,  
	c2.sexe,
	c2.Adresse,
	c2.Mail,
	 c2.ddn.Jour,
	 c2.ddn.Mois,
	 c2.ddn.Annee,
	c2.sat);}
   }

fclose(f);
fclose(f1);
remove("client.txt");
rename("temp.txt","client.txt");
return r;
}
}


void absen(int mois,int annee){
FILE *f,*f1;
int i,i1,i2,i3,i4;
int id;
int T[10];
for (id=1;id<=9;id++){T[id]=0;}
remove("abs.txt");
f1=fopen("abs.txt","a+");
f=fopen("absenteisme.txt","a+");
if (f!=NULL){
 
while (fscanf(f,"%d %d %d %d %d \n",&i,&i1,&i2,&i3,&i4)!=EOF) 
 {for (id=1;id<=9;id++){
	if ((i==id) && (i2==mois) && (i3==annee) && (i4==0)){T[id]++;}
	}
	}
}
for (id=1;id<=9;id++){
	fprintf(f1,"%d %d \n",id,T[id]);
	}
fclose(f);
fclose(f1);
}

int add_abs(int id, int jour, int mois, int annee ,int abs){
int i,i1,i2,i3,i4;
FILE *f;
f=fopen("absenteisme.txt","a+");
int r=0;
if (f!=NULL){
 
while (fscanf(f,"%d %d %d %d %d \n",&i,&i1,&i2,&i3,&i4)!=EOF) 
	{
	if ((i==id) && (i1==jour) && (i2==mois) && (i3==annee) && (i4==abs)){
	r=1;}
	}
}
if (r==0){fprintf(f,"%d %d %d %d %d \n",id,jour,mois,annee,abs );}
fclose(f);
return r;
}

float taux(int mois,int annee){
FILE *f,*f1,*f2;
int i,i1,i2,i3,i4;
float taux;
char ch1[30];
char ch2[30];
char ch3[30];
char ch4[30];
char ch5[30];
char ch6[30];
char ch7[30];
char ch8[30];
char ch9[30];
char ch10[30];
int n=0;
int nb=0;
remove("taux.txt");
f2=fopen("ouvrier.txt","a+");
f1=fopen("taux.txt","a+");
f=fopen("absenteisme.txt","a+");
if (f!=NULL){
 
while (fscanf(f,"%d %d %d %d %d\n",&i,&i1,&i2,&i3,&i4)!=EOF) 
 {
	if ((i2==mois) && (i3==annee) && (i4==0)){n++;}
	}
	
}
if (f2!=NULL){
 
while (fscanf(f2,"%s %s %s %s %s %s %s %s %s %s  \n",ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10)!=EOF) 
 {
nb++;	
}
}
g_print("nb=%d\n",nb);
if (nb!=0){
taux=(n*100)/(nb*30);
fprintf(f1,"%f",taux);
}
fclose(f);
fclose(f1);
return taux;
}









  




   














