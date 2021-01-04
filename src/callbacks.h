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

void
on_HB_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_annuler_ajout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_retour_ajout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_annuler_supp_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_annuler_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_retour_modif_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_ajout_gestion_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_supp_gestion_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_modif_gestion_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_affiche_gestion_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_quitter_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_HLbuttonGCL_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_OA_retour_menu_client_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_ajouter_un_client_menu_client_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_OA_anuler_ajout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_retour1_ajout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_afficher_un_client_menu_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_retour4_Affiche_client_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_modifier_client_menu_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_annuler2_modif_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_retour2_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_suuprimer_client_menu_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_annuler3_supp_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_Retour3_supp_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_HLbuttonCPV_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_retour_supp_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_retour_affichage_plante_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_HLbuttonLALPS_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_retour_annee_plus_seche_clicked  (GtkButton       *button,
                                        gpointer         user_data);


void
on_ADrechercheModif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ADAffichemanuelle_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ADAffichemecanique_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_HB_recherche_modif_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_HB_legumes_checkbox_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_HB_fruits_checkbox_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_OA_ajouter1_ajout_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_modifier2_modif_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_recherche_modif_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_supprimer3_supp_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_Taux_dabsenteisme_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_appliquer_clicked                (GtkButton       *button,
                                        gpointer         user_data);


void
on_OA_retour_taux_dabsenteisme_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_OA_annuler_taux_dabsenteisme_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_HLbuttonGO_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_retour_from_menu_ouvrier_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_ajouter_ouvrier_label_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_ajout_annuler_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_ajout_retour_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_modifier_ouvrier_label_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_retour_modif_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_annuler_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_supprimer_ouvrier_label_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_retour_supprimer_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_afficher_ouvriers_label_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_retour_affichage_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_validation_de_presence_label_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_retour_VDP_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_HLboutonmeilleurOuv_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_retour_MO_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_HLbuttonTDADOPM_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_ajout_confirm_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_rechercher_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_confirm_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_appliquer_supprimer_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_valider_VDP_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_TS_valider_MO_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_HLbuttonGC_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_retour_de_menu_capteurs_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_Ajouter_capteur_label_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_retour_ajout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_annuler_ajout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_modifier_capteur_label_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_annuler_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_retour_modif_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_supprimer_capteur_label_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_retour_supprim_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_annuler_supprim_clicked          (GtkButton       *button,
                                        gpointer         user_data);


void
on_ZF_retour_afficher_clicked          (GtkButton       *button,
                                        gpointer         user_data);


void
on_ZF_retour_ADCADVA_clicked           (GtkButton       *button,
                                        gpointer         user_data);




void
on_HLbuttonNDCADVA_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_afficher_les_capteurs_label_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_ajout_boutton_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_recherche_modif_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_modifier_modif_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_ZF_supprimer_supprim_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_HLbuttonLMALMDCD_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_AD_retour_MALMDCD_clicked           (GtkButton       *button,
                                        gpointer         user_data);
