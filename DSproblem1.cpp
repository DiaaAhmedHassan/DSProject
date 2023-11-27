#include<stdio.h>
const int max_size = 1000;
template <typename t>

struct stack {
	int top = -1;
	t arr[max_size];
	//push function
	void push(t element) {
		//increasing top 
		top++;
		// enter the new element to array
		arr[top] = element;
		//test push
		printf("%d", arr[top]);
	}
};

int main() {
	stack<int> s;


}