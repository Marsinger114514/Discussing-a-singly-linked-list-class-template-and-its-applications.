#include <bits/stdc++.h>
#include "Admissioncard.h"
#include "linklist.h"
using namespace std;
void schoolTest()
{
	LinkList<school> uLink; //ѧУ���� 
	School xschool;
	Node<School> *pU;    //�������ѧУ�Ƿ������������ 
	Card xcard;
	string name;
	string Admission;
	string Id;
	char Gender;
	
		while(true)
		{
			cout<<"1 -- ����ѧУ" <<endl; //���AppendCard 
			cout<<"2 -- ��ѯѧУ" <<endl;
			cout<<"3 --չʾѧУ"<<endl;//���display 
			int choice;
			cin>>choice;
			cout<<endl;
			if(choice<=0) break;
			switch(choice)
			{
				case 1:
					cout << "������ѧУ����: ";
					cin>>name>>Admission>>Id>>Gender;
					xcard.Set(name,Admission,Id,Gender);
					uLink.AppendCard(xcard);               //������֪��Ϊ�� 
					break;
				case 2:	findschool(); break;
			
			case 3:xschool.Display(cout); break;
			}
	}

void findschool()
{
	School xschool;
	cout << "����ѧУ���ƣ�";
		cin>>name;
		xschool.Set(name);   
	pU = uLink.Locate(string(xschool), true);            //������֪��Ϊ�� 
	if(pU==NULL)
	{
		cout << "û�����ѧУ" << endl;
	}
}

LinkList <Card> ulink;

void addCard()     //���� Card.Set ��Card.Card 
{
	string Name; string Admission; string Id ;char Gender;
	cout<<"������������"<<endl; 
	cout<<"������׼��֤�ţ�"<<endl; 
	cout<<"��������ţ�"<<endl;
	cout<<"�������Ա�"<<endl; 
	cout<<"1--��  2--Ů"<<endl; 
	cin>>Name>>Admission>>Id>>Gender;
	
	Card card;
	card.Set(Name,Admission,Id,Gender); //���캯����ʼ����׼��֤ 
	ulink.Append(card);   //������β����ڵ� 
}
 
void showcard()  //����������ӽڵ��Ƿ�������Ч 
{
	ulink.ShowList();
}

void findcard()   //���ostream 
{
	Node <Card> *pu;    //�����������׼��֤���Ƿ��������� 
	Card card;
	cout<<"������׼��֤�ţ�"<<endl;
	string admission;
	cin>>admission;
	card.Set("noname",admission,"00000",1);      
	pu=ulink.Locate(string(card),true ); //���                     //��䱨������֪��Ϊʲô 
	if(pu==NULL)
	{
		cout<<"���޴���"<<endl; 
	}
	else cout<<pu;    //�������ѯ����Ϣ 
}

void admissiontest()
{
	cout<<"��ѡ��"<<endl;
	cout<<"1--�½�׼��֤��Ϣ"<<endl;
	cout<<"2--չʾ����׼��֤��Ϣ"<<endl; 
	cout<<"3--��ѯ׼��֤��Ϣ"<<endl;
	int choice;
	cin>>choice;
	switch (choice)
	{
		case 1: addcard();
		case 2: showcard();
		case 3: findcard();
	 } 
	
}
