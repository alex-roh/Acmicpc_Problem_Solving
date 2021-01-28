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
#define co(a) out << a
#define cos(a) out << a << ' ' // cout with space
#define col(a) out << a << '\n' // cout with line 
#define cl out << '\n' // cout only line

ofstream out;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int LIMIT = 5;
static int debug; 

vector<int> gen(int k) {
	
    vector<int> a(LIMIT);
    for (int i=0; i<LIMIT; i++) {
        a[i] = (k&3);
        k >>= 2;
    }
    return a;
    
}

void print(vector<vector<pair<int,bool>>> &a) {
	
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j].first << ' ';
        }
        cout << '\n';
    }
    
}

int check(vector<vector<int>> &a, vector<int> &dirs) {
	
    int n = a.size();
    vector<vector<pair<int,bool>>> d(n, vector<pair<int,bool>>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            d[i][j].first = a[i][j];
        }
    }
    
    co("#"); cos(++debug); cos(":");
    
    // 0: down, 1: up, 2: left, 3: right
    for (int dir : dirs) {
    	
		switch(dir){
			case 0: // 위
				cos("up");
				break; 
			case 1: // 아래
				cos("down");
				break;
			case 2: // 오른쪽
				cos("right");
				break;
			case 3: // 왼쪽
				cos("left");
				break; 
		}
        
		bool ok = false;
		
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                d[i][j].second = false;
            }
        }
        
        while (true) {
            ok = false;
            if (dir == 1) { // 아래쪽 
                for (int i=n-2; i>=0; i--) {
                    for (int j=0; j<n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i+1][j].first == 0) {
                            d[i+1][j].first = d[i][j].first;
                            d[i+1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i+1][j].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i+1][j].second == false) {
                                d[i+1][j].first *= 2;
                                d[i+1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 0) { // 위쪽 
                for (int i=1; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i-1][j].first == 0) {
                            d[i-1][j].first = d[i][j].first;
                            d[i-1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i-1][j].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i-1][j].second == false) {
                                d[i-1][j].first *= 2;
                                d[i-1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 3) { // 왼쪽  
                for (int j=1; j<n; j++) {
                    for (int i=0; i<n; i++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j-1].first == 0) {
                            d[i][j-1].first = d[i][j].first;
                            d[i][j-1].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i][j-1].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i][j-1].second == false) {
                                d[i][j-1].first *= 2;
                                d[i][j-1].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 2) { // 오른쪽 
                for (int j=n-2; j>=0; j--) {
                    for (int i=0; i<n; i++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j+1].first == 0) {
                            d[i][j+1].first = d[i][j].first;
                            d[i][j+1].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i][j+1].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i][j+1].second == false) {
                                d[i][j+1].first *= 2;
                                d[i][j+1].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } 
            if (ok == false) break;
        }
	    cl;
		rep(i, 0, n){
			rep(j, 0, n){
				cos(d[i][j].first);
			}	
			cl;
		}
		cl;
    }
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (ans < d[i][j].first) {
                ans = d[i][j].first;
            }
        }
    }
    return ans;
}

int main() {
	
	freopen("input.txt", "rt", stdin);
	out.open("output_src.txt");
	
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int k=0; k<(1<<(LIMIT*2)); k++) {
        vector<int> dir = gen(k);
        int cur = check(a, dir);
        if (ans < cur) ans = cur;
    }
    
    cl;
	cos("ans:");
    col(ans);
    
    out.close();
    
	return 0;
}
