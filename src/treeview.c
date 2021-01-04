#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#include "treeview.h"


enum
{
	IDENTIFIANT,
	NOM,
	PRENOM,
	JOUR,
	MOIS,
	ANNEE,
	SEXE,
	TELE,
	ADD,
	MAIL,
         COLUMNS};




void affiche_listview(GtkWidget *treeview2)
{
      GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char identifiant [30];
	char nom [30];
	char prenom [30];
	char jour[30];
	char mois[30];
	char annee[30];
	char sexe[30];
	char tele[30];
	char add[30];
	char mail[30];
       store=NULL;

    FILE *f;
	
	store=gtk_tree_view_get_model(treeview2);	
	if (store==NULL)
	{

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Identifiant", renderer, "text",IDENTIFIANT, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  NOM", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Jour", renderer, "text",JOUR, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Mois", renderer, "text",MOIS, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Annee", renderer, "text",ANNEE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);	
		

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Sexe", renderer, "text",SEXE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);	

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Telephone", renderer, "text",TELE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);
	
		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Addresse", renderer, "text",ADD, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);	
	
		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Mail", renderer, "text",MAIL, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);	
	
	
	
	}
	
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);

	f = fopen("ouvrier.txt", "r");
	
	if(f ==NULL)
	{
		g_print("fichier vide");
		return;
	}		
	else 

	{
		 f = fopen("ouvrier.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",identifiant, nom, prenom, jour, mois, annee, sexe,tele, mail, add)!=EOF)
		{

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, IDENTIFIANT , identifiant, NOM, nom, PRENOM, prenom, JOUR, jour, MOIS, mois, ANNEE, annee, SEXE, sexe,TELE,tele, ADD, add, MAIL, mail,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview2),    GTK_TREE_MODEL (store));
    g_object_unref (store);
}}


