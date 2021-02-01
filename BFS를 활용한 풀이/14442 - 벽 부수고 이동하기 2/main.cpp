#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt(arr) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = b - 1; i >= a; i--)
#define mp(a,b) make_pair(a, b)

#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout only line

// ofstream out
#define fco(a) out << a
#define fco(a) out << a
#define fcos(a) out << a << ' '
#define fcol(a) out << a << '\n' 
#define fcl out << '\n'

#define frt front
#define ps push
#define pp pop
#define emt empty
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
int N, M, K;
int B[1001][1001];
int dist[1001][1001][12];
int res = -1;

typedef struct _Node{
	
	int x; int y; int used;
	_Node(int px, int py, int pused): x(px), y(py), used(pused) {};
	
} Node;

bool bcheck(int nx, int ny){
	return ((nx >= 1) && (ny >= 1) && (nx <= N) && (ny <= M));
}

int BFS(){
	
	queue<Node> que;
	que.ps(Node(1, 1, 0));
	
	rep(i, 0, 10){
		dist[1][1][i] = 1;
	}
	
	while(!que.emt()){
		
		Node cur = que.frt(); que.pp();
		
		int x = cur.x;
		int y = cur.y;
		int used = cur.used;
		
		// 도착했으면 캐싱 
		if(x == N && y == M){
			if(res == -1) res = dist[x][y][used];
			else res = min(res, dist[x][y][used]);
			continue;
		}
		
		rep(i, 0, 4){
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!bcheck(nx, ny)) continue;
			
			// 벽이고 폭파시킬 수 있는 경우 
			if(B[nx][ny] == 1 && used < K){
				
				// 이전에 폭파시킨 적이 없다면 폭파 
				if(dist[nx][ny][used + 1] == 0){
					que.ps(Node(nx, ny, used + 1));
					dist[nx][ny][used + 1] = dist[x][y][used] + 1;				
				}

			} 
			// 빈 공간인 경우
			else if(B[nx][ny] == 0) {
				
				// 이전에 다녀간 적이 없다면 다녀감
				if(dist[nx][ny][used] == 0){
					que.ps(Node(nx, ny, used));
					dist[nx][ny][used] = dist[x][y][used] + 1;	
				} 
				
			} 
			
		}
		
	}
	
	return res;
	
}


int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M); ci(K);
	cig(99999);
	
	if(N == M && N == 1){
		cos(1);
		return 0;
	}
	
	rep(i, 1, N + 1){
		string row;
		gtl(row);
		rep(j, 1, M + 1){
			B[i][j] = row[j - 1] - '0';
		}
		
	}
	
	cos(BFS());
	
	return 0;
}

