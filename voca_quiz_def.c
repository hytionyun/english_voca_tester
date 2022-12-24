#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void){
    int wordNum = 3; //단어 수
    char word[256] = "";  //단어
    char definition[256] = ""; //뜻
    char input[256] = ""; //사용자 입력
    int score = 0;
    char line[10000]; //읽어온 내용 저장용, 줄별로 최대 10000글자씩 읽어오도록 선언
    

    FILE *file = fopen("/Users/raymond/Documents/hytionyun/english_voca_tester/word.txt", "rb");
    if (file == NULL){
        printf("파일이 존재하지 않습니다.");
        return 1;
    }
    for (int i = 0; i < wordNum; i++){
        fscanf(file, "%s %s", word, definition);
        // printf("\n'%s'이라는 뜻을 가진 영어 단어는? \n", definition);
        // scanf("%s", input);

        // if (strcmp(input, word) == 0) {
        //     printf("정답입니다.\n");
        //     score++;
        // } else {
        //     printf("틀렸습니다. 정답은 %s입니다.\n", word);

        // }

        printf("\n\n'%s'의 뜻은? \n", word);
        scanf("%s", input);

        if (strcmp(input, definition) == 0) {
            printf("%s, 정답입니다.\n", definition);
            score++;
        } else {
            printf("틀렸습니다. 정답은 %s입니다.\n", definition);
        }
    }

    fseek(file, 0, SEEK_SET); 
    printf("\n==모든 단어 보기==\n\n");
    while (fgets(line, 10000, file) != NULL){
        printf("%s", line);
    }

    printf("\n==틀린 단어 보기==\n\n");
    while (fgets(line, 10000, file) != NULL){
        printf("%s", line);
    }

    printf("\n\n점수 : %d/%d\n", score, wordNum);
    fclose(file);
    return 0;
}