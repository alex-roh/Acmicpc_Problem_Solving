#include <iostream>
#include <string>
#include <stack>
#define A 65
#define a 97

using namespace std;

int precedence(char oper){
	
	if(oper == '+' || oper == '-') return 1;
	else if(oper == '*' || oper == '/') return 2;
	else if(oper == '(') return 3; // ������ ���� ������ ����ֵ��� �� 
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	string inputStr;
	getline(cin, inputStr);
	
	stack<char> myStack;
	
	for(int i = 0; i < inputStr.size(); i++){
		
		char current = inputStr[i];
		
		// �ǿ������� ��� �׳� ��� 
		if((int)current >= A && (int)current < a){
			cout << current;
		}	
		// ���� ��ȣ�� �߰ߵ� ��� 
		else if(current == '('){
			myStack.push(current);
		}
		// �ݴ� ��ȣ�� �߰ߵ� ��� 
		else if(current == ')'){
			while(myStack.top() != '('){
				cout << myStack.top();
				myStack.pop();
			}
			myStack.pop(); // (�� ���� 
		}
		// �������� ��� ���� ���� 
		else {
			// ������ ��� �ְų� �Է��� �켱������ ���ú��� �� ���� ��� 
			if(myStack.empty() || precedence(myStack.top()) < precedence(current)){
				myStack.push(current);
			}
			// �Է��� �켱������ ���ð� ���ų� �� ���� ��� 
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
