#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout only line

#define pb push_back

typedef long long ll;

typedef vector<int> vi;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;

typedef vector<bool> vb;

typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
const int MAX = 2000000000;

using namespace std;

int V, E;
vi adjList[20001];
bool visited[20001];
int color[20001];
qi que;

string BFS(int startVertex){
	
	visited[startVertex] = true;
	color[startVertex] = 1; // ���� ĥ�ؼ� ���� 
	que.push(startVertex);
	
	while(!que.empty()){
		
		int currentVertex = que.front();
		que.pop();
		
		rep(i, 0, adjList[currentVertex].size()){
			
			int nextVertex = adjList[currentVertex][i];
				
			// ���� ������ �̹� ���� ĥ���� �ְ� �� ���� ��ġ�ϴ� ��� 
			if(color[nextVertex] != 0 && color[currentVertex] == color[nextVertex]){
				return "NO";
			}
			
			if(visited[nextVertex] == false){
				
				switch(color[currentVertex]){
					case 1:
						color[nextVertex] = 2;
						break;
					case 2:
						color[nextVertex] = 1;
						break;
				}
				
				visited[nextVertex] = true;
				que.push(nextVertex);
				
			}
		}
	}
	
	// ��� ������ Ž���ߴ��� �˻� 
	rep(i, 1, V + 1){
		if(visited[i] == false && BFS(i) == "NO"){
			return "NO";
		}
	} 
	
	return "YES";
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K;	
	ci(K);
	
	while(K--){
		
		ci2(V, E);
		int src, dest;
		
		rep(i, 0, E){
			ci2(src, dest);
			adjList[src].pb(dest);
			adjList[dest].pb(src);
		}
		
		col(BFS(src));
		
		// adjList, que, visited, color �ʱ�ȭ
		for(auto& v : adjList){
			v.clear();
		}
		memset(visited, false, sizeof(visited));
		memset(color, 0, sizeof(color));
		qi().swap(que);
		
	}
	
	return 0;
}
