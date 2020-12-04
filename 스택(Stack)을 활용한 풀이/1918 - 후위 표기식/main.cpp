#include <iostream>
#include <string>
#include <stack>
#define A 65
#define a 97

using namespace std;

int precedence(char oper){
	
	if(oper == '+' || oper == '-') return 1;
	else if(oper == '*' || oper == '/') return 2;
	else if(oper == '(') return 3; // 무조건 스택 안으로 집어넣도록 함 
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	string inputStr;
	getline(cin, inputStr);
	
	stack<char> myStack;
	
	for(int i = 0; i < inputStr.size(); i++){
		
		char current = inputStr[i];
		
		// 피연산자인 경우 그냥 출력 
		if((int)current >= A && (int)current < a){
			cout << current;
		}	
		// 여는 괄호가 발견된 경우 
		else if(current == '('){
			myStack.push(current);
		}
		// 닫는 괄호가 발견된 경우 
		else if(current == ')'){
			while(myStack.top() != '('){
				cout << myStack.top();
				myStack.pop();
			}
			myStack.pop(); // (를 제거 
		}
		// 연산자인 경우 스택 조작 
		else {
			// 스택이 비어 있거나 입력의 우선순위가 스택보다 더 높은 경우 
			if(myStack.empty() || precedence(myStack.top()) < precedence(current)){
				myStack.push(current);
			}
			// 입력의 우선순위가 스택과 같거나 더 낮은 경우 
			else {
				while(!myStack.empty() && myStack.top() != '(' &&
						precedence(current) <= precedence(myStack.top())){
					cout << myStack.top();
					myStack.pop();
				}	
				myStack.push(current);
			} 
		}
	}
	
	while(!myStack.empty()){
		cout << myStack.top();
		myStack.pop();
	}
	
	return 0;
}
