#include <gtk/gtk.h>


void
on_HLbuttonConfirmer_pressed           (GtkButton       *button,
                                        gpointer         user_data);

void
on_HLbuttonConfirmer_clicked           (GtkWidget    *Window,           					gpointer         user_data);

void
on_HLbuttonCreerUnCompte_clicked       (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonRetourCreeCompte_clicked    (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonAnnulerCreerCompte_clicked  (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonDeconnecter_clicked         (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonGT_clicked                  (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonRetourduMenuTroupeau_clicked
                                        (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonRetourTroupeauMenu_clicked  (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonAnnulerAjout_clicked        (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonAfficherTr_clicked          (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonTARetour_clicked            (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonAjouterAn_clicked           (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonModifierAn_clicked          (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonAnnulerModif_clicked        (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonRetourDuModif_clicked       (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonSupprimerAn_clicked         (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonAnnulerSupprim_clicked      (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonRetourduSupprim_clicked     (GtkWidget       *Window,
                                        gpointer         user_data);
                           

void
on_HLbuttonStatistiques_clicked        (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonRetourdeStatistique_clicked (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonLNDTDCG__clicked            (GtkWidget       *Window,
                                        gpointer         user_data);

void
on_HLbuttonRDNDT_clicked               (GtkWidget       *Window,
                                        gpointer         user_data);



void
on_HLbuttonAjout_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_HLtreeviewAffichage_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_HLcheckbuttonVaches_toggled         (GtkWidget *togglebutton,
                                        gpointer         user_data);

void
on_HLcheckbuttonChevres_toggled        (GtkWidget *togglebutton,
                                        gpointer         user_data);

void
on_HLcheckbuttonMoutons_toggled        (GtkWidget *togglebutton,
                                        gpointer         user_data);

void
on_HLChercher_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_HLbuttonModif_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_HLbuttonSupprim_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_HLbuttonCreerCompte_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_HLcheckbuttonSauvegarderInfo_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ADajouterAjouter_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ADannulerAjout_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ADretourajouter_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ADchercher_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ADretourRechercher_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_modifier_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_annuler_modifier_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_retour_supp_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_supprimer_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_oui_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_Non_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_retour_afficher_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_go_to_ajouter_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_go_to_modifier_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_go_to_supprimer_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_go_to_afficher_enter             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_quiter_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_AD_retour_modifier_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_HLbuttonGEA_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);
