class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Convert intervals to event points: 
        // Start as {start, 1} for adding an interval
        // End as {end + 1, -1} for removing an interval
        vector<pair<int, int>> eventPoints;
        
        // Create event points from intervals
        for (vector<int> interval : intervals) {
            eventPoints.push_back({interval[0], 1});        // Interval start
            eventPoints.push_back({interval[1] + 1, -1});   // Interval end + 1
        }

        // Sort event points: first by the time value, 
        // then by event type (+1 for start, -1 for end)
        sort(eventPoints.begin(), eventPoints.end());

        int activeIntervals = 0;           // Current number of active intervals
        int maxActiveIntervals = 0;        // Maximum number of overlapping intervals
        
        // Traverse through all event points
        for (auto event : eventPoints) {
            activeIntervals += event.second;   // Update active intervals count
            
            // Update the maximum concurrent intervals if current exceeds previous max
            maxActiveIntervals = max(maxActiveIntervals, activeIntervals);
        }

        return maxActiveIntervals;  // Return the maximum number of concurrent intervals
    }
};

