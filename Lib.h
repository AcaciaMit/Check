typedef enum utilisateur
{
	OUI,NON,PERSO,ABS

}User;
typedef struct machine
{
	char nom[100];
	char prenom[100];
	int numero; 

}MachineEtudidant;


struct eleve
{
	int numero;
	char nom_et_prenom[100];
};



char* allocation();
int* allocationTab(int dernier_numero);
int studentCount(char* txt);
void toLower(char *str);
int search(char *fichier);
int saisiNum(int numMax);
void name_number(char *fichier);
void presence(char* fichier, char* txt, int numero);
int Avis(char *option);
void check(char* fichier, char* txt, int numero, char* option);
void titrePage(FILE* fichier);
void enteteTab(FILE* fichier);
void prepaBackup(FILE* f, FILE* f2, char* txt);
int studentCount(char* txt);
void saveStudents(FILE* f, char* txt, struct eleve *eleves, int nb_eleve);
void creationPage(FILE* f, FILE* f2, struct eleve *eleves, int nb_eleve);