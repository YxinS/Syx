#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
using namespace std;


typedef int Type;

// 链式结构：表示队列
typedef struct QListNode
{ 
    struct QListNode* _pNext; 
    Type _data; 
}QNode; 
// 队列的结构
typedef struct Queue
{ 
    struct QListNode* _front; 
    struct QListNode* _back; 
}Queue; 




// 初始化队列
void QueueInit(Queue* q); 
// 队尾入队列
void QueuePush(Queue* q, Type data); 
// 队头出队列
void QueuePop(Queue* q); 
// 获取队列头部元素
Type QueueFront(Queue* q); 
// 获取队列队尾元素
Type QueueBack(Queue* q); 
// 获取队列中有效元素个数
int QueueSize(Queue* q); 
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q); 
// 销毁队列
void QueueDestroy(Queue* q);




// 初始化队列
void QueueInit(Queue* q){
    assert(q);
    q->_back = q->_front = NULL;
}
// 队尾入队列
void QueuePush(Queue* q, Type data){
    assert(q);
    QNode* newList = (QNode*)malloc(sizeof(QNode));
    newList->_data = data;
    newList->_pNext = NULL;
    if(q->_back == NULL){
        q->_front = q->_back = newList;
    }
    else{
        q->_back->_pNext = newList;
        q->_back = newList;
    }
}
// 队头出队列
void QueuePop(Queue* q){
    assert(q);
    if(q->_front->_pNext == NULL){
        free(q->_front);
        q->_front = q->_back = NULL;
    }
    else{
        QNode* next = q->_front->_pNext;
        free(q->_front);
        q->_front = next;
    }
}
// 获取队列头部元素
Type QueueFront(Queue* q){
    assert(q);
    return q->_front->_data;
}
// 获取队列队尾元素
Type QueueBack(Queue* q){
    assert(q);
    return q->_back->_data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q){
    int n = 0;
    QNode* cur = q->_front;
    while(cur){
        n++;
        cur = cur->_pNext;
    }
    return n;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q){
    return q->_front == NULL ? 1 : 0;
}
// 销毁队列
void QueueDestroy(Queue* q){
    QNode* cur = q->_front;
    while(cur){
        QNode* next = cur->_pNext;
        free(cur);
        cur = next;
    }
    q->_front = q->_back = NULL;
}

//打印
void QueuePrint(Queue* q){
    assert(q);
    QNode* cur = q->_front;
    while(cur){
        printf("%d\n",cur->_data);
        cur= cur->_pNext;
    }
}




int main(){
    Queue q;
    QueueInit(&q);
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,13);
    QueuePush(&q,1);
    QueuePush(&q,14);
    QueuePush(&q,15);
    QueuePush(&q,19);
    while(!QueueEmpty(&q)){
        printf("%d\n",QueueFront(&q));
        QueuePop(&q);
    }
    QueueDestroy(&q);





    return 0;
    system("pause");
}