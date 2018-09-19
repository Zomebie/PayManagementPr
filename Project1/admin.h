#pragma once
#include<iostream>
#include<string>
#include"userDB.h"
using namespace std;

class Admin {

	//UserDB�� �ʵ�
	string name;
	string position;
	string department;
	string userNum;
	string password;
	double salary;
	int age;

	//�����ڸ��� �ʵ�
	string adminID;
	string pass;

	//������ �ʵ�

	UserDB *root;	 // menu���� ���� ������Ŭ������ �ּ� ���� �ʵ�
	UserDB *cur;
	UserDB *del;
	UserDB *new1;
	UserDB *head;


public:

	// Admin ������
	Admin(UserDB* root) {

		this->root = root; //menu���� UserDB�� ����Ű�� �������� �ּҸ� �޾Ƽ� �ʵ忡 �ʱ�ȭ ���ֱ�
		head = root;
		del = NULL;
		new1 = NULL;

		adminID = "1";
		pass = "1";

	}

	// ������ �α���
	bool loginID(string adminID) {

		if (this->adminID == adminID)
			return true;
		else return false;
	}


	bool loginPass(string pass) {

		if (this->pass == pass)
			return true;
		else return false;

	}

	// ������  �޴�
	void adminMode() {

		int a;   //������ ��� ����ġ�� ����

		cout << "[������ ����Դϴ�.] " << endl;
		cout << "1. ����� �߰� 2. ����� ��ȸ 3. ����� ���� 4. ����� ��������" << endl;
		cin >> a;

		switch (a)
		{
		case 1:createNode(); break;
		case 2:search(); break;
		case 3:deleteUser(); break;
		case 4:update(); break;
		default: cout << "�߸��� �Է��Դϴ�." << endl; break;
		}
	}

	// userDB ��ü �����ϱ�
	void createNode() {

		new1 = new UserDB;
		new1->next = NULL;

		if (head->next == NULL)
		{   //��ü ó�� ���� ��

			head->next = new1;
			setUserDB();   //��忡 ������ �ֱ�

		}
		else
		{
			cur = head->next;
			while (cur->next != NULL)   //������ ��ü���� Ŀ�� �ű��
			{
				cur = cur->next;
			}

			cur->next = new1;
			setUserDB();
		}

	}

	// ��ü �� �� �ֱ�
	void setUserDB() {

		cout << "��� �̸��� �Է��ϼ���:";
		cin >> name;
		setUserName(name);

		cout << "������ �Է��ϼ���:";
		cin >> position;
		setUserPosition(position);

		cout << "�μ��� �Է��ϼ���:";
		cin >> department;
		setUserDepartment(department);

		cout << "�����ȣ�� �Է��ϼ���:";
		cin >> userNum;
		setUserNum(userNum);

		cout << "��й�ȣ�� �Է��ϼ���:";
		cin >> password;
		setUserPass(password);

		cout << "�޿��� �Է��ϼ���:";
		cin >> salary;
		setUserSalary(salary);

		cout << "���̸� �Է��ϼ���:";
		cin >> age;
		setUserAge(age);

		cout << "*����ڰ� �߰��Ǿ����ϴ�.*" << endl;
	}

	//�������� �ʵ带 ������Ŭ����(UserDB)�� ���ͷ� ������
	void setUserName(string name) {
		new1->setName(name);
	}

	void setUserPosition(string position) {
		new1->setPosition(position);
	}
	void setUserDepartment(string department) {
		new1->setDepartment(department);
	}
	void setUserNum(string userNum) {
		new1->setNum(userNum);
	}
	void setUserPass(string pass) {
		new1->setPass(pass);
	}
	void setUserSalary(double salary) {
		new1->setSalary(salary);
	}
	void setUserAge(int age) {
		new1->setAge(age);
	}

	// 2. ����� ��ȸ
	void search() {

		int number;         //��ü��ȸ ������ȸ ���� ����ġ����
		string checking_ID;   //������ȸ ���̵� ��ȸ����

		cout << "1.��ü��ȸ  2.������ȸ" << endl;
		cin >> number;

		switch (number)
		{
		case 1:
		{

			cout << " ---- ��ü ��� ����Ʈ ---- " << endl;

			if (head->next == NULL)
			{   //��尡 �ϳ��� ���� ��

				cout << " * ��ϵ� ����� �����ϴ�. *" << endl;
				return;
			}
			cur = head->next;
			while (cur != NULL)   //��ü���
			{
				cout << cur->getNum() << "\t" << cur->getName() << "\t" << cur->getAge() << "\t" << cur->getDepartment() << "\t" << cur->getPosition() << "\t" << cur->getSalary() << "\t" << cur->getPass() << endl;
				cur = cur->next;
			}

		}break;



		case 2:
		{
			cout << "��ȸ�ϰ� ���� �����ȣ�� �Է����ּ��� :";
			cin >> checking_ID;

			if (head->next == NULL)
			{   //��尡 �ϳ��� ���� ��

				cout << " * ��ϵ� ����� �����ϴ�. *" << endl;
				return;
			}

			cur = head->next;
			while (cur != NULL)
			{
				if (checking_ID == cur->getNum())
				{
					cout << cur->getNum() << "\t" << cur->getName() << "\t" << cur->getAge() << "\t" << cur->getDepartment() << "\t" << cur->getPosition() << "\t" << cur->getSalary() << "\t" << cur->getPass() << endl;
					return;
				}
				cur = cur->next;
			}

			cout << " * ��ϵ� ����� �����ϴ�. *" << endl;

		}break;


		default: cout << " * �߸��� �Է��Դϴ�. *" << endl; break;

		}
	}



	// 3. ����� ����
	void deleteUser()
	{
		string checking_ID;   //���� �ϰ� ���� ��ȣ �ޱ�

		if (head->next == NULL)   //��ü�� �ϳ��� ���� ��
		{
			cout << " * ������ ����� �����ϴ�.* " << endl;
			return;
		}

		cout << "������ �����ȣ�� �Է��ϼ���: ";
		cin >> checking_ID;

		cur = head->next;
		if (checking_ID == cur->getNum())// �� ó�� ��ü�� ������ ���
		{
			if (cur->next == NULL)  // ��ó�� �Ѱ� ����
			{
				del = cur;
				head->next = NULL;
				delete(del);
				cout << "�����ȣ " << checking_ID << " �� �����Ǿ����ϴ�." << endl;
				return;
			}
			else
			{
				del = cur;
				cur = cur->next;
				del->next = NULL;
				head->next = cur;
				delete(del);
				cout << "�����ȣ " << checking_ID << " �� �����Ǿ����ϴ�." << endl;
				return;

			}


		}

		cur = head->next;
		while (cur->next != NULL)
		{

			if (checking_ID == cur->next->getNum())
			{
				del = cur->next;
				cur->next = del->next;
				del->next = NULL;
				delete(del);
				cout << "�����ȣ " << checking_ID << "�� �����Ǿ����ϴ�." << endl;
				return;

			}

			cur = cur->next;


		}// while

		cout << "��ϵ� �����ȣ�� �������� �ʽ��ϴ�." << endl;


	}// delete


// 4. ����� ��������
	void update() {

		string checking_ID;   //���� �ϰ� ���� ��ȣ �ޱ� 

		if (head->next == NULL)//��ü�� �ϳ��� ���� ��
		{

			cout << " * ��ϵ� ����� �����ϴ�. *" << endl;
			return;
		}
		cout << "������ �����ȣ�� �Է��ϼ���: ";
		cin >> checking_ID;

		cur = head->next;
		while (cur != NULL)
		{


			if (checking_ID == cur->getNum())
			{
				cout << "��� �̸��� �Է��ϼ���:";
				cin >> name;
				cur->setName(name);

				cout << "������ �Է��ϼ���:";
				cin >> position;
				cur->setPosition(position);

				cout << "�μ��� �Է��ϼ���:";
				cin >> department;
				cur->setDepartment(department);

				cout << "�����ȣ�� �Է��ϼ���:";
				cin >> userNum;
				cur->setNum(userNum);

				cout << "��й�ȣ�� �Է��ϼ���:";
				cin >> password;
				cur->setPass(password);

				cout << "�޿��� �Է��ϼ���:";
				cin >> salary;
				cur->setSalary(salary);

				cout << "���̸� �Է��ϼ���:";
				cin >> age;
				cur->setAge(age);

				cout << "*��� ������ �����Ǿ����ϴ�.*" << endl;
				return;
			}
			cur = cur->next;
		}// while

		cout << "��ϵ� �����ȣ�� �������� �ʽ��ϴ�." << endl;
	}// update
};