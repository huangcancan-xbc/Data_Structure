#define _CRT_SECURE_NO_WARNINGS 1

//力扣：20. 有效的括号
//https://leetcode.cn/problems/valid-parentheses/description/

//思路：当遇到一个左括号时，我们把它放到栈顶，等待与之匹配的右括号出现。
// 一旦遇到匹配的右括号，我们就把栈顶的左括号弹出。
// 如果遇到的右括号与栈顶的左括号不匹配，或者在遍历过程中栈为空但遇到了右括号，那么这个字符串就不是一个有效的括号序列。

//即：左括号入栈，右括号与出栈里面的左括号匹配
typedef struct stack
{
    int capacity;
    int top;
    char* a;
} ST;

void STInit(ST* p)
{
    assert(p);

    p->a = (char*)malloc(sizeof(char) * 4);

    if (p->a == NULL)
    {
        perror("malloc fail");
        return;
    }

    p->capacity = 4;
    p->top = -1;
}

bool STEmpty(ST* p)
{
    assert(p);
    return p->top == -1;
}

char STTop(ST* p)
{
    assert(p);
    assert(!STEmpty(p));
    return p->a[p->top];
}

void STDestroy(ST* p)
{
    assert(p);
    free(p->a);
    p->a = NULL;
    p->top = -1;
    p->capacity = 0;
}

void STPush(ST* p, char x)
{
    assert(p);

    if (p->top == p->capacity - 1)
    {
        char* temp = (char*)realloc(p->a, sizeof(char) * p->capacity * 2);

        if (temp == NULL)
        {
            perror("realloc fail");
            return;
        }

        p->a = temp;
        p->capacity *= 2;
    }

    p->a[++p->top] = x;
}

void STPop(ST* p)
{
    assert(p);
    assert(!STEmpty(p));
    p->top--;
}

bool isValid(char* s)
{
    ST temp;
    STInit(&temp);

    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            STPush(&temp, *s);
        }
        else
        {
            if (STEmpty(&temp))
            {
                STDestroy(&temp);
                return false;
            }

            char top = STTop(&temp);
            STPop(&temp);

            if ((*s == ')' && top != '(') ||
                (*s == ']' && top != '[') ||
                (*s == '}' && top != '{'))
            {
                STDestroy(&temp);
                return false;
            }
        }

        s++;
    }

    bool tmp = STEmpty(&temp);
    STDestroy(&temp);
    return tmp;
}