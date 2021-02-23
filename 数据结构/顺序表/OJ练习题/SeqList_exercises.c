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
//    while (i<numsSize)
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




/*题目：删除排序数组中的重复项
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
示例 1:
给定数组 nums = [1,1,2], 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],函数应该返回新的长度 5, 
并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。你不需要考虑数组中超出新长度后面的元素。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array 
*/
//int removeDuplicates(int* nums, int numsSize)
//{
//    if (numsSize == 0) //先判断nums的个数，如果为0，则返回0
//    {
//        return 0;
//    }
//    //pre前一个下标  cur记录当前下标
//    int pre = 1,     cur = 1;       //一前、一后俩个下标
//    while (pre < numsSize)
//    {
//        //判断后面下标对应的值是否==前面下标对应的值
//        //如果不相等则cur下标+1，pre+1
//        //相等则pre单独+1
//        if (nums[pre] != nums[pre - 1])
//        {
//            nums[cur] = nums[pre];
//            cur++;
//        }
//        pre++;
//    }
//    return cur;
//}



/*题目：数组形式的整数加法
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
示例 1：
输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
示例 2：
输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455
示例 3：
输入：A = [2,1,5], K = 806
输出：[1,0,2,1]
解释：215 + 806 = 1021
示例 4：
输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
输出：[1,0,0,0,0,0,0,0,0,0,0]
解释：9999999999 + 1 = 10000000000
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-to-array-form-of-integer
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//这里的int *returnSize是输出型参数，不是给你使用的，它需要解引用返回个值
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
//{
//    int Knum = K;
//    int Ksize = 0;    //用来存储k的位数
//    while (Knum)
//    {
//        ++Ksize;
//        Knum /= 10;
//    }
//    int len = ASize > Ksize ? ASize : Ksize;    //看ASize大还是Ksize大，因为要创建的结果数组的长度
//                                        //最大就是等于(Ksize)或者(ASize)的个数+1
//                                        //位数大的要用来当作循环结束条件，最大几位数就循环几次
//    int Ai = ASize - 1;     //A的最后一个元素的下标
//    int* retArray = (int*)malloc(sizeof(int) * (len + 1));  //结果数组
//    int reti = 0;         //结果数组的起始下标
//    int nextNum = 0;  //进位
//    while (len--)
//    {
//        int a = 0;
//        if (Ai >= 0)   //如果数组的位数小于K的位数时，会导致越界访问
//                    //比如A为99 k为123
//                    //   99
//                    //  123
//                    //-------
//                    //   22
//                    //此时A已经没有元素加了，如果不控制Ai>=0的话，在继续--，Ai会变成-1会造成越界访问
//                    //当Ai为0时，则没有位数了，则直接加0即可
//        {
//            a = A[Ai];
//            Ai--;
//        }
//        //加nextNum是因为，地位进位来的，如果需要进位就+1，否则+0
//        int ret = a + K % 10 + nextNum;
//        K /= 10;          //为了取到高的一位
//        if (ret > 9)       //判断是否要进位
//        {
//            ret -= 10;
//            //如果要进位，nextNUm=1
//            nextNum = 1;
//        }
//        else
//        {
//            //如果不需要进位，则进位就为0
//            nextNum = 0;
//        }
//        //顺着填入到目标数组
//        //把ret的值赋给结果数组,然后结果数组下标++
//        retArray[reti] = ret;
//        ++reti;
//    }
//    if (nextNum == 1)
//    {
//        //最后一次循环，如果进位了，则retArray[reti]的值一定为1
//        retArray[reti] = 1;
//        ++reti;
//    }
//    //在把目标数组逆置一下，得到最终结果数组
//    int left = 0, right = reti - 1;
//    while (left < right)
//    {
//        int temp = retArray[left];
//        retArray[left] = retArray[right];
//        retArray[right] = temp;
//        left++;
//        right--;
//    }
//    *returnSize = reti;
//    return retArray;
//}



/*题目：只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,1]
输出: 1
示例 2:
输入: [4,1,2,1,2]
输出: 4
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
*/
//int singleNumber(int* nums, int numsSize)
//{
//    for (int i = 1; i < numsSize; ++i)
//    {
/*
            1.交换律：a ^ b ^ c <=> a ^ c ^ b
            2.任何数与0异或为任何数 0 ^ n => n
            3.相同的数异或为0: n ^ n => 0
*/
//        //由于不让使用额外空间，则我们使用数组的第一个空间来异或
//        //如果一个数异或两次相同的数，会变回原来的值
//        //每个数都与nums[0]异或
//        nums[0] ^= nums[i];
//    }
//    return nums[0];
//}





/*题目：只出现一次的数字Ⅲ
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
示例 1：
输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
示例 2：
输入：nums = [-1,0]
输出：[-1,0]
示例 3：
输入：nums = [0,1]
输出：[1,0]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-iii
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    //按照上题的思路继续写
    //1.首先把所有数异或，得到两个只出现一次数异或的结果
    int ret = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        //任何数与0异或为任何数 0 ^ n => n
        //得到两个只出现一次数异或的结果
        ret ^= nums[i];
    }

    //2.我们开始想方法将它们分离
    //2.1首先找出ret二进制里面第M位为1的
    //说明x1和x2的第M位不相同，一个为0，一个为1
    int M = 0;
    while (M < 32)
    {
        /*假设  x1为5   x2为3
                0101    0011
                5^3==0110
                异或的俩个数一定至少会有一位为1，找到这个1所在第几位
        */
        if ((ret >> M) & 1)      //如果找到有一位为1，则退出循环，否则M++
        {
            break;
        }
        else
        {
            ++M;
        }
    }
    //2.2然后我们去数组中分离出x1和x2
    //将M位为0的分为一组，为1的分为一组
    int x1 = 0, x2 = 0;
    for (int j = 0; j < numsSize; ++j)
    {
        if ((nums[j] >> M) & 1)   //nums[j]二进制位中的第M位为1的一组
        {
            //每个第M位为1的nums成员与x1异或得到x1
            x1 ^= nums[j];
        }
        else                //nums[j]二进制位中的第M位为0的一组
        {
            //每个第M位为0的nums成员与x2异或得到x2
            x2 ^= nums[j];
        }
    }
    int* retArray = (int*)malloc(sizeof(int) * 2);
    retArray[0] = x1;
    retArray[1] = x2;
    *returnSize = 2;
    return retArray;
}