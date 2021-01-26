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

int S[9][9];
int block[9] = { 0, 0, 0, 3, 3, 3, 6, 6, 6 };
vector<pii> toBeFilled;

bool check(int x, int y){

	// 속한 행과 열을 검사
	rep(i, 0, 9){
		if((S[x][i] == S[x][y]) && (i != y)) 
			return false;
		if((S[i][y] == S[x][y]) && (i != x))
			return false;
	}
	
	// 속한 정사각형을 검사 
	int row = block[x];
	int col = block[y];
	
	vb nums(10, false);
	
	rep(i, row, row + 3){
		rep(j, col, col + 3){
			
			int val = S[i][j];
			
			if(val == 0) 
				continue;
		
			if(nums[val]) return false;
			else nums[val] = true;
		
		}
	}
	
	return true;
	
}

bool go(int index){
	
	if(index == toBeFilled.size()) 
		return true;
	
	pii pos = toBeFilled[index];
	int x = pos.fst;
	int y = pos.scd;
	
	rep(num, 1, 10){
		
		S[x][y] = num;
		
		if(check(x, y) && go(index + 1))
			return true;
		
		S[x][y] = 0;
	}
	
	return false;
	
}

void printS(){
	
	rep(i, 0, 9){
		rep(j, 0, 9){
			cos(S[i][j]);
		}
		cl;
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	rep(i, 0, 9){
		rep(j, 0, 9){
			ci(S[i][j]);
			if(S[i][j] == 0)
				toBeFilled.pb(mp(i, j));
		}
	}
	
	if(toBeFilled.size() > 0){
		go(0);	
	}
	
	printS();
	
	return 0;

}

