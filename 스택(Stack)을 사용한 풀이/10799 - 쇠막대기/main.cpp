#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("in2.txt", "rt", stdin);
	
	string str;
	getline(cin, str);
	int ironBarSize = 0;
	int answer = 0;
	
	for(int i = 0; i < str.size() - 1; i++){
	
		// �������� ���
		if(str[i] == '(' && str[i + 1] == ')'){
			answer += ironBarSize;
		} 
		// �踷����� ������ ��� 
		else if(str[i] == '(' && str[i + 1] == '('){
			ironBarSize++;
			answer++;
		}
		// �踷����� ���� ��� 
		else if(str[i] == ')' && str[i - 1] != '('){
			ironBarSize--;
		}
	}
	
	cout << answer;
	
	return 0;
}
