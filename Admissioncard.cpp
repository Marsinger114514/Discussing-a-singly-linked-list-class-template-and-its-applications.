#include "Admissioncard.h"
#include <iomanip>
Card::Card( string Name, string Admission, string Id, char Gender):name(Name),admission(Admission),id(Id),gender(Gender){

}                                                                                 //初始化

void Card::Set(string Name,char Gender,string Admission,string Id){
    name=Name;
    admission=Admission;
    id=Id;
    gender=Gender;
}


ostream & operator<<(ostream &out, const Card &c)
{
    out << setfill('0');
    out << c.name << setw(2) << c.gender <<  c.id << c.admission<<'\t';       //输出考生信息
    return out;
}
////////////////////////////
School::School( string Schoolname):schoolname(Schoolname){

}
void School::Set(string Schoolname){                //初始化
    schoolname=Schoolname;
}
void School::AppendCard(const Card &c)
{
    Card y(c);                                  //创建新对象
    link.GoBottom();                            //指针指向链表末尾
    link.Append(y);				    //在表尾追加准考证信息结点
}
void School:: Display(std::ostream &out) const
{
    out << "该校考生准考证信息：" << std::endl;
    link.PutList(out);                          //输出准考证信息链表
}
School::operator string() const
{
    return schoolname;
}
void School::Show(ostream &out) const
{
    out << "学校：" << schoolname << endl;
}
ostream & operator<<(ostream &out, const School &s)
{
    s.Show(out);                                //显示学校名称
    out << "   姓名\t性别\t身份证号\t准考证号" << endl;
    s.link.PutList(out);                        //输出考生准考证信息链表
    return out;
}