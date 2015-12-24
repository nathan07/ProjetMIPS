#include "traduction.h"

void trad(char tab[]) {
	int i = 0;
	char tabBinaire[32];
	char instruction[32];
	char* operande;
	char* operande1;
	char* operande2;
	char* operande3;
	char* operande1Binaire = malloc(5*sizeof(char));
	char* operande2Binaire = malloc(5*sizeof(char));
	char* operande3Binaire = malloc(5*sizeof(char));

	/* recherche instruction*/
	while(tab[i] != 32) {
		instruction[i] = tab[i];
		i++;
	}
	i++;

	/* recherche operandes*/
	operande = strtok(&tab[i], ", ");
	operande1 = operande;
	printf("op1 %s\n",operande1);
	if(operande != NULL) {
		operande2 = strtok(NULL, ", ");
	}
	printf("op2 %s\n",operande2);

	if(operande != NULL) {
		operande3 = strtok(NULL, ", ");
	}
    printf("op3 %s\n",operande3);

	/*on met en place une chaine contenant l'instruction en binaire, et on concatene les operandes*/
	if(strcmp(instruction, "ADD")) {
		strcpy(tabBinaire, "00000100000");
        /*on traduit operande1 et on la concatene*/
        tradOpEnBin(operande1, operande1Binaire);
        tradOpEnBin(operande3, operande3Binaire);
        tradOpEnBin(operande2, operande2Binaire);
        printf("op1bin %s\n",operande1Binaire);

        concatenerAuDebut(tabBinaire, operande1Binaire);
        strcpy(tabBinaire, operande1Binaire);
        concatenerAuDebut(tabBinaire, operande3Binaire);
        strcpy(tabBinaire, operande3Binaire);
        concatenerAuDebut(tabBinaire, operande2Binaire);
        strcpy(tabBinaire, operande2Binaire);
        printf("tabbin %s\n",tabBinaire);
        free(operande1Binaire);


        /*on traduit operande3 et on la concatene*/


        free(operande3Binaire);

        /*on traduit operande2 et on la concatene*/


        /*free(operande2Binaire);*/
	}
	printf("tabbinaire: %s\n", tabBinaire);


}

/*convertit l'operande en binaire*/
void tradOpEnBin(char* tab, char* tabOpEnBin) {
	int resultat = 0;
	if(strlen(tab) == 2) {
		resultat = atoi(&tab[1]);
		itoa(resultat,tabOpEnBin,2);
		if(strlen(tabOpEnBin) < 5) {
            int i = 0;
            char zeros[5] = "";
            while(i != 5-strlen(tabOpEnBin)) {
                strcat(zeros,"0");
                i++;
            }
            concatenerAuDebut(tabOpEnBin, zeros);
		}
	}
	else if(strlen(tab) == 3) {
        resultat = atoi(&tab[1]);
        itoa(resultat,tabOpEnBin,2);
	}
}

/*char* convertirDecEnHexa(char tab[]) {
	if(tab == 10)
		return "A";
	if(tab == 11)
		return "B";
	if(tab == 12)
		return "C";
	if(tab == 13)
		return "D";
	if(tab == 14)
		return "E";
	if(tab == 15)
		return "F";
}*/

/*permet de concatener une chaine au debut d'une autre (contraire de strcat)*/
void concatenerAuDebut(char* dest, char* src) {
    /*char* tmp = malloc(256*sizeof(char));*/
    printf("valeur resultatdebut: %d\n",*dest);
    char* tmp = NULL;
    tmp = dest;
    dest = src;
    dest = strcat(dest, tmp);
    printf("valeur resultatfin: %d\n",*dest);
    /*dest = res;*/
    /*free(tmp);*/
}
