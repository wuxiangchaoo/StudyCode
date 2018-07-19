#pragma once
#include<iostream>
#include<list>
#include <fstream>
#include<string>

#define _PATH_INIT "./login.ini"
#define _PATH_GOODS "./goods.txt"

using namespace std;

struct msg
{
	int id;
	string name;
	int price;
	int num;
};
class Information
{
public:
	Information();
	~Information();

	//��ȡ��¼��Ϣ
	void ReadLogin(CString &name, CString &pwd);

	//�޸�����
	void WritePwd(char *name, char *pwd);

	//��ȡ��Ʒ����
	void ReadDocline();

	//��Ʒд���ļ�
	void WriteDocline();

	//�������Ʒ
	void Addline(CString name, int num, int price);

	list<msg> ls;
	int num;

};

