#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;
int main()
{
	srand(time(0));
	
	char w1[]={'p','r','o','g','r','a','m','e','r','\0'};
	char w2[]={'s','o','l','u','t','i','o','n','\0'};
	char w3[]={'t','r','o','j','a','n','\0'};
	
	int s; //For size of to be guessed array 
	char tbg[10]={' '};  //To keep final word to be gussed
	
	int result= rand()%3;
	
	//cout<<"Random Number is: "<<result<<endl;   //for testing
	
	if(result==0)
	{
		for(int i=0;i<sizeof(w1);i++)
		{
			tbg[i]=w1[i];
		}
		s=sizeof(w1);
	
	}
	else if(result==1)
	{
		for(int i=0;i<sizeof(w2);i++)
		{
			tbg[i]=w2[i];
		}
		s=sizeof(w2);
	
	}
	else if(result==2)
	{
		for(int i=0;i<sizeof(w3);i++)
		{
			tbg[i]=w3[i];
		}
		s=sizeof(w3);
		
	}
	//cout<<tbg<<endl;   	//testing
	//cout<<"size: "<<s<<endl; //size of array to be gussed(tbg)
	
	char guessed[s]={' '}; //User Gussed Array 
	
	for(int i=0;i<s-1;i++)
	{
		if(guessed[i]!='-')
		{
			guessed[i]='-';
		}
	}
	
	cout<<"************ Welcome to Hangman ************"<<endl<<endl;
	cout<<"Here is the number of letters in the word you have to guess:"<<endl;
	cout<<guessed<<endl<<endl;
	cout<<"You are supposed to guess in 6 or less attempts."<<endl;
	cout<<"Type a letter in the word or $ to skip the rest of the guess attempts and type the complete word you want to guess."<<endl<<endl;	
	

	int t_attempts=6;
	bool flag= true;
	
	int guess=0;
	
	for(int i=0; i<t_attempts && flag== true ;i++ )
	{
		char ch;
		cout<<"Enter your guess # "<<++guess<<" : ";
		cin>>ch;
		
		if(ch =='$')
		{
			flag=false;
			break;
		}
		
		for(int j=0;j<s;j++)
		{
			if(tbg[j] == ch && guessed[j] == '-')
			{
				guessed[j]=ch;
			}
			
			if(strcmp(tbg,guessed)== 0)
			{
				cout<<endl<<"Congratulations you have guessed it correctly in just "<<guess<<" attempts"<<endl;
				flag = false;
				break;
			}
		
		}
		if(flag==true)
		{
		   	cout<< guessed<<endl;
		}	
	}
	
	if(strcmp(tbg,guessed)!=0 && guess==6)
	{
		flag=false;
	}
	else if(strcmp(tbg,guessed)==0 && guess!=6)   //in case user guessed in 6 or less attempts
	{
		flag = true;
	}

	if(flag == false)
	{
		cin.ignore(); // for clearance of input stream, incase of $ pressed
		
		char last[s]={' '};
		
		cout<<endl<<"You have no more guess attempts left so now you have to type in the complete word you think it would be:"<<endl;
		cout<<"Enter your word here :";
		
		cin.getline(last,s);
		
//		cout<<last<<endl; //testing
	
		if(strcmp(last,tbg) == 0 )
		{
			cout<<endl<<"Congrats you have guessed it correctly "<<endl;
		}
		else
		{
			cout<<endl<<"Sorry your guess is incorrect"<<endl;
		}
		
	}
		
}
