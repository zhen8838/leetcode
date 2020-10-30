#
# @lc app=leetcode.cn id=278 lang=python3
#
# [278] 第一个错误的版本
#

v = 4
# @lc code=start
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer


def isBadVersion(version):
    if version >= v:
        return True
    else:
        return False


class Solution:

    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        start = 0
        end = n - 1
        mid = 0
        while start < end:
            mid = (start + end) // 2
            if isBadVersion(mid):
                end = mid - 1
            else:
                start = mid + 1
        if isBadVersion(end):
            return end
        else:
            return end + 1


# @lc code=end


if __name__ == "__main__":
    s = Solution()
    print(s.firstBadVersion(5))
