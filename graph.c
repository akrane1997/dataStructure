
struct VertexNode *start = NULL;

void addVertex(char data) {
	struct VertexNode *v = (struct VertexNode *) malloc(sizeof(struct VertexNode));
	v->data = data;
	v->start = NULL;
	v->next = NULL;

	if(start == NULL)
		start = v;
	else {
		struct VertexNode *temp;
		for(temp = start; temp->next != NULL; temp = temp->next) {
		}
		temp->next = v;  // New vertex attached at end of list
	}
}
void addEdge(char v1, char v2) {
	struct VertexNode *vn1, *vn2;
	struct EdgeNode *e;
	vn1 = searchVertex(v1);
	if (vn1 == NULL) {
		printf("\n%c not found", v1);
		return;
	}

	vn2 = searchVertex(v2);
	if (vn2 == NULL) {
		printf("\n%c not found", v2);
		return;
	}
	// Create new edge

	e = (struct EdgeNode *) malloc(sizeof(struct EdgeNode));
	e->v = vn2;
	e->next = NULL;
	if (vn1->start == NULL)
		vn1->start = e;
	else {
		struct EdgeNode *temp;
		for(temp = vn1->start; temp->next != NULL; temp = temp->next) {
		}
		temp->next = e;
	}
}
struct VertexNode* searchVertex(char data) {
	struct VertexNode *temp;
	for(temp = start; temp != NULL; temp = temp->next) {
		if (temp->data == data)
			return temp;
	}
	return NULL;
}

void display() {
	struct VertexNode *temp;
	struct EdgeNode *e;
	printf("\nVertices are...\n");
	for(temp=start; temp != NULL; temp = temp->next) {
		printf("\nVertex %c",temp->data);
		printf(" Adjacent Vertices are...");
		for(e = temp->start; e != NULL; e = e->next) {
			printf("%c ",e->v->data);
		}
	}
}
void main() {
	addVertex('0');
	addVertex('1');
	addVertex('2');
	addVertex('3');
}
