#include <iostream>

using namespace std; 

int triad[1001];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i = 1; i <= 1000; i++){
		triad[i] = i * (i + 1) / 2;
	}
	
	int cnt;
	cin >> cnt;
	while(cnt--){
		
		int K;
		cin >> K;
		
		int res = 0;
		
		int firstSum = 0, secondSum = 0, thirdSum = 0;
		
		// »ï°¢¼ö¸¦ 3°³ ´õÇØº½
		for(int i = 1; firstSum <= K; i++){
		
			firstSum = triad[i];
			
			for(int j = 1; secondSum <= K; j++){
				
				secondSum = firstSum + triad[j];
				
				for(int k = 1; thirdSum <= K; k++){
					
					thirdSum = secondSum + triad[k];
						
					if(thirdSum == K){
						res = 1;
						break;
					}
				}
				if(thirdSum == K) break;
				thirdSum = 0;
			}
			if(thirdSum == K) break;
			secondSum = 0;
		} 
		
		cout << res << "\n";
		
	}
	
	return 0;
}
