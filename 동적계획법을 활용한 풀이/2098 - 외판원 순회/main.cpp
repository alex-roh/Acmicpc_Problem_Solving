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


// current ���ÿ��� visited ���ø� �����ϰ� ��ȸ���� ���� �ִܰŸ��� ��ȯ 
int TSP(int current, int visited){
	
	cos("current city"); cos(current); cos(","); col("already visited:");
	rep(i, 0, N){
		if((visited & (1 << i)) != 0)
			cos(i); // 1�� ���ؼ� ����ؾ� ��
	}
	cl;
	
	int &cachedMinCost = D[current][visited];
	
	// �̹� �ִܰŸ��� ã�� ��� ��ȯ 
	if(cachedMinCost != -1) {
		col("already cached");
		cl;
		return cachedMinCost;	
	}
	
	// ��� ���ø� �湮������ ���ȣ�� ���� 
	if(visited == ((1 << N) - 1)){
		col("end of the recursive call");
		cl;
		// ù��° ���ÿ� ����Ŭ ������ �Ǵ��� �˻�
		if(W[current][0] != 0){
			return W[current][0];
		} 
		else {
			return INF;
		}
	}
	
	col("will visit other cities");
	cl;
	
	// �ٸ� ���ø� ������� �湮�غ��鼭 cachedMonCost�� �ּҰ��� ã�� 
	cachedMinCost = MAX;
	rep(i, 0, N){
		// current���� i��° ���÷� �� �� ���ų� �̹� �湮�� ��� 
		if(W[current][i] == 0 || ((visited & (1 << i)) != 0)){
			continue;
		}
		
		// �湮�� �� �ִ� ���, ������ ã�� �ּҰ��� ��
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
