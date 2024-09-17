#include <bits/stdc++.h>
#include "Admissioncard.h"
#include "linklist.h"
using namespace std;
void schoolTest()
{
	LinkList<school> uLink; //学校链表 
	School xschool;
	Node<School> *pU;    //用来检测学校是否存在于链表中 
	Card xcard;
	string name;
	string Admission;
	string Id;
	char Gender;
	
		while(true)
		{
			cout<<"1 -- 新增学校" <<endl; //检测AppendCard 
			cout<<"2 -- 查询学校" <<endl;
			cout<<"3 --展示学校"<<endl;//检测display 
			int choice;
			cin>>choice;
			cout<<endl;
			if(choice<=0) break;
			switch(choice)
			{
				case 1:
					cout << "请输入学校名称: ";
					cin>>name>>Admission>>Id>>Gender;
					xcard.Set(name,Admission,Id,Gender);
					uLink.AppendCard(xcard);               //报错，不知道为何 
					break;
				case 2:	findschool(); break;
			
			case 3:xschool.Display(cout); break;
			}
	}

void findschool()
{
	School xschool;
	cout << "输入学校名称：";
		cin>>name;
		xschool.Set(name);   
	pU = uLink.Locate(string(xschool), true);            //报错，不知到为何 
	if(pU==NULL)
	{
		cout << "没有这个学校" << endl;
	}
}

LinkList <Card> ulink;

void addCard()     //测试 Card.Set 和Card.Card 
{
	string Name; string Admission; string Id ;char Gender;
	cout<<"请输入姓名："<<endl; 
	cout<<"请输入准考证号："<<endl; 
	cout<<"请输入序号："<<endl;
	cout<<"请输入性别："<<endl; 
	cout<<"1--男  2--女"<<endl; 
	cin>>Name>>Admission>>Id>>Gender;
	
	Card card;
	card.Set(Name,Admission,Id,Gender); //构造函数初始化新准考证 
	ulink.Append(card);   //在链表尾新添节点 
}
 
void showcard()  //用来检验添加节点是否正常生效 
{
	ulink.ShowList();
}

void findcard()   //检测ostream 
{
	Node <Card> *pu;    //用来检测所输准考证号是否在链表中 
	Card card;
	cout<<"请输入准考证号："<<endl;
	string admission;
	cin>>admission;
	card.Set("noname",admission,"00000",1);      
	pu=ulink.Locate(string(card),true ); //检测                     //这句报错，但不知道为什么 
	if(pu==NULL)
	{
		cout<<"查无此人"<<endl; 
	}
	else cout<<pu;    //输出所查询的信息 
}

void admissiontest()
{
	cout<<"请选择："<<endl;
	cout<<"1--新建准考证信息"<<endl;
	cout<<"2--展示所有准考证信息"<<endl; 
	cout<<"3--查询准考证信息"<<endl;
	int choice;
	cin>>choice;
	switch (choice)
	{
		case 1: addcard();
		case 2: showcard();
		case 3: findcard();
	 } 
	
}
