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
    char schoolname[80],name[80],admission[80],id[80],str[80];
    char gender;                  //ѧУ����������׼��֤�ţ����֤�ţ��Ա�
    int choice;
    while(true)
    {
        cout << "\n������ѧУ(��������λ���֣�ֱ�ӻس����˳�)��";
        cin.getline(schoolname, 80);
        if (schoolname[0] == '\0') {
            cout << "�˳�¼�����" << endl;
            break;
        }
        else{
            x_school.Set(schoolname);
            cout << "����ѧУ����Ϊ: "<< schoolname << endl;
            uLink.Append(x_school);
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
            cout << "1 -- ¼��׼��֤����" << endl;
            cout << "2 -- ��ѯ" << endl;
            cout << "0-- ����" << endl;
            cout << "��ѡ��";
            choice = getche() - '0';
            cout << endl;
            if(choice <= 0) break;
            switch (choice)
            {
                case 1:
                    cout << "�����루ѧ������ ѧ���Ա� ѧ��׼��֤�ţ�8λ�� ѧ�����֤�ţ�8λ����: ";
                    cin >> name >> gender >> admission >> id;
                    cin.getline(str, 80);
                    x_card.Set(name, gender, admission, id);
                    uLink.CurData().AppendCard(x_card);
                    break;
                case 2:
                    cout << uLink.CurData() << endl; break;
            }
        }
    }
    wcout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}