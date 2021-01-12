#include <iostream>

using namespace std; 

long long D[91][2];

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	D[1][0] = 0;
	D[1][1] = 1;
	D[2][0] = 1;
	D[2][1] = 0;
	
	for(int i = 3; i <= n; i++){
		D[i][0] = D[i-1][1] + D[i-1][0];
		D[i][1] = D[i-1][0];
	}
	
	cout << D[n][0] + D[n][1] << "\n";
	
	return 0;
}
