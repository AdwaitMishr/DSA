class SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> st;

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        st[p] = max(st[p << 1], st[p << 1 | 1]);
    }

    int qry(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return st[p];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        if (ql <= mid) {
            res = max(res, qry(p << 1, l, mid, ql, qr));
        }
        if (qr > mid) {
            res = max(res, qry(p << 1 | 1, mid + 1, r, ql, qr));
        }
        return res;
    }

public:
    SegmentTree(vector<int>& arr) : a(arr) {
        n = arr.size();
        st.resize(n << 2, 0);
        build(1, 0, n - 1);
    }
    int get(int l, int r) {
        if (l > r) {
            return 0;
        }
        return qry(1, 0, n - 1, l, r);
    }
};
class Solution {
private:
    void getBlks(string& s, vector<int>& zb, vector<int>& bl, vector<int>& br) {
        int n = s.length();
        int i = 0;
        while (i < n) {
            int st = i;
            while (i < n && s[i] == s[st]) {
                i++;
            }
            if (s[st] == '0') {
                zb.push_back(i - st);
                bl.push_back(st);
                br.push_back(i - 1);
            }
        }
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& qrys) {
        int c1 = count(s.begin(), s.end(), '1');
        vector<int> zb;
        vector<int> bl;
        vector<int> br;
        getBlks(s, zb, bl, br);
        int m = zb.size();
        if (m < 2) {
            return vector<int>(qrys.size(), c1);
        }
        vector<int> ts(m - 1);
        for (int i = 0; i < m - 1; i++) {
            ts[i] = zb[i] + zb[i + 1];
        }
        SegmentTree st(ts);
        vector<int> ans;
        for (auto& q : qrys) {
            int l = q[0];
            int r = q[1];
            int i = lower_bound(br.begin(), br.end(), l) - br.begin();
            int j = upper_bound(bl.begin(), bl.end(), r) - bl.begin() - 1;
            if (i > m - 1 || j < 0 || i >= j) {
                ans.push_back(c1);
                continue;
            }
            int fl = br[i] - max(bl[i], l) + 1;
            int ll = min(br[j], r) - bl[j] + 1;
            if (i + 1 == j) {
                int bg = fl + ll;
                ans.push_back(c1 + bg);
                continue;
            }
            int v1 = fl + zb[i + 1];
            int v2 = zb[j - 1] + ll;
            int v3 = st.get(i + 1, j - 2);
            int bg = max({v1, v2, v3});
            ans.push_back(c1 + bg);
        }

        return ans;
    }
};