#ifndef ADMISSIONCARD_H
#define ADMISSIONCARD_H
#include "LinkList.h"
#include <iomanip>
class School;

class Card
{
public:
    Card( string Name="noname", string Admission="00000000", string Id="no id", string Gender="m");
    void Set(string Name,string Gender,string Id,string Admission);
    friend ostream & operator<<(ostream &out, const Card &b);
    friend class School;

private:
    string name,admission,id;
    string gender;
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
    void AppendCard(const Card &c);
private:
    string schoolname;
    LinkList<Card>link;
};

#endif
