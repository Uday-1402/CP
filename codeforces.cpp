#include <bits/stdc++.h>

#define int long long
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define mkp(a, b) make_pair(a, b);
#define in(a)         \
    for (auto &i : a) \
    {                 \
        cin >> i;     \
    }

using namespace std;

bool secondSmall_firstLarge(pair<int, int> &a, pair<int, int> &b)
{
    if (a.x != b.x)
        return (a.x > b.x);
    return a.y < b.y;
}
bool firstSmall_secondLarge(pair<int, int> &a, pair<int, int> &b)
{
    if (a.x != b.x)
        return (a.x < b.x);
    return a.y > b.y;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    // cout<<a<<" "<<b<<endl;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

// void solve(){
//     int n;
//     cin>>n;

//     int l = 0;
//     int r = 1000000000;

//     vector<int> val(n);
//     for(int i = 0;i<n;i++){
//         cin>>val[i];
//         // r = max(r,val[i]);
//     }

//     vector<int> p(n,-1);

//     for(int i = 1;i<n;i++){
//         int x;
//         cin>>x;

//         p[i] = --x;
//     }

//     vector<int> adj[n];

//     for(int i = 1;i<n;i++){
//         if(p[i] != -1)
//             adj[p[i]].push_back(i);
//     }

//     // function<int(int node)> dfs = [&](int node)->int{
//     //     if(adj[node].size() == 0) return val[node];
//     //     int mini = 1e9;
//     //     for(auto adjNode:adj[node]){
//     //         mini = min(mini,dfs(adjNode));
//     //     }
//     //     if(node == 0){
//     //         return (val[node] + mini);
//     //     }
//     //     if(mini <= val[node]){
//     //         return mini;
//     //     }
//     //     else return (mini + val[node])/2;
//     // };

//     // cout<<dfs(0)<<endl;

//     function<bool(int node,int x)> check = [&](int node,int x)->bool{
//         if(adj[node].size() == 0) return (val[node] >= x);
//         bool fl = 1;
//         if(node != 0){
//             x = x + (max(0,x - val[node]));
//         }
//         if(x > 1e9) return false;
//         for(auto adjNode: adj[node]){
//             fl &= check(adjNode,x);
//         }

//         return fl;
//     };

//     int ans = 0;
//     while(l<=r){
//         int mid = l + (r-l)/2;

//         if(check(0,mid)){
//             ans = max(ans,mid);
//             l = mid+1;
//         }else{
//             r = mid-1;
//         }
//     }

//     cout<<val[0] + ans<<endl;
// }

// void solve()
// {
//     int n;
//     cin >> n;

//     vi adj[n];
//     for (int i = 1; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;

//         adj[x - 1].push_back(y - 1);
//         adj[y - 1].push_back(x - 1);
//     }

//     string s;
//     cin >> s;

//     int cnt0 = 0,cnt1 = 0,cntq = 0;

//     function<void(int node, int par)> dfs = [&](int node, int par) -> void
//     {
//         if(adj[node].size() == 1 && adj[node][0] == par){
//             if(s[node] == '?') cntq++;
//             else if(s[node] == '0') cnt0++;
//             else cnt1++;
//         }

//         for(auto adjNode:adj[node]){
//             if(adjNode != par)
//                 dfs(adjNode,node);
//         }
//     };

//     dfs(0,-1);

//     int ans = 0;
//     if(s[0] == '?'){
//         cntq--;
//         ans = max(cnt0,cnt1) + (cntq/2) + (cntq%2);
//     }else if(s[0] == '0'){
//         ans = cnt1 + (cntq/2) + (cntq%2);
//     }else{
//         ans = cnt0 + (cntq/2) + (cntq%2);
//     }

//     cout<<ans<<endl;
// }

// vector<int> isSq(1e6,0);

// void solve(){
//     int n;
//     cin>>n;

//     string s;
//     cin>>s;

//     if(isSq[n]){
//         int len = sqrt(n);
//         for(int i = 0;i<len;i++){
//             for(int j = 0;j<len;j++){
//                 if(i == 0 || i == len-1 || j == 0 || j == len - 1){
//                     if(s[i*len + j] != '1'){
//                         cout<<"No"<<endl;
//                         return;
//                     }
//                 }else{
//                     if(s[i*len + j] != '0'){
//                         cout<<"No"<<endl;
//                         return;
//                     }
//                 }
//             }
//         }
//         cout<<"Yes"<<endl;
//     }else{
//         cout<<"No"<<endl;
//     }
// }

// void solve(){
//     int l,r;
//     cin>>l>>r;

//     if(l == r){
//         cout<<1<<endl;
//         return;
//     }

//     int k = 1;
//     int cnt = 1;
//     for(int i = l;i<=r;){
//         if(i+k<=r)
//             cnt++;
//         i += k;
//         k++;
//     }

//     cout<<cnt<<endl;
// }

// void solve(){
//     int n;
//     cin>>n;

//     vi p(n+1);
//     for(int i = 1;i<=n;i++){
//         cin>>p[i];
//     }

//     string s;
//     cin>>s;

//     vi vis(n+1,0);
//     map<int,int> isBlack;

//     for(int i = 0;i<n;i++){
//         if(s[i] == '0'){
//             isBlack[p[i+1]] = 1;
//         }
//     }

//     vvi a;
//     for(auto pi:p){
//         if(pi == 0) continue; 
//         vi b;
//         while(!vis[pi]){
//             vis[pi] = 1;
//             b.push_back(pi);
//             pi = p[pi];
//         }
//         if(b.size()){
//             a.push_back(b);
//         }
//     }

//     vi ans(n+1,0);
//     for(auto i:a){
//         int nBlack = 0;
//         for(auto j:i){
//             if(isBlack[j]) nBlack++;
//         }
//         for(auto j:i){
//             ans[j] = nBlack;
//         }
//     }

//     for(int i = 1;i<=n;i++){
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
// }

int32_t main()
{
    int t;
    cin >> t;

    // for(int i = 0;i*i<=1e6;i++){
    //     isSq[i*i] = 1;
    // }

    while (t--)
    {
        solve();
    }

    return 0;
}
