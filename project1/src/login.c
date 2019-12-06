#include "login.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int verif (char login[], char Password[])
{
	int role=-1,r;
	char log[20],pass[20];
	FILE* f;
	
	f=fopen("/home/aziz/Downloads/project1/src/login.txt","r");
	if(f !=NULL)
	{
		while(fscanf(f,"%s %s %d\n",log,pass,&r)!=EOF)
		{
			if((strcmp(login,log)==0) && (strcmp(Password,pass)==0))
				role=r;
		}
		fclose(f);
	}
	return role;
}
