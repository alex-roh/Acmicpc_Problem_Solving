#include <iostream>
#include <vector>
#include <string>

#define STRIKE 1
#define BALL 2
#define ANSCNT 3 

using namespace std;

int numbers [1001][4]; 
int res; 

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt;
	cin >> cnt;
	int cntForWhile = cnt;
	while(cntForWhile--){
		
		string input;
		int strike, ball;
		cin >> input >> strike >> ball;
		
		// 위 조합을 바탕으로 123부터 987까지 불가능한 수를 제거 
		for(int i = 123; i <= 987; i++){
			
			// 0이 포함되어 있으면 지나감
			if(i % 10 == 0 || (i / 10) % 10 == 0)
				continue;
			
			// 숫자가 연속하면 지나감 
			int last = i % 10;
			int middle = (i / 10) % 10;
			int first = (i / 100) % 10;
			if(last == middle || middle == first || first == last)
				continue;
		
			// 현재 수가 정답이라고 가정하고 strike 수와 ball 수를 쌓음 
			string cur = to_string(i); 
			int currentStrike = 0;
			int currentBall = 0;
			for(int j = 0; j < 3; j++){
				
				if(cur[j] == input[j]){
					currentStrike++;
				}
					
				for(int k = 0; k < 3; k++){
					if(k == j) continue;
					if(cur[k] == input[j])
						currentBall++;
				}
			}
			
			if(currentStrike == strike && currentBall == ball){
				numbers[i][ANSCNT]++;
			}	
			
		}
	}
	
	// 정답이라면 지금까지 누적된 strike 수와 ball 수가 같아야 함 
	for(int i = 123; i <= 987; i++){
		if(numbers[i][ANSCNT] == cnt){
			res++;
		}
	}
	
	cout << res;
	
	return 0;
}
