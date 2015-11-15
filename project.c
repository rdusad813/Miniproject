
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

#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include"miniproject.h"
int newitem(){//function usefull only in the first case. When we start the inventory.
	item m[SIZE];
	static int i = 1;
	int x, n;
	int fd = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	do{	printf("\n\n");
		printf("\t\t\t\t\tItem name : ");
		scanf("%s", m[i].str);
		printf("\t\t\t\t\tQuantity in Kg : ");
		scanf("%lf", &m[i].quantity);
		printf("\t\t\t\t\tPrice  Per Kg: ");
		scanf("%lf", &m[i].price);
		m[i].serialkey = i;
		write(fd, &m[i], sizeof(m[i]));
		i++;
		printf("\n");
		printf("\t\t\t\t\tTo Continue entering data : 1\n\t\t\t\t\tTo exit : 0\n\t\t\t\t\t");
		scanf("%d", &x);
		printf("\n");
		system("clear");
	}while(x);
	close(fd);
	return 0;
}
int printmenu(){
	item m[SIZE];
	int count = 1, j, x;
	int fd = open("Allproduct.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &m, sizeof(m));
	count = x / sizeof(m[0]);
	printf("\t\t\t\t\tS.No\tITEM\tQUANTITY\tPRICE\n");
	for(j = 0; j < count; j++){
		printf("\t\t\t\t\t%d\t%s\t%lf\t%lf\n", j+1, m[j].str, m[j].quantity, m[j].price);
	}		
	close(fd);
	return 0;
}
int appenditem(){
	item m[SIZE];
	int x, n, count = 1;
	int fd = open("Allproduct.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &m, sizeof(m));
	count = x / sizeof(m[0]);
	n = count  + 1;	
	close(fd);
	int fp = open("Allproduct.txt",O_WRONLY | O_APPEND, S_IRUSR|S_IWUSR);
	if(fp == -1){
		perror("Open failed\n");
		return errno;
	}
	fp = fd;
	do{
		printf("\n\n");
		printf("\t\t\t\t\tItem name: ");
		scanf("%s", m[n].str);
		printf("\t\t\t\t\tQuantity in Kg: ");
		scanf("%lf", &m[n].quantity);
		printf("\t\t\t\t\tPrice  Per Kg: ");
		scanf("%lf", &m[n].price);
		m[n].serialkey = n ;
		write(fp, &m[n], sizeof(m[n]));
		n++;
		printf("\n");
		printf("\t\t\t\t\tTo Continue appending : 1\n\t\t\t\t\tTo exit : 0\n\t\t\t\t\t");
		scanf("%d", &x);
		system("clear");
	}while(x);
	close(fp);		
		
	return 0;
}	
int updateitem(){
	item m[SIZE];
	int x, j, count = 0, i = 1;
	double price, quantity;
	char string[16]; 
	int fd = open("Allproduct.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &m, sizeof(m));
	count = x / sizeof(m[0]);
	close(fd);
	int fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fp == -1){
		perror("Open failed\n");
		return errno;
	}
	
	do{
		printf("\n\n");
		printf("\t\t\t\t\tItem to be updated :");
		scanf("%s", string);		
		for(j = 0; j < count; j++){
			if(strcmp(string, m[j].str) == 0){
				printf("\n\n");
				printf("\t\t\t\t\t 1 : change in price \n\t\t\t\t\t 2 :change in quantity\n\t\t\t\t\t");
				printf(" 3 : Change in both\n\t\t\t\t\t");
				scanf("%d", &x);						
				switch(x){
					case 1 :
						//system("clear");
						printf("\n");
						printf("\t\t\t\t\tEnter new price : ");
						scanf("%lf", &price);
						m[j].price = price;
						int fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fp == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count; i++)
							write(fp, &m[i], sizeof(m[i]));
						close(fp);
						break;
						
					case 2 :
						//system("clear");
						printf("\n");
						printf("\t\t\t\t\tEnter new quantity : ");
						scanf("%lf", &quantity);
						m[j].quantity = quantity;
						fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fp == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count; i++)
							write(fp, &m[i], sizeof(m[i]));
						close(fp);
						break;
					case 3 :
						//system("clear");
						printf("\n");
						printf("\t\t\t\t\tEnter new price and new quantity :");
						scanf("%lf%lf", &price, &quantity);
						m[j].price = price;
						m[j].quantity = quantity;
						fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fp == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count; i++)
							write(fp, &m[i], sizeof(m[i]));
						close(fp);
						break;
					default :
						break;
				}
			}
		}
		printf("\n");
		printf("\t\t\t\t\tTo Continue updating items: 1\n\t\t\t\t\tTo exit : 0\n\t\t\t\t\t");
		scanf("%d", &x);
		printf("\n");
		system("clear");
	}while(x);
	close(fp);	
	return 0;
}
void printinventory(){
	printf("\n\n\n");
	printmenu();
}
int tobeordered(){
	item m[SIZE];
	int i = 0, x, n, count = 1, j = 1;
	int fd = open("Allproduct.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &m, sizeof(m));
	count = x / sizeof(m[0]);
	n = count  + 1;
	printf("\n\n\n");	
	for(i = 0; i < count; i++)
		if(m[i].quantity == 0){
			printf("\t\t\t\t\t %d : %s\n", j, m[i].str);
			j++;
		}	
	close(fd);
	return 0;
}

int customerwacc(){
	printf("\t\t\t\t\tINVENTORY\n");
	printmenu();
	item m[SIZE];
	int j, x, y, count1, count = 1, fp, counter = 0, ans, num, i;	
	static int k = 1;	
	costwacc cw[SIZE];
	int fd = open("Allproduct.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &m, sizeof(m));
	count = x / sizeof(m[0]);
	close(fd);
	int fm = open("Allcustomer.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fm == -1){
		perror("Open failed\n");
		return errno;
	}
	y = read(fm, &cw, sizeof(cw));
	count1 = y / sizeof(cw[0]);
	close(fm);
	do{
		printf("\n\n\n\n");
	       	printf("\t\t\t\t\tEnter customer name :");	
		scanf("%s", cw[k].name);
		printf("\t\t\t\t\tEnter the product required :");
		scanf("%s", cw[k].product);
		for(j = 0; j < count; j++){
			if(strcmp(cw[k].product, m[j].str) == 0 && m[j].quantity != 0 ){
				printf("\t\t\t\t\tProduct is available\n ");
				printf("\t\t\t\t\tEnter the quantity required in Kg.");
				scanf("%lf", &cw[k].quantity);
				if(cw[k].quantity <= m[j].quantity){
					count1++;
					printf("\t\t\t\t\tProduct available in required quantity\n");
					m[j].quantity = (m[j].quantity - cw[k].quantity);		
					count1++;				
					cw[k].price = cw[k].quantity * m[j].price;				
					fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
					if(fp == -1){
						perror("Open failed\n");
						return errno;
					}
					for(i = 0; i < count; i++)
						write(fp, &m[i], sizeof(m[i]));
					close(fp);
					fm = open("Allcustomer.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
							if(fm == -1){
								perror("Open failed\n");
								return errno;
							}
							for(i = 0; i < count1; i++)
								write(fm, &cw[i], sizeof(cw[i]));
							close(fm);
					k++;	
				}
				else if (cw[k].quantity > m[j].quantity){
					if(m[j].quantity == 0){
						printf("\t\t\t\t\tProduct Unaivaiable\n");
						break;
					}
					printf("\t\t\t\t\tQuantity of product available  : %lf\n",(m[j].quantity) );
					printf("\t\t\t\t\tDo you need the product ?\tEnter  1 : YES \t 2 : NO\n\t\t\t\t\t");
					scanf("%d", &ans);
					if(ans == 1){
						count1++;				
						m[j].quantity = 0;
						cw[k].price = cw[k].quantity * m[j].price;				
						fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fp == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count; i++)
							write(fp, &m[i], sizeof(m[i]));
						close(fp);
					
						fm = open("Allcustomer.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fm == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count1; i++)
							write(fm, &cw[i], sizeof(cw[i]));
						close(fm);
					k++;					
					}
					else 
						printf("\t\t\t\t\tWe will deginitely get you the required amount next time\n");		
					break;				
				}		
				else
					printf("\t\t\t\t\tSorry, We would definitely get you the product next time\n");
				break;
			}
			else{
				counter++;
				if(counter  == count)
					printf("\t\t\t\t\tWe don't have the product you require\n");
			}
		}

		printf("\t\t\t\t\tDo you want to continue shopping\t enter 1 : YES , 0 : NO\n\t\t\t\t\t");
		scanf("%d", &num);
		system("clear");
	}while(num);		
	return 0;
}
int printrecord(){
	int y, count1, i, c = 0;	
	char costname[16];
	item m[SIZE];
	costwacc cw[SIZE];
	printf("\n\n\n\n");	
	printf("\t\t\t\t\tEnter the cosutmer name\n\t\t\t\t\t");
	scanf("%s", costname);
	int fd =open("Allcustomer.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){		
		perror("Open failed\n");
		return errno;
	}
	y = read(fd, &cw, sizeof(cw));
	count1 = y / sizeof(cw[0]);
	close(fd);
	for(i = 0; i < count1; i++){
		if(strcmp(cw[i].name, costname) == 0){
			printf("\t\t\t\t\t%s\t%lf\t%lf\n", cw[i].product, cw[i].quantity, cw[i].price);
		}
	}
}
int bill_cwa(){
	queue q;	
	qinit(&q);
	int y, count1, i;
	double sum = 0;
	char string[16];
	int fd = open("Allcustomer.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);	
	costwacc cw[SIZE], tmp;
	if(fd == -1){
		perror("Open Failed\n");
		return errno;
	}
	y = read(fd, &cw, sizeof(cw));
	count1 = y / sizeof(cw[0]);
	close(fd);
	printf("\n\n\n\n");
	printf("\t\t\t\t\tEnter your name\n\t\t\t\t\t");
	scanf("%s",string);	
	printf("\t\t\t\t\tThese are the details of your shopping\n");
	printcost(string);
	for(i = 0; i < count1; i++){
		if(strcmp(cw[i].name, string) == 0){
			enqueue(&q, cw[i]);
		}
	}
	printf("\t\t\t\t\tYour Bill is\t");
	while(!qempty(&q)){
		tmp = dequeue(&q);
		sum = sum + tmp.price;	
	}
	printf("%lf\n", sum);
	

}
int printcost(char str[16]){
	int y, count1, i, c = 0;	
	item m[SIZE];
	costwacc cw[SIZE];
	int fd =open("Allcustomer.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){		
		perror("Open failed\n");
		return errno;
	}
	y = read(fd, &cw, sizeof(cw));
	count1 = y / sizeof(cw[0]);
	close(fd);
	for(i = 0; i < count1; i++){
		if(strcmp(cw[i].name, str) == 0){
			printf("\t\t\t\t\t%s\t%lf\t%lf\n", cw[i].product, cw[i].quantity, cw[i].price);
		}
	}
}
int customerwtacc(){
	printf("\t\t\t\t\tINVENTORY\n");
	printmenu();
	queue1 q1;
	q1_init(&q1);
	item m[SIZE];
	int j, x, y, count, fp, l, counter = 0, ans, num, i;	
	static int k = 1;	
	cost c[SIZE];
	int fd = open("Allproduct.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &m, sizeof(m));
	count = x / sizeof(m[0]);
	close(fd);
	do{
		printf("\n\n\n\n");
	       	printf("\t\t\t\t\tEnter the product required ");
		scanf("%s", c[k].product);
		for(j = 0; j < count; j++){
			if(strcmp(c[k].product, m[j].str) == 0 && m[j].quantity != 0 ){
				printf("\t\t\t\t\tProduct is available\n ");
				printf("\t\t\t\t\tEnter the quantity required in Kg.\t");
				scanf("%lf", &c[k].quantity);
				if(c[k].quantity <= m[j].quantity){
					printf("\t\t\t\t\tProduct available in required quantity\n");
					m[j].quantity = (m[j].quantity - c[k].quantity);		
					c[k].price = c[k].quantity * m[j].price;				
					fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
					if(fp == -1){
						perror("Open failed\n");
						return errno;
					}
					for(i = 0; i < count; i++)
						write(fp, &m[i], sizeof(m[i]));
					close(fp);
					enqueue_1(&q1, c[k]);				
				}
				else if (c[k].quantity > m[j].quantity){
					if(m[j].quantity == 0){
						printf("Product Unaivaiable\n");
						break;
					}
					printf("\t\t\t\t\tQuantity of product available  : %lf\n",(m[j].quantity) );
					printf("\t\t\t\t\tDo you need the product ?\tEnter  1 : YES \t 2 : NO\n\t\t\t\t\t");
					scanf("%d", &ans);
					if(ans == 1){
						m[j].quantity = 0;
						c[k].price = c[k].quantity * m[j].price;				
						fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fp == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count; i++)
							write(fp, &m[i], sizeof(m[i]));
						close(fp);
					enqueue_1(&q1, c[k]);				
					}
					else 
						printf("\t\t\t\t\tWe will definitely get you the required amount next time\n");		
					break;				
				}		
				else
					printf("\t\t\t\t\tSorry, We would definitely get you the product next time\n");
				break;
			}
			else{
				counter++;
				if(counter  == count)
					printf("\t\t\t\t\tWe don't have the product you require\n");
			}
		}

		printf("\t\t\t\t\tDo you want to continue shopping\t enter 1 : YES , 0 : NO\n\t\t\t\t\t");
		scanf("%d", &num);
		system("clear");	
	}while(num);
	bill_cwta(&q1);
			
	return 0;
}
void bill_cwta(queue1 *q){
	double sum = 0;
	cost tmp;
	printf("\n\n\n\n");
	printf("\t\t\t\t\tThese are the details of your shopping\n");
	while(!q1_empty(q)){
		tmp = dequeue_1(q);
		printf("\t\t\t\t\t%s\t%lf\t%lf\n", tmp.product, tmp.quantity, tmp.price);
		sum = sum + tmp.price;	
	}
	printf("\t\t\t\t\tYour Bill is\t");
	printf("%lf\n", sum);
}
int companydet(){
	system("clear");
	company com[SIZE];
	static int i = 1;
	int x, n;
	int fd = open("Allcompanies.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	do{
		printf("\n\n\n\n");
		printf("\t\t\t\t\tCompany Name:");
		scanf("%s", com[i].str);
		printf("\t\t\t\t\tAmount of Check :");
		scanf("%lf", &com[i].amount);
		printf("\t\t\t\t\tDate of Check Bounce(day) :" );
		scanf("%d", &com[i].d.day);
		printf("\t\t\t\t\tDate of Check Bounce(month in numbers) :" );
		scanf("%d", &com[i].d.month);
		printf("\t\t\t\t\tDate of Check Bounce(year) :" );
		scanf("%d", &com[i].d.year);
		write(fd, &com[i], sizeof(com[i]));
		i++;
		printf("\t\t\t\t\tTo Continue : 1\n\t\t\t\t\tTo exit : 0\n\t\t\t\t\t");
		scanf("%d", &x);
		printf("\n");
		system("clear");
	}while(x);
	close(fd);
	return 0;
}
int appendcompany(){
	system("clear");
	company com[SIZE];
	int x, n, count = 1;
	int fd = open("Allcompanies.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &com, sizeof(com));
	count = x / sizeof(com[0]);
	n = count  + 1;	
	close(fd);
	int fp = open("Allcompanies.txt",O_WRONLY | O_APPEND, S_IRUSR|S_IWUSR);
	if(fp == -1){
		perror("Open failed\n");
		return errno;
	}
	fp = fd;
	do{
		printf("\n\n\n\n");
		printf("\t\t\t\t\tCompany Name:");
		scanf("%s", com[n].str);
		printf("\t\t\t\t\tAmount of Check :");
		scanf("%lf", &com[n].amount);
		printf("\t\t\t\t\tDate of Check Bounce(day) :" );
		scanf("%d", &com[n].d.day);
		printf("\t\t\t\t\tDate of Check Bounce(month in numbers) :" );
		scanf("%d", &com[n].d.month);
		printf("\t\t\t\t\tDate of Check Bounce(year) :" );
		scanf("%d", &com[n].d.year);
		write(fd, &com[n], sizeof(com[n]));
		n++;
		printf("\t\t\t\t\tTo Continue : 1\n\t\t\t\t\tTo exit : 0\n\t\t\t\t\t");
		scanf("%d", &x);
		printf("\n");
		system("clear");
	}while(x);
	close(fp);		
		
	return 0;
}
int printcompany(){
	company com[SIZE];
	int count = 1, j, x;
	int fd = open("Allcompanies.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &com, sizeof(com));
	count = x / sizeof(com[0]);
	printf("\n\n\n\n");
	printf("\t\t\t\t\tS.No\tCOMPANY NAME\tAMOUNT\t\tDATE\n");
	for(j = 0; j < count; j++){
		printf("\t\t\t\t\t%d\t%s\t\t%lf\t%d-%d-%d\n", j+1, com[j].str, com[j].amount, com[j].d.day, com[j].d.month, com[j].d.year);
	}		
	close(fd);
	return 0;
}

int checkmonth(){
	list l;
	int num;
	company com[SIZE];
	int count = 1, j, x, month;
	int fd = open("Allcompanies.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &com, sizeof(com));
	count = x / sizeof(com[0]);
	do{
		printf("\n\n\n\n");	
		init(&l);
		printf("\t\t\t\t\tEnter the month number\n\t\t\t\t\t");
		scanf("%d", &month);
		for(j = 0; j < count; j++)	
			if(com[j].d.month == month)
				insert(&l, com[j].str, com[j].amount, com[j].d);
		traverse(&l);
		printf("\t\t\t\t\t1 :Continue checking\n\t\t\t\t\t0 : exit\n\t\t\t\t\t");	
		scanf("%d", &num);
		system("clear");
	}while(num);
}
int checkamount(){
	list l;
	int num;
	company com[SIZE];
	int count = 1, j, x;
	double amount;
	int fd = open("Allcompanies.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &com, sizeof(com));
	count = x / sizeof(com[0]);
	do{
		printf("\n\n\n\n");
		init(&l);
		printf("\t\t\t\t\tEnter the amount\n\t\t\t\t\t");
		scanf("%lf", &amount);
		for(j = 0; j < count; j++)	
			if(com[j].amount == amount)
				insert(&l, com[j].str, com[j].amount, com[j].d);
		traverse(&l);
		printf("\t\t\t\t\t1 :Continue checking\n\t\t\t\t\t0 : exit\n\t\t\t\t\t");	
		scanf("%d", &num);
		system("clear");
	}while(num);
}
int checkname(){
	system("clear");
	list l;
	company com[SIZE];
	int count = 1, j, x;
	int month, num;
	char name[128];
	int fd = open("Allcompanies.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &com, sizeof(com));
	count = x / sizeof(com[0]);
	do{
		printf("\n\n\n\n");
		init(&l);
		printf("\t\t\t\t\tCompany Name :\n\t\t\t\t\t");
		scanf("%s", name);
		for(j = 0; j < count; j++)
			if(strcmp(com[j].str, name) == 0)
				insert(&l, com[j].str, com[j].amount, com[j].d);
			traverse(&l);
			printf("\t\t\t\t\t1 :Continue checking\n\t\t\t\t\t0 : exit\n\t\t\t\t\t");	
			scanf("%d", &num);
			system("clear");
	}while(num);
}
int checkdate(){
	system("clear");
	list l;
	int num;
	company com[SIZE];
	int count = 1, j, x, day, month, year;
	int fd = open("Allcompanies.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &com, sizeof(com));
	count = x / sizeof(com[0]);
	do{
		printf("\n\n\n\n");		
		init(&l);
		printf("\t\t\t\t\tDay :\n\t\t\t\t\t");
		scanf("%d", &day);
		printf("\t\t\t\t\tMonth :\n\t\t\t\t\t");
		scanf("%d", &month);
		printf("\t\t\t\t\tYear :\n\t\t\t\t\t");
		scanf("%d", &year);
		for(j = 0; j < count; j++)	
			if((com[j].d.day == day) && (com[j].d.month == month) && (com[j].d.year == year))
				insert(&l, com[j].str, com[j].amount, com[j].d);
		traverse(&l);
		printf("\t\t\t\t\t1 :Continue checking\n\t\t\t\t\t0 : exit\n\t\t\t\t\t");	
		scanf("%d", &num);
		system("clear");
	}while(num);
}
