#include <iostream>
#include <string>
#include <cctype>
#define MAX 100
using namespace std;
struct queue{
  int front;
  int rear;
  char data[MAX];
};

void initqueue(queue *q){
  q->front=-1;
  q->rear=-1;
}

bool isEmpty(queue *q){
  return (q->front==-1||q->front>q->rear);
}

bool isFull(queue *q){
  return (q->rear==MAX-1);
}

void enqueue(queue *q, char x){
  if (isFull(q)){
    cout<<"Hang doi day\n";
    return;
  }
  if (isEmpty(q)){
    q->front++;
  }
  q->rear++;
  q->data[q->rear]=x;
}
char dequeue(queue *q){
  return q->data[q->front++];
}

int size(queue q){
  return q.rear-q.front +1;
}

bool isPalindrome(string str){
  queue q;
  initqueue(&q);

  for (char c: str){
    if (isalnum(c)){
      enqueue(&q, tolower(c));
    }
  }

  while (size(q)>1){
    int n=size(q);

    char front = dequeue(&q);
    for (int i=0; i<n-2; i++){
      enqueue(&q, dequeue(&q));
    }

    char last= dequeue(&q);

    if (front != last)
      return false;
  }
  return true;
}

int main(){
  string str;
  cout<<"Nhap chuoi: ";
  getline(cin,str);
  if (isPalindrome(str)){
    cout<<"Chuoi doi xung";
  } else {
    cout<<"Chuoi khong doi xung";
  }
  cout<<"Hoàn thành chương trình";
  return 0;
  
}
