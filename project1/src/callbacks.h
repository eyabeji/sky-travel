#include <gtk/gtk.h>


void
on_cox_clicked                 (GtkWidget       *widget,
                                        gpointer         user_data);


void
on_buttonreserver_clicked              (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonsuppreservation_clicked       (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_filtrer_clicked                     (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_combobox1_changed                   (GtkWidget     *objet_graphique,
                                        gpointer         user_data);
