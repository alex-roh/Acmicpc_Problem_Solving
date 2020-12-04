#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int cnt;
	cin >> cnt; // 개행문자는 입력받지 않음 
	cin.ignore();
	
	while(cnt--){
		
		stack<char> mystack;
		string sentence;
		getline(cin, sentence); // 마지막 개행문자로부터 다음 개행문자까지 있는 것을 모두 입력받음 
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
