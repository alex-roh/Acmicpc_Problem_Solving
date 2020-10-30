#include <iostream>
#include <string>
#include <stack>

using namespace std; 

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string baseEightStr;
	getline(cin, baseEightStr);
	
	// 0이 들어오면 바로 0을 출력하고 끝냄
	if(baseEightStr.compare("0") == 0){
		cout << 0;
		return 0;
	}
	
	stack<int> stackForBaseTwo;
	int n = baseEightStr.size();
	
	for(int i = n - 1; i >= 0; i--){
		
		char cur = baseEightStr[i];
		
		int curNum = (int) cur - '0';
		int cnt = 0;
	
		while(true){
			stackForBaseTwo.push(curNum % 2);
			cnt++;
			curNum /= 2;
			if(curNum == 0) break;
		}
		
		for(int i = cnt; i < 3; i++)
			stackForBaseTwo.push(curNum % 2);
		
	}
	
	
	int top = stackForBaseTwo.top();
	while(top == 0){
		stackForBaseTwo.pop();
		top = stackForBaseTwo.top();
	}
	
	while(!stackForBaseTwo.empty()){
		
		top = stackForBaseTwo.top();
		cout << top;
		stackForBaseTwo.pop();
	
	}
	
	return 0;
}
