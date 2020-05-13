#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<math.h>
#pragma warning(disable : 4996)
#define NODE "node:"
#define NAME "name"
#define SEX  "sex:"
#define MATH "math:"
#define CHINESE  "chinese:"
#define ENGLISH  "english:"
#define F_PATH  "C:/Users/Administrator/Desktop/c.txt"

//项目说明，构建一个学生信息表，并完成对信息表的增删查改功能;
typedef struct score {
		int math;
		int chinese;
		int english;
	}Score;
typedef struct student {
	int _node;
	char _name[20];
	enum sex {
		MALE,
		FEMALE
	}_sex;
	Score _score;
}Student;
//学生信息的基础结构，由名称、学号、性别构成;
typedef struct post {
	int _capacity;
	int _size;
	Student* _post = (Student*)malloc(sizeof(Student) * _capacity);
}Post;
//存储学生数据的表格

/*----------以下是操作函数模板------------------*/
extern void checkcapacity(Post*);           //检查数据表是否已满
extern void intilalise(Post*);              //进行数据初始化,主要是 分 析 文本
extern void insert(Post*);                  //增
extern void delete_(Post*);                 //删
extern void search_ergodic(Post);                        //查
/*---------以下为不同的排序方式-----------------*/
extern void bubble_sort(Post*,int);         //冒泡排序
extern void select_sort(Post*,int);         //选择排序
extern void insert_sort(Post*,int);         //插入排序
extern void quick_sort(Post*,int,int);      //快速排序
extern void shell_sort(Post*);              //希尔排序
extern void merg_sort(Post*, int, int);     //归并排序里的分治
extern void merg_array(Post*, int, int, int);      //归并排序里的归并
extern void heap_sort(Post*);                    //堆排序

//extern void change();              //改
//extern void test();                //测试 
/*-----------以下为操作界面用到的函数------------------*/
extern void version1();               //界面
extern void RandInformation();       //用来生成随机数据 