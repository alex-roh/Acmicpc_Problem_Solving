#include <iostream>
#include <stack>
#define DIFF 55

using namespace std;

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// freopen("input.txt", "rt", stdin);
	
	long long n;
	int b;
	
	cin >> n >> b;
	stack<char> myStack;
	
	int cur = n;
	while(cur != 0){

		int remainder = cur % b;
		
		char reToChar;
		if(remainder >= 10){
			reToChar = (char) remainder + DIFF;
		}
		else {
			reToChar = (char) remainder + '0';
		}
		
		myStack.push(reToChar); 
		cur /= b;
		
	}

	while(!myStack.empty()){
		cout << myStack.top();
		myStack.pop();
	}
	
	return 0;
}
