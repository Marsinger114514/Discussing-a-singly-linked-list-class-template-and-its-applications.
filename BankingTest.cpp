// BankingTest.cpp
#include "LinkList.h"
#include "Banking.h"
#include <conio.h>

void BankingTest()
{
	LinkList<User> uLink;
	User xUser;
	Node<User> *pU;
	BWB xBWB;
	char id[80], name[80], str[80];
	int choice, year, month, day;
	double money;

	while(true)
	{
		cout << "\n�������˺�(n�˺�--������ֱ�ӻس����˳�)��";
		cin.getline(id, 80);
		if(id[0] == '\0')
			break;
		if(id[0]=='N' || id[0]=='n')
		{
			cout << "�����뻧����";
			cin.getline(name, 80);
			xUser.Set(id+1, name);
			uLink.Append(xUser);
		}
		else
			xUser.Set(id, "");
		pU = uLink.Locate(string(xUser), true);
		if(pU==NULL)
		{
			cout << "�˺��������" << endl;
			continue;
		}

		while(true)
		{
			cout << endl;
			uLink.CurData().Show(cout);
			cout << "1 -- ���루������/֧ȡ��������" << endl;
			cout << "2 -- ��ѯ" << endl;
			cout << "0 -- ����" << endl;
			cout << "��ѡ��";
			choice = getche() - '0';
			cout << endl;
			if(choice<=0) break;
			switch(choice)
			{
			case 1:
					cout << "�����루�� �� �� ��: ";
					cin >> year >> month >> day >> money;
					cin.getline(str, 80);					// �������ַ�
					xBWB.Set(year, month, day, money);
					uLink.CurData().AppendBWB(xBWB);
					break;
			case 2:	cout << uLink.CurData() << endl; break;
			}
		}
	}
	cout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}
