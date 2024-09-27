#include<bits/stdc++.h>

// #define int long long
#define ll long long
#define x first
#define y second
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define mkp(a, b) make_pair(a, b);
#define rep(i,a,b) for(int i = a;i<b;i++)
#define MOD 1000000007
#define pi 3.141592653589793
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

//Dice combination DP.
// void solve(){
//     int n;
//     cin>>n;

//     vector<int> dp(n+1,0);

//     // function<int(int sum)> memo = [&](int sum)->int{
//     //     if(sum < 0) return 0;
//     //     if(sum == 0) return 1;

//     //     if(dp[sum] != -1) return dp[sum];

//     //     int ans = 0;
//     //     for(int i = 1;i<=6;i++){
//     //         ans += memo(sum - i)%MOD;
//     //         ans %= MOD;
//     //     }

//     //     return dp[sum] = ans%MOD;
//     // };

//     auto tab = [&](){
//         dp[0] = 1;
//         for(int i=1;i<=n;i++){
//             int ans = 0;
//             for(int j = 1;j<=6;j++){
//                 if(i - j >= 0){
//                     ans += dp[i-j]%MOD;
//                     ans %= MOD;
//                 }
//             }
//             dp[i] = ans%MOD;
//         }
//         cout<<dp[n]<<endl;
//     };
//     tab();

//     // cout<<memo(n)<<endl;
// }


//Minimizing coins DP
// void solve(){
//     int n,x;
//     cin>>n>>x;

//     int nums[n];
//     for(int i = 0;i<n;i++) cin>>nums[i];

//     sort(nums,nums+n);
    // vector<vector<int>> dp(n,vector<int>(x + 1,1e9));
    // vector<int> dp1(x+1,1e9);

    // function<int(int i,int sum)> memo = [&](int i,int sum)->int{
    //     if(sum == 0) return 0;
    //     if(i == 0){
    //         if(sum % nums[i]) return 1e9;
    //         return sum/nums[i];
    //     }

    //     if(dp[i][sum] != -1) return dp[i][sum];

    //     int stay = 1e9;
    //     int next = memo(i-1,sum);

    //     if(nums[i] <= sum){
    //         stay = 1 + memo(i,sum - nums[i]);
    //     }

    //     return dp[i][sum] = min(next,stay);
    // };

    // int ans = memo(n-1,x);

    // function<int(int sum)> memo1 = [&](int sum)->int{
    //     if(sum == 0) return 0;

    //     if(dp1[sum] != -1) return dp1[sum];

    //     int ans = 1e9;
    //     for(int i = 0;i<n;i++){
    //         if(sum >= nums[i]){
    //             ans = min(ans,1 + memo1(sum - nums[i]));
    //         }
    //     }

    //     return dp1[sum] = ans;
    // };

    // int ans1 = memo1(x);

    // for(int i = 0;i<n;i++){
    //     dp[i][0] = 0;
    // }
    // for(int sum = 0;sum <= x;sum++){
    //     dp[0][sum] = (sum%nums[0]) ? 1e9 : sum/nums[0];
    // }

    // dp1[0] = 0;
    // for(int sum = 1;sum<=x;sum++){
    //     for(int i = 0;i<n;i++){
    //         if(sum >= nums[i]){
    //             dp1[sum] = min(dp1[sum],1 + dp1[sum - nums[i]]);
    //         }
    //     }
    // }

    // if(dp1[x] >= 1e9) cout<<-1<<endl;
    // else cout<<dp1[x]<<endl;

    // for(int i = 1;i<n;i++){
    //     for(int sum = 1;sum <= x;sum++){
    //         int stay = 1e9;
    //         int next = dp[i-1][sum];

    //         if(nums[i] <= sum){
    //             stay = 1 + dp[i][sum - nums[i]];
    //         }

    //         dp[i][sum] = min(next,stay);
    //     }
    // }

    // if(dp[n-1][x] >= 1e9) cout<<-1<<endl;
    // else cout<<dp[n-1][x]<<endl;
    // if(ans >= 1e9) cout<<-1<<endl;
    // else cout<<ans<<endl;
    // if(ans1 >= 1e9) cout<<-1<<endl;
    // else cout<<ans1<<endl;
// }

//Coin Combinations DP
// int fac[101];
// void solve(){
//     int n,x;
//     cin>>n>>x;

//     int a[n];
//     for(int i = 0;i<n;i++) cin>>a[i];

//     vector<int> dp(x+1,0);
//     // function<int(int sum)> memo = [&](int sum)->int{
//     //     if(sum == 0) return 1;
        
//     //     if(dp[sum] < 1e9) return dp[sum];

//     //     int ans = 0;
//     //     for(int i = 0;i<n;i++){
//     //         if(sum >= a[i]){
//     //             ans += (memo(sum - a[i]) % MOD);
//     //             ans %= MOD;
//     //         }
//     //     }

//     //     return dp[sum] = ans%MOD;
//     // };

//     // cout<<memo(x)%MOD<<endl;

//     // dp[0] = 1;
//     // for(int sum = 1;sum<=x;sum++){
//     //     for(int i = 0;i<n;i++){
//     //         if(dp[sum] >= MOD) dp[sum] %= MOD;
//     //         if(sum >= a[i]){
//     //             dp[sum] += (dp[sum - a[i]]%MOD);
//     //             if(dp[sum] >= MOD) dp[sum] %= MOD;
//     //                 dp[sum] %= MOD;
//     //         }
//     //     }
//     // }

//     // cout<<dp[x]<<endl;
// }

//Coin Combination 2
// void solve(){
//     int n,x;
//     cin>>n>>x;

//     vector<int> a(n);
//     for(int i = 0;i<n;i++) cin>>a[i];

//     // vector<vector<int>> dp(x+1,vector<int>(n+1,0));

//     vector<int> curr(x+1,0);
//     vector<int> prev(x+1,0);
 

//     /////////////////O(n^3)
//     // // function<int(int sum,int prev)> memo = [&](int sum,int prev)->int{
//     // //     if(sum == 0) return 1;
        
//     // //     if(dp[sum][prev] < 1e9) return dp[sum][prev];

//     // //     int ans = 0;
//     // //     for(int i = prev;i<n;i++){
//     // //         if(sum >= a[i]){
//     // //             ans += (memo(sum - a[i],i)%MOD);
//     // //             ans %= MOD;
//     // //         }
//     // //     }

//     // //     return dp[sum][prev] = ans%MOD;
//     // // };

//     // // cout<<memo(x,0)<<endl;

//     // // for(int i = 0;i<n;i++){
//     // //     dp[0][i] = 1;
//     // // }
//     // // for(int sum = 1;sum<=x;sum++){
//     // //     for(int prev = n-1;prev>=0;prev--){
//     // //         for(int i = prev;i<n;i++){
//     // //             if(sum >= a[i]){
//     // //                 dp[sum][prev] += (dp[sum - a[i]][i]%MOD);
//     // //                 dp[sum][prev]%MOD;
//     // //             }
//     // //         }
//     // //     }
//     // // }

//     // // cout<<dp[x][0]%MOD<<endl;
//     /////////////////////

//     // function<int(int sum,int i)> memo = [&](int sum,int i)->int{
//     //     if(sum == 0) return 1;
//     //     if(i<0) return 0;

//     //     if(dp[sum][i] < 1e9) return dp[sum][i];

//     //     int take = 0;
//     //     int notTake = memo(sum,i-1)%MOD;

//     //     if(a[i] <= sum){
//     //         take = memo(sum - a[i],i)%MOD;
//     //     }

//     //     return dp[sum][i] = (take + notTake)%MOD;
//     // };

//     // cout<<memo(x,n-1)<<endl;
//     // for(int i = 0;i<n;i++) dp[0][i] = 1;

//     // sort(a,a+n);
    
//     prev[0] = 1;
//     curr[0] = 1;

//     for(int i = 1;i<=n;i++){
//         for(int sum = 1;sum <= x;sum++){
//             int take = 0;
//             int notTake = prev[sum];
//             if(a[i-1] <= sum){
//                 take = curr[sum-a[i-1]];
//             }

//             curr[sum] = (take + notTake)%MOD;
//         }
//         prev = curr;
//     }

//     cout<<prev[x]<<endl;
// }

//Removing digits
// void solve(){
//     int n;cin>>n;

//     // for(int i = 1;i<=9;i++) cout<<dig[i]<<" ";

//     vector<int> dp(n+1,1e9);
//     dp[0] = 0;
//     for(int x = 1;x<=n;x++){
//         int dig[10] = {0};
//         int p = 1;
//         while(x/p){
//             dig[(x/p)%10] = 1;
//             p *= 10;
//         }
//         for(int i = 1;i<=9;i++){
//             if(dig[i] && x >= i){
//                 dp[x] = min(dp[x],1 + dp[x-i]);
//             }
//         }
//     }

//     cout<<dp[n]<<endl;
// }

//Grid Paths
// void solve(){
//     int n;cin>>n;

//     int grid[n][n];
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j<n;j++){
//             char x;
//             cin>>x;

//             if(x == '.'){
//                 grid[i][j] = 1;
//             }else{
//                 grid[i][j] = 0;
//             }
//         }
//     }

//     vector<vector<int>> dp(n,vector<int>(n,0));
//     dp[n-1][n-1] = grid[n-1][n-1];

//     for(int i = n-1;i>=0;i--){
//         for(int j = n-1;j>=0;j--){
//             if(i == n-1 && j == n-1) continue;
//             if(grid[i][j]){
//                 int right = 0;
//                 int down = 0;
//                 if(j<n-1){
//                     right = dp[i][j+1];
//                 }
//                 if(i<n-1){
//                     down = dp[i+1][j];
//                 }
//                 dp[i][j] = (right + down)%MOD;
//             }
//         }
//     }

//     cout<<dp[0][0]<<endl;
// }

//Book Shop
// void solve(){
//     int n,x;
//     cin>>n>>x;

//     int a[n],c[n];
//     rep(i,0,n) cin>>c[i];
//     rep(i,0,n) cin>>a[i];

//     // vector<vector<int>> dp(n+1,vector<int>(x+1,0));
//     vector<int> prev(x+1,0);
//     vector<int> curr(x+1,0);

//     // for(int i = 0;i<=n;i++){
//     //     dp[i][0] = 0;
//     // }


//     // for(int sum = 0;sum<=x;sum++){
//     //     dp[0][sum] = 0;
//     // }

//     for(int i = 1;i<=n;i++){
//         for(int rem = 1;rem<=x;rem++){
//             if(rem>=c[i-1]){
//                 curr[rem] = max(curr[rem],max(a[i-1] + prev[rem-c[i-1]],prev[rem]));
//             }else{
//                 curr[rem] = max(curr[rem],prev[rem]);
//             }
//         }
//         prev = curr;
//     }

//     cout<<prev[x]<<endl;
// }

//Array Description
// void solve(){
//     int n,m;
//     cin>>n>>m;

//     int a[n];
//     rep(i,0,n) cin>>a[i];

//     // vvi dp(n+1,vi(m+1,0));
//     vll prev(m+1,0);

//     for(int i = 1;i<=m;i++){
//         if(a[0] == i || a[0] == 0){
//             prev[i] = 1;
//         }
//     }

//     for(int i = 2;i<=n;i++){
//         vector<ll> curr(m+1,0);
//         for(int k = 1;k<=m;k++){
//             //if last element of prefix of lenght i is k then the last element of prefix of length i-1 should be k-1,k or k+1.
//             //So we sum dp[i-1][k-1], dp[i-1][k] and dp[i-1][k+1];

//             if(a[i-1] == 0 || a[i-1] == k){
//                 for(int j = -1;j<=1;j++){
//                     if(k + j >= 1 && k+j<=m){
//                         curr[k] += prev[k+j];
//                         curr[k] %= MOD;
//                     }
//                 }
//             }
//         }

//         // for(int j = 1;j<=m;j++){
//         //     cout<<curr[j]<<" ";
//         // }
//         // cout<<endl;
//         prev = curr;
//     }

//     ll ans = 0;
//     for(int i = 1;i<=m;i++){
//         ans = (ans + prev[i])%MOD;
//     };

//     cout<<ans<<endl;
// }

//Counting towers
// void solve(){
//     int n;
//     cin>>n;

//     int prev[2] = {0};
//     int curr[2] = {0};
    
//     /*
//     dp[i][0] = no. of ways to fill the towers from ith row to n-1th row when a horizontal block is trying to extend.
//              = 1. close the block and start a new horizontal block.  dp[i+1][0].
//                2. close the block and start two new vertical blocks. dp[i+1][1].
//                3. don't close just extend the horizontal block.      dp[i+1][0].
//     dp[i][1] = no. of ways to fill the towers from ith row to n-1th row when two vertical blocks are trying to extend.
//              = 1. close both start two new vertical.                                 dp[i+1][1].
//                2. close both start new horizontal.                                   dp[i+1][0].
//                3. close left start new vertical on left and extend right.            dp[i+1][1].
//                4. close right start new right vertical and extend left.              dp[i+1][1].
//                5. extend both.                                                       dp[i+1][1].

//     so, dp[i][0] = 2*dp[i+1][0] + dp[i+1][1].
//         dp[i][1] = 4*dp[i+1][1] + dp[i+1][0].

//     base case :-
//     reaching the last index we will close everything.
//     dp[n][0] = 1, dp[n][1] = 1;
//     */

//     prev[0] = 1; prev[1] = 1;

//     for(int i = n-1;i>=1;i--){
//         curr[0] = (2LL * prev[0] + 1LL * prev[1]) % MOD;
//         curr[1] = (4LL * prev[1] + 1LL * prev[0]) % MOD;

//         prev[0] = curr[0];
//         prev[1] = curr[1];
//     }

//     cout<<(prev[0] + prev[1])%MOD<<endl;
// }

//Edit Distance
// void solve(){
//     string s,t;
//     cin>>s>>t;

//     int n = s.length(),m = t.length();

//     vvi dp(n+1,vi(m+1,1e9));

//     // function<int(int i,int j)> memo = [&](int i, int j)->int{
//     //     if(i == -1 && j == -1) return 0;

//     //     if(i == -1) return j+1;

//     //     if(j == -1) return i+1;

//     //     if(dp[i][j] != -1) return dp[i][j];

//     //     int ans = 1e9;
//     //     if(s[i] == t[j]){
//     //         ans = min(ans,memo(i-1,j-1));
//     //     }else{
//     //         int c1 = 1 + memo(i-1,j);
//     //         int c2 = 1 + memo(i,j-1);
//     //         int c3 = 1 + memo(i-1,j-1);
//     //         ans = min(ans,min(c1,min(c2,c3)));
//     //     }

//     //     return dp[i][j] = ans;
//     // };
//     // cout<<memo(n-1,m-1)<<endl;

//     dp[0][0] = 0;
//     for(int i = 1;i<=n;i++){
//         dp[i][0] = i;
//     }
//     for(int j = 1;j<=m;j++){
//         dp[0][j] = j;
//     }

//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             if(s[i-1] == t[j-1]){
//                 dp[i][j] = dp[i-1][j-1];
//             }else{
//                 int c1 = 1 + dp[i-1][j];
//                 int c2 = 1 + dp[i][j-1];
//                 int c3 = 1 + dp[i-1][j-1];

//                 dp[i][j] = min(dp[i][j],min(c1,min(c2,c3)));
//             }
//         }
//     }

//     cout<<dp[n][m]<<endl;
// }

//Rectangle cutting
// void solve(){
//     int n,m;cin>>n>>m;

//     vvi dp(n+1,vi(m+1,1e9));
//     // function<int(int n,int m)> memo = [&](int n,int m)->int{
//     //     if(n == m) return 0;
//     //     if(n == 1) return m-1;
//     //     if(m == 1) return n-1;

//     //     int ans = 1e9;

//     //     for(int i = 1;i<=n-1;i++){
//     //         ans = min(ans,1 + memo(i,m) + memo(n-i,m));
//     //     }
//     //     for(int j = 1;j<=m-1;j++){
//     //         ans = min(ans,1 + memo(n,j) + memo(n,m-j));
//     //     }

//     //     return ans;
//     // };

//     // cout<<memo(n,m)<<endl;

//     for(int i = 1;i<=min(n,m);i++){
//         dp[i][i] = 0;
//     }
//     for(int i = 1;i<=n;i++){
//         dp[i][1] = i-1;
//     }
//     for(int j = 1;j<=m;j++){
//         dp[1][j] = j-1;
//     }

//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             for(int k = 1;k<=i-1;k++){
//                 dp[i][j] = min(dp[i][j],1 + dp[k][j] + dp[i-k][j]); 
//             }
//             for(int k = 1;k<=j-1;k++){
//                 dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
//             }
//         }
//     }

//     cout<<dp[n][m]<<endl;
// }

//Money sums
// int dp[101][100001];
// void solve(){
//     int n;
//     cin>>n;

//     int a[n];
//     rep(i,0,n){
//         cin>>a[i];
//     }

//     set<int> st;

//     function<void(int i,int sum)> memo = [&](int i,int sum)->void{
//         if(sum != 0)
//             st.insert(sum);
//         if(i < 0) return;

//         if(dp[i][sum] == 1) return;

//         memo(i-1,sum + a[i]);
//         memo(i-1,sum);

//         dp[i][sum] =1;
//     };
//     memo(n-1,0);

//     cout<<st.size()<<endl;
//     for(auto i:st){
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }

//Removal Game
// ll dp[5001][5001][2];
// void solve(){
//     int n; cin>>n;

//     int a[n];
//     rep(i,0,n){
//         cin>>a[i];
//     }

//     // function<ll(int i,int j,bool turn)> memo = [&](int i,int j,bool turn)->ll{
//     //     if(i == j){
//     //         if(turn) return a[i];
//     //         return 0;
//     //     }
//     //     if(j - i == 1){
//     //         if(turn) return max(a[i],a[j]);
//     //         return min(a[i],a[j]);
//     //     }
//     //     if(dp[i][j][turn] != -1) return dp[i][j][turn];
        
//     //     ll ans;

//     //     if(turn){
//     //         ans = max(1LL * a[i] + memo(i+1,j,0),1LL * a[j] + memo(i,j-1,0));
//     //     }else{
//     //         ans = min(memo(i+1,j,1),memo(i,j-1,1));
//     //     }

//     //     return dp[i][j][turn] = ans;
//     // };

//     // memset(dp,-1,sizeof(dp));
//     // cout<<memo(0,n-1,1)<<endl;

//     memset(dp,0,sizeof(dp));
//     for(int i = 0;i<n;i++){
//         dp[i][i][1] = a[i];
//         dp[i][i][0] = 0;

//         if(i<n-1){
//             dp[i][i+1][1] = max(a[i],a[i+1]);
//             dp[i][i+1][0] = min(a[i],a[i+1]);
//         }
//     }

//     for(int i = n-1;i>=0;i--){
//         for(int j = i+2;j<n;j++){
//             for(short turn = 1;turn>=0;turn--){
//                 if(turn){
//                     dp[i][j][turn] = max(1LL * a[i] + dp[i+1][j][0], 1LL * a[j] + dp[i][j-1][0]);
//                 }else{
//                     dp[i][j][turn] = min(dp[i+1][j][1],dp[i][j-1][1]);
//                 }
//             }
//         }
//     }

//     cout<<dp[0][n-1][1]<<endl;
// }

//Two sets II
// int dp[501][125251];
// void solve(){
//     int n;
//     cin>>n;

//     int x = (n * (n+1))/2;

//     if(x&1){
//         cout<<0<<endl;
//         return;
//     }

//     x /= 2;
//     memset(dp,0,sizeof(dp));
//     for(int i = 0;i<=n;i++){
//         dp[i][0] = 1;
//         dp[i][i] = 1;
//     }

//     for(int i = 1;i<=n;i++){
//         for(int sum = 1;sum<=x;sum++){
//             int notTake = dp[i-1][sum];
//             int take = 0;
//             if(sum >= i){
//                 take = dp[i-1][sum-i];
//             }
//             dp[i][sum] = (take + notTake)%MOD;
//         }
//     }

//     cout<<dp[n-1][x]%MOD<<endl;
// }

//LIS
// void solve(){
//     int n;cin>>n;

//     int a[n];
//     rep(i,0,n){
//         cin>>a[i];
//     }

//     // O(n^2)
//     // vi pre(n+1,0);
//     // vi cur(n+1,0);
//     // for(int i = 1;i<=n;i++){
//     //     for(int prev = n;prev>=i;prev--){
//     //         int notTake = pre[prev];
//     //         int take = 0;
//     //         if(prev == n || a[i-1] < a[prev]){
//     //             take = 1 + pre[i-1];
//     //         }

//     //         cur[prev] = max(take,notTake);
//     //     }
//     //     pre = cur;
//     // }

//     // cout<<pre[n]<<endl;

//     vector<int> st;

//     int ans = 0;
//     for(int i = 0;i<n;i++){
//         if(st.size() == 0){
//             st.push_back(a[i]);
//         }else{
//             if(st.back() >= a[i]){
//                 int idx = lower_bound(st.begin(),st.end(),a[i]) - st.begin();
//                 st[idx] = a[i];
//             }else{
//                 st.push_back(a[i]);
//             }
//         }
//         ans = max(ans,st.size());
//     }

//     cout<<ans<<endl;
// }

//Projects
// ll dp[200001];
// void solve(){
//     int n;
//     cin>>n;

//     vector<pair<pair<int,int>,int>> a(n);
//     rep(i,0,n){
//         cin>>a[i].first.first;
//         cin>>a[i].first.second;
//         cin>>a[i].second;
//     }

//     sort(a.begin(),a.end());

//     function<int(int l,int r,int val)> findUpperBound = [&](int l,int r,int val)->int{
//         while(l<=r){
//             int mid = l + (r-l)/2;

//             int nextStart = a[mid].first.first;
//             int curEnd = val;

//             if(nextStart <= curEnd){
//                 l = mid+1;
//             }else{
//                 r = mid-1;
//             }
//         }

//         return l;
//     };

//     // function<ll(int i)> memo = [&](int i)->ll{
//     //     if(i >= n) return 0;
//     //     if(dp[i] != -1) return dp[i];

//     //     ll notTake = memo(i+1);

//     //     int nextIdx = findUpperBound(i+1,n-1,a[i].first.second);
//     //     ll take = a[i].second + memo(nextIdx);

//     //     return dp[i] = max(take,notTake);
//     // };
//     // memset(dp,-1,sizeof(dp));
//     // cout<<memo(0)<<endl;

//     memset(dp,0,sizeof(dp));
//     for(int i = n-1;i>=0;i--){
//         ll notTake = dp[i+1];

//         int nextIdx = min(n,findUpperBound(i+1,n-1,a[i].first.second));
//         ll take = a[i].second + dp[nextIdx];

//         dp[i] = max(take,notTake);
//     }

//     cout<<dp[0]<<endl;   
// }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // fac[0] = 1;

    // for(int i = 1;i<=100;i++){
    //     fac[i] = (fac[i-1]*i)%MOD;
    //     fac[i] %= MOD;
    // }

    int t = 1;
    // cin>>t;

    // memset(dp,-1,sizeof(dp));
    while(t--){
        solve();
    }

    return 0;
}