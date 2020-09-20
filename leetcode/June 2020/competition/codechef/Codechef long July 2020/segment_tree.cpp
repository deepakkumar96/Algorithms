#include <vector>
#include <iostream>

using namespace std;


typedef struct node{
	int val;
	node(int v): val(v) { }
	void split(node& l, node& r){}
	void merge(node& a, node& b)
	{
		val = min( a.val, b.val );
	}
} node;

node identity;

node range_query(vector<node> &tree, int root, int left_most_leaf, int right_most_leaf, int u, int v)
{
	//query the interval [u,v), ie, {x:u<=x<v}
	//the interval [left_most_leaf,right_most_leaf) is 
	//the set of all leaves descending from "root"
	if(u<=left_most_leaf && right_most_leaf<=v)
		return tree[root];
	int mid = (left_most_leaf+right_most_leaf)/2, 
		left_child = root*2, 
		right_child = left_child+1;
	tree[root].split(tree[left_child], tree[right_child]);
	node l=identity, r=identity;
	//identity is an element such that merge(x,identity) = merge(identity,x) = x for all x
	if(u < mid) l = range_query(tree, left_child, left_most_leaf, mid, u, v);
	if(v > mid) r = range_query(tree, right_child, mid, right_most_leaf, u, v);
	tree[root].merge(tree[left_child],tree[right_child]);
	node n;
	n.merge(l,r);
	return n;
}
void mergeup(vector<node> &tree, int postn)
{
	postn >>=1;
	while(postn>0)
	{
		tree[postn].merge(tree[postn*2],tree[postn*2+1]);
		postn >>=1;
	}
}
void update(vector<node> &tree, int pos, node new_val)
{
	pos+=(1<<n);
	tree[pos]=new_val;
	mergeup(tree, pos);
}


int main() {

    vector<node> nums = {node(1), node(20)};
    int n = nums.size();
    cout << range_query(nums, 0, 0, n, 0, 0, n) << endl;

    return 0;
}