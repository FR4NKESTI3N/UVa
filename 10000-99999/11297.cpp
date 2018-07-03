#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct Node{
    pii M, m;
    Node(pii a = {-1, -1}, pii b = {-1, -1}) : M(a), m(b){}

    bool operator==(Node &a){
        return M == a.M && m == a.m;
    }
}neg;

class SegmentTree2D{
    int n;
    vvi A;
    vector<Node> st;

    int child1(int p){return 4 * p - 2;}
    int child2(int p){return 4 * p - 1;}
    int child3(int p){return 4 * p;}
    int child4(int p){return 4 * p + 1;}

    Node maxNode(Node a, Node b){
        Node res;
        if(a == neg)
            return b;
        if(b == neg)
            return a;
        res.M = A[a.M.first][a.M.second] > A[b.M.first][b.M.second] ? a.M : b.M;
        res.m = A[a.m.first][a.m.second] > A[b.m.first][b.m.second] ? b.m : a.m;
        return res;
    }

    void build(int p, int X1, int Y1, int X2, int Y2){
        if(X1 > X2 || Y1 > Y2)
            return;
        if(X1 == X2 && Y1 == Y2){
            st[p] = Node({X1, Y1}, {X1, Y1});
            return;
        }
        build(child1(p), X1, Y1, (X1 + X2) / 2, (Y1 + Y2) / 2);
        build(child2(p), ((X1 + X2) / 2) + 1, Y1, X2, (Y1 + Y2) / 2);
        build(child3(p), X1, ((Y1 + Y2) / 2) + 1, (X1 + X2) / 2, Y2);
        build(child4(p), ((X1 + X2) / 2) + 1, ((Y1 + Y2) / 2) + 1, X2, Y2);
        st[p] = maxNode(st[p], st[child1(p)]);
        st[p] = maxNode(st[p], st[child2(p)]);
        st[p] = maxNode(st[p], st[child3(p)]);
        st[p] = maxNode(st[p], st[child4(p)]);
    }

    Node query(int p, int X1, int Y1, int X2, int Y2, int x1, int y1, int x2, int y2){
        if(X1 > x2 || Y1 > y2 || X2 < x1 || Y2 < y1 || X1 > X2 || Y1 > Y2)
            return neg;
        if(X1 >= x1 && Y1 >= y1 && X2 <= x2 && Y2 <= y2)
            return st[p];
        if(X1 == X2 && Y1 == Y2)
            return st[p];

        Node res = query(child1(p), X1, Y1, (X1 + X2) / 2, (Y1 + Y2) / 2, x1, y1, x2, y2);
        res = maxNode(res, query(child2(p), ((X1 + X2) / 2) + 1, Y1, X2, (Y1 + Y2) / 2, x1, y1, x2, y2));
        res = maxNode(res, query(child3(p), X1, ((Y1 + Y2) / 2) + 1, (X1 + X2) / 2, Y2, x1, y1, x2, y2));
        res = maxNode(res, query(child4(p), ((X1 + X2) / 2) + 1, ((Y1 + Y2) / 2) + 1, X2, Y2, x1, y1, x2, y2));
        return res;
    }

    void update(int p, int X1 ,int Y1, int X2, int Y2, int x, int y, int val){
        if(X1 == X2 && Y1 == Y2){
            A[X1][Y1] = val;
            return;
        }
        int mid_X = (X1 + X2) / 2;
        int mid_Y = (Y1 + Y2) / 2;
        if(x <= mid_X){
            if(y <= mid_Y){
                update(child1(p), X1, Y1, mid_X, mid_Y, x, y, val);
            }
            else
                update(child3(p), X1, ((Y1 + Y2) / 2) + 1, (X1 + X2) / 2, Y2, x, y, val);
        }
        else{
            if(y <= mid_Y)
                update(child2(p), ((X1 + X2) / 2) + 1, Y1, X2, (Y1 + Y2) / 2, x, y, val);
            else
                update(child4(p), ((X1 + X2) / 2) + 1, ((Y1 + Y2) / 2) + 1, X2, Y2, x, y, val);
        }
        st[p] = maxNode(st[p], st[child1(p)]);
        st[p] = maxNode(st[p], st[child2(p)]);
        st[p] = maxNode(st[p], st[child3(p)]);
        st[p] = maxNode(st[p], st[child4(p)]);
    }
public:
    SegmentTree2D(vvi mat){
        A = mat;
        n = A.size();
        st.assign(10 * n * n, neg);
        build(1, 0, 0, n - 1, n - 1);
    }

    Node query(int x1, int y1, int x2, int y2){
        return query(1, 0, 0, n - 1, n - 1, x1, y1, x2, y2);
    }

    void update(int x, int y, int val){
        update(1, 0, 0, n - 1, n - 1, x, y, val);
    }

    vvi matrix(){
        return A;
    }
};

int main(){
    int n, q;
    cin >> n;
    vector<vector<int>> mat(n, vector<int> (n, 0));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> mat[i][j];
    SegmentTree2D st(mat);
    cin >> q;
    char c;
    int e, f, g, h;
    while(q--){
        cin >> c;
        if(c == 'q'){
            cin >> e >> f >> g >> h;
            Node p = st.query(e - 1, f - 1, g - 1, h - 1);
            cout << st.matrix()[p.M.first][p.M.second] << ' ' << st.matrix()[p.m.first][p.m.second] << '\n';
        }
        else{
            cin >> e >> f >> g;
            st.update(e - 1, f - 1, g);
        }
    }
    return 0;
}
