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

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1) return -1;
    else
    {

        // m is added to handle negative x
        ll res = (x % m + m) % m;
        return res;
    }
}

void decrypt(string C, ll key1, ll key2)
{
    ll n = C.size();

    string P = "";

    forr(i, 0, n) {
        P += 'a' + ((((C[i] - 'A') - key2) + 26) * modInverse(key1, 26)) % 26;
    }

    cout << P << endl;
}

void encrypt(string P, ll key1, int key2)
{
    ll n = P.size();

    string C = "";

    forr(i, 0, n) {
        C += 'A' + ((P[i] - 'a') * key1 + key2) % 26;
    }

    cout << C << endl;

    decrypt(C, key1, key2);
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

        ll key1, key2;

        cin >> key1 >> key2;

        encrypt(s, key1, key2);


    }
    return 0;
}
