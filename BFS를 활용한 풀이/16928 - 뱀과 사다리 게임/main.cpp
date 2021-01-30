#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c) (a >= 0 && b >= 0 && a < c && b < c)
#define bnd2(a, b, c, d) (a >= 0 && b >= 0 && a < c && b < d)

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

ofstream out;
int N, M; 
int B[120];   
int dist[120];  
bool visited[120];

int BFS(){
	
	queue<pii> que;
	que.ps(mp(1, 0)); // 1에서 시작
	visited[1] = true;
	
	while(!que.emt()){
		
		// 현재 위치로 이동 
		pii cur = que.frt(); que.pp();
		int pos = cur.fst;
		int cnt = cur.scd;
		
		fco("current pos#"); fcos(pos); fcos(":");
		
		if(pos == 100){
			fcol("BFS ended.");
			return cnt;
		} 
		
		// 이동한 위치에 뱀이나 사다리가 있음
		if(B[pos] != pos) {
			
			int npos = B[pos];
			if(!visited[pos]){
				que.ps(mp(npos, cnt));
				fco("("); fcos(npos); fcos(","); fco(cnt); fco(")");
				visited[npos] = true;
			}
		}
		else {
			
			// 주사위를 굴려서 이동 
			rep(spot, 1,  6 + 1){
				
				int npos = pos + spot;
				
				// 이동한 자리에 뱀이나 사다리가 있음
				if(B[npos] != npos) npos = B[npos]; 
				
				if(npos <= 100 && !visited[npos]){
					que.ps(mp(npos, cnt + 1));
					fco("("); fcos(npos); fcos(","); fco(cnt + 1); fco(")");
					visited[npos] = true;
				}
				
			}	
			
		}
		
		fcl;
		
	}
	
	return -1;
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	
	// 보드 
	rep(i, 1, 100 + 1){
		B[i] = i;
		dist[i] = -1;
	}
	
	int from, to;
	
	// 사다리 
	rep(i, 0, N + M){
		ci2(from, to);
		B[from] = to;
	}
	
	out.open("output_AC.txt");
	
	int res = BFS();
	
	fcol(res);
	
	out.close();
	
	return 0;
}
