// Main.cpp
#include "LinkList.h"
#include <cstring> 
#include <conio.h>

int Pos(char ch, const char *str)			// ����ָ���ַ�ch���ַ���str�е��±ꡣ������ʱ����-1
{
	int i;
	for(i=0; str[i]!='\0'; i++)
		if(ch==str[i])
			return i;
	return -1;
}

int Choice(const char *prompt, const char *options="");	// ��������
int Choice(const char *prompt, const char *options)		// �������塣�����ʾ��Ϣprompt������ѡ����ַ������ء�
{
	int key;
	cout << prompt << "{";
	for(int i=0; options[i]!='\0'; i++)
	{
		if(' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// ѡ��options�еĿɴ�ӡ�ַ�
			cout << options[i] << ' ';
		else														// ѡ��options�еĲ��ֿ����ַ�
		{
			switch(options[i])
			{
			case '\t':   cout << "[Tab] ";   break;					// ѡ���е�Tab�ַ�'\t'����ASCII����9��
			case '\x1b': cout << "[Esc] ";   break;					// ѡ���е�Esc�ַ�'\x1b'����ASCII����27��
			case ' ':    cout << "[Space] "; break;					// ѡ���еĿո��ַ�' '����ASCII����32��
			}
		}
	}
	cout << "\b}: ";					// '\b'�˸�����һ��������һ�����
	do
	{
		key = getch();
	}while(options[0]!='\0' && Pos(key, options)<0); // ��optionsΪ�ճ���Ϊ0���ַ����������������ƣ�����������Ӧ����optins�С�
	cout << endl;
	return key;
}

int main()
{
	void test1(),test2(), test3(), AddressBookTest(), BankingTest();
	int key;
	while(true)
	{
		cout << "\n\n\t����������ģ�����" << endl;
		cout << "1 --- ������󣨰���������������졢��������׼I/O���ļ�I/O" << endl;
		cout << "2 --- �����㡢����/�������ҡ����á������쳣�����޸�(�滻)����" << endl;
		cout << "3 --- Լɪ��(Josephus)����(���Ե�ǰ��㶨λ���������ƴ���)" << endl;
		cout << "4 --- ͨѶ¼���Ͳ���" << endl;
		cout << "5 --- ģ��洢��ҵ��" << endl;
		key = Choice("\n��ѡ��", "12345\x1b");
		cout << "\n\n";
		if(key==27)		// '\x1b'����27��ָESC��
			break;
		switch(key)
		{
		case '1':	test1();			break;
		case '2':	test2();			break;
		case '3':	test3();			break;
		case '4':	AddressBookTest();	break;
		case '5':	BankingTest();		break;
		}
	}
	return 0;
}
