
#include <stdio.h>

//person 成员变量中，gg gg1 的空间大小都是1，地址随在age后面
//gg2的空间大小是1，地址跟在work后面
class person {
public:
	char *name;
	int age;
	char gg;
	char gg1;
	char *work;
	char gg2;
	

	void printInfo(void)
	{
		printf("name = %s, age = %d, work = %s\n", name, age, work); 
	}
};

bool memey_mode(void)
{
	int a = 1;
	return (*(char *)&a);
}

int main(int argc, char **argv)
{
	struct person persons[] = {
		{"zhangsan", 10,'a','b',"teacher",'c'},
		{"lisi", 16,'b','c',"doctor",'d'},
	};
	
	persons[0].printInfo();
	persons[1].printInfo();


	printf("sizeof *char = %d\n",sizeof(persons[0].name));
	printf("sizeof int = %d\n",sizeof(persons[0].age));
	printf("sizeof char = %d\n",sizeof(persons[0].age));

	int a = 2;
	printf("sizeof int = %d\n",sizeof(a));
	char b = 0 ;
	printf("sizeof char = %d\n",sizeof(b));

	
	printf("sizeof *char = %d\n",sizeof(&b));

	if(memey_mode())
	{
		printf("little mode");		
	}
	else
	{
		printf("big mode");
	}
	
	return 0;
}

