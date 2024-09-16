#ifndef ADMISSIONCARD_H
#define ADMISSIONCARD_H
#include "LinkList.h"
#include <iomanip>


class school;

class Card   //准考证类
{
public:
	Card( string Name="noname", string Admission="00000000", string Id="noid", char Gender='m');
	void Set(string Name,string Admission,string Id,char Gender);
	friend ostream & operator<<(ostream &out, const Card &c); //输出重载函数
	friend class School;

private:
	string name,admission,id; //姓名，准考证号，身份证号
	char gender;		
};

class School //学校类
{
public:
	School(string Schoolname="noname");
	void Set(string Schoolname);
	operator string() const;
	void Show(ostream &out) const;
	friend ostream & operator<<(ostream &out, const School &s);
        void Display(std::ostream &out) const; //显示学校的函数
   
private:
	string schoolname;//学校名称
	LinkList<Card> link;
};

#endif
