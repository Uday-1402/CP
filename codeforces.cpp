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

int callBack(int p,int q){
    return p&q;
}

int higherOrder(int a,int b,function<int(int c,int d)> callBack){
    return callBack(a,b);
}

//Problem B
// void solve(){
//     int n;
//     cin>>n;

//     vi a(n);
//     in(a);

//     cout<<a[n-1]<<" ";
//     for(int i = 0;i<n-1;i++){
//         cout<<a[i]<<" ";
//     }

//     cout<<endl;
// }

// Problem C
// void solve(){
//     int n,k;
//     cin>>n>>k;
    
//     vpi a(n);
//     for(int i = 0;i<n;i++){
//         cin>>a[i].x;
//     }
//     for(int i = 0;i<n;i++){
//         cin>>a[i].y;
//     }

//     sort(all(a));
    
//     function<int(int i)> medianIdx = [&](int i)->int{
//         int val = (n - 1)/2 + (n-1)%2;
//         if(i < val){
//             return val;
//         }
//         return val -1;
//     };

//     function<bool(int num)> check = [&](int num)->int{
//         int reqCnt = (n + 1)/2 + 1;
//         int remOps = k;
//         for(int i = n-1;i>=0;i--){
//             if(a[i].x >= num){
//                 reqCnt--;
//             }else if(a[i].y){
//                 if(num - a[i].x <= remOps){
//                     remOps -= (num - a[i].x);
//                     reqCnt--;
//                 }
//             }
//         }
//         return reqCnt <= 0;
//     };

//     int ans = a[n-1].x + a[medianIdx(n-1)].x;
//     // cout<<ans<<"*1"<<endl;
//     for(int i = n-1;i>=0;i--){
//         if(a[i].y){
//             ans = max(ans,a[i].x + k + a[medianIdx(i)].x);
//             break;
//         }
//     }
//     // cout<<ans<<"*2"<<endl;

//     int l = 1;
//     int r = 1e9;

//     while(l<=r){
//         int mid = l + (r-l)/2;

//         if(check(mid)){
//             ans = max(ans,a[n-1].x + mid);
//             l = mid+1;
//         }else{
//             r = mid-1;
//         }
//     }

//     // cout<<ans<<"*3"<<endl;
//     cout<<ans<<endl;
// }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cout<<higherOrder(1,2,callBack);

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
