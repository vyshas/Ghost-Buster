#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <alloc.h>

#define lost 200
void man_mv(int,int);
void draw(int,int,int []);
void bird(int,int);
void fire(int,int []);
void tree(int,int);
void *buf;
int z=0;
int p=-1,x,path;
int a=100, b=80;
char ch;
void main(void)
{
   int gdriver = DETECT, gmode;
   int xmax,ymax;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   xmax=getmaxx(); ymax=getmaxy();
   int poly[]={0,0,xmax,0,xmax,ymax,0,ymax,0,0};

   draw(xmax,ymax,poly);
    getch();

   closegraph();

}

 void man_mv(int x,int ymax)
 {
  setfillstyle(1,GREEN);
  fillellipse(20+x,ymax-70,20,20);
  setlinestyle(2,1,1000);
  line(20+x,ymax-50,20+x,ymax-20);
  line(20+x,ymax-20,10+x,ymax);
  line(20+x,ymax-20,30+x,ymax);
  line(20+x,ymax-35,40+x,ymax-60);
  line(20+x,ymax-35,40+x,ymax-40);
  line(40+x,ymax-60,40+x,ymax-40);

  line(38+x,ymax-120,38+x,ymax-40);
  line(32+x,ymax-100,44+x,ymax-100);
 }


 void draw(int xmax,int ymax,int *poly)
 {
   x=60;
   int i=0;

   START:
      setfillstyle(7,RED);
      cleardevice();
      int fire_poly[]={65,80+i,65,180+i,55,130+i,25,200+i,25,100+i,40,140+i,65,80+i};

   switch(i)
   {

     case 0:  drawpoly(5, poly);
		//tree(x,ymax);
	       drawpoly(7,fire_poly);
	       setfillstyle(5,YELLOW);
	       fillpoly(7,fire_poly);
	       man_mv(x,ymax);
		delay(300);
		switch(path)
	      {
	       case 0:    if(p==11)
			  {
			   getch();
			   cleardevice();
			   outtextxy(xmax/2,ymax/2,"LOST LIFE\n Press any key to Continue........\n");
			   p=-1;
			   path=random(3);
			   getch();
			  }
			  else if(p==9)
			   p=-1;


			   switch(p)
			 {
			  case -1: bird(20,1); p++;
				   break;
			  case 0: bird(a,b);
				  p++;
				  break;
			  case 1: bird(2*a,b);
				  p++;
				  break;
			  case 2: bird(3*a,2*b); p++;
				  break;
			  case 3: bird(2*a,3*b); p++;
				  break;
			  case 4: bird(4*a,4*b); p++;
				  if(x==380)
				     p++;
				  break;
			  case 5: bird(4*a,ymax-60);
				  break;
			  case 6: bird(4*a,3*b); p++;
				  break;
			  case 7: bird(2*a,2*b); p++;
				  break;
			  case 8: bird(a,4*b);
				  if(x==60)
				   p=9;
				  else
				   p=11;
				  break;
			  case 9: bird(a-20,3*b);
				  delay(1000);
				  break;
			  /*case 10:bird(4*a,ymax-60);
				  getch();
				  //delay(1000);
				  break; */
			  case 11:bird(a,ymax-60);
				  //delay(1000);
				  break;

			 }

	      i+=150;
	     if(!kbhit())
	  {
	     delay(300);
	   goto START;
	  }
       ch=getch();
       delay(100);
       switch(ch)
       {
	 case 'a': if(x==60) ;
		   else   x-=160;
		  break;
	case 'd': if(x==540) ;
		   else  x+=160;
		  break;
       }
	  goto START;

	    case 1:      if(p==11)
			  {
			   getch();
			   cleardevice();
				   outtextxy(xmax/2,ymax/2,"LOST LIFE\n Press any key to Continue........\n");

			   p=-1;
			   path=random(3);
			   getch();
			  }
			  else if(p==9)
			   p=-1;


			   switch(p)
			 {
			  case -1: bird(20,1); p++;
				   break;
			  case 0: bird(a,b);
				  p++;
				  break;
			  case 1: bird(2*a,3*b);
				  p++;
				  break;
			  case 2: bird(3*a,2*b); p++;
				  break;
			  case 3: bird(4*a,3*b); p++;
				  break;
			  case 4: bird(5*a,4*b); p++;
				  if(x==540)
				     p++;
				  break;
			  case 5: bird(5*a,ymax-60);
				  break;
			  case 6: bird(4*a,3*b); p++;
				  break;
			  case 7: bird(2*a,3*b); p++;
				  break;
			  case 8: bird(a,4*b);
				  if(x==60)
				   p=9;
				  else
				   p=11;
				  break;
			  case 9: bird(a-20,3*b);
				  delay(1000);
				  break;
			  /*case 10:bird(4*a,ymax-60);
				  getch();
				  //delay(1000);
				  break; */
			  case 11:bird(a,ymax-60);
				  //delay(1000);
				  break;

			 }

	       i+=150;
		 if(!kbhit())
		{
		 delay(300);
		 goto START;
		}
	ch=getch();
	delay(100);
	switch(ch)
       {
	 case 'a': if(x==60) ;
		   else   x-=160;
		  break;
	case 'd': if(x==540) ;
		   else  x+=160;
		  break;
       }
	  goto START;

   }  break;

   case 150:   drawpoly(5, poly);
		//tree(x,ymax);
		drawpoly(7,fire_poly);
		setfillstyle(5,RED);
	       fillpoly(7,fire_poly);
		man_mv(x,ymax);
		 delay(300);
	       switch(path)
	      {
	       case 0:   if(p==5)
			  {
			   getch();
			   //cleardevice();
			   outtextxy(xmax/2,ymax/2,"LOST LIFE\n Press any key to Continue........\n");
			     p=-1;
			   path=random(3);
			   getch();
			  }
			  else if(p==9)
			   p=-1;


			    switch(p)
			 {
			  case -1: bird(20,1); p++;
				   break;
			  case 0: bird(a,b); p++;
				  break;
			  case 1: bird(2*a,b); p++;
				  break;
			  case 2: bird(3*a,2*b); p++;
				  break;
			  case 3: bird(2*a,3*b); p++;
				  break;
			  case 4: bird(4*a,4*b); p++;
				  if(x==380)
				     p++;
				  break;
			  case 5: bird(4*a,ymax-60);
				  break;
			  case 6: bird(4*a,3*b); p++;
				  break;
			  case 7: bird(2*a,2*b); p++;
				  break;
			  case 8: bird(a,4*b);
				  if(x==60)
				   p=9;
				  else
				   p=11;
				  break;
			  case 9: bird(a-20,3*b);
				  delay(1000);
				  break;
			  /*case 10:bird(4*a,ymax-60);
				  getch();
				 // delay(1000);
				  break;  */
			  case 11:bird(a,ymax-60);
				 // delay(1000);
				  break;

			  }

		i=0;
		if(!kbhit())
		 {
		 delay(600);
		 goto START;
		 }
		 ch=getch();
		delay(100);
	       switch(ch)
	       {
		case 'a': if(x==60) ;
			   else   x-=160;
			  break;
		case 'd': if(x==540) ;
			   else  x+=160;
			  break;
	       }
	      goto START;


	    case 1:      if(p==5)
			  {
			   getch();
			   cleardevice();
				   outtextxy(xmax/2,ymax/2,"LOST LIFE\n Press any key to Continue........\n");
			   p=-1;
			   path=random(3);
			   getch();
			  }
			  else if(p==9)
			   p=-1;


			   switch(p)
			 {
			  case -1: bird(20,1); p++;
				   break;
			  case 0: bird(a,b);
				  p++;
				  break;
			  case 1: bird(2*a,3*b);
				  p++;
				  break;
			  case 2: bird(3*a,2*b); p++;
				  break;
			  case 3: bird(4*a,3*b); p++;
				  break;
			  case 4: bird(5*a,4*b); p++;
				  if(x==540)
				     p++;
				  break;
			  case 5: bird(5*a,ymax-60);
				  break;
			  case 6: bird(4*a,3*b); p++;
				  break;
			  case 7: bird(2*a,3*b); p++;
				  break;
			  case 8: bird(a,4*b);
				  if(x==60)
				   p=9;
				  else
				   p=11;
				  break;
			  case 9: bird(a-20,3*b);
				  delay(1000);
				  break;
			  /*case 10:bird(4*a,ymax-60);
				  getch();
				  //delay(1000);
				  break; */
			  case 11:bird(a,ymax-60);
				  //delay(1000);
				  break;

			 }



		i=0;
		if(!kbhit())
		 {
		 delay(600);
		 goto START;
		 }
		 ch=getch();
		delay(100);
	       switch(ch)
	       {
		case 'a': if(x==60) ;
			   else   x-=160;
			  break;
		case 'd': if(x==540) ;
			   else  x+=160;
			  break;
	       }
	      goto START;
  } break;

 }
 }
 void bird(int a, int b)
 {
   if(z==0)
  {
   int lwing[]={40,20,60,20,20,60,40,20};
   int rwing[]={100,20,120,20,140,60,100,20};
   int face[]={60,20,60,10,70,15,90,15,100,10,100,20,80,40,60,20};
 setfillstyle(1,BLUE);
 fillpoly(4,lwing);
 fillpoly(4,rwing);
 fillpoly(8,face);
  unsigned int area=imagesize(20,1,140,60);
 buf= malloc(area);
 getimage(20,1,140,60,buf);
 delay(3000);
 z++;
  }
		if(kbhit())
	       {
		ch=getch();
		delay(100);
	       switch(ch)
	       {
		case 'a': if(x==60) ;
			   else   x-=160;
			  break;
		case 'd': if(x==540) ;
			   else  x+=160;
			  break;
	       }
	       }
 putimage(a,b,buf,XOR_PUT);
}

 void tree(int x,int ymax)
 {
  int poly[]={0,35,35,35,20,0,0,35};
  setfillstyle(2,GREEN);
  drawpoly(4,poly);
  line(5,5,10,10);
}