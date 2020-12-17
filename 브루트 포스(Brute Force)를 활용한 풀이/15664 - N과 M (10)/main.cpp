#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

void DFS(int level, int cnt, string path){
	
	if(cnt == M){
		cout << path << "\n";
	}
	else {
		
		vector<bool> selected(10001);
		
		for(int i = level; i < N; i++){
			
			if(selected[arr[i]] == false){
		
				selected[arr[i]] = true;
				
				if(path == "")
					DFS(i + 1, cnt + 1, path + to_string(arr[i]));
				else
					DFS(i + 1, cnt + 1, path + " " + to_string(arr[i]));
				
			}
		
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	
	sort(arr.begin(), arr.end());
	
	DFS(0, 0, "");
	
	return 0;
}
