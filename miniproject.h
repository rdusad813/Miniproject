
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
#include<stdlib.h>
#include<string.h>
#define SIZE 512
typedef struct date{
	int day;
	int month;
	int year;
}date;
typedef struct company{
	char str[128];
	double amount;
	date d;	
}company;	
typedef struct text {
	char *str;
	double amount;
	date d;	
	struct text *next, *prev;
}text;
typedef struct list{
	text *head, *tail;
	int length;
}list;
typedef struct item{
	char str[16];
	double price;
	double quantity;
	int serialkey;
}item;
typedef struct customerwacc{
	char name[16];
	char product[16];
	double quantity;
	double price;
}costwacc;
typedef struct customer{
	char product[16];
	double quantity;
	double price;
}cost;
typedef struct node {
	costwacc cw;
	struct node *next;
}node;
typedef struct queue {
	node *head, *tail;
}queue;
typedef struct node1{
	cost c;
	struct node1 *next;
}node1;
typedef struct queue1{
	node1 *head, *tail;
}queue1;
int updateitemhi();
int newitem();
int printmenu();
void printinventory();
int tobeordered();
int customerwacc();
int customerwtacc();
int printrecord();
int bill_cwa();
void bill_cwta(queue1 *q);
void qinit(queue *q);
void enqueue(queue *q, costwacc cw);
costwacc dequeue(queue *q);
int qempty(queue *q);
int qfull(queue *q);
void q1_init(queue1 *q);
void enqueue_1(queue1 *q, cost c);
cost dequeue_1(queue1 *q);
int q1_empty(queue1 *q);
int q1_full(queue1 *q);
void init(list *l);
void traverse(list *l);
void insert(list *l, char *str, double amount, date d);
void append(list *l, char *str, double amount, date d);
int length(list *l);
int companydet();
void checkbounces();
int printcompany();
int checkname();
int checkmonth();
int checkdate();
int checkamount();
int appendcompany();
