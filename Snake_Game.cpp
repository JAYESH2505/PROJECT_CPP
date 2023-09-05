//HEADER FILE
#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace::std;

//Global Variable.
bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,Score;
int tailX[100];
int tailY[100];
int ntail;
enum Direction{STOP=0,LEFT,RIGHT,UP,DOWN};
Direction dir;

//Creating Function
void Setup()
{
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    Score=0;
    

}
void Draw()
{
    //Clear Screen.
     system("cls");

     for(int i=0;i<width+2;i++)
     {
        cout<<"#";
     }
     cout<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
            {
                cout<<"#";
            }
            if(i==y && j==x){
                cout<<"0";
            }
            else if(i==fruitY && j==fruitX)
            {
                cout<<"F";
            }
            else{
                bool print=false;
                for(int k=0;k<ntail;k++)
                {
                     
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print)
                {
                    cout<<" ";
                }
            }
            if(j==width-1)
            {
                cout<<"#";
            }
            
        }
        cout<<endl;
    }
     for(int i=0;i<width+2;i++)
     {
        cout<<"#";
     }
     cout<<endl;

     cout<<"Score : "<<Score<<endl;
}
void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
                case 'a':
                   dir=LEFT;
                   break;
                case 'd':
                   dir=RIGHT;
                   break;
                case 'w':
                    dir=UP;
                    break;
                case 's':
                    dir=DOWN;
                    break;
                case 'x':
                 gameOver=true;
                 break;
        }
    }
}
void Logic()
{
    int prevx=tailX[0];
    int prevy=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<ntail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];

        tailX[i]=prevx;
        tailY[i]=prevy;

        prevx=prev2X;
        prevy=prev2Y;
    }
     switch(dir)
     {
        case LEFT:
         x--;
         break;
        case RIGHT:
         x++;
         break;
        case UP:
         y--;
         break;
        case DOWN:
         y++;
         break;
        default:
         break;
     }
    //  if(x>width-2 || x<0)
    //  {
    //     gameOver=true;
    //  }
    //  if(y>height || y<0)
    //  {
    //     gameOver=true;
    //  }
     if(x>=width) x=0; else if(x<0) x=width-1;
     if(y>=height) y=0; else if(y<0) y=height-1;
     for(int i=0;i<ntail;i++)
     {
        if(tailX[i]==x && tailY[i]==y)
        {
            gameOver=true;
        }
     }
     if(x==fruitX && y==fruitY)
     {
      
        Score+=10;
        fruitX=rand()%width;
        fruitY=rand()%height;  
        ntail++;
     }
}


// MAIN Function.
int main()
{
          Setup();
          while(!gameOver)
          {
            Draw();
            Input();
            Logic();
            Sleep(200);
          }
}