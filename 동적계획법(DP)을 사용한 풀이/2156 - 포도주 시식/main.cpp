#include <iostream>
#include <algorithm>

using namespace std;

int D[10001][3];
int W[10001];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> W[i];
	}
	
	D[0][0] = 0;
	D[0][1] = 0;
	D[0][2] = 0;
	D[1][0] = 0;
	D[1][1] = W[1];
	D[1][2] = W[1];
	
	for(int n = 2; n <= N; n++){
		
		// n번째 와인을 0번 연속으로 마시고 최대값을 구성하는 경우 
		D[n][0] = max(max(D[n-1][0], D[n-1][1]), D[n-1][2]);
		// ... 1번 연속... 
		D[n][1] = D[n-1][0] + W[n];
		// ... 2번 연속... 
		D[n][2] = D[n-2][0] + W[n-1] + W[n];
		
	}
	
	cout << max(max(D[N][0], D[N][1]), D[N][2]);
			
	return 0;
}
