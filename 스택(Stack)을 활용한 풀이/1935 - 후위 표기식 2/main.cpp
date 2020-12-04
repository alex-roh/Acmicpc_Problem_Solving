#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#define A 65
#define a 97

using namespace std; 

int alpha[100];

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// freopen("input.txt", "rt", stdin);
	
	int size;
	cin >> size;
		
	string postfix;
	cin.ignore();
	getline(cin, postfix);
	
	int startIndex = A;
	for(int i = 0; i < size; i++){
		int input;
		cin >> input;
		alpha[startIndex++] = input; 
	}
	
	stack<double> myStack;
	
	for(int i = 0; i < postfix.size(); i++){
		
		char current = postfix[i];
		
		if((int) current < a && (int) current >= A){
			int oprd = alpha[(int)current];
			myStack.push((double)oprd);		
		}
		else {
			// 연산자가 나온 경우 계산 
			double oprd2 = myStack.top();
			myStack.pop();
			double oprd1 = myStack.top();
			myStack.pop();
			// 계산
			double result;
			switch(current){
				case '+':
					result = oprd1 + oprd2;
					break;
				case '-':
					result = oprd1 - oprd2;
					break;
				case '/':
					result = oprd1 / oprd2;
					break;
				case '*':
					result = oprd1 * oprd2;
					break;
			}
			myStack.push(result); 
		}
	}
	
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << myStack.top();
	
	return 0;
}
