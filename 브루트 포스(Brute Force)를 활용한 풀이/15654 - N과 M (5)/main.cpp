#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
bool selected[20];

void DFS(int level, string path){
	
	if(level == M){
		cout << path << "\n";
	}
	else {
		
		for(int i = 0; i < N; i++){
			
			if(selected[i] == false){
			
				selected[i] = true;
				if(path == "")
					DFS(level + 1, path + to_string(arr[i]));
				else
					DFS(level + 1, path + " " + to_string(arr[i]));
				selected[i] = false;
				
			}
			
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	
	sort(arr.begin(), arr.end());
	
	DFS(0, "");
	
	return 0;
}
