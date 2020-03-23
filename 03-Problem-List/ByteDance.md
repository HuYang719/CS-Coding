Title	Solution	Acceptance	Difficulty	Frequency  

440	K-th Smallest in Lexicographical Order    		27.9%	Hard

	
~~1262 Greatest Sum Divisible by Three    		43.7%	Medium~~

note 1262: 此题还可以采用DP的方法做。普通方法稍巧妙，但可想出


~~42	Trapping Rain Water    		46.9%	Hard~~	


**1202	Smallest String With Swaps    		43.9%	Medium**	

note 1202： 需要采用union find做，放到后面写blog


	
25 Reverse Nodes in k-Group    		39.6%	Hard	

~~146	LRU Cache    		30.0%	Medium~~
**note 146: 这题不太会，后面重点复习反复做**


~~470	Implement Rand10() Using Rand7()    		46.0%	Medium~~

note: 这题感觉有点搞笑，使用两次rand7后，按照1-10依次进行排列至40。	

	
1057 Campus Bikes    		58.3%	Medium	

note 1057: 还是不懂，不理解[要用桶排序](https://www.youtube.com/watch?v=R5OzU68vTKs)


~~670	 Maximum Swap    		41.7%	Medium~~
note 670: 此题非常好，用到了一些int string之类转换的函数，需及时复习**Level 1**

	
~~31 Next Permutation    		31.8%	Medium~~

note 31: 注意O(n)的做法，找到非递增的点，再往回找的方法



~~445	 Add Two Numbers II    		52.8%	Medium~~
note 445: 注意下用diff的写法更方便进行判断	



329	 Longest Increasing Path in a Matrix    		42.2%	Hard	



317	 Shortest Distance from All Buildings    		40.1%	Hard	



~~777	Swap Adjacent in LR String    		34.7%	Medium~~
note 777: 做法有点意思，可以再复习一下	


	
~~33  Search in Rotated Sorted Array    		33.6%	Medium~~	
note 33: 先确定好mid的所在区间，再分类。考虑好等于的时候。


	
~~71 Simplify Path     		31.1%	Medium~~

note 71: 注意使用vector的pop_back用法和string的substr用法，**注意弹出前要判断是否为空**。	



23	Merge k Sorted Lists    		38.3%	Hard	

~~143	Reorder List    		34.4%	Medium~~

note 143: 自己只做出了O(N^2)的做法，非最优解,**需要重新写几遍最优解法**


~~215	Kth Largest Element in an Array    		52.5%	Medium~~

note 215: 取巧用了个sort函数，需要多复习一下quickselect的方法

	
~~54  Spiral Matrix    		32.8%	Medium~~

note 54: 搞定!注意为空的时候要重新判断。


~~11	 Container With Most Water    		49.0%	Medium~~	


 ~~160	Intersection of Two Linked Lists    37.9%	Easy~~

 note 160: 需要注意一下两种解题方法以及List的用法


~~2	Add Two Numbers    		32.8%	Medium~~

note 2: 自己的写法比较复杂，最好复习时看一下昂写的方法	


~~236	Lowest Common Ancestor of a Binary Tree     		42.6%	Medium~~

note 160: 练习递归和树的很不错的一道题，需要及时复习，**Level 1**	


~~3	Longest Substring Without Repeating Characters    		29.6%	Medium~~
note 3: 比较巧妙，及时复习



~~199	Binary Tree Right Side View    		51.7%	Medium~~

note 199: 自己写出来了


	
41 First Missing Positive    		30.8%	Hard	

	
~~21   Merge Two Sorted Lists    		51.4%	Easy~~	

note 21:注意一下新建一个ListNode写法


~~958	Check Completeness of a Binary Tree    		51.2%	Medium~~
note 958: **需要重新复习，Level1** (hint:BFS+设定标志seennull)


~~286	Walls and Gates    		52.3%	Medium~~	

note 286: 有点疑惑更新的地方，晚上请教下xxx


79	Word Search    		33.7%	Medium	

~~314	Binary Tree Vertical Order Traversal    		43.3%	Medium~~

note 314: **需要重新复习，Level1** (hint:采用map<int,vector<int>>和queue<pair<int, TreeNode*>>+bfs)	

~~1	Two Sum    		45.1%	Easy~~

note 1: 用到了hash map存储，可以一次循环做完	



~~103	Binary Tree Zigzag Level Order Traversal    		45.3%	Medium~~

note 103: **用的bfs，没写最优解，复习时重新过一遍**
	
~~206  Reverse Linked List    		59.8%	Easy~~

note 206: 和标准做法还不太一样，复习的时候用交换的方式做

	
~~53     Maximum Subarray    		45.7%	Easy~~

note 53: 没有一开始想到方法，和dp的思想有点像，需要及时复习	


~~347	Top K Frequent Elements    		59.0%	Medium~~

note 347: 采用了最大堆，了解priority_queue<pair<int, int>>的排列方法，了解最小堆priority_queue<int, vector<int>, greater<int>>的写法。

~~695	Max Area of Island    		60.5%	Medium~~

**note 695: 要重点复习DFS这类题目**	


72	Edit Distance    		41.3%	Hard	

~~232	 Implement Queue using Stacks    		47.1%	Easy~~

note 232: 采用了两个stack，第二个用于调整顺序


~~209	Minimum Size Subarray Sum    		36.7%	Medium~~

note 209: 方法比较巧妙，双指针，及时复习,**Level 1**	


~~15	3Sum    		25.7%	Medium~~	
	
~~415	Add Strings    		46.0%	Easy~~

note 415: WA了一次，值得注意


295	Find Median from Data Stream    		41.3%	Hard	


10	Regular Expression Matching    		26.2%	Hard	
	
~~83 Remove Duplicates from Sorted List    		44.3%	Easy~~

note 83:注意一个末尾小的细节


~~124	Binary Tree Maximum Path Sum    		32.3%	Hard~~
note 124: 挺有意思的一道题目，不难，但需反复复习 **Level 1**	

152	Maximum Product Subarray    		30.8%	Medium	

**note 152: 很特别的DP题，不是特别理解还**

	
~~167 Two Sum II - Input array is sorted    		52.7%	Easy~~


~~543	 Diameter of Binary Tree     		48.2%	Easy~~	

**note 543: 树还是不熟练，要重点复习**	

~~198	 House Robber    		41.6%	Easy~~

note: 采用 dp的方法做的	

~~104	 Maximum Depth of Binary Tree    		64.1%	Easy~~	

note 104: 和543思想一样

~~73	Set Matrix Zeroes    		42.1%	Medium~~	

131

132

~~134	Gas Station    		36.8%	Medium~~

note 134: 比较神奇，直接从j开始走，注意正积累

~~136	Single Number    		63.1%	Easy~~

note 136: 异或

137	Single Number II    		48.7%	Medium

322	Coin Change    		33.8%	Medium	


~~328	Odd Even Linked List    		52.3%	Medium~~

note 328: 可以再好好想一下，even要知道的只是它的next。

~~496	Next Greater Element I    		62.3%	Easy~~
note 496: 用到了栈来求next greater元素

~~716	Max Stack    		42.1%	Easy~~
note 716: 注意用一个stack只保存最大值，最后pop的时候可以直接调用内部函数，完成对max_stack的更新。 	


~~860	Lemonade Change    		51.1%	Easy~~	


862	Shortest Subarray with Sum at Least K    		23.3%	Hard	




