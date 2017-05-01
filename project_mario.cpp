#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include<stdlib.h>

void iMouse(int button, int state, int mx, int my){}
void iMouseMove(int mx, int my){}


int t,timer_control=0;//time
char str[3],score_str[3];
int score=0,score_egg1=0,score_egg2=0,score_egg3=0,score_egg4=0,flag1=1,flag2=1,flag3=1,flag4=1,end_flag=1;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int highest_score = 0, saved_score = 0, instant_score=0;
char file_score_str[4];
char temp[4];
int flush=0;
int d=0,d1=0,d2=0;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.


int death_place=0;
int p=1,pause_l,pause_t,pause_enemy,pause_pipe,pause_life,pause_score;//pause

int sub_window=0,intro=1;
int r_x=500,r_y=50;//running the mario

int j_x = 500, j_y = 50,count=0;//jumping the mario
int i=0,j=0,p_x=1400;
int c_x=1600,c2_x=1400,c3_x=0; //running cloud

int e_y=50,e_x=100,egg=0,count_e=0,e_s=0,e_other=0,e_other2=592,egg2=0,egg3=0;//enemy's co ordinate and control,count_e->jumping enemy,e_s->to show the enemy,egg->to move front and back


int level=0,menu_x=725,menu_y=525,menu_i=0; //menu controlling
int life_count=3;
int f_x[26]={0,50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250};
int p_i2=0,m2;
int bull_x,bull_y=450,bull=0;
int help=0,about=0;


void iDraw()
{
		iClear();
	//level=0 is the menu

	if(level==0)
	{
			if(help==1)
		{
			iShowBMP(0,0,"about.bmp");
			/*iSetColor(0,0,0);
			iText(100,530,"CONTROL:",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,500,"USE 'UP' , 'DOWN', 'LEFT' , 'RIGHT' KEYS TO MOVE THE MARIO",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,470,"PRESS 'F1' TO RETURN, 'P' TO PAUSE,'ENTER' TO PLAY ,'X' TO EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,400,"STRATEGY:",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,370,"AVOID THE  ENEMYS BY JUMPING,CLASHING WITH THEM WILL COST A LIFE",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,340,"AVOID THE BOMB OF THE PLANE,AVOID THE BLACK HOLES",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,270,"SCORING:",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,240,"PASSING A PIPE WILL GIVE YOU 5 IN LEVEL ONE,10 IN LEVEL TWO,15 IN LEVEL THREE",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,210,"REMAINIG TIME WILL BE ADDED WITH THE SCORE AFTER THE LEVEL IS COMPLETE",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,100,"PRESS F1 TO RETURN",GLUT_BITMAP_TIMES_ROMAN_24);*/
		}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


		else if(highest_score==1)
		{
		    /*
		    if(flush)
		    {

                FILE *fp;
                fp = fopen("score_file.txt", "r");
                fflush(fp);
                fclose(fp);
		    }
            */



		    iShowBMP(0,0,"highest_score_show.bmp");
			//iSetColor(163, 73, 164);
			//iFilledRectangle(200, 200, 800, 200);
			//iSetColor(128, 0, 64);
			//iText(400, 350, "HIGHEST SCORE :", GLUT_BITMAP_TIMES_ROMAN_24);
			FILE *fp;
			fp = fopen("score_file.txt", "r");
			//fscanf(file_score_str, "%d", fgetc(fp));
			fscanf(fp, "%d", &d);
			//sprintf(file_score_str, "%d", fgetc(fp));

			//fscanf(fp, "%d", &d);
			//fflush(fp);
			fclose(fp);
			//d = fgetc(fp);


			//d = (int)file_score_str;



			d1 = d / 10;
			d2 = d % 10;
			/*
			printf("d %d \n", d);
			printf("d1 %d \n", d1);
			printf("d2 %d \n", d2);*/


			//d1 = file_score_str[0] - 48;
			//d2 = file_score_str[1] - 48;

			if (d1 == 0)iShowBMP(850, 150, "digit_0.bmp");
			else if(d1 ==  1)iShowBMP(850,150, "digit_1.bmp");
			else if (d1 == 2)iShowBMP(850, 150, "digit_2.bmp");
			else if (d1 == 3)iShowBMP(850, 150, "digit_3.bmp");
			else if (d1 == 4)iShowBMP(850, 150, "digit_4.bmp");
			else if (d1 == 5)iShowBMP(850, 150, "digit_5.bmp");
			else if (d1 == 6)iShowBMP(850, 150, "digit_6.bmp");
			else if (d1 == 7)iShowBMP(850, 150, "digit_7.bmp");
			else if (d1 == 8)iShowBMP(850, 150, "digit_8.bmp");
			else if (d1 == 9)iShowBMP(850, 150, "digit_9.bmp");


			if (d2 == 0)iShowBMP(960, 150, "digit_0.bmp");
			else if (d2 == 1)iShowBMP(960, 150, "digit_1.bmp");
			else if (d2 == 2)iShowBMP(960, 150, "digit_2.bmp");
			else if (d2 == 3)iShowBMP(960, 150, "digit_3.bmp");
			else if (d2 == 4)iShowBMP(960, 150, "digit_4.bmp");
			else if (d2 == 5)iShowBMP(960, 150, "digit_5.bmp");
			else if (d2 == 6)iShowBMP(960, 150, "digit_6.bmp");
			else if (d2 == 7)iShowBMP(960, 150, "digit_7.bmp");
			else if (d2 == 8)iShowBMP(960, 150, "digit_8.bmp");
			else if (d2 == 9)iShowBMP(960, 150, "digit_9.bmp");





			//iText(970, 160, file_score_str, GLUT_BITMAP_TIMES_ROMAN_24);
			//iText(440, 280," Press 'C' to clear all record  ", GLUT_BITMAP_TIMES_ROMAN_24);


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>..>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.


        }


			else if(about)
		{
			iShowBMP(100,380,"masum.bmp");
			iShowBMP(900,380,"moyeen.bmp");
			iSetColor(0,500,120);
			iText(100,300,"HELLOW EVERYONE. WE ARE FAZLAY RABBI MASUM AND MOYEEN UDDIN",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,260,"STUDENT OF DEPARTMENT OF CSE'12,BUET",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,220,"THIS GAME WAS MADE AS A TERM PROJECT OF LEVEL-1,TERM-2",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,150,"THIS WAS SUPERVISED BY: ",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,110,"ANINDYA IQBAL SIR,LECTURER,DEPARTMENT OF CSE,BUET",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(100,40,"ENJOY PLAYING :)",GLUT_BITMAP_TIMES_ROMAN_24);

		}
		else
		{
		iShowBMP(0,0,"back1.bmp");
		iShowBMP(menu_x,menu_y,"menu.bmp");
		if(intro==1)
		{
			iShowBMP(400,300,"intro_a.bmp");
			iShowBMP(400,400,"intro_jump2.bmp");
		}
		else
		{
			iShowBMP(400,300,"introb.bmp");
			iShowBMP(400,400,"intro_jump.bmp");
		}
			}
	}

	else
	{
		int loop,l_con=100;

		//iFilledRectangle(0,50,1200,550);//background

		//iShowBMP(0,50,"back.bmp");
		iShowBMP(250,450,"moon.bmp");

		iSetColor(255,255,255);
		for(loop=0;loop<7;loop++,l_con=l_con+230)
		{
			iPoint(l_con,450,1);
		}

		l_con=190;
			for(loop=0;loop<7;loop++,l_con=l_con+270)
		{
			iPoint(l_con,550,1);
		}

			l_con=220;
			for(loop=0;loop<7;loop++,l_con=l_con+300)
		{
			iPoint(l_con,500,1);
		}

			l_con=20;
			for(loop=0;loop<10;loop++,l_con=l_con+180)
		{
			iPoint(l_con,400,1);
		}
			l_con=50;
			for(loop=0;loop<10;loop++,l_con=l_con+190)
		{
			iPoint(l_con,350,1);
		}

			l_con=10;
			for(loop=0;loop<10;loop++,l_con=l_con+250)
		{
			iPoint(l_con,340,1);
		}

			l_con=400;
			for(loop=0;loop<5;loop++,l_con=l_con+290)
		{
			iPoint(l_con,525,1);
		}
			l_con=20;
			for(loop=0;loop<10;loop++,l_con=l_con+190)
		{
			iPoint(l_con,270,1);
		}
			l_con=50;
			for(loop=0;loop<10;loop++,l_con=l_con+220)
		{
			iPoint(l_con,250,1);
		}

		iSetColor(94,41,201);
		iFilledRectangle(p_x+5600,50,20,80);//ending flag


		iShowBMP(c_x,530, "plane.bmp");
		iShowBMP(c2_x,490, "plane.bmp");
		iShowBMP(c3_x,420, "plane2.bmp");
		if(bull==1)
		{
			iShowBMP(bull_x,bull_y, "bullet.bmp");
		}

		iSetColor(0,500,120);
		iText(110,512,str,GLUT_BITMAP_TIMES_ROMAN_24);//showing the time
		iText(110,542,score_str,GLUT_BITMAP_TIMES_ROMAN_24);//showing score

		iSetColor(80,233,5);
		iText(20,570,"LIFE:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,540,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,510,"TIME:",GLUT_BITMAP_TIMES_ROMAN_24);

		int m,p_i=0,m_i=0,e_d=0;

		for(m=0;m<life_count;m++,m_i=m_i+50) iShowBMP(85+m_i,565, "life.bmp");//showing life

		if(e_s==1) iShowBMP(e_x,e_y, "enemy1.bmp");//enemy 1


		if(e_s==1)
		{
			for(m=0,p_i=0;m<4;m++,p_i=p_i+1400)
			{
				iShowBMP(e_other+p_x+68+p_i,e_y, "enemy1.bmp");//showing enemy
			}

			for(m=0,p_i=0;m<4;m++,p_i=p_i+1400)
			{
				iShowBMP(e_other2+p_x+741+p_i,e_y, "enemy1.bmp");//showing enemy
			}
		}


		for(m=0,p_i=0;m<4;m++,p_i=p_i+1400) iShowBMP(p_x+p_i,50, "pipe.bmp"); //showing pipe

		iShowBMP(0,0, "footpath.bmp");//fixed footpath
		for(m=0;m<25;m++) 	iShowBMP(f_x[m],0, "footpath.bmp");//changable footpath

		iSetColor(0,0,0);

		for(m=0,p_i=0;m<4;m++,p_i=p_i+1400) iFilledRectangle(p_x+p_i+591,0,150,50);//black footpath


		if(i==7) iShowBMP(500, j_y, "run1.bmp");

		else if(i==0) iShowBMP(r_x, r_y, "run1.bmp");
		else if(i==1) iShowBMP(r_x, r_y, "run2.bmp");
		else if(i==2) iShowBMP(r_x, r_y, "run3.bmp");

		else if(i==3) iShowBMP(r_x, r_y, "brun1.bmp");
		else if(i==4) iShowBMP(r_x, r_y, "brun2.bmp");
		else if(i==5) iShowBMP(r_x, r_y, "brun3.bmp");

		else if (i == 6) iShowBMP(j_x, j_y, "run1.bmp");
		else if (i == 8) iShowBMP(j_x, j_y, "brun1.bmp");

		if(death_place==0)
		{
		if(i==9) iShowBMP(500, 50, "dead1.bmp");
		else if(i==10) iShowBMP(500, 50, "dead2.bmp");
		else if(i==11) iShowBMP(500, 50, "dead3.bmp");
		else if(i==12) iShowBMP(500, 50, "dead4.bmp");

		else if(i==13) iShowBMP(500, 50, "dead5.bmp");
		else if(i==14) iShowBMP(500, 50, "dead6.bmp");
		else if(i==15) iShowBMP(500, 50, "dead7.bmp");
		else if(i==16) iShowBMP(500, 50, "dead8.bmp");
		}
		else if(death_place==1)
		{
				if(i==9) iShowBMP(550, 0, "dead1.bmp");
		else if(i==10) iShowBMP(550, 0, "dead2.bmp");
		else if(i==11) iShowBMP(550, 0, "dead3.bmp");
		else if(i==12) iShowBMP(550, 0, "dead4.bmp");

		else if(i==13) iShowBMP(550, 0, "dead5.bmp");
		else if(i==14) iShowBMP(550, 0, "dead6.bmp");
		else if(i==15) iShowBMP(550, 0, "dead7.bmp");
		else if(i==16) iShowBMP(550, 0, "dead8.bmp");
		}


		if(sub_window==1 && life_count!=0)
		{
				iSetColor (163,73,164);
				iFilledRectangle(200,200,800,200);
				iSetColor(128,0,64);
				iText(530,350,"LIFE LOST!!",GLUT_BITMAP_TIMES_ROMAN_24);
				iText(460,300,"PRESS 'ENTER' TO CONTINUE !!",GLUT_BITMAP_HELVETICA_18);
		}

		else if(life_count==0)
		{
				iSetColor (163,73,164);
				iFilledRectangle(200,200,800,200);
				iSetColor(128,0,64);
				iText(520,350,"GAME OVER!!",GLUT_BITMAP_TIMES_ROMAN_24);
				iText(500,300,"YOUR SCORE IS  ",GLUT_BITMAP_HELVETICA_18);
				iText(680,300,score_str,GLUT_BITMAP_HELVETICA_18);
		}






//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		else if(life_count==0||sub_window==0)
		{
                instant_score=atoi(score_str);
				FILE *fp;
				fp=fopen("score_file.txt", "r");
				fscanf(fp,"%d",&saved_score);
				//saved_score=(int)fgetc(fp);
				//sprintf(file_score_str, "%d", fgetc(fp));
				//saved_score=(int)file_score_str;
				fclose(fp);


				if (instant_score > saved_score)
				{
                    FILE *fp;
                    fp=fopen("score_file.txt", "w");
				    saved_score=instant_score;
				    //fprintf(fp, "%d", saved_score);
				    fprintf(fp, "%d" , instant_score);
				    fclose(fp);
					//fputc(saved_score,fp);
				}
			    //d = fgetc(fp);
                //printf("save: %d", saved_score);


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		}
		else if(sub_window==2)
		{
				iSetColor (163,73,164);
				iFilledRectangle(200,200,800,200);
				iSetColor(128,0,64);
				iText(520,350,"LEVEL IS CLEAR",GLUT_BITMAP_TIMES_ROMAN_24);
				iText(480,300,"PRESS 'ENTER' FOR NEXT LEVEL  ",GLUT_BITMAP_HELVETICA_18);
		}

	}
}

void iKeyboard(unsigned char key)
{
    /*
    if(key=='c')
    {
        FILE *fp;
        fp = fopen("score_file.txt", "r");
		fflush(fp);
		fclose(fp);

		flush=1;



    else flush=0;
    }
    */
	if(key=='\r')
	{
		p=1;
		death_place=0;
		if(level==0)
		{
			if(menu_i==0)
			{
				level=1;
				t=91;
			}
			else if(menu_i==1)
			{
				level=2;
				t=61;
			}
			else if(menu_i==2)
			{
				level=3;
				t=46;
			}
			else if(menu_i==3)
			{
				help=1;
			}
			else if(menu_i==4)
            {
                highest_score=1;
            }
			else if(menu_i==5) about=1;
			else if(menu_i==6) exit(0);

			e_s=1;
			i=1;
			 //t=0;
			sub_window=0;
			j=0;
			p_x=1400;
			e_y=50;
			e_x=1250;
			count_e=0;
			life_count=3;
			c2_x=1400;
			c_x=1600;
			c3_x=0;
			score_egg1=0;
			score_egg2=0;
			score_egg3=0;
			score_egg4=0;
			flag1=1;
			flag2=1;
			flag3=1;
			flag4=1;
			score=0;
		}

		else
		{

			c2_x=1400;
			bull_y=550;
			c_x=1600;
			c3_x=0;
			if(e_s==0&&life_count!=0&&sub_window!=2)
			{
				e_s=1;
				i=1;
				sub_window=0;
				j=0;
				p_x=1400;
				e_y=50;
				e_x=1250;
				timer_control=0;
				count_e=0;
				if(level==1) t=91;
				else if(level==2) t=61;
				else if(level==3) t=46;
			}

			else if(life_count==0) level=0;//if all lifes are lost then main menu

			else if(sub_window==2) //if level 1 is clear
			{
				level++;
				e_s=1;
				i=1;
			  //t=0;
				sub_window=0;
				j=0;
				if(level==2) t=61;
				else if (level==3) t=46;
				p_x=1400;
				e_y=50;
				end_flag=1;
				e_x=1250;
				count_e=0;
			}
		}
	}
	else if(key == 'x') exit(0);
	else if(key == 'p')
	{
		if(p==0) p=1;
		else p=0;
	}
}

void iSpecialKeyboard(unsigned char key)
{

	 if(key==GLUT_KEY_UP)
	{
		 printf("\a");
		 if(level==0)
		 {
			if(menu_i>0)
			{
				menu_y=menu_y+70;
				if(menu_i==6) menu_y=menu_y+20;
				menu_i--;
			}
		 }

		 else if(e_s==1)
		 {
			j = 1;
		 }

	}

	 else if(key==GLUT_KEY_DOWN)
	 {
		 printf("\a");
		if(level==0)
		{
			if(menu_i<6)
			{
				menu_y=menu_y-70;
				if(menu_i==5) menu_y=menu_y-20;
				menu_i++;
			}

		}
	 }

	else if(key==GLUT_KEY_RIGHT)
	{
		if(p==0) return;
		if(level&&e_s==1)
		{
			//controlling the pipe to stop and run
				if((p_x!=580&&p_x!=580-1400&&p_x!=580-2800&&p_x!=580-4200)||j_y>162)
				{
					p_x=p_x-10;
				}

			// dynamic movement of cloud and enemy
			c_x=c_x-5;
			c2_x=c2_x-2;
			c3_x=c3_x-5;
			e_x=e_x-10;
			bull_x=bull_x-10;

			//movement of footpath
			int k;
			if((p_x!=580&&p_x!=580-1400&&p_x!=580-2800&&p_x!=580-4200)||j_y>162)
			{
				for(k=0;k<25;k++)
				{
					f_x[k]=f_x[k]-10;
					if(f_x[k]==-10) f_x[k]=1250;
				}
			}

			//running the mario
			if (j==0&&i!=7)
				{
				i=i+1;
				if (i>=3) i=0;
			}
		}
	}
	else if(key==GLUT_KEY_LEFT)
	{
		if(p==0) return;

		if(level&&e_s==1)
		{
			//controlling the pipe
				if((p_x!=430&&p_x!=430-1400&&p_x!=430-2800&&p_x!=430-4200)||j_y>120)
			{
				p_x=p_x+10;
			}

			//running the mario
				if (j==0&&i!=7)
					{
						i=i+1;
						if (i>=6) i=3;

					}

			//controlling the footpath
				int k;
				if((p_x!=430&&p_x!=430-1400&&p_x!=430-2800&&p_x!=430-4200)||j_y>120)
				{
					for(k=0;k<25;k++)
					{
						f_x[k]=f_x[k]+10;
						if(f_x[k]>=1260) f_x[k]=0;
					}
				}

			// dynamic movement of cloud and enemy
			c_x=c_x+5;
			c2_x=c2_x+2;
			c3_x=c3_x+5;
			e_x=e_x+10;
			bull_x=bull_x+10;
		}
	}

	else if(key==GLUT_KEY_F1)
	{
		sub_window=0;
		j_x = 500, j_y = 50,count=0;
		i=0,j=0,p_x=1400;
		c_x=1600,c2_x=1500,c3_x=0;
		e_y=50,e_x=1250,egg=0,count_e=0,e_s=0;
		level=0,menu_x=725,menu_y=525,menu_i=0;
		life_count=3;
		help=0;
		about=0;
		highest_score=0;

	}

	/*else if(key==GLUT_KEY_F2)
	{
		pause_l=level;
		pause_t=t;
		pause_enemy=e_x;
		pause_pipe=p_x;
		pause_life=life_count;
		p=0;
		saved_score=score;
		level=0;
	}*/

}

void iscore()
{

		sprintf(score_str,"%d",score);
	if(score_egg1||score_egg2||score_egg3||score_egg4)
	{
		if(level==1) score=score+5;
		else if(level==2) score=score+10;
		else if(level==3) score=score+15;
		sprintf(score_str,"%d",score);
		score_egg1=0;
		score_egg2=0;
		score_egg3=0;
		score_egg4=0;
	}

		if(p_x==450&&flag1==1)
		{
			score_egg1=1;
			flag1=0;
		}
		else if(p_x==450-1400&&flag2==1)
		{
			flag2=0;
			score_egg2=1;
		}
		else if( p_x==450-2800&&flag3==1)
		{
			score_egg3=1;
			flag3=0;
		}
		else if (p_x==450-4200&&flag4==1)
		{
			flag4=0;
			score_egg4=1;
		}

		if(sub_window==2&&end_flag==1)
		{
			end_flag=0;
			score=score+t;
			sprintf(score_str,"%d",score);
		}



}

void run_cloud()
{
	iscore();
	if(sub_window==2)
	{
		score_egg1=0;
		score_egg2=0;
		score_egg3=0;
		score_egg4=0;
		flag1=1;
		flag2=1;
		flag3=1;
		flag4=1;
		p=0;
	}
	if(p==0||level==0||e_x==0||i==12||i==16||sub_window==2) return;

	//controlling the cloud
	c_x=c_x-10;
	c2_x=c2_x-5;
	c3_x=c3_x-5;
	if(c3_x>=3600) c3_x=0;
	if(c_x<=0)c_x=3600;
	if(c2_x<0) c2_x=3000;

}

void jump()
{
	if(p==0) return;

	//jumping the enemy
	if(count_e!=10)
	{
		e_y=e_y+2;
		count_e++;
	}
	else
	{
		e_y=e_y-2;
		if(e_y==50) count_e=0;
	}

	//jumping the mario upwards
	if (j==1&&count!=23)
	{
			j_y=j_y+8;
			count++;
			if(i>=0&&i<=2) i = 6;
			else if (i>=3&&i<=5) i=8;

	}

	//moving on the pipe
	else if(((p_x<=570&&p_x>=440)||(p_x<=570-1400&&p_x>=440-1400)||(p_x<=570-2800&&p_x>=440-2800)||(p_x<=570-4200&&p_x>=440-4200))&&j_y==170)
	{
		i=7;
		j=0;

	}

	//jumping downwards
	else if (j==1&&count==23)
	{
		j_y = j_y - 8;

		if (j_y <=50)
		{
			j = 0;
			if(i>=0&&i<=2) i = 0;
			else if (i>=3&&i<=5) i=3;
			count=0;

		}
	}

	//jumping down from the pipe
	else if((p_x>=570||p_x<=440)&&j_y==170)
	{
		j=1;
		i=0;
	}
}

void time()
{
	if(p==0) return;
	if (t==0||level==0||e_s==0||sub_window==2) return;
		t--;
		if(t==0) timer_control=1;
		sprintf(str,"%d",t);
}


////////////////////////////////////////////////////////////////////level 1
void enemy_level1()
{

	if(level!=1||p==0)
	{
		return;
	}

		/* controlling the enemy 1 in level 1 along x axis.. here egg is the variable which controls the enemy to move right and left*/

		if((e_x>=p_x-1200)&&(egg==0)&&(e_s==1))
		{
			e_x=e_x-10;
			if(e_x<=p_x-1200) egg=1; //moving back
		}

		else if(egg&&e_x<=p_x-50&&e_s==1)
		{
			e_x=e_x+10;
			if(e_x>=p_x-50) egg=0;//moving front
		}

		if(e_other<=500&&egg2==0)
		{
			e_other=e_other+10;
			if(e_other>=500) egg2=1;
		}
		else
		{
			e_other=e_other-10;
			if(e_other<=0) egg2=0;
		}

		if(e_other2<=612&&egg3==0)
		{
			e_other2=e_other2+10;
			if(e_other2>=612) egg3=1;
		}
		else
		{
			e_other2=e_other2-10;
			if(e_other2<=0) egg3=0;
		}


}

/////level 2
void enemy_level2()
{
	if(level!=2||p==0) return;

		/* controlling the enemy 1 in level 1 along x axis.. here egg is the variable which controls the enemy to move right and left*/
	if((e_x>=p_x-1200)&&(!egg)&&(e_s==1))
		{
			e_x=e_x-10;
			if(e_x<=p_x-1200) egg=1; //moving back
		}

	else if(egg&&e_x<=p_x-50&&e_s==1)
		{
			e_x=e_x+10;
			if(e_x>=p_x-50) egg=0;//moving front
		}

	if(e_other<=500&&egg2==0)
		{
			e_other=e_other+10;
			if(e_other>=500) egg2=1;
		}
		else
		{
			e_other=e_other-10;
			if(e_other<=0) egg2=0;
		}

		if(e_other2<=612&&egg3==0)
		{
			e_other2=e_other2+10;
			if(e_other2>=612) egg3=1;
		}
		else
		{
			e_other2=e_other2-10;
			if(e_other2<=0) egg3=0;
		}

}

void enemy_level3()
{
	if(level!=3||p==0) return;

	if((e_x>=p_x-1200)&&(!egg)&&(e_s==1))
		{
			e_x=e_x-10;
			if(e_x<=p_x-1200) egg=1; //moving back
		}

	else if(egg&&e_x<=p_x-50&&e_s==1)
		{
			e_x=e_x+10;
			if(e_x>=p_x-50) egg=0;//moving front
		}
	if(e_other<=500&&egg2==0)
		{
			e_other=e_other+10;
			if(e_other>=500) egg2=1;
		}
		else
		{
			e_other=e_other-10;
			if(e_other<=0) egg2=0;
		}

		if(e_other2<=612&&egg3==0)
		{
			e_other2=e_other2+10;
			if(e_other2>=612) egg3=1;
		}
		else
		{
			e_other2=e_other2-10;
			if(e_other2<=0) egg3=0;
		}

}

void clash()
{
	//clash with the enemy forward

	if(((e_x<=r_x+80&&e_x>=r_x)&&(j_y-e_y<=20)&&e_s!=0))

	{
		i=9;
		e_s=0;////enemy wont run
		life_count--;//life lost
	}
		//clash with the enemy backward
	if((e_x>=r_x-55&&e_x<=r_x)&&(j_y-e_y<=20)&&e_s!=0)
	{
		i=13;
		e_s=0;//enemy wont run
		life_count--;//life lost
	}

	//clash with other enemies forward
		for(m2=0;m2<4;m2++,p_i2=p_i2+1400)
		{
			if(((e_other+p_x+68+p_i2<=r_x+80&&e_other+p_x+68+p_i2>=r_x)||(e_other2+p_x+741+p_i2<=r_x+80&&e_other2+p_x+741+p_i2>=r_x))&&(j_y-e_y<=20)&&e_s!=0)
			{
				i=9;
				e_s=0;////enemy wont run
				life_count--;//life lost
			}
		}
		p_i2=0;

	//into the blackhole forward
		int loop,hole=0;
		for(loop=0;loop<4;loop++,hole=hole+1400)
		{
			if((p_x+hole+591<=r_x+50&&p_x+hole+591>=r_x)&&(j_y==50)&&e_s!=0)
			{
				i=9;
				e_s=0;//enemy wont run
				life_count--;//life lost
				death_place=1;
			}
		}

	hole=0;
	//into the blackhole backward
	for(loop=0;loop<4;loop++,hole=hole+1400)
	{
		if((p_x+hole+591>=r_x-100&&p_x+hole+591<=r_x)&&(j_y==50)&&e_s!=0)
		{
			i=13;
			e_s=0;////enemy wont run
			death_place=1;
			life_count--;//life lost
		}
	}

	//clash with bullet
	if(bull_x<=r_x+75&&bull_x>=r_x&&bull_y<=140&&e_s!=0)
	{
		i=9;
		e_s=0;////enemy wont run
		life_count--;//life lost
	}
	//clash with timer
	if(timer_control==1&&e_s!=0)
	{
		i=9;
		e_s=0;////enemy wont run
		life_count--;//life lost

	}


	if(i>=9&&i<12)
	{
		i++;
		printf("\a");
		if(i==12) sub_window=1;
	}


	if(i>=13&&i<16)
	{
		printf("\a");
		i++;
		sub_window=1;
	}

	//ending level 1
	if(p_x+5600<=500)
	{
		sub_window=2;
	}


}

void introd()
{
	if(intro==0) intro=1;
	else intro=0;
}
void bullet()
{
	if(e_x==0||i==12||i==16||sub_window==2||p==0)
	{
		bull=0;
		return;
	}
		if(c2_x<=800&&c2_x>=680&&bull==0)
	{
		bull_x=800;
		bull_y=450;
		bull=1;
	}
	bull_y=bull_y-10;
	if(bull_y<=0)
	{
		bull_x=800;
		bull=0;
	}
}

int main()
{


	iSetTimer(1,run_cloud);
	iSetTimer(20, jump);
	iSetTimer(100,clash);
	iSetTimer(1000,time);
	iSetTimer(50,enemy_level1);
	iSetTimer(30,enemy_level2);
	iSetTimer(15,enemy_level3);
	iSetTimer(500,introd);
	iSetTimer(50,bullet);
	//else if(level==2) iSetTimer(100,run_enemy);

	iInitialize(1200, 600, "Mario");

	return 0;
}
