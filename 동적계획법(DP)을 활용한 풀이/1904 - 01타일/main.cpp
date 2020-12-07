#include <iostream>

using namespace std;

int D[1000001];

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	D[0] = 1;
	D[1] = 1;
	
	for(int i = 2; i <= N; i++){
		D[i] = D[i - 1] + D[i - 2];
	}
	
	cout << D[N];
	
	return 0;
}
