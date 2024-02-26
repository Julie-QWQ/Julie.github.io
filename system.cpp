#include <iostream>
#include <vector>
using namespace std;

class Member
{
public:
	static int number;
	static vector<Member*> vct;
	string name;
	
	Member() //创建对象 
	{
		set_info(); //设置信息 
		++number;
		vct.push_back(this);
	}
	
	~Member() //删除成员 
	{
		cout<<"成功删除成员 "<<name<<" !"<<endl; 
	}
	
	void change_info() //修改信息 
	{
		cout<<"请输入要更改的信息(输入欲更改信息前的数字，或者输入-1表示结束更改)："<<endl;
		change();
	}
	
	void check_info()
	{
		cout<<"1.姓名："<<name<<endl;
		cout<<"2.学号："<<ID<<endl;
		cout<<"3.性别："<<gender<<endl;
		cout<<"4.组别："<<group<<endl;
		cout<<"5.专业班级："<<major_class<<endl<<endl;
	}
	
private:
	string ID;
	string gender;
	string group;
	string major_class;
	
	void set_info() //设置信息模块 
	{
		set_name();
		set_ID();
		set_gender();
		set_group();
		set_majorclass();
		cout<<endl<<"请再次确认信息是否正确(若信息有误，则输入其序号；否则输入-1，表示无误)："<<endl;
		change();
	}
	
	void change()
	{
		int flag;
		do
		{
			cout<<endl;
			check_info();
			pos:
			cin>>flag;
			if (flag==-1)
			{
				cout<<"信息设置成功！"<<endl<<endl;
				break;
			}
			else if (flag==1) set_name();
			else if (flag==2) set_ID();
			else if (flag==3) set_gender();
			else if (flag==4) set_group();
			else if (flag==5) set_majorclass();
			else
			{
				cout<<"输入有误！请重新输入："; 
				cin.clear();
				cin.ignore(256,'\n');
				goto pos;
			}
		} while(flag);
	}
	
	void set_name()
	{
		cout<<"请输入姓名：";
		cin>>this->name;
		cout<<"姓名设置成功！"<<endl; 
	}
	void set_ID()
	{
		cout<<"请输入学号：";
		cin>>this->ID;
		cout<<"学号设置成功！"<<endl; 
	}
	void set_gender()
	{
		cout<<"请输入性别：";
		cin>>this->gender;
		cout<<"性别设置成功！"<<endl; 
	}
	void set_group()
	{
		cout<<"请输入组别：";
		cin>>this->group;
		cout<<"组别设置成功！"<<endl; 
	}
	void set_majorclass()
	{
		cout<<"请输入专业班级：";
		cin>>this->major_class;
		cout<<"专业班级设置成功！"<<endl; 
	}	
};

int Member::number=0;
vector<Member*> Member::vct;

void system_UI()
{
	cout<<" _____________________"<<endl;
	cout<<"|RPS竞培营成员管理系统|"<<endl;
	cout<<"|                     |"<<endl;
	cout<<"|    1.添加新成员     |"<<endl;
	cout<<"|     2.删除成员      |"<<endl;
	cout<<"|     3.修改信息      |"<<endl;
	cout<<"|     4.成员查询      |"<<endl;
	cout<<"|     5.关闭系统      |"<<endl;
	cout<<"|_____________________|"<<endl<<endl;
	cout<<"根据前面的序号选择想要执行的操作：";
}

bool system_operation()
{
	bool res=1;
	int choice;
	pos4:
	cin>>choice;
	cout<<endl;
	if (choice==1)
		{
			Member*p=new Member;
		}
	else if (choice==2)
		{
			int deltar;
			pos1:
			cout<<"请输入欲删除成员的序号(输入-1表示放弃删除)：";
			cin>>deltar;
			if (deltar>0 && deltar<=Member::number)
			{
				Member::vct[deltar-1]->~Member();
				vector<Member*>::iterator it=Member::vct.begin();
				Member::vct.erase(it+deltar-1);
			}
			else if (deltar==-1) goto pos0;
			else
			{
				cout<<endl<<"输入有误！请重新输入："<<endl; 
				cin.clear();
				cin.ignore(256,'\n');
				goto pos1;
			}
		}
	else if (choice==3)
		{
			int tar;
			pos2:
			cout<<"请输入成员的序号(输入0表示放弃更改信息)：";
			cin>>tar;
			if (tar>0 && tar<=Member::number) Member::vct[tar-1]->change_info();
			else if (tar==0) goto pos0;
			else
			{
				cout<<endl<<"输入有误！请重新输入："<<endl; 
				cin.clear();
				cin.ignore(256,'\n');
				goto pos2;
			}
		}
	else if (choice==4)
		{
			cout<<"所有成员信息如下："<<endl;
				for (int i=0;i<Member::number;++i)
			{
				cout<<i+1<<'.'<<Member::vct[i]->name<<'\t';
				if ((i+1)%5==0) cout<<endl;
			}
			int target;
			while (1)
			{
				pos3:
				cout<<endl<<"输入姓名前的序号，以查询其相关信息(输入0表示结束查询)：";
				cin>>target;
				if (target>0 && target<=Member::number) Member::vct[target-1]->check_info();
				else if (!target) goto pos0;
				else
				{
					cout<<"输入有误！请重新输入：";
					cin.clear();
					cin.ignore(256,'\n');
					goto pos3;
				}
			}
		}
		//case 5: 关闭系统模块的调用 将res设置为 0 表示不再循环 
	else
		{
			cout<<"输入有误！请重新输入：";
			cin.clear();
			cin.ignore(256,'\n');
			goto pos4;
		}
	pos0:
	cout<<endl;
	return res;
}

void system_cycle()
{
	bool ifcontinue;
	do
	{
		system_UI();
		ifcontinue=system_operation();
	} while (ifcontinue);
}


int main()
{
	system_cycle();
	return 0;
}
