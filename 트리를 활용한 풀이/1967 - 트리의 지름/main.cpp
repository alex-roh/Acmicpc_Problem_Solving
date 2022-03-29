#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > graph[100001]; 
bool visited[100001];
int dist[100001];
int V;

// DFS로 임의의 정점에서 다른 정점으로 이동하면서 거리를 기록함 
void DFS(int v){
	
	visited[v] = true;
	for(auto u : graph[v]){
		if(!visited[u.first]){
			dist[u.first] = dist[v] + u.second;
			DFS(u.first);
		}	
	}
	
}

// 임의의 정점에서 가장 멀리 떨어진 정점을 찾음
pair<int, int> getFarthest(){

	int maxDist = -1;
	int maxVertex = 1;
	
	for(int i = 1; i <= V + 1; i++){
		if(dist[i] > maxDist){
			maxDist = dist[i];
			maxVertex = i;	
		}	
	}
	
	return make_pair(maxVertex, maxDist);
} 

void driver(){
	
	// 루트 정점에서 다른 모든 정점으로의 거리를 업데이트
	DFS(1);
	
	// 루트 정점에서 가장 먼 정점을 구함 
	pair<int, int> v = getFarthest();
	int start = v.first;
	
	// 초기화 
	memset(visited, false, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	
	// start에서 가장 먼 정점을 구함 
	DFS(start);
	
	// 지름을 출력 
	pair<int, int> res = getFarthest();
	int diameter = res.second;
	cout << diameter; 
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> V;
	
	for(int i = 0; i < V - 1; i++){
		
		int p, c, w;
		cin >> p >> c >> w;
		
		graph[p].push_back({c, w});
		graph[c].push_back({p, w});
			
	}
	
	driver();
	
	return 0;
}
