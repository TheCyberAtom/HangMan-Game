#include <bits/stdc++.h>
#include <windows.h>
#include<conio.h>
using namespace std;

HANDLE screen = GetStdHandle( STD_OUTPUT_HANDLE );
COORD max_size = GetLargestConsoleWindowSize( screen );

void gotoxy(int line,int column)
{
    COORD pos;
    pos.X = column;
    pos.Y = line;
    SetConsoleCursorPosition( screen, pos );
}
int tries=0;
string hint;
string oWord="";
char inputChar;
char dash[]={'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'};
//char alphabets[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
string alphabets="abcdefghijklmnopqrstuvwxyz";
string result="        ";
vector<string>hm;

void hangman_animation()
{
    int j;
    for(int i=0;i<10;i++)
    {
        j=0;
       system("cls");
       while(j<=i)
       {
           cout<<"\n";
           j++;
       }
    cout<<"\n\t\t H       H       A        N       N   G GG G         M          M        A       N       N";
    cout<<"\n\t\t H       H      A A       N N     N  G      G        M M      M M       A A      N N     N";
    cout<<"\n\t\t H       H     A   A      N  N    N  G      G        M   M   M  M      A   A     N  N    N";
    cout<<"\n\t\t H-H-H-H-H    A     A     N   N   N  G               M     M    M     A     A    N   N   N";
    cout<<"\n\t\t H       H   A A-A-A A    N    N  N  G  GGGGG        M          M    A A-A-A A   N    N  N";
    cout<<"\n\t\t H       H  A         A   N     N N  G      G        M          M   A         A  N     N N";
    cout<<"\n\t\t H       H A           A  N       N   G G G G        M          M  A           A N       N";
    Sleep(100);
    }
}

void wordToBeGuessed()
{
    oWord="";
    hint="";
     cout<<
    " #--------------------------------------------------------------------------------------------------------------------#"
    "\n\t\t\t\t\t\t   HANG MAN - GAME\n"
    " #--------------------------------------------------------------------------------------------------------------------#";
    char ch;
    cout<<"\n\n\n\t\t Enter one Word to be Guessed (Less Than 15 Characters): ";
    while(TRUE)
    {
        ch=getch();
        if(ch=='\r')
            break;
        oWord=oWord+ch;
        cout<<"*";
    }
    cout<<"\n\n\n\t\t Enter HINT for the other player : ";
    getline(cin,hint);
}

void checkForWord()
{
    for(int i=0;i<oWord.length();i++)
    {
        if(oWord[i]==inputChar)
            dash[i]=inputChar;
    }
}

bool checkWin()
{
    for(int i=0;i<oWord.length();i++)
    {
        if(oWord[i]!=dash[i])
            return FALSE;
    }
    return TRUE;
}

void display()
{
    cout<<
    " #--------------------------------------------------------------------------------------------------------------------#"
    "\n\t\t\t\t\t\t    HANG MAN - GAME  \t\t\t\tTOTAL LIVES :  "<<10-tries<<"\n"
    " #--------------------------------------------------------------------------------------------------------------------#"
    "\n\t       \t|\t\t\t\t\t\t\t\t\t\t|\n"
    "\t H     \t|\t\t\t\tGUESS THE WORD BELOW  \t\t\t"<<"  \t|\t H\n"
    "\t       \t|\t\t\t\t\t\t\t\t\t\t|\n"
    "\t A     \t|\t\t\t\t\t\t\t\t\t\t|\t A\n"
    "\t       \t|\t\t\t\t\t\t\t\t\t\t|\n"
    "\t N     \t|\t\t\t";
    for(int i=0;i<15;i++)
    {
        if(i<oWord.length())
        {
            checkForWord();
            cout<<dash[i]<<"  ";
        }
        else
            cout<<"   ";
    }
    cout<<"\t\t|\t N\n"
    "\t       \t|\t\t\t\t\t\t\t\t\t\t|\n"
    "\t G     \t|-------------------------------------------------------------------------------|\t G\n"
    "\t       \t\t\t\t Hint : "<<hint<<"\n"
    "\t       \t|-------------------------------------------------------------------------------|\n"
    "\t M     \t|\t\t\t\t\t\t\t\t\t\t|\t M\n"
    "\t       \t|\t\t\t\t\t\t\t\t\t\t|\n"
    "\t A     \t|\t\t\t\t\t\t\t\t\t\t|\t A\n"
    "\t       \t|\t\t\t\t\t\t\t\t\t\t|\n"
    "\t N     \t|\t\t\t\t\t\t\t\t\t\t|\t N\n"
    "\t       \t|\t\t\t\t"<<result<<"\t\t\t\t\t|\n"
    "\t       \t|\t\t\t\t\t\t\t\t\t\t|\n"
    "\t G     \t|\t\t\t\t\t\t\t\t\t\t|\t G\n"
    "\t A     \t|\t\t\t\t\t\t\t\t\t\t|\t A\n"
    "\t M     \t|\t\t\t\t\t\t\t\t\t\t|\t M\n"
    "\t E     \t|\t\t\t\t\t\t\t\t\t\t|\t E\n"
    " #--------------------------------------------------------------------------------------------------------------------#"
    "\n\tAvailable Alphabets : ";
    for(int i=0;i<26;i++)
    {
        if(alphabets[i]==inputChar)
            alphabets[i]=' ';
        cout<<alphabets[i]<<"  ";
    }
    cout<<"\n #--------------------------------------------------------------------------------------------------------------------#";

}



int main()
{
    hangman_animation();
    char choice;
    do
    {
        oWord="";
        alphabets="abcdefghijklmnopqrstuvwxyz";
        hint="";
        result="        ";
        inputChar=' ';
        for(int i=0;i<15;i++)
        {
            dash[i]='-';
        }
        system("cls");
        wordToBeGuessed();
        tries=0;
        do
        {
            system("cls");
            //drawHangman(tries);
            display();
            if(checkWin())
            {
                result="YOU  WON";
                system("cls");
                display();
                break;
            }
            cout<<"\n\t\t\t\t\t Guess a Character : ";
            cin>>inputChar;
            tries++;
        }while(tries<=10);
        if(!checkWin())
            {
                result="YOU LOSE";
                system("cls");
                display();
            }
    cout<<"\n Do You Want To Play Again : ";
    cin>>choice;
    }while(choice=='y'|| choice=='Y');
    return 0;
}
