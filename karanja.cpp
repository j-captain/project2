 # include <iostream>
# include <ctime>
using namespace std;

void drawBoard(char *theSpaces);
void playerMove(char *theSpaces, char thePlayer);
void computerMove(char *theSpaces, char theComputer);
bool checkTheWinner(char *theSpaces, char thePlayer, char theComputer);
bool checkDraw(char *theSpaces);

int main()
{

  char theSpaces [9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
  char thePlayer = 'C';
  char theComputer = 'O';
  bool programRunning = true;
  
  drawBoard(theSpaces);
  
  while(programRunning)
     { 
       playerMove(theSpaces, thePlayer);
       drawBoard(theSpaces);
       
       if(checkTheWinner(theSpaces, thePlayer, theComputer))
          {
            programRunning = false;
            break;
           }
        else if(checkDraw(theSpaces))
          {
            programRunning = false;
            break;
           }
       
       computerMove(theSpaces, theComputer);
       drawBoard(theSpaces);
       
       if(checkTheWinner(theSpaces, thePlayer, theComputer))
          {
            programRunning = false;
            break;
           }
         else if(checkDraw(theSpaces))
          {
            programRunning = false;
            break;
           }
           
     }
     
     cout<<"•••••••••••••••••••••••••••••••••••••••••••••••••••••"<<endl;
     cout<<"THANKS FOR PLAYING"<<endl;
     cout<<"•••••••••••••••••••••••••••••••••••••••••••••••••••••"<<endl;
return 0;

}

void drawBoard( char *theSpaces)
{
  cout<<'\n';
  cout<<"     |     |     "<<endl;
  cout<<"  "<<theSpaces[0]<<"  |  "<<theSpaces[1]<<"  |  "<<theSpaces[2]<<"  "<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"  "<<theSpaces[3]<<"  |  "<<theSpaces[4]<<"  |  "<<theSpaces[5]<<"  "<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"     |     |     "<<endl;
  cout<<"  "<<theSpaces[6]<<"  |  "<<theSpaces[7]<<"  |  "<<theSpaces[8]<<"  "<<endl;
  cout<<"     |     |     "<<endl;
  cout<< '\n';

}

void playerMove(char *theSpaces, char thePlayer)
{
   int myNumber;
   do{
   	  cout<<"•••••••••••••••••••••••••••••••••••••••••••••••••••••"<<endl;
         cout<<"ENTER A NUMBER TO MARK A SPOT (1-9) :"<<endl;
         cout<<"•••••••••••••••••••••••••••••••••••••••••••••••••••••"<<endl;
         cin>>myNumber;
         myNumber --;
         
         if (theSpaces[myNumber] == ' ')
            {
              theSpaces[myNumber] = thePlayer;
              break;
            }
   
       }while(!myNumber > 0 || !myNumber < 8);
     
     
}
void computerMove(char *theSpaces, char theComputer)
{
   int computerNumber;
   srand(time(NULL));
   while(true)
      {
         computerNumber = rand() % 9;
          if(theSpaces[computerNumber] == ' ')
           { 
             theSpaces[computerNumber] = theComputer;
             break;
           }
       }

}
bool checkTheWinner(char *theSpaces, char thePlayer, char theComputer)
{
   if((theSpaces[0] != ' ') && (theSpaces[0] == theSpaces[1]) && (theSpaces[1] == theSpaces[2]))
      {
        theSpaces[0] == thePlayer ? cout<<"CONGRATULATIONS YOU WIN \n ": cout<<"SORRY YOU LOST!!! \n";
      }

   else if((theSpaces[3] != ' ') && (theSpaces[3] == theSpaces[4]) && (theSpaces[4] == theSpaces[5]))
      {
        theSpaces[3] == thePlayer ? cout<<"CONGRATULATIONS  YOU WIN \n ": cout<<"SORRY YOU LOST!!! \n";
      }
      
    else if((theSpaces[6] != ' ') && (theSpaces[6] == theSpaces[7]) && (theSpaces[7] == theSpaces[8]))
      {
        theSpaces[6] == thePlayer ? cout<<"CONGRATULATIONS YOU WIN \n ": cout<<"SORRY YOU LOST!!! \n";
      }

    else if((theSpaces[0] != ' ') && (theSpaces[0] == theSpaces[4]) && (theSpaces[4] == theSpaces[5]))
      {
        theSpaces[0] == thePlayer ? cout<<"CONGRATULATIONS YOU WIN \n ": cout<<"SORRY YOU LOST!!!\n";
      }

    else if((theSpaces[1] != ' ') && (theSpaces[1] == theSpaces[4]) && (theSpaces[4] == theSpaces[7]))
      {
        theSpaces[1] == thePlayer ? cout<<"CONGRATULATIONS  YOU WIN \n ": cout<<"SORRY YOU LOST!!! \n";
      }

    else if((theSpaces[2] != ' ') && (theSpaces[2] == theSpaces[5]) && (theSpaces[5] == theSpaces[8]))
      {
        theSpaces[2] == thePlayer ? cout<<"CONGRATULATIONS  YOU WIN \n ": cout<<"SORRY YOU LOST!!!\n";
      }

   else if((theSpaces[0] != ' ' ) && (theSpaces[0] == theSpaces[4]) && (theSpaces[4] == theSpaces[8]))
      {
        theSpaces[0] == thePlayer ? cout<<"CONGRATULATIONS  YOU WIN \n ": cout<<"SORRY YOU LOST!!!\n";
      }

   else if((theSpaces[2] != ' ') && (theSpaces[2] == theSpaces[4]) && (theSpaces[4] == theSpaces[6]))
      {
        theSpaces[2] == thePlayer ? cout<<"CONGRATULATIONS YOU WIN \n ": cout<<"SORRY YOU LOST!!! \n";
      }
    else
      {
        return false;
      }
    return true;

}
bool checkDraw(char *theSpaces)
{
   for(int i = 0; i < 9; i++)
       {
         if(theSpaces[i] == ' ')
            {
               return false;
               break;
            }
         }
         cout<<"••••••••••••••••••••••••••••••••••••••••••••"<<endl;
         cout<<"WOW,ITS A DRAW!!"<<endl;
         cout<<"••••••••••••••••••••••••••••••••••••••••••••"<<endl;
         cout<<"••••••••••••••••••••••••••••••••••••••••••••"<<endl;
         
         return true;
}
