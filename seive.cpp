#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

bool is_prime[N];
vector <int> primes;

void seive() {
	for (int i = 2; i < N; i++)
		is_prime[i] = 1;

	for (int i = 2; i*i < N; i++)
		if (is_prime[i])
			for (int j = i*i; j < N; j += i)
				is_prime[j] = 0;

	for (int i = 2; i < N; i++)
		if (is_prime[i])
			primes.push_back(i);
}

int main()
{
	ios::sync_with_stdio(false);
	seive();
	for (int p: primes)
		cout<<p<<endl;
	return 0;
}