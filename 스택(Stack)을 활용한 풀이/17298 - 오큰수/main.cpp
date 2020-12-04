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
			
			// ������ ž�� ���� ��ū���� ã�� 
			int stackTopIndex = mystack.top().first;
			int ngbOfStackTop = current;
			answerList[stackTopIndex] = ngbOfStackTop;
			mystack.pop();
		
		}
		
		// �ش� ���� ���� ��ū���� ã�� ���� Ǫ��
		mystack.push(make_pair(i, current)); 
		
	}
	
	copy(answerList.begin(), answerList.end(), ostream_iterator<int>(cout, " "));
	
	return 0;
}
