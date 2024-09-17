#include "admissioncard.h"
#include <iomanip>
#include<string>
Card::Card( string Name, string Admission, string Id, string Gender):name(Name),admission(Admission),id(Id),gender(Gender){

}                                                                              //构造函数

void Card:: Set(string Name,string Gender,string Id,string Admission){         //赋值
	name=Name;
	admission=Admission;
	id=Id;
	gender=Gender;
}


ostream & operator<<(ostream &out, const Card &c)                              //按行输出姓名，性别身份证号，准考证号
{
 
	out << c.name ;
	out<<'\t'<< c.gender ;
	out<< '\t'<< c.id;
	out<<'\t' <<setw(9)<<c.admission;
	return out;
}
School::School(string Schoolname):schoolname(Schoolname) {       //构造函数

}
void School::AppendCard(const Card &c)                                        
{

	Card y(c);                                               //创建新对象y 
//	link.GoBottom();
	link.Append(y);				                 //追加节点
}

void School::Set(string Schoolname){                             //赋值
	schoolname=Schoolname;
}
void School:: Display(std::ostream &out) const
{
	out << "该校考生信息：" << std::endl;
	link.PutList(out);                                     
}
School::operator string() const                                  //确保学校名称以string输出
{
	return schoolname;
}
void School::Show(ostream &out) const                          
{
	out << "学校名称：" << schoolname << endl;
}
ostream & operator<<(ostream &out, const School &s)
{
	s.Show(out);
	out << "姓名\t性别\t身份证号\t 准考证号" << endl;
	s.link.PutList(out);                                     //输出链表
	return out;
}
