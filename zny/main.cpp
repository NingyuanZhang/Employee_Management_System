#include"head.h"
int main()
{ p:cout<<"����������������  ��  ��ӭ����Ա�����˼�������Ϣ����ϵͳ   ��  ����������������\n\n"//ͨ��¼ϵͳ������
       <<"����������������               ��ѡ�������û�����              ����������������\n\n"
       <<"******************                1.��ͨԱ��                 ******************\n\n"
	   <<"******************                2.������Ա                 ******************\n\n"
	   <<"******************                Q.�˳�                     ******************\n\n"
	   <<"������������������            ��������             �����������������\n\n";
	char choice;
	cin>>choice;
switch(choice)
{ case'1':
  system("cls");
  {m: cout<<"*************               ���������ѡ��                       **************\n\n" 
		  <<"       ��  ��         1����������ѯԱ����Ϣ                      ��  ��        \n\n"
		  <<"       ��  ��         2�������Ų�ѯԱ����Ϣ                      ��  ��        \n\n"
		  <<"       ��  ��         3�����Ա����Ϣ��������Ϣ�͹��������      ��  ��        \n\n"
		  <<"       ��  ��         4��Ա��ƽ������                            ��  ��        \n\n"
		  <<"       ��  ��         Q���˳�                                    ��  ��        \n\n";
    char choiceA;
    cin>>choiceA;
	system("cls");
	switch(choiceA) //���й���ѡ��
	{ case'1':inquire_name();goto m;
	  case'2':inquire_number();goto m;
	  case'3':browse();goto m;
	  case'4':average();goto m;
	  case'q':
	  case'Q':goto p;
	  default:cout<<"���������������\n\n";
	}
  };system("pause");system("cls");
  case'2':
  { system("cls");
    q:cout<<"�������������룺";
    char *a="111111";char *s=new char[30];
	cin>>s;
	if(strcmp(s,a)==0)
	{system("cls");
     n:cout<<"*************              ���������ѡ��                      **************\n\n" 
           <<"       ��  ��         1��¼��Ա����Ϣ                            ��  ��        \n\n"
		   <<"       ��  ��         2���޸�Ա����Ϣ                            ��  ��        \n\n"
		   <<"       ��  ��         3��ɾ��Ա����Ϣ                            ��  ��        \n\n"
		   <<"       ��  ��         4����������ѯԱ����Ϣ                      ��  ��        \n\n"
		   <<"       ��  ��         5�������Ų�ѯԱ����Ϣ                      ��  ��        \n\n"
		   <<"       ��  ��         6�����Ա����Ϣ��������Ϣ�͹��������      ��  ��        \n\n"
		   <<"       ��  ��         7��Ա��ƽ������                            ��  ��        \n\n"
		   <<"       ��  ��         0����ʼ��                                  ��  ��        \n\n"
		   <<"       ��  ��         Q���˳�                                    ��  ��        \n\n";
     char choiceA;
     cin>>choiceA;
	 system("cls");
	 switch(choiceA) //���й���ѡ��
	 { case'1':append();goto n;
   	   case'2':modify();goto n;
	   case'3':deleted();goto n;
	   case'4':inquire_name();goto n;
	   case'5':inquire_number();goto n;
	   case'6':browse();goto n;
	   case'7':average();goto n;
	   case'0':initial();goto n;
	   case'q':
	   case'Q':goto p;
	   default:cout<<"���������������\n\n";
	 }
	}
	else {cout<<"�������������ѡ��"<<endl;
	      char m;
	      cout<<"1.������������"<<endl<<"2.�����׽���"<<endl;
	      cin>>m;
		  switch(m)
			  {case'1':system("cls");goto q;
   	           case'2':system("cls");goto p;};
	     };
  };system("pause");system("cls");
  case'q':
  case'Q': system("cls");
	       cout<<"������������������������������������\n\n"
			   <<"                                    \n\n"
			   <<"    �ѳɹ��˳�ϵͳ����ӭ�ٴ�ʹ�ã�  \n\n"
	           <<"                                    \n\n"   
		       <<"������������������������������������\n\n";
		   system("pause");return 0;
};
}