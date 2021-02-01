#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt(arr, N, M) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

#define irep(i,a,b) for(vector<int>::iterator i = a; i != b; i++)
#define pirep(i,a,b) for(vector<pii>::iterator i = a; i != b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a - 1; i >= b; i--)
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

const int MAX = 2000000000;

int N = 8;
int ux = 7, uy = 0; // 시작지점 
int gx = 0, gy = 7; // 목표지점 

bool visited[8][8][9];
char B[8][8];
vector<pii> walls;

int ddx[9] = { 0, -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[9] = { 0, -1, 0, 1, 1, 1, 0, -1, -1 };

typedef struct _Node{
	
	int x; int y; int t;
	
} Node;

int BFS(){
	
	queue<Node> que;
	que.ps({ ux, uy, 0 }); // 0초의 위치 
	
	while(!que.emt()){
		
		Node cur = que.frt(); que.pp();
		int x = cur.x;
		int y = cur.y;
		int t = cur.t;
		
		// 목적지 도착 검사 
		if(x == gx && y == gy) return 1;
		
		// 가만히 있는 것을 포함해 9가지 방향으로 이동 
		rep(i, 0, 9){
			
			int nx = x + ddx[i];
			int ny = y + ddy[i];
			int nt = min(t + 1, 8); // 8초부터는 의미가 없음 
			
			if(!bnd(nx, ny, N, N)) continue;
			
			// 목적지에 벽이 있으면 skip
			if(nx - t >= 0 && B[nx - t][ny] == '#') continue; 
			// 이동하고 나서 벽이 내려오면 skip
			if(nx - t - 1 >= 0 && B[nx - t - 1][ny] == '#') continue; 
		
			if(!visited[nx][ny][nt]){
				que.ps({ nx, ny, nt });
				visited[nx][ny][nt] = true;
			}
			
		}
		
	}
	
	return 0;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	rep(i, 0, N){
		
		string row;
		gtl(row);
		
		rep(j, 0, N){
			B[i][j] = row[j];
		}
		
	}
	
	cos(BFS());
	
	return 0;
}
