# Heap (Binary Heap)

This folder contains implementations of Binary Heap data structure.

### When to use Heap in an question 

🔑 Core intuition (memorize this)

Use a Priority Queue when you repeatedly need the “best” element,
and the definition of “best” can change over time.

“Best” can mean:

maximum

minimum

earliest

cheapest

most frequent

least distance

🧠 Decision Checklist (VERY IMPORTANT)

Ask yourself these questions in order:

1️⃣ Do I need the min / max repeatedly?

If you keep doing:

give me the smallest
give me the largest


👉 Priority Queue

2️⃣ Does the data change while I’m processing?

If elements:

get removed

get updated

get added again

👉 Priority Queue

(Sorting once won’t be enough)

3️⃣ Is greedy choice involved?

If the problem sounds like:

“always pick the best available”

“choose the most frequent”

“choose the earliest finishing”

👉 Priority Queue

4️⃣ Is the order dynamic (not fixed)?

If the “best” element:

changes after every step

depends on updated values

👉 Priority Queue

🔥 Common Patterns Where PQ Is Used
✅ 1. Scheduling / CPU / Tasks

Keywords:

tasks

cooldown

scheduling

intervals

time slots

Examples:

Task Scheduler

Meeting Rooms II

CPU scheduling

👉 Pick next task with max freq / earliest end

✅ 2. Top K problems

Keywords:

top k

kth largest / smallest

k closest

Examples:

Top K Frequent Elements

Kth Largest Element in Array

👉 Maintain only k best elements

✅ 3. Streaming data

Keywords:

running median

real-time data

Examples:

Find Median from Data Stream

👉 Data comes continuously → PQ adapts

✅ 4. Greedy graph problems

Keywords:

shortest path

minimum cost

Examples:

Dijkstra’s Algorithm

Prim’s MST

👉 Always expand the cheapest node

✅ 5. Frequency-based greedy

Keywords:

rearrange

avoid adjacency

most frequent first

Examples:

Reorganize String

Hand of Straights (heap version)

Task Scheduler

✅ 6. Interval / timeline problems

Keywords:

earliest finishing

overlapping intervals

Examples:

Meeting Rooms

Merge intervals (variants)

👉 Keep track of next ending interval

❌ When NOT to use Priority Queue
🚫 If order never changes

Example:

Sort once and iterate

👉 Just sort

🚫 If you only need one min/max

Example:

Find smallest element

👉 Linear scan

🚫 If indexed access matters

Example:

prefix sums

DP tables

👉 Arrays / vectors

#### 🧠 Compare structures (very useful)

Need	                   -    Best structure

Always smallest         -    	Min-heap

Always largest	         -     Max-heap

Sorted traversal	      -      Map / sort

Dynamic best choice	    -     Priority Queue

Constant lookup	        -     Hash map
