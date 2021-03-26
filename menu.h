#include"phone.h"
class cont: public Book
{
public:
	char* type;
	char* Type();
	cont();
	~cont();
	char* Name;
	vector<phone*>Phone;
	char*Commentary;
	void print();
	void edit();
	void add(string method);
	void setName();
	void setPhone();
	void setCommentary();
	//void save(ofstream &F);
	//void load(ifstream &F);
};