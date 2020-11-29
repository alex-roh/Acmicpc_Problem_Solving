#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr(1001);

long long DP(int n){
	
	// 2x1�� ��� 2x1 Ÿ�� �ϳ��ιۿ� ���� �� ���� 
	arr[1] = 1;
	// 2x2�� ��� 2x1 Ÿ�� 2�� or 1x2 Ÿ�� 2��
	arr[2] = 2; 
	
	for(int i = 3; i <= n; i++){
		
		// arr[i - 1] -> �� �����ʿ�  2x1 Ÿ���� 1�� ���� ���
		// arr[i - 2] -> �� �����ʿ� 1x2 Ÿ���� 2�� ���� ��� 
		// ���갪�� ������ ũ�� ������ ���� ���� ��� 10007�� ���� ���� 
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
		
	}
	
	return arr[n];
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	cout << DP(n);
	
	return 0;
}
