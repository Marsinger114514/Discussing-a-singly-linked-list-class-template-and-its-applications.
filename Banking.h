// Banking.h
#ifndef BANKING_H
#define BANKING_H
#include "LinkList.h"
#include <iomanip>

class User;	// ��ǰ����

class BWB	// Bank water bills������ˮ�˵�
{
public:
	BWB(int Year=2020, int Month=1, int Day=1, double Money=0);
	void Set(int Year, int Month, int Day, double Money);
	operator double() const;
	friend ostream & operator<<(ostream &out, const BWB &b);
	friend class User;

private:
	int year, month, day;		// ��ˮ������
	double money, balance;		// ������ˮ�˵��������
};

class User
{
public:
	User(const char *ID="00003721", const char *Name="NoName");
	void Set(const char *ID, const char *Name);
	operator string() const;
	void AppendBWB(const BWB &b);
	void Show(ostream &out) const;
	friend ostream & operator<<(ostream &out, const User &u);

private:
	string id, name;		// �˺š�����
	LinkList<BWB> link;		// ����(���˻�����ˮ��¼)
};

#endif
