#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt(arr,N,M) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

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
typedef vector<string> vs;
typedef stack<int> si;
typedef queue<int> qi;
typedef deque<int> di;
typedef priority_queue<int> pqi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

int N, cnt;
string A, B, storedA;

void flip(int i){
	if(A[i] == '0') A[i] = '1';
	else A[i] = '0';
}

void on(int i){
	
	if(i == 0){
		flip(0);
		flip(1);
	}
	else if(i == A.size() - 1){
		flip(A.size() - 1);
		flip(A.size() - 2);
	}
	else{
		flip(i - 1);
		flip(i);
		flip(i + 1);
	}
	
	cnt++;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	ci(N); cig(99999);
	
	gtl(A); gtl(B);
	storedA = A;
	
	int pos = 0;
	
	// 같은 경우에 대한 예외 처리 
	if(A == B) {
		col(0);
		return 0;
	}
	
	// 두 경우를 생성
	int res = MAX; 
	
	// 첫번째 스위치를 누르는 경우 
	on(0);
	rep(i, 1, N){
		if(A[i - 1] != B[i - 1])
			on(i);
	}
	
	if(A == B)
		res = cnt;
	
	// 첫번째 스위치를 누르지 않는 경우 
	A = storedA; cnt = 0;
	rep(i, 1, N){
		if(A[i - 1] != B[i - 1])
			on(i);
	}
	
	if(A == B)
		res = min(res, cnt);
	
	if(res != MAX)
		col(res);
	else 
		col(-1);
	
	return 0;
}
