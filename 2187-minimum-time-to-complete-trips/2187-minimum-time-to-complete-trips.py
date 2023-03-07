class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        left = 0
        right = 10 ** 15
        
        def good(target):
            trips  = 0
            for x in time:
                trips += target // x
            return (trips >= totalTrips)
        
        while(left < right):
            mid = (left + right) // 2
            if good(mid):
                right = mid
            else:
                left = mid + 1
        return left
            