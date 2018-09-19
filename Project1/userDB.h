#pragma once
#include<iostream>
#include<string>
using namespace std;

class UserDB {

	string name;      //�̸�
	string position;   //����
	string department;   //�μ�
	string userNum;      //�����ȣ 
	string password;      //��й�ȣ 
	double salary;      //�޿�
	int age;         //����


public:

	UserDB * next;      //�ڱ�����������,public���� ���ؾ� �ܺο��� ��밡��

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
