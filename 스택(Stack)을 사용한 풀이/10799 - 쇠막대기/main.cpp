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
	
		// 레이저인 경우
		if(str[i] == '(' && str[i + 1] == ')'){
			answer += ironBarSize;
		} 
		// 쇠막대기의 시작인 경우 
		else if(str[i] == '(' && str[i + 1] == '('){
			ironBarSize++;
			answer++;
		}
		// 쇠막대기의 끝인 경우 
		else if(str[i] == ')' && str[i - 1] != '('){
			ironBarSize--;
		}
	}
	
	cout << answer;
	
	return 0;
}
