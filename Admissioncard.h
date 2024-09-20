#ifndef ADMISSIONCARD_H
#define ADMISSIONCARD_H
#include "LinkList.h"
#include <iomanip>
class Card
{
public:
    Card( string Name="����", string Admission="00000000", string Id="00000000", string Gender="��");// ���캯����ʼ��
    void Set(string Name,string Gender,string Id,string Admission);                                 //  ���ú���
    friend ostream & operator<<(ostream &out, const Card &b);                                       //  ��������غ���
    friend class School;                                                                            //  ��Ԫ��
    bool operator<(const Card& other) const {
        return admission < other.admission; // ����׼��֤�Ž��бȽ�
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
    string name,admission,id;                                                                       //������׼��֤�ţ����֤��
    string gender;                                                                                  //�Ա�
};
class School
{
public:
    School(string Schoolname="����");                                    //���캯��
    void Set(string Schoolname);                                         //���ú���
    operator string() const;                                             //�����ַ�������
    void Show(ostream &out) const;                                       //��ʾѧУ����
    friend ostream & operator<<(ostream &out, const School &s);          //�������������
    void Display(std::ostream &out) const;                               //��ʾѧУ������Ϣ
    void AppendCard(const Card &c);                                      //׷��׼��������
    void SortCards(const Card &c,bool ascending_num);
    string schoolname;                                                   //ѧУ����
    LinkList<Card>link;                                                  //������
};

#endif
