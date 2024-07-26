#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"


char* allocation()
{
	char* txt;
	txt = (char*)malloc(10000*sizeof(char));
	if(txt == NULL)
	{
		printf("Erreur d'allocation");
		exit (1);
	}
	return (txt);
}

int* allocationTab(int dernier_numero)
{
	int* tab = NULL;
	tab = (int*)malloc(dernier_numero*sizeof(int));
	if(tab == NULL)
	{
		printf("Erreur d'allocation");
		exit (1);
	}
	return (tab);
}

int studentCount(char* txt)
{
	char debut[255];
	int i = 0, ligne = 0, nb_eleve, j = 0;
	FILE *f = NULL;
	f=fopen("./L1.csv", "r");
	// while(feof(f) != 0)
	// {
	// 	fscanf(f, "%c", &debut[j]);
	// }
	(fgets(debut, sizeof debut, f));
	
	while(feof(f) != 1)
	{
		fscanf(f, "%c", &txt[i]);
		printf("%c", txt[i]);
		if(ligne <= 5 && txt[i] == '1')
		{
			nb_eleve = 0;
		}
		else if(txt[i]=='\n')
		{
			nb_eleve++;
			ligne++;
		}
		i++;
	}
	fclose(f);
	return (nb_eleve);
}
void toLower(char *str)
{
    int i;
    for (i = 0; str[i]; i++) 
    {
        str[i] = tolower(str[i]);
    }
}

int search(char *fichier)
{
    int found = 0;
    char *name = NULL;
    name = (char*)malloc(1000 * sizeof(char));
    int numero = 0;
    char *stock;
    stock = (char*)malloc(1000 * sizeof(char));

    printf ("Entrer votre nom: \n");
    printf ("==> "); 
    fgets(name, 1000, stdin);
    name[strcspn(name,"\n")] = 0;
	toLower(name);
    FILE *fic = NULL;
	fic = fopen ("./L1.csv", "r");
	char temp[sizeof(stock)];
    while(fgets(stock, 1000, fic) != NULL) 
	{
        stock[strcspn(stock, "\n")] = 0;
		strcpy(temp, stock);
		toLower(temp);
		numero++;
        if (strstr(temp, name) != NULL)
		{
            found = 1;
            //printf ("est-ce que c'est votre nom : %s?\n", stock);
            //break;
            char *startname = strchr(stock, ':');
            if (startname != NULL) 
			{
                startname += 1;
                
                char *endname = strchr (startname, ':');
                if (endname != NULL) 
				{
                    size_t resultname = endname - startname;
                    char fullname [1000];
                    strncpy(fullname, startname, resultname);
                    fullname[resultname] = '\0';
                    printf ("%s\n", fullname);
                }
            }
			break;
        }
    }
    
    if (!found)
	{
        printf ("%s n'as pas été trouver\n", name);
		numero = search(fichier);	// raha tsy hita ilay anarana dia miverina mitady anarana hafa
    }

	fclose(fic);
    free (name);
    free (stock);

	return numero;
}

int saisiNum(int numMax)
{
	int numero = 0;
	printf(" ________________________________\n");
	printf("|                                |");
	printf("\n| Il y a %d eleves dans la liste |\n", numMax);
    	printf("|________________________________|\n");
    do
    {
	    printf("\nEntrez le numero de l'eleve : ");
    	scanf("%d", &numero);
        if (numero > numMax || numero <= 0) {
            printf ("Ce numero ne fait pas partie de la liste, rééssayez\n");
            
        }        
    }while(numero > numMax || numero <= 0);
	return (numero);
}

void presence(char* fichier, char* txt, int numero)
{
	 int ligne = 0;
	 FILE* f = NULL;
	 FILE* f2 = NULL;
	 f = fopen ("./L1.csv", "r"); //Fichier source
	 f2 = fopen (fichier, "a+");
	 while(fgets(txt, 500, f))
	{
		ligne++;
		if(ligne == numero+1)
		{
			
			char* num = strtok(txt,":");
			char* nom_eleve = strtok(NULL,":");
			if (num != NULL && nom_eleve != NULL){
				printf (" ___________________________________________\n");
				printf ("|                                           |\n");
				printf("|                                           |\n|\033[94m%s : %s\033[0m\n", num, nom_eleve);
				printf ("|___________________________________________|\n");
				fprintf(f2, "%s : %s: ", num, nom_eleve);
			}
			break;
		}
	}
	fclose (f);
	fclose (f2);
 }

int Avis(char *option)
{		
	int choix = 0;
	int choix1 = 0;
	char *choix2;
	do
	{
			printf ("==> voulez-vous prendre votre pc ? <==\n");
			printf("\n\033[36m ___________________________________\033[0m\n");
			printf ("\033[36m|\033[0m\033[92m 0.OUI\033[0m");
			printf("                             \033[36m|\033[0m\n");
			printf ("\033[36m|\033[0m\033[91m 1.NON\033[0m");
			printf("                             \033[36m|\033[0m\n");
			printf ("\033[36m|\033[0m\033[34m 2.PRESO \033[0m(j'utilise mon propre PC) \033[36m|\033[0m\n");
			printf ("\033[36m|\033[0m\033[95m 3.ABS\033[0m");
			printf("                             \033[36m|\033[0m\n");
			printf("\033[36m|___________________________________|\033[0m  ___________________________________\n");
			printf("               \033[36m||\033[0m                     |                                   |\n");
			printf ("               \033[36m||_____________________\033[0m|  Tapez :                          |\n");
			printf ("               \033[36m||_____________________\033[0m| \033[92m (1) \033[0m: pour choisir par numero    |\n");
			printf ("                                      | \033[91m (2) \033[0m: pour choisir par mot       |\n");
			printf("                                      |___________________________________|\n");
			printf ("\n==> ");
			scanf("%d",&choix1);
		
		if(choix1 == 1 || choix1 == 2)
		{
			/*if(choix == 1 || choix == 2)
			{*/
				switch (choix1) 
				{
					case (1) :
					printf ("\n==> ");
					scanf ("%d", &choix);
					if(choix < 0 || choix > 3)
					{
						printf("%d ne fait pas partie des options\n", choix);
					}
					break;
					case (2) :
					printf ("\n==> ");
					scanf ("%s", choix2);
					if(strcmp(choix2,"oui") == 0 || strcmp(choix2,"OUI") == 0 || strcmp(choix2,"Oui") == 0 || strcmp(choix2,"oUi") == 0 || strcmp(choix2,"ouI") == 0 || strcmp(choix2,"OUi") == 0 || strcmp(choix2,"oUI") == 0 || strcmp(choix2,"OuI") == 0 || strcmp(choix2,"non") == 0 || strcmp(choix2,"Non") == 0 || strcmp(choix2,"nOn") == 0 || strcmp(choix2,"noN") == 0 || strcmp(choix2,"NOn") == 0 || strcmp(choix2,"nON") == 0 || strcmp(choix2,"NoN") == 0 || strcmp(choix2,"perso") == 0 || strcmp(choix2,"PERSO") == 0 || strcmp(choix2,"absent") == 0 || strcmp(choix2,"ABS") == 0 || strcmp(choix2,"abs") == 0)
					{
						printf("vous avez choisi l'option %s\n", choix2);
					}
					else{
						printf("%s ne fait pas partie des options\nRecommencez s'il vous plait!\n", choix2);
					}

					break;
				}
			/*}
			else
			{
				printf("Erreur de frappe!!\nRecommencez s'il vous plait!\n");
			}*/
		}
		else
		{
			printf ("Erreur de frappe!!\nRecommencez s'il vous plait!\n==> ");
			scanf("%d",&choix1);
				switch (choix1) 
				{
					case (1) :
					{
					printf ("\n==> ");
					scanf ("%d", &choix);
					if(choix < 0 || choix > 3)
					{
						printf("%d ne fait pas partie des options\n", choix);
					}
					else
					{
						printf("vous avez choisi l'option %s\n", choix2);

					}					
					}
					break;
					case (2) :
					printf ("\n==> ");
					scanf ("%s", choix2);
					if(strcmp(choix2,"oui") == 0 || strcmp(choix2,"OUI") == 0 || strcmp(choix2,"Oui") == 0 || strcmp(choix2,"oUi") == 0 || strcmp(choix2,"ouI") == 0 || strcmp(choix2,"OUi") == 0 || strcmp(choix2,"oUI") == 0 || strcmp(choix2,"OuI") == 0 || strcmp(choix2,"non") == 0 || strcmp(choix2,"Non") == 0 || strcmp(choix2,"nOn") == 0 || strcmp(choix2,"noN") == 0 || strcmp(choix2,"NOn") == 0 || strcmp(choix2,"nON") == 0 || strcmp(choix2,"NoN") == 0 || strcmp(choix2,"perso") == 0 || strcmp(choix2,"PERSO") == 0 || strcmp(choix2,"absent") == 0 || strcmp(choix2,"ABS") == 0 || strcmp(choix2,"abs") == 0)
					{
						printf("vous avez choisi l'option %s\n", choix2);
					}
					else{
						printf("%s ne fait pas partie des options\nRecommencez s'il vous plait!\n", choix2);
					}

					break;
				}
			/*}
			else
			{
				printf("Erreur de frappe!!\nRecommencez s'il vous plait!\n");
			}*/
		}

	}
	while(choix < 0 || choix > 3);
    switch (choix1){
		case (1) :
		switch (choix) {
        	case (OUI) :
				strcpy(option, "oui");
            	printf ("%s\n", option);
            	break;
        	case (NON) :
				strcpy(option, "non");
            	printf ("%s\n", option);
            	break;
        	case (PERSO) :
				strcpy(option, "perso");
        	    printf ("%s\n", option);
        	    break;
        	case (ABS) :
				strcpy(option, "abs");
        	    printf ("%s\n", option);
        	    break;        
        	default :
        	    printf ("erreur\n");
        	    break;
    	}
		break;
		case (2) :
			switch (choix) {
        	case (OUI) :
				strcpy(option, "oui");
            	printf ("%s\n", choix2);
				option=choix2;
            	break;
        	case (NON) :
				strcpy(option, "non");
            	printf ("%s\n", choix2);
            	option=choix2;
				break;
        	case (PERSO) :
				strcpy(option, "perso");
        	    printf ("%s\n", choix2);
        	    option=choix2;
				break;
        	case (ABS) :
				strcpy(option, "abs");
        	    printf ("%s\n", choix2);
        	    option=choix2;
				break;        
        	default :
        	    printf ("erreur\n");
        	    break;
    	}
		break;
	}

	return (choix);
}

void check(char* fichier, char* txt, int numero, char* option) 
{
    FILE* fic_source = fopen("./L1.csv", "r");
    FILE* fic_dest = fopen(fichier, "w");
	char debut[255];
	(fgets(debut, sizeof debut, fic_source));
    if (fic_source == NULL || fic_dest == NULL) 
	{
        printf("Erreur d'ouverture du fichier\n");
        exit(1);
    }

    int ligne = 0;
	char date[12] = __DATE__;
	debut[strcspn(debut, "\n")] = '\0';
	fprintf(fic_dest, "%s:%s\n", debut, date);
    while (fgets(txt, 500, fic_source)) 
	{
        ligne++;
        // Supprime le caractère de nouvelle ligne à la fin de chaque ligne si présent
        txt[strcspn(txt, "\n")] = 0;
        if (ligne == numero + 1) 
		{
            // Écrire l'avis de l'utilisateur pour l'étudiant spécifié
            fprintf(fic_dest, "%s: %s\n", txt, option);
        } else {
            // Écrire l'avis par défaut "non" pour les autres étudiants
            fprintf(fic_dest, "%s: non\n", txt);
        }
    }

    fclose(fic_source);
    fclose(fic_dest);
}




void name_number(char *fichier)
{
	FILE *fic = NULL;
	fic = fopen ("./L1.csv", "r");
	char* txt = NULL;
	char option[10];
	int nb_eleve = 0;
	txt = allocation();
	nb_eleve = studentCount(txt);
	int number, choix=0;
	int choice=0;
	char* choice1=0;
	int choice2=0;
	do
	{
		printf("_______________________\n");
		printf("|                      |\n");
		printf("|(1):Entrez le nom     |\n");
		printf("|(2):Entrez le numero  |\n");
		printf("|(3):QUITER |\n");
		printf("_______________________\n");
		scanf("%d", &choice);
		getchar();
		switch(choice)
		{
			case 1:
				number = search(fichier);
				presence(fichier, txt, number-2);
				choix = Avis(option);
				check(fichier, txt, number-2, option);
				break;
			case 2:
				number=saisiNum(nb_eleve);
				presence(fichier, txt, number);
				choix = Avis(option);
				check(fichier, txt, number, option);
				break;
			case 3:
				exit(0);
			default:
				printf("Mauvais choix");
				break;	
		}
	}while(choix!=3);
}

void titrePage(FILE* fichier)
{
	char Date[50];
	time_t today;
	time(&today);
	struct tm *syncro = localtime(&today);
	strftime(Date, sizeof(Date), "Acacia_%d-%m-%Y.html", syncro);
	
	fichier = fopen(Date, "w");
	
	fprintf(fichier, "<HTML>\n\t<HEAD>\n\t\t<TITLE>\n\t\t\tprésence L1\n");
	fprintf(fichier, "\t\t</TITLE>\n\t</HEAD>\n\t<BODY bgcolor = #CCCCCC>\n");
	fprintf(fichier, "\t\t<CENTER>\n\t\t\t<TABLE border = 8>\n\t\t");
	fprintf(fichier, "\t\t<TR>\n\t\t\t\t\t<TD>\n\t\t\t\t\t\t");
	fprintf(fichier, "<FONT SIZE = 32 COLOR = #AA0000>\n");
	fprintf(fichier, "\t\t\t\t\t\t\t<B>\n\t\t\t\t\t\t\t\t");
	fprintf(fichier, "Présence du niveau L1 de la mention MIT\n");
	fprintf(fichier, "\t\t\t\t\t\t\t</B>\n\t\t\t\t\t\t");
	fprintf(fichier, "</FONT>\n\t\t\t\t\t</TD>\n");
	fprintf(fichier, "\t\t\t\t</TR>\n\t\t\t</TABLE>\n\t\t</CENTER><BR>\n");
	
	fclose(fichier);
}

void enteteTab(FILE* fichier)
{
	char Date[50];
	time_t today;
	time(&today);
	struct tm *syncro = localtime(&today);
	strftime(Date, sizeof(Date), "Acacia_%d-%m-%Y.html", syncro);
	fichier = fopen(Date, "a+");
	
	fprintf(fichier, "\t\t<TABLE border = 4>\n\t\t\t<TR>\n");
	
	fprintf(fichier, "\t\t\t\t<TD>\n\t\t\t\t\t");
	fprintf(fichier, "<FONT COLOR = #007700>\n");
	fprintf(fichier, "\t\t\t\t\t\t<B>\n");
	fprintf(fichier, "\t\t\t\t\t\t\tNUMERO\n");
	fprintf(fichier, "\t\t\t\t\t\t</B>\n\t\t\t\t\t");
	fprintf(fichier, "</FONT>\n\t\t\t\t</TD>\n");
	
	fprintf(fichier, "\t\t\t\t<TD>\n\t\t\t\t\t");
	fprintf(fichier, "<FONT COLOR = #007700>\n");
	fprintf(fichier, "\t\t\t\t\t\t<B>\n");
	fprintf(fichier, "\t\t\t\t\t\t\tNOM ET PRÉNOM(S)\n");
	fprintf(fichier, "\t\t\t\t\t\t</B>\n\t\t\t\t\t");
	fprintf(fichier, "</FONT>\n\t\t\t\t</TD>\n");
	fprintf(fichier, "\t\t\t</TR>\n\t\t\t<TR>\n");
	
	fclose(fichier);
}

void prepaBackup(FILE* fichier_1, FILE* fichier_2, char* txt)
{
	char Date[50];
	time_t today;
	time(&today);
	struct tm *syncro = localtime(&today);
	strftime(Date, sizeof(Date), "Acacia_%d-%m-%Y.csv", syncro);
	int ligne = 0, i = 0;
	fichier_1 = fopen("/home/mit/trait/devoir/L1.csv", "r");
	fichier_2 = fopen(Date, "w");
	while(fgets(txt, 500, fichier_1))
	{
		if(ligne >= 0)
		{
			char* num = strtok(txt, ":");
			char* nom_eleve = strtok(NULL, ":");
			if(num != NULL && nom_eleve !=NULL)
			{
				fprintf(fichier_2, "%s %s\n", num, nom_eleve);
			}
		}
		else if(txt[i] == '\n')
		{
			ligne++;
		}
	}
	fclose(fichier_1);
	fclose(fichier_2);
}

int studentCount(char* txt)
{
	int i = 0, ligne = 0, nb_eleve;
	FILE *fichier = NULL;
	fichier=fopen("/home/mit/trait/devoir/L1.csv", "r");
	while(feof(fichier) != 1)
	{
		fscanf(fichier, "%c", &txt[i]);
		if(ligne <= 5 && txt[i] == '1')
		{
			nb_eleve = 0;
		}
		else if(txt[i]=='\n')
		{
			nb_eleve++;
			ligne++;
		}
		i++;
	}
	fclose(fichier);
	return (nb_eleve);
}

void saveStudents(FILE* fichier, char* txt, struct eleve *eleves, int nb_eleve)
{
	char Date[50];
	time_t today;
	time(&today);
	struct tm *syncro = localtime(&today);
	strftime(Date, sizeof(Date), "Acacia_%d-%m-%Y.csv", syncro);
	int i = 0, ligne = 0, j = 0;
	fichier = fopen("/home/mit/trait/devoir/Backup_L1.csv", "r");
	ligne = 0;
	 while(fgets(txt, 500, fichier))
	{
		ligne++;
		if(ligne >= 1 && ligne <= nb_eleve)
		{
			fscanf(fichier, "%d %[^\n]", &eleves[j].numero, eleves[j].nom_et_prenom);
		}
		else if(txt[i] == '\n')
		{
			ligne++;
		}
		i++;
		j++;
	}
	
	fclose(fichier);
}

void creationPage(FILE* fichier_1, FILE* fichier_2, struct eleve *eleves, int nb_eleve)
{
	char Date[50];
	time_t today;
	time(&today);
	struct tm *syncro = localtime(&today);
	strftime(Date, sizeof(Date), "Acacia_%d-%m-%Y.html", syncro);
	int i = 0;
	fichier_1 = fopen("/home/mit/trait/devoir/L1.csv", "r");
	fichier_2 = fopen(Date, "a+");
	while(i < nb_eleve)
	{
		fprintf(fichier_2, "\t\t\t\t<TD>\n\t\t\t\t\t");
		fprintf(fichier_2, "<FONT>\n");
		fprintf(fichier_2, "\t\t\t\t\t\t<B>\n");
		fprintf(fichier_2, "\t\t\t\t\t\t\t%d\n", eleves[i].numero);
		fprintf(fichier_2, "\t\t\t\t\t\t</B>\n\t\t\t\t\t");
		fprintf(fichier_2, "</FONT>\n\t\t\t\t</TD>\n");
		
		fprintf(fichier_2, "\t\t\t\t<TD>\n\t\t\t\t\t");
		fprintf(fichier_2, "<FONT>\n");
		fprintf(fichier_2, "\t\t\t\t\t\t<B>\n");
		fprintf(fichier_2, "\t\t\t\t\t\t\t%s\n", eleves[i].nom_et_prenom);
		fprintf(fichier_2, "\t\t\t\t\t\t</B>\n\t\t\t\t\t");
		fprintf(fichier_2, "</FONT>\n\t\t\t\t</TD>\n");
		fprintf(fichier_2, "\t\t\t</TR>\n\t\t\t<TR>\n");
	
	i++;
	}
	fprintf(fichier_2, "\t\t\t</TR>\n\t\t</TABLE>\n\t</BODY>\n</HTML>");
	fclose(fichier_1);
	fclose(fichier_2);
}