#include <iostream>
#include <string>
#include <cmath>
#define DIFF 55

using namespace std; 

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// freopen("input.txt", "rt", stdin);
	
	string n;
	int b;
	cin >> n >> b;
	
	long long res = 0;
	
	int power = 0;
	for(int i = n.size() - 1; i >= 0; i--){
		
		char current = n[i];
		int curNum = (int) current;
		
		if(current >= 'A' && current <= 'Z')
			curNum -= DIFF;
		else 
			curNum -= (int) '0';
		
		int poweredNum = 1;
		int cnt = power;
		while(cnt--){
			poweredNum *= b;
		}
		
		res += poweredNum * curNum;
		power++;
		
	}
	
	cout << res;
	
	return 0;
}
