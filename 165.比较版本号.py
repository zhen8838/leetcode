#
# @lc app=leetcode.cn id=165 lang=python3
#
# [165] 比较版本号
#

# @lc code=start
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1 = version1.split('.')
        l2 = version2.split('.')
        for i in range(min(len(l1), len(l2))):
            s1 = l1[i].lstrip('0')
            n1 = int(s1) if s1 else 0
            s2 = l2[i].lstrip('0')
            n2 = int(s2) if s2 else 0
            if n1 < n2:
                return -1
            elif n1 > n2:
                return 1
        if len(l1) < len(l2):
            for i in range(len(l1), len(l2)):
                s2 = l2[i].lstrip('0')
                n2 = int(s2) if s2 else 0
                if n2 > 0:
                    return -1
        elif len(l1) > len(l2):
            for i in range(len(l2), len(l1)):
                s1 = l1[i].lstrip('0')
                n1 = int(s1) if s1 else 0
                if n1 > 0:
                    return 1
        return 0
# @lc code=end


if __name__ == "__main__":
    a = "1.0"
    b = "1.0.0"

    s = Solution()
    print(s.compareVersion(a, b))
