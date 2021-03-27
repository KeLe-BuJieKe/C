#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*������ 17.04. ��ʧ������
����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
ע�⣺�����������ԭ�������Ķ�
ʾ�� 1��
���룺[3,0,1]
�����2
ʾ�� 2��
���룺[9,6,4,2,3,5,7,0,1]
�����8
���ӣ�https://leetcode-cn.com/problems/missing-number-lcci/
*/


int missingNumber(int* nums, int numsSize)
{
    int temp = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        //��򣬰������е�����0-n�������
        temp ^= i ^ nums[i];
    }
    return temp;
}



/*��ָ Offer 56 - I. ���������ֳ��ֵĴ���
һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
ʾ�� 1��
���룺nums = [4,1,4,6]
�����[1,6] �� [6,1]
ʾ�� 2��
���룺nums = [1,2,10,4,1,4,3,3]
�����[2,10] �� [10,2]
���ӣ�https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
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
    //��ʼ������򣬵õ�ĳһ������Mλ��0�����������Mλ��1
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



/*��ָ Offer 56 - II. ���������ֳ��ֵĴ��� II
��һ������ nums �г�һ������ֻ����һ��֮�⣬�������ֶ����������Ρ����ҳ��Ǹ�ֻ����һ�ε����֡�
ʾ�� 1��
���룺nums = [3,4,3,3]
�����4
ʾ�� 2��
���룺nums = [9,1,7,9,7,9,7]
�����1
���ӣ�https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
*/

