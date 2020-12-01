#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int T[501][501];
int D[501][501]; // D[i][j] = 경로의 마지막 수가 i, j일 때의 최대합 

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			cin >> T[i][j];
		}	
	}
	
	D[1][0] = 0;
	D[1][1] = T[1][1];
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			
			D[i][j] = max(D[i-1][j-1], D[i-1][j]) + T[i][j];
			
		}	
	}
	
	int max = INT_MIN;
	for(int i = 1; i <= N; i++){
		if(D[N][i] > max)
			max = D[N][i]; 
	}
	
	cout << max;
	
	return 0;
}
