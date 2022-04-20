#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>
#define Size 200
char input[Size] = { 0 };  //����� ���� �Է¹޴� ����
double intinput[Size] = { 0 }; //inputt()�Լ����� �Էµ� ������ ���ڸ� ���� �����ϴ� �迭
char charinput[Size] = { 0 }; //inputt()�Լ����� �Էµ� ������ ��ȣ�� ���� �����ϴ� �迭
int length = 0; //���ĵ��� ��ȯ�Ǹ鼭 ���ڿ� ��ȣ�� ���̸� �����ϴ� ����
char finalbooho = { 0 };  //������ �ֻ���(top)�� ��ȣ�� �����ϴº���
double backint[Size] = { 0 }; //change�Լ��� ���� charinput[]�ǰ��� ����ǥ������� ��ȯ�Ͽ� ���� �����ϴ¹迭
char backchar[Size] = { 0 }; //change�Լ��� ���� intinput[]�ǰ��� ����ǥ������� ��ȯ�Ͽ� ���� �����ϴ¹迭
typedef struct stack {  //char�� �����͸� ���� ���� ����
    char data;
    struct stack* link;
}stack;
stack* top;   //�������� ǥ���ϴ� ������ �ϳ� �����.
void stackNull() {
    stack* temp;
    while (top != NULL)
    {
        temp = top;
        top = top->link;
        free(temp);
    }
}
void push(char booho) {
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->data = booho;
    temp->link = top;
    top = temp;
    finalbooho = booho;  //������ �ֻ��� ��ȣ�� ����
}
char pop() {
    char booho;
    stack* temp = top;
    if (top == NULL) {//���� ������ 0�� ��ȯ�Ѵ�.
        return 0;
    }
    else {
        booho = temp->data;
        top = temp->link;
        free(temp);
        return booho;
    }
}
void inputt() {  //����� ���� ���ڿ��� �Է¹ް� 10�̻��� ���� 1������ ���� ����ϰ� int���� char���� ���ο� �迭�� �ִ� �Լ�
    int k = 0;
    int i = 0;
    int j = 0;
    int jj = 0;
    int wheredot = 0;  //�Ҽ��� ����� ���� ����� ����

    length = strlen(input);//���� ���ڿ��� ���̸� ����
    for (i = 0; i < length; i++) {
        if (input[i] != '(' && input[i] != ')' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '.') { //input�������� ���ڰ� �����ϰ��(  +-*/()�� �ƴѰ��)
            if (input[i - 1] == '.') {  //�Ҽ��� ù��° �ڸ� ���(�� �ε������� ���� input�迭�� ����� ���ڰ� '.'�� ���)
                intinput[j] = input[i] - '0';//���� ���ڸ� ���ڷ� ����
                intinput[j] = intinput[j] / 10;//���� ���ڸ� 10���� ��������
                intinput[j - 2] = intinput[j - 2] + intinput[j]; //�Ҽ��� ���ڸ����ڿ� ���Ѵ�.
                j--; //�Ҽ����� �迭���� ���ܽ��������� �ε��� �ϳ��� �ٿ��ش�.
                intinput[j] = 0;
                wheredot = 100;  // 2��° �ڸ� �Ҽ��� �Ի��� �ϱ� ���ؼ� 100�̶�� ���� �ش�.(�������� ���ڸ� 100���� �����ֱ� ����)
            }
            else if (wheredot != 0) {   //�Ҽ��� �ι�° �ڸ����� �̻� ���(wheredot�� 0�� �ƴѰ��)
                intinput[j] = input[i] - '0';//���� ���� ���� ���ڷ� �����Ѵ�.
                intinput[j] = intinput[j] / wheredot;//���� ���� �Ҽ��� n��° ���̸� 10^n������ ������
                intinput[j - 1] = intinput[j - 1] + intinput[j];//���� �迭�� �����ش�.
                wheredot = wheredot * 10;  //�����ڸ� �Ҽ��� ����� ����  wheredot�� 10�� �������� �������� wheredot���� ������.
            }
            else {//10 �̻��� ���� ���ϱ�����  
                if (charinput[j - 1] != '(' && charinput[j - 1] != ')' && charinput[j - 1] != '+' && charinput[j - 1] != '-' && charinput[j - 1] != '*' && charinput[j - 1] != '/' && j > 0) { //����迭�� ���� ������ ���
                    intinput[j] = input[i] - '0';  //���� ���� ���ڷ� ���� ��
                    intinput[j - 1] = (intinput[j - 1] * 10) + intinput[j];//���� ���� 10�� ������ ���� ���� �����ش�.

                }
                else {  //�׳� ���� ���ڸ��� ���
                    intinput[j] = input[i] - '0'; //���� ���� ���ڷ� ���� ��
                    j++;      //������ ���� int���� ���ο� �迭�� ������� �迭�� �ε����� ������Ų��.
                }
            }
        }
        else {     //���� ����� ������ ��ȣ, ��Ģ������ ���� ���
                    //ex) 11+12+13   ==>
                    //intinput[0]=11, charinput[1]='+',intinput[2]=12, charinput[3]='+', intinput[4]=13 
            if (wheredot != 0)//�Ҽ��� ����� ������
                wheredot = 0;  //���� ���ڿ��� �Ҽ��� ����� ���ؼ�wheredot�� ���� 0���� �����.
            charinput[j] = input[i];//������ ���� char���� ���ο� �迭�� ������� �迭�� �ε����� ������Ų��.
            //intinput[j] = 0;
            j++;
        }
    }
    length = j;  //���ο� �迭�� ������ ���̸� �����Ų��.
    printf("\n");
}
void change() {  //���� �Է¹��� int ���� char���� ���� ����ǥ�÷� �ٲٴ� �Լ�
    int j;
    int backi = 0; //����ǥ�� ������ ���� ���� ����
    char booho;
    stackNull();
    for (j = 0; j < length; j++) {
        printf("%d. int=%f  // char=%c\n", j, intinput[j], charinput[j]);
    }
    for (j = 0; j < length; j++) {  //���� ���̸�ŭ /
        if (charinput[j] != '(' && charinput[j] != ')' && charinput[j] != '+' && charinput[j] != '-' && charinput[j] != '*' && charinput[j] != '/') {//�迭�� ���� ������ ���
            backint[backi] = intinput[j];  //����ǥ�÷� ǥ���� ���� ������ �迭�� ���� ���ڸ� �ְ� �ε����� ������Ų��.
            backi++;
        }
        else {  //�迭�� ���� ������ ���
            if (charinput[j] == '(') {  //��ȣ�� ������ ���
                push(charinput[j]);  //��ȣ�� ���ؿ� �о�ִ´�.
            }
            else if (charinput[j] == ')') { //��ȣ�� ���� �ִ°�� ���� ������ �ִ� ��ȣ���� ������ ��ȣ�� ������.
                while (1) {
                    booho = pop();
                    if (booho == '(')
                        break;
                    else {
                        backchar[backi] = booho;  //���� ��ȣ�� ����ǥ�÷� ������ �迭�� ����ְ� �ε����� ������Ų��.
                        backi++;
                    }
                }
            }
            else if (charinput[j] == '+') {    //��ȣ�� ������ push�Ѵ�.
                if (finalbooho == '*' || finalbooho == '/')//�켱������ �־� */���� �ٷιٷβ����� ���� ��ȣ�� ������ ����ִ´�.
                {
                    backchar[backi] = pop();
                    backi++;
                }
                push(charinput[j]);
            }
            else if (charinput[j] == '-') {
                if (finalbooho == '*' || finalbooho == '/')
                {
                    backchar[backi] = pop();
                    backi++;
                }
                push(charinput[j]);
            }
            else if (charinput[j] == '*') {
                if (finalbooho == '*' || finalbooho == '/')
                {
                    backchar[backi] = pop();
                    backi++;
                }
                push(charinput[j]);
            }
            else if (charinput[j] == '/') {
                if (finalbooho == '*' || finalbooho == '/')
                {
                    backchar[backi] = pop();
                    backi++;
                }
                push(charinput[j]);
            }
        }
        if (j == (length - 1)) { //������ ���� ������ ��� ��� ����� ��ȣ�� ���ؿ��� ������ ����ǥ�÷� ������ �迭�� ����ִ´�.
            while (1) {
                booho = pop();
                if (booho == 0) //���� ��ȣ�� �������
                    break;
                else {   //���� ��ȣ�� �������
                    backchar[backi] = booho;
                    backi++;
                }
            }
        }
    }
    length = backi; //�� ���̸� ����ǥ���Ǽ� �ٲ� �迭�� ���̷� �ٽ� ����( ��ȣ�� ���� ����)
    printf("-----------\n");
    for (j = 0; j < length; j++) {
        printf("%d. int=%f  // char=%c\n", j, backint[j], backchar[j]);
    }
}
void guesan() //����ǥ�÷���ȯ�� ������ ����ϴ���(�迭�� ���ð� ���� ������� ���)
{
    int k;
    int j = 0;  //����ó�� �迭�� ������ ����ϴ� ����(������ top����)
    double lastdap[Size];//����ó�� ����� �迭 
    for (k = 0; k < length; k++) {
        if (backchar[k] != '+' && backchar[k] != '-' && backchar[k] != '*' && backchar[k] != '/') { //����ǥ������ �迭 ���� ������ ���
            lastdap[j] = backint[k];      //����ǥ���� �迭�� ���� ���� �ε����� ����
            j++;           //�ε����� ������Ų��.
        }
        else {                 ////����ǥ������ �迭 ���� =-*/�� ���
            if (backchar[k] == '*') {  //����Ѵ�.
                lastdap[j - 2] = lastdap[j - 2] * lastdap[j - 1];
            }
            else if (backchar[k] == '/') {
                lastdap[j - 2] = lastdap[j - 2] / lastdap[j - 1];
            }
            else if (backchar[k] == '+') {
                lastdap[j - 2] = lastdap[j - 2] + lastdap[j - 1];
            }
            else if (backchar[k] == '-') {
                lastdap[j - 2] = lastdap[j - 2] - lastdap[j - 1];
            }
            j--;
        }
    }
    printf("\n%f", lastdap[0]);
}
int main(int argc, char* argv[]) {
    int j;
    if (argc == 2)
        strcpy_s(input, argv[1]);
    else
        printf("�߸��ԷµǾ����ϴ�.");

    printf("1.%s -------2.%s\n", argv[0], argv[1]);
    inputt();//�Էµ� ������ �������� ĳ���������� ��ȯ
    change();//��ȯ�� �������� ĳ�������� ����ǥ������ ��ȯ
    guesan();//����ǥ������ ��ȯ�� �迭�� ��� �� ���
    scanf_s("%d", &j);	//ȭ���� ������ �ʰ� �ϱ����� �ӽ÷� ����
    return 1;
}
