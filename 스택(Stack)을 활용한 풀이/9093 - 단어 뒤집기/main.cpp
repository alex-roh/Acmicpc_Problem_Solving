#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int cnt;
	cin >> cnt; // ���๮�ڴ� �Է¹��� ���� 
	cin.ignore();
	
	while(cnt--){
		
		stack<char> mystack;
		string sentence;
		getline(cin, sentence); // ������ ���๮�ڷκ��� ���� ���๮�ڱ��� �ִ� ���� ��� �Է¹��� 
		sentence += '\n';
		
		for(char ch : sentence){
			
			if(ch != ' ' && ch != '\n'){
				mystack.push(ch);
			}
			else {
				while(!mystack.empty()){
					cout << mystack.top();
					mystack.pop();
				}
				cout << ch;
			}
		}
	}
	
	return 0;
}
