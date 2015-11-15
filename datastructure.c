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

