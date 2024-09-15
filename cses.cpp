#include<bits/stdc++.h>

// #define int long long
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
void solve(){
    int n;cin>>n;

    // for(int i = 1;i<=9;i++) cout<<dig[i]<<" ";

    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    for(int x = 1;x<=n;x++){
        int dig[10] = {0};
        int p = 1;
        while(x/p){
            dig[(x/p)%10] = 1;
            p *= 10;
        }
        for(int i = 1;i<=9;i++){
            if(dig[i] && x >= i){
                dp[x] = min(dp[x],1 + dp[x-i]);
            }
        }
    }

    cout<<dp[n]<<endl;
}

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

    while(t--){
        solve();
    }

    return 0;
}