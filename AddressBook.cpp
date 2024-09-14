// AddressBook.cpp
#include "LinkList.h"
#include <iomanip>
#include <cstring>
#include <string>
#include <conio.h>

class AddressBook
{
public:
	AddressBook(int Id=0, const char *Name="NoName", const char *Phone="", const char *Email="") : id(Id)
	{
		strncpy(name, Name, sizeof(name));		// Ϊ�˰�ȫ���ϣ�ָ�����ȿ����ַ���
		name[sizeof(name)-1] = '\0';			// �Կ��ܳ������ַ������нض�
		strncpy(phone, Phone, sizeof(phone));
		phone[sizeof(phone)-1] = '\0';
		email = Email;	// �൱�� email = string(Email); ��C-�ַ���Emailת����stringȻ���ٸ�ֵ�����������ð���﷨��
	}
	friend ostream & operator<<(ostream &out, const AddressBook &a)
	{
		out << setfill('0') << setw(8) << a.id << '\t' << a.name << '\t' 
			<< setfill(' ') << setw(11) << a.phone << '\t' << a.email;
		return out;
	}
	friend istream & operator>>(istream &in, AddressBook &a)
	{
		char str[80];
		in.getline(str, 80, '\t');	a.id = atoi(str);
		in.getline(str, 80, '\t');	strncpy(a.name, str, sizeof(a.name));	a.name[sizeof(a.name)-1] = '\0';
		in.getline(str, 80, '\t');	strncpy(a.phone, str, sizeof(a.phone));	a.phone[sizeof(a.phone)-1] = '\0';
		in.getline(str, 80);		a.email = str;
		return in;
	}
	operator int()		const { return id; 			}	// ����ת�����������������ת��Ϊ int��ָ��ţ�
	operator string()	const { return name;		}	// ����ת�����������������ת��Ϊ C++�ַ���string��ָ������
	operator long long()const { return atoll(phone);}	// ����ת�����������������ת��Ϊ long long��ָ�ֻ����룩
private:
	int id;
	char name[21], phone[12];
	string email;
};

template <typename T>
void Search(LinkList<AddressBook> &link, const T &t)
{
	int n=0;
	Node<AddressBook> *p;
	p = link.Locate(t, true);
	while(p!=NULL)
	{
		n++;
		cout << link.CurData() << endl;
		p = link.Locate(t);
	}
	cout << "�ҵ� " << n << " �����������Ľ��" << endl;
}

void Find(LinkList<AddressBook> &link, int flag)
{
	char str[80];
	switch(flag)
	{
	case '1':	cout << "�������ѯ�ı��: ";
				cin.getline(str, 80);
				Search(link, atoi(str));				break;
				
	case '2':	cout << "�������ѯ������: ";
				cin.getline(str, 80);
				Search(link, string(str));				break;
				
	case '3':	cout << "�������ѯ���ֻ�����: ";
				cin.getline(str, 80);
				Search(link, atoll(str));				break;
	}
}

void AddressBookTest()
{
	int Pos(char ch, const char *str);						// ��������
	int Choice(const char *prompt, const char *options="");	// ��������
	LinkList<AddressBook> link;
	char filename[80] = "AddressBook.txt";
	AddressBook x;
	int key, k, n, yn;
	n = link.Load(filename);
	cout << "\n�Ѵ� " << filename << " �ļ��ж�ȡ�� " << n << " ����������" << endl;

	while(true)
	{
		cout << "\n\n========= ͨѶ¼ =========" << endl;
		cout << "  1 ---- �� �� ͨѶ¼ (P)" << endl;
		cout << "  2 ---- �����µĽ�� (I)" << endl;
		cout << "  3 ---- ׷���µĽ�� (A)" << endl;
		cout << "  4 ---- ��        ѯ (S)" << endl;
		cout << "  5 ---- ��        �� (V)" << endl;
		cout << "  6 ---- ��        �� (O)" << endl;
		cout << "  7 ---- ����д���ļ� (W)" << endl;
		cout << "  8 ---- ��ȡ�����ļ� (R)" << endl;
		cout << "  9 ---- �ͷ����н�� (F)" << endl;
		cout << "  0 ---- ��      �� (ESC)" << endl;
		cout << "==========================" << endl;
		key = Choice("��ѡ��", "0123456789\x1bpPiIaAsSvVoOwWrRfF");
		cout << "\n\n";
		if(key==27 || key=='0')		// '\x1b'����27��ָESC��
			break;
		switch(key)
		{
		case '1':
		case 'p':
		case 'P':	cout << link << endl;							break;
		case '2':
		case 'i':
		case 'I':	cout << "����һ����㵽�����׽��ǰ��" << endl;
					cout << "����������������(���Tab����Tab�ֻ�����TabEmail����): ";
					cin >> x;
					link.Insert(x);									break;
		case '3':
		case 'a':
		case 'A':	cout << "׷��һ�����(��β����)��";
					cout << "����������������(���Tab����Tab�ֻ�����TabEmail����): ";
					cin >> x;
					link.Append(x);									break;
		case '4':
		case 's':
		case 'S':	cout << "�������������ݲ�ѯ���ɸ����������ַ�ʽ��ѯ��" << endl;
					cout << "1 ��ţ�2 ������3 �ֻ����롣��ѡ��: ";
					k = getche();
					Find(link, k);									break;
		case '5':
		case 'v':
		case 'V':	cout << "�������н�㵹�á�����֮ǰ\n" << link << endl;
					link.Reverse();
					cout << "����֮ǰ\n" << link << endl;			break;
		case '6':
		case 'o':
		case 'O':	cout << "������� 1����ţ�2��������3���ֻ����롣��ѡ��: ";
					k = getche();
					switch(k)
					{
					case '1':	link.Sort(int(0));					// ��һ���������ݵ���ֵ����Ҫ����Ҫ������������
								cout << "\n����ţ�����������\n" << link << endl;
								link.Sort(int(0), false);
								cout << "����ţ�����������\n" << link << endl;	break;
					case '2':	link.Sort(string(""));
								cout << "\n������������������\n" << link << endl;
								link.Sort(string(""), false);
								cout << "������������������\n" << link << endl;	break;
					case '3':	link.Sort((long long)(0));
								cout << "\n���ֻ����루����������\n" << link << endl;
								link.Sort((long long)(0), false);
								cout << "���ֻ����루����������\n" << link << endl;	break;
					}
					break;
		case '7':
		case 'w':
		case 'W':	n = link.Save(filename);
					cout << "�� " << n << " ����������д�� "
						 << filename << " �ļ���" << endl;			break;
		case '8':
		case 'r':
		case 'R':	cout << "��ȡ�����ļ����Ƿ����ͷ����е����н��(y/[N])? ";
					yn = getche();
					if(yn=='y' || yn=='Y')
						link.FreeList();	
					n = link.Load(filename);
					cout << "�� " << filename << " �ļ��ж�ȡ "
						 << n << " �����ݡ����� "
						 << link.NumNodes() << " �����" << endl;	break;
		case '9':
		case 'f':
		case 'F':	cout << "�ͷ����н�㡣�Ƿ����(y/[N])? ";
					yn = getche();
					if(yn=='y' || yn=='Y')				// Ĭ�� No
						link.FreeList();							break;
		}
	}
	if(link.NumNodes())
	{
		cout << "\n�������������������������Ƿ����([Y]/n)? ";
		yn = getche();
		if(yn!='n' && yn!='N')							// Ĭ�� Yes
		{
			filename[Pos('.', filename)] = '\0';		// ȥ���ļ���չ��.txt
			strcat(filename, "(1).txt");				// ƴ�ӳ��µ��ļ���
			n = link.Save(filename);
			cout << "\n�ѽ� " << n << " ���������ݴ��� " << filename << " �ļ���" << endl;
		}
	}
	cout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}
