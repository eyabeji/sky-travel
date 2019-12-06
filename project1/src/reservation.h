#ifndef FONC_H_INCLUDED
#define FONC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct
{

char idhotel[30];
char nomhotel[10];
char ville[10];
char nbetoile[30];
char prix[300];

}hotel;

int verification (char nomhot[]);
int verificationsupp (char nomhot[]);
void afficher_hotel(GtkWidget *liste);
void reserver(hotel h,char x[]);
void afficher_reservation(GtkWidget *liste);
void supprimer_reservation(char x[]);
int fitrerreservation (char nomhot[]);
#endif
