int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    static int p[2];
    for(int i = 0; i < numsSize - 1; i++)
        for(int j = i + 1; j < numsSize ; j++)
            if(nums[j] == target - nums[i])
            {
                *returnSize = 2;
                p[0] = i;
                p[1] = j;
                return p;
            }
    *returnSize = 0;
    return NULL;
}
