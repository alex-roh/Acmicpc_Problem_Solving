#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>

using namespace std; 

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	
	vector<int> answerList(n, -1);
	stack<pair<int, int>> mystack;
	
	for(int i = 0; i < n; i++){
		
		int current;
		cin >> current;
		
		while(!mystack.empty() && mystack.top().second < current){
			
			// 스택의 탑에 대한 오큰수를 찾음 
			int stackTopIndex = mystack.top().first;
			int ngbOfStackTop = current;
			answerList[stackTopIndex] = ngbOfStackTop;
			mystack.pop();
		
		}
		
		// 해당 수에 대한 오큰수를 찾기 위해 푸쉬
		mystack.push(make_pair(i, current)); 
		
	}
	
	copy(answerList.begin(), answerList.end(), ostream_iterator<int>(cout, " "));
	
	return 0;
}
