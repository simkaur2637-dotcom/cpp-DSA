//======================================
// 1.Remove Duplicates from Sorted Array
//======================================
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int k = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (k < 2 || nums[i] != nums[k - 2]) {

                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

//====================================
//Move Zeroes
//====================================
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int k = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {

                nums[k] = nums[i];
                k++;
            }
        }

        while (k < nums.size()) {

            nums[k] = 0;
            k++;
        }
    }
};

//=======================================
//Rotate Array
//=======================================
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};
