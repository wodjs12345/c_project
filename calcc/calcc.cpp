#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>
#define Size 200
char input[Size] = { 0 };  //계산할 값을 입력받는 변수
double intinput[Size] = { 0 }; //inputt()함수에서 입력된 값에서 숫자만 빼서 저장하는 배열
char charinput[Size] = { 0 }; //inputt()함수에서 입력된 값에서 부호만 빼서 저장하는 배열
int length = 0; //수식들이 변환되면서 숫자와 부호의 길이를 저장하는 변수
char finalbooho = { 0 };  //스택의 최상위(top)의 부호를 저장하는변수
double backint[Size] = { 0 }; //change함수에 의해 charinput[]의값을 후위표기법으로 전환하여 값을 저장하는배열
char backchar[Size] = { 0 }; //change함수에 의해 intinput[]의값을 후위표기법으로 전환하여 값을 저장하는배열
typedef struct stack {  //char형 데이터를 가진 스텍 생성
    char data;
    struct stack* link;
}stack;
stack* top;   //마지막을 표현하는 스택을 하나 만든다.
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
    finalbooho = booho;  //스택의 최상위 부호를 저장
}
char pop() {
    char booho;
    stack* temp = top;
    if (top == NULL) {//뺄게 없으면 0을 반환한다.
        return 0;
    }
    else {
        booho = temp->data;
        top = temp->link;
        free(temp);
        return booho;
    }
}
void inputt() {  //계산할 값을 문자열로 입력받고 10이상의 값과 1이하의 값을 계산하고 int형과 char형의 새로운 배열에 넣는 함수
    int k = 0;
    int i = 0;
    int j = 0;
    int jj = 0;
    int wheredot = 0;  //소수점 계산을 위해 사용한 변수

    length = strlen(input);//받은 문자열의 길이를 저장
    for (i = 0; i < length; i++) {
        if (input[i] != '(' && input[i] != ')' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '.') { //input에서받은 문자가 숫자일경우(  +-*/()가 아닌경우)
            if (input[i - 1] == '.') {  //소수점 첫번째 자리 계산(전 인덱스에서 받은 input배열에 저장된 문자가 '.'인 경우)
                intinput[j] = input[i] - '0';//현재 문자를 숫자로 변경
                intinput[j] = intinput[j] / 10;//현재 숫자를 10으로 나눠준후
                intinput[j - 2] = intinput[j - 2] + intinput[j]; //소수점 앞자리숫자에 더한다.
                j--; //소수점을 배열에서 제외시켯음으로 인덱스 하나를 줄여준다.
                intinput[j] = 0;
                wheredot = 100;  // 2번째 자리 소수점 게산을 하기 위해서 100이라는 값을 준다.(다음값이 숫자면 100으로 나눠주기 위해)
            }
            else if (wheredot != 0) {   //소수점 두번째 자리부터 이상 계산(wheredot이 0이 아닌경우)
                intinput[j] = input[i] - '0';//현재 문자 값을 숫자로 변경한다.
                intinput[j] = intinput[j] / wheredot;//현재 값을 소숫점 n번째 값이면 10^n승으로 나눈후
                intinput[j - 1] = intinput[j - 1] + intinput[j];//전의 배열에 더해준다.
                wheredot = wheredot * 10;  //다음자리 소숫점 계산을 위해  wheredot에 10을 곱해준후 다음번에 wheredot으로 나눈다.
            }
            else {//10 이상의 값을 구하기위해  
                if (charinput[j - 1] != '(' && charinput[j - 1] != ')' && charinput[j - 1] != '+' && charinput[j - 1] != '-' && charinput[j - 1] != '*' && charinput[j - 1] != '/' && j > 0) { //현재배열의 앞이 숫자인 경우
                    intinput[j] = input[i] - '0';  //현재 값을 숫자로 만든 후
                    intinput[j - 1] = (intinput[j - 1] * 10) + intinput[j];//전의 값에 10을 곱한후 현재 값을 더해준다.

                }
                else {  //그냥 숫자 한자리인 경우
                    intinput[j] = input[i] - '0'; //현재 값을 숫자로 만든 후
                    j++;      //숫자의 값을 int형의 새로운 배열에 집어놓고 배열의 인덱스를 증가시킨다.
                }
            }
        }
        else {     //숫자 계산이 끝나고 괄호, 사칙연산이 나온 경우
                    //ex) 11+12+13   ==>
                    //intinput[0]=11, charinput[1]='+',intinput[2]=12, charinput[3]='+', intinput[4]=13 
            if (wheredot != 0)//소수점 계산을 했으면
                wheredot = 0;  //다음 숫자에서 소수점 계산을 위해서wheredot의 값을 0으로 만든다.
            charinput[j] = input[i];//문자의 값을 char형의 새로운 배열에 집어놓고 배열의 인덱스를 증가시킨다.
            //intinput[j] = 0;
            j++;
        }
    }
    length = j;  //새로운 배열에 저장한 길이를 저장시킨다.
    printf("\n");
}
void change() {  //새로 입력받은 int 형과 char형의 값을 후위표시로 바꾸는 함수
    int j;
    int backi = 0; //후위표시 저장을 위해 사용될 변수
    char booho;
    stackNull();
    for (j = 0; j < length; j++) {
        printf("%d. int=%f  // char=%c\n", j, intinput[j], charinput[j]);
    }
    for (j = 0; j < length; j++) {  //받은 길이만큼 /
        if (charinput[j] != '(' && charinput[j] != ')' && charinput[j] != '+' && charinput[j] != '-' && charinput[j] != '*' && charinput[j] != '/') {//배열의 값이 숫자일 경우
            backint[backi] = intinput[j];  //후위표시로 표현된 값을 저장할 배열에 현재 숫자를 넣고 인덱스를 증가시킨다.
            backi++;
        }
        else {  //배열의 값이 문자일 경우
            if (charinput[j] == '(') {  //괄호의 시작일 경우
                push(charinput[j]);  //괄호를 스텍에 밀어넣는다.
            }
            else if (charinput[j] == ')') { //괄호의 끝에 있는경우 가장 가까이 있는 괄호까지 저장한 부호를 꺼낸다.
                while (1) {
                    booho = pop();
                    if (booho == '(')
                        break;
                    else {
                        backchar[backi] = booho;  //꺼낸 부호를 후위표시로 저장할 배열에 집어넣고 인덱스를 증가시킨다.
                        backi++;
                    }
                }
            }
            else if (charinput[j] == '+') {    //부호를 만나면 push한다.
                if (finalbooho == '*' || finalbooho == '/')//우선순위를 주어 */값은 바로바로꺼낸후 현재 부호를 스텍이 집어넣는다.
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
        if (j == (length - 1)) { //수식의 끝에 도달한 경우 모든 저장된 부호를 스텍에서 꺼낸후 후위표시로 저장할 배열에 집어넣는다.
            while (1) {
                booho = pop();
                if (booho == 0) //꺼낼 부호가 없을경우
                    break;
                else {   //꺼낼 부호가 있을경우
                    backchar[backi] = booho;
                    backi++;
                }
            }
        }
    }
    length = backi; //총 길이를 후위표현되서 바뀐 배열의 길이로 다시 저장( 괄호가 빠진 길이)
    printf("-----------\n");
    for (j = 0; j < length; j++) {
        printf("%d. int=%f  // char=%c\n", j, backint[j], backchar[j]);
    }
}
void guesan() //후위표시로전환된 수식을 계산하는함(배열을 스택과 같은 방법으로 사용)
{
    int k;
    int j = 0;  //스택처럼 배열에 넣을떄 사용하는 변수(스택의 top개념)
    double lastdap[Size];//스택처럼 사용할 배열 
    for (k = 0; k < length; k++) {
        if (backchar[k] != '+' && backchar[k] != '-' && backchar[k] != '*' && backchar[k] != '/') { //후위표식으로 배열 값이 숫자일 경우
            lastdap[j] = backint[k];      //후위표현된 배열의 값을 현제 인덱스의 저장
            j++;           //인덱스를 증가시킨다.
        }
        else {                 ////후위표식으로 배열 값이 =-*/일 경우
            if (backchar[k] == '*') {  //계산한다.
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
        printf("잘못입력되었습니다.");

    printf("1.%s -------2.%s\n", argv[0], argv[1]);
    inputt();//입력된 수식을 더블형와 캐릭터형으로 변환
    change();//변환된 더블형과 캐릭터형을 후위표식으로 변환
    guesan();//후위표식으로 변환된 배열을 계산 후 출력
    scanf_s("%d", &j);	//화면이 꺼지지 않게 하기위해 임시로 넣음
    return 1;
}
