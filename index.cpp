// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n, t;
//     cin>>n>>t;
//     string s;
//     cin>>s;

//     for(int sec=0; sec<t; sec++){
//         bool swapped=false;
//         for(int i=0;i+1<n;i++){
//             if(s[i]=='B'&&s[i+1]=='G'){
//                 swap(s[i],s[i+1]);
//                 i++; // skip next index, can't reuse this G again this second
//                 swapped=true;
//             }
//         }
//         if(!swapped) break;
//     }
//     cout<<s<<"\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n;
//     cin>>n;
//     int x,y,z;
//     cin>>x>>y>>z;
//     int withoutai=n/(x+y);
//     int withai=(z*x>=n? (z*x)/(x+10*y):(n-z*x)/(x+10*y));
//     cout<<min(withai,withoutai)<<"\n";
// }

// int main(){
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
// solve();
// return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int solve(int n,int a,int b){
//     if(n<0){
//         return INT_MAX;
//     }
//     if(n==0){
//         return 0;
//     }
//     int A=a+solve(n-1,a,b);
//     int B=b+solve(n-3,a,b);
//     return min(A,B);
// }
// // void solve(){
// //     int n;
// //     cin>>n;
// //     vector<int>a(n);
// //     for(int i=0;i<n;i++){
// //         cin>>a[i];
// //     }
// //     vector<int>pf(n+1,0);
// //     pf[0]=a[0];
// //     for(int i=1;i<n;i++){
// //         pf[i]=pf[i-1]+a[i];
// //     }
// //     int ans=INT_MAX;
// //     vector<int>res;
// //     for(int i=0;i<n;i++){
// //         ans=min(ans,pf[i]/(i+1));
// //         res.push_back(ans);
// //     }
// //     for(int x:res){
// //         cout<<x<<" ";
// //     }
// //     cout<<"\n";
// // }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // int t;
//     // cin>>t;
//     // while(t--){
//     int n=5;
//     int a=10,b=25;
//         cout<<solve(n,a,b)<<" ";
//     // }
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     long long n,a,b;
//     cin>>n>>a>>b;
//     b=min(b,3*a);
//     cout<<min((1ll*n/3)*b+(1ll*n%3)*a,(1ll*(n+2)/3)*b)<<"\n";
// }

// int main(){
//     ios::sync_with_stdio(false);
//     solve();
//     return 0;
// }
// #include<bits/stdc++.h>
// #define INT_MAX 2147483647
// using namespace std;

// int solve(int n,int a,int b){
//     if(n<0){
//         return INT_MAX;
//     }
//     if(n==0){
//         return 0;
//     }
//     int x=solve(n-1,a,b);
//     int y=solve(n-3,a,b);
//     int A=(x==INT_MAX? INT_MAX:a+x);
//     int B=(y==INT_MAX? INT_MAX:b+y);
//     return min(A,B);
// }

// int main(){
//     int n=5,a=10,b=25;
//     cout<<solve(n,a,b)<<"\n";
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     long long n;
//     cin>>n;
//     vector<long long>a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     long long mx=*max_element(a.begin(),a.end());
//     long long mn=*min_element(a.begin(),a.end());
//     if(mn==mx){
//         cout<<0<<"\n";
//         return;
//     }
//     long long d=mx-mn;
//     cout<<1LL*(d+1)/2<<"\n";

// }
// int main(){
//     ios::sync_with_stdio(false);
//     solve();
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n;
//     cin>>n;
//     vector<int>a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int ans=0;
//     for(int i=0;i<n;i++){
//         if(a[i]<=(i+1)){
//             ans++;
//         }
//     }
//     cout<<ans<<"\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     long long n;
//     cin>>n;
//     vector<long long>a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     long long mx=*max_element(a.begin(),a.end());
//     vector<long long>r;
//     for(int i=0;i<n;i++){
//         r.push_back(mx-a[i]);
//     }
//      mx=*max_element(r.begin(),r.end());
//     cout<<mx+1<<"\n";
// }

// int main(){
//     ios::sync_with_stdio(false);
//     int t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     long long a,b,x;
//     cin>>a>>b>>x;
//     long long mincost=LLONG_MAX;
//     long long divsofar=0;
//     while(a>0||b>0){
//         if(b>a){
//             swap(a,b);
//         }
//         a/=x;
//         divsofar++;
//         mincost=min(mincost,divsofar+abs(a-b));
//     }
//     cout<<mincost<<"\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
//     int t;
//     cin>>t;
//     // while(t--){
//         solve();
//     // }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     long long n;
//     cin>>n;
//     vector<long long>a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     long long k=0;
//     for(int i=0;i+1<n;i++){
//         k=max(k,a[i]-a[i+1]);
//     }
//     long long prev=a[0];
//     for(int i=0;i<n;i++){
//         if(a[i]>=prev){
//             prev=a[i];
//         }
//         else if(a[i]+k>=prev){
//             prev=a[i]+k;
//         }
//         else{
//             cout<<"NO"<<"\n";
//             return;
//         }
//     }
//     cout<<"YES"<<"\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
//     // int t;
//     // cin>>t;
//     // while(t--){
//         solve();
//     // }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     long long n;
//     cin>>n;
//     vector<long long>a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     long long ans=0;
//     for(int i=0;i<n;i++){
//         if(ans>a[i]){
//             ans+=a[i];
//         }
//         else{
//             ans=a[i];
//         }
//     }
//     cout<<ans<<"\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
//     // int t;
//     // cin>>t;
//     // while(t--){
//         solve();
//     // }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// int main() {
// 	ios_base::sync_with_stdio(false); cin.tie(0);

// 	int tc; cin >> tc;
// 	while(tc--) {
// 		int n; cin >> n;
// 		vector<int> a(n), b(n);
// 		for(auto &x : a) cin >> x;
// 		for(auto &x : b) cin >> x;

// 		ll ans = 0;
// 		for(int i = 0; i < n; i++) {
// 			int j = i;
// 			for(; j < n && a[j] > b[i]; j++);
// 			if(j == n) { ans = -1; break; }
// 			for(; j > i; j--) { swap(a[j], a[j-1]); ans++; }
// 		}

// 		cout << ans << "\n";
// 	}

// 	return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// // void solve(){
// //     int n;
// //     cin>>n;
// //     vector<int>a(n);
// //     vector<int>b(n);
// //     for(int i=0;i<n;i++){
// //         cin>>a[i];
// //     }
// //     for(int i=0;i<n;i++){
// //         cin>>b[i];
// //     }
// //     long long ans=0;
// //     for(int i=0;i<n;i++){
// //         int j=i;
// //         while(j<n&&a[j]>b[i]){
// //             j++;
// //         }
// //         if(j==n){
// //             ans=-1;
// //             break;
// //         }
// //         while(j>i){
// //             swap(a[j],a[j-1]);
// //             ans++;
// //             j--;
// //         }
// //     }
// //     cout<<ans<<"\n";
// // }
// int main(){
//     // ios::sync_with_stdio(false);
//     // int t;
//     // cin>>t;
//     // while(t--){
//     //     solve();
//     // }
//     vector<int>v={10,20,30,40,50,60,70};
//     int a=21;
//     int x=upper_bound(v.begin(),v.end(),a)-v.begin();
//     cout<<v[x]<<"\n";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int k;
//         cin>>k;
//         int a1,b1,a2,b2;
//         cin>>a1>>b1;
//         cin>>a2>>b2;
//         int diff=(a1+a2)-(b1+b2);
//         if(diff-k<0){
//             cout<<"YES";
//         }
//         else if(diff-k>0){
//             cout<<"NO";
//         }
//         else{
//             if((a1+a2)>(b1+b2)){
//                 cout<<"NO";
//             }
//             else{
//                 cout<<"YES";
//             }
//         }
//     }
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// vector<int>v,h;
// int solve(int i,int n,vector<int>&dp){
//     if(i==n){
//         return 0;
//     }
//     if(i==n-1){
//         return v[i];
//     }
//     int ch1=v[i]+solve(i+1,n,dp);
//     int ch2=h[i]+solve(i+2,n,dp);
//     return min(ch1,ch2);
// }

// int main(){
//     int n;
//     cin>>n;
//     string a;
//     cin>>a;
//     string b;
//     cin>>b;
//     vector<string>boards={a,b};
//     v.resize(n,0);
//     h.resize(n,0);
//     for(int i=0;i<a.size();i++){
//         v[i]=(a[i]!=b[i]);
//     }
//     for(int i=0;i+1<b.size();i++){
//         h[i]=(a[i]!=a[i+1])+(b[i]!=b[i+1]);
//     }
//     // int ans=solve(0,n);
//     // cout<<ans<<"\n";
//     vector<int>dp(n+2,0);
//     dp[n-1]=v[n-1];
//     for(int i=n-2;i>=0;i--){
//         dp[i]=min(v[i]+dp[i+1],h[i]+dp[i+2]);
//     }
//     cout<<dp[0]<<"\n";
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n;
//     cin>>n;
//     int x1,x2,k;
//     cin>>x1>>x2>>k;
//     int cw=(x2-x1+n)%n;
//     int dist=min(cw,n-cw);
//     cout<<dist+k<<"\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
//     // int t;
//     // cin>>t;
//     // while(t--){
//         solve();
//     // }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     // int t;
//     // cin>>t;
//     // while(t--){
//         int n,m,p,q;
//         cin>>n>>m>>p>>q;
//         if(n%p==0){
//             cout<<(n==(n/p)*q? "YES":"NO")<<"\n";
//         }
//         else{
//             cout<<"YES"<<"\n";
//         }
//     // }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     //  int t;
//     // cin>>t;
//     // while(t--){
//     int n;
//     cin>>n;
//     vector<int>a(n);
//     int c0=0,c1=0,c2=0;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//         if(a[i]==0){
//             c0++;
//         }
//         else if(a[i]==1){
//             c1++;
//         }
//         else{
//             c2++;
//         }
//     }
//     if(c0==n){
//         cout<<c0<<'\n';
//         return;
//     }
//     int ans=c0;
//     int x=min(c1,c2);
//     ans+=x;
//     c1-=x;
//     c2-=x;
//     ans+=c1/3;
//     ans+=c2/3;
//     cout<<ans<<"\n";
//     // }
// }
// int main(){
//     solve();
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// struct Card{
//     int id;
//     int cost;
// };
// void solve(){
//     int n,k,p,m;
//     cin>>n>>k>>p>>m;
//     vector<Card>deck;
//     for(int i=0;i<n;i++){
//         int cst;
//         cin>>cst;
//         deck.push_back({i,cst});
//     }
//     int winid=p-1;
//     int spent=0;
//     int ans=0;
//     while(true){
//     int winpos=-1;
//     for(int i=0;i<k;i++){
//         if(deck[i].id==winid){
//             winpos=i;
//             break;
//         }
//     }
//     if(winpos!=-1){
//         Card winner=deck[winpos];
//         deck.erase(deck.begin()+winpos);
//         deck.push_back(winner);
//         if(spent+winner.cost>m){
//             break;
//         }
//         spent+=winner.cost;
//         ans++;
//     }
//     else{
//         int mn=INT_MAX,idx=0;
//         for(int i=0;i<k;i++){
//             if(deck[i].cost<mn){
//                 mn=deck[i].cost;
//                 idx=i;
//             }
//         }
//         if(spent+mn>m){
//             break;
//         }
//         spent+=mn;
//         Card curr=deck[idx];
//         deck.erase(deck.begin()+idx);
//         deck.push_back(curr);
//     }
//     }
//     cout<<ans<<"\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
//     // int t;
//     // cin>>t;
//     // while(t--){
//         solve();
//     // }
//     return 0;
// }


// int main(){
//     ios::sync_with_stdio(false);
//     // int t;
//     // cin>>t;
//     // while(t--){
//         int n,m;
//         cin>>n>>m;
//         vector<long long>a(n+1);
//         for(int i=1;i<=n;i++){
//             cin>>a[i];
//         }
//         int co=0,ce=0;
//         for(int i=0;i<m;i++){
//             int xi;
//             cin>>xi;
//             if(xi%2==0){
//                 ce++;
//             }
//             else{
//                 co++;
//             }
//         }
//         long long total=0;
//         vector<long long>even,odd;
//         for(int i=1;i<=n;i++){
//             if(a[i]%2==0){
//                 even.push_back(a[i]);
//                 total+=a[i];
//             }
//             else{
//                 odd.push_back(a[i]);
//                 total+=a[i];
//             }
//         }
//         sort(even.rbegin(),even.rend());
//         sort(odd.rbegin(),odd.rend());
//         long long markedcnt=0;
//         auto marked=[&](vector<long long>&grp,int cnt){
//             if(cnt==0||grp.empty()){
//                 return 0;
//             }
//             markedcnt+=grp[0];
//             for(int i=1;i<cnt&&i<(int)grp.size()&&grp[i]>0;i++){
//                 markedcnt+=grp[i];
//             }
//         };
//         marked(even,ce);
//         marked(odd,co);
//         cout<<total-markedcnt<<"\n";
//     // }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//         int n,k;
//         cin>>n>>k;
//         string s;
//         cin>>s;
//         for(int i=0;i<n;i++){
//             if(s[i]=='1'){
//                 if(i+k>=n){
//                     cout<<"NO"<<"\n";
//                     return;
//                 }
//                 s[i]='0';
//                 s[i+k]='0';
//             }
//         }
//         cout<<"YES"<<"\n";
// }

// int main(){
//     ios::sync_with_stdio(false);
//     int t;
//     cin>>t;
//     while(t--){
//     solve();
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
 
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int t;
cin >> t;
 
while (t--) {
    int n;
    cin>>n;
    vector<int>p(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    string s;
    cin>>s;
    vector<bool>vis(n+1,0);
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        vector<int>cycle;
        int curr=i;
        while(!vis[curr]){
            vis[curr]=1;
            cycle.push_back(curr);
            curr=p[curr];
        }
        int cnt=0;
        for(int node:cycle){
            if(s[node-1]=='0'){
                cnt++;
            }
        }
        for(int node:cycle){
            ans[node]=cnt;
        }
    }
   for(int i=1;i<=n;i++){
       cout<<ans[i]<<" ";
   }
   cout<<"\n";
}
return 0;
}



















