#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long P[101];
	
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	P[6] = 3;
	P[7] = 4;
	P[8] = 5;
	P[9] = 7;
	P[10] = 9;
	
	int cnt;
	cin >> cnt;
	
	while(cnt--){
	
		int N;
		cin >> N;
	
		for(int i = 11; i <= N; i++){
			P[i] = P[i - 1] + P[i - 5];
		}
	
		cout << P[N] << "\n";	
	
	}
	
	return 0;
}
