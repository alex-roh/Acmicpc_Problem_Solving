#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt;
	cin >> cnt;
	
	while(cnt--){
		
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		
		int changingY, index;
		for(index = x; index <= 1600000000; index += M){
			
			changingY = index % N;
			
			if(changingY == 0){
				changingY = N;
			} 
			
			if(changingY == y){
				break;
			}
		}
		
		if(index > 40000){
			cout << -1 << "\n";
		}
		else {
			cout << index << "\n";
		}
	}
	
	return 0;
}
