#include "stdafx.h"
#include "Information.h"


Information::Information()
{
}


Information::~Information()
{
}

//��ȡ��¼��Ϣ
void Information :: ReadLogin(CString &name, CString &pwd)
{
	ifstream ino(_PATH_INIT);
	string strname, strpwd;
	getline(ino, strname);
	getline(ino, strpwd);
	name = strname.c_str();
	pwd = strpwd.c_str();
}

//��Ʒд���ļ�
void Information::WriteDocline()
{
	ofstream ofs(_PATH_GOODS);
	if (ls.size()>0)
	{
		ofs << "��ƷID|��Ʒ����|��Ʒ�۸�|���" << endl;
		for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			ofs << it->id << "|";
			ofs << it->name << "|";
			ofs << it->price << "|";
			ofs << it->num << endl;
		}
	}
	ofs.close();
}

//�޸�����
void Information::WritePwd(char *name, char *pwd)
{
	ofstream fileout(_PATH_INIT);//ios::trunc�����ԭ�ļ�����,�ɲ�д,Ĭ�Ͼ�����
	if (!fileout){
		cout << "Create file failure...\n";
		exit(0);
	}
	fileout << name << endl;
	fileout << pwd << endl;
	fileout.close();
}

//��ȡ��Ʒ����
void Information::ReadDocline()
{
	ifstream ifs(_PATH_GOODS);
	char buff[1024] = { 0 };
	num = 0;
	ls.clear();
	ifs.getline(buff, sizeof(buff));//��ȡ��ͷ
	while (!ifs.eof())
	{
		msg tmp;
		ifs.getline(buff, sizeof(buff));
		num++;

		char *sst = strtok(buff,"|");

		if (sst != NULL)
		{
			tmp.id = atoi(sst);
		}
		else
		{
			break;
		}
		sst = strtok(NULL, "|");
		tmp.name = sst;

		sst = strtok(NULL, "|");
		tmp.price = atoi(sst);

		sst = strtok(NULL, "|");
		tmp.num = atoi(sst);
		 
		ls.push_back(tmp);
	}
	ifs.close();
}


//�������Ʒ
void Information::Addline(CString name, int num, int price)
{
	msg tmp;
	if (ls.size() > 0)
	{
		if (!name.IsEmpty() && num > 0 && price > 0)
		{
			tmp.id = ls.size() + 1;
			CStringA str;
			str = name;
			tmp.name = str.GetBuffer();
			tmp.num = num;
			tmp.price = price;
			ls.push_back(tmp);
		}
	}
}
