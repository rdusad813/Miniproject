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

