#include <iostream>

using namespace std;

long long D[31];

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	// D[n] = 3*[n-2] + 2*[n-4] + 2*[n-6] + ...
	// D[2] = 3 * D[0]
	// D[4] = 3 * D[2] + 2 * D[0]
	// 따라서 D[0]을 1로 초기화함 
	D[0] = 1;
	
	// n이 짝수일 때만 만들 수 있음 
	for(int i = 2; i <= N; i += 2){
		
		// 마지막에 3*2 타일이 오는 경우 
		D[i] = 3 * D[i - 2];
		
		// 마지막에 3*(4, 6, 8,...) 타일이 오는 경우 
		for(int j = i - 4; j >= 0; j -= 2){
			D[i] += 2 * D[j];
		}
	}
	
	cout << D[N];
	
	return 0;
}
