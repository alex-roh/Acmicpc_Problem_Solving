#include <iostream>

using namespace std;

char board[51][51];
char temp[51][51];

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M, N;
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			
			cin >> board[i][j];
			
		}
	}
	
	int min = 10000;
	
	for(int i = 1; i + 7 <= N; i++){
		for(int j = 1; j + 7 <= M; j++){
			
			int cnt = 0;
			
			// 체스판 배열을 temp 배열으로 복사함 
			for(int k = i; k <= i + 7; k++){
				for(int r = j; r <= j + 7; r++){
					temp[k][r] = board[k][r];
				}
			}
			
			for(int k = i; k <= i + 7; k++){
				for(int r = j; r <= j + 7; r++){
					
					char cur = temp[k][r];
					
					// 오른쪽을 살펴봄 
					if(r + 1 <= j + 7 && cur == temp[k][r + 1]){
						cnt++;
						if(cur == 'W')
							temp[k][r + 1] = 'B';
						else 
							temp[k][r + 1] = 'W';
					}
					
					// 아래를 살펴봄 
					if(k + 1 <= i + 7 && cur == board[k + 1][r]){
						cnt++;
						if(cur == 'W')
							temp[k + 1][r] = 'B';
						else 
							temp[k + 1][r] = 'W';
					}
					
				}
			}		
			
			// 90도 뒤집었을 때 카운트가 더 적은지 확인
			if(64 - cnt < cnt)
				cnt = 64 - cnt;			 
			
			// 최소값 캐싱
			if(min > cnt){
				min = cnt;
			}	
		}
	}
	
	cout << min << "\n";
	
	return 0;
}
