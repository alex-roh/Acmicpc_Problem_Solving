#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string input;
	while(getline(cin, input)){
		
		if(input == ".") break;
		
		stack<char> mystack;
		bool alreadyPrintFlag = false;
		
		for(char ch : input){
			
			if(ch == '[' || ch == '('){
				mystack.push(ch);
			}	
			else if(ch == ']'){
				if(mystack.empty() || mystack.top() != '['){
					cout << "no\n";
					alreadyPrintFlag = true;
					break;
				}
				mystack.pop();
			}
			else if(ch == ')'){
				if(mystack.empty() || mystack.top() != '('){
					cout << "no\n";
					alreadyPrintFlag = true;
					break;
				}
				mystack.pop();
			}
		}
		
		if(!alreadyPrintFlag){
			if(!mystack.empty())
				cout << "no\n";
			else
				cout << "yes\n";
		}
		
	}
	
	return 0;
}
