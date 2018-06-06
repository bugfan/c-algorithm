#include <stdio.h>
#include <malloc.h>

struct Mq
{
    int data;
    struct Mq *next;
};
int In(struct Mq *mq, int v)
{
    struct Mq *new;
    new = (struct Mq *)malloc(sizeof(struct Mq));
    new->data = v;
    // new->next = mq;
    mq = new;
    return v;
}
int Out(struct Mq *mq)
{
    int retData = mq->data;
    *mq = *mq->next;
    return retData;
}
int main()
{
    struct Mq *m;
    m = (struct Mq *)malloc(sizeof(struct Mq));
    int v = 23;
    // m->data = &v;
    // printf("%d,%d\n", *(int *)m->data);
    printf("%d\n", In(m, v));
    printf("%d\n", m->data);
    struct Mq *m2;
    m2 = m->next;
    printf("%d\n", m2->data);

    int v1 = 24;
    // printf("%d\n", In(m, v1));

    // int v2 = 24;
    // In(m, &v2);
    // printf("%d\n", m->next->data);
}