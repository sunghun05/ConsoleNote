#include "file.c"

static int cnt = 0;

int init(void) {
	head = (Node*)malloc(sizeof(Node));
	p = (Node*)malloc(sizeof(Node));

	head->data.f = NULL;
	head->next = NULL;
	return 0;
}

int make() {

	if (head->next == NULL) {

		Node* newNode = (Node*)malloc(sizeof(Node));

		newNode->data.f = newNote(newNode);
		newNode->next = NULL;
		head->next = (Node*)newNode;
	}
	else {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		Node* newNode = (Node*)malloc(sizeof(Node));

		newNode->data.f = newNote(newNode);
		newNode->next = NULL;
		p->next = (Node*)newNode;
		}
	cnt++;
	return 0;
}

int ls() {
	p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%s   ", p->data.noteName);
	 }
	printf("\n");
	return 0;
}
int ls_r() {
	int mode = 0;
	p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%s   ", p->data.noteName);
	 }
	printf("\n");
	printf("choose file >> ");
	scanf("%d", &mode);
	Node* tmp;
	tmp = NULL;
	if (mode == -1) {
		del();
		exit(0);
	}
	else {
		readNote(tmp, mode);
	}

	return 0;
}
int checkSame(char name[]) {
	Node* tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp = head;

	while (tmp->next != NULL) {
		
		tmp = tmp->next;

		if (strcmp(tmp->data.noteName, name) == 0) {
			return -1;
		}
	 }
	return 0;
}
int del(void) {

	p = head;

	while (p->next != NULL) {
		Node* tmp;
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(p);
	return 0;
}