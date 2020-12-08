#include <iostream>
#include <vector> 
#include <functional>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> D(1000100, INT_MAX);
int C[101];

int N, K;

void DFS(int amount){
	
	if(amount >= K){
		return;
	}
	else {
		for(int i = 1; i <= N; i++){
			
			int toBeAmount = amount + C[i];
			
			// �� ���ų� ���� �������� toBeAmount�� �̹� ������� ��� 
			if(D[toBeAmount] <= D[amount] + 1){
				continue;
			}
			// toBeAmount�� �������� �ϴ� ��� 
			else {
				D[toBeAmount] = D[amount] + 1;
				DFS(toBeAmount);
			}
		}
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	
	for(int i = 1; i <= N; i++){
		int amt;
		cin >> amt;
		C[i] = amt;
		D[C[i]] = 1;
	}
	
	// ������ ������������ ����  
	sort(C + 1, C + N + 1, greater<int>());
	
	for(int i = 1; i <= N; i++)
		DFS(C[i]);
	
	if(D[K] == INT_MAX)
		cout << -1;
	else
		cout << D[K];
	
	return 0;
}
