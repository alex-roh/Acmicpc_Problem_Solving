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
	
	// ù��° ���� ���� R, G, B�϶��� ���� �ݺ��� 
	for(int color = R; color <= B; color++){
		
		// ù��° ���� ������ for�� ������ color�� �����ϱ� ����
		// �ٸ� ���� DP �迭���� �ִ��� ū ���� ��������
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
			// ù��° ���� ���� n��° ���� ���� ���� ���� �н� 
			if(i == color){
				continue;
			}
			else {
				// �ּ� ����� ĳ���� 
				if(minVal > D[N][i]){
					minVal = D[N][i];
				}
			}
		}
		
	}
	
	cout << minVal;
	
	return 0;
}
