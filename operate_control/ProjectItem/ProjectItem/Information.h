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

	//读取登录信息
	void ReadLogin(CString &name, CString &pwd);

	//修改密码
	void WritePwd(char *name, char *pwd);

	//读取商品数据
	void ReadDocline();

	//商品写入文件
	void WriteDocline();

	//添加新商品
	void Addline(CString name, int num, int price);

	list<msg> ls;
	int num;

};

