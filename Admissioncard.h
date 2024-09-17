#ifndef ADMISSIONCARD_H
#define ADMISSIONCARD_H
#include "LinkList.h"
#include <iomanip>
#include <string>


class school;

class Card                                        //准考证类
{
public:
    Card(const char* Name="匿名",char Gender='女', const char* Admission="00000000", const char* Id="00000000" ); //构造函数
    void Set(const char* Name,char Gender,const char* Admission,const char* Id);   //设置准考证信息
    friend ostream & operator<<(ostream &out, const Card &c);       //重载输出流运算符函数
    friend class School;

private:
    string name,admission,id;                  //姓名，准考证号，身份证号
    char gender;                               //性别
};

class School //学校类
{
public:
    School(const char* Schoolname="匿名");       //构造函数
    void Set(const char* Schoolname);              //设置学校信息
    operator string() const;                  //转换School对象类型为string
    void Show(ostream &out) const;            //显示不同学校的链表
    friend ostream & operator<<(ostream &out, const School &s);   //重载输出流运算符函数
    void AppendCard(const Card &c);           //追加考生准考结点
    void Display(ostream &out) const;    //显示同一学校的不同考生准考证信息的链表

private:
    string schoolname;                         //学校名称
    LinkList<Card> link;
};

#endif