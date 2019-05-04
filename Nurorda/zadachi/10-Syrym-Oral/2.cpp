#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
int n,m,x,y,fup[200009],tin[200009],tim,i;
bool was[200009],w[200009];
vector < int > g[200009],ans,numr[200009];
void dfs(int v, int p)
{
	was[v] = true;
    tin[v] = fup[v] = ++tim;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
			
			if (to == p) continue;
			
			if (!was[to])
			{

				dfs(to,v);
				fup[v] = min(fup[v] , fup[to]);

				if (fup[to] > tin[v]) w[numr[v][i]] = true;
			}else

				fup[v] = min(tin[to],fup[v]);
	}
}
int main()

{
	//freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		numr[x].push_back(i);
		numr[y].push_back(i);
	}

	for (i = 1; i <= n; i++)
		if ( !was[i] ) dfs(i,-1);

	for (i = 1; i <= m; i++)
		if (w[i]) ans.push_back(i);
 	printf("%d\n",ans.size());
	for (i = 0; i < ans.size(); i++)
		printf("%d ",ans[i]);
    system ("pause");
    return 0;
}
