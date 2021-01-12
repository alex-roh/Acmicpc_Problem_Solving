#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// D[N] : N만큼의 무게가 가방에 남았을 때 담을 수 있는 최댓값
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

			// 가방에 아이템을 담을 수 있고 해당 아이템을 이전에 담지 않은 경우에만			
			if(selected[i] == false && remainingWeight >= itemWeight){
				
				int remainingWeightAfter = remainingWeight - itemWeight; // 해당 아이템을 담고 난 이후 가방의 남은 무게 
				int valueAfter = D[remainingWeight] + itemValue;
				
				//최대값을 갱신하지 않은 경우 
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
