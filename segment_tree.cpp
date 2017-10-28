#include <bits/stdc++.h>

using namespace std;

const int N = 312345;

int tr[4*N];

void update(int i, int tx1, int tx2, int x) {
	if (tx1 > x || tx2 < x || tx1 > tx2)
		return;

	if (tx1 == tx2)
		tr[i] = 1;
	else {
		int txm = (tx1 + tx2)/2;
		update(2*i, tx1, txm, x);
		update(2*i + 1, txm + 1, tx2, x);
		tr[i] = tr[2*i] + tr[2*i + 1];
	}
}

int query(int i, int tx1, int tx2, int x1, int x2) {
	if (tx1 > tx2 || x1 > x2 || tx1 > x2 || tx2 < x1)
		return 0;

	if (tx1 >= x1 && tx2 <= x2)
		return tr[i];

	int txm = (tx1 + tx2)/2;
	return query(2*i, tx1, txm, x1, x2) + query(2*i + 1, txm + 1, tx2, x1, x2);
}


/////////////////////////////////////////////////////////////////////////////////

struct Node
{
	//define Value(s) and Lazy
	int Value, Lazy;
	Node(int x = 0, int y = 0) {Value = x; Lazy = y;}
};

Node SegTree[100001];

void PropogateLazy(int i, int STx1, int STx2)
{
	//Propgate laziness
}

void Merge(Node& Ans, Node& Left, Node& Right)
{
	//Merge operation
}

void Build(int i, int STx1, int STx2)
{
	if (STx1 > STx2)
		return;

	if (STx1 == STx2)
	{
		//Set leaf node
		return;
	}

	int STxm = (STx1 + STx2)/2;
	Build(2*i, STx1, STxm);
	Build(2*i + 1, STxm + 1, STx2);
	Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
}

void UpdateRange(int i, int STx1, int STx2, int x1, int x2, int V, int P)
{
	PropogateLazy(i, STx1, STx2);

	if (STx1 > STx2 || x1 > x2 || STx1 > x2 || STx2 < x1)
		return;

	if (STx1 >= x1 && STx2 <= x2)
	{
		//Update current node 'i' and propgate laziness down if (STx1 != STx2)
		return;
	}

	int STxm = (STx1 + STx2)/2;
	UpdateRange(2*i, STx1, STxm, x1, x2, V, P);
	UpdateRange(2*i + 1, STxm + 1, STx2, x1, x2, V, P);
	Merge(SegTree[i], SegTree[2*i], SegTree[2*i + 1]);
}

Node Query(int i, int STx1, int STx2, int x1, int x2)
{
	PropogateLazy(i, STx1, STx2);

	if (STx1 > STx2 || x1 > x2 || STx1 > x2 || STx2 < x1)
		return Node();

	if (STx1 >= x1 && STx2 <= x2)
		return SegTree[i];
	int STxm = (STx1 + STx2)/2;
	Node Ans, Left = Query(2*i, STx1, STxm, x1, x2), Right = Query(2*i + 1, STxm + 1, STx2, x1, x2);
	Merge(Ans, Left, Right);
	return Ans;
}

int main()
{
	ios::sync_with_stdio(false);
	
	return 0;
}