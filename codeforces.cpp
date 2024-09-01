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
//     int n,a,b;
//     cin>>n>>a>>b;

//     double k = (2*(b-a) + 1)/2;

//     int k1 = floor(k);
//     int k2 = ceil(k);

//     if(k1<=n && k1>0){
//         int ans = (k1*(b+1) - ((k1*(k1+1))/2) + a*(n-k1));
//     }
//     if(k2<=n && k2)

//     if(k>0 && k<n){
//         cout<<(int)(k*(b+1) - ((k*(k+1))/2) + a*(n-k))<<endl;
//     }
//     else{
//         cout<<a*n<<endl;
//     }
// }

// vector<int> moves = {0,-1,0,1,0};

// int helper(int i,int cnt,vector<int>& arr){
//     if(cnt == 0){

//     }
// }

// int lcs(int i,int j,string& a,string& b,vector<vector<int>>& dp){
//     // if(i == a.length() && j == b.length()) return 0;
//     if(i==a.length() || j==b.length()) return 0;
//     if(dp[i][j] != -1) return dp[i][j];

//     int ans = INT_MIN;
//     if(a[i] == b[j]){
//         ans = 1 + lcs(i+1,j+1,a,b,dp);
//     }

//     ans = max(ans,max(lcs(i+1,j,a,b,dp),lcs(i,j+1,a,b,dp)));

//     return dp[i][j] = ans;
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;

//     string s,t;
//     cin>>s;
//     cin>>t;

//     vvi a(26,vi(n,0)),b(26,vi(n,0));

//     for(int i = 0;i<26;i++){
//         char c = i + 'a';
//         for(int j = 0;j<n;j++){
//             if(s[j] == c){
//                 a[i][j] = 1;
//             }
//             if(t[j] == c){
//                 b[i][j] = 1;
//             }
//         }
//     }

//     for(int i = 0;i<26;i++){
//         for(int j = 1;j<n;j++){
//             a[i][j] += a[i][j-1];
//             b[i][j] += b[i][j-1];
//         }
//     }

//     // cout<<'a'<<"           "<<'b'<<endl;
//     // for(int i = 0;i<26;i++){
//     //     for(int j = 0;j<n;j++){
//     //         cout<<a[i][j]<<" ";
//     //     }
//     //     for(int j = 0;j<n;j++){
//     //         cout<<b[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }

//     while(q--){
//         int l,r;
//         cin>>l>>r;
//         l--;
//         r--;

//         int ans = 0;
//         for(int i = 0;i<26;i++){
//             int iInb = b[i][r];
//             int iIna = a[i][r];
//             if(l > 0){
//                 iInb -= b[i][l-1];
//                 iIna -= a[i][l-1];
//             }
//             ans += (abs(iInb - iIna));
//         }
//         cout<<ans/2<<endl;
//     }
// }

// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;

//     vc a(n+1);
//     for(int i = 1;i<=n;i++){
//         cin>>a[i];
//     }

//     int i = 0;
//     while(i<n+1){
//         if(i == 0 || a[i] == 'L'){
//             int j = i+m;
//             if(j >= n+1){
//                 cout<<"Yes"<<endl;
//                 return;
//             }
//             int lastWidx = -1;
//             int lastLidx = -1;
//             while(j>i){
//                 if(a[j] == 'L'){
//                     lastLidx = max(lastLidx,j);
//                 }
//                 if(a[j] == 'W'){
//                     lastWidx = max(lastWidx,j);
//                 }
//                 j--;
//             }
//             if(lastLidx != -1 && lastLidx != i){
//                 i = lastLidx;
//             }else if(lastWidx != -1){
//                 i = lastWidx;
//             }else{
//                 cout<<"No"<<endl;
//                 return;
//             }
//         }
//         else if(a[i] == 'W'){
//             int cnt = 0;
//             while(i<n+1 && a[i] == 'W'){
//                 if(a[i] == 'C'){
//                     cout<<"No"<<endl;
//                 }
//                 cnt++;
//                 i++;
//             }
//             if(cnt>k){
//                 cout<<"No"<<endl;
//                 return;
//             }
//             if(i == n+1){
//                 cout<<"Yes"<<endl;
//                 return;
//             }
//             k -= cnt;
//         }
//         else if(a[i] == 'C'){
//             cout<<"No"<<endl;
//             return;
//         }
//     }

//     cout<<"Yes"<<endl;
// }

// bool check(int node,vector<int> adj[],vector<int>& val,int x){
//     if(adj[node].size() == 0){
//         return (val[node] >= x);
//     }

//     bool fl = 1;
//     for(auto adjNode:adj[node]){
//         if(val[node]+x >= ){
//             fl &= check(adjNode,adj,val,x);
//         }else{
//             fl &= check(adjNode,adj,val,x + (x-val[node]));
//         }
//     }

//     return fl;
// }

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

// void solve(){
//     int n,m;
//     vi a;

//     cin>>n;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         a.push_back(x);
//     }
//     cin>>m;

//     set<set<int>> st;
//     map<int,set<int>> mp;
//     for(int i = 0;i<n;i++){
//         mp[a[i]].insert(i);
//     }
//     for(auto i:mp){
//         st.insert(i.second);
//     }

//     mp.clear();

//     // for(auto i:st){
//     //     for(auto j:i){
//     //         cout<<j<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     for(int i = 0;i<m;i++){
//         string s;
//         cin>>s;

//         if(s.length() != n){
//             cout<<"No"<<endl;
//             continue;
//         }

//         for(int i = 0;i<s.length();i++){
//             mp[s[i]].insert(i);
//         }

//         bool fl = 1;
//         for(auto j:mp){
//             set<int> s1 = j.second;
//             int tmp = a[*(s1.begin())];
//             for(auto k:s1){
//                 if(a[k] != tmp){
//                     fl = 0;
//                     break;
//                 }
//             }
//             if(fl == 0) break;
//         }
//         for(auto j:st){
//             char tmp = s[*(j.begin())];
//             for(auto k:j){
//                 if(s[k] != tmp){
//                     fl = 0;
//                     break;
//                 }
//             }
//             if(fl == 0) break;
//         }

//         mp.clear();

//         if(fl){
//             cout<<"YES"<<endl;
//         }else{
//             cout<<"No"<<endl;
//         }
//     }
//     // cout<<"*********"<<endl;
// }

// void solve(){
//     int n;
//     cin>>n;

//     vi a(n),b(n);

//     for(int i = 0 ;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i = 0 ;i<n;i++){
//         cin>>b[i];
//     }

//     int i = 0,ii = 0,j = n-1,jj = n-1;

//     while(i<j){
//         if(a[i] != b[ii] && a[i] != b[jj]){
//             cout<<"Alice"<<endl;
//             return;
//         }else if(a[j] != b[ii] && a[j] != b[jj]){
//             cout<<"Alice"<<endl;
//             return;
//         }else{
//             if(a[i] == b[ii]){
//                 i++;
//                 ii++;
//             }else if(a[i] == b[jj]){
//                 i++;
//                 jj--;
//             }else if(a[j] == b[ii]){
//                 j--;
//                 ii++;
//             }else if(a[j] == b[jj]){
//                 j--;
//                 jj--;
//             }
//         }
//     }

//     cout<<"Bob"<<endl;
// }


// void solve(){
//     int n;
//     cin>>n;

//     vi a(n);
//     in(a);

//     sort(all(a));

//     int ans = -1;
//     cout<<a[n/2]<<endl;
// }

// void solve(){
//     int n;
//     cin>>n;

//     vector<int> ans(n+1,-1);

//     function<int(int u,int v)> query = [&](int u,int v)->int{
//         cout<<"? "<<u<<" "<<v<<endl;
//         int res;
//         cin>>res;
//         cout.flush();

//         return res;
//     };

//     ans[1] = 1;
//     for(int i = 2;i<=n;i++){
//         int lastAncestor = 1;
//         while(true){
//             int x = query(i,lastAncestor);
//             if(x == i){
//                 break;
//             }
//             lastAncestor = x;
//         }
//         ans[i] = lastAncestor;
//     }

//     cout<<"! ";
//     for(int i = 2;i<=n;i++){
//         cout<<i<<" "<<ans[i]<<" ";
//     }
//     cout<<endl;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;

//     vi a(n);
//     in(a);

//     sort(all(a),greater<int>());

//     int sc = 0;
//     if(n&1){
//         sc = a[n-1];
//     }
    
//     priority_queue<int> q;
//     for(int i = 0;i<n-1;i+=2){
//         sc += (a[i] - a[i+1]);
//         q.push(a[i] - a[i+1]);
//     }

//     if(k == 0){
//         cout<<sc<<endl;
//         return;
//     }

//     while(!q.empty() && k){
//         int x = q.top();
//         q.pop();
//         if(k >= x){
//             sc -= x;
//             k -= x;
//         }else if(k > 0){
//             sc -= k;
//             k = 0;
//         }
//     }

//     cout<<sc<<endl;
// }

// void solve(){
//     int n,a,b;
//     cin>>n>>a>>b;

//     vi v(n);
//     in(v);

//     int g = __gcd(a,b);

//     for(auto &i:v){
//         i %= g;
//     }

//     int ans = INT_MAX;
//     sort(all(v));

//     int maxi = v[n-1];

//     for(int i = 0;i<n;i++){
//         ans = min(ans,maxi - v[i]);
//         maxi = v[i] + g;
//     }

//     cout<<ans<<endl;
// }

void solve(){
    
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
