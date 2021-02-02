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

vb isPrime(10000, true);
bool visited[10000];

void gen(){
	
	isPrime[0] = false;
	isPrime[1] = false;
	
	for(int i = 2; i < 10000; i++){
		if(!isPrime[i]) continue;
		for(int j = i * 2; j < 10000; j += i)
			isPrime[j] = false;
	}
		
}

int BFS(int src, int dest){
	
	memset(visited, false, sizeof(visited[0]) * 10000);
	queue<pii> que;
	que.ps(mp(src, 0));
	visited[src] = true;
	
	while(!que.emt()){
		
		pii cur = que.frt(); que.pp();
		int num = cur.fst;
		int cnt = cur.scd;
		
		if(num == dest)
			return cnt; 
		
		for(int base = 1; base < 10000; base *= 10){
			
			int digit = (num / base) % 10;
			int cnum = num - (digit * base);
			
			rep(i, 0, 10){
				
				int tnum = cnum + (i * base);
				
				// 범위 체크
				if(tnum < 1000 || tnum > 10000) continue;
				
				// 아직 방문하지 않았고 소수라면 
				if(!visited[tnum] && isPrime[tnum]){
					visited[tnum] = true;
					que.ps(mp(tnum, cnt + 1));
				}
				
			}
			
		}
		
	}
	
	return -1;
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt;
	ci(cnt);
	
	gen();
	
	while(cnt--){
		
		int src, dest;
		
		ci(src);
		ci(dest);
		
		int res = BFS(src, dest);
		
		if(res != -1) col(res);
		else col("impossible");
		
	}
	
	return 0;
}
