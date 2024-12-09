typedef struct {
	FILE* f;
	char noteName[20];
}information;

typedef struct {
	information data;
	struct Node* next;
}Node;

Node* head;
Node* p;
