#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"




void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	int x;
	GtkWidget *a ,*b,*c,*window1,*window2,*window6,*window7;
	char login[20],password[20];
	FILE *f;
      window1=lookup_widget(objet_graphique,"window1");
	a=lookup_widget(objet_graphique,"entry1");//entry1 est le nom donner dans le glade
	b=lookup_widget(objet_graphique,"entry2");
	c=lookup_widget(objet_graphique,"label4");//en cas d'erreur il est caché option
		

	strcpy(login,gtk_entry_get_text(GTK_ENTRY(a)));

	strcpy(password,gtk_entry_get_text(GTK_ENTRY(b)));
	x =verifier(login,password);


	if(x==1)
{
window2=create_window2();
gtk_widget_show (window2);
gtk_widget_hide(window1);

}

else if(x==2)
{
window6=create_window6();
gtk_widget_show (window6);
gtk_widget_hide(window1);

}
else if (x==3)
{
window7=create_window7();
gtk_widget_show (window7);
gtk_widget_hide(window1);

}
	else

	{
	gtk_label_set_text(GTK_LABEL(c),"Authentification non valide ");}

}




void
on_espace_client_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window2,*window3,*List_View;

	

window3=create_window3();
gtk_widget_show (window3);
window2=lookup_widget(objet_graphique,"window2");
gtk_widget_hide(window2);
List_View=lookup_widget(window3,"treeview1");
afficherfiche(List_View);

}


void
on_treeview1_row_activated             (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


gchar *nom,*prenom,*e_mail,*adresse,*num_tel,*sexe,*jour,*mois,*annee;

GtkWidget *window5,*window3, *nomNU,*prenomNU,*e_mailNU,*adresseNU,*num_telNU,*jourNU,*moisNU,*anneeNU,*sexeNU,*treeview;
	
	window5=create_window5();	
	treeview=lookup_widget(objet_graphique,"treeview1");
	    	
	window3=lookup_widget(objet_graphique,"window3");
 
    	nomNU=lookup_widget(window5, "entry8");
	prenomNU=lookup_widget(window5,"entry9");
	e_mailNU=lookup_widget(window5, "entry10");
	num_telNU=lookup_widget(window5, "entry11");
	jourNU=lookup_widget(window5, "spinbutton4");
	moisNU=lookup_widget(window5, "spinbutton5");
	anneeNU=lookup_widget(window5, "spinbutton6");
	adresseNU=lookup_widget(window5, "entry12");
	sexeNU=lookup_widget(window5, "combobox2");

    GtkTreeIter iter;
    GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
    gtk_tree_model_get_iter(model,&iter,path);
    gtk_tree_model_get (model,&iter,0,&nom,1,&prenom,2,&e_mail,3,&num_tel,7,&adresse,8,&sexe,-1);
    printf("%s %s %s %s %s %s %s %s %s\n",nom,prenom,e_mail,num_tel,jour,mois,annee,adresse,sexe);
   
    gtk_entry_set_text(GTK_ENTRY (nomNU),_(nom));
    gtk_entry_set_text(GTK_ENTRY (prenomNU),_(prenom));
    gtk_entry_set_text(GTK_ENTRY (e_mailNU),_(e_mail));
    gtk_entry_set_text(GTK_ENTRY (num_telNU),_(num_tel));
    gtk_entry_set_text(GTK_ENTRY (jourNU),_(jour));
    gtk_entry_set_text(GTK_ENTRY (moisNU),_(mois));
    gtk_entry_set_text(GTK_ENTRY (anneeNU),_(annee));
    gtk_entry_set_text(GTK_ENTRY (adresseNU),_(adresse));
    gtk_entry_set_text(GTK_ENTRY (sexeNU),_(sexe)); 
    gtk_widget_hide(window3);
    gtk_widget_show(window5);
}




void
on_ajout_client_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window4,*window3;


window4=create_window4();
gtk_widget_show (window4);
window3=lookup_widget(objet_graphique,"window3");
gtk_widget_hide(window3);	



}


void
on_modif_client_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window5,*window3;


window5=create_window5();
gtk_widget_show (window5);
window3=lookup_widget(objet_graphique,"window3");
gtk_widget_hide(window3);	


}


void
on_retour_menu_employer_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window2,*window3;


window2=create_window2();
gtk_widget_show (window2);
window3=lookup_widget(objet_graphique,"window3");
gtk_widget_hide(window3);	



}


void
on_retour_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{/*GtkWidget *window4,*window3,*List_View;

window4=lookup_widget(objet_graphique,"window4");
window3=create_window3();
gtk_widget_hide(window4);
List_View=lookup_widget(window3,"treeview1");
afficherfiche(List_View);
gtk_widget_show (window3);*/	



}


void
on_confirmer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
fiche fi;
GtkWidget *nom,*prenom,*e_mail,*adresse,*sexe,*jour,*mois,*annee ,*num_tel ;
GtkWidget *window3,*window4,*List_View;


nom=lookup_widget(objet_graphique, "entry3");
prenom=lookup_widget(objet_graphique,"entry4");
e_mail=lookup_widget(objet_graphique, "entry5");
jour=lookup_widget(objet_graphique, "spinbutton1");
mois=lookup_widget(objet_graphique, "spinbutton2");
annee=lookup_widget(objet_graphique, "spinannee");
adresse=lookup_widget(objet_graphique, "entry7");
num_tel=lookup_widget(objet_graphique, "entry6");
sexe=lookup_widget(objet_graphique, "combobox1");

strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(fi.e_mail,gtk_entry_get_text(GTK_ENTRY(e_mail)));
strcpy(fi.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe)));
fi.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
fi.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
fi.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(fi.num_tel,gtk_entry_get_text(GTK_ENTRY(num_tel)));
strcpy(fi.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));


ajouterfiche(fi);
window3=create_window3();
gtk_widget_show (window3);
window4=lookup_widget(objet_graphique,"window4");
gtk_widget_hide(window4);
List_View=lookup_widget(window3,"treeview1");
afficherfiche(List_View);
	

}


void
on_retour_gestion_client_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window5,*window3,*List_View;


window3=create_window3();
gtk_widget_show (window3);
window5=lookup_widget(objet_graphique,"window5");
gtk_widget_hide(window5);
List_View=lookup_widget(window3,"treeview1");
afficherfiche(List_View);
		



}


void
on_confirmer_modif_client_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nom1,*prenom1,*e_mail1,*adresse1,*sexe1,*jour1,*mois1,*annee1 ,*num_tel1,*window3,*window5,*List_View;

   fiche fi;

    char      nom[20],prenom[20],e_mail[30],sexe[10],adresse[50],num_tel[50];
   int jour,mois,annee;
  
    nom1=lookup_widget(objet_graphique, "entry8");
	prenom1=lookup_widget(objet_graphique,"entry9");
	e_mail1=lookup_widget(objet_graphique, "entry10");
	jour1=lookup_widget(objet_graphique, "spinbutton4");
	mois1=lookup_widget(objet_graphique, "spinbutton5");
	annee1=lookup_widget(objet_graphique, "spinbutton6");
	adresse1=lookup_widget(objet_graphique, "entry12");
	num_tel1=lookup_widget(objet_graphique, "entry11");
	sexe1=lookup_widget(objet_graphique, "combobox2");

strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(fi.e_mail,gtk_entry_get_text(GTK_ENTRY(e_mail1)));
strcpy(fi.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe1)));
jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour1));
mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois1));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
strcpy(fi.num_tel,gtk_entry_get_text(GTK_ENTRY(num_tel1)));
strcpy(fi.adresse,gtk_entry_get_text(GTK_ENTRY(adresse1)));
fi.jour=jour;
fi.mois=mois;
fi.annee=annee;

   modifierfiche(fi.nom,fi.prenom,fi.e_mail,fi.num_tel,fi.jour,fi.mois,fi.annee,fi.adresse,fi.sexe);

    window3=create_window3();
    gtk_widget_show(window3);
    window5=lookup_widget(objet_graphique,"window5");
    gtk_widget_hide(window5);
    List_View=lookup_widget(window3,"treeview1");
    afficherfiche(List_View);

}


void
on_supprimer_client_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *nomNU,*prenomNU,*e_mailNU,*adresseNU,*num_telNU,*jourNU,*moisNU,*anneeNU,*sexeNU,*window3,*window5,*List_View;

 
    fiche fi;
 char nom[20],prenom[20],e_mail[30],sexe[10],adresse[50],num_tel[50]; 
int jour,mois,annee;
    
	nomNU=lookup_widget(objet_graphique, "entry8");
	prenomNU=lookup_widget(objet_graphique,"entry9");
	e_mailNU=lookup_widget(objet_graphique, "entry10");
	jourNU=lookup_widget(objet_graphique, "spinbutton4");
	moisNU=lookup_widget(objet_graphique, "spinbutton5");
	anneeNU=lookup_widget(objet_graphique, "spinbutton6");
	adresseNU=lookup_widget(objet_graphique, "entry12");
	num_telNU=lookup_widget(objet_graphique, "entry11");
	sexeNU=lookup_widget(objet_graphique, "combobox2");



strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY(nomNU)));
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY(prenomNU)));
strcpy(fi.e_mail,gtk_entry_get_text(GTK_ENTRY(e_mailNU)));
//strcpy(fi.type_de_voyage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_de_voyageNU)));
//strcpy(fi.type_de_voyage" ");
fi.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jourNU));
fi.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(moisNU));
fi.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneeNU));
strcpy(fi.num_tel,gtk_entry_get_text(GTK_ENTRY(num_telNU)));
strcpy(fi.adresse,gtk_entry_get_text(GTK_ENTRY(adresseNU)));



//,prenom,e_mail,num_tel,jour,mois,annee,adresse,type_de_voyage
    supprimerfiche(fi.nom,fi.prenom,fi.e_mail,fi.num_tel,fi.jour,fi.mois,fi.annee,fi.adresse,fi.sexe);
    
    window3=create_window3();
    gtk_widget_show(window3);
    window5=lookup_widget(objet_graphique,"window5");
    gtk_widget_hide(window5);
    List_View=lookup_widget(window3,"treeview1");
    afficherfiche(List_View);

}





void
on_button_return_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4,*window3,*List_View;

window4=lookup_widget(objet_graphique,"window4");
window3=create_window3();
gtk_widget_hide(window4);
List_View=lookup_widget(window3,"treeview1");
afficherfiche(List_View);
gtk_widget_show (window3);

}


void
on_dadmin_clicked                      (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	
window1=create_window1();
gtk_widget_show (window1);
window2=lookup_widget(objet_graphique,"window2");
gtk_widget_hide(window2);

}




void
on_dagent_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1,*window6;
	
window1=create_window1();
gtk_widget_show (window1);
window6=lookup_widget(objet_graphique,"window6");
gtk_widget_hide(window6);


}


void
on_dclient_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1,*window7;
	
window1=create_window1();
gtk_widget_show (window1);
window7=lookup_widget(objet_graphique,"window7");
gtk_widget_hide(window7);

}

