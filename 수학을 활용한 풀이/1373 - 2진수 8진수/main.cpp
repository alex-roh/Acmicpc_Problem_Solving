#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std; 

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string baseTwoStr;
	getline(cin, baseTwoStr);
	
	int n = baseTwoStr.size();
	
	// 뒤에서부터 카운트 
	stack<int> myStack;
	for(int i = n - 1; i >= 0; ){
		
		int num = 0;
		int cnt = 3;
		
		for(int j = 0; j < 3; j++){
			
			char cur = baseTwoStr[i - j];
			if(cur == '1') num += pow(2, j);
			
		}
		
		myStack.push(num);
		i -= 3;
	}
	
	while(!myStack.empty()){
		cout << myStack.top();
		myStack.pop();
	}
	
	return 0;
}
