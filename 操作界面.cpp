#include"标头.h"
//初始化学生数据表格
Post student_post={ 
	student_post._capacity=100,  
	student_post._size = 0, 
	student_post._post=(Student*)malloc(sizeof(Student) * student_post._capacity)
};

void version1() {
	intilalise(&student_post);
	int a = -1;
	while (1) {
	printf("please selet your operation:\n\
     0.show the data\n\
	 1.increse a data\n\
     2.delete a data\n\
     3.search a data\n\
     4.change  a  data \n\
     5.exit\n\
");
	scanf("%d", &a);
	//操作选项
	switch (a) {

	case 0:
	printf("-----NODE-----NAME-----SEX-----MATH-----CHINESE-----ENGLISH-----\n");
	for (int ac = 0; ac < student_post._size; ac++)
		printf("|  %6d  ||  %10s  ||  %3d  ||  %4d  ||  %4d  ||  %4d  |\n", student_post._post[ac]._node, student_post._post[ac]._name, student_post._post[ac]._sex, student_post._post[ac]._score.math, student_post._post[ac]._score.chinese, student_post._post[ac]._score.english);
	//此处需要优化，数据分割线需要对齐一下
	break;

	case 1:
		insert(&student_post);
	break;

	case 2:
		delete_(&student_post);
		break;

	case 3:
		//bubble_sort(&student_post,0);
		//select_sort(&student_post,0);
		//insert_sort(&student_post,0);
		//quick_sort(&student_post, 0, student_post._size-1);
		//shell_sort(&student_post);
		//merg_sort(&student_post,0, student_post._size-1);
		heap_sort(&student_post);
		break;
	case 4:
		search_ergodic(student_post);
		break;
	case 5:
		exit(0);
		break;
	//default:
	//	printf("input wrong! ! !Please slecet again\n\n");
		//break;
	}
	
}
}