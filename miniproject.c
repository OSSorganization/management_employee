#include <stdio.h>

typedef struct{
    char name[100];
    int month, day;
    int in_hour, in_minute;
    int out_hour, out_minute;
    int rest_hour, rest_minute;
} Employee;

int create_emp(Employee *a){
    char name[100] ;

    printf("날짜입력 ex) 7월5일 -> 7/5\n");
    printf("날짜: ");
    scanf("%d/%d", &a->month, &a->day);
    printf("이름을 입력하세요: ");
    scanf("%s", a->name);
    printf("\n");
    printf("시간은 24시 기준 예) 19:15\n");
    printf("출근시간: ");
    scanf("%d:%d", &a->in_hour, &a->in_minute);
    printf("퇴근시간: ");
    scanf("%d:%d", &a->out_hour, &a->out_minute);
    printf("휴식시간: ");
    scanf("%d:%d", &a->rest_hour, &a->rest_minute);
}

void read_emp(Employee a){

    printf("\n%d월%d일\n", a.month, a.day);
    printf("이름: %s\n", a.name);
    printf("출근시간: %d시%d분\n", a.in_hour, a.in_minute);
    printf("퇴근시간: %d시%d분\n", a.out_hour, a.out_minute);
    printf("휴식시간: %d시%d분\n", a.rest_hour, a.rest_minute);

}

void list_emp(Employee* a, int index){
    for(int i=0; i<index; i++){
        printf("%d번\n, i+1");
        read_emp(a[i]);
        printf("\n");
    }
}

void update_emp(Employee* a, int index){
    int select;
    list_emp(a, index)
    printf("번호는? ");
    scanf("%d", &select);
    


}

int main(){
    Employee a;

    create_emp(&a);
    read_emp(a);
    



}
