#pragma warning(disable : 4996)
#include<stdlib.h>
#include<stdio.h>

struct Stack {
	char* data;
	int top;
	int capacity;
}myStack;

void creatStack(int capacity) {
	myStack.top = -1;
	myStack.capacity = capacity;
	myStack.data = (char*)malloc(myStack.capacity * sizeof(char));
}
void printStack() {
	
	for (int elementCounter = 0; elementCounter <= myStack.top; elementCounter++) {// ask
		printf("%c",myStack.data[elementCounter]);
	}
	
}

int isFull() {
	if (myStack.top == (myStack.capacity - 1))
		return -1;
	else return 0;
}
int isEmpty() {
	if (myStack.top == -1)
		return -1;
	else return 0;
}

int pop() {
	// first we need to check if stack is already empty
	if (isEmpty == -1) {
		printf("stack is Empty\n");
		return;
	}
	myStack.top--;
	return myStack.data[myStack.top + 1];
}
int push(char newData) {
	// first we need to check if stack is full
	if (isFull == -1) {
		printf("stack is full\n");
		return;
	}
	myStack.top++;
	myStack.data[myStack.top] = newData;
	return 0;
}

void expression_check(char* expression) {
	int charIndex = 0;
	while (expression[charIndex] != NULL) {
		if (expression[charIndex] == '{' || expression[charIndex] == '(' || expression[charIndex] == '[')
			push(expression[charIndex]);
		else if (expression[charIndex] == '}' && pop() != '{') {
				printf("unbalanced");
				return;
		}
		else if (expression[charIndex] == ')' && pop() != '(') {
			printf("unbalanced");
			return;
		}
		else if (expression[charIndex] == ']' && pop() != '[') {
			printf("unbalanced");
			return;
		}
		charIndex++;
	}
	if(myStack.top == -1)
		printf("balanced");
	else {
		printf("unbalanced\n");
		printStack();
	}
		
	
}
///////////////////////////////////driver////////////////////////////////////////////////

int main() {
	
	int userTextCapacity;
	printf("enter the maximum size of the text \n");
	scanf("%d", &userTextCapacity);
	creatStack(userTextCapacity);
	char* userText = (char*)malloc(userTextCapacity * sizeof(char));
	printf("enter the text to be checked \n");
	scanf("%s", userText);
	printf("user text%s\n", userText);

	expression_check(userText);

	free(userText);
	free(myStack.data);

}
