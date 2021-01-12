#include <iostream>
#include <string>

using namespace std;

int P[501][501];
bool visited[501][501];
int N, M;
int maxVal = -1;

void DFS(int x, int y, int squareCnt, int sum){
	
	if(squareCnt == 4){
		
		if(sum > maxVal){
			maxVal = sum;
		}
		return;
		
	}
	else {
		
		visited[x][y] = true;
			
		// 위쪽으로 이동
		if(x != 1 && visited[x - 1][y] == false){
			DFS(x - 1, y, squareCnt + 1, sum + P[x - 1][y]);
		}
		
		// 오른쪽으로 이동
		if(y != M && visited[x][y + 1] == false){
			DFS(x, y + 1, squareCnt + 1, sum + P[x][y + 1]);
		}
		
		// 아래쪽으로 이동 
		if(x != N && visited[x + 1][y] == false){
			DFS(x + 1, y, squareCnt + 1, sum + P[x + 1][y]);
		}
		
		// 왼쪽으로 이동 
		if(y != 1 && visited[x][y - 1] == false){
			DFS(x, y - 1, squareCnt + 1, sum + P[x][y - 1]);
		}
		
		visited[x][y] = false;
		
	}	
	
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> P[i][j];
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			DFS(i, j, 1, P[i][j]);
			//   □(i,j)
			// □□□
			if(i != N && j != 1 && j != M){
				int shape = P[i][j] + P[i + 1][j] + P[i + 1][j - 1] + P[i + 1][j + 1];
				if(maxVal < shape)
					maxVal = shape;
			}
			//   □(i,j)
			//   □□
			//   □
			if(i <= N - 2 && j != M){
				int shape = P[i][j] + P[i + 1][j] + P[i + 2][j] + P[i + 1][j + 1];
				if(maxVal < shape)
					maxVal = shape;	
			} 
			// (i,j) □□□
			//         □
			if(i != N && j <= M - 2){
				int shape = P[i][j] + P[i][j + 1] + P[i][j + 2] + P[i + 1][j + 1];
				if(maxVal < shape)
					maxVal = shape;		
			}
			//   □(i,j)
			// □□
			//   □
			if(i <= N - 2 && j != 1){
				int shape = P[i][j] + P[i + 1][j] + P[i + 2][j] + P[i + 1][j - 1];
				if(maxVal < shape)
					maxVal = shape;
			}
			 
		}
	}
	
	cout << maxVal;
	
	return 0;
}
