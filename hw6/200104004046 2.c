#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int player_move(int player,int (roll_dice)(int player));
void printMap (int x, int y, char map[x][y]);
int dice(int player);
int startGame();
char map[15][30];
//location of players
int xp1=1,yp1=1,track1=1;
int xp2=3,yp2=3,track2=1;

int main()
{
    srand(time(NULL));
    int lines=15,col=30;
    ///////////////this block crate map//////////////////
    for(int a=0; a<lines; a++)
    {
        for(int b=0; b<col; b++)
        {
            if((a==0 || a==14)||((a==2 || a==12) && (b>1 && b<28)) || ((a==4 || a==10) && (b>3 && b<26)) )
            {
                map[a][b]='-';
            } else if(((b==0 || b==29) && a!=0 && a!=14)||((b==2 || b==27) && a<12 && a>2)||((b==4 || b==25) && a<10 && a>4))
            {
                map[a][b]=':';
            } else
            {
                map[a][b]=' ';
            }
        }
    }
    map[1][1]='1';
    map[2][1]='_';
    map[3][3]='2';
    map[4][3]='_';
    map[1][14]='X';
    map[7][28]='X';
    map[13][14]='X';
    map[3][10]='X';
    map[3][18]='X';
    map[5][26]='X';
    map[10][26]='X';
    map[11][10]='X';
    map[11][18]='X';
//////////////////////////////////////////////////////////

    printMap (lines,col, map);
    int move;
    int first_player,second_player;
    printf("To start to game, players should dice and decide who is going to start first_player according to it\n");
    int who_start=startGame();
//this block select who start first
    if(who_start==1)
    {

        printf("\033[0;33m");
        printf(" *** Player 1 will start the game... ***");
        printf("\033[0m");
        first_player=1;
        second_player=2;
    } else
    {
        printf("\033[0;34m");
        printf(" *** Player 2 will start the game... ***");
        printf("\033[0m");
        first_player=2;
        second_player=1;
    }
    //this is the part where the game is played. if a player wins the game, the game is over
    do
    {
        move=player_move(first_player,dice);
        if(move!=0)
        {
            move=player_move(second_player,dice);
        }
        printMap (lines,col, map);
    } while (move!=0);
}
//the progress of the players is made in this block
//track variable is for determine player which sides of the race track
int player_move(int player,int (roll_dice)(int player))
{
    int dice;
    dice=(roll_dice)(player);
    if(player==1)
    {   map[yp1][xp1]=' ';
        if(track1==1)
        {
            if(xp1+dice<=28)
            {
                xp1=xp1+dice;
            } else
            {
                dice=dice-(28-xp1);
                yp1=yp1+dice;
                track1=2;
                xp1=28;
            }
        } else if(track1==2)
        {

            if(yp1+dice<=13)
            {
                yp1= yp1+dice;
            } else
            {
                dice=dice-(13-yp1);
                track1=3;
                xp1=xp1-dice;
                yp1=13;
            }
        } else if(track1==3)
        {

            if(xp1-dice>=1)
            {
                xp1= xp1-dice;
            } else
            {
                dice=dice-(xp1-1);
                track1=4;
                yp1=yp1-dice;
                xp1=1;
            }
        } else if(track1==4)
        {

            if(yp1-dice>1)
            {
                yp1= yp1-dice;
            } else
            {

                dice=dice-(yp1-1);
                yp1=1;
                xp1=xp1+dice;
                map[yp1][xp1]='1';

                printf("\033[0;33m");
                printf("\nPlayer 1 won!\n");
                printf("\033[0m");
                map[2][1]='_';
                return 0;

            }
        }

        if(map[yp1][xp1]=='X')
        {
            printf("\033[0;33m");
            printf("\nPlayer 1 Penalty!\n");
            printf("\033[0m");
            if(yp1==1)
            {
                xp1-=2;
            } else if(xp1==28)
            {
                yp1-=2;
            } else if(yp1==13)
            {
                xp1+=2;
            }
        }
        map[yp1][xp1]='1';
    } else if(player==2)
    {
        map[yp2][xp2]=' ';
        if(track2==1)
        {
            if(xp2+dice<=26)
            {
                xp2=xp2+dice;
            } else
            {
                dice=dice-(26-xp2);
                track2=2;
                yp2=yp2+dice;
                xp2=26;
            }
        } else if(track2==2)
        {

            if(yp2+dice<=11)
            {
                yp2= yp2+dice;
            } else
            {
                dice=dice-(11-yp2);
                track2=3;
                xp2=xp2-dice;
                yp2=11;
            }
        } else if(track2==3)
        {

            if(xp2-dice>=3)
            {
                xp2= xp2-dice;
            } else
            {
                dice=dice-(xp2-3);
                track2=4;
                yp2=yp2-dice;
                xp2=3;
            }
        } else if(track2==4)
        {

            if(yp2-dice>3)
            {
                yp2= yp2-dice;
            } else
            {
                dice=dice-(yp2-3);
                yp2=3;
                xp2=xp2+dice;
                map[yp2][xp2]='2';
                printf("\033[0;34m");
                printf("\nPlayer 2 won!\n");
                printf("\033[0m");
                map[4][3]='_';
                return 0;

            }
        }

        if(map[yp2][xp2]== 'X')
        {
            printf("\033[0;34m");
            printf("\nPlayer 2 Penalty!\n");
            printf("\033[0m");
            if(yp2==3)
            {
                xp2-=2;
            } else if(xp2==26 )
            {
                yp2-=2;
            } else if(yp2==11)
            {
                xp2+=2;
            }
        }
        map[yp2][xp2]='2';
    }
}
int dice(int player)
{
    int start;
    char play;
    if(player==1)
    {
        printf("\033[0;33m");
    } else
    {
        printf("\033[0;34m");
    }
    printf("\nPLAYER %d... press Enter to dice\n",player);
    do play = getchar();
    while ((play != EOF) && (play != '\n'));
    int dice=rand()%6+1;
    printf("DICE: %d\n",dice);
    printf("\033[0m");


    return dice;
}
//this block decide who start first
int startGame()
{

    int stop=0;
    int dice1,dice2;
    do
    {
        dice1=dice(1);
        dice2=dice(2);
        if(dice1==dice2)
        {
            printf("Same dice value...Please try again!");
        } else
        {
            if(dice1>dice2)
            {
                return 1;
            } else
            {
                return 2;
            }
        }
    } while (stop==0);
}
//this block print map
void printMap (int x, int y, char map[x][y])
{
    for(int a=0; a<15; a++)
    {
        for(int b=0; b<30; b++)
        {
            if(map[a][b]=='1')
            {
                printf("\033[0;33m");
            } else if(map[a][b]=='2')
            {
                printf("\033[0;34m");
            } else if(map[a][b]=='X')
            {
                printf("\033[0;31m");

            } else if(map[a][b]=='_')
            {
                printf("\033[0;32m");
            }
            printf("%c",map[a][b]);
            printf("\033[0m");
        }
        printf("\n");
    }
}