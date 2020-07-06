
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int place(int);
void queen(int);
void Board();
void Q(int,int);
void CounT(int,int,int);
int XYGraphic(int);
int x[9];

                                int main(void)
                                {
                             queen(8);
                             return 0;
                                }

void queen(int n)
{
 int k= 1,z,X,Y,counter=0,x2,y2,loc;
 int extern x[9];
 char answer;

                     int gdriver = DETECT, gmode, errorcode;
              /* initialize graphics and local variables */
		    initgraph(&gdriver, &gmode, "");
 x[1] = 0;
 printf("WHETHER YOU WANT TO CHOOSE A COORDINATE <Press C> OR\n");
 printf("COMPUTER TAKES ALL POSSIBLE CASES <Press A>:");
 scanf("%c",&answer);

 if(answer == 'c' || answer == 'C')

      {

       printf("X,Y:");

       scanf("%d%d",&x2,&y2);

       }

 clearviewport();

 while(k > 0)

 {



  x[k]++ ;

  while(x[k] <= n && !place(k))

   x[k]++;



   if(x[k] <= n)

   {

    if(k == n)

     {

     if(answer == 'a' || answer == 'A')

      {

      Board();

      counter++;

      for(int m=1;m<9;m++)

       {

z=x[m];

X = XYGraphic(m);

Y = XYGraphic(z);

       Q(X,Y);

       CounT(m,z,counter);

       }

       delay(3000);

      }

     else if(answer == 'c' || answer == 'C')

      {

       for(int i=1;i<9;i++)

       if(i==x2 && x[i]==y2)

 loc = 1;

       if(loc == 1)

{

 Board();

 counter++;

 for(int m=1;m<9;m++)

 {

   z=x[m];

   X = XYGraphic(m);

   Y = XYGraphic(z);

 Q(X,Y);

 CounT(m,z,counter);

 }

 loc = 0;

 delay(3000);

}

      }



       if(kbhit())

  exit(0);

 clearviewport();

}

    else

    {

    k++;x[k]=0;}

    }

    else

    k--;



    }



   }



int place(int l)

{

int i=1;

int extern x[9];

while(i < l)

{

 if((x[i] == x[l]) || abs(x[i] -x[l]) == abs(i - l))

  return(0);

  i +=1;

  }

  return(1);

}

int XYGraphic(int p)

{

 switch(p)

 {

  case 1: return 65;

  case 2: return 115;

  case 3: return 165;

  case 4: return 215;

  case 5: return 265;

  case 6: return 315;

  case 7: return 365;

  case 8: return 415;

 }

 return 0;

}

void CounT(int x3,int y3,int c)

{

       gotoxy(60,4);

       printf("[%d]",c);

       gotoxy(59,6+x3);

       printf("(%c,%d)",96+x3,y3);

}



void Q(int x1,int y1)

{

for(int i=0;i<=15;i++)

{

 setcolor(i);

 circle(x1,y1,i);

}

}



void Board()

{

    int m,n;

    outtextxy(65,20,"a");

    outtextxy(115,20,"b");

    outtextxy(165,20,"c");

    outtextxy(215,20,"d");

    outtextxy(265,20,"e");

    outtextxy(315,20,"f");

    outtextxy(365,20,"g");

    outtextxy(415,20,"h");

    outtextxy(20,65,"1");

    outtextxy(20,115,"2");

    outtextxy(20,165,"3");

    outtextxy(20,215,"4");

    outtextxy(20,265,"5");

    outtextxy(20,315,"6");

    outtextxy(20,365,"7");

    outtextxy(20,415,"8");



    for(int j=0;j<8;j++)

    for(int i=0; i<8;i++)

     rectangle(50*i+40,50*j+40,50*(i+1)+40,50*(j+1)+40);



     for(int l=0;l<8;l++)

     {

      if(l%2 == 0)

      {m=0; n=0;}

      else

      {m=1; n=50;}

      for(int k=0;k<4+m;k++)

       {

setfillstyle(SOLID_FILL,getmaxcolor());

floodfill(100*k-n+41,50*l+41,getmaxcolor());

}

     }

 }
