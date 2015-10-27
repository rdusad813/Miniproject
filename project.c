#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include"miniproject.h"
int newitem(){
	item m[SIZE];
	static int i = 1;
	int x, n;
	int fd = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	do{
		printf("Item name :");
		scanf("%s", m[i].str);
		printf("Quantity in Kg :");
		scanf("%lf", &m[i].quantity);
		printf("Price  Per Kg: ");
		scanf("%lf", &m[i].price);
		m[i].serialkey = i;
		write(fd, &m[i], sizeof(m[i]));
		i++;
		printf("To Continue : 1\nTo exit : 0\n");
		scanf("%d", &x);
		printf("\n");
		printmenu();
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
	printf("S.No\tITEM\tQUANTITY\tPRICE\n");
	for(j = 0; j < count; j++){
		printf("%d\t%s\t%lf\t%lf\n", j+1, m[j].str, m[j].quantity, m[j].price);
	}		
	close(fd);
	return 0;
}
void printinventory(){
	printmenu();
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
		printf("Item name :");
		scanf("%s", m[n].str);
		printf("Quantity in Kg :");
		scanf("%lf", &m[n].quantity);
		printf("Price  Per Kg: ");
		scanf("%lf", &m[n].price);
		m[n].serialkey = n ;
		write(fp, &m[n], sizeof(m[n]));
		n++;
		printf("To Continue : 1\nTo exit : 0\n");
		scanf("%d", &x);
		printf("\n");
		printmenu();
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
		perror("Open failed\n");
		return errno;
	}
	if(fp == -1){
	
	do{
		printf("Item to be updated :");
		for(j = 0; j < count; j++){
			if(strcmp(string, m[j].str) == 0){
				printf("Press 1 : change in price \n 2 :change in quantity\n 3 : Change in both");
				scanf("%d", &x);						
				switch(x){
					case 1 :
						printf("Enter new price : ");
						scanf("%lf", &price);
		scanf("%s", string);
						m[j].price = price;
						int fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fp == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count; i++)
							write(fp, &m[i], sizeof(m[i]));
						close(fp);
						printmenu();
						break;
						
					case 2 :
						printf("Enter new quantity : ");
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
						printmenu();
						break;
					case 3 :
						printf("Enter new price and new quantity :");
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
						printmenu();
						break;
				}
			}
		}
		printf("To Continue : 1\nTo exit : 0\n");
		scanf("%d", &x);
		printf("\n");
		printmenu();
	}while(x);
	close(fp);	
	return 0;
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
	for(i = 1; i < count; i++)
		if(m[i].quantity == 0){
			printf(" %d : %s\n", j, m[i].str);
			j++;
		}	
	close(fd);
	return 0;
}

int costumerwacc(){
	item m[SIZE];
	int j, x, y, count1 = 1, count = 1, fp,  k = 1, counter = 0, ans, num, i;	
	costwacc cw[SIZE];
	int fd = open("Allproduct.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1){
		perror("Open failed\n");
		return errno;
	}
	x = read(fd, &m, sizeof(m));
	count = x / sizeof(m[0]);
	close(fd);
	int fm = open("Allcostumer.txt",O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR);
	if(fm == -1){
		perror("Open failed\n");
		return errno;
	}
	y = read(fm, &cw, sizeof(cw));
	count1 = y / sizeof(cw[0]);
	close(fm);
	
	do{
	       	printf("Enter costumer name");	
		scanf("%s", cw[k].name);
		printf("Enter the product required");
		scanf("%s", cw[k].product);
		for(j = 0; j < count; j++){
			if(strcmp(cw[k].product, m[j].str) == 0 && m[j].quantity != 0 ){
				printf("Product is available\n ");
				printf("Enter the quantity required in Kg.");
				scanf("%lf", &cw[k].quantity);
				if(cw[k].quantity <= m[j].quantity){
					printf("Product available in required quantity");
					m[j].quantity = (m[j].quantity - cw[k].quantity);		
				fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fp == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count; i++)
							write(fp, &m[i], sizeof(m[i]));
						close(fp);
						
				
				fm = open("Allcostumer.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fm == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count1; i++)
							write(fm, &cw[i], sizeof(cw[i]));
						close(fm);
				}
				else if (cw[k].quantity > m[j].quantity){
					if(m[j].quantity == 0){
						printf("Product Unaivaiable\n");
						break;
					}
					printf("Quantity of product available  : %lf",(m[j].quantity) );
					printf("Do you need the product ?\tEnter  1 : YES \t 2 : NO");
					scanf("%d", &ans);
					if(ans == 1){
						m[j].quantity = 0;
						fp = open("Allproduct.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fp == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count; i++)
							write(fp, &m[i], sizeof(m[i]));
						close(fp);
					
						fm = open("Allcostumer.txt",O_WRONLY | O_CREAT, S_IRUSR|S_IWUSR);
						if(fm == -1){
							perror("Open failed\n");
							return errno;
						}
						for(i = 0; i < count1; i++)
							write(fm, &cw[i], sizeof(cw[i]));
						close(fm);
					}
					else 
						printf("We will deginitely get you the required amount next time");		
					break;				
				}		
				else
					printf("Sorry, We would definitely get you the product next time");
				break;			
			}
			else	{
				if(counter == 0){
					printf("We dont have the product You require\n");
					counter++;
				}
				else
					break;
					
			}
		}

		printf("Do you want to continue shopping\t enter 1 : YES , 0 : NO");
		scanf("%d", &num);
	}while(num);		
	return 0;
}
