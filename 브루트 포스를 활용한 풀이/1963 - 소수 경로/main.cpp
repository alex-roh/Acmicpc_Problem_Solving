#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;

vector<bool> isPrime(10000, true);

void findPrimes(){
	
	isPrime[0] = false;
	isPrime[1] = false;
	
	for(int i = 2; i <= 10000; i++){
		if(isPrime[i] == false) continue;
		else{
			for(int j = i * 2; j <= 10000; j += i){
				isPrime[j] = false;
			}
		}
	}
	
}

void BFS(int src, int dest){
	
	vector<bool> visitedPrimes(10000, false);
	vector<int> distances(10000, 0);
	queue<int> myQueue;
	
	myQueue.push(src);
	visitedPrimes[src] = true;
	
	while(!myQueue.empty()){
		
		int node = myQueue.front();
		myQueue.pop();
		
		for(int i = 1000; i <= 9999; i++){
		
			if(node == i) continue;
			if(isPrime[i] == false) continue;
			
			int diffCnt = 0;
			string source = to_string(node);
			string dest = to_string(i);
			
			for(int k = 0; k < source.size(); k++){
				if(source[k] == dest[k]) 
					diffCnt++;
			}	
			// 하나만 바꿔 이동할 수 있는 소수를 찾음 
			if(diffCnt == 3 && visitedPrimes[i] == false){
				myQueue.push(i);
				distances[i] = distances[node] + 1;
				visitedPrimes[i] = true;
			}	
		}
	
	}
	
	/*
		
		for(int i = 0; i < 4; i++){
			
			nodeToStr = to_string(node);
			
			for(int j = 0; j <= 9; j++){
				
				nodeToStr[i] = (char) j + '0';	
				int nodeAfterConversion = stoi(nodeToStr);
				
				if(nodeAfterConversion == dest){
					cout << distances[node] + 1 << "\n";
					return;
				}
				
				if(nodeAfterConversion >= 1000 
					&& isPrime[nodeAfterConversion] 
					&& visitedPrimes[nodeAfterConversion] == false){
					
					myQueue.push(nodeAfterConversion);	
					distances[nodeAfterConversion] = distances[node] + 1;
					visitedPrimes[nodeAfterConversion] = true;
					
				}
			}
		}
	}
	*/
	
	if(distances[dest] == 0)
		cout << "impossible\n";
	else
		cout << distances[dest] << "\n";
		
	return;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	findPrimes();
	
	int cnt;
	cin >> cnt;
	
	for(int i = 0; i < cnt; i++){
	
		int source, dest;
		cin >> source >> dest;	
		
		if(source == dest){
			cout << 0 << "\n";
			continue;
		}
		
		BFS(source, dest);
		
	}
	
	return 0;
}
