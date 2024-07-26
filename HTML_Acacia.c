#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct eleve
{
	int numero;
	char nom_et_prenom[100];
};

void titrePage(FILE* fichier);
void enteteTab(FILE* fichier);
void prepaBackup(FILE* f, FILE* f2, char* txt);
int studentCount(char* txt);
void saveStudents(FILE* f, char* txt, struct eleve *eleves, int nb_eleve);
void creationPage(FILE* f, FILE* f2, struct eleve *eleves, int nb_eleve);
char* allocation();

int main()
{
	FILE* fichier_1 = NULL;
	FILE* fichier_2 = NULL;
	char* txt = NULL;
	struct eleve eleves[100];
	int nb_eleve;
	txt = allocation();
	titrePage(fichier_1);
	enteteTab(fichier_1);
	prepaBackup(fichier_1, fichier_2, txt);
	nb_eleve = studentCount(txt);
	saveStudents(fichier_1, txt, eleves, nb_eleve);
	creationPage(fichier_1, fichier_2, eleves, nb_eleve);
	return (0);
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
