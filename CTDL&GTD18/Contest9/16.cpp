/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[1005];
vector<int> ke[1005];
int n,m,s;
void BFS(int u){
    queue<int> q;
    q.push(u); vis[u] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        //cout << x << ' ';
        for(auto v : ke[x]){
            if(vis[v] == 0){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
void Input(){
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++){
        ke[i].clear();
    }
    cin >> n >> m ;
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}
void Solve(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            BFS(i);
            res++;
        }
    }
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
