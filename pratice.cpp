#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

#define FOR(k,a,b) for(int k=(a); k<=(b); ++k)
#define IFOR(k,a,b) for(int k=(a); k>=(b); --k)
#define REP(k,a) for(int k=0; k<(a);++k)
#define IREP(k,a) for(int k=a-1; k>=(0);--k)
#define SZ(a) int((a).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define MP make_pair
#define x first
#define y second
#define INF 1000000001
#define INFLONG 1000000000000000000
#define MOD 1000000007
#define MAX 100
#define ITERS 100
#define MAXM 200000
#define MAXN 1000000
#define PI 3.1415926535897932384626
#define ERR -987654321
#define read1(a) scanf("%d",&a)
#define read2(a,b) scanf("%d%d",&a,&b)
#define read3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define readl1(a) scanf("%lld",&a)
#define readl2(a,b) scanf("%lld%lld",&a,&b)
#define readl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

int dp[110][110];
bool visited[110][110];
pii d[8] = {{-1,-1}, {-1,0}, {0,-1}, {1,1}, {1,0}, {0,1}, {1,-1}, {-1,1}};

int get_lower(int a, int r, int y) {
    int p = sqrt(r*r - y*y);
    return a - p;
}

int get_upper(int a, int r, int y) {
    int p = sqrt(r*r - y*y);
    return a + p + 1;
}

bool dfs(int x, int y, int a, int b) {
    cout<<"--"<<x<<" "<<y<<endl;
    if(x == a && y == b) return true;
    visited[y][x] = true;
    bool flag = false;
    REP(i,8) {
        int p = x + d[i].x, q = y + d[i].y;
        //cout<<p<<" "<<q<<endl;
        if(p>a || q>b || p<0 || q<0 || visited[q][p] || dp[q][p] != 0) continue;
        flag |= dfs(p, q, a, b);
    }
    cout<<"_____________________"<<endl;
    return flag;
}

string solve(int a, int b, int n, int r, vector<int> &x, vector<int> &y) {
    REP(i,b+1) {
        REP(j,x.size()) {
            //cout<<i<<" "<<j<<" "<<endl;
            if(abs(i-y[j]) > r) continue;
            int x1 = get_lower(x[j], r, i-y[j]);
            int x2 = get_upper(x[j], r, i-y[j]);
            cout<<i<<" "<<j<<" "<<x1<<" "<<x2<<endl;
            if(x1<=100) {
                if(x1<0) dp[i][0] += 1;
                else dp[i][x1] += 1;
            }
            if(x2>=0 && x2<=100) dp[i][x2] -= 1;
        }
    }
    REP(i,101) {
        REP(j,101) if(j) dp[i][j] += dp[i][j-1];
    }
    REP(i,5) {
        REP(j,5) cout<<dp[i][j]<<" "; cout<<endl;
    }
    memset(visited, false, sizeof(visited));
    if(dfs(0,0,a,b)) return "YES";
    else "NO";
}

int main() {
	int a,b,n,r;
	vi x, y;
	cin>>a>>b>>n>>r;
	x.resize(n); y.resize(n);
	REP(i,n) cin>>x[i];
	REP(i,n) cin>>y[i];
	solve(a,b,n,r,x,y);
}
