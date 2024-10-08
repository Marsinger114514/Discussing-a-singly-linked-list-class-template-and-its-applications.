#ifndef ADMISSIONCARD_H
#define ADMISSIONCARD_H
#include "LinkList.h"
#include <iomanip>
class Card
{
public:
    Card( string Name="匿名", string Admission="00000000", string Id="00000000", string Gender="男");// 构造函数初始化
    void Set(string Name,string Gender,string Id,string Admission);                                 //  设置函数
    friend ostream & operator<<(ostream &out, const Card &b);                                       //  输出流重载函数
    friend class School;                                                                            //  友元类
    string GetAdmission() const {                                                                   //  获取准考证信息
        return admission;
    }
    bool operator<(const Card& other) const {                                                       //  比较重载函数
        return admission < other.admission;
    }
    bool operator<=(const Card& other) const {
        return admission <= other.admission;
    }
    bool operator>(const Card& other) const {
        return admission > other.admission;
    }
    bool operator>=(const Card& other) const {
        return admission >= other.admission;
    }
private:
    string name,admission,id;                                                                       //姓名，准考证号，身份证号
    string gender;                                                                                  //性别
};
class School
{
public:
    School(string Schoolname="无名");                                     //构造函数
    void Set(string Schoolname);                                         //设置函数
    operator string() const;                                             //重载字符串函数
    void Show(ostream &out) const;                                       //显示学校名称
    friend ostream & operator<<(ostream &out, const School &s);          //重载输出流函数
    void Display(std::ostream &out) const;                               //显示学校考生信息
    void AppendCard(const Card &c);                                      //追加准考生类结点
    void SortCards(const Card &c,bool ascending_num);                    //排序准考证信息
    Card* FindCardByAdmission(const string& admission);                  //根据准考证信息寻找准考证结点
    bool RemoveCardByAdmission(const string& admission);                 //移除准考证结点
    string ReturnSchoolname(const Node<School>* p) {                     //返回学校名称
        return p->data.schoolname;
    }
private:
    string schoolname;                                                   //学校名称
    LinkList<Card>link;                                                  //准考证链表类
};

#endif
