/* ------------------------------------------------------------------|
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

 

示例 1：

输入：nums = [1,3,5]
输出：1
示例 2：

输入：nums = [2,2,2,0,1]
输出：0
 

提示：

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
 

进阶：

这道题是 寻找旋转排序数组中的最小值 的延伸题目。
允许重复会影响算法的时间复杂度吗？会如何影响，为什么？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*	二分法
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：11.8 MB, 在所有 C++ 提交中击败了89.54%的用户
*/
int findMin(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    else if (n == 2) {
        return min(nums[0], nums[1]);
    }
    int l = 0;
    int r = n - 1;
    int mid;
    if (nums[l] < nums[r]) {
        return nums[0];
    }
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] == nums[r]) {
            r--;
        }
        else if (nums[mid] > nums[r]) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return nums[l];
}

/*	左闭右开分治法
*	执行用时：8 ms, 在所有 C++ 提交中击败了60.56%的用户
*	内存消耗：11.9 MB, 在所有 C++ 提交中击败了85.00%的用户
*/
//int dfs(int l, int r,vector<int> & nums) {
//    if (r - l == 2) {
//        return min(nums[r - 1], nums[l]);
//    }
//    else if (r - l == 1) {
//        return nums[l];
//    }
//    else {
//        int mid = (r + l) / 2;
//        return min(dfs(l, mid, nums), dfs(mid, r, nums));
//    }
//}
//
//int findMin(vector<int>& nums) {
//    return dfs(0, nums.size(),nums);
//}

/*	遍历法
*	执行用时：8 ms, 在所有 C++ 提交中击败了60.56%的用户
*	内存消耗：12 MB, 在所有 C++ 提交中击败了36.89%的用户
*/
//int findMin(vector<int>& nums) {
//    int min = INT_MAX;
//    for (int &i : nums) {
//        if (i < min) {
//            min = i;
//        }
//    }
//    return min;
//}

int main() {
    vector<int> nums = { 2,2,2,0,1 };
    findMin(nums);
}