#define SIZE 512
typedef struct item{
	char str[16];
	double price;
	double quantity;
	int serialkey;
}item;
typedef struct costumerwacc{
	char name[16];
	char product[16];
	double quantity;
}costwacc;
typedef struct costumer{
	char product[16];
	double quantity;
}cost;
int updateitemhi();
int newitem();
int printmenu();
int tobeordered();
void printinventory();
int costumerwacc();
void costumer();
int openfile();
