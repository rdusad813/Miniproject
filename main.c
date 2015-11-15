
/*****************************************************************************
 * Copyright (C) Rishabh Dusad rdusad813@gmail.com
 
 * This file is part of Grocery Store Management System.

 *   Grocery Store Management System is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   Grocery Store Management System is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with Grocery Store Management System.  If not, see <http://www.gnu.org/licenses/>.

 *****************************************************************************/

#include<stdio.h>
#include"miniproject.h"
int main(){
	int a, b, c, d, x, f, g;
	system("clear");
	printf("\n\n\n\n\n\t\t\t\t\t\t\tWELCOME TO TIRUPATI PROVISIONAL STORES\t\t\n");
	system("sleep 3");
	system("clear");
	do{
		printf("\n\n\n\n\t\t\t\t\t1 : Inventory \n\t\t\t\t\t2 : customer\n\t\t\t\t\t3 : Company\n\t\t\t\t\t");
		scanf("%d", &a);
		switch(a){
			 case 1: 
				system("clear");
				printf("\n\n\n\n");
				printf("\t\t\t\t\t1 : New Item \n\t\t\t\t\t2 : Append item\n\t\t\t\t\t3 : Item  Detail Updation\n\t\t\t\t");
				printf("\t4 : PRINT INVENTORY\n\t\t\t\t\t5 : Check for Items to be ordered\n\t\t\t\t\t");
				scanf("%d", &b);
				system("clear");	
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
					default :
						break;

				}
				break;
			case 2 :
				system("clear");
				printf("\n\n\n\n");
				printf("\t\t\t\t\t1: customer with account\n\t\t\t\t\t2 : customer without account\n\t\t\t\t\t");
				scanf("%d", &c);
				system("clear");
				switch(c){
					case 1 :
						printf("\n\n\n\n");
						printf("\t\t\t\t\t1 : New entry\n\t\t\t\t\t2: print record\n\t\t\t\t\t3: Bill\n\t\t\t\t\t");
						scanf("%d", &f);
						system("clear");						
						switch(f){
							case 1 :
								customerwacc();
								break;
							case 2 :
								printrecord();
								break;					
							case 3 :
								bill_cwa();
								break;
							default :
								break;	
						}		
						break;		
					case 2 :
						customerwtacc();
						break;
					default :
						break;				
				}
				break;		
			case 3 :
				system("clear");
				printf("\n\n\n\n");
				printf("\t\t\t\t\t1 :Enter Company\n\t\t\t\t\t2 : Append new company\n\t\t\t\t\t");
				printf("3 : Print Company Details\n\t\t\t\t\t4 : Check for check Bounce dates\n\t\t\t\t\t");
				scanf("%d", &d);
				switch(d){	
					case 1 :
						companydet();
						break;			
					case 2 :
						appendcompany();
						break;					
					case 3 :
						printcompany();
						break;
					case 4 :
						system("clear");
						printf("\n\n\n\n");
						printf("\t\t\t\t\tSearch Based on \n");
						printf("\t\t\t\t\t1 : Company Name\n\t\t\t\t\t2 : Check bounces in the month\n");
						printf("\t\t\t\t\t3 : Check bounces on a given date\n\t\t\t\t\t4 : based on amount\n\t\t\t\t\t");
						scanf("%d", &g);
						switch(g){
							case 1 : 
								checkname();
								break;
							case 2 :
								checkmonth();
								break;
							case 3 :	
								checkdate();
								break;
							case 4 :
								checkamount();
								break;
							default :
								break;
						}
						break;
					default :
						break;
				}
			default :
				break;

		
		}
		printf("\n\n\n\n");
		printf("\t\t\t\t\tMain menu: 1\n\t\t\t\t\tTo exit : 0\n\t\t\t\t\t");
		scanf("%d", &x);
		system("clear");
		printf("\n");
	}while(x);
	return 0;
}
