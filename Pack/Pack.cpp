#include "Pack.h"

Pack::Pack(const String &pn, const String &dn,const String &ud):PackName(pn),DireName(dn),UnPackName(ud),content(NULL),size(0),rootName(_T("//"))
{

}
Pack::~Pack()
{

}

void Pack::GitInfo(String &name)
{
	//��ȡ��ǰĿ¼���ļ�����Ŀ¼�嵥
	Directory dire(name);
	vector <SystemFile *> sy;
	dire.list(sy);

	

	//��ӡ����
	for (int k = 0; k < sy.size(); ++k)
	{
		String tempString = sy[k]->getFullName();
		printMessage3(_T("--:%s"), tempString.getCStr());
	}


	//���ļ�Ŀ¼���д��
	for (int i = 0; i < sy.size(); i++)
	{
		

		INFO inf;
		memset(inf.name, 0, 100);
		memset(inf.path, 0, 100);
		sy[i]->getName().copy(inf.name,sy[i]->getName().getLength());
		sy[i]->getFullName().copy(inf.path, sy[i]->getFullName().getLength());
		inf.type = GettType(sy[i]->getFullName());
		inf.len = GetLen(sy[i]->getFullName());

		info.push_back(inf);

		if (SystemFile::isDirectory(sy[i]->getFullName()))
		{
			GitInfo(sy[i]->getFullName());
		}
		


	}
}

void Pack::PackFileandDire()
{
	GitInfo(DireName);
	File file(PackName);
	if (file.exists())
		file.remove();

	
	//���ⲿ��Ϣд����ļ�
	size = info.size();
	cout << "�ļ��ܸ�����" << size << endl;
	int se = 0,be = 0,cc = 0;
	for (int i = 0; i < size; i++)
	{
		FileOutputStream fout(PackName, APPEND_MODE);
		DataOutputStream out(&fout);
		out.write((unsigned char *)&info[i], sizeof(INFO));
		
		
		//д���ļ�����
		if (info[i].type == 1)
		{
			
			FileInputStream fin(info[i].path);
			DataInputStream in(&fin);
			unsigned char *buf = new unsigned char[info[i].len];
			memset(buf, 0, info[i].len);
			in.read(buf, info[i].len);
			
			
			
			//д����ļ�
			
			FileOutputStream fout1(PackName, APPEND_MODE);
			DataOutputStream out1(&fout1);
			out1.write(buf, info[i].len);
			
			
			
			
		}
		
		
	}
	
	
}

void Pack::UnPackFileandDire()
{
	//������Ŀ¼


	File file(PackName);
	INFO ii;
	FileInputStream fin(PackName);
	DataInputStream in(&fin);
	//��ȡ������
	SetRoot(DireName);
	String dr = UnPackName + "\\" + rootName,na;
	//������Ŀ¼
	Directory root(dr);
	root.create();

	int i = size;
	while (i--)
	{
		fin.seek(0, CURRENT_ORIGIN);
		in.read((unsigned char *)&ii, sizeof(INFO));
		//Ŀ¼
		if (ii.type == 2)
		{
			na = ii.path;
			na.replace(0, DireName.getLength(), dr);
			printMessage(na);
			Directory dd(na);
			dd.create();
		}
		//�ļ�
		if (ii.type == 1)
		{
			na = ii.path;
			na.replace(0, DireName.getLength(), dr);

			printMessage(na);
			File ff(na);
			if (ff.exists())
				ff.remove();
			ff.create();

			//��ȡ����

			unsigned char *buf = new unsigned char[ii.len];
			memset(buf, 0, ii.len);

			in.read(buf, ii.len);

			FileOutputStream fout1(na, APPEND_MODE);
			DataOutputStream out1(&fout1);

			out1.write(buf, ii.len);

		}
	}
	
	

	
	
}



int Pack::GettType(String &name)
{
	//�ļ����
	if (SystemFile::isFile(name))
	{
		return 1;
	}
	//Ŀ¼���
	else if(SystemFile::isDirectory(name))
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int Pack::GetLen(String &name)
{
	
	//�ļ����
	if (SystemFile::isFile(name))
	{
		
		File ff(name);
		return ff.getLength();
	}
	//Ŀ¼���
	else if (SystemFile::isDirectory(name))
	{
		return 0;
	}
	else
	{
		return 0;
	}
}

void Pack::SetRoot(String &name)
{
	Directory dire(name);
	rootName = dire.getName();
}