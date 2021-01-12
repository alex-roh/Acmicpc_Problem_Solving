#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout line

#define pb push_back

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

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

const int MAX = 2000000000;

using namespace std;

int GLN(int x){ int len = 0; while(x >= 1){ len++; x /= 10; } return len; } // get length of a number
int POW(int x, int y) { int z = 1; while(y--){ z *= x; } return z; }

int S;
int cnt;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ci(cnt);
	
	while(cnt--){
		
		string oper;
		ci(oper);
		
		if(oper == "all"){
			S = (1 << 20) - 1;
			continue;
		}
		else if(oper == "empty"){
			S = 0;
			continue;
		}
		
		int element;
		ci(element);
		element--;
		
		if(oper == "add"){
			S = (S | (1 << element));
		}
		else if(oper == "remove"){
			S = (S & ~(1 << element));
		}
		else if (oper == "toggle"){
			S = (S ^ (1 << element));
		}
		else if(oper == "check"){
			if((S & (1 << element)) != 0)
				col(1);
			else
				col(0); 
		}
	}
	
	return 0;
}

