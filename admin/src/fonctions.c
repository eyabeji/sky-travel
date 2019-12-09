#include <string.h>
#include<stdlib.h>
#include"fonctions.h"
#include <gtk/gtk.h>
#include <stdio.h>
void ajouter (char login[],char password[], int role)
{
    FILE *f;
    f=fopen("/home/eya/Projets/admin/src/users.txt","a+");
    if(f!=NULL){//si le fichier est ouvert
        fprintf(f,"%s %s %d \n",login,password,role);
    }
    fclose(f);
}
void afficher()
{
    FILE *f;
    f=fopen("/home/eya/Projets/admin/src/users.txt","r");
    char login[20],password[20];
    int role;
    while(fscanf(f,"%s %s %d",login,password,&role)!=EOF){
        fprintf(f,"%s %s %d", login,password,role);
    }
    fclose(f);
}
int verifier(char login[],char password[])
{
    FILE *f;
    int role;
    char login1[20];char password1[20];
    f=fopen("/home/eya/Projets/admin/src/users.txt","r");//ouvrir le fichier users.txt et verifier
   
    while(fscanf(f,"%s %s %d", login1,password1,&role )!=EOF){//end of file si le ficher est terminer
        if (strcmp(login1,login)==0 && strcmp(password1,password)==0)
        {
            fclose(f);
            return (role);
        }
    }
    fclose(f);
    return 0;
}

void ajouterfiche(fiche fi)
{
	FILE *f;
	f = fopen("/home/eya/Projets/admin/src/fiche.txt","a");
	if(f!=NULL){
		fprintf(f,"%s %s %s %s %d %d %d %s %s\n",fi.nom,fi.prenom,fi.e_mail,fi.num_tel,fi.jour,fi.mois,fi.annee,fi.adresse,fi.sexe);
	}
	fclose(f);

}


void afficherfiche(GtkWidget *filistview)
{ 
enum {
       COL_NOM,
       COL_PRENOM,
       COL_E_MAIL, 
       COL_NUM_TEL,
       COL_JOUR,
       COL_MOIS,
       COL_ANNEE,
       COL_ADRESSE,
       COL_SEXE,
       NUM_COLS	
      };
char nom[20],prenom[20],e_mail[30],sexe[10],adresse[50],num_tel[50]; int jour,mois,annee;
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
GtkTreeIter *iter;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("/home/eya/Projets/admin/src/fiche.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s %s %d %d %d %s %s\n",nom,prenom,e_mail,num_tel,&jour,&mois,&annee,adresse,sexe)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_NOM, nom,
		          COL_PRENOM, prenom,
		          COL_E_MAIL, e_mail,
			  COL_NUM_TEL,num_tel,
                          COL_JOUR,jour,
                          COL_MOIS,mois,
                          COL_ANNEE,annee,
			  COL_ADRESSE,adresse,
			  COL_SEXE,sexe,
                   
                       -1);}
       

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Nom",celrender,"text",COL_NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Prenom",celrender,"text",COL_PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("e_mail",celrender,"text",COL_E_MAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("num_tel",celrender,"text",COL_NUM_TEL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
	
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("jour",celrender,"text",COL_JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mois",celrender,"text",COL_MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("annee",celrender,"text",COL_ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Adresse",celrender,"text",COL_ADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
	
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("sexe",celrender,"text",COL_SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	gtk_tree_view_set_model (GTK_TREE_VIEW(filistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}



void modifierfiche(char nom[],char prenom[],char e_mail[],char num_tel[],int jour,int mois,int annee,char adresse[],char sexe [] )
{    
    char nom1[20],prenom1[20],e_mail1[30],adresse1[50],sexe1[10], num_tel1[50]; int jour1,mois1,annee1;

    FILE *f , *tmp;
    f=fopen("/home/eya/Projets/admin/src/fiche.txt","r");
    tmp=fopen("/home/eya/Projets/admin/src/tmp.txt","a+");
    while(fscanf(f,"%s %s %s %s %d %d %d %s %s\n",nom1,prenom1,e_mail1,num_tel1,&jour1,&mois1,&annee1,adresse1,sexe1)!=EOF){
        if(!strcmp(nom,nom1)){fprintf(tmp,"%s %s %s %s %d %d %d %s %s\n",nom,prenom,e_mail,num_tel,jour,mois,annee,adresse,sexe);}
else fprintf(tmp,"%s %s %s %s %d %d %d %s %s\n",nom1,prenom1,e_mail1,num_tel1,jour1,mois1,annee1,adresse1,sexe1);
}
fclose(f);
fclose(tmp);
rename("/home/eya/Projets/admin/src/tmp.txt","/home/eya/Projets/admin/src/fiche.txt");
} 



void supprimerfiche(char nom[],char prenom[],char e_mail[],char num_tel[],int jour,int mois,int annee,char adresse[],char sexe [])
{    
    char nomNU[20],prenomNU[20],e_mailNU[30],sexeNU[10],adresseNU[50],num_telNU[50]; 
int jourNU,moisNU,anneeNU;
    
    FILE *f , *tmp;
    f=fopen("/home/eya/Projets/admin/src/fiche.txt","r");
    tmp=fopen("/home/eya/Projets/admin/src/tmp.txt","a+");
    while(fscanf(f,"%s %s %s %s %d %d %d %s %s\n",nomNU,prenomNU,e_mailNU,num_telNU,&jourNU,&moisNU,&anneeNU,adresseNU,sexeNU)!=EOF){
        if(strcmp(nom,nomNU) || strcmp(e_mail,e_mailNU) ||  strcmp(num_tel,num_telNU)  )
fprintf(tmp,"%s %s %s %s %d %d %d %s %s\n",nomNU,prenomNU,e_mailNU,num_telNU,jourNU,moisNU,anneeNU,adresseNU,sexeNU);
}
fclose(f);
fclose(tmp);
rename("/home/eya/Projets/admin/src/tmp.txt","/home/eya/Projets/admin/src/fiche.txt");
} 

