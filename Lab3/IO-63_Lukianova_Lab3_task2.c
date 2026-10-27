#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif
#define URL_LEN 100

typedef struct Node {
    char         url[URL_LEN];
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void stack_init(Stack *s)            { s->top = NULL; }
int  is_empty(const Stack *s)        { return s->top == NULL; }
int  is_full(const Stack *s)         { (void)s; return 0; }

int push(Stack *s, const char *value)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) return 0;
    strncpy(n->url, value, URL_LEN - 1);
    n->url[URL_LEN - 1] = '\0';
    n->next = s->top;
    s->top = n;
    return 1;
}

int pop(Stack *s, char *out)
{
    Node *n;
    if (is_empty(s)) return 0;
    n = s->top;
    strcpy(out, n->url);
    s->top = n->next;
    free(n);
    return 1;
}

int peek(const Stack *s, char *out)
{
    if (is_empty(s)) return 0;
    strcpy(out, s->top->url);
    return 1;
}

void stack_clear(Stack *s)
{
    Node *n;
    while (s->top != NULL) {
        n = s->top;
        s->top = n->next;
        free(n);
    }
}

void stack_destroy(Stack *s)         { stack_clear(s); }

#define HOME_PAGE "home"

typedef struct {
    Stack back;
    Stack forward;
    char  current[URL_LEN];
} Browser;

static void browser_init(Browser *b)
{
    stack_init(&b->back);
    stack_init(&b->forward);
    strcpy(b->current, HOME_PAGE);
}

static void browser_destroy(Browser *b)
{
    stack_destroy(&b->back);
    stack_destroy(&b->forward);
}

static void browser_go(Browser *b, const char *url)
{
    if (!push(&b->back, b->current)) {
        printf("Помилка: історія «Назад» переповнена, перехід неможливий.\n");
        return;
    }
    strncpy(b->current, url, URL_LEN - 1);
    b->current[URL_LEN - 1] = '\0';
    stack_clear(&b->forward);
}

static void browser_back(Browser *b)
{
    char page[URL_LEN];

    if (is_empty(&b->back)) {
        printf("Неможливо: стек «Назад» порожній (це перша сторінка історії).\n");
        return;
    }
    if (!push(&b->forward, b->current)) {
        printf("Помилка: стек «Вперед» переповнений.\n");
        return;
    }
    pop(&b->back, page);
    strcpy(b->current, page);
}

static void browser_forward(Browser *b)
{
    char page[URL_LEN];

    if (is_empty(&b->forward)) {
        printf("Неможливо: стек «Вперед» порожній (немає сторінок, на які можна піти вперед).\n");
        return;
    }
    if (!push(&b->back, b->current)) {
        printf("Помилка: стек «Назад» переповнений.\n");
        return;
    }
    pop(&b->forward, page);
    strcpy(b->current, page);
}

static void browser_show(const Browser *b)
{
    char page[URL_LEN];

    printf("Поточна сторінка: %s\n", b->current);
    if (peek(&b->back, page))    printf("  Назад поверне на: %s\n", page);
    else                         printf("  Назад: порожньо\n");
    if (peek(&b->forward, page)) printf("  Вперед поверне на: %s\n", page);
    else                         printf("  Вперед: порожньо\n");
}

static void print_help(void)
{
    printf("Команди:\n");
    printf("  go <сторінка>  - перейти на нову сторінку\n");
    printf("  back           - назад\n");
    printf("  forward        - вперед\n");
    printf("  show           - показати стан історії\n");
    printf("  exit           - завершити роботу\n");
}

int main(int argc, char *argv[])
{
    Browser b;
    FILE   *in = stdin;
    int     interactive = 1;
    char    line[256], cmd[32], arg[URL_LEN];
    int     n;

#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif


    if (argc > 1) {
        in = fopen(argv[1], "r");
        if (in == NULL) {
            printf("Не вдалося відкрити файл %s\n", argv[1]);
            return 1;
        }
        interactive = 0;
    }

    browser_init(&b);
    if (interactive) print_help();
    printf("Поточна сторінка: %s\n", b.current);

    for (;;) {
        if (interactive) { printf("> "); fflush(stdout); }
        if (fgets(line, sizeof line, in) == NULL) break;

        line[strcspn(line, "\r\n")] = '\0';
        n = sscanf(line, "%31s %99s", cmd, arg);
        if (n < 1) continue;
        if (!interactive) printf("> %s\n", line);
        if (strcmp(cmd, "exit") == 0) break;

        if (strcmp(cmd, "go") == 0) {
            if (n < 2) { printf("Вкажіть сторінку: go <сторінка>\n"); continue; }
            browser_go(&b, arg);
            printf("Поточна сторінка: %s\n", b.current);
        } else if (strcmp(cmd, "back") == 0) {
            browser_back(&b);
            printf("Поточна сторінка: %s\n", b.current);
        } else if (strcmp(cmd, "forward") == 0) {
            browser_forward(&b);
            printf("Поточна сторінка: %s\n", b.current);
        } else if (strcmp(cmd, "show") == 0) {
            browser_show(&b);
        } else {
            printf("Невідома команда: %s\n", cmd);
        }
    }

    printf("Остаточна поточна сторінка: %s\n", b.current);
    browser_destroy(&b);
    if (in != stdin) fclose(in);
    return 0;
}
