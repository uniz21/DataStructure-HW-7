///*
// *  doubly-linked-list.c
// *
// *  Doubly Linked List
// *
// *  Data Structures
// *  Department of Computer Science
// *  at Chungbuk National University
// *
// */
//
//#include<stdio.h>
//#include<stdlib.h>
// /* �ʿ��� ������� �߰� if necessary */
//
//typedef struct Node {
//	int key;
//	struct Node* llink;
//	struct Node* rlink;
//}listNode;
//
//typedef struct Head {
//	struct Node* first;
//}headNode;
//
///* �Լ� ����Ʈ */
//
///* note: initialize�� ���������͸� �Ű������� ����
//		 singly-linked-list�� initialize�� �������� ���� �Ұ� */
//int initialize(headNode** h);
//
///* note: freeList�� �̱������͸� �Ű������� ����
//		- initialize�� �� �ٸ��� ���� �Ұ�
//		- ���������͸� �Ű������� �޾Ƶ� ������ �� ���� �� */
//int freeList(headNode* h);
////int freeList(headNode** h);
//
//int insertNode(headNode* h, int key);
//int insertLast(headNode* h, int key);
//int insertFirst(headNode* h, int key);
//int deleteNode(headNode* h, int key);
//int deleteLast(headNode* h);
//int deleteFirst(headNode* h);
//int invertList(headNode* h);
//
//void printList(headNode* h);
//
//int main()
//{
//	char command;
//	int key;
//	headNode* headnode = NULL;
//
//	/* printf("[----- [������]  [2016039040] -----]\n"); */
//	printf("[----- [Yoon YongJin]  [2016039040] -----]\n");
//
//	do {
//		printf("----------------------------------------------------------------\n");
//		printf("                     Doubly Linked  List                        \n");
//		printf("----------------------------------------------------------------\n");
//		printf(" Initialize    = z           Print         = p \n");
//		printf(" Insert Node   = i           Delete Node   = d \n");
//		printf(" Insert Last   = n           Delete Last   = e\n");
//		printf(" Insert First  = f           Delete First  = t\n");
//		printf(" Invert List   = r           Quit          = q\n");
//		printf("----------------------------------------------------------------\n");
//
//		printf("Command = ");
//		scanf(" %c", &command);
//
//		switch (command) {
//		case 'z': case 'Z':
//			initialize(&headnode);
//			break;
//		case 'p': case 'P':
//			printList(headnode);
//			break;
//		case 'i': case 'I':
//			printf("Your Key = ");
//			scanf("%d", &key);
//			insertNode(headnode, key);
//			break;
//		case 'd': case 'D':
//			printf("Your Key = ");
//			scanf("%d", &key);
//			deleteNode(headnode, key);
//			break;
//		case 'n': case 'N':
//			printf("Your Key = ");
//			scanf("%d", &key);
//			insertLast(headnode, key);
//			break;
//		case 'e': case 'E':
//			deleteLast(headnode);
//			break;
//		case 'f': case 'F':
//			printf("Your Key = ");
//			scanf("%d", &key);
//			insertFirst(headnode, key);
//			break;
//		case 't': case 'T':
//			deleteFirst(headnode);
//			break;
//		case 'r': case 'R':
//			invertList(headnode);
//			break;
//		case 'q': case 'Q':
//			freeList(headnode);
//			break;
//		case 'x':
//			freeList(&headnode);
//			break;
//		default:
//			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
//			break;
//		}
//	} while (command != 'q' && command != 'Q');
//
//	return 0;
//}
//
//int initialize(headNode** h) {
//	/*	��ó��
//		headNode�� ����� ����Ʈ�� �ִٸ�, freeList�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
//	if (*h != NULL) {
//		freeList(h);
//	}
//
//	headNode* temp = (headNode*)malloc(sizeof(headNode));
//	temp->first = NULL;
//	*h = temp;
//
//	return 0;
//}
//
////�̱������͸� �Ű������� ���� �Ҵ����� �Լ�
//int freeList(headNode* h) {
//
//	listNode* p;
//	listNode* prev;
//
//	//���������Ͱ� �Ű������� ȣ��Ǿ��� ���
//	if (h->first->llink != NULL)
//	{
//		headNode** x = h;
//		listNode** z = *x;
//		p = *z;
//
//		while (p != NULL)
//		{
//			prev = p->llink;
//
//			p = p->rlink;
//			free(prev);
//		}
//		free(z);
//	}
//	//�̱������Ͱ� �Ű������� ȣ��Ǿ��� ���
//	else
//	{
//		p = h->first;
//
//		while (p != NULL)
//		{
//			prev = p->llink;
//
//			p = p->rlink;
//			free(prev);
//		}
//		free(h);
//	}
//
//	return 0;
//}
//
////���������͸� �Ű������� ���� �Ҵ����� �Լ�
////int freeList(headNode** h) {
////	headNode* t = *h;
////	listNode* p;
////	listNode* prev;
////	
////	p = t->first;
////	
////	while (p != NULL)
////		{
////		prev = p->llink;
////	
////		p = p->rlink;
////		free(prev);
////	}
////	
////	free(t);
////	return 0;
////}
//
//void printList(headNode* h) {
//	int i = 0;
//	listNode* p;
//
//	printf("\n---PRINT\n");
//
//	if (h == NULL) {
//		printf("Nothing to print....\n");
//		return;
//	}
//
//	p = h->first;
//
//	while (p != NULL) {
//		printf("[ [%d]=%d ] ", i, p->key);
//		p = p->rlink;
//		i++;
//	}
//
//	printf("  items = %d\n", i);
//}
//
///**
// * list�� key�� ���� ����ϳ��� �߰�
// */
//int insertLast(headNode* h, int key) {
//	/*	��ó��	*/
//	if (h == NULL) {
//		printf("Initialize First\n");
//		return 0;
//	}
//
//	listNode* p;
//	listNode* lastnode = (listNode*)malloc(sizeof(listNode));
//
//	/* ����Ʈ�� ����ְ�, ù ��° ��� ������ ��� */
//	if (h->first == NULL)
//	{
//		insertFirst(h, key);
//		return 0;
//	}
//
//	p = h->first;
//
//	while (p != NULL) {
//		if (p->rlink == NULL)
//		{
//			lastnode->key = key;
//			lastnode->llink = p;
//			lastnode->rlink = NULL;
//			//���� ������ ��� �����ʿ� ���ο� ������ ��� ����
//			p->rlink = lastnode;
//			break;
//		}
//		p = p->rlink;
//	}
//
//	return 0;
//}
//
///**
// * list�� ������ ��� ����
// */
//int deleteLast(headNode* h) {
//	/*	��ó��	*/
//	if (h == NULL) {
//		printf("Initialize First\n");
//		return 0;
//	}
//
//	if (h->first == NULL)
//	{
//		printf("There is no Node\n");
//		return 0;
//	}
//
//	listNode* p;
//	listNode* prev;
//
//	p = h->first;
//
//	while (p != NULL) {
//		/* ����Ʈ�� ��尡 �ϳ����� ��� */
//		if (p->llink == NULL && p->rlink == NULL)
//		{
//			deleteFirst(h);
//			return 0;
//		}
//		//������ ��� ����
//		else if (p->rlink == NULL)
//		{
//			prev = p->llink;
//			prev->rlink = NULL;
//			free(p);
//			return 0;
//		}
//		p = p->rlink;
//	}
//
//	return 0;
//}
//
///**
// * list ó���� key�� ���� ����ϳ��� �߰�
// */
//int insertFirst(headNode* h, int key) {
//	/*	��ó��	*/
//	if (h == NULL) {
//		printf("Initialize First\n");
//		return 0;
//	}
//
//	listNode* firstnode = (listNode*)malloc(sizeof(listNode));
//
//	firstnode->key = key;
//	firstnode->llink = NULL;
//	firstnode->rlink = h->first;
//	//���� ����Ʈ�� �ִ� ���, ���� ù ����� ���ʿ� ���ο� ù ��带 ����
//	if (h->first != NULL) h->first->llink = firstnode;
//	h->first = firstnode;
//
//	return 0;
//}
//
///**
// * list�� ù��° ��� ����
// */
//int deleteFirst(headNode* h) {
//	/*	��ó��	*/
//	if (h == NULL) {
//		printf("Initialize First\n");
//		return 0;
//	}
//
//	if (h->first == NULL)
//	{
//		printf("There is no Node\n");
//		return 0;
//	}
//
//	listNode* p;
//
//	p = h->first;
//
//	//��尡 �ϳ����� ����Ʈ�� ���
//	if (p->rlink == NULL)
//	{
//		h->first = NULL;
//	}
//	else
//	{
//		//������ ù ��� ���� ��带 ���
//		listNode* secondnode;
//		//�ι�° ��带 ù ���� ����
//		secondnode = p->rlink;
//		secondnode->llink = NULL;
//		h->first = secondnode;
//	}
//	//������ ù��° ��� �Ҵ� ����
//	free(p);
//	return 0;
//}
//
///**
// * ����Ʈ�� ��ũ�� �������� �� ��ġ
// */
//int invertList(headNode* h) {
//	/*	��ó��	*/
//	if (h == NULL) {
//		printf("Initialize First\n");
//		return 0;
//	}
//
//	if (h->first == NULL)
//	{
//		printf("Make List First\n");
//		return 0;
//	}
//
//	//����Ʈ�� ������ �ٲٴ� �������� ���� ����Ʈ�� ������ ����ϱ� ���� �ӽó��
//	listNode* nextnode = NULL;
//	//����Ʈ�� ���� �����ϸ� ���Ӱ� ������� ù ���� ��尡 �� ������ ���
//	listNode* lastnode = NULL;
//
//	listNode* p;
//
//	p = h->first;
//
//	while (p != NULL)
//	{
//		//����Ʈ�� ������ ��� ���
//		if (p->rlink == NULL) lastnode = p;
//		//����Ʈ�� ���� ����
//		nextnode = p->rlink;
//		p->rlink = p->llink;
//		p->llink = nextnode;
//		//���� ����Ʈ�� ������ ���� ���� ��� Ž��
//		p = nextnode;
//	}
//
//	h->first = lastnode;
//
//	return 0;
//}
//
///* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
//int insertNode(headNode* h, int key) {
//	/*	��ó��	*/
//	if (h == NULL) {
//		printf("Initialize First\n");
//		return 0;
//	}
//
//	listNode* p;
//	listNode* node2insert = (listNode*)malloc(sizeof(listNode));
//
//	/* ����Ʈ�� ����ְ�, ù ��° ��� ������ ��� */
//	if (h->first == NULL)
//	{
//		insertFirst(h, key);
//		return 0;
//	}
//
//	p = h->first;
//
//	while (p != NULL) {
//		/* ���ο� ����� ���� ��ġ�� ����Ʈ�� ù ��� ���� ��� */
//		if (p == h->first && p->key > key)
//		{
//			insertFirst(h, key);
//			return 0;
//		}
//		/* ���� Ž������ ����� Ű���� �Է¹��� Ű������ ū ���*/
//		else if (p->key > key)
//		{
//			node2insert->key = key;
//
//			node2insert->llink = p->llink;
//			p->llink->rlink = node2insert;
//
//			node2insert->rlink = p;
//			p->llink = node2insert;
//
//			return 0;
//		}
//		p = p->rlink;
//	}
//
//	/* �Է¹��� Ű ������ ū Ű ���� ���� ��尡 ���� ��� ������ ���� �� ��� �߰� */
//	insertLast(h, key);
//
//	return 0;
//}
//
///**
// * list���� key�� ���� ��� ����
// */
//int deleteNode(headNode* h, int key) {
//	/*	��ó��	*/
//	if (h == NULL) {
//		printf("Initialize First\n");
//		return 0;
//	}
//
//	if (h->first == NULL)
//	{
//		printf("There is no Node\n");
//		return 0;
//	}
//
//	listNode* p;
//
//	p = h->first;
//
//	while (p != NULL) {
//		/* ������ ��尡 ù ��° ����� ��� */
//		if (p == h->first && p->key == key)
//		{
//			deleteFirst(h);
//			return 0;
//		}
//		/* ������ ��尡 ������ ����� ��� */
//		else if (p->rlink == NULL && p->key == key)
//		{
//			deleteLast(h);
//			return 0;
//		}
//		/* ����Ʈ���� ó������ ����ġ�� Ű ���� ��ġ�ϴ� ��带 ���� */
//		else if (p->key == key)
//		{
//			p->llink->rlink = p->rlink;
//			p->rlink->llink = p->llink;
//			free(p);
//			return 0;
//		}
//		p = p->rlink;
//	}
//
//	//��� ��� Ž���� ���� ������ ������ ��带 ã�� ���ߴٸ�
//	printf("There is no node corresponding to the key value.\n");
//
//	return 0;
//}