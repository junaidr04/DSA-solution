#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<int> twoSum(vector<int>&nums, int target)
    {
        map<int, int>freq;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            int num=nums[i];
            int need=target-num;
            if(freq.find(need) != freq.end())
            {
                return {freq[need], i};
            }
            freq[num]=i;
        }
        return {-1, -1};
    }
};
int main()
{
    int n,target;
    cout<<"Enter the num of element = ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the number = ";
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter the target = ";
    cin>>target;
    Solution sol;
    vector<int> result=sol.twoSum(nums, target);
    if(result[0] != -1)
    {
        cout<<result[0]<<","<<result[1]<<endl;
    }
    else
    {
        cout<<"No sol"<<endl;
    }
    return 0;
}