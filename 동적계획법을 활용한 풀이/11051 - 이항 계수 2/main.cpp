#include <iostream>

using namespace std;

long long C[1001][1001];

int mod = 10007;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	
	for(int n = 1; n <= N; n++){
		C[n][0] = 1;
		C[n][n] = 1;
		for(int k = 1; k < n; k++){
			C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % mod;	
		}
	}
	
	cout << C[N][K];
	
	return 0;
}
