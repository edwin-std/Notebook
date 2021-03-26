#include"Book.h"
class phone: public Book
{
public:
	phone();
	~phone();
	char* Type();
	char*type;
	char*Phone;
	char*Commentary;
	void print();
	void edit();
	void initPhone(int n);
	void initType(int n);
	void initCommentary(int n);
	void setPhone();
	void setType();
	void setCommentary();
	void add(string method);
	//void save(ofstream &F);
	//void load(ifstream &F);
};