#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c) (a >= 0 && b >= 0 && a < c && b < c)
#define bnd2(a, b, c, d) (a >= 0 && b >= 0 && a < c && b < d)

#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a - 1; i >= b; i--)
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

bool visited[10001];
pii from[10001];

void fourToOne(int& rg1, int* rg4){
	
	int n = rg4[0];
	
	rep(i, 1, 4)
		n = (n * 10) + rg4[i];
	
	rg1 = n;
	
}

void oneToFour(int& rg1, int* rg4){
	
	int n = rg1;
	
	rrep(i, 4, 0){
		rg4[i] = n % 10;
		n /= 10;
	}
	
}

int D(int& rg1, int* rg4){
	
	int n = rg1;
	
	n *= 2;
	
	if(n > 9999)
		n = n % 10000;
	
	rg1 = n;

	return rg1;	
}

int S(int& rg1, int* rg4){
	
	int n = rg1;
	n--;
	
	rg1 = n;
	
	if(n == -1)
		rg1 = 9999;

	return rg1;
}

int L(int& rg1, int* rg4){
	
	int last = rg4[0];
	
	rg4[0] = rg4[1];
	rg4[1] = rg4[2];
	rg4[2] = rg4[3];
	rg4[3] = last;
	
	fourToOne(rg1, rg4);

	return rg1;	
}

int R(int& rg1, int* rg4){
	
	int first = rg4[3];
	
	rg4[3] = rg4[2];
	rg4[2] = rg4[1];
	rg4[1] = rg4[0];
	rg4[0] = first;
	
	fourToOne(rg1, rg4);

	return rg1;	
}

int start(int i, int& rg1, int* rg4){
	switch(i){
		case 1:
			return D(rg1, rg4);
		case 2:
			return S(rg1, rg4);
		case 3:
			return L(rg1, rg4);
		case 4:
			return R(rg1, rg4);
	}
}

void printPath(int A, int B){
	
	int cur = B;
	string path = "";
	
	while(cur != A){
		
		switch(from[cur].scd){
			case 1:
				path = 'D' + path;
				break;
			case 2:
				path = 'S' + path;
				break;
			case 3:
				path = 'L' + path;
				break;
			case 4:
				path = 'R' + path;
				break;
		}
		
		cur = from[cur].fst;
		
	}
	
	col(path);
	
}

void BFS(int A, int B){
	
	qi que;
	que.ps(A);
	visited[A] = true;
	
	while(!que.emt()){
	
		int cnum = que.frt(); que.pp();	
		
		if(cnum == B) printPath(A, B);
		
		rep(i, 1, 5){
			
			// 레지스터 상태를 생성 
			int reg1 = cnum; 
			int reg4[4] = { 0, 0, 0, 0 };
			oneToFour(reg1, reg4);
		
			// 명령어를 실행 
			int res = start(i, reg1, reg4);
			
			if(!visited[res]){
				que.ps(res);
				visited[res] = true;
				from[res].fst = cnum;
				from[res].scd = i;
			}
			
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt;
	ci(cnt);
	
	while(cnt--){
	
		memset(visited, false, 10001 * sizeof(bool));
		memset(from, 0, 10001 * sizeof(pii));
		int A, B;
		ci2(A, B);
		BFS(A, B);
		
	}
	
	return 0;
}
