 #include"miniproject.h"
void init(list *l) {
	l->head = l->tail = NULL;
	l->length = 0;
}
void traverse(list *l) {
	text *p;
	int i = 1;
	p = l->head;
	printf("\t\t\t\t\tS.No\tCOMPANY NAME\tAMOUNT\t\tDATE\n");
	while(p != l->tail) {
		printf("\t\t\t\t\t%d\t%s\t\t%lf\t%d-%d-%d\n", i, p->str, p->amount, p->d.day, p->d.month, p->d.year);
		p = p->next;
		i++;	
	}
	if(p)
		printf("\t\t\t\t\t%d\t%s\t\t%lf\t%d-%d-%d\n", i, p->str, p->amount, p->d.day, p->d.month, p->d.year);
	p = l->tail;
}

void insert(list *l, char *str, double amount, date d) {
	text *p, *tmp;
	int i, pos = 0;
	tmp = (text *)malloc(sizeof(text));
	tmp->str = (char *)malloc(strlen(str) + 1);
	strcpy(tmp->str, str);
	tmp->amount = amount;
	tmp->d = d;
	if(l->head == NULL) {
		tmp->next = tmp->prev = 
		l->head = l->tail = tmp;
		l->length = 1;
		return;
	}
	p = l->head;
	for(i = 0; i < pos - 1; i++)
		p = p->next;
	if(pos == 0)
		p = p->prev;
	
	tmp->prev = p;	
	tmp->next = p->next;
	p->next->prev = tmp;
 	p->next = tmp;
	if(pos == l->length)
		l->tail = tmp;
	if(pos == 0)
		l->head = tmp;
	pos++;	
	(l->length)++;
}

void append(list *l, char *str, double amount, date d) {
	text *tmp = (text *)malloc(sizeof(text));
	tmp->str = malloc(strlen(str)+1);
	strcpy(tmp->str, str);
	tmp->d = d;
	tmp->amount = amount;
	if(l->head) {
		tmp->next = l->head;
		tmp->prev = l->tail;
		l->head->prev = tmp;
		l->tail->next = tmp;
	} else {
		tmp->next = tmp->prev = l->head = tmp;
	}
	l->tail = tmp;	
	l->length++;
}

int length(list *l) {
	return l->length;
}
