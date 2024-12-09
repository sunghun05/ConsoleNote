void enter(FILE* file);
FILE* newNote(Node* newNode) {
	FILE* f;
	int mode = 0;
	while (1) {

		mode = 0;

		printf("select format : .txt / .bin : 0/1 >>");
		scanf("%d", &mode);

		printf("new note title >>");
		scanf("%s", newNode->data.noteName);

		switch (mode) {
		case 0:
			strcat(newNode->data.noteName, ".txt");

			break;
		case 1:
			strcat(newNode->data.noteName, ".bin");
			break;
		}

		if (checkSame(newNode->data.noteName) == -1) {
			printf("note named %s is already exists\n", newNode->data.noteName);
		}
		else {
		
			break;
		}
	}

	if (mode == 0) {
		if ((f = fopen(newNode->data.noteName, "w")) == NULL) {
			printf("error::newNote\n");
			exit(1);
		}
		printf("empty %s is created.\n", newNode->data.noteName);

		printf("enter content (exit with ^+z)\n");
		enter(f);
	}
	else {
		if (f = fopen(newNode->data.noteName, "wb") == NULL) {
			printf("error::newNote\n");
			exit(1);
		}
		printf("empty %s is created.\n", newNode->data.noteName);

		printf("enter content (exit with ^+z)\n");
	}
	
	fclose(f);
	return f;
}
FILE* readNote(Node* tmp, int mode) {

	tmp = (Node*)malloc(sizeof(Node));
	tmp = head;

	for (int i = 1; i <= mode; i++) {

		tmp = tmp->next;
	}

	FILE* f;

	if ((f = fopen(tmp->data.noteName, "r")) == NULL) {
		printf("error::readNote\n");
		exit(1);
	}
	printf("%s content::\n", tmp->data.noteName);

	char line[100];
	fseek(f, SEEK_SET, 0);
	while (fgets(line, 100, f) != NULL) {
		printf("%s", line);
	}
	
	fclose(f);
	printf("\nclosed.\n");

	return f;
}

void enter(FILE* file) {
	
	char line[100];
	int lineNum = 1;

	while (1) {
		fprintf(file, "%d", lineNum);
		if (fgets(line, 100, stdin) == NULL) {
			break;
		}
		
		lineNum++;
		fputs(line, file);

	}
}
void modify(void) {



}