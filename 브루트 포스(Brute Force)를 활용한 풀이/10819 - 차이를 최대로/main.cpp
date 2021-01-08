#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[10];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	int max = -1;
	
	do {
		int sum = 0;
		for(int i = 0; i + 1 < n; i++){
			sum += abs(arr[i] - arr[i + 1]);	
		}
		if(sum > max) max = sum;
		
	} while(next_permutation(arr, arr + n));
	
	cout << max;
	
	return 0;
}
