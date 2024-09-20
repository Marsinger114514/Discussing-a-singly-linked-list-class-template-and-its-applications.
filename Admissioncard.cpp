#include "admissioncard.h"
#include <iomanip>
#include<string>
Card::Card( string Name, string Admission, string Id, string Gender):name(Name),admission(Admission),id(Id),gender(Gender){

}                                                                              //���캯��

void Card:: Set(string Name,string Gender,string Id,string Admission){         //��ֵ
	name=Name;
	admission=Admission;
	id=Id;
	gender=Gender;
}


ostream & operator<<(ostream &out, const Card &c)                              //��������������Ա����֤�ţ�׼��֤��
{
 
	out << c.name ;
	out<<'\t'<< c.gender ;
	out<< '\t'<< c.id;
	out<<'\t' <<setw(9)<<c.admission;
	return out;
}
School::School(string Schoolname):schoolname(Schoolname) {       //���캯��

}
void School::AppendCard(const Card &c)                                        
{

	Card y(c);                                               //�����¶���y 
//	link.GoBottom();
	link.Append(y);				                 //׷�ӽڵ�
}

void School::Set(string Schoolname){                             //��ֵ
	schoolname=Schoolname;
}
void School:: Display(std::ostream &out) const
{
	out << "��У������Ϣ��" << std::endl;
	link.PutList(out);                                     
}
School::operator string() const                                  //ȷ��ѧУ������string���
{
	return schoolname;
}
void School::Show(ostream &out) const                          
{
	out << "ѧУ���ƣ�" << schoolname << endl;
}
void School::SortCards(const Card &c,bool ascending_num) {

      Card y(c);
	link.Sort(y,ascending_num);
}
ostream & operator<<(ostream &out, const School &s)
{
	s.Show(out);
	out << "����\t�Ա�\t���֤��\t ׼��֤��" << endl;
	s.link.PutList(out);                                     //�������
	return out;
}
