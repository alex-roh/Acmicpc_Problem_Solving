#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	long long N;
	
	cin >> N;
	str = to_string(N);
	
	long long cnt = 0, base = 1, i;
	for(i = 1; i <= str.size() - 1; i++){
		cnt += 9 * i * base;
		base *= 10;
	}
	
	long long remainder = N - base + 1;
	cnt += remainder * i;
	
	cout << cnt;
	
	return 0;
}
