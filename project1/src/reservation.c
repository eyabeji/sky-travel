#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include "reservation.h"
#include <gtk/gtk.h>




//affichager hotel
void afficher_hotel(GtkWidget *liste)
{
enum   
{       
        IDHOTEL,
        NOMHOTEL,
	VILLE,
	NBETOILE,
        PRIX,
	COLUMNS
};

        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char idhotel[30];
	char nomhotel[10];
	char ville[30];
	char nbetoile[10];
	char prix[300];
        store=NULL;

        FILE *f;
	
store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("idhotel", renderer, "text",IDHOTEL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nomhotel", renderer, "text",NOMHOTEL, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ville", renderer, "text",VILLE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);		
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nbetoile", renderer, "text",NBETOILE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);     
	
	}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);

	f = fopen("/home/aziz/Downloads/project1/src/hotel.txt", "r");
	
	if(f!=NULL)

	{ f = fopen("/home/aziz/Downloads/project1/src/hotel.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s\n",idhotel,nomhotel,ville,nbetoile,prix)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, IDHOTEL, idhotel, NOMHOTEL,nomhotel, VILLE,ville, NBETOILE,nbetoile, PRIX,prix, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    	g_object_unref (store);
	}
}
int verification (char nomhot[])
{	int r=-1;
	char nomhotel[30];
	FILE* f;
	
	f=fopen("/home/aziz/Downloads/project1/src/hotel.txt","a+");
	if(f !=NULL)
	{
              while(fscanf(f,"%s \n",nomhotel)!=EOF)
		{
			if((strcmp(nomhot,nomhotel)==0))
			{
				r=0;		   
			
			}
		}
		fclose(f);
	}
	return r;
}
int fitrerreservation (char nomhot[])
{ int n=-1;
 char nomhotel[30];
FILE* f;
f=fopen("/home/aziz/Downloads/project1/src/reservation.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s \n",nomhotel)!=EOF)
		{
			if((strcmp(nomhot,nomhotel)==0))
			{ n=0;
				}
		}
		fclose(f);
	}
return n;
}	
int verificationsupp (char nomhot[])
{	int r=-1;
	char nomhotel[30];
	FILE* f;
	 
	f=fopen("/home/aziz/Downloads/project1/src/reservation.txt","a+");
	if(f !=NULL)
	{
              while(fscanf(f,"%s \n",nomhotel)!=EOF)
		{
			if((strcmp(nomhot,nomhotel)==0))
			{
				r=0;		   
			
			}
		}
		fclose(f);
	}
	return r;
}
//ajouter reservation
void reserver(hotel h,char x[])
{
enum   
{       
        IDHOTEL,
        NOMHOTEL,
	VILLE,
	NBETOILE,
        PRIX
};
	char idhotel[30];
	char nomhotel[10];
	char ville[30];
	char nbetoile[10];
	char prix[300];
	
	FILE* f;
	FILE* f1;
	
	f=fopen("/home/aziz/Downloads/project1/src/hotel.txt","r");
	f1=fopen("/home/aziz/Downloads/project1/src/reservation.txt","a+");
	if(f !=NULL)
	{
              while(fscanf(f,"%s %s %s %s %s \n",idhotel,nomhotel,ville,nbetoile,prix)!=EOF)
		{
				if(strcmp(x,nomhotel)==0){
			
				fprintf(f1,"%s %s %s %s %s \n",idhotel,nomhotel,ville,nbetoile,prix);	
		      					}
					
		}
		fclose(f);
		fclose(f1);
	}
}





//afficher mes reservation

void afficher_reservation(GtkWidget *liste)
{
enum   
{       
        IDHOTEL,
        NOMHOTEL,
	VILLE,
	NBETOILE,
        PRIX,
	COLUMNS
};

        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char idhotel[30];
	char nomhotel[10];
	char ville[30];
	char nbetoile[10];
	char prix[300];
        store=NULL;

        FILE *f;
	
store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("idhotel", renderer, "text",IDHOTEL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nomhotel", renderer, "text",NOMHOTEL, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ville", renderer, "text",VILLE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);		
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nbetoile", renderer, "text",NBETOILE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);     
	
	}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);

	f = fopen("/home/aziz/Downloads/project1/src/reservation.txt", "r");
	
	if(f!=NULL)

	{ f = fopen("/home/aziz/Downloads/project1/src/reservation.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s\n",idhotel,nomhotel,ville,nbetoile,prix)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, IDHOTEL, idhotel, NOMHOTEL,nomhotel, VILLE,ville, NBETOILE,nbetoile, PRIX,prix, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    	g_object_unref (store);
	}
}







//supprimer reservation
void supprimer_reservation(char x[])
{
	char idhotel[30];
	char nomhotel[10];
	char ville[30];
	char nbetoile[10];
	char prix[300];

FILE *f;
FILE *ftemp;

f=fopen("/home/aziz/Downloads/project1/src/reservation.txt","a+");
ftemp=fopen("/home/aziz/Downloads/project1/src/temp.txt","w+");

if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",idhotel,nomhotel,ville,nbetoile,prix)!=EOF)
		{
				if(strcmp(x,nomhotel)!=0){
			
				fprintf(ftemp,"%s %s %s %s %s \n",idhotel,nomhotel,ville,nbetoile,prix);	
		      					}
					
		}
fclose(ftemp);
fclose(f);
}
remove("/home/aziz/Downloads/project1/src/reservation.txt");
rename("/home/aziz/Downloads/project1/src/temp.txt","/home/aziz/Downloads/project1/src/reservation.txt");
}

