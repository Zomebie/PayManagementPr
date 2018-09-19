#pragma once
#include<iostream>
#include<string>
using namespace std;

class UserDB {

	string name;      //이름
	string position;   //직급
	string department;   //부서
	string userNum;      //사원번호 
	string password;      //비밀번호 
	double salary;      //급여
	int age;         //나이


public:

	UserDB * next;      //자기참조포인터,public으로 정해야 외부에서 사용가능

	UserDB() {

		next = NULL;

	}


	void setName(string name)
	{
		this->name = name;
	}
	string getName()const {
		return name;
	}

	void setAge(int age)
	{
		this->age = age;
	}
	int getAge()const {
		return age;
	}

	void setNum(string userNum)
	{
		this->userNum = userNum;
	}
	string getNum()const {

		return userNum;
	}

	void setPass(string password)
	{
		this->password = password;
	}
	string getPass()const {

		return password;
	}

	void setDepartment(string department)
	{
		this->department = department;
	}
	string getDepartment()const {
		return department;
	}

	void setPosition(string position)
	{
		this->position = position;
	}
	string getPosition()const {
		return position;
	}

	void setSalary(double salary)
	{
		this->salary = salary;
	}
	double getSalary()const {
		return salary;
	}


};
