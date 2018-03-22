#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int spf[N];

void pre() {
	for (int i = 2; i < N; i++)
		spf[i] = i;
	for (int i = 2; i*i < N; i++)
		if (spf[i] == i)
			for (int j = i*i; j < N; j += i)
				spf[j] = i;
}

int main() {
	ios::sync_with_stdio(0);

	pre();
	return 0;
}