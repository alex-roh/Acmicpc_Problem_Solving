#include <iostream>
#include <string>

using namespace std;

bool selected[20];
int N, M;
	
void DFS(int level, string sequence){
	
	if(level > M){
		cout << sequence << '\n';
	}
	else {
	
		for(int i = 1; i <= N; i++){
		
			if(selected[i] == false){
				selected[i] = true;
				if(sequence == "")
					DFS(level + 1, sequence + to_string(i));
				else 
					DFS(level + 1, sequence + " " + to_string(i));
				selected[i] = false;
			}
			
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
