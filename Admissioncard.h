#ifndef ADMISSIONCARD_H
#define ADMISSIONCARD_H
#include "LinkList.h"
#include <iomanip>


class school;

class Card
{
public:
	Card( string Name="noname", string Admission="00000000", string Id="noid", char Gender='m');
	void Set(string Name,string Admission,string Id,char Gender);
	friend ostream & operator<<(ostream &out, const Card &c);
	friend class School;

private:
	string name,admission,id;
	char gender;		
};

class School
{
public:
	School(string Schoolname="noname");
	void Set(string Schoolname);
	operator string() const;
	void Show(ostream &out) const;
	friend ostream & operator<<(ostream &out, const School &s);
    void Display(std::ostream &out) const; 
   
private:
	string schoolname;
	LinkList<Card> link;
};

#endif
