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

typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
const int MAX = 2000000000;

using namespace std;

int N, M, V;
vi adjList[1001];
bool visitedDFS[1001];
bool visitedBFS[1001];

void dfs(int vertex){
	
	visitedDFS[vertex] = true;
	cos(vertex);
			
	rep(i, 0, adjList[vertex].size()){
		
		int nextVertex = adjList[vertex][i];
		
		if(visitedDFS[nextVertex] == false){
			dfs(nextVertex);
		}
		
	}		

}

void bfs(int startVertex){
	
	qi que;
	que.push(startVertex);
	visitedBFS[startVertex] = true;
	
	while(!que.empty()){
		
		int cur = que.front();
		que.pop();
		cos(cur);
		
		rep(i, 0, adjList[cur].size())
		{
			int nextVertex = adjList[cur][i];
			if(visitedBFS[nextVertex] == false){
				visitedBFS[nextVertex] = true;
				que.push(nextVertex);
			}		
		}
			
	}	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	ci(V);
		
	rep(i, 0, M){
		
		int a, b;
		ci2(a, b);
		adjList[a].pb(b);
		adjList[b].pb(a);
		
	}
	
	rep(i, 0, N)
		sort(adjList[i].begin(), adjList[i].end());
	
	dfs(V);
	cl;
	bfs(V);
	
	return 0;
}
