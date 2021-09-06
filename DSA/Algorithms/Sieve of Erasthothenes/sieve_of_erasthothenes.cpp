#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void prime_sieve(vector<bool>& is_prime)
{
    ll n = is_prime.size() - 1;
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (is_prime[i] && i * i <= n)
        {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
    ll n {};
    cout << "Enter the value of n: ";
    cin >> n;

    vector<bool> is_prime(n + 1, true);
    prime_sieve(is_prime);

    cout << "Prime numbers from 1 to " << n << ":\n";
    for (long i = 1; i <= n; i++)
        if (is_prime[i]) cout << i << " ";
    cout << "\n";

    return 0;
}
