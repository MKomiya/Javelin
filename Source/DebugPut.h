/**
 * �f�o�b�O�p��log.txt�ɕ������f���o���N���X�B
 */
#pragma once
#include <string>
#include <fstream>
using namespace std;

class DebugPut
{
public:
	/**
	 * ���O�t�@�C���̓��e��S�ď�������B
	 */
	void LogClear()
	{
		ofstream ofs;
		ofs.open("log.html", ios_base::out | ios_base::trunc );
		ofs.close();
	}

	void LogInit()
	{
		ofstream ofs;
		string str;
		ofs.open("log.html", ios_base::out | ios_base::trunc );

		str = "<HTML><HEAD><TITLE>DEBUG LOG</TITLE><STYLE><!--BODY{font-size:12px; font-family:\"MS �S�V�b�N\";}--></STYLE></HEAD><BODY>";
		ofs.write(str.c_str(), str.size());

		ofs.close();
	}

	void LogEnd()
	{
		ofstream ofs;
		string str;
		ofs.open("log.html", ios_base::out | ios_base::app );
		
		str = "</BODY></HTML>";
		ofs.write(str.c_str(), str.size());
		
		ofs.close();
	}
	/**
 	 * ���O�t�@�C���̖��[�ɕ��������s�������ށB
	 */
	void PutLog(string s)
	{
		ofstream ofs;

		string str("�@�@�@�@");
		str += s;
		str += "<BR>";

		ofs.open("log.html", ios_base::out | ios_base::app );
		ofs.write(str.c_str(), str.size());
		ofs.close();
	}

	void PutLogTopic(string s)
	{
		ofstream ofs;

		string str("<BR><TABLE width=\"100%\" bgcolor=\"#2222aa\"><TBODY><TR><TD align=\"center\"><B><FONT color=\"WHITE\">");
		str += s;
		str += "</FONT></B></TD></TR></TBODY></TABLE><BR>";

		ofs.open("log.html", ios_base::out | ios_base::app );
		ofs.write(str.c_str(), str.size());
		ofs.close();
	}
};