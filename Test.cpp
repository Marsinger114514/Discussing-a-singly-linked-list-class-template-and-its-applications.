// Test.cpp
#include "LinkList.h"
#include <cstring>
#include <conio.h>

int Pause(const char* prompt = "���������������")
{
	cout << prompt;
	return getch();
}

void test1()				// ������ģ��LinkList�� ���캯�������������������ļ�I/O�������������������������Ե�
{
	int n, iArray[] = {900, 800, 500};					// ׼����int������
	int iN = sizeof(iArray)/sizeof(*iArray);
	
	LinkList<int> iLink0, iLink1(2), iLink2(iN, iArray), iLArray[] = {iLink0, iLink1, iLink2};
			// ����3������������ֱ�Ϊ0, 2, 3�����Լ�һ���������飨Ԫ�ظ���Ϊ3��������������ɵ����飩
	int nLL = sizeof(iLArray)/sizeof(*iLArray);
	LinkList<LinkList<int> > iLLink(nLL, iLArray);
			// �����������������������Ϊ����������

	cout << "\n\n(1.1) ���������һ�ָ�ʽ��" << endl;
	cout << "\tcout << iLink0 << endl;" << endl;	cout << iLink0 << endl;
	cout << "\tcout << iLink1 << endl;" << endl;	cout << iLink0 << endl;
	cout << "\tcout << iLink2 << endl;" << endl;	cout << iLink0 << endl;
	Pause();
	
	cout << "\n\n(1.2) �����������Ԫ��" << endl;
	for(int i=0; i<nLL; i++)
		cout << iLArray[i] << endl;
	Pause();

	cout << "\n\n(1.3) ���������һ�ָ�ʽ��" << endl;
	cout << "\tiLink0.ShowList();" << endl;			iLink0.ShowList();
	cout << "\tiLink1.ShowList();" << endl;			iLink1.ShowList();
	cout << "\tiLink2.ShowList();" << endl;			iLink2.ShowList();
	Pause();

	cout << "\n\n(1.4) ���������������ָ�ʽ��" << endl;
	cout << "\tcout << iLLink << endl;" << endl;	cout << iLLink << endl;
	cout << "\tiLLink.ShowList();" << endl;			iLLink.ShowList();
	Pause();

	cout << "\n\n(1.5) ������������" << endl;
	cout << "\tn = iLLink.Save(\"LLink.txt\");" << endl;
	n = iLLink.Save("LLink.txt");
	cout << "\t" << n << " ���������д���ļ� \"LLink.txt\" ��" << endl;
	Pause();

	cout << "\n\n(1.6) ���ļ��ж�ȡ����ʱ�����������ͷ������е����н��" << endl;
	cout << "\tiLLink.FreeList(); iLLink.ShowList();" << endl;
	iLLink.FreeList();
	iLLink.ShowList();
	cout << "\tn = iLLink.Load(\"LLink.txt\");" << endl;
	n = iLLink.Load("LLink.txt");
	cout << "\t��ȡ " << n << " ��������ݣ�����������ȡ�������" << endl;
	cout << iLLink << endl;
	Pause();

	double dArray[] = {1.414, 2.718, 3.142};					// ׼����double������
	int dN = sizeof(dArray)/sizeof(*dArray);
	LinkList<double> dLink0, dLink1(2), dLink2(dN, dArray);		// ����3������������ֱ�Ϊ0, 2, 3��

	cout << "\n\n(1.7) ������Ϊdouble�����ݲ���" << endl;
	dLink0.ShowList();	cout << dLink0 << endl;
	dLink1.ShowList();	cout << dLink1 << endl;
	dLink2.ShowList();	cout << dLink2 << endl;
	Pause();

	n = dLink2.Save("dLink.txt");
	cout << "\n\n(1.8) ���������ݣ��� " << n << " ���������д���ļ� \"dLink.txt\" ��" << endl;
}

void test2()	// ���Բ��룬����/�������ң��޸ģ��滻�����ݣ����á�����ȳ�Ա����
{
	int iArray[] = {1, 2, 3, 3, 5, 6, 7, 8, 8, 3};
	int n = sizeof(iArray)/sizeof(*iArray);
	LinkList<int> iLink(n, iArray);
	
	cout << "\nԭʼ����" << endl;
	iLink.ShowList();
	cout << "\n\n(2.1) �� 0 ���뵽���׽��ǰ����Ϊ�µ����׽��" << endl;
	iLink.Insert(0);
	iLink.ShowList();
	Pause();

	cout << "\n\n(2.2) �� 100 ���뵽��β���󣬳�Ϊ�µ���β���" << endl;
	iLink.Append(100);
	iLink.ShowList();
	Pause();

	cout << "\n\n(2.3) ����ǰ���������3����㣨��0��ʼ��";
	iLink.Go(3);
	iLink.ShowList();
	Pause();

	cout << "\n\n(2.4) �ڵ�ǰ���ǰ���� 30" << endl;
	iLink.InsertBefore(30);
	iLink.ShowList();
	Pause();

	cout << "\n\n(2.5) �ڵ�ǰ������� 40" << endl;
	iLink.InsertAfter(40);
	iLink.ShowList();
	Pause();

	cout << "\n\n(2.6) ���������㵹��" << endl;
	iLink.Reverse();
	iLink.ShowList();
	Pause();

	cout << "\n\n(2.7) ������������" << endl;
	iLink.Sort(int(0));
	iLink.ShowList();
	Pause();

	cout << "\n\n(2.8) �������򣨽���" << endl;
	iLink.Sort(int(0), false);
	iLink.ShowList();
	Pause();

	cout << "\n\n(2.9) �����쳣�������е�ǰ�����Զ�λ��Ա����Go(n)�����n���ܳ��������" << endl;
	for (int i = iLink.NumNodes() + 1; i > -2; i--)
	{
		cout << "Go(" << i << "): ";
		iLink.Go(i);		// ����ʹcur_nodeΪNULL
		try
		{
			cout << iLink.CurData() << endl;
		}
		catch (int)
		{
			cout << "\t��׽���쳣�������������Χ" << endl;
		}
	}
	Pause();

	int x;
	cout << "\n\n(2.10) �������в��Ҳ��޸ģ��滻�����ݣ�������Ҫ��ѯ������: ";
	cin >> x;
	Node<int> *p;
	p = iLink.Locate(x, true);
	n = 0;
	while(p!=NULL)
	{
		cout << "�ҵ��� " << iLink.CurPos() << " ���(��Ŵ�0��ʼ)��\t" << iLink.CurData() << endl;
		cout << "�޸�Ϊ: ";
		cin >> iLink.CurData();				// �������ñ��ʽ iLink.CurData() ����ֵ������������ֵ
		n++;
		p = iLink.Locate(x);
	}
	cout << "\t���ҵ� " << n << " �������������" << (n>0? "�����������޸ġ�":"��") << endl;
	cout << "\n����ǰ�������Ϊ�׽��" << endl;
	iLink.GoTop();
	iLink.ShowList();
}

void test3()								// ���Ե�ǰ�����Զ�λ����Զ�λ��ɾ����ǰ��㺯��
{
	int n, interval, k = 0, m;
	cout << "\nԼɪ��(Josephus)����" << endl;
	cout << "��n��С��(���1~n)Χ��һȦ���ӵ�1��С����ʼ��˳ʱ�뷽���1~mѭ������������m��С����Ȧ��"
		<< "���ʣ�µ�С��Ϊʤ���ߡ�" << endl;
	cout << "������С������ �����(�� 10 3 ): ";
	cin >> n >> interval;

	if (interval <= 1)
	{
		cout << "�����Ӧ�ô���1���ֵ���Ϊ2��" << endl;
		interval = 2;
	}
	LinkList<int> link;
	for (int i = 1; i <= n; i++)
		link.Append(i);
	link.GoTop();
	cout << "��ʼ̬\t";
	link.ShowList();
	while (link.NumNodes() > 1)
	{
		if (++k == interval)
		{
			m = link.DeleteCurNode();
			cout << m << " ��Ȧ\t";
			if (link.CurNode() == NULL)
				link.GoTop();
			k = 1;
			Pause("");
		}
		else
			cout << "\t";
		link.Skip();
		if (link.CurNode() == NULL)
			link.GoTop();
		link.ShowList();
	}
	cout << "ʤ����: " << link.CurData() << " �š�" << endl;
}
