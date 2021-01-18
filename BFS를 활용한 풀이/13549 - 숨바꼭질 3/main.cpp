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

qi que;
int N, K;
vi t(100001, -1);

bool check(int pos){
	return (pos <= 100000 && pos >= 0);
}

void move(int pos, int nPos){
	if(check(nPos)){
		int nT = t[pos] + 1;
		// 아직 한번도 방문하지 않았거나 더 작은 시간으로 온 경우에만 
		if(t[nPos] == -1 || (t[nPos] >= 0 && nT < t[nPos])){
			t[nPos] = nT;
			que.push(nPos);
		}
	}
}

void teleport(int pos, int nPos){
	if(check(nPos)){
		if(t[nPos] == -1 || (t[nPos] >= 0 && t[pos] < t[nPos])){
			t[nPos] = t[pos];
			que.push(nPos);
		}
	}
}

int res = MAX;

void BFS(){
	
	que.push(N);
	t[N] = 0;
	
	while(!que.empty()){
		
		int pos = que.front(); que.pop();
		int nPos;
		
		if(pos == K){
			if(t[pos] < res)
				res = t[pos];
		}
		
		// x - 1로 이동
		nPos = pos - 1;
		move(pos, nPos);
		
		// x + 1로 이동
		nPos = pos + 1;
		move(pos, nPos);
		
		// x * 2로 이동 
		nPos = pos * 2;
		teleport(pos, nPos);
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, K);
	BFS();
	col(res);
	
	return 0;
}
