#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[50];
int arrForPermute[50];
int limit;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt;
	cin >> cnt;
	while(cnt){
		
		int n = cnt;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		for(int i = 0; i < n - 6; i++){
			arrForPermute[i] = 0;
		}
		for(int i = n - 6; i < n; i++){
			arrForPermute[i] = 1;
		}
		
		do{
			for(int i = 0; i < n; i++){
				if(arrForPermute[i] == 1)
					cout << arr[i] << " ";
			}
			cout << "\n";
			
		}while(next_permutation(arrForPermute, arrForPermute + n));
		
		cin >> cnt;
		cout << "\n";
	}
	
	return 0;
}
