class RandomizedSet
{
public:
    vector<int> nums;
    unordered_map<int, int> valToIndex;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (valToIndex.count(val))
            return false;
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!valToIndex.count(val))
            return false;
        int index = valToIndex[val];
        int lastVal = nums.back();
        nums[index] = lastVal;
        valToIndex[lastVal] = index;
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom()
    {
        int randIndex = rand() % nums.size();
        return nums[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */