#include <iostream>
#include <vector>

int maxSubArray(std::vector<int> &nums);

int main() {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    maxSubArray(nums);

    return 0;
}

int maxSubArray(std::vector<int> &nums) {

    int summ = nums[0], left = 0, right = 0, maxSumm = nums[0], bestLeft;

    for (int i = 1; i < nums.size(); i++) {

        if (summ > 0 && nums[i] < 0 && std::abs(nums[i]) > summ) {
            summ = nums[i];
        }

        summ += nums[i];

        if (nums[i] > summ) {
            summ = nums[i];
            if (i > right) bestLeft = i;
            else left = i;
        }
        if (summ > maxSumm) {
            maxSumm = summ;
            right = i;
        }
        if (bestLeft < right) left = bestLeft;
        if (maxSumm < maxSumm - nums[left]) {
            left++;
        }

    }
    std::cout << left << " - " << right << std::endl;

    return maxSumm;

}







