char* reverseParentheses(char* s) {
    int n = strlen(s);
    int* oppind = malloc(n * sizeof(int));
    int tos = -1;
    int stack[2001];

    for (int i = 0; i < n; i++) {
        oppind[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++tos] = i;
        } else if (s[i] == ')') {
            int openindex = stack[tos--];
            oppind[openindex] = i;
            oppind[i] = openindex;
        }
    }

    char* ans = malloc((n + 1) * sizeof(char));
    int dir = 1, index = 0;

    for (int i = 0; i < n; i += dir) {
        if (s[i] == '(' || s[i] == ')') {
            i = oppind[i];
            dir *= -1;
        } else {
            ans[index++] = s[i];
        }
    }

    ans[index] = '\0';
    return ans;
}
