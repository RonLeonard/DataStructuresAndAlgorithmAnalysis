#include <iostream>


int find_notuseguard(const char *s, int size, char value)
{
    if (s == nullptr || size <= 0)
        return -1;
    
    int i = 0;
    while (i < size) {
        if (s[i] == value)
            return i;
        i++;
    }
    return -1;
}

int find_useguard(char *s, int size, char value)
{
    if (s == nullptr || size <= 0) {
        return -1;
    }
        
    int i = 0;
    if (s[size - 1] == value) {
        return size - 1;
    }
        
    
    char tmp = s[size - 1];
    s[size - 1] = value;

    while (s[i] != value) {
        i++;
    }

    s[size - 1] = tmp;

    if (i == size - 1) {
         return -1;
    }
    else {
        return i;
    }
        

}

int main(int argc, char *argv[])
{
    //char a[6] = {1, 2, 3, 4, 5, 6}; 
    char *a = "123456";
    int i;
    i = find_notuseguard(a, 6, '4');
    printf("i = %d\n", i);
    return 0;
}