#include <iostream>
#include <algorithm>

using namespace std;

long long D[4][100001];
long long C[3][100001];

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int testCnt;
	cin >> testCnt;
	
	while(testCnt--){
		
		int n;
		cin >> n;
		
		for(int i = 1; i <= 2; i++){
			for(int j = 1; j <= n; j++){
				cin >> C[i][j];
			}
		}
	
		D[1][1] = C[1][1];
		D[2][1] = C[2][1];
		D[3][1] = 0; // 1행과 2행 중 어느 것도 뽑지 않은 경우 
	
		for(int i = 2; i <= n; i++){
			D[1][i] = max(D[2][i - 1], D[3][i - 1]) + C[1][i];
			D[2][i] = max(D[1][i - 1], D[3][i - 1]) + C[2][i];
			D[3][i] = max(max(D[1][i - 1], D[2][i - 1]), D[3][i - 1]);
		}
		
		cout << max(max(D[1][n], D[2][n]), D[3][n]) << "\n";
		
	}
	
	return 0;
}
