#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int D[10000000];
vector<pair<int, int>> items(101); // first - weight, second - value
bool selected[101];
int N, K;

void DFS(int index, int weight, int value){
	
	if(index > N){
		return;
	}
	else {
		for(int i = index; i <= N; i++){
			
			int weightAfter = weight + items[i].first;
			int valueAfter = value + items[i].second;
			
			
			if(weightAfter > K){
				continue;
			}
			if(D[weightAfter] > valueAfter){
				continue;
			}
			
			D[weightAfter] = valueAfter;
			DFS(i + 1, weightAfter, valueAfter);
		}		
	}
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++){
		int W, V;
		cin >> W >> V;
		items[i] = make_pair(W, V);
	}
	
	DFS(1, 0, 0);	
	
	
	int max = -1;
	for(int i = 1; i <= K; i++){
		if(D[i] > max)
			max = D[i];
	}
	
	cout << max;
	
	return 0;
}
