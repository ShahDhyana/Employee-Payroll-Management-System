#include<iostream>
#include<fstream>
using namespace std;

//gloabal
int id,rate;
int minutes;
char name[20];
float salary;

bool login()
{
	string log_id,log_pass;

	cout<<"\n---Login Page---\n";
	cout<<"Enter ID       = ";
	cin>>log_id;
	cout<<"Enter Password = ";
	cin>>log_pass;
	
	if(log_id=="admin"&& log_pass=="admin123")
		cout<<"\nLogin Successful !!";
	else
		cout<<"\nInvalid Credentials";
		
}
void add_emp()
{
	int min;
	cout<<"Enter the Id:";
	cin>>id;
	cout<<"Enter the name:";
	cin>>name;
	cout<<"Enter working minutes:";
	cin>>minutes;
	
	if(minutes>=60)
	{
		salary=(minutes/60)*100;
	}
	
	else if(minutes>=30)
	{
		salary=50;
	}

	else
	{
		cout<<"Not valid!!";
	}
	
	ofstream fout("employee.dat",ios::app|ios::binary);
	fout.write((char*)&id,sizeof(id));
	fout.write((char*)&name,sizeof(name));
	fout.write((char*)&minutes,sizeof(minutes));
	fout.write((char*)&salary,sizeof(salary));
	fout.close();
	
	cout<<"\nEmployee Added successful !!";
}

void display_emp()
{
	ifstream fin("employee.dat",ios::binary);
	cout<<"----Employee Record----\n";
	while(fin.read((char*)&id,sizeof(id)))

	{
		fin.read((char*)&name,sizeof(name));
		fin.read((char*)&minutes,sizeof(minutes));
		fin.read((char*)&salary,sizeof(salary));
		
		cout<<"\nId :"<<id;
		cout<<"\nName :"<<name;
		cout<<"\nWorking-minutes :"<<minutes;
		cout<<"\nSalary :"<<salary<<endl;
	}
		fin.close();
}

int main()
{
	int choice;
	bool flag=false;
	ofstream fout("employee.dat",ios::binary);

	do{
		cout<<"\n            WELCOME            ";
		cout<<"\n*****Employee Pay-Rolled System*****";
		cout<<"\n1.Login for Employees";
		cout<<"\n2.Add Employee";
		cout<<"\n3.Display Employee";
		cout<<"\n4.Exits";
		cout<<"\nEnter Choice :";
		cin>>choice;
		switch(choice)
		{
			case 1:
				login();
				break;
			case 2:
				add_emp();
				break;
			case 3:
				display_emp();
				break;
			case 4:
				cout<<"Exiting...\n";
				break;

			default:
				cout<<"Invalid choice!\n";
		}
	}
	while(choice!=4);
	return 0;
	fout.close();	
}
