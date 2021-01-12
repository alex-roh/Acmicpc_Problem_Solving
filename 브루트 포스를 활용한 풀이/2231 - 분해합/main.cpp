#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int res = -1;
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		
		int temp = i;
		string str = to_string(temp);
		
		for(int j = 0; j < str.size(); j++){
			temp += str[j] - '0';
		}
		
		if(temp == N){
			res = i;
			break;
		}
		
	}
	
	if(res == -1){
		cout << 0;
	}
	else {
		cout << res;
	}
	
	return 0;
}
