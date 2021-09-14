#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

int count_char(char* str, char target) {
    int x=0;
    int y=strlen(str);
    for(int i=0; i<=y-1; ++i){
        if(target==str[i]){
            ++x;
        }else{
            continue;
        }
    }
    return x;
}

int count_int(int* lon, int len, int target) {
    int a=0;
    for(int i=0; i<=len-1; ++i){
        if(lon[i]==target){
            ++a;
        }
    }
  return a;
}

char* my_strcat(char* str1, char* str2) {
    int a=strlen(str1);
    int b=strlen(str2);
    int l=str1;
    char *c=malloc((a+b+1)*sizeof(char))
    for(int i=0; i<=a-1; ++i){
        c[i]=str1[i];
    }
    for(int i=0; i<=b-1; ++i){
        c[l]=str2[i];
        ++l
    }
    retuurn c;
}

char* remove_white(char* str) {
    int len=strlen(str);
    int x=0;
    char c=malloc((len+1)*sizeof(char));
    for(int i=0; i<=len-1; ++i){
        if(str[i]==' '){
            continue;
        }else{
            c[x]=str[i];
            ++x;
        }
    }
    return c;
    free(c);
}

char* connect_all(char** los, int len) {
    int x=0;
    int p=0;
    for(int i=0; i<=len-1; ++i){
        int l=strlen(los[i]);
        x=x+l;
    }
    char *c=malloc((x+1)*sizeof(char));
    for(int i=0; i<=len-1; ++i){
        int a=i;
        for(int j=0; j<=strlen(los[a])-1; ++j){
            c[p]=los[a][j];
            ++p;
        }
    }
    return c;
    free(c);
}

int filter(int **arr, int len, bool (*pred) (int)) {
  return 0;
}

bool is_plalindrome(char* str) {
    int a=1;
    int len=strlen(str);
    int b=0;
    int c=len-1;
    while(b<=(len-1)/2){
        if(str[b]==str[c]){
            ++b;
            --c;
        }
        else{
            a=0;
            break;
        }
    }
    if(a==1){
        return true;
    }else{
        return false;
    }
}


void merge_array(int* destination, int* arr1, int* arr2, int len1, int len2) {
    int p1=0;
    int p2=0;
    int p3=0;
    while(p1<=len1-1&&p2<=len2-1){
        if(p1==len1-1){
            destination[p3]=arr2[p2];
            ++p2;
            ++p3;
        }else if(p2==len2-1){
            destination[p3]=arr1[p1];
            ++p1;
            ++p3;
        }else if(arr1[p1]<=arr2[p2]){
            destination[p3]=arr1[p1];
            ++p1;
            ++p3
        }else{
            destination[p3]=arr2[p2];
            ++p2;
            ++p3;
        
    }

}

void* find_extreme(void** arr, int len, bool(*compare_func)(void*, void*)) {
    
}

/* for testing filter/find_max */
bool is_even(int n) {
  return n % 2 == 0;
}

bool is_greater_4(int n) {
  return n > 4;
}

bool is_greater(void* n, void* m) {
  int* a = (int*) n;
  int* b = (int*) m;
  return *a < *b;
}

bool is_smaller(void* n, void* m) {
  int* a = (int*) n;
  int* b = (int*) m;
  return *a > *b;
}

/* tests */

int main() {
  /* tests for count_char */
  assert(count_char("This is a pretty long string you know?", 's') == 3);
  assert(count_char("eagle", 'e') == 2);
  assert(count_char("eagle", 'a') == 1);
  assert(count_char("eagle", 'z') == 0);
  printf("count_char passed\n");

  /* tests for count_int */

  int arr[] = {1, 2, 3, 1, 2, 3, 1};
  assert(count_int(arr, 7, 1) == 3);
  assert(count_int(arr, 7, 2) == 2);
  assert(count_int(arr, 7, 3) == 2);
  printf("count_int passed\n");

  /* tests for my_strcat */

  char* srv = my_strcat("a", "b");
  assert(strcmp(srv, "ab") == 0);
  free(srv);

  srv = my_strcat("", "b");
  assert(strcmp(srv, "b") == 0);
  free(srv);

  srv = my_strcat("a", "");
  assert(strcmp(srv, "a") == 0);
  free(srv);

  srv = my_strcat("eagle", "sogood");
  assert(strcmp(srv, "eaglesogood") == 0);
  free(srv);

  printf("my_strcat passed\n");

  /* tests for remove_white */

  srv = remove_white("nowhite");
  assert(strcmp(srv, "nowhite") == 0);
  free(srv);

  srv = remove_white("n o w h     i te");
  assert(strcmp(srv, "nowhite") == 0);
  free(srv);

  printf("remove_white passed\n");

  /* tests for connect_all */

  char* ss[] = {"e", "agle", "ru", "le"};
  srv = connect_all(ss, 4);
  assert(strcmp(srv, "eaglerule") == 0);
  free(srv);

  printf("connect_all passed\n");

  /* tests for filter */

  int* ints = (int*)malloc(sizeof(int) * 10);
  for(int i = 0; i < 10; i++) {
    ints[i] = i;
  }
  int nlen = filter(&ints, 10, is_even);
  assert(nlen == 5);
  assert(ints[0] == 0);
  assert(ints[1] == 2);
  assert(ints[2] == 4);
  assert(ints[3] == 6);
  assert(ints[4] == 8);

  nlen = filter(&ints, 5, is_greater_4);
  assert(nlen == 2);
  assert(ints[0] == 6);
  assert(ints[1] == 8);
  free(ints);

  printf("filter passed\n");

  /* tests for is_plalindrome */

  assert(is_plalindrome("aba") == true);
  assert(is_plalindrome("abba") == true);
  assert(is_plalindrome("abcba") == true);
  assert(is_plalindrome("a") == true);
  assert(is_plalindrome("aBA") == false);
  assert(is_plalindrome("abc") == false);
  assert(is_plalindrome("abbbaa") == false);

  printf("is_plalindrome passed\n");

  /* tests for merge_array */

  int narr1[] = {2, 4, 6, 9};
  int narr2[] = {1, 3, 5};
  int* dest = malloc(sizeof(int) * 7);
  merge_array(dest, narr1, narr2, 4, 3);
  assert(dest[0] == 1);
  assert(dest[1] == 2);
  assert(dest[2] == 3);
  assert(dest[3] == 4);
  assert(dest[4] == 5);
  assert(dest[5] == 6);
  assert(dest[6] == 9);
  merge_array(dest, narr2, narr1, 3, 4);
  assert(dest[0] == 1);
  assert(dest[1] == 2);
  assert(dest[2] == 3);
  assert(dest[3] == 4);
  assert(dest[4] == 5);
  assert(dest[5] == 6);
  assert(dest[6] == 9);
  free(dest);

  printf("merge_array passed\n");

  /* tests for find_extreme */
  int n1 = 1;
  int n2 = 2;
  int n3 = 3;
  void** varr = malloc(sizeof(void*) * 3);
  varr[0] = &n1;
  varr[1] = &n2;
  varr[2] = &n3;
  assert(*((int*)find_extreme(varr, 3, is_smaller)) == 1);
  assert(*((int*)find_extreme(varr, 3, is_greater)) == 3);
  free(varr);
  printf("find_max passed\nyou are the BOSS!\n");
}
