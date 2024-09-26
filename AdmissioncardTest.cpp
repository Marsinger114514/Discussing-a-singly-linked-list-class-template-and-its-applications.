#include <conio.h>
#include "Admissioncard.h"
#include "linklist.h"
#include <string>
using namespace std;

void AdmissionTest()
{
    LinkList<School> uLink;          //��������ͽ��
    School x_school;
    Node<School> *pU,*p1;
    Card x_card;
    int p, i, choice;                // ������ţ�ѭ����ѡ����Ϊ
    string schoolname, name, admission, id, gender; // ѧУ����������׼��֤�ţ����֤�ţ��Ա�
    bool continueMainLoop = true;   // ����һ���������ڿ���ѭ��

    L1:while (continueMainLoop)
    {
        cout << "\n������ѧУ(�����뺺�֣�ֱ�ӻس����˳�)��";
        getline(cin, schoolname);
        if (schoolname.empty()) { // �ĳɼ���ַ����Ƿ�Ϊ��
            continueMainLoop = false; // ����Ϊ false ��ʾ�˳�ѭ��
            break;
        }
        else {
            x_school.Set(schoolname);
            cout << "ѧУ����Ϊ: " << schoolname << endl;
            bool addOrNot = true;                           // ��������ж��Ƿ�Ҫ������ѧУ���
            for (pU = uLink.GoTop(),i=1; pU != nullptr; pU = uLink.Skip(),i++) {
                if(schoolname==x_school.ReturnSchoolname(pU)) {
                    addOrNot=false;
                    break;
                }
                if(i==uLink.NumNodes())
                    break;
            }
            if(addOrNot) {
                uLink.Append(x_school);
            }
        }

         pU = uLink.Locate(string(x_school), true);     // �ҵ�����λ��

        if (pU == nullptr)
        {
            cout << "ѧУ�����������" << endl;
            continue;
        }

        bool continueSubLoop = true;            // ����һ���������ڿ���ѭ��

        while (continueSubLoop)
        {
            cout << endl;
            try {
                uLink.CurData().Show(cout);
            }catch (int) {
                cout << "��ǰɾ�������޷����У��ָ���ʼ" << endl;
                goto L1;
            }

            cout << "1 -- ¼��׼��֤����" << endl;
            cout << "2 -- ��ѯ��У������Ϣ" << endl;
            cout << "3 -- ��ѯ���п�����Ϣ" << endl;
            cout << "4 -- �����У������Ϣ" << endl;
            cout << "5 -- ɾ����ǰ���" << endl;
            cout << "6 -- �޸ĵ�ǰ���" << endl;
            cout << "0 -- ����" << endl;
            cout << "��ѡ��";
            choice = getche() - '0';
            cout << endl;

            if (choice == 0)
            {
                continueSubLoop = false;
                continue;
            }

            switch (choice)
            {
            L2:case 1:
                {
                    cout << "�����루ѧ������ ѧ���Ա� ѧ�����֤�ţ�8λ�� ѧ��׼��֤�ţ�8λ����: ";   //¼��׼��֤����
                    cin >> name >> gender >> id >> admission;
                    cin.ignore();
                    if(uLink.CurData().FindCardByAdmission(admission)!=nullptr) {
                        cout << "��׼��֤�Ѵ��ڣ�����������" << endl;
                        goto L2;
                    }
                    x_card.Set(name, gender, id, admission);
                    uLink.CurData().AppendCard(x_card);
                }
                break;
            case 2:
                    cout << uLink.CurData() << endl;            //���
                break;
            case 3:
                {
                    cout << "���п�����Ϣ��" << endl;
                    p = uLink.CurPos();
                    for (uLink.GoTop(),i=1; ; uLink.Skip(),i++)   //ѭ���������
                    {
                       cout << uLink.CurData() << endl;
                        if(i==uLink.NumNodes())
                            break;
                    }
                    for (uLink.GoTop();p>0;uLink.Skip(),p--)
                        ;
                }
                break;
            case 4:
                {
                    cout << "��ѡ������ʽ������׼��֤������   ��1�������򣬡�2��������"<< endl;   //�������
                    int ascending_num = getche() - '0';
                    if (ascending_num==1||ascending_num==2) {
                        bool ascending = (ascending_num == 1);
                        uLink.CurData().SortCards(x_card,ascending);
                        cout << uLink.CurData() << endl;
                    }else {
                        cout << "��Ч��ѡ�����������룡" << endl;
                    }
                }
                break;
            case 5:
                {
                    cout << "��ѡ��ɾ����ʽ ����1���� ����ѧУ����2��������׼��֤�ţ�" << endl;     //ɾ��ѧУ��׼��֤���
                    int DeleteChoice = getche() - '0';
                    cout << endl;
                    if (DeleteChoice == 1) {                                        //��ѧУɾ��
                        cout << "������ѧУ��: ";
                        string schoolnameToDelete;
                        getline(cin, schoolnameToDelete);
                        p1 = uLink.Locate(string(schoolnameToDelete), true);
                        if (p1 != nullptr) {
                            uLink.DeleteCurNode();
                            cout << "ѧУΪ " << schoolnameToDelete << " �Ŀ�����Ϣ��ɾ����" << endl;
                            if(uLink.GoTop() == nullptr) {
                                cout << "ȫ��ѧУ�����ɾ�������ص���ʼ" << endl;
                                goto L1;
                            }
                        }else  {
                            cout << "δ�ҵ�ѧУΪ " << schoolnameToDelete << " �Ŀ�����Ϣ��" << endl;
                        }

                    }else if (DeleteChoice == 2) {
                        cout << "������׼��֤��: ";        // ��׼��֤��ɾ��
                        string admissionToDelete;
                        cin >> admissionToDelete;
                        bool cardFound = false;
                        for (pU = uLink.GoTop(); pU != nullptr; pU = uLink.Skip()) {
                            try {if (pU->data.RemoveCardByAdmission(admissionToDelete)) {       // ����ѧУ��ɾ��׼��֤����
                                cout << "׼��֤�� " << admissionToDelete << " �Ŀ�����Ϣ��ɾ����" << endl;
                                cardFound = true;
                                break;
                            }
                            }catch (int){
                                cout << "�޽�����ɾ��" << endl;
                            }
                        }

                        if (!cardFound) {
                            cout << "δ�ҵ�׼��֤��Ϊ " << admissionToDelete << " �Ŀ�����Ϣ��" << endl;
                        }
                    }else {
                        cout << "��Ч��ѡ�����������룡" << endl;
                    }
                }
                break;
            case 6:
                {
                    cout << "��ѡ���޸����ͣ�1: �޸�ѧУ��Ϣ��2: �޸�׼��֤��Ϣ����";           // �޸ĵ�ǰ���
                    int modifyChoice = getche() - '0';
                    cout << endl;
                    if (modifyChoice == 1) {
                        cout << "�������µ�ѧУ����: ";                                    // �޸�ѧУ��Ϣ
                        getline(cin, schoolname);
                        uLink.CurData().Set(schoolname);
                        cout << "��ǰѧУ�������޸�Ϊ: " << schoolname << endl;
                    } else if (modifyChoice == 2) {
                        cout << "������Ҫ�޸ĵ�׼��֤��: ";                                // �޸�׼��֤��Ϣ
                        cin >> admission;
                        cin.ignore();
                        Card* card = uLink.CurData().FindCardByAdmission(admission);
                        if (card != nullptr) {
                            cout << "�������µ���Ϣ��ѧ������ ѧ���Ա� ѧ�����֤�ţ�8λ�� ѧ��׼��֤�ţ�8λ����: ";
                            cin >> name >> gender >> id >> admission ;
                            card->Set(name, gender,id , admission);
                            cout << "׼��֤��Ϣ�Ѹ��£�" << endl;
                        } else {
                            cout << "�Ҳ�����׼��֤�ŵ�ѧ����" << endl;
                        }
                    } else {
                        cout << "��Ч��ѡ�����������룡" << endl;
                    }
                }
                break;
            default:
                    cout << "��Ч��ѡ�����������룡" << endl;
                break;
            }
        }
    }

    cout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}

