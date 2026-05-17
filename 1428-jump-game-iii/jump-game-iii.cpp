class Solution {
public:
    bool recursive(vector<int>& arr, int start, vector<bool>& visited) {
        int n = arr.size();
        if (start < 0 || start >= n || visited[start])
            return false;

        if (arr[start] == 0)
            return true;

        visited[start] = true;
        return recursive(arr, start + arr[start], visited) ||
               recursive(arr, start - arr[start], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        return recursive(arr, start, visited);
    }
};