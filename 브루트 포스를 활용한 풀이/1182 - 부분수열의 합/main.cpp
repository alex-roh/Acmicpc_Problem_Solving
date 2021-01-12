#include <iostream>
#include <string>

using namespace std;

int arr[21];
int N, S; 
int cnt;

// 조합을 만드는 DFS 
void DFS(int level, int sum, string path){
	
	if(level > N){
		if(sum == S)
			cnt++;
		return;
	}
	else {
		
		// 현재 수 포함 
		DFS(level + 1, sum + arr[level], path + " " + to_string(arr[level]));
			
		// 현재 수 비포함
		DFS(level + 1, sum, path + " ");
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	
	DFS(1, 0, "");
	
	if(S == 0) cout << cnt - 1;
	else cout << cnt;
	
	return 0;
}
