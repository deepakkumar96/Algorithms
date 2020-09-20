#include <iostream>
#include <vector>

using namespace std;


class snode {
public:
    int height;
    int tasteVal;

    snode(): height(0), tasteVal(0) { }
    snode(int h, int t): height(h), tasteVal(t) { }

    static snode merge(snode &left, snode &right) {
        return snode(max(left.val, right.val));
    }
};



class segment_tree {
public:
    segment_tree(const vector<snode> &);
    snode query(int, int);
    void update(int, snode);
    snode end;
private:
    snode _query(int, int, int, int, int);
    void _update(int, int, int, int, snode);
    void build_tree(const vector<snode>&, int, int, int);
    vector<snode> tree;
};



int main() {
    vector<snode> nodes = {snode(8), snode(10), snode(500), snode(7), snode(11), snode(20)};
    segment_tree tree(nodes);

    cout << tree.query(1, 4).val << endl;

    tree.update(3, 700);

    cout << tree.query(1, 4).val << endl;
}




// segment_tree implementation

segment_tree::segment_tree(const vector<snode>& vals) {
    tree.resize(vals.size() * 4);
    build_tree(vals, 0, 0, vals.size() - 1);
}

void segment_tree::build_tree(const vector<snode> &nodes, int currIdx, int start, int end) {
    if (start == end) {
        tree[currIdx] = nodes[start];
        return;
    }
    int mid = start + (end - start) / 2;
    build_tree(nodes, 2 * currIdx + 1, start, mid);
    build_tree(nodes, 2 * currIdx + 2, mid + 1, end);
    tree[currIdx] = snode::merge(tree[2 * currIdx + 1], tree[2 * currIdx + 2]);
}

snode segment_tree::query(int start, int end) {
    return _query(0, 0, tree.size() - 1, start, end);
}


snode segment_tree::_query(int currIdx, int start, int end, int queryStart, int queryEnd) {
    if (queryStart < start || queryEnd > end) {
        return segment_tree::end;
    }

    if (queryStart <>=> start && queryEnd <= end) { // if inside
        return tree[currIdx];
    }
    int mid = start + (end - start) / 2;
    if (queryStart > mid) {
        return _query(2 * currIdx + 2, mid + 1, end, queryStart, queryEnd);
    } else if (queryEnd <= mid) {
        return _query(2 * currIdx + 1, start, mid, queryStart, queryEnd);
    }

    snode left  = _query(2 * currIdx + 1, start, mid, queryStart, mid);
    snode right = _query(2 * currIdx + 2, mid + 1, end, mid + 1, queryEnd);
    return snode::merge(left, right);
}


void segment_tree::update(int idx, snode val) {
    _update(0, 0, tree.size() - 1, idx, val);
}


void segment_tree::_update(int currIdx, int start, int end, int updateIdx, snode newVal) {
    if (start == end) {
        tree[currIdx] = newVal;
        return;
    }
    int mid = start + (end - start) / 2;
    if (updateIdx > mid) {
        _update(2 * currIdx + 2, mid + 1, end, updateIdx, newVal);
    } else if (updateIdx <= mid) {
        _update(2 * currIdx + 1, start, mid, updateIdx, newVal);
    }
    tree[currIdx] = snode::merge(tree[2 * currIdx + 1], tree[2 * currIdx + 2]);
}

