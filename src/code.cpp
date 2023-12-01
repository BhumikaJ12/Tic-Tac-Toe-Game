
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<alloc.h>
#include<fstream.h>
#include<time.h>

void graph(); 
void startgraph();
void gameloadingscreen();
void menuscreen();
void gamescreen(); void scorescreen();
void helpscreen(); void aboutscreen();
void inputnamescreen(); void exitgame();
void resetboxes();
void board();
void heading(char s[70]);
char* getstring(char) ;
void savescore2file(int gamestatus);
void backbutton();

//mouse functions..
void initmouse();
void showmouse();
void hidemouse() ;
void getmouse();
void setmouse() ;


//list of global variables.
union REGS in,out;
int px =1, py =1;
int click =0 ;
char box[11];
int playerturn=1;
char firstplayername[70]="Player1";
char secondplayername[70]="Player2";
char currentplayername[70]="";
char* combineplayernames();
int gamestatus=0;

void main()
{
	startgraph();
       // graph();
	gameloadingscreen();
	menuscreen();
        getch(); cleardevice(); closegraph();
} //end main................................................................

void gameloadingscreen()
{
     	setbkcolor(LIGHTBLUE);
	settextstyle(1,0,5);
	setcolor(WHITE);
	outtextxy(100,100,"TIC-TAC-TOE");
	setcolor(MAGENTA);
	settextstyle(3,0,1);
	outtextxy(400,143,"Fun Begins In A Moment....");
	setfillstyle(1,WHITE);
	outtextxy(150,370,"Loading...");
      	for(int i=1;i<=150;i++)
       	{
	  	bar(150,400,200+i,420);
	  	delay(30);
       	} 
     	 //graph(); getch();
} //end of gameloadingscreen()...............

void menuscreen()
{
      	delay(100); //put delay for mouse
      	cleardevice();
      	heading("Main Menu");
      	setfillstyle(1,LIGHTGRAY);
      	bar(220,100,220+200,100+30);
      	outtextxy(220+20,100,"Play Game");

      	bar(220,160,420,190);
      	outtextxy(240,160,"Scores");

      	bar(220,220,420,250);
      	outtextxy(240,220,"Help");

      	bar(220,280,420,310);
      	outtextxy(240,280,"About");

      	bar(220,340,420,370);
      	outtextxy(240,340,"Input Names");

      	bar(220,400,420,430);
      	outtextxy(240,400,"Exit");

      	initmouse(); showmouse();
      	while(1)
       	{
	        getmouse();   //px py click
     	 	if(px>=220&&px<=420&&py>=100&&py<=130&&click==1)
	 	{	
	   	  	hidemouse();
	   	  	playerturn=1;
		   	gamestatus=0;
		   	resetboxes();
		   	gamescreen();
		   	break;
	 	} //end if.
      		else if(px>=220&&px<=420&&py>=160&&py<=190&&click==1)
	        {
	     	  	hidemouse();
	          	scorescreen(); break;
	        }
      		else if(px>=220&&px<=420&&py>=220&&py<=250&&click==1)
	    	{
	      	 	hidemouse();
	         	helpscreen(); break;
	        }
      		else if(px>=220&&px<=420 && py>=280 && py<=310 && click==1)
	    	{
	      		hidemouse();
	      		aboutscreen(); break;
	    	}
      		else  if(px>=220&&px<=420 && py>=340 && py<=370 && click==1)
	   	{
	     		hidemouse();
	     		inputnamescreen(); break;

	    	}
      		else if(px>=220&&px<=420&&py>=400&&py<=430 && click==1)
	    	{
	     		hidemouse(); exitgame();
	    	}
       } 
   } //end menuscreen()....

   void whichplayerturn();
   char markx0;
   void checkgamestatus();

   void gamescreen()
   {
       	delay(100);
       	cleardevice(); hidemouse(); setbkcolor(LIGHTBLUE);
       	setfillstyle(1,WHITE);
      
       	settextstyle(1,0,2); setcolor(WHITE);
       	outtextxy(20,20,combineplayernames());

       	whichplayerturn();

       	board();

       	settextstyle(1,0,2);
       	bar3d(40,430,40+100,430+30,5,1);
       	outtextxy(70,430,"Exit..");
       
       	initmouse(); showmouse();
       	checkgamestatus();
       	while(gamestatus==0)
	{
	 	getmouse();
	  	if(px>=40&&px<=140&&py>=80&&py<=180&&click==1&&box[1]=='1')
	   	{
	      		box[1]=markx0;
	      		gamescreen();
	   	} 

	   	else if(px>=150&&px<=250&&py>=80&&py<=180&&click==1&&box[2]=='2')
	     	{
			box[2]= markx0;
			gamescreen();
	     	}

	    	else if(px>=260&&px<=360&&py>=80&&py<=180&&click==1&&box[3]=='3')
	     	{
			box[3]= markx0;
			gamescreen();
	     	}

	    	else if(px>=40&&px<=140&&py>=190&&py<=290&&click==1&&box[4]=='4')
	     	{
			box[4]= markx0;
			gamescreen();
	     	}

	    	else if(px>=150&&px<=250&&py>=190&&py<=290&&click==1&&box[5]=='5')
	     	{
			box[5]= markx0;
			gamescreen();
	     	}

	    	else if(px>=260&&px<=360&&py>=190&&py<=290&&click==1&&box[6]=='6')
	     	{
			box[6]= markx0;
			gamescreen();
	     	}

	    	else if(px>=40&&px<=140&&py>=300&&py<=400&&click==1&&box[7]=='7')
	     	{
			box[7]= markx0;
			gamescreen();
	     	}

	    	else if(px>=150&&px<=250&&py>=300&&py<=400&&click==1&&box[8]=='8')
	     	{
			box[8]= markx0;
			gamescreen();
	     	}

	    	else if(px>=260&&px<=360&&py>=300&&py<=400&&click==1&&box[9]=='9')
	     	{
			box[9]= markx0;
			gamescreen();
	     	}

	    	else if(px>=40&&px<=140&&py>=430&&py<=460&&click==1)
	     	{
			hidemouse(); //to avoid image flicker patch on menuscreen
		 	menuscreen();
	     	}

	} //end  while loop...


	char str[70];

	if(gamestatus == 1)
	{
	 	whichplayerturn();
	  	settextstyle(1,0,3); setcolor(BLUE);

	  	strcpy(str,""); strcat(str,currentplayername);
	  	strcat(str, " Wins....!!");
	  	setfillstyle(1,WHITE);
	  	bar3d(410,60,620,250,10,1);
	  	outtextxy(420,80,str);

	  	circle(520,190,50);
	  	circle(500,170,10);
	  	circle(540,170,10);
 
	  	ellipse(520,210,180,360,30,15); //happy smile.. set angle 180 - 360 degree
	  	savescore2file(gamestatus);

	 } //end if..
	else if(gamestatus == 2) //check for draw..
	{
	  	settextstyle(1,0,3); setcolor(GREEN);

		strcpy(str,"");
		strcat(str, " It's Draw ....!!");
		setfillstyle(1,WHITE);
		bar3d(410,60,620,250,10,1);
		outtextxy(420,80,str);
		
	  	//adding sad smiley here
	  	circle(520,190,50); //face..
	  	circle(500,170,10); //left eye.
	  	circle(540,170,10); //right eye.

	  	ellipse(520,210,0,180,30,15); //sad smile.. set angle 0 - 180 degree
	  	savescore2file(gamestatus);

	  } //end else if..


	sleep(5); hidemouse(); menuscreen();
     } //end gamescreen().............

void savescore2file(int gamestatus)
{
	 time_t t1; //to save current date n time.
	 t1= time(NULL);
	 //cout<<current date is "<<ctime(&t1);
	 ofstream ofs;
	 ofs.open("scores.txt",ios::app);
	 char msg[100];
	 if(gamestatus == 1) //win
	  {                           
	     ofs<<"\n"<<firstplayername<<" v/s "<<secondplayername<<" & Won By "<<currentplayername<<". Dated:"<<ctime(&t1);
	  }//end if.
	 else if(gamestatus == 2)  //draw..
	  {
	     ofs<<"\n"<<firstplayername<<" v/s "<<secondplayername<<" & It was a Draw!!  Dated:"<<ctime(&t1);
	  }

	  ofs.close();
       } //end of savescore2file()...

void checkgamestatus()
	{
    //step1 check for win/lose  set gamestatus to 1
	if(
    ( box[1] == box[2] && box[2] == box[3] ) ||
    ( box[4] == box[5] && box[5] == box[6] ) ||
    ( box[7] == box[8] && box[8] == box[9] ) ||
    ( box[1] == box[4] && box[4] == box[7] ) ||
    ( box[2] == box[5] && box[5] == box[8] ) ||
    ( box[3] == box[6] && box[6] == box[9] ) ||
    ( box[1] == box[5] && box[5] == box[9] ) ||
    ( box[3] == box[5] && box[5] == box[7] )
	  )
	   {
	     gamestatus = 1;
	     return  ;
	    }

	   if(
	   box[1]!='1'&&box[2]!='2'&&box[3]!='3'&&box[4]!='4'
	   &&box[5]!='5'&&box[6]!='6'&&box[7]!='7'&&box[8]!='8'
	   &&box[9]!='9')
	     
	      {
	       gamestatus =2;

	      }
	    else
	      {
	       gamestatus =0;

	       }
	} //end of checkgamestatus()....

void whichplayerturn()
       {  //sets markx0 to x or 0 and playerturn to 1 or 2..
	  if(playerturn == 1) //if1st player turn..
	     {
	       setcolor(GREEN); markx0='X';
	       playerturn=2; //flip turn to 2nd player..
	       strcpy(currentplayername,firstplayername);
	     }//end if..
	  else if(playerturn == 2)
	    {
	      setcolor(BLACK); markx0='0';
	      playerturn=1; //flip turn to 1st player.
	      strcpy(currentplayername,secondplayername);

	    } //end else if.




     setfillstyle(1,WHITE);
     bar(420,80,580,140);
     settextstyle(1,0,3); setcolor(GREEN);
     char msg[100];
     strcpy(msg,""); strcat(msg,"Now "); strcat(msg,currentplayername);
     outtextxy(430,80,msg);
     char msg2[70];
     strcpy(msg2,"");
     strcat(msg2," Turn..");
     outtextxy(430,110,msg2);
   
       } //end whichplayerturn().............

void board()
     {
	settextstyle(4,0,4); setcolor(BLUE);
	setfillstyle(1,GREEN);
	bar3d(30,70,360+10,400+10,20,1);
	setfillstyle(1,GREEN);
	floodfill(60,60,BLUE);
	floodfill(380,80,BLUE);

	setfillstyle(1,WHITE);
	bar(40,80,140,180);
	bar(150,80,250,180);
	bar(260,80,360,180);
	outtextxy(40+50-5,80+50-20,getstring(box[1]));
	outtextxy(195,110,getstring(box[2]));
	outtextxy(305,110,getstring(box[3]));
	bar(40,190,140,290);
	bar(150,190,250,290);
	bar(260,190,360,290);
	outtextxy(85,220,getstring(box[4]) );
	outtextxy(195,220,getstring(box[5]));
	outtextxy(305,220,getstring(box[6]));
	bar(40,300,140,400);
	bar(150,300,250,400);
	bar(260,300,360,400);
	outtextxy(85,330,getstring(box[7]));
	outtextxy(195,330,getstring(box[8]));
	outtextxy(305,330,getstring(box[9]));
     } //end of board()...

char* getstring(char a)
    {
      char *s;
      /*
      //itoa(number, string, 10); is used to convert int to string.
      //char *itoa(int value, char *string, int radix);
     // cout<<"value of a:"<<a; getch();
      if(a== 88)
	return "X";   //ascii alt 88 = X
      else
       {
       s=itoa(a,s,2 );
       //	cout<<"s: "<<s;
       //	cout<<"under getstring()..."; getch();
	return s;
	*/

       switch(a)
	{
	  case '0': s="0"; break;
	  case 'X': s="X"; break;
	  case '1': s="1"; break;
	  case '2': s="2"; break;
	  case '3': s="3"; break;
	  case '4': s="4"; break;
	  case '5': s="5"; break;
	  case '6': s="6"; break;
	  case '7': s="7"; break;
	  case '8': s="8"; break;
	  case '9': s="9"; break;
	 }//end switch...
	 return s;
}//end getstring()..

void scorescreen()
      {
	 cleardevice();
	 setbkcolor(LIGHTBLUE);
	 heading("Score Board");
	 settextstyle(2,0,5);
	 setcolor(WHITE);
	 ifstream ifs;
	 ifs.open("scores.txt",ios::in);
	 char line[200]; int i=0;
	  int serialno=0;
	  char msg[205]="";

	 if(ifs == NULL || ifs.eof() != 0)
	  {
	    outtextxy(20,80,"None Played. No Scores....");
	    goto closingfilelabel;
	  } //end if.
	  while(ifs.eof() == 0)
	   {
	      delay(100);
	      ifs.getline(line,200);
	      if(strcmp(line,"") == 0) continue;
	      sprintf(msg,"%d.) %s",++serialno,line);
	      outtextxy(20, 80+i, msg);
	      i=i+20;
	   } //end while...

	   closingfilelabel:
	   ifs.close();
	   backbutton(); //show back button at left bottom area..


} //end scorescreen()...........
void helpscreen()
     {
	cleardevice(); setbkcolor(LIGHTBLUE);
	heading("HELP...");
	setcolor(WHITE);
	outtextxy(20,80,"Tic Tac Toe is a simple game. ");
	outtextxy(20,120,"1. The game is played on a grid that's 3 squares by ");
	outtextxy(20,145,"   3 squares.");
	outtextxy(20,180,"2. You are 'X' and your friend is 'O'. Players take ");
	outtextxy(20,205,"   turns putting their marks in grids.");
	outtextxy(20,240,"3. The first player to get 3 of her marks in a row");
	outtextxy(20,265,"   (up, down, across, or diagonally) is the winner.");
	outtextxy(20,300,"4. When all 9 squares are filled, the game is over.");
	outtextxy(20,325,"   If no player has 3 marks in a row, the game ");
	outtextxy(20,345,"   ends in a tie.");
	backbutton();
     } //end helpscreen()................
void aboutscreen()
     {
	cleardevice(); setbkcolor(LIGHTBLUE);
	heading("ABOUT....");
	setcolor(WHITE);
	//graph();
	outtextxy(20,90,"This interactive and strategic game allows you to ");
	outtextxy(20,130,"engage in friendly matches with a friend. Enjoy the");
	outtextxy(20,170,"thrill of outsmarting your opponent and achieving");
	outtextxy(20,210,"victory in this timeless contest of Xs and Os");
	outtextxy(20,360,"Designed and created by Bhumika Jain.");
	backbutton();
     } //end aboutscreen()..................

void inputnamescreen()
     {
       cleardevice();
       setbkcolor(LIGHTBLUE);

       outtextxy(60,60,"Enter First Player Name: ");
       gotoxy(10,8);
       fflush(stdin); gets(firstplayername); fflush(stdin);
       setfillstyle(1,LIGHTBLUE);
       bar(60,60,400,90); //hide prev. msg.
       outtextxy(60,60,"Enter Second Player Name: ");
       gotoxy(10,10);
       fflush(stdin); gets(secondplayername); fflush(stdin);
       sleep(1);
       cleardevice();
       menuscreen(); //must call it else infinite loop.....

     } //end inputnamescreen()...............

void backbutton()
     {
       setfillstyle(1,WHITE);
       bar3d(20,440,120,475,5,1);
       settextstyle(1,0,2);
       setcolor(LIGHTBLUE);
       outtextxy(20,440,"  BACK  ");
       initmouse(); showmouse();
	while(1)
	 {
	   getmouse();
	   if(px>=10&&px<=120&&py>=450&&py<=475&&click==1)
	     {
	       hidemouse(); menuscreen(); break;
	     } //end if...

	 } //end while...

     }//end  backbutton()......
void exitgame()
     {
       cleardevice();
       closegraph();
       exit(0);
     }
void resetboxes()
     {
       box[0]='0';
       box[1]='1';
       box[2]='2';
       box[3]='3';
       box[4]='4';
       box[5]='5';
       box[6]='6';
       box[7]='7';
       box[8]='8';
       box[9]='9';
       box[10]=NULL;
}//end resetboxes()..

char* combineplayernames()
   {
       char *str;
       strcpy(str,""); //clear it.
       strcat(str,"   ");
       strcat(str,firstplayername);
       strcat(str," : X");
       strcat(str,"   ");
       strcat(str,secondplayername);
       strcat(str," : 0");
       strcat(str,"");
       return str;
} //end combineplayernames()..

void heading(char label[70])
   {
      setfillstyle(SOLID_FILL,WHITE);
      bar3d(220,40,220+200,40+30,5,1);
			//depth,topflag.. 0 means no top else yes to top.
      settextstyle(1,0,3); setcolor(BLUE);// setbkcolor(CYAN);

      outtextxy(220+20,40,label);
    //  cout<<"value of lable: "<<label;
}//end heading()..

void  graph()      //temp code for xy axis........................
  {
    int x; //  x axis..
    int y; //  y axis..
    int i; //  loop..
    char xsg[10]; // x coordinate msg.
    char ysg[10]; // y coordinate msg.
    setbkcolor(DARKGRAY);
    settextstyle(2,0,2);

    for(x=0,y=0;x<=639;x=x+20,y=y+20)
      {
	//for x axis....
	setcolor(WHITE);
	line(x,0,x,479);
	sprintf(xsg,"%d",x);
	outtextxy(x+2,0,xsg);

	//for y axis...
	setcolor(WHITE);
	line(0,y,639,y);
	sprintf(ysg,"%d",y);
	outtextxy(0+2,y+1,ysg);

	// red color for x axis..
	setcolor(RED);
	line(x+10,0+10,x+10,479);
	line(0+10,y+10,639,y+10); //for y axis..

       } //end for..


}//end graph()............................................................................

void startgraph()
   {
   //request for autodetection...
   int gd = DETECT, gm, errcode;
    //intialize graphics system.
    initgraph(&gd, &gm, "c:\\tc\\bgi");
     delay(100); //to avoid flicker at begin..
    //read result of initialization.
    errcode = graphresult();
     if(errcode != grOk) //some error...
       {
	 cout<<"Graphics err msg: "<<grapherrormsg(errcode)<<endl;
	 getch();
	  exit(1); //terminate code...
       } //end if...

} //end startgraph()...

    //mouse functions...
void initmouse()
     {
	in.x.ax=0;
	int86(51,&in,&out);
	delay(50);
}//end initmouse()...
void showmouse()
       {
	setmouse(); //must setmouse() 1st time.. to avoid
	//trouble for automatic left click somewhere..

	      in.x.ax=1;
	      int86(51,&in,&out);
	      //click =0; //reset to 0 else troubles alot..
}

void getmouse()
       {
	       in.x.ax=3;
	       int86(51,&in,&out);
	       click=out.x.bx;
	       px=out.x.cx;
	       py=out.x.dx;
	      delay(50);
}

void hidemouse()
       {
	      //click=0; //reset to 0 trouble alot..
	       //	setmouse();
		  in.x.ax=2;
		 int86(51,&in,&out);

       }

void setmouse( )          //int &px,int &py)
      {
	     in.x.ax= 4;
	    // in.x.cx= 0 ;  //px;
	    // in.x.dx= 0;  // py;
	     in.x.bx= 0;
	     int86(0x33,&in,&out);
      }
