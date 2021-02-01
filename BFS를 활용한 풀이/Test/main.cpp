#include <bits/stdc++.h>

using namespace std;


#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt(arr, N, M) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

#define irep(i,a,b) for(vector<int>::iterator i = a; i != b; i++)
#define pirep(i,a,b) for(vector<pii>::iterator i = a; i != b; i++)
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

ofstream out;
bool check[8][8][9];
int dx[] = {0,0,1,-1,1,-1,1,-1,0};
int dy[] = {1,-1,0,0,1,1,-1,-1,0};


int main() {
	
	freopen("input.txt", "rt", stdin);
	out.open("output.txt");
	
    int n = 8;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    queue<tuple<int,int,int>> q;
    check[7][0][0] = true;
    q.push(make_tuple(7,0,0));
    bool ans = false;
    while (!q.empty()) {
        int x, y, t;
        tie(x,y,t) = q.front(); q.pop();
        if (x == 0 && y == 7) ans = true;
        for (int k=0; k<9; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            int nt = min(t+1, 8);
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (nx-t >= 0 && a[nx-t][ny] == '#') continue;
                if (nx-t-1 >= 0 && a[nx-t-1][ny] == '#') continue;
                if (check[nx][ny][nt] == false) {
                    check[nx][ny][nt] = true;
                    q.push(make_tuple(nx,ny,nt));
                }
            }
        }
    }
    
    cout << (ans ? 1 : 0) << '\n';
    
	rep(i, 0, 8){
		rep(j, 0, 8){
			rep(k, 0, 9){
				fco("visited["); fco(i); fco("]["); fco(j); fco("]["); fco(k); fcos("] ="); fcol(check[i][j][k]);
			}
		}
	}
    
    return 0;
}

