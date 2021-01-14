#include <bits/stdc++.h>

using namespace std;

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

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

int M, N; // M - 행, N - 열
int total;
int sumForRipe;
int box[1001][1001];
int dayCachedTable[1001][1001];

queue<pii> queForRipe;
queue<pii> queForYet;

void BFS(){
	
	// 입력받을 때 안 익은 토마토의 위치를 큐에 넣어둔 상태
	while(!queForRipe.empty()){
		
		pii ripeTomato = queForRipe.front();
		queForRipe.pop();
		
		int curX = ripeTomato.fst;
		int curY = ripeTomato.scd;
		
		rep(i, 0, 4){
			
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			
			// 해당 위치에 토마토가 안 익은 토마토가 있는 경우에만 넣음 
			if( nextX >= 0 && nextY >= 0 && nextX < N && nextY < M &&
				box[nextX][nextY] == 0){
				
				dayCachedTable[nextX][nextY] = dayCachedTable[curX][curY] + 1;
				box[nextX][nextY] = 1;
				sumForRipe++;
				queForRipe.push(mp(nextX, nextY));
				
			}
		}
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(M, N);
	rep(i, 0, N){
		rep(j, 0, M){
			ci(box[i][j]);
			if(box[i][j] != -1) 
				total++;
			if(box[i][j] == 1){
				queForRipe.push(mp(i, j));
				sumForRipe++;	
			}
		}
	}
	
	BFS();
	
	if(sumForRipe == total){
		int max = -1;
		rep(i, 0, N){
			rep(j, 0, M){
				if(max < dayCachedTable[i][j]){
					max = dayCachedTable[i][j];
				}
			}
		}
		col(max);
	}
	else{
		col(-1);
	}
	
	return 0;
}

