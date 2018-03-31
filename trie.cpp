#include <bits/stdc++.h>

using namespace std;

struct node {
	char c;
	map <char, node*> m;
};

void add(node* curr, string word, int idx) {
	if (curr == NULL || idx == word.size())
		return;

	char x = word[idx];
	if (!curr->m.count(x)) {
		node* next = new node;
		next->c = x;
		curr->m[x] = next;
	}

	add(curr->m[x], word, idx + 1);
}

void show(node* curr) {
	if (curr == NULL)
		return;

	cout<<"curr->c: "<<curr->c<<", children: ";
	for (pair <char, node*> p: curr->m)
		cout<<p.first<<" ";
	cout<<endl;

	for (pair <char, node*> p: curr->m)
		show(p.second);
}

vector <string> v;
int n;

int main() {
	ios::sync_with_stdio(0);

	cin>>n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin>>v[i];

	node* th = new node;
	th->c = '\0';

	for (auto s: v)
		add(th, s, 0);

	show(th);
	return 0;
}