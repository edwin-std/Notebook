#include"phone.h"
phone::phone(void)
{
	Phone=0;
	type=0;
	Commentary=0;
};
phone::~phone(void)
{
	if(Phone!=0)
		delete Phone;
	if(type!=0)
		delete type;
	if(Commentary!=0)
		delete Commentary;
};
void phone::print()
{
	cout << "Phone type: " << type << endl;
	cout << "Phone number: " << Phone << endl;
	cout << "Commetary: " << Commentary << endl;
};
void phone::initPhone(int a)
{
	if (Phone != "\0")
		delete Phone;
	Phone = new char[a];
};
void phone::initType(int a)
{
	if (type != "\0")
		delete type;
	type = new char[a];
};
void phone::initCommentary(int a)
{
	if (Commentary != "\0")
		delete Commentary;
	Commentary = new char[a];
};
void phone::setPhone()
{
	char P[100];
	cout << "Enter the number" << endl;
	cin >> P;
	initPhone(strlen(P)+1);
	strcpy(Phone,P);
};
void phone::setCommentary()
{
	char P[100];
	cout << "Enter the commentary" << endl;
	cin >> P;
	initCommentary(strlen(P)+1);
	strcpy(Commentary,P);
};
void phone::setType()
{
	char P[100];
	cout << "Enter the type" << endl;
	cin >> P;
	initType(strlen(P) + 1);
	strcpy(type, P);
};
void phone::add(string method)
{
	if (method != "new")
		return;
	cout << "Creating new phone" << endl;
	setPhone();
	setType();
	setCommentary();
};
char* phone::Type()
{
	return type;
};
void phone::edit()
{
	print();
	int i;
	while(1)
	{
		cout<<"1 - edit number\n2 - edit type\n3 - edit commentary\n0 - exit"<<endl;
		cin>>i;
		switch(i)
		{
		case 1:
			setPhone();
			break;
		case 2:
			setType();
			break;
		case 3:
			setCommentary();
			break;
		case 0:
			return;
		default:
			cout<<"404"<<endl;
			break;
		}
	}
};
/*void phone::Legacysave(ofstream &F)
{
	F<<"''"<<type<<"'': {"<<endl;
	F<<"''Phone'': "<<"''"<<Phone<<"''"<<endl;
	F<<"''Commentary'': "<<Commentary<<endl;
	F<<"}";
};*/