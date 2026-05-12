class Solution {
public:
    bool canFinish(vector<vector<int>>& tasks, int energy) {

        for (auto& task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            // Check if current energy is enough
            if (energy >= minimum) {
                energy -= actual;
            } else {
                return false;
            }
        }

        return true;
    };

    int minimumEffort(vector<vector<int>>& tasks) {
        // ___
        // Sort based on (minimum - actual) in decreasing order
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int low = 0;
        int high = 0;

        // low = maximum minimum energy
        // high = sum of all minimum energies
        for (auto& task : tasks) {

            low = max(low, task[1]);
            high += task[1];
        }

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(tasks, mid)) {

                ans = mid;
                high = mid - 1;
            } else {

                low = mid + 1;
            }

            // ___
        }
        return ans;
    }
};