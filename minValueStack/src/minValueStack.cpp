//============================================================================
// Name        : minValueStack.cpp
// Author      : ukiah
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <malloc.h>

#define MAX 50

typedef int DataType;

typedef struct{
	DataType data[MAX];
	int top;
}SeqStack;

using namespace std;

class Solution{

public:
	SeqStack *createemptystacks(){
		SeqStack *s;
		s=(SeqStack *)malloc(sizeof(SeqStack));
		s->top=0;
		return s;
	}
	int stackemptys(SeqStack *s){
		return s->top==0;
	}
	int stackfulls(SeqStack *s){
		return s->top==MAX;
	}
	void pushs(SeqStack *s,DataType x){
		if(stackfulls(s))
			cout<<"over flow"<<endl;
		else
			s->data[s->top++]=x;
	}
	void pops(SeqStack *s){
		if(stackemptys(s))
			cout<<"underflow"<<endl;
		else
			s->top--;
	}
	DataType gettops(SeqStack *s){

		return s->data[s->top-1];
	}
};

int main() {

		int i=0,N,price,min=-1;
		Solution *sa=new Solution();
		SeqStack *s1=sa->createemptystacks();
		SeqStack *s2=sa->createemptystacks();

	    cout<<"输入帽子的个数："<<endl;
	    cin>>N;
	    if(N>MAX){
	    	cout<<"超出限制"<<endl;
	    	return 0;
	    }

	    cout<<"分别输入每顶帽子的价格："<<endl;
	    while(i<N&&cin>>price){
	    	if(-1==min)min=price;
	    	if(min>price){
	    		min=price;
	    		cout<<"--";
	    		sa->pushs(s2,price);
	    	}
	    	sa->pushs(s1,price);
	        i++;
	    }
//	    for(int a=0;a<2;a++){
//	    	if(sa->stackemptys(s2)){
//	    		cout<<-1<<endl;
//	    	}
//	    	else
//	    		sa->pops(s2);
//	    }
	    if(!sa->stackemptys(s2))
	    	cout<<sa->gettops(s2)<<endl;
	    else
	    	cout<<-1<<endl;
	return 0;
}
