#include <iostream>

using namespace std;

long long D[201][201];
const int mod = 1000000000;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	
	for(int n = 0; n <= N; n++){
		D[1][n] = 1;
	}
	
	for(int k = 2; k <= K; k++){
		for(int n = 0; n <= N; n++){
			for(int i = 0; i <= n; i++){
				D[k][n] = (D[k][n] + D[k - 1][n - i]) % mod;
			}
		}
	}
	
	cout << D[K][N] % mod << "\n";
	
	return 0;
}
