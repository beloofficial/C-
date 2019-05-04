#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)1e5 + 10;
const LL INF = (LL)1e18;
LL str[maxn],mmask[maxn];
LL cost[1 << 12],dp[1 << 12];
vector<int> g[maxn];
bool used[maxn];
int main()
{
freopen("D.in", "r", stdin);
freopen("D.out", "w", stdout);

	int b,n,m; cin >> b >> n >> m;
	int id = 0;
	for (int i = 0; i < b; i++) {
		int k; scanf("%d",&k);
		for (int j = 0; j < k; j++) {
			scanf("%d",&str[id]);
			mmask[id] = 1 << i;
			id++;
		}
	}
	for (int i = 0; i < m; i++) {
		int k; scanf("%d%d",&str[n + i],&k);
		for (int j = 0; j < k; j++) {
			int x; scanf("%d",&x);
			--x;
			g[n + i].pb(x);
		}
	}
	for (int i = 0; i < (1 << b); i++) {
		cost[i] = INF;
		dp[i] = INF;
	}
	queue<int> q;
	for (int i = n; i < n + m; i++) {
		memset(used,false,sizeof(used));
		int mask = 0;
		q.push(i);
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			mask |= mmask[v];
			for (int j = 0; j < sz(g[v]); j++) {
				int to = g[v][j];
				if (used[to]) continue;
				used[to] = true;
				q.push(to);
			}
		}
		mmask[i] = mask;
	}
	for (int i = 0; i < n + m; i++) {
		cost[mmask[i]] = min(cost[mmask[i]],str[i]);
	}
	cost[0] = 0;
	dp[0] = 0;
	for (int i = 0; i < (1 << b); i++) {
		for (int j = 0; j < (1 << b); j++) {
			dp[i | j] = min(dp[i | j],dp[i] + cost[j]);
		}
	}
	cout << dp[(1 << b) - 1] << endl;
	return 0;
}