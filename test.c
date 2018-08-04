#include <stdio.h>
#include <malloc.h>

struct Mq
{
    int data;
    struct Mq *next;
};
struct Mq *MQ;
void init()
{
    MQ = (struct Mq *)malloc(sizeof(struct Mq *));
}
int In(struct Mq *mq, int v)
{
    struct Mq *new;
    new = (struct Mq *)malloc(sizeof(struct Mq *));
    new->data = v;
    // new->next = mq;
    mq = new;
    return v;
}
// int Out(struct Mq *mq)
// {
//     int retData = mq->data;
//     *mq = *mq->next;
//     return retData;
// }
int main()
{
    printf("0:%d\n", MQ->data);
    printf("a:%d\n", In(MQ, 34));
    printf("b:%d\n", MQ->data);
    while (1)
        ;
}