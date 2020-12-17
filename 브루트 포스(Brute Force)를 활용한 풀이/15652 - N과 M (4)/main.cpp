#include <iostream>
#include <string>

using namespace std;

int N, M;

void DFS(int level, int cnt, string path){
	
	if(cnt == M){
		cout << path << "\n";
	}
	else {
		
		for(int i = level; i <= N; i++){
			
			if(path == "")
				DFS(i, cnt + 1, path + to_string(i));
			else
				DFS(i, cnt + 1, path + " " + to_string(i));
			
		}
		
	}
	
	
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	
	DFS(1, 0, "");
	
	return 0;
}
