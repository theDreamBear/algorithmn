#
# @lc app=leetcode.cn id=497 lang=python3
#
# [497] 非重叠矩形中的随机点
#

# @lc code=start
def randonPoint(v):
    lx = v[0]
    ly = v[1]

    rx = v[2]
    ry = v[3]

    dx = rx - lx
    dy = ry - ly

    nx = random.randint(0, dx) + lx
    ny = random.randint(0, dy) + ly
    return [nx, ny]


def binarySearch(area, v):
    low = 0
    high = len(area) - 1
    while low + 1 < high:
        mid = (high - low) // 2 + low
        if area[mid] <= v:
            low = mid
        else:
            high = mid
    if area[high] < v:
        return high
    return low


class Solution:

    def __init__(self, rects: List[List[int]]):
        self.dt = {}
        self.areas = [0]
        pre = 0
        for idx, v in enumerate(rects):
            lx = v[0]
            ly = v[1]

            rx = v[2]
            ry = v[3]
            area = (rx - lx + 1) * (ry - ly + 1)
            self.areas.append(area + pre)
            pre += area
            self.dt[idx] = v
        self.max = self.areas[-1]

    def pick(self) -> List[int]:
        v = random.randint(0, self.max - 1)
        idx = binarySearch(self.areas, v)
        return randonPoint(self.dt[idx])


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
# @lc code=end

