#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"
#include "verif.h"



int verif (char identifian[],Client *c)
{

Client c2;
int r=0;
FILE* f=NULL;
f=fopen("client.txt","r");
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
	if(strcmp(c2.Id,identifian)==0)
	{r=1;
	*c=c2;	}
}
fclose(f);
return r;
}
