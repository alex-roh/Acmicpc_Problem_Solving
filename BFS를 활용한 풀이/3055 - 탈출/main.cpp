#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt(arr,N,M) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

#define irep(i,a,b) for(vector<int>::iterator i = a; i != b; i++)
#define pirep(i,a,b) for(vector<pii>::iterator i = a; i != b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,b,a) for(int i = b - 1; i >= a; i--)
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

int R, C;
int T[51][51][2501];
int W[51][51];
vector<string> B(50);
queue<pii> waters;

int hx, hy; // 고슴도치의 위치
int bx, by; // 비버의 위치 
int res = MAX;

typedef struct _Node{
	
	int x, y, t;
	
} Node;

int hogBFS(){
	
	queue<Node> que;
	que.ps({ hx, hy, 0 });
	T[hx][hy][0] = 0;
	
	while(!que.emt()){
		
		Node cur = que.frt(); que.pp();
		
		int x = cur.x;
		int y = cur.y;
		int t = cur.t;
		
		// 비버의 소굴에 도착
		if(x == bx && y == by) {
			res = min(res, T[x][y][t]);
			continue;
		}
		
		rep(i, 0, 4){
		
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = t + 1;
			
			if(!bnd(nx, ny, R, C)) continue;
			if(T[nx][ny][nt] > 0) continue; 
			
			// 다음 위치가 돌인 경우 
			if(B[nx][ny] == 'X') continue; 
			// 다음 위치로 가면 다음에 물이 차는 경우 
			if(W[nx][ny] == nt) continue;
			// 다음 위치가 이미 물이 찬 구역인 경우 
			if(W[nx][ny] <= t && W[nx][ny] >= 0) continue;
			
			que.ps({ nx, ny, nt });
			T[nx][ny][nt] = T[x][y][t] + 1;
			
		}
		
	}

	return res;	
}

void waterBFS(){
	
	while(!waters.emt()){
		
		pii cur = waters.frt(); waters.pp();
		
		int x = cur.fst;
		int y = cur.scd;
		
		rep(i, 0, 4){
		
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!bnd(nx, ny, R, C)) continue;
			
			// 이전에 방문한 적이 없고 빈칸이어야함 
			if(W[nx][ny] == -1 && B[nx][ny] == '.'){
				W[nx][ny] = W[x][y] + 1;
				waters.ps(mp(nx, ny));
			}
			
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(W, -1, sizeof(W[0][0]) * 51 * 51);
	
	ci2(R, C); cig(99999);
	rep(i, 0, R){
		gtl(B[i]);
		rep(j, 0, C){
			// 비버 
			if(B[i][j] == 'D'){
				bx = i; by = j; 
			}
			// 고슴도치
			else if(B[i][j] == 'S'){
				hx = i; hy = j; 
			}
			// 물웅덩이
			else if(B[i][j] == '*'){
				waters.ps(mp(i, j));
				W[i][j] = 0;
			} 
		}
	}
	
	// 물 flood fill
	waterBFS();
	
	// 고슴도치로 BFS를 진행 
	int res = hogBFS();
	if(res != MAX) col(res);
	else col("KAKTUS");
	
	return 0;
}
