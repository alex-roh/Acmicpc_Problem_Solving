#include <iostream>

using namespace std;

int A[10001];

void swap(int& a, int& b){
	
	int temp = a;
	a = b;
	b = temp;
	
}

bool prev_permutation(int *arr, int size){
	
	int i = size - 1; 
	// step 1
	while(i > 0 && arr[i - 1] <= arr[i]){
		i--;
	}
	if(i <= 0)
		return false;
	// step 2
	int j = size - 1;
	while(j >= i && arr[j] > arr[i - 1]){
		j--;
	}
	swap(arr[j], arr[i - 1]);
	j = size - 1;
	while(j > i){
		swap(arr[j], arr[i]);
		i++; j--;
	}
	return true;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	if(prev_permutation(A, N)){
		for(int i = 0; i < N; i++){
			cout << A[i] << " ";
		}
	}
	else{
		cout << -1;
	}
	
	return 0;
}
