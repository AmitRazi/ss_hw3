#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
char line[LINE];
char word[WORD];
void shift_right(int *arr, int i){
    while(i > 0){
        *(arr+i) = *(arr+i-1);
        i--;
    }
}
void insertion_sort(int* arr , int len){
    for(int i =1 ; i < len ; i++){
        int temp = *(arr+i);

        int j = i -1;
        while(j>=0 && *(arr+j) > temp){
            j--;
        }
        //memcpy(arr+j+1,arr+j,sizeof(int)*(i-j));
        shift_right(arr+j+1,i-j-1);
        *(arr+j+1) = temp;
    }
}
int get_line(){
    char ch = ' ';
    int i = -1;
    do {
        ch = getchar();
        if (ch == '\n' || ch == EOF) {
           break;
        } else {
           line[++i] = ch;
        }
    } while (ch != EOF);
    if(i == -1) return 0;
    line[i+1] = '\0';
    return 1;
}

int substring(){
    if(strlen(line) < strlen(word)) return 0;
    char *p;
    p = strstr(line,word);
    if(p) return 1;
    return 0;
}

void print_line(){
    while(get_line()){
        if(substring()){
          printf("%s\n",line);
        }
    }
}
int getword(char *buf) {
    char ch = ' ';
    int i = -1;
    do {
        ch = getchar();
        if (ch == '\n' || ch == EOF) {
            break;
        } else {
            buf[++i] = ch;
        }
    } while (ch != ' ' && ch != '\n' && ch != '\t');
    if(i == -1) return 0;
    buf[i+1] = '\0';
    return i;
}
void similar(char *s,int n){
    int i=0,j=0;
    while(word[i] != '\0' && s[j] != '\0'){
        if(s[j] == word[i]){
            i++;
            j++;
        }
        else j++;
    }
    if(word[i] == '\0'){
        printf("%s\n",s);
    }
}
void print_similiar_words(){
    char buf[WORD];
    while(getword(buf)){
        if(strlen(buf) >= strlen(word)){
            similar(buf,1);
        }
    }
}

int main() {

	/*int arr[50] = {0};
	for(int i = 0 ; i < 50 ; i++){
	int temp = 0;
	scanf("%d",&temp);
	arr[i] = temp;
	}
	insertion_sort(arr,sizeof(arr)/sizeof(arr[0]));
	for(int i = 0; i < 50 ; i++){
	printf("%d,",arr[i]);
	}*/
    /* int arr[] = {85, 78, 38,11, 78, 73, 75, 17, 28, 2};
     insertion_sort(arr,sizeof(arr)/sizeof(arr[0]));

     //print_lines("cat");
     for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++){
         if(i != sizeof(arr)/sizeof(arr[0]) -1 )
         printf("%d,",arr[i]);
         else
             printf("%d\n",arr[i]);
     }
    fgets(line,LINE,stdin);
    int i = 0;
    while(*(line+i) != ' '){
        word[i++] =*(line+i);
    }

    i++;
    char choice = *(line+i);

    fgets(line,LINE,stdin);
    print_line();*/
    fgets(line,LINE,stdin);
    int i = 0;
    while(*(line+i) != ' '){
        word[i++] =*(line+i);
    }

    //print_similar_words(word);
    i++;
    char choice = *(line+i);

    fgets(line,LINE,stdin);
    if(choice == 'a'){
        print_line(word);
    } else if(choice == 'b'){
        print_similiar_words(word);
    }
    return 0;
}
