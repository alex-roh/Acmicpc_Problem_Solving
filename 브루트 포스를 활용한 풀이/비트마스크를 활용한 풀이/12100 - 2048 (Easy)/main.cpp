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
#define co(a) out << a
#define cos(a) out << a << ' ' // cout with space
#define col(a) out << a << '\n' // cout with line 
#define cl out << '\n' // cout only line

#define pb push_back
#define fst first
#define scd second

#define COMBINED 1
#define NOT_COMBINED 0

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

ofstream out;
int LIMIT = 5;
int N;
static int debug;

// 완전탐색을 위해 모든 경우의 수를 생성 
vi gen(int k){
	
	vi dir(LIMIT);
	
	rep(i, 0, LIMIT){
		dir[i] = (k & 3);
		k >>= 2;
	}
	
	return dir;
	
}

// 더 이상 바꿀 수 있는 원소가 없을 때 false를 반환 
bool moveForward(vector<vector<pii>> &B, int dr, int dc){
	
	bool isChanged = false;
	
	rep(r, 0, N){
		
		rep(c, 0, N){
			
			pii &cur = B[r][c];
			pii &next = B[r + dr][c + dc];
			
			if(!bnd(r + dr, c + dc, N))
				continue;
			
			if(cur.fst == 0 && next.fst == 0)
				continue;
			
			if(cur.fst == next.fst){
				
				// 두 칸 모두 미방문한 경우에만 
				if(cur.scd == NOT_COMBINED && next.scd == NOT_COMBINED){
					
					next.fst *= 2;
					next.scd = COMBINED;
					cur.fst = 0;
					
					isChanged = true;
					
				}
				
			}
			
			else if(cur.fst != 0 && next.fst == 0){
				
				next.fst = cur.fst;
				next.scd = cur.scd;
				cur.fst = 0;
				
				isChanged = true;
			}
			
		}
		
	}
	
	return isChanged;
	
}

// 더 이상 바꿀 수 있는 원소가 없을 때 false를 반환 
bool moveBackward(vector<vector<pii>> &B, int dr, int dc){
	
	bool isChanged = false;
	
	for(int r = N - 1; r >= 0; r--){
		
		for(int c = N - 1; c >= 0; c--){
			
			if(!bnd(r + dr, c + dc, N))
				continue;
				
			pii &cur = B[r][c];
			pii &next = B[r + dr][c + dc];
			
			if(cur.fst == 0 && next.fst == 0)
				continue;
			
			if(cur.fst == next.fst){
				
				// 두 칸 모두 미방문한 경우에만 
				if(cur.scd == NOT_COMBINED && next.scd == NOT_COMBINED){
					
					next.fst *= 2;
					next.scd = COMBINED;
					cur.fst = 0;
					
					isChanged = true;
					
				}
				
			}
			
			else if(cur.fst != 0 && next.fst == 0){
				
				next.fst = cur.fst;
				next.scd = cur.scd;
				cur.fst = 0;
				
				isChanged = true;
			}
			
		}
		
	}
	
	return isChanged;
	
}

// 한 이동이 끝나고 방문 여부를 초기화함 
void resetVisited(vector<vector<pii>> &B){
	
	rep(i, 0, N)
		rep(j, 0, N)
			B[i][j].scd = NOT_COMBINED;
	
}

// 해당 경우의 수에서 얻을 수 있는 최대값을 반환 
int go(vi dir, vector<vector<pii>> &B){
	
	co("#"); cos(++debug); cos(":");
	
	rep(i, 0, LIMIT){
		
		resetVisited(B);
	
		switch(dir[i]){
			case 0: // 위
				cos("up");
				while(moveForward(B, -1, 0));
				break; 
			case 1: // 아래
				cos("down");
				while(moveBackward(B, 1, 0));
				break;
			case 2: // 오른쪽
				cos("right");
				while(moveBackward(B, 0, 1));
				break;
			case 3: // 왼쪽
				cos("left");
				while(moveForward(B, 0, -1));
				break; 
		}
		
		cl;
		rep(i, 0, N){
			rep(j, 0, N){
				cos(B[i][j].fst);
			}	
			cl;
		}
		cl;
		
	}
	
	int maxBlock = -1;
	
	rep(i, 0, N){
		rep(j, 0, N){
			if(maxBlock < B[i][j].fst)
				maxBlock = B[i][j].fst;
		}
	}
	
	return maxBlock;
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	out.open("output_mine.txt"); 
	
	ci(N);
	vector<vi> B(N, vi(N, 0));
	
	rep(i, 0, N){
		rep(j, 0, N){
			ci(B[i][j]);
		}	
	}
	
	int maxBlock = -1;
	
	rep(k, 0, (1 << (LIMIT * 2))){
		
		vi dir = gen(k);
		
		vector<vector<pii>> cB(N, vector<pii>(N));
		
		rep(i, 0, N){
			rep(j, 0, N){
				cB[i][j].fst = B[i][j];
				cB[i][j].scd = NOT_COMBINED;
			}	
		}
		
		int maxFromGo = go(dir, cB);
		
		if(maxBlock < maxFromGo)
			maxBlock = maxFromGo;
		
	}
	
	cl;
	cos("ans:");
	col(maxBlock);
	
	cout << maxBlock;
	
	out.close();
	
	return 0;
}

