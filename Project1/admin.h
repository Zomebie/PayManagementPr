#pragma once
#include<iostream>
#include<string>
#include"userDB.h"
using namespace std;

class Admin {

	//UserDB용 필드
	string name;
	string position;
	string department;
	string userNum;
	string password;
	double salary;
	int age;

	//관리자모드용 필드
	string adminID;
	string pass;

	//포인터 필드

	UserDB *root;	 // menu에서 받은 데이터클래스의 주소 저장 필드
	UserDB *cur;
	UserDB *del;
	UserDB *new1;
	UserDB *head;


public:

	// Admin 생성자
	Admin(UserDB* root) {

		this->root = root; //menu에서 UserDB를 가리키는 포인터의 주소를 받아서 필드에 초기화 해주기
		head = root;
		del = NULL;
		new1 = NULL;

		adminID = "1";
		pass = "1";

	}

	// 관리자 로그인
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

	// 관리자  메뉴
	void adminMode() {

		int a;   //관리자 모드 스위치용 변수

		cout << "[관리자 모드입니다.] " << endl;
		cout << "1. 사용자 추가 2. 사용자 조회 3. 사용자 삭제 4. 사용자 정보수정" << endl;
		cin >> a;

		switch (a)
		{
		case 1:createNode(); break;
		case 2:search(); break;
		case 3:deleteUser(); break;
		case 4:update(); break;
		default: cout << "잘못된 입력입니다." << endl; break;
		}
	}

	// userDB 객체 생성하기
	void createNode() {

		new1 = new UserDB;
		new1->next = NULL;

		if (head->next == NULL)
		{   //객체 처음 생성 시

			head->next = new1;
			setUserDB();   //노드에 데이터 넣기

		}
		else
		{
			cur = head->next;
			while (cur->next != NULL)   //마지막 객체까지 커서 옮기기
			{
				cur = cur->next;
			}

			cur->next = new1;
			setUserDB();
		}

	}

	// 객체 안 값 넣기
	void setUserDB() {

		cout << "사원 이름을 입력하세요:";
		cin >> name;
		setUserName(name);

		cout << "직급을 입력하세요:";
		cin >> position;
		setUserPosition(position);

		cout << "부서를 입력하세요:";
		cin >> department;
		setUserDepartment(department);

		cout << "사원번호를 입력하세요:";
		cin >> userNum;
		setUserNum(userNum);

		cout << "비밀번호를 입력하세요:";
		cin >> password;
		setUserPass(password);

		cout << "급여를 입력하세요:";
		cin >> salary;
		setUserSalary(salary);

		cout << "나이를 입력하세요:";
		cin >> age;
		setUserAge(age);

		cout << "*사용자가 추가되었습니다.*" << endl;
	}

	//개인정보 필드를 데이터클래스(UserDB)의 세터로 보내기
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

	// 2. 사용자 조회
	void search() {

		int number;         //전체조회 개인조회 선택 스위치변수
		string checking_ID;   //개인조회 아이디 조회변수

		cout << "1.전체조회  2.개인조회" << endl;
		cin >> number;

		switch (number)
		{
		case 1:
		{

			cout << " ---- 전체 사원 리스트 ---- " << endl;

			if (head->next == NULL)
			{   //노드가 하나도 없을 시

				cout << " * 등록된 사원이 없습니다. *" << endl;
				return;
			}
			cur = head->next;
			while (cur != NULL)   //전체출력
			{
				cout << cur->getNum() << "\t" << cur->getName() << "\t" << cur->getAge() << "\t" << cur->getDepartment() << "\t" << cur->getPosition() << "\t" << cur->getSalary() << "\t" << cur->getPass() << endl;
				cur = cur->next;
			}

		}break;



		case 2:
		{
			cout << "조회하고 싶은 사원번호를 입력해주세요 :";
			cin >> checking_ID;

			if (head->next == NULL)
			{   //노드가 하나도 없을 시

				cout << " * 등록된 사원이 없습니다. *" << endl;
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

			cout << " * 등록된 사원이 없습니다. *" << endl;

		}break;


		default: cout << " * 잘못된 입력입니다. *" << endl; break;

		}
	}



	// 3. 사용자 삭제
	void deleteUser()
	{
		string checking_ID;   //삭제 하고 싶은 번호 받기

		if (head->next == NULL)   //객체가 하나도 없을 시
		{
			cout << " * 삭제할 사원이 없습니다.* " << endl;
			return;
		}

		cout << "삭제할 사원번호를 입력하세요: ";
		cin >> checking_ID;

		cur = head->next;
		if (checking_ID == cur->getNum())// 맨 처음 객체를 삭제할 경우
		{
			if (cur->next == NULL)  // 맨처음 한개 삭제
			{
				del = cur;
				head->next = NULL;
				delete(del);
				cout << "사원번호 " << checking_ID << " 가 삭제되었습니다." << endl;
				return;
			}
			else
			{
				del = cur;
				cur = cur->next;
				del->next = NULL;
				head->next = cur;
				delete(del);
				cout << "사원번호 " << checking_ID << " 가 삭제되었습니다." << endl;
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
				cout << "사원번호 " << checking_ID << "가 삭제되었습니다." << endl;
				return;

			}

			cur = cur->next;


		}// while

		cout << "등록된 사원번호가 존재하지 않습니다." << endl;


	}// delete


// 4. 사용자 정보수정
	void update() {

		string checking_ID;   //삭제 하고 싶은 번호 받기 

		if (head->next == NULL)//객체가 하나도 없을 시
		{

			cout << " * 등록된 사원이 없습니다. *" << endl;
			return;
		}
		cout << "삭제할 사원번호를 입력하세요: ";
		cin >> checking_ID;

		cur = head->next;
		while (cur != NULL)
		{


			if (checking_ID == cur->getNum())
			{
				cout << "사원 이름을 입력하세요:";
				cin >> name;
				cur->setName(name);

				cout << "직급을 입력하세요:";
				cin >> position;
				cur->setPosition(position);

				cout << "부서를 입력하세요:";
				cin >> department;
				cur->setDepartment(department);

				cout << "사원번호를 입력하세요:";
				cin >> userNum;
				cur->setNum(userNum);

				cout << "비밀번호를 입력하세요:";
				cin >> password;
				cur->setPass(password);

				cout << "급여를 입력하세요:";
				cin >> salary;
				cur->setSalary(salary);

				cout << "나이를 입력하세요:";
				cin >> age;
				cur->setAge(age);

				cout << "*사원 정보가 수정되었습니다.*" << endl;
				return;
			}
			cur = cur->next;
		}// while

		cout << "등록된 사원번호가 존재하지 않습니다." << endl;
	}// update
};