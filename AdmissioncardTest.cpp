#include <conio.h>
#include "Admissioncard.h"
#include "linklist.h"
#include <string>
using namespace std;

void AdmissionTest()
{
    LinkList<School> uLink;          //定义链表和结点
    School x_school;
    Node<School> *pU,*p1;
    Card x_card;
    int p, i, choice;                // 用于序号，循环，选择行为
    string schoolname, name, admission, id, gender; // 学校名，姓名，准考证号，身份证号，性别
    bool continueMainLoop = true;   // 定义一个变量用于控制循环

    L1:while (continueMainLoop)
    {
        cout << "\n请输入学校(请输入汉字，直接回车则退出)：";
        getline(cin, schoolname);
        if (schoolname.empty()) { // 改成检查字符串是否为空
            continueMainLoop = false; // 设置为 false 表示退出循环
            break;
        }
        else {
            x_school.Set(schoolname);
            cout << "学校名称为: " << schoolname << endl;
            bool addOrNot = true;                           // 定义变量判断是否要增加新学校结点
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

         pU = uLink.Locate(string(x_school), true);     // 找到结点的位置

        if (pU == nullptr)
        {
            cout << "学校名称输入错误！" << endl;
            continue;
        }

        bool continueSubLoop = true;            // 定义一个变量用于控制循环

        while (continueSubLoop)
        {
            cout << endl;
            try {
                uLink.CurData().Show(cout);
            }catch (int) {
                cout << "当前删除操作无法进行，恢复初始" << endl;
                goto L1;
            }

            cout << "1 -- 录入准考证数据" << endl;
            cout << "2 -- 查询该校考生信息" << endl;
            cout << "3 -- 查询所有考生信息" << endl;
            cout << "4 -- 排序该校考生信息" << endl;
            cout << "5 -- 删除当前结点" << endl;
            cout << "6 -- 修改当前结点" << endl;
            cout << "0 -- 返回" << endl;
            cout << "请选择：";
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
                    cout << "请输入（学生姓名 学生性别 学生身份证号（8位） 学生准考证号（8位））: ";   //录入准考证数据
                    cin >> name >> gender >> id >> admission;
                    cin.ignore();
                    if(uLink.CurData().FindCardByAdmission(admission)!=nullptr) {
                        cout << "该准考证已存在，请重新输入" << endl;
                        goto L2;
                    }
                    x_card.Set(name, gender, id, admission);
                    uLink.CurData().AppendCard(x_card);
                }
                break;
            case 2:
                    cout << uLink.CurData() << endl;            //输出
                break;
            case 3:
                {
                    cout << "所有考生信息：" << endl;
                    p = uLink.CurPos();
                    for (uLink.GoTop(),i=1; ; uLink.Skip(),i++)   //循环遍历输出
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
                    cout << "请选择排序方式（根据准考证号排序   “1”：升序，“2”：降序）"<< endl;   //排序操作
                    int ascending_num = getche() - '0';
                    if (ascending_num==1||ascending_num==2) {
                        bool ascending = (ascending_num == 1);
                        uLink.CurData().SortCards(x_card,ascending);
                        cout << uLink.CurData() << endl;
                    }else {
                        cout << "无效的选择，请重新输入！" << endl;
                    }
                }
                break;
            case 5:
                {
                    cout << "请选择删除方式 （“1”； 根据学校，“2”：根据准考证号）" << endl;     //删除学校或准考证结点
                    int DeleteChoice = getche() - '0';
                    cout << endl;
                    if (DeleteChoice == 1) {                                        //按学校删除
                        cout << "请输入学校名: ";
                        string schoolnameToDelete;
                        getline(cin, schoolnameToDelete);
                        p1 = uLink.Locate(string(schoolnameToDelete), true);
                        if (p1 != nullptr) {
                            uLink.DeleteCurNode();
                            cout << "学校为 " << schoolnameToDelete << " 的考生信息已删除！" << endl;
                            if(uLink.GoTop() == nullptr) {
                                cout << "全部学校结点已删除，返回到初始" << endl;
                                goto L1;
                            }
                        }else  {
                            cout << "未找到学校为 " << schoolnameToDelete << " 的考生信息！" << endl;
                        }

                    }else if (DeleteChoice == 2) {
                        cout << "请输入准考证号: ";        // 按准考证号删除
                        string admissionToDelete;
                        cin >> admissionToDelete;
                        bool cardFound = false;
                        for (pU = uLink.GoTop(); pU != nullptr; pU = uLink.Skip()) {
                            try {if (pU->data.RemoveCardByAdmission(admissionToDelete)) {       // 调用学校的删除准考证方法
                                cout << "准考证号 " << admissionToDelete << " 的考生信息已删除！" << endl;
                                cardFound = true;
                                break;
                            }
                            }catch (int){
                                cout << "无结点可以删除" << endl;
                            }
                        }

                        if (!cardFound) {
                            cout << "未找到准考证号为 " << admissionToDelete << " 的考生信息！" << endl;
                        }
                    }else {
                        cout << "无效的选择，请重新输入！" << endl;
                    }
                }
                break;
            case 6:
                {
                    cout << "请选择修改类型（1: 修改学校信息，2: 修改准考证信息）：";           // 修改当前结点
                    int modifyChoice = getche() - '0';
                    cout << endl;
                    if (modifyChoice == 1) {
                        cout << "请输入新的学校名称: ";                                    // 修改学校信息
                        getline(cin, schoolname);
                        uLink.CurData().Set(schoolname);
                        cout << "当前学校名称已修改为: " << schoolname << endl;
                    } else if (modifyChoice == 2) {
                        cout << "请输入要修改的准考证号: ";                                // 修改准考证信息
                        cin >> admission;
                        cin.ignore();
                        Card* card = uLink.CurData().FindCardByAdmission(admission);
                        if (card != nullptr) {
                            cout << "请输入新的信息（学生姓名 学生性别 学生身份证号（8位） 学生准考证号（8位））: ";
                            cin >> name >> gender >> id >> admission ;
                            card->Set(name, gender,id , admission);
                            cout << "准考证信息已更新！" << endl;
                        } else {
                            cout << "找不到该准考证号的学生！" << endl;
                        }
                    } else {
                        cout << "无效的选择，请重新输入！" << endl;
                    }
                }
                break;
            default:
                    cout << "无效的选择，请重新输入！" << endl;
                break;
            }
        }
    }

    cout << "\n自动调用析构函数释放所有结点，返回主函数。\n" << endl;
}

