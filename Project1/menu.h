#pragma once
#include<iostream>
#include<string>
#include"admin.h"
#include"user.h"
#include"userDB.h"
using namespace std;

class Menu {

	Admin *admin;   //������
	User *user;      //���

	UserDB* root;

	string adminID; //�����ڿ� �Է¾��̵�
	string adminPass;   //�����ڿ� �Է��н�����

	string userNum;   //����� �Է»����ȣ
	string userPass;   //����� �Է��н�����

	int a;

public: Menu() {

	root = new UserDB();		// ���̳�� �����
	root->next = NULL;
	admin = new Admin(root);   //�����ڿ��� ������ Ŭ����(���̳���ּ�) �Ѱ��ֱ�
	user = new User(root);   // ����ڿ��� �Ȱ��� �ּ� �Ѱ��ֱ�

	menu();


}

		void menu() {

			while (1)
			{
				cout << "===== �޿����� ���α׷��Դϴ�.=====" << endl;
				cout << "1. ������ ���  " << "\t" << "2. ����� ���" << endl;
				cin >> a;

				switch (a)
				{

				case 1:
				{
					cout << "������ID�� �Է��ϼ��� => ";
					cin >> adminID;

					if (admin->loginID(adminID))
					{

						cout << "��й�ȣ�� �Է��ϼ��� => ";
						cin >> adminPass;

						if (admin->loginPass(adminPass))
						{


							cout << " *** Login Success *** " << endl;
							// ������ ���
							admin->adminMode();

						}
						else
						{

							cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl; continue;
						}
					}
					else
					{

						cout << "������ID�� Ʋ�Ƚ��ϴ�." << endl; continue;
					}
				}break;

				case 2:
				{
					cout << "�����ȣ�� �Է��ϼ��� => ";
					cin >> userNum;

					if (user->loginID(userNum))
					{

						cout << "��й�ȣ�� �Է��ϼ��� => ";
						cin >> userPass;

						if (user->loginPass(userPass))
						{


							cout << " *** User Login Success *** " << endl;

							// ����� ��ȸ���
							user->userSearch();

						}


						else
						{

							cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl; continue;
						}

					}
					else
					{
						cout << "�����ȣ�� �������� �ʽ��ϴ�. " << endl;
					}

				} break;

				default: cout << "�߸��� �Է��Դϴ�." << endl; break;

				}


			}

		}
};