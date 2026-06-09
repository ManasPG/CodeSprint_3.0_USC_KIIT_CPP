#include <bits/stdc++.h>
using namespace std;

struct Query
{
    int l, r, idx;
};

int blockSize;
long long curAns = 0;

vector<int> freq;

bool cmp(const Query &a, const Query &b)
{
    int blockA = a.l / blockSize;
    int blockB = b.l / blockSize;
    if (blockA != blockB)
    {
        return blockA < blockB;
    }
    return a.r < b.r;
}

void add(int x)
{
    curAns -= 1LL * freq[x] * freq[x];
    freq[x]++;
    curAns += 1LL * freq[x] * freq[x];
}

void removeElement(int x)
{
    curAns -= 1LL * freq[x] * freq[x];
    freq[x]--;
    curAns += 1LL * freq[x] * freq[x];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    }

    int q;
    cin >> q;

    vector<Query> queries(q);

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    blockSize = sqrt(n);
    sort(queries.begin(), queries.end(), cmp);

    freq.resize(comp.size() + 1, 0);
    vector<long long> answer(q);

    int curL = 0;
    int curR = -1;

    for (auto &query : queries)
    {
        int L = query.l;
        int R = query.r;
        while (curR < R)
        {
            curR++;
            add(a[curR]);
        }

        while (curR > R)
        {
            removeElement(a[curR]);
            curR--;
        }
        while (curL < L)
        {
            removeElement(a[curL]);
            curL++;
        }
        while (curL > L)
        {
            curL--;
            add(a[curL]);
        }

        answer[query.idx] = curAns;
    }

    for (int i = 0; i < q; i++)
    {
        cout << answer[i] << "\n";
    }
    return 0;
}