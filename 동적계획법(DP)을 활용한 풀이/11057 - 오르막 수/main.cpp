#include <iostream>

using namespace std;

long long D[1001][10];
const int mod = 10007;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	for(int i = 0; i <= 9; i++){
		D[1][i] = 1;
	}
	
	for(int n = 2; n <= N; n++){
		for(int i = 0; i <= 9; i++){
			if(i == 0){
				D[n][i] = (D[n][i] + D[n - 1][i]) % mod;
				continue;
			}
			for(int j = 0; j <= i; j++){
				D[n][i]	= (D[n][i] + D[n - 1][j]) % mod;
			}
		}
	}

	long long sum = 0;
	for(int i = 0; i <= 9; i++){
		sum = (sum + D[N][i]) % mod;
	}
	
	cout << sum;
	
	return 0;
}
