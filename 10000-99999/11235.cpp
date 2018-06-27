#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct NodeData{
    int left, right, mid;
    NodeData(){
        left = -1, right = -1, mid = -1;
    }
    void assign(int l, int m, int r){
        left = l, mid = m, right = r;
    }

    bool operator==(NodeData &r){
        return left == r.left && right == r.right && mid == r.mid;
    }
}nullData;

class SegmentTree{
    int n;
    vector<int> count, start;
    vector<NodeData> st;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1) + 1;}

    void build(int p, int L, int R){
        if(L == R)
            st[p].assign(start[L], -1, start[L]);
        else{
            build(left(p), L, (L + R) >> 1);
            build(right(p), ((L + R) >> 1) + 1, R);
            st[p].assign(st[left(p)].left, -1, st[right(p)].right);
            if(st[left(p)].mid == -1)
                st[p].mid = st[right(p)].mid;
            else if(st[right(p)].mid == -1)
                st[p].mid = st[left(p)].mid;
            else
                st[p].mid = (count[st[left(p)].mid] < count[st[right(p)].mid] ? st[right(p)].mid : st[left(p)].mid);
            if(st[left(p)].right == st[right(p)].left){
                int tmp_mid = st[left(p)].right;
                if(((st[p].mid == - 1) || (count[st[p].mid] < count[tmp_mid])) && tmp_mid >= L && tmp_mid + count[tmp_mid] - 1 <= R)
                    st[p].mid = tmp_mid;
            }
        }
    }

    NodeData query(int p, int L, int R, int i, int j){
        NodeData P;
        if(i > R || j < L)
            return nullData;
        if(L >= i && R <= j)
            return st[p];
        NodeData P1 = query(left(p), L, (L + R) >> 1, i, j);
        NodeData P2 = query(right(p), ((L + R) >> 1) + 1, R, i, j);
        if(P1 == nullData)
            return P2;
        if(P2 == nullData)
            return P1;
        if(P1.mid == -1)
            P.mid = P2.mid;
        else if(P2.mid == -1)
            P.mid = P1.mid;
        else
            P.mid = (count[P1.mid] < count[P2.mid]) ? P2.mid : P1.mid;
        if(P1.right == P2.left){
            int tmp_mid = P1.right;
            if((P.mid == -1 || count[P.mid] < count[tmp_mid]) && tmp_mid >= i && tmp_mid + count[tmp_mid] - 1 <= j)
                P.mid = tmp_mid;
        }
        P.left = P1.left, P.right = P2.right;
        return P;
    }
public:
    SegmentTree(vector<int> cnt, vector<int> strt){
        n = cnt.size();
        count = cnt, start = strt;
        st.assign(4*n, NodeData());
        build(1, 0, n - 1);
    }
    int query(int i, int j){
        NodeData p = query(1, 0, n - 1, i, j);
        if(p == nullData)
            return -1;
        int m = count[p.mid];
        int l = count[p.left] + min(p.left - i, 0) + min(j - (p.left + count[p.left] - 1), 0);
        int r = count[p.right] + min(p.right - i, 0) + min(j - (p.right + count[p.right] - 1), 0);
        return max(m, max(l, r));
    }
};

int main(){
    int n, q, l, r;
    while(true){
        cin >> n;
        if(n == 0)
            break;
        cin >> q;
        vector<int> ar(n), count(n), start(n);
        for(int i = 0; i < n; ++i){
            cin >> ar[i];
            ar[i] += 200000;
        }
        int i = 0, j, tmp;
        while(i < n){
            j = i + 1;
            while(ar[j] == ar[i])
                ++j;
            tmp = j - i;
            for(int a0 = i; a0 < j; ++a0){
                count[a0] = tmp;
                start[a0] = i;
            }
            i = j;
        }
        SegmentTree st(count, start);
        for(int i = 0; i < q; ++i){
            cin >> l >> r;
            cout << st.query(l - 1, r - 1) << '\n';
        }
    }
    return 0;
}
