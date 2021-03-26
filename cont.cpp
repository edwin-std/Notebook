#include"cont.h"
cont::cont(void)
{
	type=new char[7];
	type="contact";
	Name=0;
	Commentary=0;
};
cont::~cont(void)
{
	if(Name!=0)
		delete Name;
	if(Commentary!=0)
		delete Commentary;
	Phone.clear();
	delete &Phone;
};
void cont::setName()
{
	char c[100];
	cout<<"Enter the name"<<endl;
	cin >> c;
	Name=new char[strlen(c)+1];
	strcpy(Name,c);
};
void cont::setCommentary()
{
	char c[100];
	cout<<"Enter the commentary if needed"<<endl;
	cin >> c;
	Commentary=new char[strlen(c)+1];
	strcpy(Commentary,c);
};
void cont::add(string method)
{
	if (method == "new")
	{
		cout << "Creating new contact" << endl;
		setName();
		setCommentary();
	}
	else if (method == "phone")
	{
		cout << "Creating new phone" << endl;
		phone*A = new phone;
		A->add("new");
		Phone.push_back(A);
	}
};
char* cont::Type()
{
	return type;
};
void cont::print()
{
	cout<<type<<endl;
	int ind = 0;
	if(Name!="\0")
		cout << Name << endl;
	else cout << "No name" << endl;
	if(Phone.empty()!=true)
	{
		while(Phone[ind]!=Phone.back())
			Phone[ind++]->print();
		Phone[ind]->print();
	}
	if(Commentary!="\0")
		cout << Commentary << endl;
	else cout << "No commentary" << endl;
};
void cont::edit()
{
	int i;
	print();
	while(1)
	{
		cout<<"1 - edit name\n2 - edit phones\n3 - edit commentary\n0 - exit"<<endl;
		cin>>i;
		switch(i)
		{
		case 1:
			setName();
			break;
		case 2:
			if(Phone.empty()==true)
			{
				cout<<"No phones avaible"<<endl;
				return;
			}
			int j;
			cout << "Number of phones: " << Phone.size() << endl;
			cout << "Enter the phone id you want to edit" << endl;
			cin >> j;
			if(j < Phone.size())
				Phone[j]->edit();
			else cout << "This id doesn't exist" << endl;
			break;
		case 3:
			setCommentary();
			break;
		case 0:
			return;
		default:
			cout << "404" << endl;
			break;
		}
	}
};
/*void cont::LegacySave(ofstream &F)
{
	int i=0;
	F<<"''"<<type<<"'': {"<<endl;
	F<<"''Name'': "<<"''"<<Name<<"'',"<<endl;
	F<<"''Commentary'': "<<"''"<<Commentary<<"'',"<<endl;
	if(Phone.empty()!=true)
	{
		F<<"''Phones'': ["<<endl;
		while(Phone[i]!=Phone.back())
		{
			Phone[i++]->save(F);
			F<<","<<endl;
		}
		Phone[i]->save(F);
		F<<endl<<"]"<<endl;
	}
};*/