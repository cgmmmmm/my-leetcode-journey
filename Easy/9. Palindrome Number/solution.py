# This solution is inefficient, a runtime of worse case O(n), where n is the length of the integer

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        intString = str(x)
        left = 0
        right = len(intString) - 1
        
        for i in intString:
            while left < right:
                if intString[left] == intString[right]:
                    left += 1
                    right -= 1
                else:
                    return False
                    
        return True
            
