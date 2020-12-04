#include <iostream>
#include <algorithm>

using namespace std;

int S[301];
long long D[301][2];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	N++; // 시작점을 앞에 추가함 
	
	S[1] = 0; // 시작점의 스코어는 0 
	for(int i = 2; i <= N; i++){
		cin >> S[i];
	}	
	
	D[1][1] = S[1];
	D[1][0] = S[1];
	
	for(int n = 2; n <= N; n++){
		
		if(n == 3){
			D[n][1] = max(D[n-1][1], D[n-1][0]) + S[n];
			D[n][0] = max(D[n-2][1], D[n-2][0]) + S[n];	
		}
		else {
			
			D[n][1] = D[n-1][0] + S[n];
			D[n][0] = max(D[n-2][1], D[n-2][0]) + S[n];
		
		}
		
	}
	
	cout << max(D[N][1], D[N][0]);
	
	return 0;
}
