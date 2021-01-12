#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool selected[20];
int index;
int N, M;

void DFS(int level, int cnt, string path){
	
	if(cnt == M){
		cout << path << "\n";
	}
	else {
		
		for(int i = level; i <= N; i++){
			if(selected[i] == false){
				
				selected[i] = true;
				if(path == "")
					DFS(i + 1, cnt + 1, path + to_string(i));
				else 
					DFS(i + 1, cnt + 1, path + " " + to_string(i));
				selected[i] = false;
				
			}
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
