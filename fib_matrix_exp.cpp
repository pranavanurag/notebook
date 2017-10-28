#include <bits/stdc++.h>

using namespace std;

#define mod ((long long)1e9 + 7)

map <long long, long long> memo;

long long fib_mod(long long n) {
	if (memo.count(n) > 0)
		return memo[n];

	if (n%2 == 0)
		memo[n] = ((((2*fib_mod(n/2 - 1))%mod + fib_mod(n/2))%mod) * fib_mod(n/2))%mod;
	else
		memo[n] = ((fib_mod((n + 1)/2)*fib_mod((n + 1)/2))%mod + (fib_mod((n - 1)/2)*fib_mod((n - 1)/2)%mod))%mod;

	return memo[n];
}

int main()
{
	ios::sync_with_stdio(false);
	memo[0] = 0, memo[1] = 1;
	for (int i = 0; i <= 100; i++)
		cout<<"i = "<<i<<": "<<fib_mod(i)<<endl;
	return 0;
}