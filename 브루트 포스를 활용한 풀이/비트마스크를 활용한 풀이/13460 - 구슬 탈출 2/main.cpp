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

int N, M;
char B[11][11];
bool visited[11][11][11][11]; // rx, ry, bx, by

int hx, hy;
int res = MAX;

typedef struct _Node{
	
	int rx; int ry;
	int bx; int by;
	int cnt;
	
	_Node(int arx, int ary, int abx, int aby, int acnt)
		: rx(arx), ry(ary), bx(abx), by(aby), cnt(acnt){}
	
} Node;

bool isAtHole(int x, int y){
	return (x == hx) && (y == hy);
}

bool isCrush(int rx, int ry, int bx, int by){
	return (rx == bx) && (ry == by);
}

bool isThereWall(int x, int y){
	return (B[x][y] == '#');
}

// ������ ������ ��ġ�� ���� 
void move(int &x, int &y, int dirX, int dirY){
	
	if(dirX == 0){
		// �¿� �̵� 
		while(B[x][y] != '#' && !isAtHole(x, y))
			y += dirY;
		
		if(!isAtHole(x, y))
			y += dirY * (-1);
	}
	
	if(dirY == 0){
		// �Ʒ��� �̵� 
		while(B[x][y] != '#' && !isAtHole(x, y))
			x += dirX;
		
		if(!isAtHole(x, y))
			x += dirX * (-1);
	}
	
}

// �¿�� �浹�� ��� ��ġ�� ���� 
void crushAtRow(int cry, int cby, int &nry, int &nby, int dir){
	switch(dir){
		case 1:
			// ���������� �̵� 
			if(cry < cby)
				nry = nby - 1;
			else
				nby = nry - 1;
			break;
		case -1:
			// �������� �̵� 
			if(cry < cby)
				nby = nry + 1;
			else
				nry = nby + 1;
			break;
	}
}

// �Ʒ����� �浹�� ��� ��ġ�� ���� 
void crushAtCol(int crx, int cbx, int &nrx, int &nbx, int dir){
	switch(dir){
		case 1:
			// �Ʒ��� �̵� 
			if(crx < cbx)
				nrx = nbx - 1;
			else
				nbx = nrx - 1;
			break;	
		case -1:
			// ���� �̵� 
			if(crx < cbx)
				nbx = nrx + 1;
			else
				nrx = nbx + 1;
			break;
	}
}

void BFS(int frx, int fry, int fbx, int fby){
	
	Node node(frx, fry, fbx, fby, 0);
	queue<Node> que;
	que.push(node);
	
	while(!que.empty()){
	
		Node cur = que.front(); que.pop();
		
		int ccnt = cur.cnt;
		
		// Ƚ���� 10�� ������ ���� 
		if(ccnt > 10) continue;
		
		int crx = cur.rx; int cry = cur.ry;
		int cbx = cur.bx; int cby = cur.by;
		
		// Ǫ�� ������ ���ۿ� ������ ��� ����
		if(isAtHole(cbx, cby)) continue; 
		
		// ���� ������ ���ۿ� ������ ��� Ƚ���� ĳ���ϰ� ���� 
		if(isAtHole(crx, cry)){
			if(ccnt < res) 
				res = ccnt;
			continue;
		} 
		
		visited[crx][cry][cbx][cby] = true;
		
		// ������� ������ 
		rep(i, 0, 4){
			
			int nrx = crx; int nry = cry;
			int nbx = cbx; int nby = cby;
			
			move(nrx, nry, dx[i], dy[i]);
			move(nbx, nby, dx[i], dy[i]);
			
			// �̹� �湮�� ���� ��� ����
			if(visited[nrx][nry][nbx][nby]) continue; 
			
			// ���� ������ Ǫ�� ������ �浹���� ���� ��� 
			if(!isCrush(nrx, nry, nbx, nby)){
				que.push(Node(nrx, nry, nbx, nby, ccnt + 1));
				continue;
			}
			
			// ���� ������ Ǫ�� ������ �浹�ߴµ� ������ ���
			if(B[nrx][nry] == 'O') continue;
			
			// ���� ������ Ǫ�� ������ �¿�� �浹�� 
			if(dx[i] == 0) 
				crushAtRow(cry, cby, nry, nby, dy[i]);
			
			// ���� ������ Ǫ�� ������ �Ʒ����� �浹�� 
			if(dy[i] == 0)
				crushAtCol(crx, cbx, nrx, nbx, dx[i]);
			
			que.push(Node(nrx, nry, nbx, nby, ccnt + 1));
			 
		}
	
	}
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	cig(99999);
	
	int frx, fry, fbx, fby;
	
	rep(i, 0, N){
		
		string str;
		gtl(str);
		
		rep(j, 0, M){
			
			B[i][j] = str[j];
			
			if(B[i][j] == 'O'){
				hx = i; hy = j;
			}
			else if(B[i][j] == 'R'){
				frx = i; fry = j;
			}
			else if(B[i][j] == 'B'){
				fbx = i; fby = j;
			}	
		
		}
	}
	
	BFS(frx, fry, fbx, fby);
	
	if(res > 10) col(-1);
	else col(res);
	
	return 0;
}
