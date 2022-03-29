#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > graph[100001]; 
bool visited[100001];
int dist[100001];
int V;

// DFS�� ������ �������� �ٸ� �������� �̵��ϸ鼭 �Ÿ��� ����� 
void DFS(int v){
	
	visited[v] = true;
	for(auto u : graph[v]){
		if(!visited[u.first]){
			dist[u.first] = dist[v] + u.second;
			DFS(u.first);
		}	
	}
	
}

// ������ �������� ���� �ָ� ������ ������ ã��
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
	
	// ��Ʈ �������� �ٸ� ��� ���������� �Ÿ��� ������Ʈ
	DFS(1);
	
	// ��Ʈ �������� ���� �� ������ ���� 
	pair<int, int> v = getFarthest();
	int start = v.first;
	
	// �ʱ�ȭ 
	memset(visited, false, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	
	// start���� ���� �� ������ ���� 
	DFS(start);
	
	// ������ ��� 
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
