#include <iostream>
#include <cmath>

using namespace std;

int D[100001];

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int N = 1; N <= n; N++){
		D[N] = N; // (1^2) * N = N인 경우가 최대값이므로
		
		// D[N] = min(D[N - i^2]) + 1에서 i의 범위는 1부터 root N까지 
		for(int i = 1; i * i <= N; i++){
			// 지금 구한 D[N - i^2] + 1이 D[N]보다 작아서 갱신해야 하는 경우
			if(D[N] > D[N - i * i] + 1){
				D[N] = D[N - i * i] + 1;
			}
		}	
	}
	
	cout << D[n];
	
	return 0;
}
