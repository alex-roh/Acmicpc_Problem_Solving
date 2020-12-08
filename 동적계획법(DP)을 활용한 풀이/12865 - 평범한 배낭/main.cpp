#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// D[N] : N��ŭ�� ���԰� ���濡 ������ �� ���� �� �ִ� �ִ�
int D[100001];
bool selected[101]; 
vector<pair<int, int>> items(101); // first - weight, second - value
int N, K;

void DFS(int remainingWeight, int value){
	
	if(remainingWeight <= 0){
		return;
	}
	else {
	
		for(int i = 1; i <= N; i++){

			int itemWeight = items[i].first;
			int itemValue = items[i].second;

			// ���濡 �������� ���� �� �ְ� �ش� �������� ������ ���� ���� ��쿡��			
			if(selected[i] == false && remainingWeight >= itemWeight){
				
				int remainingWeightAfter = remainingWeight - itemWeight; // �ش� �������� ��� �� ���� ������ ���� ���� 
				int valueAfter = D[remainingWeight] + itemValue;
				
				//�ִ밪�� �������� ���� ��� 
				if(D[remainingWeightAfter] < valueAfter){
					
					D[remainingWeightAfter] = valueAfter;
					selected[i] = true;
					DFS(remainingWeight - itemWeight, value);
					selected[i] = false;
					
				}	 
				
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
		int W, V;
		cin >> W >> V;
		items[i] = make_pair(W, V);
	}
	
	DFS(K, 0);	
	
	int max = -1;
	for(int i = 0; i <= K; i++){
		if(D[i] > max)
			max = D[i];
	}
	
	cout << max;
	
	return 0;
}
