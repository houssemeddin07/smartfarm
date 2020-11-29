#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "animaux.h"

char nom_fichier[100]="animaux.txt";
char nom_fich[100]="utilisateurs.txt";
char login_fichier[100]="login.txt";
void
on_HLbuttonConfirmer_clicked           (GtkWidget       *Window,  				gpointer         user_data)
{ 

char username[20];
char password[20];
GtkWidget* utilis;
GtkWidget* motdepasse;
GtkWidget* resultat;
GtkWidget* checkbox;
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
int result=chercher_utilisateur(username,password,nom_fich);

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
gtk_label_set_text(GTK_LABEL(resultat),"Champs vides");
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
gtk_label_set_text(GTK_LABEL(resultat),"Animal introuvable");

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

}


void
on_ADannulerAjout_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAnnulerAjouter;
windowAnnulerAjouter=create_AD_gestion_equipement();
gtk_widget_show(windowAnnulerAjouter);
gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_ADretourajouter_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourAjouter;
windowRetourAjouter=create_AD_gestion_equipement();
gtk_widget_show(windowRetourAjouter);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ADchercher_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRechercher;
windowRechercher=create_AD_modifier_equipement();
gtk_widget_show(windowRechercher);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_ADretourRechercher_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourRechercher;
windowRetourRechercher=create_AD_gestion_equipement();
gtk_widget_show(windowRetourRechercher);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_modifier_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_AD_annuler_modifier_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAnnulerModifier;
windowAnnulerModifier=create_AD_recherche_equipement();
gtk_widget_show(windowAnnulerModifier);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_retour_supp_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourSupp;
windowRetourSupp=create_AD_gestion_equipement();
gtk_widget_show(windowRetourSupp);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_supprimer_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupprimer;
windowsupprimer=create_AD_supprimer_equipement_oui();
gtk_widget_show(windowsupprimer);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_oui_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_AD_Non_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowNonsupprimer;
windowNonsupprimer=create_AD_supprimer_equipement();
gtk_widget_show(windowNonsupprimer);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_retour_afficher_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourAffiche;
windowRetourAffiche=create_AD_gestion_equipement();
gtk_widget_show(windowRetourAffiche);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_go_to_ajouter_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowGoToajouter;
windowGoToajouter=create_AD_ajouter_equipement ();
gtk_widget_show(windowGoToajouter);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_go_to_modifier_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowGoTomodifier;
windowGoTomodifier=create_AD_recherche_equipement();
gtk_widget_show(windowGoTomodifier);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_go_to_supprimer_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowGoTosupprimer;
windowGoTosupprimer=create_AD_supprimer_equipement();
gtk_widget_show(windowGoTosupprimer);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_go_to_afficher_enter             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowGoToafficher;
windowGoToafficher=create_AD_afficher_equipement();
gtk_widget_show(windowGoToafficher);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_AD_quiter_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_AD_retour_modifier_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRetourModifier;
windowRetourModifier=create_AD_gestion_equipement();
gtk_widget_show(windowRetourModifier);
gtk_widget_destroy(GTK_WIDGET(button));
}


void
on_HLbuttonGEA_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowHLbuttonGEA;
windowHLbuttonGEA=create_AD_gestion_equipement();
gtk_widget_show(windowHLbuttonGEA);
gtk_widget_destroy(GTK_WIDGET(button));
}

