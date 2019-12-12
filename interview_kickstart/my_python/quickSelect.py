def helper(A, start, end, index):  # index of interest
    # Base case
    if start >= end:
        if start == end:
            return A[star]
        else:
            print("Bug!")

    # lomuto
    #
    # at the end: pivot at orange index
    if index == orange: # found it!
        return A[index]
    elif index < orange:
        return helper(A, start, orange - 1, index)
    else
        return helper(A, orange + 1, end, index)

def quickSelect(nums, k):
    return helper(nums, 0, len(nums) - 1, len(nums) - k)  # 2nd largest -> k - 1

# homework: extend lomuto to do 3-way partitioning in one-pass, which is good for a lot of duplicates. Dutch National Flag (3-colorring)
# Leetcode 215
# Leetcode 973

# Leetcode 703

# Leetcode 295 : Hint: you need to store ALL numbers
# Hint 2: need 2 collections 
# - Left collection: Max Heap
# - Right collection: Min Heap
# - then the top of both, the median is the average of them
# - then adding new value, pop one from the added heap, and add that popped value to the other heap -> need re-balance the 2 heaps -> size diff can't be 2

# to use min heap as max heap => insert the negation value into the fake max heap

minHeap = []
maxHeap = []
median = 0.0
for each new-val in stream:
    if new-val <= median:
        # insert left - insert to max heap
        insert new-val into max heap
        # re-balance if needed
        if (size of max-heap) - (size of min-heap) == 2:
            re-balance
            minHeap.push(the extracted val from max heap)
    elif new-val > median:
        insert new-val into min heap
        if (size of min-heap) - (size of max-heap) == 2:
            re-balance
            maxHeap.push(the extracted val from min heap)
            minHeap.push(the extracted val from max heap)

    if (size of minHeap) == (size of maxHeap):
        return avg of both roots
    else if (size of minHeap) > (size of maxHeap):
        return root of minHeap
    else if (size of maxHeap) > (size of minHeap):
        return root of maxHeap * -1  # because we use minHeap as maxHeap


Conclusion
- non-streaming: quick select to return median
- streaming: need 2 heaps


# Leetcode 23: merge k sorted lists : external merge : Hint: combine merge sort with heap
