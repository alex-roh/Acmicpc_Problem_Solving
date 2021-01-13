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

string BFS(int startVertex, array<vi, 20001>& adjList){
	
	vb visited(V + 1, false);
	vi color(V + 1, -1);
	
	qi que;
	
	visited[startVertex] = true;
	color[startVertex] = 0; // 색을 칠해서 넣음 
	que.push(startVertex);
	
	while(!que.empty()){
		
		int currentVertex = que.front();
		que.pop();
		
		rep(i, 0, adjList[currentVertex].size()){
			
			int nextVertex = adjList[currentVertex][i];
			
			// 다음 정점에 이미 색이 칠해져 있고 내 색과 일치하는 경우 
			if(color[nextVertex] != -1 && color[currentVertex] == color[nextVertex]){
				return "NO";
			}
			
			if(visited[nextVertex] == false){
				
				color[nextVertex] = color[currentVertex] ^ 1;
				visited[nextVertex] = true;
				que.push(nextVertex);
				
			}
		}
	}
	
	return "YES";
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K;	
	ci(K);
	
	while(K--){
		
		ci2(V, E);
		array<vi, 20001> adjList;
		int src, dest;
		
		rep(i, 0, E){
			int src, dest;
			ci2(src, dest);
			adjList[src].pb(dest);
			adjList[dest].pb(src);
		}
		
		col(BFS(src, adjList));
		
	}
	
	return 0;
}
