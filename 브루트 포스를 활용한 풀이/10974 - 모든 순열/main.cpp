#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {

	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	// ���� ������ ���� ������ ���� ������ ����鼭 ����ؼ� ����Ѵ�.
	do {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(arr.begin(), arr.end()));
	
	return 0;

}
