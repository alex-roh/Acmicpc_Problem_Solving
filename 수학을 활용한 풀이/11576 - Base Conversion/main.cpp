#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// freopen("input.txt", "rt", stdin);
	
	int base;
	int myBase;
	
	cin >> base >> myBase;
	
	int m;
	cin >> m;
	long long toBeConvertedNum = 0;
	int power = m - 1;
	
	while(m--){
		
		int cur;
		cin >> cur;
		
		int toBeMultiplied = 1;
	
		int currentPower = power;	
		while(currentPower--){
			toBeMultiplied *= base;
		}
		
		int toBePushedCur = cur * toBeMultiplied;
		
		toBeConvertedNum += toBePushedCur;
		power--;
		
	}
	
	stack<int> myStack;
	while(toBeConvertedNum != 0){
		myStack.push(toBeConvertedNum % myBase);
		toBeConvertedNum /= myBase;
	}
	
	while(!myStack.empty()){
		cout << myStack.top() << " ";
		myStack.pop();
	}
	
	return 0;
}
