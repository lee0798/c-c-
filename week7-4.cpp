#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH	21

// DO NOT MODIFY //
struct Node {
    char url[MAX_URL_LENGTH];
    struct Node* prev;
    struct Node* next;//더블링크드 리스트에 전 후 노드
};

typedef struct {
    struct Node* head;
    struct Node* cursor;// 커서는 현재 위치
} BrowserHistory;
// DO NOT MODIFY //

BrowserHistory* browserHistoryCreate(char* homepage) {//초기 url을 만들때 사용 그 후 부터는 visit사용
    BrowserHistory* urlhis = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->url, homepage); // 홈페이지주소를 url에 복사하기
    urlhis->head = node;
    urlhis->cursor = node;
    node->prev = NULL;
    node->next = NULL;
    return urlhis;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    if (obj->cursor->next != NULL)
    {//새로 방문 하면 앞으로 가기가 다 삭제 해야하니까
        obj->cursor->next->prev = NULL;
    }
    newNode->prev = obj->cursor;
    newNode->next = NULL;
    //교수님이 얘기하신 것 중에 새로 방문할 경우 앞의 기록들을 다 지워야 한다..
    obj->cursor->next = newNode;
    obj->cursor = newNode;// 더블 링크드리스트 활용 새로운 url연결하기 커서의 위치는 visit함수에서 넣으면 url주소이다.
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {//메인 함수에서 obj와 몇칸 이동 할 지 정보를 받아온다(cmd,parm)을 통해서 steps수가 여태까지 forward 스탭보다 많다면 반복문 정지
    while (obj->cursor->prev != NULL && steps > 0)
    {
        obj->cursor = obj->cursor->prev;
        steps--;
    }
    return obj->cursor->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {//메인 함수에서 obj와 몇칸 이동 할 지 정보를 받아온다(cmd,parm)을 통해서 steps수가 여태까지 back 스탭보다 많다면 반복문 정지
    while (obj->cursor->next != NULL && steps > 0)
    {
        obj->cursor = obj->cursor->next;
        steps--;
    }
    return obj->cursor->url;
}

void browserHistoryFree(BrowserHistory* obj) {//동적 할당 했던 구조체를 free선언해주기 더블 링크드 리스트에서 temp선언후 temp free해주었던 것 활용해보기
    struct Node* cur = obj->head;
    while (cur != NULL)
    {
        struct Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
}

// DO NOT MODIFY //
int main() {
    int i = 0, count = 0;
    char arg1[500];
    char arg2[500];
    char cmd[100][500];
    char parm[100][500];
    char output[100][500];

    fgets(arg1, 500, stdin);//한줄 입력 받기
    fgets(arg2, 500, stdin);
    arg1[strlen(arg1) - 1] = '\0';//마지막 문자열을 NULL값으로 함으로써 fget받기 종료
    arg2[strlen(arg2) - 1] = '\0';

    char* token = strtok(arg1, " "); // 공백으로 문자열 나누기

    while (token != NULL) {
        strcpy(cmd[i], token); // 나눈 문자열을 배열에 저장하기
        token = strtok(NULL, " ");
        i++;
    }

    count = i;

    i = 0;
    token = strtok(arg2, " "); // 공백으로 문자열 나누기
    while (token != NULL) {
        strcpy(parm[i], token); // 나눈 문자열을 배열에 저장하기
        token = strtok(NULL, " ");
        i++;
    }


    BrowserHistory* obj;
    for (i = 0; i < count; i++) {//for문을 돌면서 cmd, parm의 배열값을 세트로 받아옴 
        if (strcmp(cmd[i], "BrowserHistory") == 0) {
            obj = browserHistoryCreate(parm[i]);
        }
        else if (strcmp(cmd[i], "visit") == 0) {
            browserHistoryVisit(obj, parm[i]);
        }
        else if (strcmp(cmd[i], "back") == 0) {
            printf("%s ", browserHistoryBack(obj, atoi(parm[i])));//atoi 두자리수 이상 문자열도 숫자로 바꿀수 있음 
        }
        else if (strcmp(cmd[i], "forward") == 0) {
            printf("%s ", browserHistoryForward(obj, atoi(parm[i])));
        }
    }
    browserHistoryFree(obj);
    return 0;
}
// DO NOT MODIFY //