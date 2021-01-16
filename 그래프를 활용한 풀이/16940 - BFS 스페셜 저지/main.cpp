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

vi graph[100001];
di BFS;

bool visited[100001];

void testBFS(){

	qi que;
	que.push(1);
	visited[1] = true;
	BFS.pop_front();
	
	while(!que.empty()){
		
		int v = que.front(); que.pop(); 
		
		// v�� ����Ǿ� �����鼭 ���� �̹湮�� ������ ��� 
		int cnt = 0;
		vi connectedVs;
		rep(i, 0, graph[v].size()){
			int connectedV = graph[v][i];
			if(visited[connectedV] == false){
				cnt++;
				connectedVs.pb(connectedV);
			}
		}
		
		// BFS �迭�� �����ϴ� ���� ������ ���� ���� �������� ������� 
		rep(i, 0, cnt){
			int cur = BFS.front();
			BFS.pop_front();
			que.push(cur);
			visited[cur] = true;
		}
		
		// �ùٸ� BFS �迭�̶�� connectedVs �ȿ� �ִ� ��� ������ visited�� true���� ��
		rep(i, 0, connectedVs.size()){
			int cur = connectedVs[i];
			if(visited[cur] == false){
				col(0);
				return;
			}
		} 
		
	}
	
	col(1);
	
} 

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	ci(N);
	
	rep(i, 0, N - 1){
		int a, b;
		ci2(a, b);
		graph[a].pb(b);
		graph[b].pb(a);
	} 
	
	rep(i, 0, N){
		int a;
		ci(a);
		BFS.pb(a);	
	}
	
	// �Է����� ���� BFS �湮 ������ ������ 
	if(BFS[0] == 1)
		testBFS();
	else 
		col(0);
	
	return 0;
}
