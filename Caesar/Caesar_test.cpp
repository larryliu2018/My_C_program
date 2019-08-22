#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

//凯撒加密与解密算法
 
using namespace std;

void encry(string str,int n,int mode)  //str输入密码，n秘钥，模式
{
	if(mode==1)
	{
		for(int i=0;i<str.size();i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
				str[i]=(str[i]-'A'+n)%26+'A';
			else if(str[i]>='a'&&str[i]<='z')
				str[i]=(str[i]-'a'+n)%26+'a';		
		}
		cout<<"加密完成："<<str<<endl;
//			FileOut(str);
//			cout<<"已输出到文件"<<endl; 
	}

	 else
	 {
	 		cout<<"该模式不支持此项功能！"<<endl; 
	 }

}

void decry(string str,int n,int mode) //str待解密字符串，n为秘钥，模式
{
	if(mode==2)
	{
		for(int i=0;i<str.size();i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
				str[i]=(str[i]-'A'+26-n)%26+'A';
			else if(str[i]>='a'&&str[i]<='z')
				str[i]=(str[i]-'a'+26-n)%26+'a';
			
		}
		cout<<"解密完成："<<str<<endl; 		
	 } 
	 else
	 {
	 	cout<<"该模式不支持此项功能！"<<endl; 
	 }
} 

int main(void)
{
	string str;
	int model;
	int n;
	while(1)
	{
		cout<<"凯撒密码：请选择模式：\n";
		cout<<"1.加密\n";
		cout<<"2.解密\n";
		cout<<"3.退出\n";
		cin>>model;
		cout<<endl; 
		switch(model)
		{
			case 1:
				cout<<"请输入要加密的字符串：";
				cin>>str;
				cout<<"请输入该密码算法的偏移数量：";
				cin>>n;
				encry(str,n,model);
				cout<<endl;
				break;
			case 2:
			 	cout<<"请输入要解密的字符串：";
				cin>>str;
				cout<<"请输入原密码算法的偏移数量：";
				cin>>n;
				decry(str,n,model);
				cout<<endl;
				break;
			case 3:
				return 0;
				break;
			default:
				break;
		}
		
		
	}
	
	return 0;
	
	
}









