class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        frequency = {}

        for num in nums:
            if num not in frequency:
                frequency[num] = 1
            else:
                frequency[num] += 1

        #Approach 1: using Sort by lambda function
        # Explaining lambda function and its syntax:
        #  1. We can't sort a dictionary directly, so we have to return the dictionary in the form of a key-value pairs tuple
        #  2. frequency.items() returns the dictionary's key-value pairs as a list of tuples
        #       - returns something like [(1,3), (2,2), (3,1)]
        #  3. key=lambda item: item[1] specifies that the sorting should be based on the second element ("1") of each tuples, which is the value
        #  4. reverse=True here to sort it in a descending order
        list_of_sorted_frequency_tuples = sorted(frequency.items(), key=lambda item: item[1], reverse=True)

        # (key for ...) this is a list comprehension; a shorthand way to build list
        #  - it takes key from each tuple and puts it into a new list
        # (for key, value in ...) this is a loop that iterates through each key-value tuple
        #  - Testcase: [1,1,1,2,2,3]
        #  - First iteration loop: key = 1, value = 3
        #  - Second iteration loop: key = 2, value = 2
        # list_of_sorted_frequency_tuples[:k] this is a list slicing.
        #  - If list_of_sorted_frequency_tuples[:k] is something like [(1, 3), (2, 2), (3, 1)], then list_of_sorted_frequency_tuples[:2] is [(1, 3), (2, 2)]
        #  - it takes the first k tuples from list_of_sorted_frequency_tuples
        return [key for key, value in list_of_sorted_frequency_tuples[:k]]

        # This whole entire line is a compact version of:
        # result = []
        # for key, value in list_of_sorted_frequency_tuples[:k]:
        #   result.append(key)
        # return result
