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
	// ���� D[0]�� 1�� �ʱ�ȭ�� 
	D[0] = 1;
	
	// n�� ¦���� ���� ���� �� ���� 
	for(int i = 2; i <= N; i += 2){
		
		// �������� 3*2 Ÿ���� ���� ��� 
		D[i] = 3 * D[i - 2];
		
		// �������� 3*(4, 6, 8,...) Ÿ���� ���� ��� 
		for(int j = i - 4; j >= 0; j -= 2){
			D[i] += 2 * D[j];
		}
	}
	
	cout << D[N];
	
	return 0;
}
