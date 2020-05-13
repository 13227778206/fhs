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

//��Ŀ˵��������һ��ѧ����Ϣ������ɶ���Ϣ�����ɾ��Ĺ���;
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
//ѧ����Ϣ�Ļ����ṹ�������ơ�ѧ�š��Ա𹹳�;
typedef struct post {
	int _capacity;
	int _size;
	Student* _post = (Student*)malloc(sizeof(Student) * _capacity);
}Post;
//�洢ѧ�����ݵı��

/*----------�����ǲ�������ģ��------------------*/
extern void checkcapacity(Post*);           //������ݱ��Ƿ�����
extern void intilalise(Post*);              //�������ݳ�ʼ��,��Ҫ�� �� �� �ı�
extern void insert(Post*);                  //��
extern void delete_(Post*);                 //ɾ
extern void search_ergodic(Post);                        //��
/*---------����Ϊ��ͬ������ʽ-----------------*/
extern void bubble_sort(Post*,int);         //ð������
extern void select_sort(Post*,int);         //ѡ������
extern void insert_sort(Post*,int);         //��������
extern void quick_sort(Post*,int,int);      //��������
extern void shell_sort(Post*);              //ϣ������
extern void merg_sort(Post*, int, int);     //�鲢������ķ���
extern void merg_array(Post*, int, int, int);      //�鲢������Ĺ鲢
extern void heap_sort(Post*);                    //������

//extern void change();              //��
//extern void test();                //���� 
/*-----------����Ϊ���������õ��ĺ���------------------*/
extern void version1();               //����
extern void RandInformation();       //��������������� 