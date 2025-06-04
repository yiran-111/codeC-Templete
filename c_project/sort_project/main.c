/**
 * *****************************************************************************
 * @file        main.c
 * @brief       用于实现排序的一个工程
 * @author      yiran-111 (1179862677@qq.com)
 * @date        2025-06-04
 * @copyright   buaa
 * *****************************************************************************
 */
#include <stdio.h>
/**
 * @name:quick_sort1
 * @msg:此函数用于快速排序
 * @return {*}
 * @param {int} NeedSort
 * @param {int} left
 * @param {int} right
 */
void quick_sort1(int NeedSort[], int left, int right)
{
    /**
     * @brief
     * 快速排序：第一步确定分界点x第二步调整区间，令有小于等于
     * x的在a区间，大于x的在b区间。第三步递归处理左右两段区间。
     *
     * 主要思想是分治。最难的一步是调整范围：从最简单的开始：新
     * 建两个数组，扫描一遍按照上面思想，插入a和插入b，再把a和b
     * 合并。而比较复杂且占用空间更低的算法是，建立两个指针i和j
     * 一个放在头一个放在尾，交替移动，直到遇到小于等于或大于等
     * 于x的数为止。一旦发现，就把这两个指向的值交换，继续推进。
     * 在i和j互相错开，或i和j处于同一位置，则终止。
     */
    if (left >= right)
        return;
    int x = NeedSort[right], i = left - 1, j = right + 1, swap = 0;
    /**边界问题：
     * 用i和用j两种情况进行递归，就要考虑到数组上下界的问题，
     * 用了i就不能用左边界，用了j就不能用右边界，否则对付一些
     * 特殊数组，就会出现一边区间为负，另一边区间仍为原本的
     * 情况，这是不希望看到的。边界问题不要过多考虑，看模板
     * 即可，重点理解它的思想。
     */
    while (i < j)
    {
        do
        {
            i++;
        } while (NeedSort[i] < x);
        do
        {
            j--;
        } while (NeedSort[j] > x);
        if (i < j)
        {
            swap = NeedSort[i];
            NeedSort[i] = NeedSort[j];
            NeedSort[j] = swap;
        }
    }
    quick_sort1(NeedSort, left, i - 1);
    quick_sort1(NeedSort, i, right);
}
/**
 * @name: merge_sort
 * @msg: 归并排序的用法
 * @return {*}
 * @param {int} NeedSort
 * @param {int} left
 * @param {int} right
 */
void merge_sort(int NeedSort[], int left, int right)
{
    /**
     * 归并排序的基本思想是，取数组中点位置为分界点，进行
     * 递归排序，用指针交替移动的方式把两个拆分数组合二为一。
     */
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    merge_sort(NeedSort, left, mid);
    merge_sort(NeedSort, mid + 1, right);

    int k = 0, i = left, j = mid + 1;
    int temp[100];
    while (i <= mid && j <= right)
    {
        if (NeedSort[i] <= NeedSort[j])
            temp[k++] = NeedSort[i++];
        else
            temp[k++] = NeedSort[j++];
    }
    while (i <= mid)
        temp[k++] = NeedSort[i++];
    while (j <= right)
        temp[k++] = NeedSort[j++];
    for (i = left, j = 0; i <= right; i++, j++)
        NeedSort[i] = temp[j];
}
int main()
{
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(a, 0, 9);
    for (int index = 0; index < 10; index++)
    {
        printf("%d ", a[index]);
    }
    return 0;
}
