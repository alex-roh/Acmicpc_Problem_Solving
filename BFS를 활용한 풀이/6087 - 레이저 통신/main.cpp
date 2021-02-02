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

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

int W, H;
char B[101][101];
int mirrors[101][101];
bool isFind;

int sx, sy; // 시작 
int gx, gy; // 도착 

typedef struct _Node{
	
	int x, y, from, cnt;
	
} Node;

int BFS(){

	memset(mirrors, -1, sizeof(mirrors[0][0]) * 101 * 101);
	
	queue<Node> que;
	que.ps({ sx, sy, -1, 0 });	
	mirrors[sx][sy] = 0;
	
	while(!que.emt()){
		
		Node cur = que.frt(); que.pp();
		
		const int lx = 8;
		const int ly = 6;
		
		int x = cur.x;
		int y = cur.y;
		int from = cur.from;
		int cnt = cur.cnt; 
		
		// 큐에 넣은 이후 보드의 상황이 바뀌었다면 노드를 버림
		if(cnt != mirrors[x][y]) continue;
		
		// 도착했는지 확인
		if(x == gx && y == gy) continue;
		
		rep(i, 0, 4){
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!bnd(nx, ny, H, W)) continue;
			if(B[nx][ny] == '*') continue;
			
			int diff = abs(from - i);
			if(diff == 3) diff = 1;
			
			// 거울을 쓰지 않고 갈 수 있는 경우
			if(from == -1 || diff == 0){
				
				if(mirrors[nx][ny] == -1 || mirrors[nx][ny] >= mirrors[x][y]){
					
					mirrors[nx][ny] = mirrors[x][y];
					que.ps({ nx, ny, i, mirrors[nx][ny]});

				}
				
			} 
			// 겨울을 쓰고 갈 수 있는 경우 
			else if(diff == 1){
			
				if(mirrors[nx][ny] == -1 || (mirrors[nx][ny] >= mirrors[x][y] + 1)){
	
					mirrors[nx][ny] = mirrors[x][y] + 1;
					que.ps({ nx, ny, i, mirrors[nx][ny]});
					
				}
				
			}
			
		}
		
	}
	
	return mirrors[gx][gy];
	
}

int main(int argc, char** argv) {
	
	// reopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(W, H); cig(99999);
	
	rep(i, 0, H){
		string row;
		gtl(row);
		rep(j, 0, W){
			B[i][j] = row[j];
			if(B[i][j] == 'C' && !isFind){
				sx = i; sy = j;
				isFind = true;
			}
			else if(B[i][j] == 'C' && isFind){
				gx = i; gy = j;
			}
		}
	}
	
	co(BFS());
	
	return 0;
}
