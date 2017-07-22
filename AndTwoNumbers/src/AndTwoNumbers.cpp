//============================================================================
// Name        : AndTwoNumbers.cpp
// Author      : ukiah
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct ListNode {
      int val;
      ListNode *next;
  }ListNode;

class Solution {
public:
	Solution(){	}


	ListNode* addTwoNumbers(ListNode* pa, ListNode* pb) {
	        ListNode *p,*q,*pc;
	        int flag=0;
	        pc=(ListNode *)malloc(sizeof(ListNode));
	        p=pc;
	        while(pa!=NULL&&pb!=NULL){
	            q=(ListNode *)malloc(sizeof(ListNode));
	            q->val=pa->val+pb->val;
	            if(flag==1){
	                q->val=q->val+1;
	                flag=0;
	            }
	            if(q->val>=10){
	                q->val=q->val%10;
	                flag=1;
	            }
	            p->next=q;
	            p=q;
	            pa=pa->next;
	            pb=pb->next;
	        }
	        if(pa==NULL)pa=pb;
	        while(pa!=NULL){
	            q=(ListNode *)malloc(sizeof(ListNode));
	            q->val=pa->val;
	            if(flag==1){
	                q->val=q->val+1;
	                flag=0;
	            }
	            if(q->val>=10){
	                q->val=q->val%10;
	                flag=1;
	            }
	            pa=pa->next;
	            p->next=q;
	            p=q;
	        }
	        if(flag==1){//注意这条判断语句的位置在while(pa!=NULL)后
	        	 q=(ListNode *)malloc(sizeof(ListNode));
	        	 q->val=1;
	        	 p->next=q;
	        	 p=q;
	        }
	        p->next=NULL;
	        p=pc;
	        pc=p->next;
	        free(p);
	        return(pc);
	    }

    ListNode *createfirst(){
    	ListNode *s,*h;
    	int x,tag;
    	cout<<"输入结束标志："<<endl;
    	cin>>tag;
    	h=NULL;
    	cout<<"输入数据 x："<<endl;
    	cin>>x;
    	while(x!=tag){
    		s=(ListNode *)malloc(sizeof(ListNode));
    		s->val=x;
    		s->next=h;
    		h=s;
    		cin>>x;
    	}
    	return h;
    }

    void LookAllNode(ListNode *pa){
    	ListNode *pb;
    	pb=pa;
    	while(pb!=NULL){
    		cout<<pb->val<<"--";
    		pb=pb->next;
    	}
    	cout<<endl;
    }
};
int main()
{
   cout << "Hello World";
    Solution *sa=new Solution();
   	ListNode *p,*q,*pc;
	p=sa->createfirst();
	q=sa->createfirst();

	sa->LookAllNode(p);
	sa->LookAllNode(q);

	pc=sa->addTwoNumbers(p,q);

	sa->LookAllNode(pc);

   return 0;
}
