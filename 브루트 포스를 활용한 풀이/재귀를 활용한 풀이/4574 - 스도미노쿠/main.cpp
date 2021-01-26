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

int rdx[2] = {0, 1};
int rdy[2] = {1, 0};

int B[11][11];
bool domino[11][11];
int block[10] = {0, 1, 1, 1, 4, 4, 4, 7, 7, 7};
vector<pii> toBeFilled;

bool checkBound(int a, int b, int N, int M){
	return (a >= 1 && b >= 1 && a < N && b < M);
} 

void printB(){
	
	rep(i, 1, 10){
		rep(j, 1, 10){
			cos(B[i][j]);
		}
		cl;
	}
	cl;
	
}

bool check(int x, int y){

	// 속한 행과 열을 검사
	rep(i, 1, 10){
		if((B[x][i] == B[x][y]) && (i != y)) {
			return false;
		}
		if((B[i][y] == B[x][y]) && (i != x)){
			return false;
		}
	}
	
	// 속한 정사각형을 검사 
	int row = block[x];
	int col = block[y];
	
	vb nums(10, false);
	
	rep(i, row, row + 3){
		rep(j, col, col + 3){
			
			int val = B[i][j];
			if(val == 0) continue;
		
			if(nums[val]) return false;
			else nums[val] = true;
		
		}
	}
	
	return true;
	
}

void getInput(){
	
	int cnt;
	ci(cnt);
	
	while(cnt){
		
		cig(99999);
		string str;
		int row, col;
		
		rep(i, 0, cnt){
			
			gtl(str);
			
			int num1, num2;
			
			num1 = str[0] - '0';
			row = str[2] - 'A' + 1;
			col = str[3] - '0';
			
			B[row][col] = num1;
			
			num2 = str[5] - '0';
			row = str[7] - 'A' + 1;
			col = str[8] - '0';
			
			B[row][col] = num2;
			
			domino[num1][num2] = true;
			domino[num2][num1] = true;
			
		}
		
		gtl(str);
		
		int pos = 0;
		
		for(int index = 1; index < 10; ){
			
			if(str[pos] == ' ') {
				pos++;
			}
			else if(str[pos] >= 'A' && str[pos] <= 'Z'){
				row = str[pos] - 'A' + 1;
				pos++;
			}
			else if(str[pos] >= '0' && str[pos] <= '9'){
				col = str[pos] - '0';
				B[row][col] = index;
				pos++;
				index++;
			}
			
		}
		
		rep(i, 1, 10){
			rep(j, 1, 10){
				if(B[i][j] == 0)
					toBeFilled.pb(mp(i, j));
			}
		}
		
		ci(cnt);
		
	}
	
}

bool go(int index){
	
	if(index == toBeFilled.size())
		return true;
	
	pii pos = toBeFilled[index];
	int x = pos.fst;
	int y = pos.scd;
	
	rep(k, 0, 2){
		
		int nx = x + rdx[k];
		int ny = y + rdy[k];
		
		if(!checkBound(nx, ny, 10, 10)) continue;
		if(B[nx][ny] != 0) continue;
		
		rep(i, 1, 10){
		
			rep(j, 1, 10){
			
				if(i == j || domino[i][j]) continue;
				
				B[x][y] = i;
				B[nx][ny] = j;
				
				domino[i][j] = true;
				domino[j][i] = true;
				
				if(check(x, y) && check(nx, ny) && go(index + 1))
					return true;
				
				B[x][y] = 0;
				B[nx][ny] = 0;
				domino[i][j] = false;
				domino[j][i] = false;
				
			}
			
		}
		
	}
	
	return false;
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	
	getInput();
	
	printB();
	
	if(toBeFilled.size() > 0)
		go(0);	
	
	printB();
	
	return 0;

}

