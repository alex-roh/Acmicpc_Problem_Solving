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
int T[51][51];
int W[51][51];
char B[51][51];
queue<pii> waters;

int hx, hy; // 고슴도치의 위치
int bx, by; // 비버의 위치 

int hogBFS(){
	
	memset(T, -1, sizeof(T[0][0]) * 51 * 51);
	
	queue<pii> que;
	que.ps(mp(hx, hy));
	T[hx][hy] = 0;
	
	while(!que.emt()){
		
		pii cur = que.frt(); que.pp();
		
		int x = cur.fst;
		int y = cur.scd;
		
		rep(i, 0, 4){
		
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!bnd(nx, ny, R, C)) continue;
			
			// 이미 캐싱한 경우
			if(T[nx][ny] != -1) continue; 
			// 다음 위치가 돌인 경우 
			if(B[nx][ny] == 'X') continue; 
			
			// 다음 위치에 이미 물이 차 있거나 다음에 물이 차는 경우 
			if(W[nx][ny] != -1 && W[nx][ny] <= T[x][y] + 1) continue;
			
			que.ps(mp(nx, ny));
			T[nx][ny] = T[x][y] + 1;
			
		}
		
	}

	return T[bx][by];	
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
			if(W[nx][ny] != -1) continue;
			if(B[nx][ny] == 'X' || B[nx][ny] == 'D') continue;
		
			W[nx][ny] = W[x][y] + 1;
			waters.ps(mp(nx, ny));
			
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(R, C); cig(99999);
	memset(W, -1, sizeof(W[0][0]) * 51 * 51);
	
	rep(i, 0, R){
		
		string row;
		gtl(row);
		
		rep(j, 0, C){
			
			B[i][j] = row[j];
			
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
	if(res != -1) col(res);
	else col("KAKTUS");
	
	return 0;
}
