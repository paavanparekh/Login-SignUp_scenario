//Author : Paavan Parekh && Param Parekh
//date of publishing : 7 aug. 2020
//learn : A good project today is better than best project tomorrow

/*************************Topics covered******************************/
//C++ graphics
//Mouse handling
//File handling in C++
//Modulo programming
//Before going to see the code, please read project manual(ReadMe.md)  
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<string>
#include<ctype.h>
#include<fstream>
using namespace std;
void SignIn_working();
/************ Graphics Part ************/
bool IsOnBox(int left,int top,int right,int bottom,POINT &cursor)
{
	return ((cursor.x>=left && cursor.x<=right) && (cursor.y>=top && cursor.y<=bottom) );
}
void back_button(int left,int top,int right,int bottom)
{
	setcolor(15);
	setfillstyle(SOLID_FILL,4);
	rectangle(left,top,right,bottom);
	floodfill(left+1,top+1,15);
	settextstyle(9,0,1.5);
	outtextxy(left+12,top+12,(char*)"BACK");
}
void MainBox()
{
	setcolor(15);
	setfillstyle(SOLID_FILL,9);
	rectangle(100,80,400,400);
	floodfill(101,101,15);
	setfillstyle(SOLID_FILL,4);
	rectangle(100,80,400,115);
	floodfill(101,101,15);
}
void MainBox_signup()
{
	setcolor(15);
	setfillstyle(SOLID_FILL,9);
	rectangle(100,80,500,500);
	floodfill(101,101,15);
	setfillstyle(SOLID_FILL,4);
	rectangle(100,80,500,115);
	floodfill(101,101,15);
}
string text_read_password(int x,int y)
{
	char ch[2]=" ";
	string str="";
	int i=1;
	while(1)
	{
	 fflush(stdin);
	 ch[0]=getch();
	 if(ch[0]=='\r')
	 break;
	   setcolor(15);
	   
	   outtextxy(x + i,y,(char*)"*");
	   str=str+ch[0];
	   i+=12;
	   delay(5);	
	}
	return str;
}
string text_read(int x,int y)
{
	char ch[2]=" ";
	string str="";
	int i=0;
	while(1)
	{
     fflush(stdin);
	 ch[0]=getch();
	 if(ch[0]=='\r')
	 break;
	   setcolor(15);
	   
	   outtextxy(x + i,y,ch);
	   str=str+ch[0];
	   i+=15;
	   delay(3);	
	}
	return str;
}
 void SignInGraphic()
 {
 	MainBox();
	settextstyle(9,0,3);
	setcolor(3);
    outtextxy(210,85,(char*)"Sign In");
    settextstyle(9,0,1.5);
    setcolor(10);
    outtextxy(108,180,(char*)"UserName");
    outtextxy(108,220,(char*)"Password ");
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(250,180,385,200);
    floodfill(251,181,0);
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(250,220,385,240);
    floodfill(251,221,0);
    setcolor(10);
    outtextxy(200,259,(char*)"Forgot Password?");
    setcolor(0);
    setfillstyle(SOLID_FILL,7);
    rectangle(200,330,300,370);
    floodfill(201,331,0);
    setcolor(3);
    outtextxy(215,340,(char*)"LogIn");
    setcolor(5);
    outtextxy(100,410,(char*)"New User?Create Account");
   
 }
void SignUpGraphic()
{
	MainBox_signup();
	settextstyle(9,0,3);
	setcolor(3);
    outtextxy(250,85,(char*)"Sign Up");
    settextstyle(9,0,1.5);
    setcolor(10);
    outtextxy(108,180,(char*)"UserName");
    outtextxy(108,220,(char*)"Password ");
    outtextxy(108,260,(char*)"Email-Id ");
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(250,180,385,200);
    floodfill(251,181,0);
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(250,220,385,240);
    floodfill(251,221,0);
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(250,260,490,280);
    floodfill(251,261,0);
    setcolor(0);
    setfillstyle(SOLID_FILL,7);
    rectangle(230,330,330,370);
    floodfill(231,331,0);
    setcolor(9);
    outtextxy(234,340,(char*)"Sign Up");
    back_button(230,530,330,570);
    
}
void forgotPasswordGraphic()
{
    MainBox();
	settextstyle(9,0,3);
	setcolor(3);
    outtextxy(138,85,(char*)"Forgot Password");
    settextstyle(9,0,1);
    setcolor(10);
    outtextxy(108,180,(char*)"Username");
    outtextxy(108,220,(char*)"Password");
    outtextxy(108,260,(char*)"Confirm");
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(250,180,385,200);
    floodfill(251,181,0);
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(250,220,385,240);
    floodfill(251,221,0);
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(250,260,385,280);
    floodfill(251,261,0);
    setcolor(0);
    setfillstyle(SOLID_FILL,7);
    rectangle(200,330,300,370);
    floodfill(201,331,0);
    setcolor(9);
    outtextxy(208,340,(char*)"Change");
    back_button(200,450,300,490);
 
 
 }
 /*******Oops part*****************/
 struct Client
 {
 	string Username,Password,Emailid;
 };
 /*********Operating functions*********/
bool IsValid_username(string _username)
{
    if(_username=="")
     return 0;
	if(_username.length()>8)
	return 0;
	for(int i=0;i<_username.length();i++)
	{
		if(isspace(_username[i]))
		 return 0;
	}
	return 1;
}
bool IsValid_password(string _password)
{
	int i1=0,i2=0,i3=0,i4=0;

	if(_password.length()>8)
	return 0;
  for(int i=0;i<_password.length();i++)
  {
    if(_password[i]>=65 && _password[i]<=90)
    i1++;
	else if(_password[i]>=97 && _password[i]<=122)
    i2++;
    else if(_password[i]>=48 && _password[i]<=57)
    i3++;
    else
    i4++;
  }	
  if(i1==0 || i2==0 || i3==0 ||i4==0)
  return 0;
  else 
  return 1;
}
bool Is_there_emailid(string emailid)
{
	ifstream Fp("userdata.txt");
   struct Client c2;
   
   while(Fp>>c2.Username>>c2.Password>>c2.Emailid)
   {
   	      if(c2.Emailid==emailid)
   	         return 1;
   }
   Fp.close();
    return 0;
}
bool Is_there_password(string _password)
{

   ifstream Fp("userdata.txt");
   struct Client c2;
   
   while(Fp>>c2.Username>>c2.Password>>c2.Emailid)
   {
   	      if(c2.Password==_password)
   	         return 1;
   }
   Fp.close();
    return 0;
}
bool IsValid_Emailid(string emailid)
{
	int i1=0,i2=0;
	if(emailid=="")
	return 0;
	for(int i=0;i<emailid.length();i++)
	{
		if(emailid[i]=='.')
		i1++;
		else if(emailid[i]=='@')
		i2++;
	}
	if(i1>=1 && i2==1)
	return 1;
	else
	return 0;
	
}
bool Is_same(string _password,string _confirm)
{
	return (_password==_confirm);
}
bool Is_there_username(string _username)
{
   ifstream Fp("userdata.txt");
   struct Client c2;
   
   while(Fp>>c2.Username>>c2.Password>>c2.Emailid)
   {
   	      if(c2.Username==_username)
   	         return 1;
   }
   Fp.close();
    return 0;	
}
void change_Password(string _username,string _password)
{
    Client c;
    int pos=0;
    ofstream Fp("temp.txt");
    ifstream fp("userdata.txt");
	 while(fp>>c.Username>>c.Password>>c.Emailid)
	 {
	 	 if(c.Username!=_username)
	 	    Fp<<c.Username<<" "<<c.Password<<"  "<<c.Emailid<<endl;
	 	 else
		    Fp<<c.Username<<" "<<_password<<" "<<c.Emailid<<endl; 
    }
	 fp.close();
	 Fp.close();
	 remove((const char*)"userdata.txt");
	 rename((const char*)"temp.txt",(const char*)"userdata.txt");
}
void Error_Message(int no)
{
	
	switch(no)
	{
		case 1:
			{
				setcolor(4);
				outtextxy(250,180,(char*)"                    ");
				outtextxy(100,600,(char*)"Invalid username.Reenter it");
				delay(2000);
				outtextxy(100,600,(char*)"                                                       ");
				fflush(stdin);
				break;
			}
	   case 2:
	        {
	   	        setcolor(4);
	   	        outtextxy(250,220,(char*)"                    ");
				outtextxy(100,600,(char*)"Invalid password.Reenter it");
				delay(2000);
				outtextxy(100,600,(char*)"                                                        ");
				fflush(stdin);
				break;
			}
	  case 3:
	       {
	       	    setcolor(4);
	       	    outtextxy(250,180,(char*)"                    ");
				outtextxy(250,220,(char*)"                    ");
				outtextxy(100,600,(char*)"       User not found        ");
				delay(2000);
				outtextxy(100,600,(char*)"                                 ");
				fflush(stdin);
				break;
	       }
	 case 4:
	 {
	 	        setcolor(4);
	   	        outtextxy(250,260,(char*)"                                                    ");
				outtextxy(100,600,(char*)"Invalid EmailId.ReEnter it");
				delay(2000);
				outtextxy(100,600,(char*)"                                                       ");
				fflush(stdin);
				break;
	 } 
	 case 5:
	 {
	 	        setcolor(4);
	       	    outtextxy(250,220,(char*)"                    ");
				outtextxy(250,260,(char*)"                    ");
				outtextxy(100,600,(char*)"Passwords are not same.ReEnter it");
				delay(2000);
				outtextxy(100,600,(char*)"                                                    ");
				fflush(stdin);
				break;     
     } 	
     case 6:
     	{
     		    setcolor(4);
	       	    outtextxy(250,180,(char*)"                    ");
				outtextxy(250,220,(char*)"                    ");
				outtextxy(250,260,(char*)"                    ");
				outtextxy(100,600,(char*)"       User not found              ");
				delay(2000);
				outtextxy(100,600,(char*)"                                                      ");
				fflush(stdin);
				break;     
		}
    case 7:
	   {
		        setcolor(4);
				outtextxy(250,180,(char*)"                    ");
				outtextxy(100,600,(char*)"username exists.Reenter it");
				delay(2000);
				outtextxy(100,600,(char*)"                                                      ");
				fflush(stdin);
				break;
	   } 
	   case 8:
	   {
	   	        setcolor(4);
				outtextxy(250,260,(char*)"                                  ");
				outtextxy(100,600,(char*)"Emailid exists.Reenter it");
				delay(2000);
				outtextxy(100,600,(char*)"                                                    ");
				fflush(stdin);
				break;
	   }
	   case 9:
	   {
	   	        setcolor(4);
				//outtextxy(250,260,(char*)"                    ");
				outtextxy(100,600,(char*)"Enter valid username/password/Email-id...");
				delay(2000);
				outtextxy(100,600,(char*)"                                                                      ");
				fflush(stdin);
				break;
	   }		
	}
}
void welcome()
{
	int x=getmaxx();
	int y=getmaxy();
	setactivepage(2);
	setfillstyle(SOLID_FILL,9);
	rectangle(100,100,x-100,y-100);
	floodfill(101,201,15);
	setcolor(15);
	settextstyle(9,0,5);
	outtextxy(x/2-130,y/2-100,(char*)"WELCOME");
	back_button(x-201,110,x-101,155);
	setvisualpage(2);
	while(1)
	{
		POINT cursor;
		GetCursorPos(&cursor);
		if(IsOnBox(x-201,110,x-101,155,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			
		    setactivepage(1);
		    cleardevice();
		    SignInGraphic();
		    setvisualpage(1);
		    SignIn_working();
			
		}
		delay(3);
	}
	getch();
	closegraph();
}
void initgraphic(int x,int y)
{
	initwindow(x,y);
	setactivepage(1);
	cleardevice();
	SignInGraphic();
	setvisualpage(1);
}
void Put_there(string _username,string _password,string _emailid)
{
	ofstream fp("userdata.txt",ios::app);
	fp<<_username<<" "<<_password<<" "<<_emailid<<endl;
	fp.close();
}
void SignUp_working()
{
	string _username,_password,_emailid;//error of the year 
	POINT cursor;
	while(1)
	{
       GetCursorPos(&cursor);
	   if(IsOnBox(250,180,385,200,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
		    _username=text_read(250,180);
		    if(!IsValid_username(_username))
			Error_Message(1);  //1 -- Invalid username
			if(Is_there_username(_username))
			Error_Message(7);//7-- if username exist
		}
		else if(IsOnBox(250,220,385,240,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
		
			_password=text_read(250,220);
		    if(!IsValid_password(_password))
			Error_Message(2); // 2-- invalid password
		}
		else if(IsOnBox(250,260,385,280,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			_emailid=text_read(250,260);
			if(!IsValid_Emailid(_emailid))
			Error_Message(4);  //4--invalid emailid
			if(Is_there_emailid(_emailid))
			Error_Message(8);
			
		}
		else if(IsOnBox(200,330,300,370,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			outtextxy(250,180,(char*)"                    ");
			outtextxy(250,220,(char*)"                    ");
			outtextxy(250,260,(char*)"                                  ");
			if(Is_there_emailid(_emailid) || Is_there_username(_username))
			   Error_Message(9);
			else if(IsValid_username(_username) && IsValid_password(_password) && IsValid_Emailid(_emailid))
			{
				Put_there(_username,_password,_emailid);
			    welcome();
			}
			else if(!IsValid_username(_username) && !IsValid_password(_password) && !IsValid_Emailid(_emailid))
			     Error_Message(9);
			else if(!IsValid_username(_username))
			    Error_Message(1);
			else if(!IsValid_password(_password))
			    Error_Message(2);
			else if(!IsValid_Emailid(_emailid))
			    Error_Message(4);
			
		}
		else if(IsOnBox(230,530,330,570,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			setactivepage(1);
			cleardevice();
			SignInGraphic();
		    setvisualpage(1);
		    SignIn_working();
		}
		delay(3);
    }
}
void Forgotpassword_working()
{
	string _username,_password,_confirm;//error of the year 
	POINT cursor;
	while(1)
	{
       GetCursorPos(&cursor);
	   if(IsOnBox(250,180,385,200,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
		    _username=text_read(250,180);
		    if(!IsValid_username(_username))
			Error_Message(1);  //1 -- Invalid username
		}
		else if(IsOnBox(250,220,385,240,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
		
			_password=text_read_password(250,220);
		    if(!IsValid_password(_password))
			Error_Message(2); // 2-- invalid password
		}
		else if(IsOnBox(250,260,385,280,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			_confirm=text_read_password(250,260);
			if(!Is_same(_password,_confirm))
			Error_Message(5);// 5--> if both are not same
		}
		else if(IsOnBox(200,330,300,370,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			if(!Is_there_username(_username))
			Error_Message(6);
			else
			{
			change_Password(_username,_password);
			welcome();
			}
			
		}
		else if(IsOnBox(200,450,300,490,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			setactivepage(1);
			cleardevice();
			SignInGraphic();
		    setvisualpage(1);
		    SignIn_working();
		}
		delay(3);
}
}
void SignIn_working()
{
	
	string _username,_password;//error of the year 
	POINT cursor;
	while(1)
	{
       GetCursorPos(&cursor);
	   if(IsOnBox(250,180,385,200,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
		    _username=text_read(250,180);
		    if(!IsValid_username(_username))
			Error_Message(1);  //1 -- Invalid username
		}
		else if(IsOnBox(250,220,385,240,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
		
			_password=text_read_password(250,220);
		    if(!IsValid_password(_password))
			Error_Message(2); // 2-- invalid password
		}
		else if(IsOnBox(200,330,300,370,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			cout<<_username<<" "<<_password<<endl;
			if(Is_there_username(_username) && Is_there_password(_password))
			{
			  outtextxy(250,180,(char*)"                    ");
			  outtextxy(250,220,(char*)"                    ");
			  welcome();	
			}
			
			else
			Error_Message(3);//  3-- user not found
		}
		else if(IsOnBox(100,410,300,430,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			setactivepage(3);
			cleardevice();
			SignUpGraphic();
			setvisualpage(3);
		    SignUp_working();
		}
		else if(IsOnBox(200,259,300,300,cursor) && GetAsyncKeyState(VK_LBUTTON))
		{
			setactivepage(4);
			cleardevice();
			forgotPasswordGraphic();
			setvisualpage(4);
			Forgotpassword_working();
		}
	delay(3);
}
}
/******************main()******************/
 int main()
{
    initgraphic(1000,1000);
    clearmouseclick(WM_LBUTTONDOWN);
    SignIn_working();
	getch();
	closegraph();
}
