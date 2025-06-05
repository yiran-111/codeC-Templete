/**
 * *****************************************************************************
 * @file binary_search.c
 * @brief
 * @author 王轶冉 (1179862677@qq.com)
 * @version 1.0
 * @date 2025-06-05
 * @copyright Copyright (c) 2025  北京航空航天大学
 * *****************************************************************************
 */
#include <stdio.h>
#include <stdbool.h>
/**
 * @name:check
 * @msg:查找数据的那个要求
 * @return {*}
 * @param {int} x
 */
bool check(int x)
{
    /**
     * @brief:此处填入处理逻辑，也就是查找数据的那个要求。
     */
}
/**
 * 二分查找的两个模板分别用于解决两类问题：寻找第一个满足条件的元
 * 素（左边界）和寻找最后一个满足条件的元素（右边界）。这两个模板
 * 在边界移动和中间点的计算上有所不同，以避免死循环和确保正确性。
 */
// 模板一：当区间 [l, r] 被划分为 [l, mid] 和 [mid+1, r] 时使用
// 适用于寻找第一个满足条件的元素（左边界）
/**
 * @name:bsearch_1
 * @msg:左模板
 * @return {*}
 * @param {int} l
 * @param {int} r
 */
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = (l + r) >> 1; // 向下取整
        if (check(mid))
            r = mid; // mid 满足条件，搜索左半部分 [l, mid]
        else
            l = mid + 1; // mid 不满足条件，搜索右半部分 [mid+1, r]
    }
    return l;
}

// 模板二：当区间 [l, r] 被划分为 [l, mid-1] 和 [mid, r] 时使用
// 适用于寻找最后一个满足条件的元素（右边界）
/**
 * @name:bsearch_2
 * @msg:右模板
 * @return {*}
 * @param {int} l
 * @param {int} r
 */
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = (l + r + 1) >> 1; // 向上取整（避免死循环）
        if (check(mid))
            l = mid; // mid 满足条件，搜索右半部分 [mid, r]
        else
            r = mid - 1; // mid 不满足条件，搜索左半部分 [l, mid-1]
    }
    return l;
}
int main()
{
    return 0;
}
/**
 * 折半查找原理：从表的中间记录开始，如果给定值和
 * 中间记录的关键字相等，则查找成功；如果给定值大
 * 于或小于中间记录的关键字，则在表中大于或小于中
 * 间记录的那一半中查找，一直重复操作。直到查找成
 * 功，或者在某一步中查找区间为空，则代表查找失败。
 * 用于处理顺序规定，而需要查找的数据结构。
 */