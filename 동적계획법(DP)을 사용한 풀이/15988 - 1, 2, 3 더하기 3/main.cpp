#include <iostream>

using namespace std;

long long D[1000001];
const int limit = 1000000;
const int mod = 1000000009;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	D[0] = 1;
	D[1] = 1;
	D[2] = 2;
	D[3] = 3;
	
	for(int n = 3; n <= limit; n++){
		D[n] = (D[n - 1] + D[n - 2] + D[n - 3]) % mod;
	}
	
	int cnt;
	cin >> cnt;
	while(cnt--){
		int input;
		cin >> input;
		cout << D[input] % mod << "\n";
	}
	
	return 0;
}
