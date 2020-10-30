#include <iostream>
#include <vector>

using namespace std;

bool check[1000001];
int primes[1000001];
int primeCnt;

void getPrimesAndUpdateCheck(){
	
	check[0] = true;
	check[1] = true;
	
	for(int i = 2; i <= 1000001; i++){
		if(check[i] == false){
			primes[primeCnt++] = i;
			for(int j = i + i; j <= 1000001; j += i){
				check[j] = true;
			}	
		}
	}
	
}

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	getPrimesAndUpdateCheck();
	
	int n;
	cin >> n;
	
	while(n--){
		
		int cur;
		cin >> cur;
		int cnt = 0;
		
		// cout << "cur is " << cur << "\n";
		
		vector<bool> visited(cur);
		
		for(int i = 0; primes[i] < cur; i++){
			
			int a = primes[i];
			visited[a] = true;
			
			int b = cur - a;
			if(b != a && visited[b] == true) break;
			
			// cout << "a = " << a << ", b = " << b << "\n";
			
			if(check[b] == false){
				cnt++;
			}
			
		}
		
		cout << cnt << "\n";
		
	}
	
	return 0;
}
