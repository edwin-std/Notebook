#include"Book.h"
class note: public Book
{
public:
	note();
	~note();
	char* type;
	char* Type();
	char* Body;
	char* Header;
	void print();
	void edit();
	void add(string method);
	void initBody(int a);
	void initHeader(int a);
	void setBody();
	void setHeader();
	//void save(ofstream &F);
	//void load(ifstream &F);
};