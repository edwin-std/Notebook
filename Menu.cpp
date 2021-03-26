#include"Menu.h"
Menu::Menu()
{
	cout<<"WIP"<<endl;
};
Menu::~Menu()
{
	Book.clear();
	delete &Book;
}
void Menu::addCont()
{
	cout << "Adding contact" << endl;
	cont*Cont=new cont;
	Cont->add();
	Cont->print();
	Book.push_back(Cont);
};
void Menu::addNote()
{
	cout<<"Adding note" << endl;
	note*Note=new note;
	Note->add();
	Note->print();
	Book.push_back(Note);
};
void Menu::printAll()
{
	int i=0;
	if(Book.empty()==true)
	{
		cout << "The list is empty" << endl;
		return;
	}
	while(Book[i]!=Book.back())
	{
		cout << i << ". ";
		Book[i++]->print();
	}
	cout << i << ". ";
	Book[i]->print();
};
void Menu::printCont()
{
	int i=0;
	if(Book.empty()==true)
	{
		cout<<"The list is empty"<<endl;
		return;
	}
	while(Book[i]!=Book.back())
	{
		if(strcmp(Book[i]->Type(),"contact")==0)
		{
			cout<<i<<". ";
			Book[i]->print();
		}
		i++;
	}
	if(strcmp(Book[i]->Type(),"contact")==0)
		{
			cout<<i<<". ";
			Book[i]->print();
		}
};
void Menu::del()
{
	int i;
	printAll();
	cout << Book.size() << " elements" << endl;
	cout << "Enter the id you want to delete" << endl;
	cin>>i;
	if(i<Book.size())
	{
		delete Book[i];
		Book.erase(Book.begin()+i);
	}
	else cout << "404" << endl;
};
void Menu::addPhone()
{
	int i, k;
	while(1)
	{
		cout << "1 - add to the existing contact\n2 - add to the new contact\n"<<endl;
		cin >> i;
		switch(i)
		{
		case 1:
			if(Book.empty()==true)
				cout << "No contacts avaible, please add new one" << endl;
			else
			{
				printCont();
				while(1)
				{
					cout << "Enter the number of the contact" << endl;
					cin >> k;
					if(k < Book.size())
					{
						if(strcmp(Book[k]->Type(),"contact")==0)
						{
							Book[k]->add("phone");
							cout << "Added" << endl;
						}
						else cout << "Not a contact, enter valid id" << endl;
						break;
					}
					else cout << "404" << endl;
				}
			return;
			}
		case 2:
			addCont();
			Book.back()->add("phone");
			cout << "Added" << endl;
			return;
		}
	}
};
void Menu::addElem()
{
	int a;
	while(1)
	{
		cout << "Adding new page\n1 - add contact\n2 - add phone\n3 - add note" << endl;
		cin >> a;
		switch(a)
		{
		case 1:
			addCont();
			return;
		case 2:
			addPhone();
			return;
		case 3:
			addNote();
			return;
		default:
			cout << "404" << endl;
			break;
		}
	}
}
void Menu::edit()
{
	int i;
	printAll();
	cout << "Enter the id you want to edit" << endl;
	cin >> i;
	int d = Book.size();
	if(i<d)
		Book[i]->edit();
	else cout << "404" << endl;
};
void Menu::MainMenu()
{
	int a;
	while(1)
	{
		cout << "Main menu\nEnter the type of operation\n1 - print\n2 - add\n3 - edit\n4 - delete\n5 - save\n0 - exit" << endl;
		cin >> a;
		switch(a)
		{
		case 1:
			printAll();
			break;
		case 2:
			addElem();
			break;
		case 3:
			edit();
			break;
		case 4:
			del();
			break;
		case 5:
			save();
			break;
		case 0:
			return;
		default:
			cout << "404" << endl;
			break;
		}
	}
};
void Menu::save()
{}
/*
{
	int i = 0;
	ofstream F;
	F.open("123.txt");
	if (Book.empty() != true)
	{
		while (Book[i] != Book.back())
			Book[i++]->save(F);
		Book[i]->save(F);
	}
	F.close();
	cout << "Saved" << endl;
};*/
void Menu::load()
{
	char S[100];
	ifstream F;
	F.open("1234.txt");
	while (!F.eof())
	{
		F.getline(S, 99);
		if (strcmp(S, "contact") == 0)
		{
			F.getline(S, 99);
			cont*A = new cont;
			A->Name = new char[strlen(S) + 1];
			strcpy(A->Name, S);
			F.getline(S, 99);
			A->Commentary = new char[strlen(S) + 1];
			strcpy(A->Commentary, S);
			F.getline(S, 99);
			while (strcmp(S, "/contact") != 0)
			{
				phone*B = new phone;
				B->type = new char[strlen(S) + 1];
				strcpy(B->type, S);
				F.getline(S, 99);
				B->Phone = new char[strlen(S) + 1];
				strcpy(B->Phone, S);
				F.getline(S, 99);
				B->Commentary = new char[strlen(S) + 1];
				strcpy(B->Commentary, S);
				A->Phone.push_back(B);
				F.getline(S, 99);
			}
			Book.push_back(A);
		}
	}
};
/*void Menu::Legacysave()
{
	int i=0;
	ofstream F;
	F.open("123.txt");
	F<<"{"<<endl;
	if(Book.empty()!=true)
	{
		while(Book[i]!=Book.back())
		{
			Book[i++]->save(F);
			F<<","<<endl;
		}
		Book[i]->save(F);
	}
	F<<"}"<<endl;
	F.close();
	cout<<"Saved"<<endl;
};
void Menu::Legacyload()
{
	string S;
	ifstream F;
	F.open("123.txt");
	while(!F.eof())
	{
		getline(F,S);
		int i=S.find("''",0);
		if(i!=-1)
		{
			int j=S.find("''",i+1);
			string Info=S.substr(i+2,j-i-2);
			cout<<Info<<endl;
		}
	}
};*/