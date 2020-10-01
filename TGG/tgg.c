#include "tgg.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//this is the first usage of the x macros...
//these actually create the definitions of the structures
#include "xm_struct_definers.h"
#include "xm_structs.h"
#include "xm_clear_macros.h"
//------------------------------

//this is the second usage of the x macros...
//which creates 3 functions that print out the contents of each type of structure
#include "xm_struct_printers.h"
#include "xm_structs.h"
#include "xm_clear_macros.h"
//------------------------------

int tw, th;
int* tw0, th0;


float version=0.05;
char playername[16];
int plselect=0;
int plname = 0;
int dump;


struct SMALL_RECT {
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
};

int main()
{
    dterm(&tw, &th);    // détecte la taille de l'écran (terminal)
    printf("%d and %d", tw, th);
    if (tw != 200 || th != 200)
    {
     printf ("terminal doesnt have the right size, resizing...");
        SMALL_RECT windowSize = {0 ,0 ,57 ,107};
        HANDLE hStdout;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        cls(hStdout);
    }

    mainmenu:
    printf("current resolution: %dx%d\t\tTHE GREATEST GAME ver %.2f\n",tw,th,version);
    printf("\t\t\t\t\t    CHOOSE AN OPTION");
    putchar('\n');
    putchar('\n');
    putchar('\n');
    printf("\t\t\t\t\t 1-Continue my adventure\n");
    putchar('\n');
    printf("\t\t\t\t\t 2-Begin a new adventure\n");
    putchar('\n');
    printf("\t\t\t\t\t 3-Options(not working) \n");
    putchar('\n');
    puts("Enter your selection : ");
    scanf("%d%*c",&plselect);

    switch(plselect)
    {
        case 1:
        namesc(dump);


        break;

        case 2:
        ZAWARUDOinit('n');
        break;

        case 3:
        puts("I TOLD YOU, ITS NOT READY YOU DONKEY");
        break;

        default:
        goto mainmenu;
    }



    return(0);
}
