#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "login.h"
#include "reservation.h"

	GtkWidget *user;
	GtkWidget *Interfaceclient;


void
on_cox_clicked                 (GtkWidget       *widget,
                                        gpointer         user_data)
{

	GtkWidget *treeview7;
	GtkWidget *treeview2;
	GtkWidget *treeview3;
	GtkWidget *log, *pwd;
	GtkWidget *output;
	user=create_user();
	int x;
	char login1[20];
	char Password1[20];
	

	log=lookup_widget(widget,"log");
	pwd=lookup_widget(widget,"pwd");
	output=lookup_widget(widget,"err");
	//role=lookup_widget(widget,"role");
	strcpy(login1,gtk_entry_get_text(GTK_ENTRY(log)));
	strcpy(Password1,gtk_entry_get_text(GTK_ENTRY(pwd)));
	x = verif(login1,Password1);
	if (x==-1)
	{
		gtk_label_set_text(GTK_LABEL(output),"mdp incorrect");
	}	
	else
	{	
		user=lookup_widget(widget,"user");
		gtk_widget_destroy(user);
		Interfaceclient=create_Interfaceclient();
		gtk_widget_show(Interfaceclient);
		//gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"user")));
		treeview2=lookup_widget(Interfaceclient,"treeview2");
		afficher_hotel(treeview2);
		treeview3=lookup_widget(Interfaceclient,"treeview3");
		afficher_reservation(treeview3);	
		treeview7=lookup_widget(Interfaceclient,"treeview7");	
}
}


void
on_buttonreserver_clicked              (GtkWidget       *widget,
                                        gpointer         user_data)
{
	hotel h;
	GtkWidget *nomhot;
	GtkWidget *labelreserver;
	char nomhot1[20];
	int rep;

	nomhot=lookup_widget(widget,"nomhot");
	labelreserver=lookup_widget(widget,"labelreserver");
	strcpy(nomhot1,gtk_entry_get_text(GTK_ENTRY(nomhot)));
	rep=verification(nomhot1);
	if(rep==-1){
	

			gtk_label_set_text(GTK_LABEL(labelreserver),"erreur");
		   }else{
			reserver(h,nomhot1);
			gtk_label_set_text(GTK_LABEL(labelreserver),"reserver avec succ (y)");
			}

	

}

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
}


void
on_buttonsuppreservation_clicked       (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget  *nomr;
GtkWidget  *labelsuppreservation;
	char x[40];
	int rep;

	nomr=lookup_widget(widget,"nomreservation");
	labelsuppreservation=lookup_widget(widget,"labelsuppreservation");
	strcpy(x,gtk_entry_get_text(GTK_ENTRY(nomr)));
	rep=verificationsupp(x);
	if(rep==-1){
	

			gtk_label_set_text(GTK_LABEL(labelsuppreservation),"verifier nom");
		   }else{
			supprimer_reservation(x);
			gtk_label_set_text(GTK_LABEL(labelsuppreservation),"suppression avec succ");
			}
	//gtk_entry_set_text(GTK_ENTRY(idr), "");


}


/*void
on_filtrer_clicked                     (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget  *nomn ,treeview7;
char x[20];
int rep;
nomn=lookup_widget(widget,"filtrationnom");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(nomn)));
rep=fitrerreservation(x);
if (rep==-1) {
	gtk_label_set_text(GTK_LABEL(labelpasdehotels),"indisponibles");
}
else {
	fitrerreservation (char nomhot[]);	
	gtk_widget_show(treeview7);
	}

}
*/

void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_combobox1_changed                   (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
enum 
 {
	IDHOTEL,
        NOMHOTEL,
	VILLE,
	NBETOILE,
        PRIX,
	COLUMNS};
GtkWidget *combobox1 = lookup_widget(objet_graphique, "combobox1");

GtkWidget *t = lookup_widget(objet_graphique, "treeview7");

 GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
char idhotel[30];
char nomhotel[10];
char ville[30];
char nbetoile[10];
char prix[30];
FILE *f;

store = gtk_tree_view_get_model(t);
    if (strcmp("sousse", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))) == 0) {
      if (store == NULL) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" idhotel",renderer,"text",IDHOTEL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(t),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" nomhotel",renderer,"text",NOMHOTEL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(t),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" ville", renderer, "text",VILLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(t), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" nbetoile", renderer, "text", NBETOILE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(t), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" prix", renderer, "text",PRIX, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(t), column);

         }

        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    

      f = fopen("/home/aziz/Downloads/project1/src/sousse.txt", "r");
      if (f == NULL) {
        return;

      }else {
    while(fscanf(f, "%s %s %s %s %s ", idhotel, nomhotel, ville, nbetoile, prix) != EOF) {
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter, IDHOTEL,idhotel, NOMHOTEL, nomhotel, VILLE, ville, NBETOILE,nbetoile ,PRIX, prix, -1);
    
   } 
 fclose(f);
 gtk_tree_view_set_model(GTK_TREE_VIEW(t), GTK_TREE_MODEL(store));
    g_object_unref(store);




}}
}

