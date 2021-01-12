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

const int INF = 0x3f7f7f7f;
const int MAX = 2000000000;

using namespace std;

int GLN(int x){ int len = 0; while(x >= 1){ len++; x /= 10; } return len; } // get length of a number
int POW(int x, int y) { int z = 1; while(y--){ z *= x; } return z; }

int N; 
int W[16][16];
int D[16][1 << 16];


// current 도시에서 visited 도시를 제외하고 순회했을 때의 최단거리를 반환 
int TSP(int current, int visited){
	
	cos("current city"); cos(current); cos(","); col("already visited:");
	rep(i, 0, N){
		if((visited & (1 << i)) != 0)
			cos(i); // 1을 더해서 출력해야 함
	}
	cl;
	
	int &cachedMinCost = D[current][visited];
	
	// 이미 최단거리를 찾은 경우 반환 
	if(cachedMinCost != -1) {
		col("already cached");
		cl;
		return cachedMinCost;	
	}
	
	// 모든 도시를 방문했으면 재귀호출 종료 
	if(visited == ((1 << N) - 1)){
		col("end of the recursive call");
		cl;
		// 첫번째 도시와 사이클 형성이 되는지 검사
		if(W[current][0] != 0){
			return W[current][0];
		} 
		else {
			return INF;
		}
	}
	
	col("will visit other cities");
	cl;
	
	// 다른 도시를 순서대로 방문해보면서 cachedMonCost의 최소값을 찾음 
	cachedMinCost = MAX;
	rep(i, 0, N){
		// current에서 i번째 도시로 갈 수 없거나 이미 방문한 경우 
		if(W[current][i] == 0 || ((visited & (1 << i)) != 0)){
			continue;
		}
		
		// 방문할 수 있는 경우, 이전에 찾은 최소값과 비교
		cachedMinCost = min(cachedMinCost, TSP(i, visited | (1 << i)) + W[current][i]);
	}
	
	return cachedMinCost;
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N);
	rep(i, 0, N){
		rep(j, 0, N){
			ci(W[i][j]);
		}
	}
	
	memset(D, -1, sizeof(D));
	
	col(TSP(0, 1));
	
	rep(i, 0, N){
		int minVal = MAX;
		rep(j, 0, (1 << N)){
			if(D[i][j] < minVal && D[i][j] != -1) minVal = D[i][j];
		}
		co("D["); co(i); co("]"); co(" = "); col(minVal);
	}
	
	return 0;
}
