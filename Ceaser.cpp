#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace  __gnu_pbds;
using namespace std;
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read(x) scanf("%d",&x)
#define llread(x) scanf("%lld",&x)
#define forr(i,x,n) for(ll i = x;i<n;i++)
#define fort(i,x,n) for(ll i = x;i>=n;i--)
#define ll long long
#define F first
#define S second
#define pb push_back
#define mod 1000000007
#define mxn 200005

void decrypt(string C, ll key)
{
    ll n = C.size();

    string P = "";

    forr(i, 0, n) {
        P += ('a' + (((C[i] - key) - 'A') + 26) % 26);
    }

    cout << P << endl;
}

void encrypt(string P, ll key)
{
    ll n = P.size();

    string C = "";

    forr(i, 0, n) {
        C += ('A' + ((P[i] + key) - 'a') % 26);
    }

    cout << C << endl;

    decrypt(C, key);
}



int main()
{
    faster_io

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t = 1, n, p, q, P, C;

    // cin >> t;


    while (t--) {
        string s;

        cin >> s;

        ll key;

        cin >> key;

        encrypt(s, key);




    }
    return 0;
}
