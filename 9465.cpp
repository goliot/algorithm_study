#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[100001];
bool visited[100001];
vector<int> v[100001];

void dfs(int k) {
    visited[k] = true;
    for(int i=0; i<v[k].size(); i++) {
        int next = v[k][i];
        if(!visited[next]) {
            arr[next] = k;
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);
    for(int i=2; i<=n; i++) cout << arr[i] << '\n';

    return 0;
}