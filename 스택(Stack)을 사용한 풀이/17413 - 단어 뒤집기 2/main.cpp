#include <iostream>
#include <stack> 
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("in5.txt", "rt", stdin);
	
	string str;
	getline(cin, str);
	
	stack<char> words;
	
	for(char c : str){
		
		// 태그의 시작인 <이 들어오면 출력하고 스택에 push 
		if(c == '<'){
			// 이전에 들어온 단어를 출력 
			while(!words.empty()){
				cout << words.top();
				words.pop();
			} 
			cout << c;
			words.push(c);
			continue;		
		}
		// >이 들어오면 출력하고 스택에서 <을 pop 
		else if(c == '>'){
			cout << c;
			words.pop();
			continue;		
		}
		
		// 태그 안의 문자는 그대로 출력
		if(!words.empty() && words.top() == '<'){
			cout << c;
			continue;
		} 
		
		// 공백이 아닌 경우는 모두 push 
		if(c != ' '){
			words.push(c);
		}
		// 공백이 들어오면 pop한 후 공백 출력 
		else {
			while(!words.empty()){
				cout << words.top();
				words.pop();
			} 
			cout << c;
		}
	}
	
	// 마지막엔 공백이 없으므로 스택에 있는 원소를 모두 출력 
	while(!words.empty()){
		cout << words.top();
		words.pop();
	} 
			
	return 0;
}
