#include<bits/stdc++.h>

// #define int long long
#define ll long long
#define ld long double
#define int ll
#define x first
#define y second
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
#define MOD 1000000007
#define vi vector<int>
#define pi 3.141592653589793
#define rep(i,a,b) for(int i = a;i<b;i++)
using namespace std;

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

//Finds (a^m-2 = a^-1 mod m) when m is prime. In CF m is mostly 1e9 + 7 which is prime.
//Helpful in modular arithmetic involving division.
int inv(int a,int m){
    // a^(m-2) = a^-1 mod m; (if m is prime, in our case 1e9 + 7) (we will be passing m-2 to this function.)
    int res = 1;
    while(m){
        if(m&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        m = (m>>1);
    }

    return res%MOD;
}
////////////// CF-973 Div 2 ///////////////////////////
//Problem A
// void solve(){
//     int n,x,y;
//     cin>>n;
//     cin>>x>>y;

//     cout<< n/min(x,y) + (n%min(x,y) > 0)<<endl;

//     // if(x >= y){
//     //     cout<<(n/y) + (n%y > 0)<<endl;
//     // }else{
//     //     cout<<n/x + (n%x > 0)<<endl;
//     // }
// }

//Problem B
// void solve(){
//     int n;
//     cin>>n;

//     ll a[n];
//     rep(i,0,n){
//         cin>>a[i];
//     }

//     ll sum = 0;
//     for(int i = 0;i<n-2;i++){
//         sum += a[i];
//     }

//     cout<<a[n-1] - (a[n-2] - sum)<<endl;
// }

//Problem C
// void solve(){
//     int n; cin>>n;

//     function<bool(string s)> guess = [&](string s)->bool{
//         cout<<"? "<<s<<endl;
//         bool res;
//         cin>>res;

//         return res;
//     };

//     string s = "";
//     bool fl = 0;
//     while(s.length() < n){
//         if(!fl){
//             if(guess(s+'0')){
//                 s += '0';
//             }else if(guess(s+'1')){
//                 s += '1';
//             }else{
//                 fl = 1;
//             }
//         }else{
//             if(guess('0' + s)){
//                 s = '0' + s;
//             }else{
//                 s = '1' + s;
//             }
//         }
//     }

//     cout<<"! "<<s<<endl;
//     cout.flush();
// }

//Problem D (--pending...)
// void solve(){
//     int n;cin>>n;

//     ll a[n],sum = 0;
//     rep(i,0,n){
//         cin>>a[i];
//         sum += a[i];
//     }

//     ll l = 0;
//     ll r = 1e13;

//     while(l<=r){
//         ll mid = l + (r - l)/2;

//         int acc = 0;
//         for(int i = 0;i<n;i++){
//             if(a[i]+acc > mid){
//                 a[i] = mid;
//                 acc = (a[i] + acc - mid);
//             }
//         }

//         if(acc){
//             l = mid + 1;
//         }else{
//             r = mid-1;
//         }
//     }

//     l = 0;
//     ll mx = r;
//     while(l<=r){
//         ll mid = l + (r-l)/2;

//         int acc = 0;
//         for(int i = 0;i<n;i++){
//             if(a[i] + acc > mid){
//                 a[i] = mid;
//                 acc = a[i] + acc - mid;
//             }
//         }

//         if(acc){
//             l = mid+1;
//         }else{
//             r = mid-1;
//         }
//     }
//     ll mn = r;

//     cout<<mx - mn<<endl;

// }
////////////// //////////// ///////////////////////////


///////////// CF 974 Div 3 ////////////////////////////

//Problem 1
// void solve(){
//     int n,k;
//     cin>>n>>k;

//     int a[n];
//     rep(i,0,n){
//         cin>>a[i];
//     }

//     int rg = 0;
//     int ans = 0;
//     rep(i,0,n){
//         if(a[i] == 0 && rg){
//             rg--;
//             ans++;
//         }
//         if(a[i] > 0 && a[i]>=k){
//             rg += a[i];
//         }
//     }

//     cout<<ans<<endl;
// }

//Problem 2
// void solve(){
//     ll n,k;
//     cin>>n>>k;

//     ll l = 0;
//     ll r = n;

//     ll ans = 0;
//     while(l<=r){
//         int i = l + (r-l)/2;

//         if(i < n+1-k){
//             ans = max(ans,i);
//             l = i+1;
//         }else{
//             r = i-1;
//         }
//     }

//     ll cntOddn = n - (n/2);
//     ll cntOddans = ans - (ans/2);

//     bool isSumEven = ((cntOddn%2 == 0 && cntOddans%2 == 1) || (cntOddn%2 == 1 && cntOddans%2 == 0));

//     cout<<(isSumEven?"NO":"Yes")<<endl;
// }

//Problem C
// void solve(){
//     ll n;
//     cin>>n;

//     ld a[n];
//     ll maxIdx = 0;
//     ld sm = 0;
//     rep(i,0,n){
//         cin>>a[i];
//         if(a[i] > a[maxIdx]){
//             maxIdx = i;
//         }
//         sm += a[i];
//     }

//     ll l = 0;
//     ll r = 2*1e11 + 1;

//     ll val = r+1;
//     ll ans = r+1;
//     while(l<=r){
//         ll x = l + (r-l)/2;

//         ld tmp = a[maxIdx];
//         a[maxIdx] += x;
//         double avg = ((sm + x)/n);
//         int cnt = 0;
//         for(ll i = 0;i<n;i++){
//             if(a[i] < (avg/2)){
//                 cnt++;
//             }
//         }

//         ll hTotPop = n/2;
//         if(cnt >= hTotPop + 1){
//             ans = min(ans,x);
//             r = x - 1;
//         }else{
//             l = x + 1;
//         }
//     }

//     cout<<((ans == val) ? -1 : ans)<<endl;
// }

//Problem D
// void solve(){
//     int n,d,k;
//     cin>>n>>d>>k;

//     int startedJobs[n+1] = {0};
//     int endedJobs[n+1] = {0};

//     rep(i,0,k){
//         int s,e;
//         cin>>s>>e;

//         startedJobs[s]++;
//         endedJobs[e]++;
//     }

//     for(int i = 1;i<=n;i++){
//         startedJobs[i] += startedJobs[i-1];
//         endedJobs[i] += endedJobs[i-1];
//     }

//     int minO = 1e9;
//     int maxO = 0;

//     int bro = 1;
//     int mum = 1;

//     for(int s = d;s<=n;s++){
//         int o = startedJobs[s] - endedJobs[s-d];

//         if(o > maxO) maxO = o, bro = s-d+1;
//         if(o < minO) minO = o, mum = s-d+1;
//     }

//     cout<<bro<<" "<<mum<<endl;
// }

//Problem E
void solve(){
    int n,m,h;
    cin>>n>>m>>h;

    bool a[n] = {0};
    rep(i,0,h){
        int x;
        cin>>x;

        a[x-1] = 1;
    }

    vector<pair<int,int>> g[2*n];//n - 2n-1 nodes are mirrors of nodes 0-(n-1).
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;

        u--;
        v--;

        g[u].push_back({v,w});
        g[v].push_back({u,w});

        g[u+n].push_back({v+n,w/2});
        g[v+n].push_back({u+n,w/2});
    }

    for(int i = 0;i<n;i++){
        if(a[i])
            g[i].push_back({i+n,0});
    }

    auto dijkstra = [&](int start)->vector<int>{
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> arr(2*n,1e15);
        q.push({0,start});
        arr[start] = 0;
        while(!q.empty()){
            auto p = q.top();
            int cost = p.first;
            int node = p.second;

            q.pop();

            if(arr[node] < cost) continue;
            if(arr[node] == 1e15) continue;

            for(auto adj:g[node]){
                int adjNode = adj.first;
                int c = adj.second;
                if(c + arr[node] < arr[adjNode]){
                    arr[adjNode] = c+arr[node];
                    q.push({arr[adjNode],adjNode});
                }
            }
        }

        return arr;
    };

    auto arr1 = dijkstra(0);
    auto arr2 = dijkstra(n-1);

    int ans = 1e15;
    for(int i = 0;i<n;i++){
         ans = min(ans,max(min(arr1[i],arr1[i+n]),min(arr2[i],arr2[i+n])));
    }

    // cout<<"***********"<<endl;
    // for(auto i:arr1){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i:arr2){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // cout<<"***********"<<endl;

    cout<<((ans >= 1e15)?-1:ans)<<endl;
}

////////////// //////////// ///////////////////////////



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}