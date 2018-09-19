#pragma once
#include<iostream>
#include<string>
#include"admin.h"
#include"user.h"
#include"userDB.h"
using namespace std;

class Menu {

	Admin *admin;   //관리자
	User *user;      //사원

	UserDB* root;

	string adminID; //관리자용 입력아이디
	string adminPass;   //관리자용 입력패스워드

	string userNum;   //사원용 입력사원번호
	string userPass;   //사원용 입력패스워드

	int a;

public: Menu() {

	root = new UserDB();		// 더미노드 만들기
	root->next = NULL;
	admin = new Admin(root);   //관리자에게 데이터 클래스(더미노드주소) 넘겨주기
	user = new User(root);   // 사용자에게 똑같은 주소 넘겨주기

	menu();


}

		void menu() {

			while (1)
			{
				cout << "===== 급여관리 프로그램입니다.=====" << endl;
				cout << "1. 관리자 모드  " << "\t" << "2. 사용자 모드" << endl;
				cin >> a;

				switch (a)
				{

				case 1:
				{
					cout << "관리자ID를 입력하세요 => ";
					cin >> adminID;

					if (admin->loginID(adminID))
					{

						cout << "비밀번호를 입력하세요 => ";
						cin >> adminPass;

						if (admin->loginPass(adminPass))
						{


							cout << " *** Login Success *** " << endl;
							// 관리자 모드
							admin->adminMode();

						}
						else
						{

							cout << "비밀번호가 틀렸습니다." << endl; continue;
						}
					}
					else
					{

						cout << "관리자ID가 틀렸습니다." << endl; continue;
					}
				}break;

				case 2:
				{
					cout << "사원번호를 입력하세요 => ";
					cin >> userNum;

					if (user->loginID(userNum))
					{

						cout << "비밀번호를 입력하세요 => ";
						cin >> userPass;

						if (user->loginPass(userPass))
						{


							cout << " *** User Login Success *** " << endl;

							// 사용자 조회모드
							user->userSearch();

						}


						else
						{

							cout << "비밀번호가 틀렸습니다." << endl; continue;
						}

					}
					else
					{
						cout << "사원번호가 존재하지 않습니다. " << endl;
					}

				} break;

				default: cout << "잘못된 입력입니다." << endl; break;

				}


			}

		}
};