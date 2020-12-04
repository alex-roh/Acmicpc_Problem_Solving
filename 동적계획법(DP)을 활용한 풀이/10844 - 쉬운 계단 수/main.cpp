#include <iostream>

using namespace std;
long long D[101][10];                                                                                                     

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	D[1][0] = 0;
	for(int i = 1; i <= 9; i++){
		D[1][i] = 1;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= 9; j++){
			
			if(j < 9 && j > 0){
				D[i][j] = (D[i-1][j-1] + D[i-1][j+1]) % 1000000000;
			}
			else if(j == 9){
				D[i][j] = D[i-1][j-1] % 1000000000;
			}
			else if(j == 0){
				D[i][j] = D[i-1][j+1] % 1000000000;
			}
		}
	}
	
	long long sum = 0;
	for(int i = 0; i <= 9; i++){
		sum = (sum + D[n][i]) % 1000000000;
	}
	
	cout << sum;
	
	return 0;
}
