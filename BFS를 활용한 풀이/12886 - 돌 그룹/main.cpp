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

int A, B, C;
int total;
bool visited[1501][1501]; // A-B∏∏ ¿˙¿Â 

const int AB = 0;
const int AC = 1;
const int BC = 2;

void insertQue(queue<pii> &que, int n1, int n2){
	
	int X;
	
	if(n1 < n2) {
		X = n1;
		n1 += X;
		n2 -= X;
	}
	else if(n2 < n1) {
		X = n2;
		n1 += X;
		n2 -= X;
	}
	else 
		return;
		
	if(!visited[n1][n2]){
		que.ps(mp(n1, n2));
		visited[n1][n2] = true;
		visited[n2][n1] = true;
	}

}

int BFS(){
	
	queue<pii> que;
	que.ps(mp(A, B));
	visited[A][B] = true;
	
	while(!que.emt()){
		
		pii cur = que.frt(); que.pp();
		
		int a = cur.fst;
		int b = cur.scd;
		int c = total - a - b;
		
		if(a == b && b == c) return 1;
		
		int nums[3] = { a, b, c }; 
	
		rep(i, 0, 3){
			rep(j, 0, 3){
				
				if(i == j) continue;
				
				if(nums[i] < nums[j]){
				
					int X = nums[i];
					int copied[3] = { a, b, c };	
					
					copied[i] += X;
					copied[j] -= X;
					
					if(!visited[copied[i]][copied[j]]){
						que.ps(mp(copied[i], copied[j]));
						visited[copied[i]][copied[j]] = true;
					}
					
				}
				
				
			}
		}
		
	}

	return 0;	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(A, B); ci(C);
	total = A + B + C;
	
	if(A == B && B == C) cos(1);
	else cos(BFS());
	
	return 0;
}
