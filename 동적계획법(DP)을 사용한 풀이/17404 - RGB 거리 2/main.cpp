#include <iostream>
#include <climits>
#define R 1
#define G 2
#define B 3

using namespace std;

int C[1001][4];
long long D[1001][4];

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> C[i][R] >> C[i][G] >> C[i][B];
	}
	
	int minVal = INT_MAX;
	
	// 첫번째 집의 색이 R, G, B일때에 대한 반복문 
	for(int color = R; color <= B; color++){
		
		// 첫번째 집의 색으로 for문 변수인 color를 선택하기 위해
		// 다른 색의 DP 배열에는 최대한 큰 값을 설정해줌
		for(int i = R; i <= B; i++){
			if(i == color){
				D[1][color] = C[1][color];
			}
			else {
				D[1][i] = 1000 * 1000;	
			}
		}
		
		for(int i = 2; i <= N; i++){
			
			D[i][R] = min(D[i-1][G], D[i-1][B]) + C[i][R];
			D[i][G] = min(D[i-1][R], D[i-1][B]) + C[i][G];
			D[i][B] = min(D[i-1][R], D[i-1][G]) + C[i][B];
			
		}
		
		for(int i = R; i <= B; i++){
			// 첫번째 집의 색과 n번째 집의 색이 같은 경우는 패스 
			if(i == color){
				continue;
			}
			else {
				// 최소 비용을 캐싱함 
				if(minVal > D[N][i]){
					minVal = D[N][i];
				}
			}
		}
		
	}
	
	cout << minVal;
	
	return 0;
}
