/*****************************************************************************
 * Copyright (C) Rishabh Dusad rdusad813@gmail.com
 
 * This file is part of Grocery Store management System.

 *   Grocery Store management System is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   Grocery Store management System is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with Grocery Store management System.  If not, see <http://www.gnu.org/licenses/>.

 *****************************************************************************/

#include"miniproject.h"
void qinit(queue *q){
	q->head = NULL;
	q->tail = NULL;
}
void enqueue(queue *q, costwacc cw){
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->cw = cw;	
	tmp->next = NULL;
	if(q->tail == NULL)
		q->head = tmp;
	else 
		q->tail->next = tmp;
	q->tail = tmp;
	
}
costwacc dequeue(queue *q){
	node *tmp = q->head->next;
	costwacc retdata = q->head->cw;
	free(q->head);
	q->head = tmp;
	if(q->head == NULL)
		q->tail = NULL;
	return retdata;
}
int qempty(queue *q){
	if(q->head == NULL)
		return 1;
	return 0;
}
int qfull(queue *q){
	return 0;
}

