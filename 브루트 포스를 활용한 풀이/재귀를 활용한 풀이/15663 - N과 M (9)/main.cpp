#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> numOfEachElement(10001);

void DFS(int level, int cnt, string path){
	
	if(cnt == M){
		
		cout << path << "\n";
		
	}
	else {
	
		vector<bool> innerSelected(10001, false);
		
		for(int i = 0; i < N; i++){
			
			if(numOfEachElement[arr[i]] > 0 && innerSelected[arr[i]] == false){
				
				innerSelected[arr[i]] = true;
				numOfEachElement[arr[i]]--;
				
				if(path == "")
					DFS(i + 1, cnt + 1, path + to_string(arr[i]));
				else
					DFS(i + 1, cnt + 1, path + " " + to_string(arr[i]));	
				
				numOfEachElement[arr[i]]++;
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
		numOfEachElement[temp]++;
	}
	
	sort(arr.begin(), arr.end());
	
	DFS(0, 0, "");
	
	return 0;
}
