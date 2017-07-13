#include<iostream>
#include<cstdlib>
#include<fstream>
#include<time.h>
#include<string>
#include<conio.h>
#include<string.h>
using namespace std;

struct ll{
	char str[15];
	struct ll *next;
}*s,*t,*n;
int newg();
int startf();
int escore=0,hscore=0,hlevel=0,match=0;

int elevel()
{
	int chance;
	system("cls");
	cout<<"\n\t\t\t***EVIL HANGMAN***";
	if(hlevel==1) cout<<"\n\t\t\t\t\t\t\tYOUR SCORE: "<<hscore;
	else cout<<"\n\t\t\t\t\t\t\tYOUR SCORE: "<<escore;
	cout<<"\n\nYOUR WORD IS:  \n\n";
	ifstream fl;
	fl.open("el.txt");
	if(fl.is_open())
	{
		char  tl[15],tline[15],line[15],pline[15];
		srand(time(NULL));
     	int a1=64+rand()%26;
    	char c1;
    	c1=a1;
    	while(fl.getline(line,15))
    	{
    		if(c1==line[0])
    		{
    			match=1;
    			if(s==NULL){
    				n=(struct ll*)malloc(sizeof(struct ll));
    				strcpy(n->str,line);
    				n->next=NULL;
    				s=n;
				}
				else{
					t=s;
					while(t->next!=NULL)
					{
						if(strcmp(n->str,line)==0) break;
						t=t->next;
					}
					if(strcmp(t->str,line)==0) {
					}
					else{
						n=(struct ll*)malloc(sizeof(struct ll));
    				    strcpy(n->str,line);
    				    n->next=NULL;
    				    t->next=n;
				   }}
				    
				   	  if(s->next==NULL||strcmp(t->str,line)!=0){
						 strcpy(tl,line);
						 strcpy(pline,line);
    				     int wl=strlen(line);chance=wl+1;
    			         int i;char ans[wl];
    				     for(i=0;i<wl;i++){
    				    	tl[i]='-';
				        	}
				        		strcpy(tline,line);
				   	     cout<<"   "<<tl<<"\n\n";
					  for(i=0;i<wl+1;i++){
					  int j,result=0;
					  if(chance==0) break;
					  	cin>>ans[i];
						  for(j=0;j<strlen(line);j++){
					  		if(ans[i]==tline[j]){
					  			tline[j]='*';
							  result=1;wl+=1;
					  	tl[j]=ans[i];break;}}
					  	if(result!=1){chance--;
					  	cout<<"\t HAHAHAHA..! LETTER NOT MATCH..HAHA!..\n\n";if(chance!=0) cout<<"\tI WANNA GIVE YOU MORE "<<chance<<" CHANCE..HAHAHAHA!.\n\n";
					  }
					  cout<<"\n"<<tl<<"\n\n";if(strcmp(tl,line)==0) break;
					  }
					  fl.close();
					  fl.open("el.txt");
					  int right=0;
					  while(fl.getline(line,15)){
					  	if(hlevel==1){
					  		if(strcmp(line,tline)==0){ right=1;
						   hscore++;
						   cout<<"\tHMMM...! YOU FIND IT..BUT NEXT TIME,TAKE CARE..HAHAHA!..\n\n";
						   cout<<"\t\tYOUR SCORE IS:  "<<hscore<<"\n\n";getch();
						   elevel();
						  }}
						  else{
					  	   if(strcmp(line,tl)==0){ right=1;
						   escore++;
						   cout<<"\tHMMM...! YOU FIND IT..BUT NEXT TIME,TAKE CARE..HAHAHA!..\n\n";
						   cout<<"\t\tYOUR SCORE IS:  "<<escore<<"\n\n";getch();
						   elevel();
					     }}
					  }
					  if(right==0){ 
					     if(chance<=0) {cout<<"\n\tHAHAHA..!YOU CANT FIND IT..LET ME EAT U!..HAHAHAH! VERY YUMMY..!\n\n";cout<<"MAGIC WORD IS:  "<<pline<<"\n\n\t\t\t******GAME OVER******";
					     cout<<"\t\tYOUR SCORE IS:  ";if(hlevel==1) cout<<hscore;else cout<<escore;getch();
						 return startf(); }
						 
					     }
					  }
					}
			}if(match==0) return elevel();
		}
	else
	  {
	  	system("cls");
	    cout<<"\t\t*EVIL IS SLEEPING COME NEXT TIME..HAHAHAHA!*\n";
	    getch();
	    return newg();}
}

int newg()
{
	int chc;
	system("cls");
	cout<<"\t\tWELCOME NEW PLAYER\n\n";
	cout<<"\t1.EASY LEVEL\n\n";
	cout<<"\t2.HARD LEVEL\n\n";
	cin>>chc;
	if(chc!=1&&chc!=2)
	{
		cout<<"\n\t*INVALID INPUT..TRY AGAIN!\n\n";
		return newg();
	}
	else
	{
		 if(chc==2) hlevel=1;
		 elevel();
	}
}

int abt()
{
	system("cls");
	cout<<"\n\t\t\t***EVIL HANGMAN***\n\n\n";
	cout<<"**INSTRUCTION**\n\nTHIS GAME IS FINDING MISSING LETTERS IN GIVEN WORD\nTHAT WILL IMPROVE YOUR VOCABULARY\nYOU HAVE FOUR CHANCE IF U FIND THOSE LETTERS IN GIVEN ATTEMPTS THEN YOU WILL WIN\nELSE AN EVIL HANGMAN WILL EAT YOU AND U LOST";
	cout<<"\n\n\t\t*MADE BY *\n\n\t\tPIN2 SHARMA";
	cout<<"\n\n*FOR FEEDBACK AND MORE GAMES MAIL ME ON:  pin2sharma248@gmail.com";
	cout<<"\n\n\t\t\t**THANK YOU!**";getch();
	return startf();
}
int startf()
{
	int choice;
	system("cls");
	cout<<"\t\t\t***WELCOME TO EVIL HANGMAN***\n\n\n";
	cout<<"\t1.START NEW GAME\n\n";
	cout<<"\t2.ABOUT(&)\n\n";
	cout<<"\t0.QUIT\n\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			newg();
			break;
		case 2:
			abt();
			break;
		default:
			cout<<"\t\tTHANKS FOR PLAYING THIS GAME\n";
			return 0;
	}
}
main()
{
	startf();
}
