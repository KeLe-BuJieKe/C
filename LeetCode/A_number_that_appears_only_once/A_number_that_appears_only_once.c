#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*面试题 17.04. 消失的数字
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
注意：本题相对书上原题稍作改动
示例 1：
输入：[3,0,1]
输出：2
示例 2：
输入：[9,6,4,2,3,5,7,0,1]
输出：8
链接：https://leetcode-cn.com/problems/missing-number-lcci/
*/


int missingNumber(int* nums, int numsSize)
{
    int temp = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        //异或，把数组中的数与0-n的数异或
        temp ^= i ^ nums[i];
    }
    return temp;
}



/*剑指 Offer 56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。
示例 1：
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
*/

int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    if (nums == NULL || numsSize < 2)
    {
        return NULL;
    }
    int temp = 0;
    for (int i = 0; i < numsSize; i++)
    {
        temp ^= nums[i];
    }
    //开始分组异或，得到某一个数得M位是0，另外个数得M位是1
    int M = 0;
    for (M = 0; M < 32; M++)
    {
        if ((temp >> M) & 1)
        {
            break;
        }
    }
    int x1 = 0;
    int x2 = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if ((nums[j] >> M) & 1)
        {
            x1 ^= nums[j];
        }
        else
        {
            x2 ^= nums[j];
        }
    }
    int* ret = (int*)malloc(2 * sizeof(int));
    ret[0] = x1;
    ret[1] = x2;
    *returnSize = 2;
    return ret;
}



/*剑指 Offer 56 - II. 数组中数字出现的次数 II
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
示例 1：
输入：nums = [3,4,3,3]
输出：4
示例 2：
输入：nums = [9,1,7,9,7,9,7]
输出：1
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
*/

