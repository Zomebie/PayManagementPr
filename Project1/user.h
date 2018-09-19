#pragma once
#include<iostream>
#include<string>
#include"userDB.h"
using namespace std;

class User {  // �α��ΰ� ��ȸ

		   // �����忡���� �ش� ����� ��ȸ ����

	string checking_ID; // �˻����̵�

	UserDB *root;	//menu���� ���� ������Ŭ������ �ּ� ���� �ʵ�
	UserDB *cur;
	UserDB *head;

public:

	User(UserDB* root) {

		this->root = root;
		head =root;


	}

	// ����� �α��� 0�̸� ���� 
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

		if (head ->next == NULL) {   //��ü�� �ϳ��� ���� ��

			cout << " * ��ϵ� ����� �����ϴ�. *" << endl;
			return;
		}

		cout << cur->getNum() << "\t" << cur->getName() << "\t" << cur->getAge() << "\t" << cur->getDepartment() << "\t" << cur->getPosition() << "\t" << cur->getSalary() << "\t" << cur->getPass() << endl;

	}

};
