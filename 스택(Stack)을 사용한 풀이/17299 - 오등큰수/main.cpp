#include <iostream>
#include <vector>
#include <iterator>
#include <stack>

using namespace std;

vector<int> countVec(1000001);

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	cin.tie(0);
  	cout.tie(0);
  	ios::sync_with_stdio(0);	

	int n;
	cin >> n;
	
	vector<int> oldVec(n);
	
	for(int i = 0; i < n; i++){
		int current;
		cin >> current;
		countVec[current]++;
		oldVec[i] = current;
	}
	
	vector<int> newVec(n);
	
	for(int i = 0; i < n; i++){
		int index = oldVec[i];
		newVec[i] = countVec[index];		
	}
	
	vector<int> answerList(n, -1);
	stack<pair<int, int>> mystack;
	
	for(int i = 0; i < n; i++){
		
		while(!mystack.empty() && mystack.top().second < newVec[i]){
			
			// ������ ž�� ���� ����ū���� ã�� 
			int stackTopIndex = mystack.top().first;
			int ngbOfStackTop = oldVec[i];
			answerList[stackTopIndex] = ngbOfStackTop;
			mystack.pop();
		
		}
		
		// �ش� ���� ���� ����ū���� ã�� ���� Ǫ��
		mystack.push(make_pair(i, newVec[i])); 
		
	}
	
	copy(answerList.begin(), answerList.end(), ostream_iterator<int>(cout, " "));
	
	
	
	return 0;
}
