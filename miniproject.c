#include <stdio.h>
#include <string.h>

// 직원 한 명에 대한 이름, 출퇴근, 휴게 시간 데이터 저장할 구조체 정의
typedef struct{ 
    char name[100];
    int month, day;
    int in_hour, in_minute;
    int out_hour, out_minute;
    int rest_hour, rest_minute;
} Employee;

int createProduct(Employee *e);             // 함수명 수정, 앞으로 함수명 수정해야 하는 부분은 // -으로 표시
void readProduct(Employee *e);              // -
int updateProduct(Employee *e);             // -
int deleteProduct(Employee *e);             // -
void listProduct(Employee *e,int count);    // -
void saveData(Employee *e, int count);
int loadData(Employee *e);
int selectMenu();
int selectDataNo(Employee *e, int count);
void showInTime(Employee *e, int count);
void showOutTime(Employee *e, int count);
void searchTime(Employee *e, int count);
void calculateDailyWage(Employee *e, int count);
int create_emp(Employee *a);

int create_emp(Employee *a){
    char name[100] ;
    char date[100] ;

    printf("날짜입력 ex) 7월5일 -> 7/5\n");
    printf("날짜: ");
    scanf("%d/%d", &a->month, &a->day);
    printf("이름을 입력하세요: ");
    scanf("%s", a->name);
    printf("시간은 24시 기준 예) 19:15\n");
    printf("\n 출근시간: ");
    scanf("%d:%d", &a->in_hour, &a->in_minute);
    printf("퇴근시간: ");
    scanf("%d:%d", &a->out_hour, &a->out_minute);
    printf("휴식시간: ");
    scanf("%d:%d", &a->rest_hour, &a->rest_minute);

    return 1;
}

void calculateDailyWage(Employee *e, int count){
    char search[20];
    int wage;
    int working_time;

    printf("일급을 검색할 직원의 이름을 입력하세요 : ");
    printf("\t(일급은 최저시급으로 계산됩니다. 현재 최저시급: 9,160원)\n");
    scanf("%s", search);

    for(int i = 0; i<count; i++){
        if(e[i].month == -1) continue;
        if(strstr(e[i].name, search)){
            working_time = ((e[i].out_hour*60 + e[i].out_minute) - (e[i].in_hour * 60 + e[i].in_minute)) - (e[i].rest_hour*60 + e[i].rest_minute);
            working_time /= 60;
            wage = 9160 * (working_time);
            printf("직원 %s의 %d월 %d일의 하루 임금은 %d원 입니다.\n",e[i].name, e[i].month, e[i].day, wage);
        }
    }
}

void searchTime(Employee *e, int count){
    int scnt = 0;
    char search[20];

    printf("출퇴근 시간이 언제인지 검색할 직원의 이름을 입력하세요 : ");
    scanf("%s", search);

    for(int i = 0; i<count; i++){
        if(e[i].month == -1) continue;
        if(strstr(e[i].name, search)){
            readProduct(&e[i]);
            scnt++;
        }
    }
    if(scnt == 0)
    printf("=> 검색된 데이터 없음! \n");
}

void showInTime(Employee *e, int count){
    printf("---- 출근 시간 시간별 통계 ----\n");
    printf(" (오전 6~7시, 7~8시, 8~9시, 9~10시로 나누어서 결과 보여줌)\n");
    char mark = '*';
    for (int time = 6; time <= 9; time++){ // 6시부터 10시까지 한시간 간격으로 출근한 사람들 데이터 출력
        int cnt = 0;
        for(int i=0; i<count; i++){
            if( e[i].in_hour == time){
                cnt++;
            }
        }
        printf("[ 오전 %d시 ~ %d시 ]에 출근한 사람 수 : %d\n  ", time, time+1, cnt);
        for(int i = 0; i < cnt; i++)
            printf("%c", mark);
        printf("\n\t:");
        for(int i=0; i<count; i++){
            if( e[i].in_hour == time){
                printf("%s ",e[i].name);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void showOutTime(Employee *e, int count){
    printf("---- 퇴근 시간 시간별 통계 ----\n");
    printf(" (오후 5~6시, 6~7시, 7~8시, 8시~9시로 나누어서 결과 보여줌)\n");
    char mark = '*';
    for (int time = 5; time <= 8; time++){ // 5시부터 9시까지 한시간 간격으로 출근한 사람들 데이터 출력
        int cnt = 0;
        for(int i=0; i<count; i++){
            if( e[i].out_hour-12 == time){ // 18시는 오후 6시임(18-12 = 6)
                cnt++;
            }
        }
        printf("[ 오후 %d시 ~ %d시 ]에 퇴근한 사람 수 : %d\n  ", time, time+1, cnt);
        for(int i = 0; i < cnt; i++)
            printf("%c", mark);
        printf("\n\t:");
        for(int i=0; i<count; i++){
            if( e[i].out_hour == time){
                printf("%s ",e[i].name);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int selectMenu(){
    int menu;
    printf("\n*** 직원들 출퇴근 관리 시스템 ***\n");
    printf("============  메 뉴  ===========\n\n");
    printf("1. 등록된 직원 출퇴근 정보 조회\n");
    printf("2. 직원 출퇴근 정보 추가\n");
    printf("3. 직원 출퇴근 정보 수정\n");
    printf("4. 직원 출퇴근 정보 삭제\n");
    printf("5. 등록된 직원 출퇴근 정보 저장\n");
    printf("6. 출근 시간 시간별 통계\n");
    printf("7. 퇴근 시간 시간별 통계\n");
    printf("8. 직원 출퇴근 시간 검색\n");
    printf("9. 직원 일급 계산\n");
    printf("0. 프로그램 종료\n\n");
    printf("\n================================\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

// 함수 구현 임의로
int createProduct(Employee *p){
    printf("\n");
    printf("직원 이름 : ");
    scanf("%s",p->name);

    printf("출근 시간 - 시 : ");
    scanf("%d",&p->in_hour);

    printf("출근 시간 - 분 : ");
    scanf("%d",&p->in_minute);

    printf("퇴근 시간 - 시 : ");
    scanf("%d",&p->out_hour);

    printf("퇴근 시간 - 분 : ");
    scanf("%d",&p->out_minute);

    printf("총 휴게 시간 - 시 : ");
    scanf("%d",&p->rest_hour);

    printf("총 휴게 시간 - 분 : ");
    scanf("%d",&p->rest_minute);
    
    printf("==> 추가됨\n"); 
    return 1;
}

// 함수 구현 임의로
void readProduct(Employee *p){
    printf("%-10s 출근시간: %4d:%d, 퇴근시간: %4d:%d\n",p->name,p->in_hour,p->in_minute, p->out_hour, p->out_minute);
}

// 함수 구현 임의로
int updateProduct(Employee *p){


    return 1;
};

// 함수 구현 임의로
int deleteProduct(Employee *p){
    p->month=-1;
    p->month=-1;
    printf("==> 삭제됨!\n");
    return 0;
}

// 함수 구현 임의로
void listProduct(Employee *p,int count){

}

int selectDataNo(Employee *p, int count){
    int no;
    listProduct(p,count);                       // -
    printf("고르려는 번호는 (취소: 0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

//배열데이터를 파일에 저장하는 함수
// 함수 구현 임의로
void saveData(Employee p[], int count){
    
}

//파일에서 데이터 불러오는 함수
// 함수 구현 임의로
int loadData(Employee *p){
    
    return 0;
}


int main(void){
    Employee elist[100];                    // 100명의 직원 관리
    int curcount=0;
    int count = 0, menu;
    
    count = loadData(elist);
    curcount=count; 

    while (1){
        menu = selectMenu();
        getchar();
        if(menu == 0) break;
        if(menu == 1 || menu ==3 || menu == 4){	
		    if (count==0){ 
                printf("데이터가 없습니다.\n");
			    continue;
			}
		}

        if(menu == 1) listProduct(elist,curcount);              // -
        else if (menu == 2) {
            count+=createProduct(&elist[curcount++]);           // -
        }
        else if (menu == 3) {
            int no=selectDataNo(elist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            updateProduct(&elist[no-1]);                        // -
        }
        else if (menu == 4) {
            int no=selectDataNo(elist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct(&elist[no-1])) count --;       // -  
           	 } 
        }
	    else if (menu == 5){
		    if (count==0) printf("데이터가 없습니다.\n");
		    else saveData(elist,curcount);
	    }
        else if (menu == 6){
		    if (count==0) printf("데이터가 없습니다.\n");
		    else showInTime(elist,curcount);
	    }
        else if (menu == 7){
		    if (count==0) printf("데이터가 없습니다.\n");
		    else showOutTime(elist,curcount);
	    }
        else if (menu == 8){
		    if (count==0) printf("데이터가 없어 검색할 수 없습니다.\n");
		    else searchTime(elist,curcount);
	    }
        else if (menu == 9){
		    if (count==0) printf("데이터가 없어 검색할 수 없습니다.\n");
		    else calculateDailyWage(elist,curcount);
	    }
	}

	printf("\n종료됨!\n");
   	return 0;
}
