You are given a 0-indexed array of integers nums of length n. You are initially 
positioned at nums[0]. Each element nums[i] represents the maximum length of a 
forward jump from index i. In other words, if you are at nums[i], you can jump to 
any nums[i + j] where:0 <= j <= nums[i] and i + j < n 

#include <iostream>
using namespace std; int 
minJumps(int nums[], int n) {     if (n <= 1) return 0;     
int jumps = 0;     int currentEnd = 0;     int 
currentFarthest = 0;     for (int i = 0; i < n - 1; i++) 
{         
currentFarthest = max(currentFarthest, i + 
nums[i]);         
if (i == currentEnd) {             
currentEnd = currentFarthest;             
n - 1) break;  
}}  
return jumps;  
jumps++;             
if (currentEnd >= 
} int main() 
{  
int n;     cout << "Enter the size of the 
array: ";     
int[n];     
array: ";     
{         
cin >> n;     int* nums = new 
cout << "Enter the elements of the 
for (int i = 0; i < n; i++) 
cin >> nums[i];  
}  
int result = minJumps(nums, n);     cout << "Minimum number of jumps to reach 
the last index: " << result << endl;     delete[] nums;     return 0;  
}
