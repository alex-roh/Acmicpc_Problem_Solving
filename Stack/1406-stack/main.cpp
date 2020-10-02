#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string sentence;
	getline(cin, sentence);
	
	stack<char> leftStack;
	stack<char> rightStack;
	
	for(int i = 0; i < sentence.size(); i++){
		leftStack.push(sentence[i]);
	}
	
	int n;
	cin >> n;
	cin.ignore();
	
	while(n--){
		
		string operation;
		getline(cin, operation);
		
		if(operation == "L" && !leftStack.empty()){
			char ch = leftStack.top();
			leftStack.pop();
			rightStack.push(ch);	
		}
		else if(operation == "D" && !rightStack.empty()){
			char ch = rightStack.top();
			rightStack.pop();
			leftStack.push(ch);
		}
		else if(operation == "B" && !leftStack.empty()){
			leftStack.pop();
		}
		else if (operation[0] == 'P') {
			leftStack.push(operation[2]);
		}
	}
	
	while(!leftStack.empty()) {
		char ch = leftStack.top();
		rightStack.push(ch);
		leftStack.pop();
	}
	while(!rightStack.empty()) {
		cout << rightStack.top();
		rightStack.pop();
	}
	
	return 0;
}
