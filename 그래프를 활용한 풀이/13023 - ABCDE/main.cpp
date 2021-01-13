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
vi graph[2001];
bool visited[2001];
int ans;

bool DFS(int vertex, int cnt){

	// 정답을 찾음
	if(cnt >= 5){
		return true;
	} 
		
	// 현재 정점에 있는 모든 간선으로 뻗어나가 봄 
	rep(i, 0, graph[vertex].size()){
		
		int &nextVertex = graph[vertex][i];
		
		if(visited[nextVertex] == false){
		
			int &nextVertex = graph[vertex][i];
			visited[nextVertex] = true;
			
			if(DFS(nextVertex, cnt + 1) == true)
				return true;
			else
				visited[nextVertex] = false;
		}			
	}
	
	return false;
			
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	
	while(M--){
		
		int a, b;
		ci2(a, b);
		graph[a].pb(b);
		graph[b].pb(a);
		
	}
	
	rep(i, 0, N){
		visited[i] = true;
		if(DFS(i, 1)){
			ans = 1;
			break;
		}
		visited[i] = false;
	}

	col(ans);
	
	return 0;
}

