#include <stdio.h>
#include <string.h>

void patternMatch(char text[], char pattern[]) {
    int t_len = strlen(text);
    int p_len = strlen(pattern);
    int found = 0;

    for (int i = 0; i <= t_len - p_len; i++) {
        int j;
        for (j = 0; j < p_len; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == p_len) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found)
        printf("Pattern not found.\n");
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    patternMatch(text, pattern);

    return 0;
}
