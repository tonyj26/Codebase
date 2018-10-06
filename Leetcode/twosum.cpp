/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target){
    std::unordered_map<int, int> hash;
    std::vector<int> result;
    for(int i = 0; i < numbers.size(); i++){
      int numberToFind = target - numbers[i];

      if (hash.find(numberToFind) != hash.end()) {
        result.push_back(hash[numberToFind] + 1);
        result.push_back(i + 1);
        return result;
      }

      hash[numbers[i]] = i;
    }
    return result;
  }
};

int main(){
  std::vector<int> nums = {2, 7, 11, 15};
  Solution sol;
  sol.twoSum(nums, 9).empty();
  return 0;
}
