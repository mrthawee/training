'''
Binary Heap
    Insert: O(log n)
    Delete: O(log n)

    Change Priority (update a value of any node): O(log n)
    BuildHeap: O(n)

HeapSort for n values = BuildHeap + Delete
    = O(n) + O(n * log n) = O(n log n)
* In-place = Yes
* Stable = No
'''
import heapq

l = [ 5, 7, 9, 1, 3 ]

heapq.heapify(l)
print("heap =", l)

res_min = []
while len(l):
    res_min.append(heapq.heappop(l))
print('Sorting min-to-max:', res_min)
#print(res_min)

# Max Heap : val * -1
x = [ 5, 7, 9, 1, 3 ]
m = []
for v in x:
    heapq.heappush(m, v*-1)
#print(m)
res_max = []
while len(m):
    res_max.append(-1 * heapq.heappop(m))
print('Sorting max-to-min:', res_max)
