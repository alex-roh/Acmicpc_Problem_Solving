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

// ofstream out
const int MAX = 2000000000;

int N;
vi c(21);
char B[21][21];

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// out.open("output.txt);
	
	ci(N); cig(99999);
	
	rep(i, 0, N){
		
		string str;
		gtl(str);
		
		rep(j, 0, N){
		
			B[i][j] = str[j];
			if(B[i][j] == 'T') {
				// 그 열에 있는 T의 개수 
				c[j]++;
			}
			
		}
	}
	
	int res = MAX;
	
	// 뒤집을 행을 1로 나타내는 순열 패턴 생성 
	rep(pattern, 0, (1 << 20)){
		
		// col 카피 
		vi tc(c);
	
		rep(i, 0, N){
			// 현재 뒤집을 행이라면 
			if((pattern & (1 << i)) != 0){
				rep(j, 0, N){
					if(B[i][j] == 'T') tc[j]--;
					else tc[j]++;
				} 
			}
		}
		
		int sum = 0;
		
		// 뒤집을 열을 선택함 
		rep(i, 0, N){
			
			// 뒤집을 때 T의 개수가 더 적어진다면 
			if(abs(N - tc[i]) < tc[i])
				sum += abs(N - tc[i]);
			else
				sum += tc[i];
		
		}
		
		res = min(res, sum);
		
	}
	
	col(res);
	
	// out.close();
	return 0;
}
