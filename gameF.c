#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
//#include <ncurses.h>
#include <unistd.h>

//size of matrix N*N
#define N 9     //sudoku--
#define K 40
#define MAX_LEN 200
int SRN, n, pos, value;
int arr[N][N], solved[N][N], validij[40]; //--sudoku


//TIC_TAC_TOE - call function is at line 272
int k, end=1,count=0;
char a[9]={'1','2','3','4','5','6','7','8','9'};
void draw()
{   system("cls");
    printf("\n\n \t \t \t \t \t \t  ***TICTACTOE GAME***  ");
    printf("\n\n");
        printf("\n \t \t \t \t \t \t ____________");

    printf("\n \t \t \t \t \t \t |%c | %c | %c |",a[0],a[1],a[2]);
    printf("\n \t \t \t \t \t \t |--|---|---|");
    printf("\n \t \t \t \t \t \t |%c | %c | %c |",a[3],a[4],a[5]);
    printf("\n \t \t \t \t \t \t |--|---|---|");
    printf("\n \t \t \t \t \t \t |%c | %c | %c |",a[6],a[7],a[8]);
    printf("\n \t \t \t \t \t \t |__|___|___|");





}
void goodbye()
{
printf("\n\n \t\t\t #GOODBYE!! HAVE A NICE DAY!");
}


void getInput()
{
    char ch;


    if(k==1)
    {
    printf("\n \t\t\t Player 1's turn: ");
    printf("\n \t\t\t Enter the position: ");
    scanf(" %c",&ch);
    count++;
    for (int i = 0; i <= 8; i++)
    {
        if (a[i]==ch)
        {
            a[i]='x';
            k=2;
        }

    }
    }
    else
    {   printf("\n \t\t\t Player 2's turn: ");
    printf("\n \t\t\t Enter the position: ");
    scanf(" %c",&ch);
    count++;
       for (int i = 0; i <= 8; i++)
    {
        if (a[i]==ch)
        {
            a[i]='O';
            k=1;
        }

    }
    }


}
int gameOver()
{
    if (a[0]=='x' && a[1]=='x' && a[2]=='x')
        return(1);
    else if (a[3]=='x' && a[4]=='x' && a[5]=='x')
        return(1);
    else if (a[6]=='x' && a[7]=='x' && a[8]=='x')
        return(1);
    else if (a[0]=='x' && a[4]=='x' && a[8]=='x')
        return(1);
    else if (a[2]=='x' && a[4]=='x' && a[6]=='x')
        return(1);
    else if (a[0]=='x' && a[3]=='x' && a[6]=='x')
        return(1);
    else if (a[2]=='x' && a[5]=='x' && a[8]=='x')
        return(1);
    else if(a[0]=='O' && a[1]=='O' && a[2]=='O')
        return(2);
    else if (a[3]=='O' && a[4]=='O' && a[5]=='O')
        return(2);
    else if (a[6]=='O' && a[7]=='O' && a[8]=='O')
        return(2);
    else if (a[0]=='O' && a[4]=='O' && a[8]=='O')
        return(2);
    else if (a[2]=='O' && a[4]=='O' && a[6]=='O')
        return(2);
    else if (a[0]=='O' && a[3]=='O' && a[6]=='O')
        return(2);
    else if (a[2]=='O' && a[5]=='O' && a[8]=='O')
        return(2);
    else
    return(3);
}
void final()
{
    int w;
    w=gameOver();
    if (w==1)
    {
    printf("\n\n \t \t \t \t \t \t Player 1 won the game!!");
    end=0;
    }
   else if (w==2)
   {
    printf("\n\n \t \t \t \t \t \t Player 2 won the game!!");
    end=0;
   }
    else
      if(end==1)
        {
            if(count==9)
            {
            printf("\n\n \tt\t\t\t\t\tThe game was draw!!\n");
            end=0;
            }


        }
}

//Hangman
void hangman()
{
    FILE *fp;
char s2[50],b[50];
char s1[50];
char d='_';
char ch='a',next='a';
char alpha,c;
int i=0,count=0,test=0,j,length,ans=0;
while(1)
{
count=0;
ans=0;
i=0;
test=0;
printf("\n \n \t \t \t \t \t \t ********WELCOME TO HANGMAN********");
printf("\n\n \t\t #PRESS 's' TO START THE GAME#");
ch=getche();
if(ch=='s' || ch=='S')
{
printf("\n \t \t \t \t \t \t ***** HANGMAN *****");
printf("\n \t \t \t \t \t \t ...................");
printf("\n\n \t\t#PRESS 'p' IF YOU WANT TO PLAY AND PRESS 'g' IF YOU WANT TO GIVE WORDS TO YOUR FRIEND# ");
scanf(" %c",&next);
if(next=='p' || next=='P')
{
 fp=fopen("words.txt","r");
while(1)
{
    c=fgetc(fp);
    if(c==EOF)
    {
        s1[i]='\0';
        break;
    }
    else
    {
        s1[i]=c;
        i++;
    }

}
fclose(fp);
strcpy(s2,s1);
}
else if(next=='g' || next=='G')
{
printf("\n \t\tEnter a word that you want you friend to guess:\n \n");
scanf("%s",s2);
strcpy(s1,s2);
}
else
{
    printf("\n \t\t PlEASE!! ENTER THE CHARACTER REQUESTED ABOVE");
    break;
}
}
else
{
    printf("\n \t\t PLEASE! Enter s to start the game");
    break;
}
length=strlen(s2);
printf("\n \t\tYou will get 6 chances to guess the word \n \n \t \t \t \t \t \t \t");
for(i=0;i<length;i++)
{
printf("%c ",d);
b[i]=d;
}
printf("\n \n \t \t \t \t \t \t *****.............******");
while(count<6)
{
test=0;
printf("\n\n\t\t Enter a character :");
alpha=getche();
for(j=0;j<length;j++)
{
if(alpha==s2[j])
{
test=1;
ans++;
b[j]=s2[j];
s2[j]='*';
}
}
system("cls");
printf("\n \t \t \t \t \t \t ***** HANGMAN *****");
printf("\n \t \t \t \t \t \t ................... \n \n \t \t \t \t \t \t \t");
for(i=0;i<length;i++)
{
printf("%c ",b[i]);
}
printf("\n \n \t \t \t \t \t \t *****.............******");
if(test==1)
{
printf("\n \t\t You are correct %c is a coreect one",alpha);
printf("\n \t\t You have got %d letters to guess",length-ans);
}
else
{
count++;
printf("\n\n \t\t  %c is a wrong letter or you have already given this letter",alpha);
printf("\n \t\t You have only got %d chances left",6-count);
}
if(length==ans)
break;
}
if(length==ans)
printf("\n\n \t \t \t \t \t \t **YOU WON THW GAME**");
else
{
printf("\n\n \t \t \t \t \t \t **SORRY! YOU ARE HANGED BETTER LUCK NEXT TIME**");
printf("\n \t\t\t THE CORRECT WORD IS:");
puts(s1);
}
printf("\n\n \t\t\t If you want to restart the game, PLEASE! Enter character 'r' \n \t\t\t  And if you want to end game,PlEASE! Enter any character :");
ch=getche();
if(ch =='r' || ch =='R')
    system("cls");
else
{
    printf("\n\n \t \t \t \t \t ## THANK YOU FOR PLAYING HANGMAN ##");
    break;
}
}
}
void tictac()
{
  int start;
char check;

    printf("\n\n \t \t \t \t \t \t *** Tictactoe game ****\n");
    label1:
    printf("\n\n\n \t\t\t press 1 to start game.\n \t\t\t press 2 to see how to play.\n \t\t\t press 3 to exit.");
    scanf("%d",&start);
    if(start==2)
    {
        printf("\n \t\t Symbol for player 1 is x and that of player 2 is O.\n \t\t Whichever player got their 3 symbols consecutively either diagonally or side ways wins the match. \n \t\t On other condition the match will end as draw.");
            goto label1;
    }
    else if(start==1)
    {label2:
    printf("\n \t\t Who wants to start first?\n \t\t press 1 for player 1 to start and 2 to player 2 to start: ");
    scanf("%d",&k);
while(end)
{
 draw();
 getInput();
 draw();
 final();
}
printf("\n\n \t\t\t Thank you for playing .");
printf("\n\n \t\t\t Do you want to play again?");
printf("\n \t\t\t If yes press y and to exit press any other key.");
scanf(" %c",&check);
  if(check=='y'||check=='Y')
  {
  a[0]='1';
    a[1]='2';

    a[2]='3';
    a[3]='4';
    a[4]='5';
    a[5]='6';
    a[6]='7';
    a[7]='8';
    a[8]='9';
    end=1;
    count=0;

    goto label2;
  }
else
goodbye();
}
else
goodbye();
}

//Sudoku
int rndm(int);
int menu();
void sudoku()
{
    double SRNd = sqrt(N);
    SRN = (int)SRNd;
}
void print_matrix()
{
    system("cls");
    printf("\t\t\t  1 2 3 4 5 6 7 8 9\n");
    printf("\t\t\t  -----------------\n");
    for (int i = 0; i < N; i++)
    {
        printf("\t\t\t");
        for (int j = 0; j < N; j++)
        {
            if( j == 0)
            {
            	printf("%d|%d ",i+1, arr[i][j]);
            }
            else
            {
            printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\t\tInput syntax:a-position value");
    printf("\n\t\tYou can enter 0 0 to go back to main menu");
}
bool not_in_box(int rowS, int colS, int num) //not_in_box = unUsedInBox
{
    for (int i = 0; i < SRN; i++)
    {
        for (int j = 0; j < SRN; j++)
        {
            if (arr[rowS + i][colS + j] == num)
                return false;
        }
    }
    return true;
}

void fill_box(int row, int col)
{
    int num;
    srand(time(0));
    for (int i = 0; i < SRN; i++)
    {
        for (int j = 0; j < SRN; j++)
        {

            do
            {
                num = rndm(N);
            } while (!not_in_box(row, col, num));
            arr[row + i][col + j] = num;
        }
    }
}
void fill_diagonals()
{
    for (int i = 0; i < N; i = i + SRN)
    {
        fill_box(i, i);
    }
}

int rndm(int num)
{
    return rand() % (num + 1);
}
bool not_in_row(int i, int num)
{
    for (int j = 0; j < N; j++)
        if (arr[i][j] == num)
            return false;
    return true;
}
bool not_in_col(int j, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i][j] == num)
            return false;
    }
    return true;
}
bool check_if_safe(int i, int j, int num)
{
    return (not_in_row(i, num) &&
            not_in_col(j, num) &&
            not_in_box(i - i % SRN, j - j % SRN, num));
}
bool fillRemaining(int i, int j)
{
    if (j >= N && i < N - 1)
    {
        i = i + 1;
        j = 0;
    }
    if (i >= N && j >= N)
        return true;
    if (i < SRN)
    {
        if (j < SRN)
            j = SRN;
    }
    else if (i < N - SRN)
    {
        if (j == (int)(i / SRN) * SRN)
            j = j + SRN;
    }
    else
    {
        if (j == N - SRN)
        {
            i = i + 1;
            j = 0;
            if (i >= N)
                return true;
        }
    }
    for (int num = 1; num <= N; num++)
    {
        if (check_if_safe(i, j, num))
        {
            arr[i][j] = num;
            if (fillRemaining(i, j + 1))
                return true;
            arr[i][j] = 0;
        }
    }
    return false;
}
void solved_grid()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            solved[i][j] = arr[i][j];
    }
}
void print_solved()
{
    printf("\nSolved Matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", solved[i][j]);
        }
        printf("\n");
    }
}
void check_input(int i, int j, int x)
{
    validij[x] = (i + 1) * 10 + (j + 1);
}
void remove_rnd_digits()
{
    int count = K, x = 0;
    do
    {
        int cell_id = rndm(N * N) - 1;
        int i = (cell_id / N);
        int j = cell_id % 9;
        if (j != 0)
            j = j - 1;

        if (arr[i][j] != 0)
        {
            count--;
            arr[i][j] = 0;
            check_input(i, j, x);
            x += 1;
        }

    } while (count != 0);
}
void fill_values()
{
    fill_diagonals(); //randomly fill the diagonals

    fillRemaining(0, SRN); //filling the rest of the boxes

    solved_grid(); //store the solution in a different matrix if the user gives up

    remove_rnd_digits(); //randomly remove digits to generate a sudoku;
}
int invalid(int x)
{
    for (int i = 0; i < 40; i++)
    {
        if (x == validij[i]) //validij is the postion of all 0s
            return 1;
    }
    return 0;
}
int check(int p, int v) //p for pos, v for value
{
    int i = p / 10;
    int j = p % 10;
    int r;
    r = check_if_safe(i - 1, j - 1, v);
    if (v >= 10)
        return 2;
    return r;
}

void update_scr()
{
    int i, j;
    i = pos / 10;
    j = pos % 10;
    if (check(pos, value) == 1) //row, column and box check)
    {
        arr[i - 1][j - 1] = value;
        print_matrix();
    }
    else if (check(pos, value) == 2)
    {
        printf("Go through the game rules again please!");
    }
    else
    {
        printf("Already in row or column or box");
    }
}
void print_text(FILE *fptr)
{
    char read_string[MAX_LEN];

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
}
int how_to_play()
{
    int in;
    system("cls");
    char *filename = "HTP.txt";
    FILE *fptr = NULL;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error printing title! %s\n", filename);
        return 1;
    }

    print_text(fptr);
    fclose(fptr);
    y:
    printf("\nEnter 0 to exit to main menu:");
    scanf("%d", &in);
    switch (in)
    {
    case 0:
        menu();
        break;

    default:
        goto y;
        break;
    }
}
int check_if_solved()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)
                return 0;
        }
    }
    return 1;
}
void user_prompt()
{
    int boolean;

    x:
    printf("\nYour Input:a-");
    scanf("%d%d", &pos, &value);
    if (check_if_solved() == 1)
    {
        printf("Congratulations! You Solved it.\n");
    }
    else
    {
        if (pos == 0 && value == 0)
        {
            menu();
        }
        else
        {
            boolean = invalid(pos);
            switch (boolean)
            {
            case 1:
                update_scr();
                goto x;
                break;
            case 0:
                printf("a%d is permanent\n", pos);
                sleep(1);
                goto x;
                break;

            default:
                printf("Can't understand that input\n");
                sleep(1);
                goto x;
                break;
            }
        }
    }
}
void interface()
{
    char ch;
    int op;
    printf("\t\t\t1.Start a Game\n");
    printf("\t\t\t2.How to Play\n");
    printf("\t\t\t0.Exit\n");
    printf("\t\t\tOption:");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        break;
    case 1:
        print_matrix();
        user_prompt();
        break;
    case 2:
        how_to_play();
        break;

    default:
        printf("That option isn't available");
        break;
    }
}

int menu()
{
    system("cls");
    char *filename = "title.txt";
    FILE *fptr = NULL;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error printing title! %s\n", filename);
        return 1;
    }

    print_text(fptr);
    fclose(fptr);
    interface();

    return 0;
}

void s_game()
{
    system("cls");
    sudoku();
    fill_values();
    //print_solved();
    menu();

    //return 0;
}

//Rock-Paper-Scissor
int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    else if (c1 == 'r' && c2 == 's')
    {
        return 1;
    }
    else if (c2 == 'r' && c1 == 's')
    {
        return 0;
    }
    else if (c1 == 'p' && c2 == 'r')
    {
        return 1;
    }
    else if (c2 == 'p' && c1 == 'r')
    {
        return 0;
    }

    else if (c1 == 's' && c2 == 'p')
    {
        return 1;
    }
    else if (c2 == 's' && c1 == 'p')
    {
        return 0;
    }
}
int paper()
{
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("\t\t\t\tWelcome to the Rock Paper Scissors\n");
    printf("\t\t\t\t----------------------------------\n\n");
    printf("\n\t\t\t\t You will get 3 chances to play and if you score twice you win \n");
    for (int i = 0; i < 3; i++)
    {
        // Take player input
        printf("\t\t\tPress 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n\n");
        printf("\t\t\t\tPlayer's turn: ");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];
        printf("\t\t\t -----------------\n");
        printf("\t\t\t| You choose: %c   |\n", playerChar);
        printf("\t\t\t -----------------\n\n");

        //computer generate
        printf("\t\t\tPress 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n\n");
        printf("\t\t\t\tComputer's turn\n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf("\t\t\t --------------------\n");
        printf("\t\t\t| Computer choose: %c |\n", compChar);
        printf("\t\t\t --------------------\n\n");

        // compater character and increment the score
        if (greater(compChar, playerChar) == 1)
        {
            compScore++;
            printf("\t\t\tComputer Got It!\n\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore++;
            playerScore++;
            printf("\t\t\tIt's a draw. Both got 1 point!\n\n");
        }
        else
        {
            playerScore++;
            printf("\t\t\tYou Got It!\n\n");
        }

        printf("\t\t\t -------------\n");
        printf("\t\t\t| You: %d      |\n", playerScore);
        printf("\t\t\t| Computer: %d |\n", compScore);
        printf("\t\t\t -------------\n\n");

        printf("\t\t\t===========================================================\n\n");
    }

    printf("\t\t\t\t ----------------- \n");
    printf("\t\t\t\t|   Final Score   |\n");
    printf("\t\t\t\t|-----------------|\n");
    printf("\t\t\t\t|  You | Computer |\n");
    printf("\t\t\t\t|------|----------|\n");
    printf("\t\t\t\t|   %d  |     %d    |\n", playerScore, compScore);
    printf("\t\t\t\t ----------------- \n\n");

    // compare score
    if (playerScore > compScore)
    {
        printf("\n\t -------------------\n");
        printf("\t| You Win the match |\n");
        printf("\t -------------------\n");
    }
    else if (playerScore < compScore)
    {
        printf("\n\t ------------------------\n");
        printf("\t| Computer Win the match |\n");
        printf("\t ------------------------\n");
    }
    else
    {
        printf("\n\t -------------\n");
        printf("\t| It's a draw |\n");
        printf("\t -------------\n");
    }

    return 0;
}
int main()
{
int star;
int x;
x = 22;
while(x != 0)
{
system("cls");
    char *filename = "main.txt";
    FILE *fptr = NULL;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error printing title! %s\n", filename);
        return 1;
    }

    print_text(fptr);
    fclose(fptr);
printf("\n\n\n \t\t\t 1.HANGMAN\n \t\t\t 2.TIC TAC TOE \n \t\t\t 3.SUDOKU \n \t\t\t 4.ROCK PAPER SCISSORS\n \t\t\t 0.Exit");
printf("\n\n\t\t\t Choose An Option:");
scanf("%d",&star);
switch(star)
{
    case 1:
    system("cls");
    hangman();
    break;

    case 2:
     system("cls");
     tictac();
     break;

    case 3:
     system("cls");
     s_game();
     break;

    case 4:
     system("cls");
     paper();
     break;

    case 0:
        exit(0);

    default:
        printf("\n\n \t\t *PLEASE CHOOSE AVAILABLE OPTIONS");
        break;




}
printf("\n\n\t\tEnter 0 to exit and 1 to get back to main menu:");
scanf("%d",&x);

}
printf("\n\n \t \t \t \t \t \t **THANK YOU FOR PLAYING**");
getch();
}
