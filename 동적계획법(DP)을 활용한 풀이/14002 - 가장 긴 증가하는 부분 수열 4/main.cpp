#include <iostream>
#include <vector>

using namespace std;

int D[1001];
int arr[1001];
vector<int> cachedArr[1001];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		D[i] = 1;
	}
	
	int res = 1;
	int resIndex = 1;
	cachedArr[1].push_back(arr[1]);
	
	for(int i = 2; i <= n; i++){
		int max = 0;
		int maxIndex = 0;
		for(int j = i - 1; j > 0; j--){
			if(arr[j] < arr[i] && D[j] > max){
				max = D[j];
				maxIndex = j;
			}
		}
		D[i] += max;
		
		if(max != 0){
			cachedArr[i] = cachedArr[maxIndex];
			cachedArr[i].push_back(arr[i]);	
		}
		else {
			cachedArr[i].push_back(arr[i]);
		}
		
		if(D[i] > res){
			res = D[i];
			resIndex = i;
		}
	}
	
	cout << res << "\n";

	for(vector<int>::iterator it = cachedArr[resIndex].begin(); it != cachedArr[resIndex].end(); it++){
		cout << *it << " ";
	}
	
	return 0;
}
