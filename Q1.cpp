Given an array nums of size n, return the majority element.The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array. 
#include <iostream> using namespace 
std; int majorityElement(int nums[], int 
n) {     int candidate = nums[0];     int 
count = 1;     for (int i = 1; i < n; i++) 
{         if (nums[i] == candidate) 
{             count++;  
        } else {  
            count--;  
        }         if (count == 0) 
{             candidate = 
nums[i];             count = 1;  
        }  
    }     return 
candidate;  
} int main() 
{  
int n;     cout << "Enter the size of the array: ";     cin >> n;       
int* 
nums = new int[n];  // Dynamically allocating memory for the array     
cout << "Enter the elements of the array: ";     for (int i = 0; i < n; i++) 
{         
cin >> nums[i];  
}  
int result = majorityElement(nums, n);     cout << 
"The majority element is: " << result << endl;     delete[] 
nums;  // Deallocate the memory     return 0; } 
