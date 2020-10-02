#include "tgg.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
static float version=0.09;
char playername[16];
int plselect=0;
int plname = 0;
int dump;



int main()
{


    mainmenu:
    PlaySound(TEXT("./music/menu.wav"), NULL, SND_FILENAME |     SND_LOOP | SND_ASYNC);

    printf("\t\t\t\t\t      TGG ver %.2f\n",version);
        std::cout << R"(
                                                       ______      ______
                                             _______  |  ____|    |  ____|
                                            |_______| | |  __     | |  __
                                 />____________| |____| |_|_ |____| |_|_ |____
                        [########[]____________| |____| |__| |____| |__| |____>
                                 \>            |_|    |______|    |______|

)" << '\n';
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
        system("cls");
        std::cout <<"do nothing";



        break;

        case 2:
        characterdatatest();
        break;

        case 3:
        puts("I TOLD YOU, ITS NOT READY YOU DONKEY");
        break;

        default:
        goto mainmenu;
    }



    return(0);
}
