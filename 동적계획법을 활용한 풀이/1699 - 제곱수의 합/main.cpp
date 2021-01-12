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
		D[N] = N; // (1^2) * N = N�� ��찡 �ִ밪�̹Ƿ�
		
		// D[N] = min(D[N - i^2]) + 1���� i�� ������ 1���� root N���� 
		for(int i = 1; i * i <= N; i++){
			// ���� ���� D[N - i^2] + 1�� D[N]���� �۾Ƽ� �����ؾ� �ϴ� ���
			if(D[N] > D[N - i * i] + 1){
				D[N] = D[N - i * i] + 1;
			}
		}	
	}
	
	cout << D[n];
	
	return 0;
}
