/*
 * By	: Alisa
 * Date	: 15-08-04
 *
 * A linked list is given such that each node contains an additional random pointer
 * which could point to any node in the list or null.
 * Return a deep copy of the list.
 */

#include <iostream>
using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x=-1) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        
        RandomListNode *p = head;
        while (p)
        {// 先复制节点并连在其后，形如A-A'-B-B'-C-C'.....
            RandomListNode *New = new RandomListNode(p->label);
            RandomListNode *next = p->next;
            
            p->next = New;
            New->next = next;
            
            p = next;
        }
        
        p = head;
        while (p)
        {// 逐个复制原节点的random指针，与原节点的位置关系间接保证了节点的唯一性(原节点的next就是对应新节点)
            RandomListNode *R = p->random;
            p->next->random = R ? R->next : 0;
            p = p->next->next;
        }
        
        p = head;
        RandomListNode * ret = head->next, *r = ret;
        while (r)
        {// 将列表分离成两个表并返回新表
            p->next = r->next;
            r->next = p->next ? p->next->next : 0;
            
            p = p->next;
            r = r->next;
        }
        return ret;
    }
};

void out(RandomListNode *p)
{
	while(p)
	{
		cout << p->label << "\t";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Solution S;
	RandomListNode p[10];
	p[0].label = 1; p[0].next = &p[1]; p[0].random = &p[3];
	p[1].label = 2; p[1].next = &p[2]; p[1].random = &p[6];
	p[2].label = 3; p[2].next = &p[3]; p[2].random = 0;
	p[3].label = 4; p[3].next = &p[4]; p[3].random = &p[2];
	p[4].label = 5; p[4].next = &p[5]; p[4].random = 0;
	p[5].label = 6; p[5].next = &p[6]; p[5].random = &p[4];
	p[6].label = 7; p[6].next = 0;	   p[6].random = &p[6];
	
	

	cout << "Label\tnext\tranddom\n";

	for (int i=0; i<7; ++i)
		cout << p[i].label << "\t" << p[i].next - &p[0] << "\t" << p[i].random - &p[0] << endl;
	
	RandomListNode *r = S.copyRandomList(&p[0]);
	cout << endl;
	for (int i=0; i<7; ++i)
		cout << p[i].label << "\t" << p[i].next - &p[0] << "\t" << p[i].random - &p[0] << endl;
	cout << endl;
	for (; r; r=r->next)
	{
		cout << r->label << "\t" << r->next - r << "\t" << r->random - r << endl;
	}
	return 0;
}