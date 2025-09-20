#include <bits/stdc++.h>
using namespace std;

class Router {
private:
    struct Packet {
        int source, destination, timestamp;
        Packet(int s, int d, int t) : source(s), destination(d), timestamp(t) {}
    };

    int memoryLimit;
    vector<Packet> packets;  // store packets in FIFO
    unordered_set<string> set;  // to check duplicates
    unordered_map<int, vector<int>> map;  // destination -> list of timestamps

    string getKey(int source, int destination, int timestamp) {
        return to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);
    }

    int lowerBound(const vector<int>& arr, int target) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int upperBound(const vector<int>& arr, int target) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string value = getKey(source, destination, timestamp);

        if (set.count(value)) {
            return false;  // duplicate
        }

        if ((int)packets.size() == memoryLimit) {
            Packet packet = packets.front();
            packets.erase(packets.begin());

            string key = getKey(packet.source, packet.destination, packet.timestamp);
            set.erase(key);

            auto& timestamps = map[packet.destination];
            if (!timestamps.empty()) {
                timestamps.erase(timestamps.begin());
            }
        }

        set.insert(value);
        packets.emplace_back(source, destination, timestamp);
        map[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) {
            return {}; // no packets
        }

        Packet packet = packets.front();
        packets.erase(packets.begin());

        string key = getKey(packet.source, packet.destination, packet.timestamp);
        set.erase(key);

        auto& timestamps = map[packet.destination];
        if (!timestamps.empty()) {
            timestamps.erase(timestamps.begin());
        }

        return {packet.source, packet.destination, packet.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = map.find(destination);
        if (it == map.end() || it->second.empty())
            return 0;

        const vector<int>& arr = it->second;
        int upper = upperBound(arr, endTime);
        int lower = lowerBound(arr, startTime);

        return upper - lower;
    }
};
