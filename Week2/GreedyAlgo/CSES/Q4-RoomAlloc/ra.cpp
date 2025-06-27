// A Complete chatgpt code

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> customers(n);  // (arrival, departure, index)
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        customers[i] = {a, b, i};
    }

    sort(customers.begin(), customers.end());  // sort by arrival time

    // min-heap: (departure day, room number)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int room_count = 0;
    vector<int> result(n);

    for (auto [a, b, idx] : customers) {
        if (!pq.empty() && pq.top().first < a) {
            // Reuse a room
            auto [end_day, room] = pq.top(); pq.pop();
            result[idx] = room;
            pq.push({b, room});
        } else {
            // Allocate new room
            ++room_count;
            result[idx] = room_count;
            pq.push({b, room_count});
        }
    }

    cout << room_count << "\n";
    for (int i = 0; i < n; ++i) cout << result[i] << " ";
    cout << "\n";
}
