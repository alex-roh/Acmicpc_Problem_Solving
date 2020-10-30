#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	
	if(n == 0){
		cout << 0;
		return 0;
	}
	
	int cur = n;
	stack<int> stackForBaseTwo;
	
	while(cur != 0){
	
		if(cur % 2 == 0){
			cur = -(cur / 2);
			stackForBaseTwo.push(0);
		}
		else {
			// Ȧ���̸鼭 ����� ��� 
			if(cur > 0){
				cur = -(cur / 2);	
			}
			// Ȧ���̸鼭 ������ ��� (����) 
			else {
				// e.g., -13 = -2 * 7 + 1 
				cur = -((cur - 1) / 2);		
			}
			stackForBaseTwo.push(1);
		}
	}
	
	while(!stackForBaseTwo.empty()){
		cout << stackForBaseTwo.top();
		stackForBaseTwo.pop();
	}
	
	return 0;
}
