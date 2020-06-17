// Plan: This was an extremely painful problem.

class Solution {
public:
    int tryIPv4OrIPv6(const string& IP) {
        if (IP.find('.') != string::npos && IP.find(':') == string::npos) {
            auto count = 0;
            for (auto c : IP) {
                if (c == '.') {
                    ++count;
                }
            }
            return count == 3 ? 4 : -1;
        }
        if (IP.find('.') == string::npos && IP.find(':') != string::npos) {
            auto count = 0;
            for (auto c : IP) {
                if (c == ':') {
                    ++count;
                }
            }
            return count == 7 ? 8 : -1;
        }
        return -1;
    }
    int validIPv4Octet(const string& s) {
        if (!s.size() or s.size() > 3) return -1;
        for (auto c : s) if (!isdigit(c)) return -1;
        auto num = stoi(s, nullptr, 10);
        auto str = to_string(num);
        return 0 <= num and num < 256 and str == s ? num : -1;
    }
    int validIPv6Hextet(const string& s) {
        if (!s.size() or s.size() > 4) return -1;
        for (auto c : s) if (!isxdigit(c)) return -1;
        auto num = stoul(s, nullptr, 16);
        return 0 <= num && num < 65536 ? num : -1;
    }
    vector<int> splitIPv4(const string& IP) {
        auto result = vector<int>{};
        stringstream ss(IP);
        string octet;
        while (getline(ss, octet, '.')) {
            auto num = validIPv4Octet(octet);
            if (num != -1)
                result.push_back(num);
        }
        return result;
    }
    vector<int> splitIPv6(const string& IP) {
        auto result = vector<int>{};
        stringstream ss(IP);
        string hextet;
        while (getline(ss, hextet, ':')) {
            auto num = validIPv6Hextet(hextet);
            if (num != -1)
                result.push_back(num);
        }
        return result;
    }
    void print(const vector<int>& v) {
        cout << "[";
        for (auto num : v) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    string validIPAddress(string IP) {
        string result = "";
        auto type = tryIPv4OrIPv6(IP);
        auto split = vector<int>{};
        if (type == 4) {
            split = splitIPv4(IP);
            result = "IPv4";
        }
        if (type == 8) {
            split = splitIPv6(IP);
            result = "IPv6";
        }
        //cout << result << "\n";
        //print(split);
        return type == split.size() ? result : "Neither";
    }
};
