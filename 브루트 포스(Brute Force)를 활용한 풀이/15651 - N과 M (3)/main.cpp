#include <iostream>
#include <string>

using namespace std;

int N, M;

void DFS(int level, string path){
	
	if(level > M){
		cout << path << "\n";
		return;
	}
	else {
		
		for(int i = 1; i <= N; i++){
			
			if(path == "")
				DFS(level + 1, path + to_string(i));
			else
				DFS(level + 1, path + " " + to_string(i));
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	
	DFS(1, "");
	
	return 0;
}
