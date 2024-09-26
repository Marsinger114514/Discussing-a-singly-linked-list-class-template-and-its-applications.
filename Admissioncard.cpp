#include "admissioncard.h"
#include <iomanip>
#include<string>
Card::Card( string Name, string Admission, string Id, string Gender):name(Name),admission(Admission),id(Id),gender(Gender){

}                                                                              //构造函数

void Card:: Set(string Name,string Gender,string Id ,string Admission){         //赋值
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
void School::SortCards(const Card &c,bool ascending_num) {

	Card y(c);
	link.Sort(y,ascending_num);
}
ostream & operator<<(ostream &out, const School &s)
{
	s.Show(out);
	out << "姓名\t性别\t身份证号\t 准考证号" << endl;
	s.link.PutList(out);                                     //输出链表
	return out;
}

Card* School::FindCardByAdmission(const string& admission) {
	Node<Card>* current = link.GoTop();  // 获取链表头结点
	while (current != nullptr) {
		if (current->data.GetAdmission() == admission) {  // 比较准考证号
			return &(current->data);  // 找到后返回对应的 Card 对象
		}
		current = link.Skip();  // 移动到下一个节点
	}
	return nullptr;  // 未找到则返回 nullptr
}

bool School::RemoveCardByAdmission(const string& admission) {
	Node<Card>* prev = nullptr;
	for (Node<Card>* current = link.GoTop(); current != nullptr; current = link.Skip()) {
		if (current->data.GetAdmission() == admission) {
			if (prev == nullptr) {
				// 删除头节点
				link.DeleteHead();
			} else {
				// 删除中间或尾节点
				prev->next = current->next;
				delete current; // 释放内存
			}
			return true; // 删除成功
		}
		prev = current;
	}
	return false; // 未找到准考证
}