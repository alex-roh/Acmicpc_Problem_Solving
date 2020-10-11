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
		
		// �±��� ������ <�� ������ ����ϰ� ���ÿ� push 
		if(c == '<'){
			// ������ ���� �ܾ ��� 
			while(!words.empty()){
				cout << words.top();
				words.pop();
			} 
			cout << c;
			words.push(c);
			continue;		
		}
		// >�� ������ ����ϰ� ���ÿ��� <�� pop 
		else if(c == '>'){
			cout << c;
			words.pop();
			continue;		
		}
		
		// �±� ���� ���ڴ� �״�� ���
		if(!words.empty() && words.top() == '<'){
			cout << c;
			continue;
		} 
		
		// ������ �ƴ� ���� ��� push 
		if(c != ' '){
			words.push(c);
		}
		// ������ ������ pop�� �� ���� ��� 
		else {
			while(!words.empty()){
				cout << words.top();
				words.pop();
			} 
			cout << c;
		}
	}
	
	// �������� ������ �����Ƿ� ���ÿ� �ִ� ���Ҹ� ��� ��� 
	while(!words.empty()){
		cout << words.top();
		words.pop();
	} 
			
	return 0;
}
