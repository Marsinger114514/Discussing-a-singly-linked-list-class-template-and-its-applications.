#include <conio.h>
#include "Admissioncard.h"
#include "linklist.h"
using namespace std;
void AdmissionTest()
{
    LinkList<School> uLink;
    School x_school;
    Node<School> *pU;
    Card x_card;
    char schoolname[80],name[80],admission[80],id[80],gender,str[80];                  //ѧУ����������׼��֤�ţ����֤�ţ��Ա�
    int choice;
    while(true)
    {
        cout << "\n������ѧУ(��������λ���֣�ֱ�ӻس����˳�)��";
        cin.getline(schoolname, 80);
        if(schoolname[0] == '\0'){
            cout << "�˳�¼�����" << endl;
            break;
        }
        else{
            x_school.Set(schoolname);
            cout << "����ѧУ����Ϊ: " << x_school << endl;
        }

        pU = uLink.Locate(string(x_school), true);

        if(pU==nullptr)
        {
            cout << "ѧУ�����������" << endl;
            continue;
        }

        while(true)
        {
            cout << endl;
            uLink.CurData().Show(cout);
            cout << "0 -- ¼��׼��֤����" << endl;
            cout << "1 -- ��ѯ" << endl;
            cout << "2 -- ����" << endl;
            cout << "��ѡ��";
            choice = getche() - '0';
            cout << endl;
            if(choice == 2) break;
            switch (choice)
            {
                case 0:
                    cout << "�����루ѧ������ ѧ���Ա� ѧ��׼��֤�� ѧ�����֤�ţ�: ";
                    cin.ignore();  // ���Ի������еĻ��з�
                    cin >> name >> gender >> admission >> id;
                    cin.ignore();  // ���������Ļ��з�
                    x_card.Set(name, gender, admission, id);
                    uLink.CurData().AppendCard(x_card);
                    break;
                case 1:
                    cout << uLink.CurData() << endl; break;
                default:
                    cout << "��Чѡ�������ѡ��" << endl;
                    break;
            }
        }
    }
    cout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}