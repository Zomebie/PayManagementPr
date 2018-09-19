#pragma once
#include<iostream>
#include<string>
#include"userDB.h"
using namespace std;

class User {  // 로그인과 조회

		   // 사원모드에서는 해당 사원만 조회 가능

	string checking_ID; // 검색아이디

	UserDB *root;	//menu에서 받은 데이터클래스의 주소 저장 필드
	UserDB *cur;
	UserDB *head;

public:

	User(UserDB* root) {

		this->root = root;
		head =root;


	}

	// 사용자 로그인 0이면 거짓 
	bool loginID(string userNum) {

		cur = head->next;
		while (cur != NULL)
		{
			if (userNum == cur->getNum()) {

				return true;

			}
			cur = cur->next;
		}

		return false;

	}


	bool loginPass(string pass) {

		cur = head->next;

		while (cur != NULL) {
			if (pass == cur->getPass()) {

				return true;

			}
			cur = cur->next;

		}
		return false;

	}


	void userSearch() {

		if (head ->next == NULL) {   //객체가 하나도 없을 시

			cout << " * 등록된 사원이 없습니다. *" << endl;
			return;
		}

		cout << cur->getNum() << "\t" << cur->getName() << "\t" << cur->getAge() << "\t" << cur->getDepartment() << "\t" << cur->getPosition() << "\t" << cur->getSalary() << "\t" << cur->getPass() << endl;

	}

};
