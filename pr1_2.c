#include <stdio.h>
#include <string.h>

int main() {
    printf("Finite automata is: a+bb\n");
    printf("Enter String: ");
    char str[200];
    scanf("%s", str);

    int i = 0;

    if (str[i] == 'a') {
        while (str[i] == 'a') {
            i++;
        }
        if (str[i] == 'b' && str[i + 1] == 'b' && str[i + 2] == '\0') {
            printf("Accepted\n");
        } else {
            printf("Not Accepted\n");
        }
    } else {
        printf("Not Accepted\n");
    }

    return 0;
}
