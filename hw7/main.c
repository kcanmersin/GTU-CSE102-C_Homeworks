#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
void print_map(char map[][15]);
void fill_space(char map[][15]);
void ower_write_x(int x,int y, int len, int direction , char map[][15]);
int control_board(int x,int y, char word[],char map[][15],int len);
int play_game(void(crate_map)(char map[][15]));
void crate_map(char map[][15]);
int write(char *word,int direction,int len,char map[][15],int x, int y);
char words_from_file[7][6];
enum Direction{left_to_right,top_left_to_bottom_right,up_to_down,top_right_to_bottom_left,right_to_left,bottom_right_to_top_left,down_to_up,bottom_left_to_top_right};
int main()
{
    int control=1;
    srand(time(NULL));
    printf("**** Welcome to the WORD PUZZLE ****\n* First write  the initial position of the word you found, then the word itself\n* Press\":q\" before enter coordinates for exit\n\nGame Starting...\n\n\n");
    do {
        control=play_game(crate_map);
    } while(control==1);

}

int play_game(void(crate_map)(char map[][15]))
{
    char map[15][15];
    //this function crate map
    (crate_map)(map);

    int x,y,try=3;
    int point=0;
    char player_word[5];
    //check is a special variable.It assing as a direction if word user write founded in board, if word did not found check is -1, if wrong input came in check is -2
    int len,check=-2;
    do
    {
        printf("Enter coordinates and word: ");
        //takes input from user
        if(scanf("%d %d %s",&x,&y,player_word)==3)
        {
            if(x>14 || y>14 || y<0 || x<0)
            {
                check=-2;
                printf("\nBe careful!. Board is only 15x15!! Please write values only  0-14 and between\n");
            }else
            {
                len=strlen(player_word);
                //if the word is found as a result of the entered values, the check assing to direction of word,if it did not found check is -1
                check=control_board(x,y,player_word,map,len);
            }
        } else
        {
            scanf("%s",player_word);
            if(strcmp(player_word,":q")==0)
            {
                printf("You choose exit. Game over. Have a nice day!\n"); 
                printf("Your total points %d\n",point);
                return 0;

            } else
            {
                printf("You entered wrong input!! Please be careful!!\n");
                //if wrong input came in check is -2
                check=-2;
                while(getchar()!='\n');
            }
        }
        //this if control the word is from file
        if(check>=0)
        {
            int control=0;
            for(int a=0;a<=7;a++)
            {
                if(strcmp(player_word,words_from_file[a])==0)
                {
                    control=1;
                }
            }
            if(control==0)
            {
                printf("The entered word was not found in the file\n");
                check=-1;
            }
        }
        if(check>=0)
        {
            point+=2;
            printf("Founded You got 2 points. Your total points : %d\n",point);

            ower_write_x(x,y,len,check,map);
            for(int a=0; a<15; a++)
            {
                for(int b=0; b<15; b++)
                {
                    printf("%c ",map[a][b]);
                }
                printf("\n");
            }
        } else if(check==-1)
        {
            try--;
            if(try==0)
            {
                printf("You lost your all chances!\n");
            }else
            {
                printf("Wrong choice! You have only %d lefts\n",try);
            }
            
        }
    } while(try>0 && point<14);
    if(try==0)
        {
            printf("\n You lose the game!!");
        }
    else if(point==14)
    {
        printf("\n Congratulations you won the game!!\n");
    }
}
//after user found a word, this function write x on it
void ower_write_x(int x,int y, int len, int direction , char map[][15])
{
    if(direction==left_to_right)
    {
        for(int j=0; j<len; j++)
            map[y][x+j]='X';
    } else if(direction==top_left_to_bottom_right)
    {
        for(int j=0; j<len; j++)
            map[y+j][x+j]='X';
    } else if(direction==up_to_down)
    {
        for(int j=0; j<len; j++)
            map[y+j][x]='X';
    } else if(direction==top_right_to_bottom_left)
    {
        for(int j=0; j<len; j++)
            map[y+j][x-j]='X';
    } else if(direction==right_to_left)
    {
        for(int j=0; j<len; j++)
            map[y][x-j]='X';
    } else if(direction==bottom_right_to_top_left)
    {
        for(int j=0; j<len; j++)
            map[y-j][x-j]='X';
    } else if(direction==down_to_up)
    {
        for(int j=0; j<len; j++)
            map[y-j][x]='X';
    } else if(direction==bottom_left_to_top_right)
    {
        for(int j=0; j<len; j++)
            map[y-j][x+j]='X';
    }
}
//this function crate map
void crate_map(char map[][15])
{
    for(int a=0; a<15; a++)
    {
        for(int b=0; b<15; b++)
        {
            map[a][b]='-';
        }
    }
    //select 7 word index//
    int selected_words[7];
    int counter=0;
    int random;
    int control=1;
    //this part is in order for there to be no repetition in the array
    do
    {
        control=1;
        random=rand()%50+1;
        for(int a=0; a<7; a++)
        {
            if(random==selected_words[a])
            {
                control=0;
                break;
            }
        }
        if(control!=0)
        {
            selected_words[counter]=random;
            counter++;
        }
    } while(counter<7);
    //sort them
    int temp;
    for(int j = 0; j < 6; j++) {
        for(int l = 0; l < 6 - j ; l++) {
            if(selected_words[l] > selected_words[l+1] ) {
                temp = selected_words[l];
                selected_words[l] = selected_words[l+1];
                selected_words[l+1]= temp;
            }
        }
    }
    //select words from file
    FILE *fp=fopen("wordlist.txt","r");
    char word[50];
    int direction,x,y;
    int is_wrote=0;
    int len=0;
    printf("\n");
    counter=0;
    while(fscanf(fp,"%s",word)==1)
    {
        for(int a=0;a<7;a++)
        {
            if(counter==selected_words[a])
            {
                strcpy(&words_from_file[a][0],word);
                len=strlen(word);
                do
                {
                    //randomize words position and direction
                    x=rand()%15;
                    y=rand()%15;
                    direction=rand()%8;
                    //placed word to the board until it fit flawless
                    is_wrote=write(&word[0],direction,len,map,x,y);
                } while(is_wrote==0);
                    printf("%d %d %s %d\n",x,y,words_from_file[a],direction);
                break;
            }
        }
        counter++;
    }
    fclose(fp);
    //fill empty spaces
    fill_space(map);
    print_map(map);
}

void print_map(char map[][15])
{
    for(int a=0; a<15; a++)
    {
        for(int b=0; b<15; b++)
        {
            printf("%c ",map[a][b]);
        }
        printf("\n");
    }
}
//controls whether the word entered by the user is in the position entered by the user
//if word found returns direction of word
int control_board(int x,int y, char word[],char map[][15],int len)
{
    int control;
    for(int direction=0; direction<=7; direction++)
    {
        
     control=1;
        switch (direction)
        {
        case left_to_right:
            if(x+len<=14)
            {

                for(int j=0; j<len; j++)
                {
                    if(map[y][x+j]!=word[j])
                    {
                        control=0;
                        break;
                    }
                }
                if(control==1)
                {
                    return direction;
                }
            }
            break;
        case top_left_to_bottom_right:
            if(x+len<=14 || y+len<=14)
            {

                for(int j=0; j<len; j++)
                    if(map[y+j][x+j]!=word[j])
                    {
                        control=0;
                        break;
                    }
                if(control==1)
                {
                    return direction;
                }
            }
            break;
        case up_to_down:
            if( y+len<=14)
            {

                for(int j=0; j<len; j++)
                {
                    if(   map[y+j][x]!=word[j])
                    {   control=0;
                        break;
                    }

                }

                if(control==1)
                {
                    return direction;
                }
            }
            break;
        case top_right_to_bottom_left:
            if( y+len<=14 || x+len>=14)
            {

                for(int j=0; j<len; j++)
                    if(   map[y+j][x-j]!=word[j])
                    {   control=0;
                        break;
                    }
                if(control==1)
                {
                    return direction;
                }
            }
            break;
        case right_to_left:
            if(  x-len>=0)
            {

                for(int j=0; j<len; j++)
                    if(   map[y][x-j]!=word[j])
                    {
                        control=0;
                        break;
                    }
                if(control==1)
                {
                    return direction;
                }
            }
            break;
        case bottom_right_to_top_left:
            if(x-len>=0 || y-len>=0)
            {

                for(int j=0; j<len; j++)
                    if(   map[y-j][x-j]!=word[j])
                    {
                        control=0;
                        break;
                    }
                if(control==1)
                {
                    return direction;
                }
            }
            break;
        case down_to_up:
            if( y-len>=0)
            {
                for(int j=0; j<len; j++)
                    if(   map[y-j][x]!=word[j])
                    {
                        control=0;
                        break;
                    }
                if(control==1)
                {
                    return direction;
                }
            }
            break;
        case bottom_left_to_top_right:
            if( y-len>=0 || x+len<=14)
            {

                for(int j=0; j<len; j++)
                    if(   map[y-j][x+j]!=word[j])
                    {
                        control=0;
                        break;
                    }
                if(control==1)
                {
                    return direction;
                }
            }
            break;
        }
    }
    return -1;
}
//fill empty spaces with random letters
void fill_space(char map[][15])
{
    int random;
    char letter;
    for(int a=0; a<15; a++)
    {
        for(int b=0; b<15; b++)
        {
            random=rand()%26;
            letter='a'+random;
            if(map[a][b]=='-')
                map[a][b]=letter;
        }
    }
}
//randomly places the 7 selected words from the file. if word properly placed return 1
int write(char *word,int direction,int len,char map[][15],int x, int y)
{
    if(direction==left_to_right)
    {
        if(x+len>14)
            return 0;
        for(int j=0; j<len; j++)
            if( map[y][x+j]!='-')
                return 0;
        for(int j=0; j<len; j++)
            map[y][x+j]=word[j];
    } else if(direction==top_left_to_bottom_right)
    {
        if(x+len>14 || y+len>14)
            return 0;
        for(int j=0; j<len; j++)
            if( map[y+j][x+j]!='-')
                return 0;
        for(int j=0; j<len; j++)
            map[y+j][x+j]=word[j];
    } else if(direction==up_to_down)
    {
        if( y+len>14)
            return 0;
        for(int j=0; j<len; j++)
            if( map[y+j][x]!='-')
                return 0;
        for(int j=0; j<len; j++)
            map[y+j][x]=word[j];
    } else if(direction==top_right_to_bottom_left)
    {
        if( y+len>14 || x+len<14)
            return 0;
        for(int j=0; j<len; j++)
            if( map[y+j][x-j]!='-')
                return 0;
        for(int j=0; j<len; j++)
            map[y+j][x-j]=word[j];
    } else if(direction==right_to_left)
    {
        if(  x-len<0)
            return 0;
        for(int j=0; j<len; j++)
            if( map[y][x-j]!='-')
                return 0;
        for(int j=0; j<len; j++)
            map[y][x-j]=word[j];
    } else if(direction==bottom_right_to_top_left)
    {
        if(x-len<0 || y-len<0)
            return 0;
        for(int j=0; j<len; j++)
            if( map[y-j][x-j]!='-')
                return 0;
        for(int j=0; j<len; j++)
            map[y-j][x-j]=word[j];
    } else if(direction==down_to_up)
    {
        if( y-len<0)
            return 0;
        for(int j=0; j<len; j++)
            if( map[y-j][x]!='-')
                return 0;
        for(int j=0; j<len; j++)
            map[y-j][x]=word[j];
    } else if(direction==bottom_left_to_top_right)
    {
        if( y-len<0 || x+len>14)
            return 0;
        for(int j=0; j<len; j++)
            if( map[y-j][x+j]!='-')
                return 0;
        for(int j=0; j<len; j++)
            map[y-j][x+j]=word[j];
    }
    return 1;
}