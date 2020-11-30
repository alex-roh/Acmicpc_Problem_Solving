#include <iostream>
#include <climits>

using namespace std;

int arr[1001];
int D[1001];

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		D[i] = 1;
	}
	
	int res = 1;
	
	for(int i = 2; i <= n; i++){
		int max = 0;
		for(int j = i - 1; j > 0; j--){
			if(arr[j] < arr[i] && D[j] > max){
				max = D[j];
			}
		}
		D[i] += max;
		if(D[i] > res){
			res = D[i];
		}
	}
	
	cout << res;
	
	return 0;
}
