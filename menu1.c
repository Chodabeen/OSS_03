#include <stdio.h>

// Menu 구조체 정의(이름, 종류, 가격)
typedef struct{
    char name[30];  // 한글을 utf-8에서 3 byte를 차지하기 때문에, 먹물 고르곤졸라를 입력하기 위해 크기를 30으로 늘렸다
    char type;
    int price;
} Menu;

// 입력버퍼를 지우는 함수
void ClearLineFromReadBuffer(void){
    while(getchar() != '\n'); 
}

//하나의 Menu 데이터 추가 함수
int addMenu(Menu *m){
    ClearLineFromReadBuffer();
    printf("메뉴명은? ");
    scanf("%[^\n]s", m->name);
    ClearLineFromReadBuffer();
    printf("메뉴종류(P/S/R)? ");
    scanf("%c", &m->type);
    ClearLineFromReadBuffer();
    printf("가격은? ");
    scanf("%d", &m->price);
    ClearLineFromReadBuffer();
    
    return 1;
}

// 하나의 데이터 조회 기능 구현
void readMenu(Menu m){
    printf("*****************\n");
    printf("1 %5d %c %s\n", m.price, m.type, m.name);
}

// 하나의 데이터 수정 기능 구현
int updateMenu(Menu *m){
    ClearLineFromReadBuffer();
    printf("새 메뉴명은? ");
    scanf("%[^\n]s", m->name);
    ClearLineFromReadBuffer();
    printf("새 메뉴종류(P/S/R)? ");
    scanf("%c", &m->type);
    ClearLineFromReadBuffer();
    printf("새 가격은? ");
    scanf("%d", &m->price);
    ClearLineFromReadBuffer();
    printf("수정성공!\n");
    
    return 1;
}

// 하나의 데이터 삭제 기능 구현
int deleteMenu(Menu *m){
    m->price = -1;
    return 1;
}

// 유저가 사용할 기능 선택
int selectMenu(){
    int num;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &num);
    return num;
}

// 전체 프로그램을 구성하는 main 함수 구현
int main(void){
    Menu m;
    int count = 0, num;

    while(1) {
        num = selectMenu();

        if(num == 0)
            break;
        if(count == 0){
            if(num == 1 || num == 3 || num == 4){
                printf("저장된 데이터가 없습니다. 다시 메뉴를 선택해주세요\n");
                continue; // 데이터가 없는데 추가 이외에 명령을 내리면 selectMenu 창을 다시 보여줌
            }
        }
        if(num == 1)
            readMenu(m);
        else if(num == 2){
            count += addMenu(&m);
        }
        else if(num == 3){
            updateMenu(&m);
        }
        else if(num == 4){
            int isdel = deleteMenu(&m);
            if(isdel == 1)
                printf("=> 삭제됨!\n");
        }
    }
    printf("종료됨!\n");
    return 0;
}


