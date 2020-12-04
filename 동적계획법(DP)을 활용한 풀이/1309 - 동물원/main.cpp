#include <iostream>

using namespace std;

long long D[100001][3];
const int mod = 9901;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	 
	D[1][0] = 1; // 왼쪽에 사자 
	D[1][1] = 1; // 오른쪽에 사자
	D[1][2] = 1; // 사자를 놓지 않음 
	
	for(int i = 2; i <= n; i++){
		D[i][0] = (D[i - 1][1] + D[i - 1][2]) % mod;
		D[i][1] = (D[i - 1][0] + D[i - 1][2]) % mod;
		D[i][2] = (D[i - 1][0] + D[i - 1][1] + D[i - 1][2]) % mod;
	} 
	
	cout << (D[n][0] + D[n][1] + D[n][2]) % mod;
	
	return 0;
}
