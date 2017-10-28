#include <bits/stdc++.h>

using namespace std;

#define LSB(x) (x & -x)

int bit[10001], n;

int pre_sum(int index) {
	int ans = 0;
	for (; index != 0; index -= LSB(index))
		ans += bit[index];
	return ans;	
}

int sum_q(int x, int y) {
	return pre_sum(y) - pre_sum(x - 1);
}

void update(int i, int val) {
	int increment = val - sum_q(i, i - 1);
	for (; i <= n; i += LSB(i))
		bit[i] += increment;
}

int main() {
	ios::sync_with_stdio(false);
	memset(bit, 0, sizeof bit);
	
	cin>>n;
	for (int i = 1, temp; i <= n && cin>>temp; i++)
		update(i, temp);
	int q;
	cin>>q;
	while (q--) {
		int l, r;
		cin>>l>>r;
		cout<<sum_q(l, r)<<endl;
	}
	return 0;
}