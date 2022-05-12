#include <stdio.h>

// Score 구조체 정의(이름, 국어점수, 영어점수, 수학점수)
typedef struct{
    char name[20];
    int kor;
    int eng;
    int math;
} Score;
 
//하나의 Score 데이터 추가 함수
int addScore(Score *s){
    printf("이름은? ");
    scanf("%s", s->name);
    printf("국어는? ");
    scanf("%d", &s->kor);
    printf("영어는? ");
    scanf("%d", &s->eng);
    printf("수학은? ");
    scanf("%d", &s->math);
    return 1;  // 정상적으로 성공하면 1
}

// 하나의 데이터 조회 기능 구현
void readScore(Score s){
    int sum = s.kor + s.eng + s.math;
    double avg = sum/3.0;

    printf("Name    Kor  Eng  Math  Sum  Avg \n");
    printf("%8s %4d %4d %4d %5d %5.1f\n", s.name, s.kor, s.eng, s.math, sum, avg);
}

// 하나의 데이터 수정 기능 구현
int updateScore(Score *s){
    printf("이름은? ");
    scanf("%s", s->name);
    printf("국어는? ");
    scanf("%d", &s->kor);
    printf("영어는? ");
    scanf("%d", &s->eng);
    printf("수학은? ");
    scanf("%d", &s->math);
    printf("=> 수정성공!\n");
    return 1;
}
// 하나의 데이터 삭제 기능 구현
int deleteScore(Score *s){
    s->kor = -1;
    s->eng = -1;
    s->math = -1;
    return 1;
}

// 유저가 사용할 기능 선택
int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

// 전체 프로그램을 구성하는 main 함수 구현
int main(void){
    Score s;
    int count = 0, menu;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) 
            break;
        if(count == 0){
            if(menu == 1 || menu == 3 || menu == 4){
                printf("저장된 데이터가 없습니다. 다시 메뉴를 선택해주세요\n");
                continue; // 데이터가 없는데 추가 이외에 명령을 내리면 selectMenu 창을 다시 보여줌
            }
        }
        if(menu == 1){
            readScore(s);
        }
        else if(menu == 2){
            addScore(&s);
            count++;
        }
        else if(menu == 3){
            updateScore(&s);
        }
        else if(menu == 4){
            int isdel = deleteScore(&s);
            count--;
            if(isdel == 1)
                printf("=> 삭제됨!\n");
        }
    }
    printf("종료됨!\n");
    return 0;
}
