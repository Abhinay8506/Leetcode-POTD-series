public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetingCount(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
           available.push(i);
        }
        sort(meetings.begin(), meetings.end());

        for (auto meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!busy.empty() && busy.top().first <= start) {
                int room = busy.top().second;
                busy.pop();
                available.push(room);
            }
            if (!available.empty()) {
                int room = available.top();
                available.pop();
                busy.push({end, room});
                meetingCount[room]++;
            } else {
                auto [vacantTime, room] = busy.top();
                busy.pop();
                busy.push({vacantTime + end - start, room});
                meetingCount[room]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};
