#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "animaux.h"
#include "equipement.h"
#include "plante.h"

// ons
#include "client.h"
#include "verif.h"
#include "treeveiw.h"
// tasnim
#include "func.h"
#include "treeview.h"
//zayneb
#include "ztreeview.h"
#include "capteur.h"
#include "zverif.h"
// achref
#include "achrefcapteur.h"



char nom_fichier[100]="animaux.txt";
char nom_fich[100]="utilisateurs.txt";
char login_fichier[100]="login.txt";
char nom_fichier_equipement[20]="equipement.txt";
char nom_fichier_plante[50]="plante.txt";
char nom_fichier_client[50]="client.txt";
void
on_HLbuttonConfirmer_clicked           (GtkWidget       *Window,  				gpointer         user_data)
{ 

char username[20];
char password[20];
int role;
GtkWidget* utilis;
GtkWidget* motdepasse;
GtkWidget* resultat;
GtkWidget* checkbox;
GtkWidget* Statistiques;
  GtkWidget *window1;
  GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;


// Nom ENTRY TEXT
utilis = lookup_widget(Window, "HLentryNomUtilisateur");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(utilis)));
// mot de passe ENTRY TEXT
motdepasse = lookup_widget(Window, "HLentryPassword");
strcpy(password,gtk_entry_get_text(GTK_ENTRY(motdepasse)));

// LABEL RESULTAT
 resultat=lookup_widget(Window, "HLresultatLogin");

 //CHECKBOXES INITIALISATIONS
   checkbox=lookup_widget(Window,"HLcheckbuttonSauvegarderInfo");

if (strcmp(username,"")==0 || strcmp(password,"")==0)
gtk_label_set_text(GTK_LABEL(resultat),"Erreur: champs vides!");
else
{ 
int result=chercher_utilisateur(username,password,nom_fich,&role);

 if (result==-1)
{gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Nom d\'utilisateur/ mot de passe incorrecte(s)");
}
else {

// TO CHECK THE CHECKBOX STATE TO WHETHER WE HAVE TO SAVE LOGIN AND PASSWORD
	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(checkbox)))
			{  ajoutloginandpassword(username,password,login_fichier);}
else {remove(login_fichier);}
 

  window1 = create_menu_proprietaire();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  if (role==0)
  {Statistiques=lookup_widget(window1, "HLbuttonStatistiques");
   gtk_widget_destroy(GTK_WIDGET(Statistiques));
   }
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
	}


}	



}


void
on_HLbuttonCreerUnCompte_clicked       (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
  GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_creer_un_compte();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));


}


void
on_HLbuttonRetourCreeCompte_clicked    (GtkWidget       *Window,
                                        gpointer         user_data)
{

GtkWidget *UN;
GtkWidget *MP;
GtkWidget *checkbox;
char nomutilisateur[50]="";
char motdepasse[50]="";
GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_Lobby();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));

readData (nomutilisateur,motdepasse,login_fichier );
if (strcmp(nomutilisateur,"")!=0 && strcmp(motdepasse,"")!=0)
{
// Nom ENTRY TEXT
UN = lookup_widget(window1, "HLentryNomUtilisateur");
gtk_entry_set_text(GTK_ENTRY(UN),nomutilisateur);
// mot de passe ENTRY TEXT
MP = lookup_widget(window1, "HLentryPassword");
gtk_entry_set_text(GTK_ENTRY(MP),motdepasse);

//CHECKBOXES INITIALISATIONS
   checkbox=lookup_widget(window1,"HLcheckbuttonSauvegarderInfo");
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(checkbox),TRUE);

}
}


void
on_HLbuttonAnnulerCreerCompte_clicked  (GtkWidget       *Window,
                                        gpointer         user_data)
{

GtkWidget *UN;
GtkWidget *MP;
GtkWidget *checkbox;
char nomutilisateur[50]="";
char motdepasse[50]="";
GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_Lobby();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));


readData (nomutilisateur,motdepasse,login_fichier );
if (strcmp(nomutilisateur,"")!=0 && strcmp(motdepasse,"")!=0)
{
// Nom ENTRY TEXT
UN = lookup_widget(window1, "HLentryNomUtilisateur");
gtk_entry_set_text(GTK_ENTRY(UN),nomutilisateur);
// mot de passe ENTRY TEXT
MP = lookup_widget(window1, "HLentryPassword");
gtk_entry_set_text(GTK_ENTRY(MP),motdepasse);

//CHECKBOXES INITIALISATIONS
   checkbox=lookup_widget(window1,"HLcheckbuttonSauvegarderInfo");
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(checkbox),TRUE);

}
}


void
on_HLbuttonDeconnecter_clicked         (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *UN;
GtkWidget *MP;
GtkWidget *checkbox;
char nomutilisateur[50]="";
char motdepasse[50]="";
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_Lobby();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));



readData (nomutilisateur,motdepasse,login_fichier );
if (strcmp(nomutilisateur,"")!=0 && strcmp(motdepasse,"")!=0)
{
// Nom ENTRY TEXT
UN = lookup_widget(window1, "HLentryNomUtilisateur");
gtk_entry_set_text(GTK_ENTRY(UN),nomutilisateur);
// mot de passe ENTRY TEXT
MP = lookup_widget(window1, "HLentryPassword");
gtk_entry_set_text(GTK_ENTRY(MP),motdepasse);

//CHECKBOXES INITIALISATIONS
   checkbox=lookup_widget(window1,"HLcheckbuttonSauvegarderInfo");
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(checkbox),TRUE);

}

}


void
on_HLbuttonGT_clicked                  (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_troupeau();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));


}


void
on_HLbuttonRetourduMenuTroupeau_clicked
                                        (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_proprietaire();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}





void
on_HLbuttonRetourTroupeauMenu_clicked  (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_troupeau();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}


void
on_HLbuttonAnnulerAjout_clicked        (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_troupeau();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}


void
on_HLbuttonAfficherTr_clicked          (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *window1;
GtkWidget *VacheCheckBox;
GtkWidget *ChevreCheckBox;
GtkWidget *MoutonCheckBox;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_affichage_troupeaux();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
  //TREEVIEW INITIALISATION
  treeview1=lookup_widget(window1,"HLtreeviewAffichage");
  //CHECKBOXES INITIALISATIONS
   VacheCheckBox=lookup_widget(window1,"HLcheckbuttonVaches");
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(VacheCheckBox),TRUE);

   MoutonCheckBox=lookup_widget(window1,"HLcheckbuttonMoutons");
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(MoutonCheckBox),TRUE);

   ChevreCheckBox=lookup_widget(window1,"HLcheckbuttonChevres");
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(ChevreCheckBox),TRUE);
  afficher_animaux(treeview1,VacheCheckBox,ChevreCheckBox,MoutonCheckBox);
  
}

void
on_HLbuttonTARetour_clicked            (GtkWidget       *Window,
                                        gpointer         user_data)
{
  GtkWidget *window1;
  GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_troupeau();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}


void
on_HLbuttonAjouterAn_clicked           (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
  GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_ajouter_animal();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}


void
on_HLbuttonModifierAn_clicked          (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
  GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_modifier_animal();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));

}


void
on_HLbuttonAnnulerModif_clicked        (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
  GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_troupeau();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}


void
on_HLbuttonRetourDuModif_clicked       (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
  GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_troupeau();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}


void
on_HLbuttonSupprimerAn_clicked         (GtkWidget       *Window,
                                        gpointer         user_data)
{ GtkWidget *window1;
  GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_supprimer_animal();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));

}


void
on_HLbuttonAnnulerSupprim_clicked      (GtkWidget       *Window,
                                        gpointer         user_data)
{GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_troupeau();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}


void
on_HLbuttonRetourduSupprim_clicked     (GtkWidget       *Window,
                                        gpointer         user_data)
{GtkWidget *window1;
  GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_troupeau();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));

}





void
on_HLbuttonStatistiques_clicked        (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_statistiques();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}


void
on_HLbuttonRetourdeStatistique_clicked (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_menu_proprietaire();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}


void
on_HLbuttonLNDTDCG__clicked            (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *vaches;
GtkWidget *moutons;
GtkWidget *chevres;
int v=0,c=0,m=0;
char sm[10];
char sv[10];
char sc[10];

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_nombre_de_troupeaux();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));

// LABEL NVache
 vaches=lookup_widget(window1, "HLlabelNDV");
// LABEL NVache
 moutons=lookup_widget(window1, "HLlabelNDM");
// LABEL NVache
 chevres=lookup_widget(window1, "HLlabelNDC");

 afficher_nombre_de_troupeaux(&v, &m, &c, nom_fichier);

sprintf(sv,"%d",v);
sprintf(sm,"%d",m);
sprintf(sc,"%d",c);

gtk_label_set_text(GTK_LABEL(vaches),sv);
gtk_label_set_text(GTK_LABEL(moutons),sm);
gtk_label_set_text(GTK_LABEL(chevres),sc);
}


void
on_HLbuttonRDNDT_clicked               (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *window1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
  window1 = create_statistiques();
  gtk_widget_modify_bg(GTK_WIDGET(window1),GTK_STATE_NORMAL,&color);
  gtk_widget_show (window1);
  gtk_widget_destroy(GTK_WIDGET(Window));
}





void
on_HLbuttonAjout_clicked               (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget* Male;
GtkWidget* femelle;
GtkWidget* output;
GtkWidget* jour;
GtkWidget* mois;
GtkWidget* annee;
GtkWidget* ComboBox;
GtkWidget* Identifiant;
GtkWidget* resultat;
char type[10];
char Identif[50];
char Sexe[10];
animal m;


// IDENTIFIANT ENTRY TEXT
Identifiant = lookup_widget(Window, "HLentryIdentifiantAjout");
strcpy(m.Identifiant,gtk_entry_get_text(GTK_ENTRY(Identifiant)));
g_print("Identifiant est %s\n",m.Identifiant);



//RADIO BUTTONS
Male = lookup_widget(Window, "HLradiobuttonMaleAjout");
femelle = lookup_widget(Window, "HLradiobuttonFemelleAjout");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(femelle)))
{ 
 strcpy(m.sexe,"femelle");
g_print("sexe=%s\n",Sexe);
}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Male)))
{
 strcpy(m.sexe,"male");
 g_print("sexe=%s\n",Sexe);
}


// Spinbuttons
jour= lookup_widget(Window, "HLspinbuttonjourAjout");
mois= lookup_widget(Window, "HLspinbuttonmoisAjout");
annee= lookup_widget(Window,"HLspinbuttonanneeAjout");
 m.D.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
 m.D.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
 m.D.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
g_print("j=%d,m=%d,a=%d\n",m.D.jour,m.D.mois,m.D.annee);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),10);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),10);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),2010);

// LABEL RESULTAT
 resultat=lookup_widget(Window, "HLlabelResultatAjout");


// combobox
ComboBox= lookup_widget(Window,"HLcombobox1");
// CONTROLE DE SAISIE SI COMBO BOX N'EST PAS SELECTIONNE

 if ((strcmp(m.Identifiant,"")==0) || gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboBox))==NULL) {
gtk_label_set_text(GTK_LABEL(resultat),"Erreur:Champs vides!");
}

else{
strcpy(m.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboBox)));
g_print("type = %s\n",m.type);


// FONCTION AJOUT DE ANIMAUX.C
int result=ajout_animal (m ,nom_fichier);
if (result==1)
	gtk_label_set_text(GTK_LABEL(resultat),"Ajout termine avec succes!");
else 
	gtk_label_set_text(GTK_LABEL(resultat),"Identifiant existe deja!");
}


////////////////////////////////////////////////////////////////////
// POUR LA MODIFICATION

//gtk_combo_box_set_active(GTK_COMBO_BOX(ComboBox),2);

/*

if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(femelle)))
{ 
 g_print("femelle\n");
 gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(Male),TRUE);

}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Male)))
{
 g_print(" Male\n");
 gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(femelle),TRUE);

}
*/
/////////////////////////////////////////////////////////////////////

}


void
on_HLtreeviewAffichage_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_HLcheckbuttonVaches_toggled         (GtkWidget *togglebutton,
                                        gpointer         user_data)
{

GtkWidget *treeview1;

GtkWidget *VacheCheckBox;
GtkWidget *ChevreCheckBox;
GtkWidget *MoutonCheckBox;

  treeview1=lookup_widget(togglebutton,"HLtreeviewAffichage");

   VacheCheckBox=lookup_widget(togglebutton,"HLcheckbuttonVaches");
   MoutonCheckBox=lookup_widget(togglebutton,"HLcheckbuttonMoutons");
   ChevreCheckBox=lookup_widget(togglebutton,"HLcheckbuttonChevres");
  // REAFFICHER LA LISTE 
  afficher_animaux(treeview1,VacheCheckBox,ChevreCheckBox,MoutonCheckBox);
  
}


void
on_HLcheckbuttonChevres_toggled        (GtkWidget *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *treeview1;

GtkWidget *VacheCheckBox;
GtkWidget *ChevreCheckBox;
GtkWidget *MoutonCheckBox;

  treeview1=lookup_widget(togglebutton,"HLtreeviewAffichage");

   VacheCheckBox=lookup_widget(togglebutton,"HLcheckbuttonVaches");
   MoutonCheckBox=lookup_widget(togglebutton,"HLcheckbuttonMoutons");
   ChevreCheckBox=lookup_widget(togglebutton,"HLcheckbuttonChevres");
  // REAFFICHER LA LISTE 
  afficher_animaux(treeview1,VacheCheckBox,ChevreCheckBox,MoutonCheckBox);
  
}


void
on_HLcheckbuttonMoutons_toggled        (GtkWidget *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *treeview1;

GtkWidget *VacheCheckBox;
GtkWidget *ChevreCheckBox;
GtkWidget *MoutonCheckBox;

  treeview1=lookup_widget(togglebutton,"HLtreeviewAffichage");

   VacheCheckBox=lookup_widget(togglebutton,"HLcheckbuttonVaches");
   MoutonCheckBox=lookup_widget(togglebutton,"HLcheckbuttonMoutons");
   ChevreCheckBox=lookup_widget(togglebutton,"HLcheckbuttonChevres");
  // REAFFICHER LA LISTE 
  afficher_animaux(treeview1,VacheCheckBox,ChevreCheckBox,MoutonCheckBox);
  
}


void
on_HLChercher_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget* Male;
GtkWidget* femelle;
GtkWidget* jour;
GtkWidget* mois;
GtkWidget* annee;
GtkWidget* ComboBox;
GtkWidget* Identifiant;
GtkWidget* resultat;
char type[10];
char Identif[50];
char Sexe[10];
animal *m;


// IDENTIFIANT ENTRY TEXT
Identifiant = lookup_widget(button, "HLentryIdentifiantModif");
strcpy(Identif,gtk_entry_get_text(GTK_ENTRY(Identifiant)));

m=recherche_animal(Identif,nom_fichier);

// LABEL RESULTAT
 resultat=lookup_widget(button, "HLlabelResultatModif");
if (m==NULL)
gtk_label_set_text(GTK_LABEL(resultat),"Animal introuvable!");

else {

//RADIO BUTTONS
Male = lookup_widget(button, "HLradiobuttonMaleModif");
femelle = lookup_widget(button, "HLradiobuttonFemelleModif");
if (strcmp(m->sexe,"male")==0)
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(Male),TRUE);
else
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(femelle),TRUE);


// combobox
ComboBox= lookup_widget(button,"HLmodifComboBox");

if (strcmp(m->type,"chevre")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(ComboBox),2);
else if (strcmp(m->type,"mouton")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(ComboBox),1);
else if (strcmp(m->type,"vache")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(ComboBox),0);



// Spinbuttons
jour= lookup_widget(button, "HLspinbuttonjourModif");
mois= lookup_widget(button, "HLspinbuttonmoisModif");
annee= lookup_widget(button,"HLspinbuttonanneeModif");

gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),m->D.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),m->D.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),m->D.annee);


}

}


void
on_HLbuttonModif_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{


GtkWidget* Male;
GtkWidget* femelle;
GtkWidget* jour;
GtkWidget* mois;
GtkWidget* annee;
GtkWidget* ComboBox;
GtkWidget* Identifiant;
GtkWidget* resultat;
char type[10];
char Identif[50];
char Sexe[10];
animal *m;

m=malloc(sizeof (animal));

// IDENTIFIANT ENTRY TEXT
Identifiant = lookup_widget(button, "HLentryIdentifiantModif");
strcpy(m->Identifiant,gtk_entry_get_text(GTK_ENTRY(Identifiant)));


// combobox
	ComboBox= lookup_widget(button,"HLmodifComboBox");

//RADIO BUTTONS
Male = lookup_widget(button, "HLradiobuttonMaleModif");
femelle = lookup_widget(button, "HLradiobuttonFemelleModif");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(femelle)))
{ 
 strcpy(m->sexe,"femelle");
}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Male)))
{
 strcpy(m->sexe,"male");
}


// Spinbuttons
jour= lookup_widget(button, "HLspinbuttonjourModif");
mois= lookup_widget(button, "HLspinbuttonmoisModif");
annee= lookup_widget(button,"HLspinbuttonanneeModif");
 m->D.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
 m->D.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
 m->D.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


// LABEL RESULTAT
 resultat=lookup_widget(button, "HLlabelResultatModif");
if (strcmp(m->Identifiant,"")==0 || (strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboBox)),"")==0))
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Champs vides!");
else if (date_valide(m->D)==0)
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Date invalide!");
else
	{
	
	strcpy(m->type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboBox)));

	int res= modifier_animal(m, nom_fichier);
	if (res==-1)
		gtk_label_set_text(GTK_LABEL(resultat),"Erreur: fichier vide!");
	else if (res==0)
		gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Identifiant introuvable!");
	else if (res==1)
		gtk_label_set_text(GTK_LABEL(resultat),"Modification terminee avec success!");	
	}
	


}


void
on_HLbuttonSupprim_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* Identifiant;
GtkWidget* resultat;

char Identif[50];
// IDENTIFIANT ENTRY TEXT
Identifiant = lookup_widget(button, "HLentryIdentifiantSupprim");
strcpy(Identif,gtk_entry_get_text(GTK_ENTRY(Identifiant)));

// LABEL RESULTAT
 resultat=lookup_widget(button, "HLlabelResultatSupprim");

if (strcmp(Identif,"")!=0){

int res=supprimer_animal(Identif, nom_fichier);


if (res==1)
	gtk_label_set_text(GTK_LABEL(resultat),"Suppression terminee avec success!");
else if (res==0)
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Identifiant introuvable!");
else if (res==-1)
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: fichier vide!");
}
else 
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Champ Identifiant vide!");

}


void
on_HLbuttonCreerCompte_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
 utilisateur u;
char RMP[20];
GtkWidget* nom;
GtkWidget* prenom;
GtkWidget* utilis;
GtkWidget* motdepasse;
GtkWidget* remotdepasse;
GtkWidget* Ouvrier;
GtkWidget* Admin;
GtkWidget* resultat;


// Nom ENTRY TEXT
nom = lookup_widget(button, "HLentryCreerCompteNom");
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
// prenom ENTRY TEXT
prenom = lookup_widget(button, "HLentryCreerComptePrenom");
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
// utilisateur ENTRY TEXT
utilis = lookup_widget(button, "HLentryCreerCompteUtilisateur");
strcpy(u.utilisateur,gtk_entry_get_text(GTK_ENTRY(utilis)));
// mot de passe ENTRY TEXT
motdepasse = lookup_widget(button, "HLentryCreeCompteMP");
strcpy(u.motdepasse,gtk_entry_get_text(GTK_ENTRY(motdepasse)));
// retapper mot de passe ENTRY TEXT
remotdepasse = lookup_widget(button, "HLentryCreeCompteRMP");
strcpy(RMP,gtk_entry_get_text(GTK_ENTRY(remotdepasse)));


//RADIO BUTTONS
Ouvrier = lookup_widget(button, "HLradioOuvrier");
Admin = lookup_widget(button, "HLradioAdmin");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Admin)))
{  
   // Admin recoit 1
  u.role=1;
}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Ouvrier)))
{
  // ouvrier recoit 0 
  u.role=0;
}

// LABEL RESULTAT
 resultat=lookup_widget(button, "HLlabelResultatCreerCompte");
  if (strcmp(u.nom,"")==0 ||strcmp(u.prenom,"")==0 ||strcmp(u.utilisateur,"")==0 || strcmp(u.motdepasse,"")==0||
strcmp(RMP,"")==0)
     gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Champs vides!");
else if (strcmp(RMP,u.motdepasse)!=0)
     gtk_label_set_text(GTK_LABEL(resultat),"Erreur: mots de passes differents!");
	else 
	{
	int res=ajouter_utilisateur(u,nom_fich);
	if (res==-1)
		gtk_label_set_text(GTK_LABEL(resultat),"Erreur: nom d\'utilisateur existe deja!");
	else
		gtk_label_set_text(GTK_LABEL(resultat),"Compte cree avec succes!");
}


	

}


void
on_HLcheckbuttonSauvegarderInfo_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
/*
GtkWidget* login;
GtkWidget* password;
char nomutilisateur[50];
char motdepasse[50];

  login=lookup_widget(togglebutton,"HLentryNomUtilisateur");
strcpy(nomutilisateur,gtk_entry_get_text(GTK_ENTRY(login)));

   password=lookup_widget(togglebutton,"HLentryPassword");
strcpy(motdepasse,gtk_entry_get_text(GTK_ENTRY(password)));
*/
}


void
on_ADajouterAjouter_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *referance;
GtkWidget *mar;
GtkWidget *ty;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *resultat;
char ref[15];
char marque[10];
char type[15];
equipement E;

referance= lookup_widget(button,"ADreferanceAjouter");
strcpy(E.ref,gtk_entry_get_text(GTK_ENTRY(referance)));
g_print("referance est %s\n",E.ref);
mar= lookup_widget(button,"ADmarqueAjouter");
strcpy(E.marque,gtk_entry_get_text(GTK_ENTRY(mar)));
g_print("referance est %s\n",E.marque);

ty=lookup_widget(button,"ADtypeAjouter");

resultat=lookup_widget(button,"ADresultatAjout");


if((strcmp(E.ref,"")==0) || (strcmp(E.marque,"")==0)||
strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)),"")==0)
{
gtk_label_set_text(GTK_LABEL(resultat),"champs vides");

}
else{
strcpy(E.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));
g_print("type=%s\n",E.type);

jour= lookup_widget(button,"ADjour");
mois= lookup_widget(button,"ADmois");
annee= lookup_widget(button,"ADannee");
E.D.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
E.D.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
E.D.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
g_print("j=%d,m=%d,a=%d\n",E.D.jour,E.D.mois,E.D.annee);



int result=ajouter_equipement(E, nom_fichier_equipement );
if(result==1)
	gtk_label_set_text(GTK_LABEL(resultat),"ajout termine avec succes!");
else
	gtk_label_set_text(GTK_LABEL(resultat),"identifiant existe deja!");
}

}


void
on_ADannulerAjout_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAnnulerAjouter;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowAnnulerAjouter=create_AD_gestion_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowAnnulerAjouter),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowAnnulerAjouter);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_ADretourajouter_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourAjouter;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowRetourAjouter=create_AD_gestion_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowRetourAjouter),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowRetourAjouter);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ADchercher_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRechercher;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowRechercher=create_AD_modifier_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowRechercher),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowRechercher);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ADretourRechercher_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourRechercher;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowRetourRechercher=create_AD_gestion_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowRetourRechercher),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowRetourRechercher);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_modifier_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *referance;
GtkWidget *mar;
GtkWidget *ty;
GtkWidget *joure;
GtkWidget *moise;
GtkWidget *anneee;
GtkWidget *resultat;
char ref[15];
char marque[10];
char type[15];
equipement *E;

E=malloc(sizeof (equipement));

// IDENTIFIANT ENTRY TEXT
referance= lookup_widget(button,"AD_referanceAmodifier");
strcpy(E->ref,gtk_entry_get_text(GTK_ENTRY(referance)));

mar= lookup_widget(button,"AD_marqueAmodifier");
strcpy(E->marque,gtk_entry_get_text(GTK_ENTRY(mar)));


// combobox

ty=lookup_widget(button,"AD_typeAmodifier");
joure= lookup_widget(button, "AD_jour_modifier");
moise= lookup_widget(button, "AD_mois_modifier");
anneee= lookup_widget(button,"AD_annee_modifier");
 E->D.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(joure));
 E->D.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moise));
 E->D.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneee));

resultat=lookup_widget(button,"AD_ResultatModif");
if((strcmp(E->ref,"")==0) || (strcmp(E->marque,"")==0) || (strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)),"")==0))
{
gtk_label_set_text(GTK_LABEL(resultat),"Erreur: champs vides");

}
else {
strcpy(E->type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));

	int res= modifier_equipement(E, nom_fichier_equipement );
	if (res==-1)
		gtk_label_set_text(GTK_LABEL(resultat),"Erreur: fichier vide!");
	else if (res==0)
		gtk_label_set_text(GTK_LABEL(resultat),"Erreur: refreance introuvable!");
	else if (res==1)
		gtk_label_set_text(GTK_LABEL(resultat),"Modification terminee avec success!");
}

}


void
on_AD_annuler_modifier_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAnnulerModifier;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowAnnulerModifier=create_AD_gestion_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowAnnulerModifier),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowAnnulerModifier);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_retour_supp_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourSupp;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowRetourSupp=create_AD_gestion_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowRetourSupp),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowRetourSupp);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_supprimer_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* referance;
GtkWidget* resultat;

char ref[10];

referance=lookup_widget(button,"AD_ReferanceAsupprimer");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(referance)));
resultat=lookup_widget(button,"AD_ResultatSuppression");

if(strcmp(ref,"")!=0){
int res=supp_equipement(ref, nom_fichier_equipement);
if(res==1)
{
	gtk_label_set_text(GTK_LABEL(resultat),"suppression termine avec succese!");
}
else if(res==0)
{
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur! Reference introvable");
}
else if(res==-1)
{
	gtk_label_set_text(GTK_LABEL(resultat),"fichier vide");
}

}
else 
{
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: champ reference vide!");
} 
}




void
on_AD_retour_afficher_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourAffiche;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowRetourAffiche=create_AD_gestion_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowRetourAffiche),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowRetourAffiche);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_go_to_ajouter_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowGoToajouter;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowGoToajouter=create_AD_ajouter_equipement ();
gtk_widget_modify_bg(GTK_WIDGET(windowGoToajouter),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowGoToajouter);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_go_to_modifier_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowGoTomodifier;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowGoTomodifier=create_AD_modifier_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowGoTomodifier),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowGoTomodifier);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_go_to_supprimer_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowGoTosupprimer;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowGoTosupprimer=create_AD_supprimer_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowGoTosupprimer),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowGoTosupprimer);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_go_to_afficher_enter             (GtkWidget       *button,
                                        gpointer         user_data)
{
/////////////////////////////////////////////////////
GtkWidget *windowGoToafficher;
GtkWidget *mecanique;
GtkWidget *manuelle; 
GtkWidget *treeview1;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
windowGoToafficher=create_AD_afficher_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowGoToafficher),GTK_STATE_NORMAL,&color);

gtk_widget_show(windowGoToafficher);
gtk_widget_destroy(GTK_WIDGET(button));
  //TREEVIEW INITIALISATION
  treeview1=lookup_widget(windowGoToafficher,"AD_treeview1");
 //CHECKBOXES INITIALISATIONS
   mecanique=lookup_widget(windowGoToafficher,"ADAffichemecanique");
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(mecanique),TRUE);

   manuelle=lookup_widget(windowGoToafficher,"ADAffichemanuelle");
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(manuelle),TRUE);
   afficher_equipements(treeview1,mecanique,manuelle);


}


void
on_AD_quiter_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;
GtkWidget *Menuproprietaire;
Menuproprietaire=create_menu_proprietaire();
gtk_widget_modify_bg(GTK_WIDGET(Menuproprietaire),GTK_STATE_NORMAL,&color);
gtk_widget_show(Menuproprietaire);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_retour_modifier_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourModifier;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;


windowRetourModifier=create_AD_gestion_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowRetourModifier),GTK_STATE_NORMAL,&color);

gtk_widget_show(windowRetourModifier);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HLbuttonGEA_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowHLbuttonGEA;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

windowHLbuttonGEA=create_AD_gestion_equipement();
gtk_widget_modify_bg(GTK_WIDGET(windowHLbuttonGEA),GTK_STATE_NORMAL,&color);


gtk_widget_show(windowHLbuttonGEA);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HB_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *Ty;
GtkWidget *Nombre;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *resultat;
char ID[50];
char type[50];
char nombre[10];
plante A;
//zone de texte
id=lookup_widget(button,"HB_idtext_ajout");
strcpy(A.ID,gtk_entry_get_text(GTK_ENTRY(id)));
g_print("id est %s\n",A.ID);

Nombre=lookup_widget(button,"HB_nombre_ajout");
strcpy(A.nombre,gtk_entry_get_text(GTK_ENTRY(Nombre)));
g_print("le Nombre est %s\n",A.nombre);

//spinbuttons
jour=lookup_widget(button,"HB_jour_ajout");
mois=lookup_widget(button,"HB_mois_ajout");
annee=lookup_widget(button,"HB_annee_ajout");
A.D.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
A.D.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
A.D.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
g_print("jour=%d,mois=%d,annee=%d\n",A.D.jour,A.D.mois,A.D.annee);


//label resultat
resultat=lookup_widget(button,"HB_AjoutResultat");
//combobox
Ty=lookup_widget(button,"HB_type_ajout");
//control de saisi de combobox
if((strcmp(A.ID,"")==0)||(strcmp(A.nombre,"")==0)||strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Ty)),"")==0){
gtk_label_set_text(GTK_LABEL(resultat),"Erreur:champs vides!");
}
else{
strcpy(A.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Ty)));
g_print("type=%s\n",A.type);

//fonction ajout plante.c
int res=ajout_plante(A ,nom_fichier_plante);
if(res==1)
	gtk_label_set_text(GTK_LABEL(resultat),"ajout termine avec succes!");
else
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: identifiant existe deja!");

}

}


void
on_HB_annuler_ajout_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_gestion_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HB_retour_ajout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_gestion_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_HB_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *resultat;
char ID[50];
id=lookup_widget(button,"HB_idtext_supp");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));
resultat=lookup_widget(button,"HB_supprim_resultat");
if(strcmp(ID,"")!=0){
int resul=supprimer_plante(ID, nom_fichier_plante);
if(resul==1)
	gtk_label_set_text(GTK_LABEL(resultat),"suppression terminee avec succes!");
else if(resul==0)
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur:identifiant introuvable!");
else if(resul==-1)
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur:fichier vide!");
}
else 
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: champ vide!");

}


void
on_HB_annuler_supp_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_gestion_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HB_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *Ty;
GtkWidget *Nombre;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *resultat;
char ID[50];
char type[50];
char nombre[10];
plante *A;
A=malloc(sizeof (plante));

id=lookup_widget(button,"HB_Identifiant_modif");
strcpy(A->ID,gtk_entry_get_text(GTK_ENTRY(id)));


Nombre=lookup_widget(button,"HB_nombre_modif");
strcpy(A->nombre,gtk_entry_get_text(GTK_ENTRY(Nombre)));

Ty=lookup_widget(button,"HB_type_modif");

jour=lookup_widget(button,"HB_jour_modif");
mois=lookup_widget(button,"HB_mois_modif");
annee=lookup_widget(button,"HB_annee_modif");
A->D.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
A->D.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
A->D.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

resultat=lookup_widget(button,"HB_Modif_resultat");
if((strcmp(A->ID,"")==0)|| strcmp(A->nombre,"")==0|| (strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Ty)),"")==0)){
gtk_label_set_text(GTK_LABEL(resultat),"champs vides");
}
else{
strcpy(A->type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Ty)));
int resul=modifier_plante(A, nom_fichier_plante);
if(resul==-1)
	gtk_label_set_text(GTK_LABEL(resultat),"fichier vide");
else if(resul==0)
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur:identifiant intouvable!");
else if(resul==1)
	gtk_label_set_text(GTK_LABEL(resultat),"modification termine avec succes!");



}

}


void
on_HB_annuler_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_gestion_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HB_retour_modif_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_gestion_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HB_ajout_gestion_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_ajout_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HB_supp_gestion_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_supp_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_HB_modif_gestion_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_modif_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_HB_affiche_gestion_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *treeview1;
GtkWidget *legume;
GtkWidget *fruit;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_affichage();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

/////////////////////////////////////////////////


  //TREEVIEW INITIALISATION
  treeview1=lookup_widget(window,"HB_affichage_plante");
 //CHECKBOXES INITIALISATIONS
   legume=lookup_widget(window,"HB_legumes_checkbox");
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(legume),TRUE);

   fruit=lookup_widget(window,"HB_fruits_checkbox");
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(fruit),TRUE);
   afficher_plantes(treeview1,legume,fruit);


}


void
on_HB_quitter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_menu_proprietaire();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HLbuttonGCL_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_menu_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
 
}


void
on_OA_retour_menu_client_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_menu_proprietaire();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_ajouter_un_client_menu_client_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_ajout_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_anuler_ajout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_menu_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_retour1_ajout_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_menu_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_afficher_un_client_menu_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window;
GtkWidget *treeveiw;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_Afficher_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));


treeveiw=lookup_widget(window,"OA_treeview1_affiche_client");
affiche_listview1(treeveiw);

}


void
on_OA_retour4_Affiche_client_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_menu_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_modifier_client_menu_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_modifier_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_annuler2_modif_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_menu_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_retour2_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_menu_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_suuprimer_client_menu_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_supp_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_OA_annuler3_supp_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_menu_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_Retour3_supp_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_menu_client();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HLbuttonCPV_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_gestion_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_HB_retour_supp_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_gestion_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HB_retour_affichage_plante_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_gestion_plante();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_HLbuttonLALPS_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *resultat;
char result[50];
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_HB_annee_plus_seche();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

int annee =annee_plus_seche("temperature.txt");
sprintf(result,"%d",annee);
resultat=lookup_widget(window,"HB_ALPS_resultat");
	gtk_label_set_text(GTK_LABEL(resultat),result);

}


void
on_HB_retour_annee_plus_seche_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_statistiques();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);


gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ADrechercheModif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *referance;
GtkWidget *marq;
GtkWidget *ty;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *resultat;
char ref[15];
char marque[10];
char type[15];
equipement* E;


// IDENTIFIANT ENTRY TEXT
referance= lookup_widget(button,"AD_referanceAmodifier");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(referance)));

E=rechreche_equipement(ref, nom_fichier_equipement);

resultat=lookup_widget(button,"AD_ResultatModif");
if (E==NULL)
	gtk_label_set_text(GTK_LABEL(resultat),"equipement introuvable");

else {
marq=lookup_widget(button,"AD_marqueAmodifier");
gtk_entry_set_text(GTK_ENTRY(marq),E->marque);

ty= lookup_widget(button,"AD_typeAmodifier");

if (strcmp(E->type,"manuelle")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(ty),0);
else if(strcmp(E->type,"mecanique")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(ty),1);


jour= lookup_widget(button, "AD_jour_modifier");
mois= lookup_widget(button, "AD_mois_modifier");
annee= lookup_widget(button,"AD_annee_modifier");

gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),E->D.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),E->D.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),E->D.annee);
}

}


void
on_ADAffichemanuelle_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

GtkWidget *mecanique;
GtkWidget *manuelle; 
GtkWidget *treeview1;


  //TREEVIEW INITIALISATION
  treeview1=lookup_widget(togglebutton,"AD_treeview1");
 //CHECKBOXES INITIALISATIONS
   mecanique=lookup_widget(togglebutton,"ADAffichemecanique");
   manuelle=lookup_widget(togglebutton,"ADAffichemanuelle");


   afficher_equipements(treeview1,mecanique,manuelle);

}


void
on_ADAffichemecanique_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *mecanique;
GtkWidget *manuelle; 
GtkWidget *treeview1;


  //TREEVIEW INITIALISATION
  treeview1=lookup_widget(togglebutton,"AD_treeview1");
 //CHECKBOXES INITIALISATIONS
   mecanique=lookup_widget(togglebutton,"ADAffichemecanique");
   manuelle=lookup_widget(togglebutton,"ADAffichemanuelle");


   afficher_equipements(treeview1,mecanique,manuelle);
}


void
on_HB_recherche_modif_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *Ty;
GtkWidget *Nombre;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *resultat;
char ID[50];
char type[50];
char nombre[10];
plante *A;

id=lookup_widget(button,"HB_Identifiant_modif");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));

A=recherche_plante(ID, nom_fichier_plante);
resultat=lookup_widget(button,"HB_Modif_resultat");
if (A==NULL)
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: identifiant introuvable!");
else{
gtk_label_set_text(GTK_LABEL(resultat),"");
Ty=lookup_widget(button,"HB_type_modif");
if(strcmp(A->type,"fruit")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(Ty),1);
else if(strcmp(A->type,"legume")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(Ty),0);

Nombre=lookup_widget(button,"HB_nombre_modif");
gtk_entry_set_text(GTK_ENTRY(Nombre),A->nombre);

jour=lookup_widget(button,"HB_jour_modif");
mois=lookup_widget(button,"HB_mois_modif");
annee=lookup_widget(button,"HB_annee_modif");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),A->D.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),A->D.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),A->D.annee);
	
}

}


void
on_HB_legumes_checkbox_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

GtkWidget *fruit;
GtkWidget *legume; 
GtkWidget *treeview1;


  //TREEVIEW INITIALISATION
  treeview1=lookup_widget(togglebutton,"HB_affichage_plante");
 //CHECKBOXES INITIALISATIONS
   legume=lookup_widget(togglebutton,"HB_legumes_checkbox");
   fruit=lookup_widget(togglebutton,"HB_fruits_checkbox");


   afficher_plantes(treeview1,legume,fruit);
}


void
on_HB_fruits_checkbox_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *fruit;
GtkWidget *legume; 
GtkWidget *treeview1;


  //TREEVIEW INITIALISATION
  treeview1=lookup_widget(togglebutton,"HB_affichage_plante");
 //CHECKBOXES INITIALISATIONS
   legume=lookup_widget(togglebutton,"HB_legumes_checkbox");
   fruit=lookup_widget(togglebutton,"HB_fruits_checkbox");


   afficher_plantes(treeview1,legume,fruit);
}


void
on_OA_ajouter1_ajout_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget* identifiant;
GtkWidget* nom;
GtkWidget* prenom;
GtkWidget* Jour;
GtkWidget* Mois;
GtkWidget* Annee;
GtkWidget* Male;
GtkWidget* femelle;
GtkWidget* Add;
GtkWidget* mail;
GtkWidget* resultat;


char Identifiant[30];
char Nom[20];
char Prenom[20];
char sexe [10];
char Adresse[20];
char Mail[20];


Client c;


//IDENTIFIANT ENTRY TEXT
identifiant = lookup_widget(button, "OA_identifiant_ajout");
strcpy(c.Id,gtk_entry_get_text(GTK_ENTRY(identifiant)));

//Nom Entry Text
nom = lookup_widget(button,"OA_nom1_ajout");
strcpy(c.Nom,gtk_entry_get_text(GTK_ENTRY(nom)));

//Prenom Entry Text
prenom = lookup_widget(button,"OA_prenom1_ajout");
strcpy(c.Prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

//Adresse Entry Text
Add = lookup_widget(button,"OA_adresse1_ajout");
strcpy(c.Adresse,gtk_entry_get_text(GTK_ENTRY(Add)));

//Mail Entry Text
mail = lookup_widget(button,"OA_mail1_ajout");
strcpy(c.Mail,gtk_entry_get_text(GTK_ENTRY(mail)));

// RADIO BUTTONS
Male = lookup_widget(button,"OA_male_ajout");
femelle = lookup_widget(button,"OA_femele_ajout");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(femelle)))
{
strcpy(c.sexe,"femelle");
}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Male)))
{
strcpy(c.sexe,"male");
}

//spinbuttons
Jour = lookup_widget(button,"OA_jour_ajout");
Mois = lookup_widget(button,"OA_mois_ajout");
Annee = lookup_widget(button,"OA_annee_ajout");
c.ddn.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.ddn.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.ddn.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));

//LABEL RESULTAT 
resultat=lookup_widget(button,"OA_Ajout_valide");

//FONCTION AJOUT de CLIENT.C
strcpy(c.sat,"dissatisfait");
if (strcmp(c.Id,"")!=0 &&strcmp(c.Nom,"")!=0&&strcmp(c.Prenom,"")!=0&&strcmp(c.Adresse,"")!=0&&strcmp(c.Mail,"")!=0 )
{
int result=ajout_client(c);
if (result==1)
	gtk_label_set_text(GTK_LABEL(resultat),"Ajout terminer avec succes!");
else 
	gtk_label_set_text(GTK_LABEL(resultat),"Identifiant existe deja!");
}
else 
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: champs vides");
}


void
on_OA_modifier2_modif_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget* identifiant;
GtkWidget* nom;
GtkWidget* prenom;
GtkWidget* Jour;
GtkWidget* Mois;
GtkWidget* Annee;
GtkWidget* Male;
GtkWidget* femelle;
GtkWidget* Add;
GtkWidget* mail;
GtkWidget* resultat;
GtkWidget *satis;

char Identifiant[30];
char Nom[20];
char Prenom[20];
char sexe [10];
char Adresse[20];
char Mail[20];
char sati[20];


Client c;


identifiant= lookup_widget(button,"OA_identifiant2_modif");
strcpy(c.Id,gtk_entry_get_text(GTK_ENTRY(identifiant)));

//Nom Entry Text
nom = lookup_widget(button,"OA_nom2_modif");
strcpy(c.Nom,gtk_entry_get_text(GTK_ENTRY(nom)));

//Prenom Entry Text
prenom = lookup_widget(button,"OA_prenom2_modif");
strcpy(c.Prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

//Adresse Entry Text
Add = lookup_widget(button,"OA_adresse2_modif");
strcpy(c.Adresse,gtk_entry_get_text(GTK_ENTRY(Add)));

//Mail Entry Text
mail = lookup_widget(button,"OA_mail2_modif");
strcpy(c.Mail,gtk_entry_get_text(GTK_ENTRY(mail)));


// RADIO BUTTONS
Male = lookup_widget(button,"OA_male2_modif");
femelle = lookup_widget(button,"OA_femelle2_modif");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(femelle)))
{
strcpy(c.sexe,"femelle");
}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Male)))
{
strcpy(c.sexe,"male");
}

//spinbuttons
Jour = lookup_widget(button,"OA_jour2_modif");
Mois = lookup_widget(button,"OA_mois2_modif");
Annee = lookup_widget(button,"OA_annee2_modif");
c.ddn.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.ddn.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.ddn.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));


satis = lookup_widget(button,"OA_satisfait_modif");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(satis)))
strcpy(c.sat,"satisfait");

else
strcpy(c.sat,"dissatisfait");


// LABEL RESULTAT
 resultat=lookup_widget(button, "OA_modification_terminee_avec_succee_modif");
if ((strcmp(c.Id,"")==0) || (strcmp(c.Nom,"")==0) || (strcmp(c.Prenom,"")==0) || (strcmp(c.Adresse,"")==0) || (strcmp(c.Mail,"")==0)){
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Champs vides!");
}
else
{

int res=Modifier_client(c);
	if (res==0)
		gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Identifiant introuvable!");
	else if (res==1)
		gtk_label_set_text(GTK_LABEL(resultat),"Modification terminee avec success!");	
	}
}


void
on_OA_recherche_modif_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *identifiant;
GtkWidget *result;
char Id[20];
int r;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *adresse;
GtkWidget *mail;
GtkWidget *Male;
GtkWidget *femelle;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *satisfait;
Client * c;
c=malloc(sizeof (Client));
identifiant=lookup_widget(button,"OA_identifiant2_modif");
strcpy(Id,gtk_entry_get_text(GTK_ENTRY(identifiant)));


result= lookup_widget(button,"OA_modification_terminee_avec_succee_modif");

 if (strcmp(Id,"")==0) {
gtk_label_set_text(GTK_LABEL(result),"Erreur:Champs Identifiant vide!");
}
else {
r=verif(Id,c);
if (r==0){
gtk_label_set_text(GTK_LABEL(result),"identifiant introuvable ");
}
 else if(r==1){gtk_label_set_text(GTK_LABEL(result),"identifiant trouve ");
////////////////////////


//RADIO BUTTONS
Male = lookup_widget(button, "OA_male2_modif");
femelle = lookup_widget(button, "OA_femelle2_modif");
if (strcmp(c->sexe,"male")==0)
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(Male),TRUE);
else
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(femelle),TRUE);



// Spinbuttons
jour= lookup_widget(button, "OA_jour2_modif");
mois= lookup_widget(button, "OA_mois2_modif");
annee= lookup_widget(button,"OA_annee2_modif");

gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),c->ddn.Jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),c->ddn.Mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),c->ddn.Annee);

// labels
nom=lookup_widget(button,"OA_nom2_modif");
prenom=lookup_widget(button,"OA_prenom2_modif");
adresse=lookup_widget(button,"OA_adresse2_modif");
mail=lookup_widget(button,"OA_mail2_modif");

// entry
gtk_entry_set_text(GTK_ENTRY(nom),c->Nom);
gtk_entry_set_text(GTK_ENTRY(prenom),c->Prenom);
gtk_entry_set_text(GTK_ENTRY(adresse),c->Adresse);
gtk_entry_set_text(GTK_ENTRY(mail),c->Mail);


// checkbox
satisfait=lookup_widget(button,"OA_satisfait_modif");
if (strcmp(c->sat,"dissatisfait")!=0)
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(satisfait),TRUE);
else
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(satisfait),FALSE);
////////////////////////
}
else{gtk_label_set_text(GTK_LABEL(result),"erreur ");}
}

}


void
on_OA_supprimer3_supp_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget* identifiant;
GtkWidget* resultat;

char Id[50];

//Identifiant combobox 
identifiant= lookup_widget(button,"OA_Identifiant_supp");
strcpy(Id,gtk_entry_get_text(GTK_ENTRY(identifiant)));


resultat= lookup_widget(button,"OA_suppresion_termine_supp");

 if (strcmp(Id,"")==0) {
gtk_label_set_text(GTK_LABEL(resultat),"Erreur:Champ Identifiant vide!");
}

else{
// FONCTION suppression D'un client
int result= supprimer_client(Id);
if (result==1)
	gtk_label_set_text(GTK_LABEL(resultat),"suppression terminee!");
else 
	gtk_label_set_text(GTK_LABEL(resultat),"Identifiant introuvable!");
}
}


void
on_OA_Taux_dabsenteisme_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_Taux_dabsenteisme();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_OA_appliquer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *treeveiw;
GtkWidget *label;
int m,a,r;
float t;
char ch1[10];
char ch2[10];
char res[20];
char resultat[100];
treeveiw = lookup_widget(button,"treeview1");

mois = lookup_widget(button,"combobox1");
annee = lookup_widget(button,"combobox2");
label=lookup_widget(button,"label74");

if (gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois))!=NULL && 
gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee))!=NULL){
strcpy(ch1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(ch2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee)));


sscanf(ch1,"%d",&m);
sscanf(ch2,"%d",&a);

absen(m,a);
t=taux(m,a);
sprintf(res,"%f",t);

listview(treeveiw);



strcpy(resultat,"taux = ");
strcat(resultat,res);
gtk_label_set_text(GTK_LABEL(label),resultat);
}
else {gtk_label_set_text(GTK_LABEL(label),"veuillez choisir le mois et l\'annee");}
}


void
on_OA_retour_taux_dabsenteisme_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_statistiques();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_OA_annuler_taux_dabsenteisme_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_statistiques();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_HLbuttonGO_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_menu_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_TS_retour_from_menu_ouvrier_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_menu_proprietaire();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_TS_ajouter_ouvrier_label_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_ajoutOuvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_TS_ajout_annuler_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_menu_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_TS_ajout_retour_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_menu_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_TS_modifier_ouvrier_label_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_modifierOuvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_TS_retour_modif_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_menu_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_TS_annuler_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_menu_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_TS_supprimer_ouvrier_label_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_supprimer_un_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_TS_retour_supprimer_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_menu_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_TS_afficher_ouvriers_label_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *treeview;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_afficher_les_ouvriers();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));


treeview=lookup_widget(window,"TS_affichage_treeview");
affiche_listview(treeview);

}


void
on_TS_retour_affichage_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_menu_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_TS_validation_de_presence_label_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_validation_de_presence();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_TS_retour_VDP_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_menu_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HLboutonmeilleurOuv_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_TS_meilleur_ouvrier();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_TS_retour_MO_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_statistiques();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_HLbuttonTDADOPM_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_OA_Taux_dabsenteisme();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_TS_ajout_confirm_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget* Identifiant;
GtkWidget* nom;
GtkWidget* prenom;
GtkWidget* Jour;
GtkWidget* Mois;
GtkWidget* Annee;
GtkWidget* male;
GtkWidget* female;

GtkWidget* telephone;
GtkWidget* Adresse;

GtkWidget* Adressemail;
GtkWidget* resultat;

char Identif[50];
char NOM[50];
char PRENOM[50];
char Sexe[10];
char addres[30];
char adrmaill[30];
char tel[20];
tasnimouvrier o;
tasnimouvrier *c;
c= malloc(sizeof(tasnimouvrier));


//IDENTIFIANT ENTRY TEXT
Identifiant = lookup_widget(button, "TS_Identifiant_ajout");
strcpy(o.Id,gtk_entry_get_text(GTK_ENTRY(Identifiant)));


//nom ENTRY TEXT
nom = lookup_widget(button, "TS_nom_ajout");
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(nom)));


//prenom ENTRY TEXT
prenom = lookup_widget(button, "TS_prenom_ajout");
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));


// RADIO BUTTONS
male = lookup_widget(button,"TS_Male_ajout");
female = lookup_widget(button,"TS_Femelle_ajout");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(female)))
{
strcpy(o.sexe,"femelle");
}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(male)))
{
strcpy(o.sexe,"male");
}

//spinbuttons
Jour = lookup_widget(button,"TS_DN_Jour_ajout");
Mois = lookup_widget(button,"TS_DN_Mois_ajout");
Annee = lookup_widget(button,"TS_DN_Annee_ajout");
o.ddn.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
o.ddn.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
o.ddn.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));


//telephone ENTRY TEXT
telephone = lookup_widget(button, "TS_Telephone_ajout");
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(telephone)));
sscanf(tel ,"%d",&o.telephone);


//adresse ENTRY TEXT
Adresse = lookup_widget(button, "TS_Adresse_ajout");
strcpy(o.Adresse,gtk_entry_get_text(GTK_ENTRY(Adresse)));


//adressemail ENTRY TEXT
Adressemail = lookup_widget(button, "TS_Adresse_email_ajout");
strcpy(o.Adressemail,gtk_entry_get_text(GTK_ENTRY(Adressemail)));



//LABEL RESULTAT 
resultat=lookup_widget(button, "TS_resultat_ajout");


if (strcmp(o.Id,"")!=0&&strcmp(o.nom,"")!=0&&strcmp(o.prenom,"")!=0 &&strcmp(tel,"")!=0&&strcmp(o.Adresse,"")!=0 && strcmp(o.Adressemail,"")!=0){
//FONCTION AJOUT de ouvrier.C
int result=verifier_ouvrier(o.Id,c);
if (result==0){
	ajouter_ouvrier(o);
	gtk_label_set_text(GTK_LABEL(resultat),"Ajout termine avec succes!");}
else 
	gtk_label_set_text(GTK_LABEL(resultat),"Identifiant existe deja!");
}
else {gtk_label_set_text(GTK_LABEL(resultat),"Erreur: champs vides!");}

}


void
on_TS_rechercher_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget* Identifiant;
GtkWidget* nom;
GtkWidget* prenom;
GtkWidget* Jour;
GtkWidget* Mois;
GtkWidget* Annee;
GtkWidget* male;
GtkWidget* female;

GtkWidget* telephone;
GtkWidget* Adresse;

GtkWidget* Adressemail;
GtkWidget* resultat;

char Identif[50];
char NOM[50];
char PRENOM[50];
char Sexe[10];
char addres[30];
char adrmaill[30];
int tel;
char t[10];
tasnimouvrier o;
tasnimouvrier *c;
c= malloc(sizeof(tasnimouvrier));

//IDENTIFIANT combobox
Identifiant=lookup_widget(button,"TS_Identifiant_modif");
strcpy(Identif,gtk_entry_get_text(GTK_ENTRY(Identifiant)));

//nom ENTRY TEXT
nom = lookup_widget(button, "TS_nom_modif");



//prenom ENTRY TEXT
prenom = lookup_widget(button, "TS_prenom_modif");


//telephone ENTRY TEXT
telephone = lookup_widget(button, "TS_telephone_modif");



//adresse ENTRY TEXT
Adresse = lookup_widget(button, "TS_adresse_modif");



//adressemail ENTRY TEXT
Adressemail = lookup_widget(button, "TS_address_mail_modif");


//spinbuttons
Jour = lookup_widget(button,"TS_DN_jour_modif");
Mois = lookup_widget(button,"TS_DN_mois_modif");
Annee = lookup_widget(button,"TS_DN_annee_modif");


//o=recherche_ouvrier(Identifiant,nom_fichier);
resultat=lookup_widget(button,"TS_resultat_modif");

if (strcmp(Identif,"")==0)
gtk_label_set_text(GTK_LABEL(resultat),"ID vide");

else {
int result=verifier_ouvrier(Identif,c);

if (result==1){
gtk_label_set_text(GTK_LABEL(resultat),"Identifiant trouve");
////////////////////////

g_print("went through\n");
g_print("%s",c->nom);
//RADIO BUTTONS
male = lookup_widget(button, "TS_male_modif");
female = lookup_widget(button, "TS_femelle_modif");
if (strcmp(c->sexe,"male")==0)
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(male),TRUE);
else
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(female),TRUE);



gtk_spin_button_set_value(GTK_SPIN_BUTTON(Jour),c->ddn.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Mois),c->ddn.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Annee),c->ddn.annee);


// entry
gtk_entry_set_text(GTK_ENTRY(nom),c->nom);
gtk_entry_set_text(GTK_ENTRY(prenom),c->prenom);
gtk_entry_set_text(GTK_ENTRY(Adresse),c->Adresse);
char tel[50];
sprintf(tel,"%d",c->telephone);
gtk_entry_set_text(GTK_ENTRY(telephone),tel);
gtk_entry_set_text(GTK_ENTRY(Adressemail),c->Adressemail);


/////////////
}
else 
gtk_label_set_text(GTK_LABEL(resultat),"Identifiant inexsistant");
}
}


void
on_TS_confirm_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* Identifiant;
GtkWidget* nom;
GtkWidget* prenom;
GtkWidget* Jour;
GtkWidget* Mois;
GtkWidget* Annee;
GtkWidget* male;
GtkWidget* female;

GtkWidget* telephone;
GtkWidget* Adresse;

GtkWidget* Adressemail;
GtkWidget* resultat;

char Identif[50];
char NOM[50];
char PRENOM[50];
char Sexe[10];
char addres[30];
char adrmaill[30];
char tel[10];
tasnimouvrier o;
tasnimouvrier *c;
c= malloc(sizeof(tasnimouvrier));

//IDENTIFIANT combobox
Identifiant=lookup_widget(button,"TS_Identifiant_modif");
strcpy(o.Id,gtk_entry_get_text(GTK_ENTRY(Identifiant)));



//nom ENTRY TEXT
nom = lookup_widget(button, "TS_nom_modif");
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(nom)));



//prenom ENTRY TEXT
prenom = lookup_widget(button, "TS_prenom_modif");
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));



// RADIO BUTTONS
male = lookup_widget(button,"TS_male_modif");
female = lookup_widget(button,"TS_femelle_modif");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(female)))
{
strcpy(o.sexe,"femelle");

}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(male)))
{
strcpy(o.sexe,"male");
}

//spinbuttons
Jour = lookup_widget(button,"TS_DN_jour_modif");
Mois = lookup_widget(button,"TS_DN_mois_modif");
Annee = lookup_widget(button,"TS_DN_annee_modif");
o.ddn.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
o.ddn.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
o.ddn.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));


//telephone ENTRY TEXT
telephone = lookup_widget(button, "TS_telephone_modif");
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(telephone)));
sscanf(tel ,"%d",&o.telephone);



//adresse ENTRY TEXT
Adresse = lookup_widget(button, "TS_adresse_modif");
strcpy(o.Adresse,gtk_entry_get_text(GTK_ENTRY(Adresse)));



//adressemail ENTRY TEXT
Adressemail = lookup_widget(button, "TS_address_mail_modif");
strcpy(o.Adressemail,gtk_entry_get_text(GTK_ENTRY(Adressemail)));



//LABEL RESULTAT 
resultat=lookup_widget(button, "TS_resultat_modif");
if (strcmp(o.Id,"")==0)
{
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Champs vides!");
}
else
	{

	int res= verifier_ouvrier(o.Id,c);
	if (res==0)
		gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Identifiant introuvable!");
	else if (res==1){
	sup_ouvrier(o.Id);
	ajouter_ouvrier(o);
		gtk_label_set_text(GTK_LABEL(resultat),"Modification terminee avec success!");}	
	}


}


void
on_TS_appliquer_supprimer_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* Identifiant;
GtkWidget* resultat;
tasnimouvrier *c;
c= malloc(sizeof(tasnimouvrier));

char Identif[50];

//combobox identifiant supprimer
Identifiant=lookup_widget(button,"TS_Identifiant_supprimer");
strcpy(Identif,gtk_entry_get_text(GTK_ENTRY(Identifiant)));

// LABEL RESULTAT
 resultat=lookup_widget(button, "TS_resultat_supprimer");

// CONTROLE DE SAISIE SI COMBO BOX N'EST PAS SELECTIONNE

 if (strcmp(Identif,"")==0){
gtk_label_set_text(GTK_LABEL(resultat),"Champs vides");
}

else{

	int res= verifier_ouvrier(Identif,c);
	if (res==0)
		gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Identifiant introuvable!");
	else if (res==1){
sup_ouvrier(Identif);
		gtk_label_set_text(GTK_LABEL(resultat),"Suppression terminee avec success!");	}
	}

}


void
on_TS_valider_VDP_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget* Identifiant;
GtkWidget* resultat;
GtkWidget* Jour;
GtkWidget* Mois;
GtkWidget* Annee;
GtkWidget* result;
GtkWidget* absent;


char Identif[50];
int jour,mois,annee,abs;
int res,id;
Identifiant=lookup_widget(button,"TS_Identifiant_VDP");
strcpy(Identif,gtk_entry_get_text(GTK_ENTRY(Identifiant)));

sscanf(Identif ,"%d",&id);

// RADIO BUTTONS
absent = lookup_widget(button,"TS_checkbox_VDP");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(absent)))
{
abs=1;

}
else 
{
abs=0;
}

//spinbuttons
Jour = lookup_widget(button,"TS_jour_VDP");
Mois = lookup_widget(button,"TS_mois_VDP");
Annee = lookup_widget(button,"TS_annee_VDP");
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));

result=lookup_widget(button,"TS_resultat_VDP");

if (strcmp(Identif,"")!=0){
res=add_abss(id,jour,mois,annee,abs);
if (res==0)
gtk_label_set_text(GTK_LABEL(result),"Validation de presenece ajoutee");
else 
gtk_label_set_text(GTK_LABEL(result),"Validation de presenece exsiste deja");
}
else 
gtk_label_set_text(GTK_LABEL(result),"Erreur : champ identifiant vide");
}


void
on_TS_valider_MO_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Annee;
GtkWidget *ID;
GtkWidget *Heur;
int annee;
absence abs;
char i[10];
char i1[10];

Annee=lookup_widget(button,"TS_annee_MO");
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));

ID=lookup_widget(button,"TS_identifiant_MO");
Heur=lookup_widget(button,"TS_NHT_MO");
abs=absenn(annee);
sprintf(i,"%d",abs.id);

sprintf(i1,"%d",abs.heur);
gtk_label_set_text(GTK_LABEL(ID),i);
gtk_label_set_text(GTK_LABEL(Heur),i1);

}


void
on_HLbuttonGC_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_menu_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_ZF_retour_de_menu_capteurs_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_menu_proprietaire();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ZF_Ajouter_capteur_label_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_ajouter_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_ZF_retour_ajout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_menu_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ZF_annuler_ajout_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_menu_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ZF_modifier_capteur_label_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_modifier_un_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_ZF_annuler_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_menu_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ZF_retour_modif_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_menu_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ZF_supprimer_capteur_label_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_supprimer_un_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_ZF_retour_supprim_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_menu_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ZF_annuler_supprim_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_menu_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}





void
on_ZF_retour_afficher_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_menu_capteur();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}





void
on_ZF_retour_ADCADVA_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_statistiques();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}





void
on_HLbuttonNDCADVA_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *capteur;
GtkWidget *treeview;
int k;
char k1[100];

GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_NDCADVA();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
//

capteur= lookup_widget(window,"ZB_NB_CAPTEURS_ADVA");
k=alarment(0,10,40,50);
temper(0,10,40,50);
//k=alarment(1,40);
//temper(10,40);
sprintf(k1,"nb totale d'alarm = %d",k);

treeview= lookup_widget(window,"ZF_ADCADVA_treview");
affiche_alarm(treeview);
gtk_label_set_text(GTK_LABEL(capteur),k1);
/*capteur= lookup_widget(window6,"nombre_label");
k=alarment(0,10,40,50);
temper(0,10,40,50);
sprintf(k1,"nb totale d'alarm = %d",k);

treeview= lookup_widget(window6,"treeview1");
affiche_alarm(treeview);
gtk_label_set_text(GTK_LABEL(capteur),k1);*/

}


void
on_ZF_afficher_les_capteurs_label_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *treeveiw;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_ZF_afficher_les_capteurs();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
//


treeveiw=lookup_widget(window,"ZF_affichage_treeview");
affiche_zlistview1(treeveiw);


}


void
on_ZF_ajout_boutton_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* Identifiant;
GtkWidget* Humidite;
GtkWidget* Temperature;
GtkWidget* Marque;
GtkWidget* ComboBox;
GtkWidget* Reference;
GtkWidget* resultat;

char reference[20];
capteur C;
 
///////////////////IDENTIFIANT ENTRY TEXT
Identifiant = lookup_widget(button,"ZF_Identifiant_ajout");
strcpy(C.identifiant,gtk_entry_get_text(GTK_ENTRY(Identifiant)));

//RADIO BUTTON
Temperature=lookup_widget(button,"ZF_temperature_ajout");
Humidite=lookup_widget(button,"ZF_humidite_ajout");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Temperature)))
{ 
 strcpy(C.type,"Temperature");
}
else
{
 strcpy(C.type,"Humidite");
}

 resultat=lookup_widget(button, "ZF_resultat_ajout");

// combobox
Marque= lookup_widget(button,"ZF_marque_ajout");

// CONTROLE DE SAISIE SI COMBO BOX N'EST PAS SELECTIONNE

 if ((strcmp(C.identifiant,"")==0)) {
gtk_label_set_text(GTK_LABEL(resultat),"Champs vides");
return;
}

else{
strcpy(C.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Marque)));
}


//////////////Reference ENTRY TEXT
Reference = lookup_widget(button,"ZF_reference_ajout");
strcpy(reference,gtk_entry_get_text(GTK_ENTRY(Reference)));
sscanf(reference ,"%d",&C.reference);
// FONCTION AJOUT DE CAPTEUR.C
strcpy(C.etat,"bonne");

if (gtk_combo_box_get_active_text(GTK_COMBO_BOX(Marque))==NULL || strcmp(C.identifiant,"")==0 || strcmp(reference,"")==0)
{gtk_label_set_text(GTK_LABEL(resultat),"Erreur : champs vides!");}

else {

int result=ajouter(C);
if (result==1)
	gtk_label_set_text(GTK_LABEL(resultat),"Ajout termine avec succes!");
else 
{	gtk_label_set_text(GTK_LABEL(resultat),"Identifiant existe deja!");
}

}

}


void
on_ZF_recherche_modif_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Identifiant;
GtkWidget *resultat;
GtkWidget *temperature;
GtkWidget *humidite;
GtkWidget *ComboBox;
GtkWidget *reference;
GtkWidget *etat;

char identifiant [100];
int r=0;
capteur *c;
c=malloc(sizeof(capteur));

Identifiant = lookup_widget(button,"ZF_Identifiant_modif");
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(Identifiant)));
resultat= lookup_widget(button,"ZF_resulat_modif");
r=verifier(identifiant,c);
if (r==0)
gtk_label_set_text(GTK_LABEL(resultat),"identifiant n'exsiste pas");
else if (r==1)
{
gtk_label_set_text(GTK_LABEL(resultat),"identifiant trouve");


/////////////

//RADIO BUTTONS
temperature = lookup_widget(button, "ZF_temperature_modif");
humidite = lookup_widget(button, "ZF_humidite_modif");
if (strcmp(c->type,"Temperature")==0)
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(temperature),TRUE);
else
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(humidite),TRUE);


// combobox
ComboBox= lookup_widget(button,"ZF_marque_modif");

if (strcmp(c->marque,"WoMaster")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(ComboBox),2);
else if (strcmp(c->marque,"honeywell")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(ComboBox),1);
else if (strcmp(c->marque,"simex")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(ComboBox),0);

// labels
reference=lookup_widget(button,"ZF_reference_modif");

// entry
char ref[50];
sprintf(ref,"%d",c->reference);
gtk_entry_set_text(GTK_ENTRY(reference),ref);



// checkbox
etat=lookup_widget(button,"ZF_etat_modif");
if (strcmp(c->etat,"bonne")==0)
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(etat),TRUE);
else
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(etat),FALSE);

////////////
}
}


void
on_ZF_modifier_modif_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* Identifiant;
GtkWidget* Humidite;
GtkWidget* Temperature;
GtkWidget* Marque;
GtkWidget* ComboBox;
GtkWidget* Reference;
GtkWidget* resultat;
GtkWidget *Etat;

char reference[20];
capteur C;
 
///////////////////IDENTIFIANT ENTRY TEXT
Identifiant = lookup_widget(button,"ZF_Identifiant_modif");
strcpy(C.identifiant,gtk_entry_get_text(GTK_ENTRY(Identifiant)));

//RADIO BUTTON
Temperature=lookup_widget(button,"ZF_temperature_modif");
Humidite=lookup_widget(button,"ZF_humidite_modif");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Temperature)))
{ 
 strcpy(C.type,"Temperature");
}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Humidite)))
{
 strcpy(C.type,"Humidite");
}

 resultat=lookup_widget(button,"ZF_resulat_modif");

// combobox
Marque= lookup_widget(button,"ZF_marque_modif");

// CONTROLE DE SAISIE SI COMBO BOX N'EST PAS SELECTIONNE

 if (strcmp(C.identifiant,"")==0) {
gtk_label_set_text(GTK_LABEL(resultat),"Champs vides");
return 0;
}

else{
strcpy(C.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Marque)));
}


//////////////Reference ENTRY TEXT
Reference = lookup_widget(button,"ZF_reference_modif");
strcpy(reference,gtk_entry_get_text(GTK_ENTRY(Reference)));
sscanf(reference ,"%d",&C.reference);
// FONCTION AJOUT DE CAPTEUR.C

Etat = lookup_widget(button,"ZF_etat_modif");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Etat)))
strcpy(C.etat,"bonne");

else
strcpy(C.etat,"panne");

if (strcmp(C.identifiant,"")==0 ||gtk_combo_box_get_active_text(GTK_COMBO_BOX(Marque))==NULL || strcmp(reference,"")==0)
gtk_label_set_text(GTK_LABEL(resultat),"Erreur : champs vides");
else {

modifier(C);
	gtk_label_set_text(GTK_LABEL(resultat),"modif termine avec succes!");
}

}


void
on_ZF_supprimer_supprim_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* identifiant;
GtkWidget* resultat;

char id[50];
int res;

// IDENTIFIANT ENTRY TEXT
identifiant = lookup_widget(button, "ZF_Identifiant_supprim");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(identifiant)));

// LABEL RESULTAT
 resultat=lookup_widget(button, "ZF_resultat_supprim");

if (strcmp(id,"")!=0){

res=supprimer(id);


if (res==1)
	gtk_label_set_text(GTK_LABEL(resultat),"Suppression terminee avec success!");
else if (res==0)
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Identifiant introuvable!");
}
else 
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur: Champ Identifiant vide!");
}


void
on_HLbuttonLMALMDCD_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *resultat;
char *marq;
char result[20]="";
marq=malloc(100*sizeof(char));
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_AD_LA_MARQUE_ALMDCD();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));

// LABEL RESULTAT
 resultat=lookup_widget(window, "AD_MALMDCD");

marqueCapDeffecteueux("temperature.txt","capteur.txt" ,marq,-10.0 ,60.0);
//strcpy(result,marq);
gtk_label_set_text(GTK_LABEL(resultat),marq);

}


void
on_AD_retour_MALMDCD_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GdkColor color;
  color.red=0x0000;
  color.green=0xC000;
  color.blue=0xC000;

window=create_statistiques();
gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);

gtk_widget_show(window);
gtk_widget_destroy(GTK_WIDGET(button));
}

