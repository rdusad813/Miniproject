
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

#include"miniproject.h"
void q1_init(queue1 *q){
	q->head = NULL;
	q->tail = NULL;
}
void enqueue_1(queue1 *q, cost c){
	node1 *tmp1;
	tmp1 = (node1 *)malloc(sizeof(node1));
	tmp1->c = c;	
	tmp1->next = NULL;
	if(q->tail == NULL)
		q->head = tmp1;
	else 
		q->tail->next = tmp1;
	q->tail = tmp1;
	
}
cost dequeue_1(queue1 *q){
	node1 *tmp1 = q->head->next;
	cost retdata = q->head->c;
	free(q->head);
	q->head = tmp1;
	if(q->head == NULL)
		q->tail = NULL;
	return retdata;
}
int q1_empty(queue1 *q){
	if(q->head == NULL)
		return 1;
	return 0;
}
int q1_full(queue1 *q){
	return 0;
}

