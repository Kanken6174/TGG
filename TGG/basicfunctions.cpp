#include <iostream>
#include "tgg.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <fstream>
#include "dirent.h"
#ifndef WIN32
    #include <sys/types.h>
#endif

#define MAXC 150
#define true 1

#define false 0

#include <stdio.h>

#define MAX_WORD   21986
#define NUM_WORDS  3
using namespace std;





// En-dessous, c'est des lignes de code quasi-inutiles pour contr�ler le terminal.
void dterm(int*tw0, int*th0)
{

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    *tw0=columns;
    *th0=rows;
}

//On arrive au code utile

int namesc(char* plname)
{

    printf("\t\t\t      Welcome player, please enter your name (15 max)");
    putchar('\n');
    printf("\t\t\t\t\t");
    fgets(plname,15,stdin);
    return(0);

}

void characterdatatest()
{


    char firstname[10];
    char familyname[10];
    char title[25];
    int level;
    int ID;
    int relation;

    int health;
    int basehealth;
    int mana;
    int basemana;
    int stamina;
    int basestamina;

    int strenght;
    int intelligence;
    int agility;
    int wisdom;
    int speech;

    int race;
    int blessing;
    int job;

    bool dead;
    bool poisonned;
    bool sleeping;
    bool male;
    bool ennemy;
    bool follower;

    ofstream file;
    file.open ("filePath.txt");
    file << firstname, familyname, title, level, ID, relation, health, basehealth, mana, basemana, stamina, basestamina,
    file.close();

/*
FILE* output;
system("MD DATASHEETS\\CHARACTER_DATASHEETS");
DIR* dir = opendir("./DATASHEETS/CHARACTER_DATASHEETS");
if (dir)
{

        output = fopen("./DATASHEETS/CHARACTER_DATASHEETS/last.dat", "ra");
            fwrite(&data, sizeof(data), 1, output);

    if (output == NULL) {
        perror("Failed: ");

    }


    closedir(dir);
}
    if(errno == ENOTDIR)
{
    puts("Kanken : Wow... je sais pas trop ce qu'il s'est pass�, j'ai essay� d'avoir acces a un dossier mais a la place j'ai eu un fichier... �-�");
}


fclose(output);
}*/

void ZAWARUDOinit(char poulet)
{
    int maxseed=100;
    char answer='n';
    if (poulet == 'n')
    {
        char paths[150]="none";
        char buf[155];
        GetCurrentDirectory(MAX_PATH,paths);

        printf("le PATH est: %s \n", paths);
        snprintf(buf, sizeof(buf), "CD %s",paths);
        printf("%s\n", buf);
        system(buf);
        system("MD DATASHEETS\\CHARACTER_DATASHEETS");

        puts("Veuillez choisir un nombre d'arret pour la creation de personnages (100-99999) [obviously 99K prendra des plombes et sera hyper lent]");
        scanf("%d%*c", &maxseed);
        printf("Seed d'arret choisie: %d, est-ce correct? (y/n)", maxseed);
        scanf("%c%*c", &answer);


        puts("Debut de l'initialisation du monde...");
        int x=1;

        }

        }



void pick (char type, char* adress)
{
    if (type == 'n')
    {
        /* Open words file */
    FILE *fp = fopen("names.RAND", "r");

    if (fp == NULL) {
        perror("Unable to locate word list");
        exit(EXIT_FAILURE);
    }

    /* Count words in file */
    char word[MAX_WORD];
    long wc = 0;
    while (fgets(word, sizeof word, fp) != NULL) {
        ++wc;
    }

    /* Store random words in array */
    char randwords[NUM_WORDS][MAX_WORD];
    srand((unsigned) time(NULL));

    for (size_t i = 0; i < NUM_WORDS; i++) {
        rewind(fp);
        int sel = rand() % wc + 1;

        for (int j = 0; j < sel; j++) {
            if (fgets(word, sizeof word, fp) == NULL) {
                perror("Error in fgets()");
            }
        }
        for(i=0; i < 15; i++)
        *adress=word[i];
    //    strcpy(randwords[i], word);
    }

    if (fclose(fp) != 0) {
        perror("Unable to close file");
    }

    /* Display results */

    }



    }





















