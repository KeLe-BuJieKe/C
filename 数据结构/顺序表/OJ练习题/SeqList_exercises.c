#define _CRT_SECURE_NO_WARNINGS 1


/*题目：移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
*/
//题解如下
//int removeElement(int* nums, int numsSize, int val)
//{
//    int i = 0, j = 0;
//    while (numsSize--)
//    {
//        //运用俩个下标，当nums[i]==val时，i自增，j不变
//        //             当nums[i]!=val时，把nums[i]的值赋给nums[j]，并且j++，i++
//        if (nums[i] != val)
//        {
//            nums[j] = nums[i];
//            j++;
//        }
//        i++;
//    }
//    return j;
//}