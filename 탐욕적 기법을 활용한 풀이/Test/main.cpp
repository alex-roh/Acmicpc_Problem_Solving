#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

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

#define tp top
#define frt front
#define ps push
#define pp pop
#define emt empty
#define pb push_back
#define fst first
#define scd second

using namespace std;
struct jewel {
    int m, v;
};
int main() {
	
	freopen("input.txt", "rt", stdin);
	
    int n,k;
    scanf("%d %d",&n,&k);
    vector<jewel> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].m, &a[i].v);
    }
    sort(a.begin(), a.end(), [](jewel u, jewel v) {
        return u.v > v.v;
    });
    
    multiset<int> s;
    for (int i=0; i<k; i++) {
        int t;
        scanf("%d",&t);
        s.insert(t);
    }
    long long ans = 0;
    for (int i=0; i<n; i++) {
        auto it = s.lower_bound(a[i].m);
        if (it != s.end()) {
            ans += a[i].v;
            s.erase(it);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
