#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#include "ztreeview.h"
#include "capteur.h"



enum
{
	IDENTIFIANT,
	TYPE,
        MARQUE,
      	REFERENCE,
	ETAT,
         COLUMNS};



void affiche_zlistview1(GtkWidget *treeview2)
{
      GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char identifiant [30];
	char type [30];
	char marque [30];
	char reference [30];
	char etat[30];
       store=NULL;

    FILE *f;
	
	store=gtk_tree_view_get_model(treeview2);	
	if (store==NULL)
	{

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Identifiant", renderer, "text",IDENTIFIANT, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  TYPE", renderer, "text",TYPE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  MARQUE", renderer, "text",MARQUE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Reference", renderer, "text",REFERENCE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Etat", renderer, "text",ETAT, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);
	
	}
	
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);

	f = fopen("capteur.txt", "r");
	
	if(f ==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("capteur.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s",identifiant,type,marque,reference,etat)!=EOF)
		{

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, IDENTIFIANT , identifiant , TYPE , type , MARQUE , marque ,REFERENCE , reference , ETAT, etat,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview2),    GTK_TREE_MODEL (store));
    g_object_unref (store);
}}


enum
{
	ID,
	ALAR,
         N_COLUMNS};



void affiche_alarm(GtkWidget *treeview2)
{
      GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char identifiant [30];
	char alarm[30];
       store=NULL;

    FILE *f;
	
	store=gtk_tree_view_get_model(treeview2);	
	if (store==NULL)
	{

		 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Identifiant", renderer, "text",ID, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nb d'Alarm", renderer, "text",ALAR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2), column);
	
	}
	
		store=gtk_list_store_new (N_COLUMNS, G_TYPE_STRING,  G_TYPE_STRING);

	f = fopen("rature.txt", "r");
	
	if(f ==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("rature.txt", "a+");
              while(fscanf(f,"%s %s",identifiant,alarm)!=EOF)
		{

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID , identifiant ,ALAR,alarm,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview2),    GTK_TREE_MODEL (store));
    g_object_unref (store);
}}

