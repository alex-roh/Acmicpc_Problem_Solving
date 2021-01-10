#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N;
int students[21]; 
int matrix[21][21];
int minVal = INT_MAX;

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

	// N/2명으로 팀을 나누어야 하므로 0을 N/2, 1을 N/2만큼 집어넣음 
	for(int i = 1; i <= N/2; i++){
		students[i] = 0; // start
	}
	for(int i = N/2 + 1; i <= N; i++){
		students[i] = 1; // link
	}
	
	do{
		
		int startSum = 0;
		int linkSum = 0;
		
		// 합을 캐싱함
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				
				if(i == j) continue;
				// 같은 팀에 소속되어 있으면 합에 더함 
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
		
	} while(next_permutation(students + 1, students + N + 1));
	
	cout << minVal;
	
	return 0;
}
