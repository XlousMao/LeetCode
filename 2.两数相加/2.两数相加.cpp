// 2.两数相加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret=new ListNode();
        ListNode* i=l1;
        ListNode* l=l2;
        ListNode* end = ret;
        int jinwei=0;
        while(i!=NULL||l!=NULL)
        {
            int num=jinwei;
            if(i!=NULL)
            {
                num+=i->val;
            }
            if(l!=NULL)
            {
                num+=l->val;
            }
            jinwei=num/10;
            num%=10;
            ret->next=new ListNode(num);
            ret=ret->next;
            if(i!=NULL)
            {
                i=i->next;
            }
            if(l!=NULL)
            {
                l=l->next;
            }
        }
        if(jinwei!=0)
        {
            ret->next=new ListNode(jinwei);
        }
        return end->next;
    }
};
int main()
{
    ListNode*l1=new ListNode(2,new ListNode(4,new ListNode(3)));
    ListNode*l2=new ListNode(5,new ListNode(6,new ListNode(4)));
    Solution s;
    ListNode* ret=s.addTwoNumbers(l1,l2);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
