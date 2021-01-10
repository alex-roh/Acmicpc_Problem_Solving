#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
const int MAX = 2000000000;

using namespace std;

int N;
int matrix[21][21];
int students[21];
int minVal = MAX;

void DFS(int index, bool ok){

	// 전부 0이거나 전부 1인 경우는 제외함 
	if(index > N && ok == false) return;
	
	// 모든 학생을 팀에 분류했으면 합을 계산 
	if(index > N){
		
		int startSum = 0;
		int linkSum = 0;
		
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				
				if(i == j) continue;
				if(students[i] == students[j]){
					
					if(students[i] == 0){
						startSum += matrix[i][j];
					}
					else{
						linkSum += matrix[i][j];
					}	
				}
			}
		}
		
		int diff = abs(startSum - linkSum);
		if(diff < minVal) minVal = diff;
		
	}
	else {
		
		// 스타트 팀에 포함시킴 
		students[index] = 0;
		if(index > 1 && students[index] != students[index - 1])
			ok = true;
		DFS(index + 1, ok);
		ok = false;		
		// 링크 팀에 포함시킴
		students[index] = 1;
		if(index > 1 && students[index] != students[index - 1])
			ok = true;
		DFS(index + 1, ok);
		ok = false;	
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> matrix[i][j];
		}
	}
	
	DFS(1, false);
	
	cout << minVal;
	
	return 0;
}
