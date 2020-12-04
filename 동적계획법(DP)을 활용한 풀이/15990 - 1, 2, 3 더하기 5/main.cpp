#include <iostream>

// D[i][j] : i를 나타내는데 마지막 수를 j로 사용한 경우의 수 
long long D[100002][4];

using namespace std;

void DP(){
	
	for(int N = 1; N <= 100001; N++){
		
		if(N == 1){
			D[N][1] = 1;
			D[N][2] = 0;
			D[N][3] = 0;	
		}
		else if(N == 2){
			D[N][1] = D[N-1][2] + D[N-1][3];
			D[N][2] = 1;
			D[N][3] = 0;
		}
		else if(N == 3){
			D[N][1] = D[N-1][2] + D[N-1][3];
			D[N][2] = D[N-2][1] + D[N-2][3];
			D[N][3] = 1;
		}
		else if(N > 3){
			D[N][1] = D[N-1][2] + D[N-1][3];
			D[N][2] = D[N-2][1] + D[N-2][3];
			D[N][3] = D[N-3][1] + D[N-3][2];	
		}
		
		D[N][1] %= 1000000009LL;
		D[N][2] %= 1000000009LL;
		D[N][3] %= 1000000009LL;
		
	}
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	DP();
	
	int testCnt;
	cin >> testCnt;
	
	while(testCnt--){
		int n;
		cin >> n;
		cout << (D[n][1] + D[n][2] + D[n][3]) % 1000000009LL << "\n";
	}
	
	return 0;
}
