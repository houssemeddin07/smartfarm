#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "capteur.h"
#include "zverif.h"
#include <gtk/gtk.h>


int verifier (char identifian[], capteur * c)
{

capteur c1;
int r=0;
FILE* f=NULL;
f=fopen("capteur.txt","r");
while (fscanf(f,"%s %s %s %d %s\n",
c1.identifiant,
c1.type,
c1.marque,
&c1.reference,
c1.etat)!=EOF)
{	
	if(strcmp(c1.identifiant,identifian)==0)
	{r=1;
	*c=c1;}
}
fclose(f);
return r;
}
