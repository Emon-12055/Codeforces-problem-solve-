#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


struct Activity {
    int start, finish, index;
};

bool compareActivity(Activity a, Activity b) {
    return a.finish < b.finish;
}

vector<int> activitySelection(vector<int> start, vector<int> finish) {
    int n = start.size();
    vector<int> selected;

    if (n == 0) return selected;

    vector<Activity> activities;

    for (int i = 0; i < n; i++) {
        Activity temp;
        temp.start = start[i];
        temp.finish = finish[i];
        temp.index = i;
        activities.push_back(temp);
    }

    sort(activities.begin(), activities.end(), compareActivity);

    selected.push_back(activities[0].index);
    int lastFinish = activities[0].finish;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            selected.push_back(activities[i].index);
            lastFinish = activities[i].finish;
        }
    }

    return selected;
}

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compareJob(Job a, Job b) {
    return a.profit > b.profit;
}

pair<vector<char>, int> jobSequencing(vector<Job> jobs) {
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), compareJob);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    vector<char> result(maxDeadline, '-');
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (result[j] == '-') {
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return make_pair(result, totalProfit);
}


int main() {

    // ===== Activity Selection Input =====
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<int> start(n), finish(n);

    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }

    cout << "Enter finish times:\n";
    for (int i = 0; i < n; i++) {
        cin >> finish[i];
    }

    vector<int> selectedActivities = activitySelection(start, finish);

    cout << "\nSelected Activities: ";
    for (int i = 0; i < selectedActivities.size(); i++) {
        cout << "A" << selectedActivities[i] + 1 << " ";
    }
    cout << endl;



    int m;
    cout << "\nEnter number of jobs: ";
    cin >> m;

    vector<Job> jobs(m);

    cout << "Enter job details (ID Deadline Profit):\n";
    for (int i = 0; i < m; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    pair<vector<char>, int> result = jobSequencing(jobs);

    cout << "\nScheduled Jobs:\n";
    for (int i = 0; i < result.first.size(); i++) {
        if (result.first[i] != '-') {
            cout << "Slot " << i + 1 << ": " << result.first[i] << endl;
        }
    }

    cout << "Total Profit: " << result.second << endl;

    return 0;
}

