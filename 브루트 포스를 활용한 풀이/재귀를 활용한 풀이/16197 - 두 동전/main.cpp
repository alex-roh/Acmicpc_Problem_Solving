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

int N, M;
int sfx, sfy; // starting first x, y
int ssx, ssy; // starting second x, y
char B[21][21];

int minCnt = MAX;

bool isDropped(int x, int y){
	return (x < 0 || x >= N || y < 0 || y >= M);
}

// 두 동전을 이동시킴 
int go(int fx, int fy, int sx, int sy, int cnt){
	
	if(cnt > 10) return -1;
	
	// 동전이 밑으로 떨어진 경우 
	if(isDropped(fx, fy) || isDropped(sx, sy)){
	
		if(isDropped(fx, fy) && isDropped(sx, sy)) 
			return -1;
	
		if(minCnt > cnt)
			minCnt = cnt;
	
		return 0;

	}
	
	rep(i, 0, 4){
		
		int nfx, nfy, nsx, nsy;
		
		nfx = fx + dx[i];
		nfy = fy + dy[i];
		
		if(bnd2(nfx, nfy, N, M) && B[nfx][nfy] == '#'){
			nfx = fx;
			nfy = fy;
		}
		
		nsx = sx + dx[i];
		nsy = sy + dy[i];
				
		if(bnd2(nsx, nsy, N, M) && B[nsx][nsy] == '#'){
			nsx = sx;
			nsy = sy;
		}
		
		int res = go(nfx, nfy, nsx, nsy, cnt + 1);
		if(res == -1) continue;
		
	}
	
	return 0;
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	cig(99999);
	bool isFirst = true;
	
	rep(i, 0, N){
		string str;
		gtl(str);
		
		rep(j, 0, M){
			
			B[i][j] = str[j];
			
			if(B[i][j] == 'o'){
				
				if(isFirst){
					sfx = i;
					sfy = j;
					isFirst = false;
				}
				else {
					ssx = i;
					ssy = j;
				}
			}
			
		}
	}
	
	go(sfx, sfy, ssx, ssy, 0);
	
	if(minCnt < MAX){
		col(minCnt);
	}
	else{
		col(-1);
	}
	
	return 0;
}
