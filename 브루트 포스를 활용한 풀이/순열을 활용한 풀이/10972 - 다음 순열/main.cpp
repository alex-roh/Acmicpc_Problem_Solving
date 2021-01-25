#include <iostream>
#include <algorithm>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int arr[10001];
int ans[10001];

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	// 1. A[i - 1] < A[i]�� �����ϴ� ���� ū i�� ã��
	int i = -1;
	for(int k = 1; k <= N; k++){
		if(arr[k - 1] < arr[k]){
			i = k;
		}
	}
	
	if(i == -1){
		cout << -1;
		return 0;
	}
	
	// 2. A[j] > A[i-1]�� ������Ű�� ���� ū j�� ã�� 
	int j;
	for(int k = i; k < N; k++){
		if(arr[k] > arr[i - 1]){
			j = k;
		}
	}
	
	// 3. A[i-1]�� A[j]�� �����Ѵ�
	swap(arr[i - 1], arr[j]);
	
	// 4. A[i]���� ������ ������
	int cursor = i;
	for(int k = N - 1; k >= 0; k--){
		if(k >= i){
			ans[cursor] = arr[k];
			cursor++;	
		}	
		else
			ans[k] = arr[k];
	}
	
	for(int k = 0; k < N; k++){
		cout << ans[k] << ' ';
	}
	
	return 0;
}
