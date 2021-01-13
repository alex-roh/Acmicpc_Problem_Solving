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

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
const int MAX = 2000000000;

using namespace std;

int N, M;
vi adjList[1001];
bool visited[1001];
int cnt;

void DFS(int vertex){
	
	visited[vertex] = true;
	cnt++;
	
	rep(i, 0, adjList[vertex].size()){
		
		int nextVertex = adjList[vertex][i];
		
		if(visited[nextVertex] == false){
			DFS(nextVertex);
		}
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	
	int startVertex;
	
	rep(i, 0, M){
		
		int src, dest;
		ci2(src, dest);
		adjList[src].pb(dest);
		adjList[dest].pb(src);
		startVertex = src;
		
	}	
	
	DFS(startVertex);
	
	int vertexIndex = 0;
	int ans = 1;
	
	while(cnt != N){
		
		rep(i, vertexIndex, N){
			if(visited[i] == false){
				vertexIndex = i;
			}
		}
		
		DFS(vertexIndex);
		ans++;
	}
	
	col(ans);
	
	return 0;
}

