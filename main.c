#include<stdio.h>
#include"miniproject.h"
int main(){
	int a, b, c, d, x;
	printf("\t\tWELCOME TO TIRUPATI PROVISIONAL STORES\t\t\n");
	do{
		printf("1 : Inventory \n2 : Costumer\n3 : Company\n");
		scanf("%d", &a);
		switch(a){
			 case 1: 
				printf("1 : New Item \n2 : Append item\n3 : Item  Detail Updation\n4 : PRINT INVENTORY\n");
				printf("5 : Check for Items to be ordered\n");
				scanf("%d", &b);
				switch(b){
					case 1 : 
						newitem();
						break;
					case 2 :
						appenditem();
						break;
					case 3 :
						updateitem();
						break;
			 		case 4 :
						printinventory();
						break;
					case 5 : 
						tobeordered();
						break;
				}
				break;
			case 2 :
				printf("1 : Costumer with account\n 2 : Costumer without account\n");
				scanf("%d", &c);
				switch(c){
					case 1 :
						costumerwacc();
						break;
					/*case 2 :
						costumer();
						break;*/
				}
			/*case 3 :
				printf("1 :Company sales updation\n 2 : New Company ");
				scanf("%d", &d);
				switch(d){	
					case 1 :
						compnydet();
					case 2 :
						newcompany();
				}*/

		
		}	
		printf("To Continue with the shop: 1\nTo exit : 0\n");
		scanf("%d", &x);
		printf("\n");
		printinventory();
	}while(x);
	return 0;
}
