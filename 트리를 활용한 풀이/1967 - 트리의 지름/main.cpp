#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c) (a >= 0 && b >= 0 && a < c && b < c)
#define bnd2(a, b, c, d) (a >= 0 && b >= 0 && a < c && b < d)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mp(a,b) make_pair(a, b)

#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout only line

#define pb push_back
#define fst first
#define scd second

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef stack<int> si;
typedef queue<int> qi;
typedef deque<int> di;
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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

vector<pii> graph[100001]; 
bool visited[100001];
int distFromV[100001];
int V;

// DFS로 임의의 정점에서 다른 정점으로 이동하면서 거리를 기록함 
void updateDistance(int v, int dist){
	
	rep(i, 0, graph[v].size()){
		
		int nV = graph[v][i].fst;
		int distnV = graph[v][i].scd;
		
		if(visited[nV] == false){
			visited[nV] = true;
			distFromV[nV] = dist + distnV;
			updateDistance(nV, distFromV[nV]);
		}
		
	}
	
}

// 임의의 정점에서 가장 멀리 떨어진 정점을 찾음
pii findFarthestVertex(){

	int maxDist = -1;
	int maxVertex = 1;
	
	rep(i, 1, V + 1){
		if(distFromV[i] > maxDist){
			maxDist = distFromV[i];
			maxVertex = i;	
		}	
	}
	
	return mp(maxVertex, maxDist);
} 

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(V);
	
	rep(i, 0, V - 1){
		
		int parent, child, weight;
		ci2(parent, child); ci(weight);
		
		graph[parent].pb(mp(child, weight));
		graph[child].pb(mp(parent, weight));
			
	}
	
	// 루트 정점에서 다른 모든 정점으로의 거리를 업데이트함
	visited[1] = true;
	updateDistance(1, 0);
	
	// 루트 정점에서 가장 먼 정점 farthestVertex를 구함 
	pii farthest = findFarthestVertex();
	int farthestVertex = farthest.fst;
	
	// farthestVertex에서 다른 모든 정점으로의 거리를 업데이트함 
	memset(visited, false, sizeof(visited));
	memset(distFromV, 0, sizeof(distFromV));
	visited[farthestVertex] = true;
	updateDistance(farthestVertex, 0);
	
	// 지름을 찾아서 출력
	pii farthest2 = findFarthestVertex();
	int diameter = farthest2.scd;
	col(diameter); 
	
	return 0;
}
