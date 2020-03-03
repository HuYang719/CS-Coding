/**
 * 题目：滑动窗口的最大值
 * 思路：滑动窗口应当是队列，但为了得到滑动窗口的最大值，队列序可以从两端删除元素，因此使用双端队列。
 *     原则：
 *     对新来的元素k，将其与双端队列中的元素相比较
 *     1）前面比k小的，直接移出队列（因为不再可能成为后面滑动窗口的最大值了!）,
 *     2）前面比k大的X，比较两者下标，判断X是否已不在窗口之内，不在了，直接移出队列
 *     队列的第一个元素是滑动窗口中的最大值
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
    	vector<int> res;
    	deque<int> s;
    	for(int i = 0; i < num.size(); i++) {
    		while(s.size() && numb[s.back()] <= num[i])
    			s.pop_back();
    		while(s.size() && i-s.front()+1 > size) // check the first ele in deque is in the window
    			s.pop_front();
    		s.push_back(i) 
    	}
        
    }
};



class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;
        for(unsigned int i=0;i<num.size();++i){
            while(s.size() && num[s.back()]<=num[i])//从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
                s.pop_back();
            while(s.size() && i-s.front()+1>size)//当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
                s.pop_front();
            s.push_back(i);//把每次滑动的num下标加入队列
            if(size&&i+1>=size)//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
                res.push_back(num[s.front()]);
        }
        return res;
    }
};

int main(){
    
    Solution sol;
    int res = sol.method();
    cout<<"ans:"<<res<<endl;
    getchar();
    return 0;
    
}


// 复杂度分析
// O(2^n)