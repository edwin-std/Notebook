#include"note.h"
note::note(void)
{
	type=new char[4];
	type="note";
	Body=0;
	Header=0;
};
note::~note(void)
{
	if (type != 0)
		delete type;
	if(Body!=0)
		delete Body;
	if(Header!=0)
		delete Header;
};
char* note::Type()
{
	return type;
};
void note::print()
{
	cout<<type<<endl;
	if (Header != "\0")
		cout << Header << endl;
	else
		cout << "Header is empty" << endl;
	if(Body!="\0")
		cout << Body << endl;
	else
		cout << "Body is empty" << endl;
}
void note::initBody(int a)
{
	if(Body!=0)
		delete Body;
	Body = new char[a];
};
void note::initHeader(int a)
{
	if(Header !=0)
		delete Header;
	Header = new char[a];
};
void note::setBody()
{
	char a[5000];
	cout << "Enter the note" << endl;
	cin >> a;
	initBody(strlen(a)+1);
	strcpy(Body,a);
};
void note::setHeader()
{
	char a[5000];
	cout << "Enter the header" << endl;
	cin >> a;
	initHeader(strlen(a)+1);
	strcpy(Header,a);
};
void note::add(string method)
{
	if (method != "new")
		return;
	cout << "Creating new note" << endl;
	setHeader();
	setBody();
};
void note::edit()
{
	int i;
	while(1)
	{
		cout << "1 - edit header\n2 - edit note\n0 - exit" << endl;
		cin >> i;
		switch(i)
		{
		case 1:
			setHeader();
			break;
		case 2:
			setBody();
			break;
		case 0:
			return;
		default:
			cout << "404" << endl;
			break;
		}
	}
};
/*void note::Legacysave(ofstream& F)
{
	F<<"''"<<type<<"'': {"<<endl;
	F<<"''Header'': "<<"''"<<Header<<"'',"<<endl;
	F<<"''Body'': "<<"''"<<Body<<"''"<<endl;
	F<<"}"<<endl;
};*/
/*void note::Legacyload(ifstream& F)
{
	string S;
	getline(F,S);
	int i=S.find("''",0);
		if(i!=-1)
		{
			int j=S.find("''",i+1);
			string Info=S.substr(i+2,j-i-2);
			if(Info=="Header")
			{
				string Info1=S.substr(j+6,S.length()-j-8);
				initHeader(Info1.length()+1);
				strcpy(Header,Info1.c_str());
			}
			if(Info=="Body")
			{
				string Info1=S.substr(j+6,S.length()-j-8);
				initBody(Info1.length()+1);
				strcpy(Body,Info1.c_str());
			}
		}

};*/