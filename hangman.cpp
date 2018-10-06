// HEADER FILES USED //
//make sure to add txt files for the game to be played //git 
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<conio.h>
#include<ctype.h>
// FUNCTION DECLARATION OF FUNCTION WHICH CHECKS IF THE GUSSED LETTER IS CORRECT OR NOT 
int check(char, char[], char[]);
// FUNCTION TO DISPLAY GAME TITLE 
{cout <<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
cout<<"\n\t**  **     ***    **   *    ******  *      **       ***  **   *    *   *      *****    ";
cout<<"\n\t**  **    * **    ***  *    **      **    ***      * **  ***  *    *   *      *        ";
cout<<"\n\t******   *****   ** * *    **  **  *  * * **    *****   ** * *    *****    *****    ";
cout<<"\n\t**  **  *    **   **  **    **   *  *   *  **   *   **   **  **        *  **      *    ";
cout<<"\n\t**  ** *     **   **   *    ******  *      **  *    **   **   *        *  **  *****    ";
cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}
//FUNCTION TO HOLD THE SCREEN FOR SOME TIME
void stop()
{   for(long stop=0;stop<30000000;stop++)
		{}
	}
// MAIN FUNCTION
int main()
{ int k,cc;
int mx_tries =5;               
char name[25],again,ch,beg,dif,choice;
	 ifstream fin;
open:
clrscr(); 
display();  

cout<<"\n\n\t\t1.)NEW GAME ";
cout<<"\n\t\t2.)HELP ";
cout<<"\n\t\tENTER YOUR OPTION :";
beg=getch();
if(beg=='2')
{   clrscr();
display();

	 cout << "\n\n\tWELCOME TO HANGMAN (bETA version)";
	cout << "\n\n\t\tEACH HIDDEN LETTER IS REPRESENTED BY A STAR";
	cout << "\n\n\t\tYOU HAVE TO TRY ONLY ONE LETTER IN ONE CHANCE";
	cout << "\n\n\t\tYOU HAVE " <<mx_tries<< " CHANCES TO TRY AND GUESS THE WORD";
	 cout << "\n\n\t\tREADY NOW???";
	 cout << "\n\n\t\t\tPRESS ENTER";
	 cin.get(ch);
	 goto difficulty;

}


if(beg=='1')
{  difficulty:
	 start:
	 clrscr(); //TO CLEAR SCREEN
display();


cout<<"\n\n\t: DIFFICULTY :";
cout<<"\n\t1.)EASY";
cout<<"\n\t2.)MEDIUM";
cout<<"\n\t3.)HARD";
cout<<"\n\n\tENTER YOUR OPTION :";
dif=getch();
if(dif!='1'&&dif!='2'&&dif!='3')

{ cout<<"\n\n\tERROR 500x"<<endl;
	 stop();
	  goto start;
}
}

if(beg!='1'&&beg!='2')
{
	 cout<<"\n\n\tERROR 500x"<<endl;
	stop();
goto open;}
 categories:
	clrscr();
display();

	cout<<"\n\n\t:CATEGORIES:";
	cout<<"\n\n\t1.)CAR BRANDS";
	cout<<"\n\t2.)GAMES";
	cout<<"\n\t3.)BIKE BRANDS";
	cout<<"\n\n\tENTER YOUR OPTION :";
	choice=getch();

switch(choice)    // TO OPEN THE FILE PRESENT, DEPENDING ON DIFFICULTY AND CATEGORY CHOSEN
{
	 case '1': if(dif=='1')
	 {fin.open("car1.txt");};
	 if(dif=='2')
	  {fin.open("car2.txt");};
	  if(dif=='3')
	  {fin.open("car3.txt");};
	 break;
	 case '2':if(dif=='1')
	 {fin.open("game1.txt");};
	 if(dif=='2')
	  {fin.open("game2.txt");};
	  if(dif=='3')
	  {fin.open("game3.txt");};
	 break;
	 case '3':if(dif=='1')
	 {fin.open("bike1.txt");};
	 if(dif=='2')
	  {fin.open("bike2.txt");};
	  if(dif=='3')
	  {fin.open("bike3.txt");};
	  break;
	 default:cout<<"\n\n\tERROR 5000x";
	 stop();
	 goto categories; 
}
	clrscr();
char letter;
int num_guess=0;
randomize();
k=random(5)+1;
for(int i=0;i<k;i++)    // TO RANDOMLY CHOOSE A WORD FROM THE FILE
{
	 fin>>name;
}
char word[25];
strcpy(word,name);
int x;
x=strlen(word);
char unknown[15];
int j;
for(j=0;j<x;j++)
{ unknown[j]='*';
 }
 unknown[j]='\n';

while(num_guess<mx_tries)
{   if(choice=='1')
  {
  display();

	 cout<<"\n\tCATEGORY : CAR BRANDS :";
		 cout<<"\t\t\tYOU HAVE "<<mx_tries-num_guess<<" GUESS LEFT"<<endl;
  }

  if(choice=='2')
  {
display();


	 cout<<"\n\tCATEGORY : GAMES :";
		 cout<<"\t\t\tYOU HAVE "<<mx_tries-num_guess<<" GUESS LEFT"<<endl;
  }

  if(choice=='3')
  {
display();


	 cout<<"\n\tCATEGORY : BIKE BRANDS :";
	cout<<"\t\t\tYOU HAVE "<<mx_tries-num_guess<<" GUESS LEFT"<<endl;
  }
	 cout<<"\n\tHIDDEN WORD:";
	 cout.write(unknown,x);
	 cout<<"\t\t\tWORD LENGTH :"<<x;
	 cout<<"\n\n\tGUESS A LETTER: ";
	 letter=getch();


	 if(check(letter,word,unknown)==0)
	 { 	  cout<<"\n\n\tTRY AGAIN ";
		  num_guess++; }
	 else
	
   {	 cout<<"\n\n\tCORRECT ";		  }

  stop();

clrscr();
	 for(int k=0;k<x;k++)
	 {if(word[k]==unknown[k])
		  {cc=1;}
		  else
		 {  cc=0;
			break; }
		 }
	 if(cc==1)

	 {     cout<<"\n\tCONGRATULATIONS"<<"\n\tYOU DID IT";
		  cout<<"\n\n\tCORRECT WORD:"<<word;
		  cout<<"\n\n\tWANNA TRY AGAIN ???";
		  cout<<"\n\n\t1.)YES";
		  cout<<"\n\t2.)NO";
		  cout<<"\n\n\tENTER YOUR OPTION :";
		  again=getch();
	 if(again=='1')
	 {   fin.close();
		  goto start;   }
	 if(again=='2')
	 {cout<<"\n\n\tTHANK YOU FOR PLAYING :)";}
	  else
	 { cout<<"\n\n\tLOOSER "; }
 break;	 }
}
if(num_guess==mx_tries)











{	 cout<<"\n\tYOU HAVE BEEN HANGED\n";
	 cout<<"\n\t  *********                             ";
	 cout<<"\n\t  *       *                             ";
	 cout<<"\n\t  *       *                             ";
	 cout<<"\n\t  *      ***        *****   ******  *****  ";
	 cout<<"\n\t  *     *   *       ** **     **     **  *  ";
	 cout<<"\n\t  *    * *  * *     *****     **     *****  ";
	 cout<<"\n\t  *     *   *       ** *      **     **     ";
	 cout<<"\n\t  *      ***        **  *     **     **     ";
	 cout<<"\n\t  *       *         **   *   ****    **     ";
	 cout<<"\n\t  *      ***                            ";
	 cout<<"\n\t  *     * * *                           ";
	 cout<<"\n\t  *    *  *  *                          ";
	 cout<<"\n\t  *       *                             ";
	 cout<<"\n\t  *       *                             ";
	 cout<<"\n\t  *       *                             ";
	 cout<<"\n\t  *      * *                            ";
	 cout<<"\n\t  *     *   *                           ";
	 cout<<"\n\t  *                                     ";
	 cout<<"\n\t  *                                     ";
	 cout<<"\n\t*********************                   ";


	 if(choice=='1')
	 {cout<<"\n\n\tTHE CAR BRAND WAS :"<<word;}
	 if(choice=='2')
	 {cout<<"\n\n\tTHE GAME  WAS :"<<word;}
	 if(choice=='3')
	 {cout<<"\n\n\tTHE BIKE BRAND WAS :"<<word;}
	 cout<<"\n\n\tWANNA TRY AGAIN ???";
	 cout<<"\n\n\t1.)YES";
	 cout<<"\n\t2.)NO";
	 cout<<"\n\n\tENTER YOUR OPTION :";
	 again=getch();
	 if(again=='1')
	 {   fin.close();
		  goto start;
	 }
		if(again=='2')
	 {cout<<"\n\n\tTHANK YOU FOR PLAYING :)";}
	  else
	 { cout<<"\n\n\tLOOSER "; }


}

	 return 0;
}
//FUNCTION TO CHECK IF THE GUESSED LETTER IS CORRECT OR NOT
int check(char guess,char secretword[],char guessword[])
{
	 int i;
	 int match=0;
	 int len=strlen(secretword);
	 for(i=0;i<len;i++)
	 {
		  if(guess==guessword[i])             // IF THE GUESS LETTER IS ALREADY TYPED
		  {
				return 0;
		  }
		  if(guess==tolower(guessword[i]))
		  {
				return 0;
		  }
		  if(guess==secretword[i])
		  {
				guessword[i]=guess;
				match=1;
		  }
		  if(guess==tolower(secretword[i]))     
		  {
				guessword[i]=toupper(guess);
				match=1;
		  }
	 }
	 return match;
}


