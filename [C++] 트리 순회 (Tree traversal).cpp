#include <iostream>
#include <queue>
using namespace std;

typedef struct node {
	char value;
	struct node * reftChild;
	struct node * rightChild;

	node(const char val) {
		this->value = val;
		this->reftChild = NULL;
		this->rightChild = NULL;
	}
} Node;

typedef struct root {
	Node * currentNode;
} Root;

void preOrder(Node * node) {
	if (node) {
		cout << "※ PreOrder: " << node->value << endl;
		preOrder(node->reftChild);
		preOrder(node->rightChild);
	}
}

void inOrder(Node * node) {
	if (node) {
		inOrder(node->reftChild);
		cout << "※ InOrder: " << node->value << endl;
		inOrder(node->rightChild);
	}
}

void postOrder(Node * node) {
	if (node) {
		postOrder(node->reftChild);
		postOrder(node->rightChild);
		cout << "※ PostOrder: " << node->value << endl;
	}
}

void leverOrder(Node * node) {

	queue<Node*> que;
	que.push(node);

	while (!que.empty()) {

		Node * child = que.front();	que.pop();
		cout << "※ LevelOrder: " << child->value << endl;

		if (child->reftChild) { que.push(child->reftChild); }
		if (child->rightChild) { que.push(child->rightChild); }
	}
}

Node * createTree() 
{
	// Create Node
	Node * childNode1 = new Node('F');
	Node * childNode2 = new Node('A');
	Node * childNode3 = new Node('B');
	Node * childNode4 = new Node('C');
	Node * childNode5 = new Node('D');
	Node * childNode6 = new Node('E');
	Node * childNode7 = new Node('F');
	Node * childNode8 = new Node('G');
	Node * childNode9 = new Node('H');
	Node * childNode10 = new Node('I');

	// F Node
	childNode1->reftChild = childNode3;
	childNode1->rightChild = childNode8;

	// G Node
	childNode8->rightChild = childNode10;

	// B Node
	childNode3->reftChild = childNode2;
	childNode3->rightChild = childNode5;

	// D Node
	childNode5->reftChild = childNode4;
	childNode5->rightChild = childNode6;

	// I Node
	childNode10->reftChild = childNode9;
	
	return childNode1;
}

int main(void) 
{
	Root * head = new Root();
	head->currentNode = createTree();
	
	preOrder(head->currentNode);
	inOrder(head->currentNode);
	postOrder(head->currentNode);
	leverOrder(head->currentNode);

	return 0;
}
