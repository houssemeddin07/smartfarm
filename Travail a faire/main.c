#include <stdio.h>
#include "animaux.h"
#include <string.h>
#include <stdlib.h>
int main (){
char nom_fichier[20]="animaux.txt";
char Identifiant[20];
animal m,*m1,*m2;
int V=0,M=0,C=0;
int modifresult;
strcpy(m.Identifiant,"3faaaaa");
strcpy(m.sexe,"male");
strcpy(m.type,"chevre");
m.D.jour=30;
m.D.mois=1;
m.D.annee=2005;

m2= malloc (sizeof (animal));

// AJOUT ANIMAL
int result=ajout_animal(m,nom_fichier);
if (result==1)
	printf ("ajout terminee avec success\n");
else if (result==0)
	printf ("erreur de donnees (Date incorrecte)\n");
else
	printf ("Identifiant existe deja\n");


// RECHERCHE ANIMAL
printf ("donner l\'identifiant de l\'animal que vous voulez Afficher:");
scanf ("%s",Identifiant);
m1=recherche_animal(Identifiant,nom_fichier);
if (m1!=NULL)
{ printf ("Identifiant:%s\nsexe:%s\ntype:%s\nDate de naissance:%d/%d/%d\n",m1->Identifiant,
m1->sexe,
m1->type,
m1->D.jour,
m1->D.mois,
m1->D.annee);
 }
else printf ("animal introuvable\n");


// SAISIE DE NOUVELLE DONNEES POUR LA MODIFICATION

printf ("donner l\'identifiant de l\'animal que vous voulez Modifier:");
scanf ("%s",Identifiant);
strcpy(m2->Identifiant,Identifiant);
printf ("donner le nouveau sexe de l\'animal: <male/femele>:");
scanf("%s",m2->sexe);
printf ("donner le type de l\'animal: <chevre/mouton/vache>:");
scanf("%s",m2->type);
do{
printf ("donner le jour de naissance de l\'animal:");
scanf("%d",&m2->D.jour);
printf ("donner le mois de naissance de l\'animal:");
scanf("%d",&m2->D.mois);
printf ("donner l\'annee de naissance de l\'animal:");
scanf("%d",&m2->D.annee);
if (date_valide(m2->D)==0)
	printf ("Date invalide\n");
}
while (date_valide(m2->D)==0);

// MODIFIER ANIMAL
 modifresult=modifier_animal(m2,nom_fichier);
if (modifresult==1)
	printf ("modification terminee avec success\n");
else if (modifresult==0)
	printf ("Identifiant introuvable\n");
else 
	printf ("echec modification\n");



// SUPPRIMER ANIMAL
printf ("donner l\'identifiant de l\'animal a supprimer:");
scanf ("%s",Identifiant);
int supprimresult=supprimer_animal(Identifiant,nom_fichier);
if (supprimresult==1)
	printf ("suppression terminee avec success\n");
else if (supprimresult==0)
	printf ("Identifiant introuvable\n");
else 
	printf ("echec suppression\n");


// AFFICHAGE ANIMAUX
printf ("Affichage des animaux:\n");
affichage_animaux(nom_fichier);


// AFFICHAGE DE NOMBRE DE TROUPEAUX
printf ("Nombre de troupeaux:\n");
afficher_nombre_de_troupeaux(&V,&M,&C,nom_fichier);
printf("Vaches:%d|Moutons:%d|Chevres:%d\n",V,M,C);
return 0;
}
