//snake
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<process.h>

/*
ESC 27 
UPARR 72 
LEFTARR 75 
DOWNARR 80 
RIGHTARR 77
ENTER 13
n 110 
*/

	void color()
	{
	unsigned t=time(NULL);
	srand(t);
	int a=rand()/100%15+1;
	textcolor(a);
	}

	void programmer()
	{
	textcolor(7);
	clrscr();
	gotoxy(1,25);
	_setcursortype(_NOCURSOR);
	textcolor(7);
	cout<<"\n\n\nThanks for playing the game!!!";
	cout<<"\t\t\t\t\tCREATED BY ";
	color();
	cprintf("Reet Awwsum");
	getch();
	exit(0);
	}

	void loading()
	{
	clrscr();
	_setcursortype(_NOCURSOR);
	
		for (int r=1; r<3; r++)
		{
			textcolor(7);
			clrscr();
			textcolor(12);
			gotoxy(35,12);
			cprintf("LOADING");
			delay(520);
			cprintf(".");
			delay(520);
			cprintf(".");
			delay(520);
			cprintf(".");
			delay(520);
		}
	
	}
	
	void playagain()
	{
	void main();
	textcolor(7);
	clrscr();
	char m,n;
	_setcursortype(_NOCURSOR);
	int p=1,v=0;
		for (int i=5; i<=75; i++)
		{
			gotoxy(i,2);
			cout<<char(196);
			gotoxy(i,6);
			cout<<char(196);
		}

	gotoxy(36,4);
	color();
	cprintf("PLAY AGAIN ?");
	gotoxy(10,8);
	textcolor(3);
	cprintf("YES");
	gotoxy(10,10);
	textcolor(7);
	cprintf("NO");
	gotoxy(9,8);
	cout<<char(16);
	
	while(v!=13)
		{
			v=getch();
			if (v==0)
				v=getch();

			if (v==27)
				programmer();

			if (v==80)
			{
				if (p==1)
				{
					gotoxy(9,8);
						cout<<char(255);
					gotoxy(10,8);
						textcolor(7);
						cprintf("YES");
					gotoxy(10,10);
						textcolor(3);
						cprintf("NO");
					gotoxy(9,10);
						cout<<char(16);
					p=2;
				}

				else if (p==2)
				{
					gotoxy(9,10);
						cout<<char(255);
					gotoxy(10,10);
						textcolor(7);
						cprintf("NO");
					gotoxy(10,8);
						textcolor(3);
						cprintf("YES");
					gotoxy(9,8);
						cout<<char(16);
					p=1;
				}
			}

			if (v==72)
			{
				if (p==1)
				{
					gotoxy(9,8);
						cout<<char(255);
					gotoxy(10,8);
						textcolor(7);
						cprintf("YES");
					gotoxy(10,10);
						textcolor(3);
						cprintf("NO");
					gotoxy(9,10);
						cout<<char(16);
					p=2;
				}

				else if (p==2)
				{
					gotoxy(9,10);
						cout<<char(255);
					gotoxy(10,10);
						textcolor(7);
						cprintf("NO");
					gotoxy(10,8);
						textcolor(3);
						cprintf("YES");
					gotoxy(9,8);
						cout<<char(16);
					p=1;
				}
			}
		}
		
		switch(p)
		{
			case 1: main(); break;
			case 2: programmer(); break;
		}
		
	}
	
	class snake
	{
	int speed,eatx,eaty,x,y,newkey,score,food,length,a[50],b[50];
	public:
	void firstscreen();
	void collision();
	void speedselect();
	void gamescreen();
	void eatxy();
	void game();
	void gamescore();
	void checkcollision();
	};
	
	void snake::eatxy()
	{
	unsigned t=time(NULL);
	srand(t);
	eatx=rand()/100%77+2;
	eaty=rand()/100%20+2;
	food=rand()/100%8+1;
	gotoxy(eatx,eaty);
		
			if (score%25==1||score%24==1||score%23==1||score%22==1||score%21==1||score%20==1)
			{
			cout<<"$";
			food=101;
			}
	
		
		else
		cout<<food;
	}
	
	void snake::gamescore()
	{
		gotoxy(76,24);
		score=score+food;
		cout<<score;
		
	}
	
	void snake::checkcollision()
	{
		if (x==1||x==80||y==1||y==23)
		{
				collision();
		}

		for (int i=1; i<=50; i++)
		{
			if (a[i]==x)
			{
				if (b[i]==y)
				collision();
			}
		}	
	}
	
	void snake::game()
	{
	void main();
		
		x=43; y=12; length=6;
		score=0;
		
		for(;;)
		{
			while (!kbhit())
			{
				if ((eatx==x)&&(eaty==y))
				{
					gamescore();
					eatxy();
					length=length+2;
				}
				
				gotoxy(x,y);
				cout<<"";
				
		/*		for (int i=1; i<=length+1; i++)
				{
					if (newkey==72)
					{
						gotoxy(x,y+i);
						a[i]=x; b[i]=y+i;
					}	
					
					if (newkey==75)
					{
						gotoxy(x+i,y);
						a[i]=x+i; b[i]=y;
					}	
					
					if (newkey==80)
					{
						gotoxy(x,y-i);
						a[i]=x; b[i]=y-i;
					}
					
					if (newkey==77)
					{
						gotoxy(x-i,y);
						a[i]=x-i; b[i]=y;
					}
					
					if (i==length+1)
					cout<<" ";
					
					else
					cout<<"Û";
				}	*/
				
				delay(speed);
				gotoxy(x,y);
				
				checkcollision();
				
				if (newkey==72)
				y--;
				
				if (newkey==75)
				x--;
				
				if (newkey==80)
				y++;
				
				if (newkey==77)
				x++;
				
				if (newkey==27)
				programmer();
				
				if (newkey==13)
				getch();
				
				if (newkey==110)
				main();
				
				cout<<" ";
				
			}
		
			newkey=getch();
			
			if (newkey==0)
			newkey=getch();
			
		}	
	}

	void snake::gamescreen()
	{
	char i;
	textcolor(7);
	clrscr();
	textcolor(14);
	cprintf("É");
	textcolor(RED);
	for(i=0;i<78;i++)
	cprintf("Í");
	textcolor(14);
	cprintf("»");
	gotoxy(1,23);
	cprintf("È");
	textcolor(RED);
	for(i=0;i<78;i++)
	cprintf("Í");
	textcolor(14);
	cprintf("¼");
	textcolor(RED);
	window(1,2,1,23);
	for(i=0;i<21;i++)
	cprintf("º");

	window(80,2,80,23);
	for(i=0;i<21;i++)
	cprintf("º");
	window(1,1,80,25);
	gotoxy(43,12);
	printf("");
	gotoxy(1,24);
	printf("Welcome to the game of ");
	color();
	cprintf("SNAKE");
	cout<<" !!";
	textcolor(7);
	gotoxy(50,24);
	cout<<"ENTER to Pause";
	cout<<"\n(Press any arrow key to start now, Esc to leave, N for new game at any time...)";
	newkey=getch();
	if (newkey==0)
	newkey=getch();
	eatxy();
	gotoxy(1,24);
	delline(); delline();
	gotoxy(35,24);
	cout<<"EAT !!!!!";
	gotoxy(70,24);
	color();
	cprintf("SCORE=");
	cout<<"0";
	}

	void snake::speedselect()
	{
	textcolor(7);
	clrscr();
	char m,n;
	_setcursortype(_NOCURSOR);
	int p=2,v=0;
		for (int i=5; i<=75; i++)
		{
		gotoxy(i,2);
		cout<<char(196);
		gotoxy(i,6);
		cout<<char(196);
		}

	gotoxy(36,4);
	color();
	cprintf("SELECT SPEED");
	gotoxy(10,8);
	textcolor(3);
	cout<<"SLOW";
	gotoxy(10,10);
	cprintf("MEDIUM");
	gotoxy(9,10);
	cout<<char(16);
	gotoxy(10,12);
	cout<<"FAST";

		while (v!=13)
		{
				v=getch();
				if (v==0)
				v=getch();

				if (v==13)
				break;

				if (v==27)
				programmer();

				if (v==80)
				{
					if (p==1)
					{
						gotoxy(9,8);
						cout<<" ";
						gotoxy(9,10);
						cout<<char(16);
						gotoxy(10,8);
						textcolor(7);
						cprintf("SLOW");
						gotoxy(10,10);
						textcolor(3);
						cprintf("MEDIUM");
						p=2;
					}

					else if (p==2)
					{
						gotoxy(9,10);
						cout<<" ";
						gotoxy(9,12);
						cout<<char(16);
						textcolor(7);
						gotoxy(10,10);
						cprintf("MEDIUM");
						gotoxy(10,12);
						textcolor(3);
						cprintf("FAST");
						p=3;
					}

					else if (p==3)
					{
						gotoxy(9,12);
						cout<<" ";
						gotoxy(9,8);
						cout<<char(16);
						gotoxy(10,12);
						textcolor(7);
						cprintf("FAST");
						gotoxy(10,8);
						textcolor(3);
						cprintf("SLOW");
						p=1;
					}

				}

				if (v==72)
				{
					if (p==1)
					{
						gotoxy(9,8);
						cout<<" ";
						gotoxy(9,12);
						cout<<char(16);
						gotoxy(10,8);
						textcolor(7);
						cprintf("SLOW");
						gotoxy(10,12);
						textcolor(3);
						cprintf("FAST");
						p=3;
					}

					else if (p==2)
					{
						gotoxy(9,10);
						cout<<" ";
						gotoxy(9,8);
						cout<<char(16);
						gotoxy(10,10);
						textcolor(7);
						cprintf("MEDIUM");
						gotoxy(10,8);
						textcolor(3);
						cprintf("SLOW");
						p=1;
					}

					else if (p==3)
					{
						gotoxy(9,12);
						cout<<" ";
						gotoxy(9,10);
						cout<<char(16);
						textcolor(7);
						gotoxy(10,12);
						cprintf("FAST");
						gotoxy(10,10);
						textcolor(3);
						cprintf("MEDIUM");
						p=2;
					}
				}
		}

		switch(p)
		{
			case 1: speed=200; break;   
			case 2: speed=120; break;   
			case 3: speed=70; break;
		}
	}
	
	void snake::collision()
	{
		gotoxy(1,24);
		delline();
		gotoxy(35,24);
		color();
		cprintf("GAME OVER");
		gotoxy(1,25);
		textcolor(7);
		cprintf("The snake collided with the wall or with itself!");
		gotoxy(70,24);
		color();
		cprintf("SCORE=");
		cout<<score;
		getch();
		playagain();	
	}
	
	void snake::firstscreen()
	{
	_setcursortype(_NOCURSOR);
	color();

		for (int i=75; i>=38; i--)
		{
		gotoxy(i,12);
		cputs("Snake ");
		gotoxy(24,13);
		cout<<"--*--*--*--*--*--*--*--*--*--*--";
		delay(120);
		}

	gotoxy(19,25);
	cout<<"******** PRESS ANY KEY TO CONTINUE ********";
	int g=getch();
	if (g==0)
	g=getch();

	if (g==27)
	programmer();

	}

void main()
{
_setcursortype(_NOCURSOR);
textcolor(7);
clrscr();
snake s;
s.firstscreen();
s.speedselect();
loading();
s.gamescreen();
s.game();
}