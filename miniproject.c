#include <stdin.h>

typedef struct{
    char name[100];
    int month, day;
    int in_hour, in_minute;
    int out_hour, out_minute;
    int rest_hour, rest_minute;
} Employee;

int create_emp(Employee *a){
    char [100] name;
    char [100] date;

    printf("날짜입력 ex) 7월5일 -> 7/5\n");
    printf("날짜: ");
    scanf("%d/%d", &month, &day);
    printf("이름을 입력하세요: ");
    scanf("%s", a->name);
    printf("시간은 24시 기준 예) 19:15\n");
    printf("\n 출근시간: ");
    scanf("%d:%d", &in_hour, &in_minute);
    printf("퇴근시간: ");
    scanf("%d:%d", &out_hour, &out_minute);
    printf("휴식시간: ");
    scanf("%d:%d", &rest_hour, &rest_minute);
}


