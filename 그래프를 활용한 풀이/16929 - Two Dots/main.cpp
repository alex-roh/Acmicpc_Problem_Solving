#include <bits/stdc++.h>

using namespace std;

#define bnd1(a,b,c) (a >= 0 && b >= 0 && a < c && b < c)
#define bnd2(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)

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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

int N, M;
char board[51][51];
bool isSrc[51][51];

// x, y에서 srcX, srcY로 돌아오는 사이클이 있는지 검사 
bool DFS(int x, int y, int srcX, int srcY){
	
	// src 였던 위치에 도달하면 사이클이 있는 것 
	if(isSrc[x][y]){
		return true;
	}
	
	isSrc[x][y] = true; 
	
	rep(i, 0, 4){
	
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		
		// 다음 위치가 같은 색상이면 방문함 
		// 자신이 넘어왔던 위치로는 다시 가지 않음 
		if( bnd2(nextX, nextY, N, M)
			&& (board[nextX][nextY] == board[x][y])
			&& !(nextX == srcX && nextY == srcY)){
			if(DFS(nextX, nextY, x, y))
				return true;
		}
	}
	
	return false;

}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	cig(99999);
	
	rep(i, 0, N){
		string row;
		gtl(row);
		rep(j, 0, M){
			board[i][j] = row[j];	
		}
	}
	
	rep(i, 0, N){
		rep(j, 0, M){
			if(isSrc[i][j]) continue;
			// 현재 위치 i, j에서 사이클을 검사
			if(DFS(i, j, -999, -999)){
				col("Yes");
				return 0;
			}
		}
	}
	
	col("No");
	
	return 0;
}

