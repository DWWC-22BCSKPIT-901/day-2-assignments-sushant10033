You are given an integer array jobs, where jobs[i] is the amount of time it 
takes to complete the ith job.There are k workers that you can assign jobs to. 
Each job should be assigned to exactly one worker. The working time of a 
worker is the sum of the time it takes to complete all jobs assigned to them. 
Your goal is to devise an optimal assignment such that the maximum working 
time of any worker is minimized. 
Return the minimum possible maximum working time of any assignment 

#include <iostream> 
#include <numeric> 
#include <algorithm> 
using namespace std; 
bool canAssignJobs(int jobs[], int n, int k, int max_time) { 
    int workers = 1, current_time = 0; 
    for (int i = 0; i < n; i++) { 
        if (current_time + jobs[i] > max_time) { 
            workers++; 
            current_time = jobs[i]; 
            if (workers > k) return false; 
        } else { 
            current_time += jobs[i]; 
        } 
    } 
 
    return true; 
} 
int minimumTimeRequired(int jobs[], int n, int k) { 
    int left = *max_element(jobs, jobs + n); 
    int right = accumulate(jobs, jobs + n, 0); 
    while (left < right) { 
        int mid = left + (right - left) / 2; 
        if (canAssignJobs(jobs, n, k, mid)) { 
            right = mid; 
        } else { 
            left = mid + 1; 
        } 
    } 
    return left; 
} 
int main() { 
    int n, k; 
    cin >> n >> k; 
    int jobs[n]; 
    for (int i = 0; i < n; i++) { 
        cin >> jobs[i]; 
} 
int result = minimumTimeRequired(jobs, n, k); 
cout << result << endl; 
return 0; 
}
