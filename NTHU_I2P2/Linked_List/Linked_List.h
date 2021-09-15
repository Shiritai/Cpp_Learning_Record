/* for C */

# ifndef _LINKED_LIST_H
# define _LINKED_LIST_H

# include <stdlib.h>
# include <string.h>

# define l_nd list_node

typedef struct t_node {
    void * data;
    size_t sz;
    struct t_node * next;
} list_node;

typedef struct list {
    l_nd * begin, * end;
    int size;
} linked_list;

# include <stdio.h>
/* 假設資料是字串, i.e. char * */
void print_list(linked_list * ls){
    printf("List Size : %d\n", ls->size);
    if (ls->size){
        l_nd * cur = ls->begin;
        do {
            printf("[%s] --> ", (char *) cur->data);
            cur = cur->next;
        } while (cur != ls->begin);
        puts("END");
    }
}

/* return NULL if MLE */
l_nd * __to_node(void * data, size_t sz){
    l_nd * ret = (l_nd *) malloc(sizeof(l_nd));
    if (!ret)
        return NULL;
    ret->sz = sz;
    ret->data = malloc(ret->sz);
    memcpy(ret->data, data, ret->sz);
    ret->next = ret; // circular linked_list
    return ret;
}

void __free_node(l_nd * node){
    free(node->data);
    free(node);
}

void init_list(linked_list * list_to_init){
    list_to_init->begin = list_to_init->end = NULL;
    list_to_init->size = 0;
}

void push_back(linked_list * ls, void * data, size_t data_size){
    l_nd * tail = __to_node(data, data_size);
    if (!ls->size){
        ls->begin = ls->end = tail;
        ++(ls->size);
        return;
    }
    tail->next = ls->begin; // circular
    (ls->end)->next = tail; // concatenate nodes
    ls->end = tail; // move the end pointer
    ++(ls->size);
}

/* deep copy without changing OTHER's nodes */
void push_back_list(linked_list * ls, linked_list * other){
    if (!other->size)
        return;
    ls->size += other->size;
    l_nd * o_trave = other->begin;
    do {
        push_back(ls, o_trave->data, o_trave->sz);
    } while (o_trave != other->begin); // 等到 o_trave 轉回來就表示遍歷完整個 other 了
}

void push_front(linked_list * ls, void * data, size_t data_size){
    l_nd * lead = __to_node(data, data_size);
    if (!ls->size){
        ls->begin = ls->end = lead;
        ++(ls->size);
        return;
    }
    lead->next = ls->begin;
    ls->begin = lead;
    ls->end->next = ls->begin; // circular
    ++(ls->size);
}

/* pop a data from the given list */
void * pop_front(linked_list * ls){
    void * ret = NULL;
    if (ls->size){
        ret = ls->begin->data;
        if (ls->begin == ls->end){
            __free_node(ls->begin);
            ls->begin = ls->end = NULL;
        }
        else {
            ls->end->next = ls->begin->next;// 要刪除, ls->begin, 將 ls->end 下一個 (指到 begin 的) 指標移動
            __free_node(ls->begin);
            ls->begin = ls->end->next; // 將 begin 指標指到新的首個元素
        }
        --(ls->size);
    }
    return ret;
}

void * pop_back(linked_list * ls){
    void * ret = NULL;
    if (ls->size){
        ret = ls->end->data;
        if (ls->begin == ls->end){ // 也可以 ls->size == 1
            __free_node(ls->begin);
            ls->begin = ls->end = NULL;
        }
        else {
            l_nd * cur = ls->begin;
            while (cur->next != ls->end)
                cur = cur->next;
            __free_node(ls->end);
            ls->end = cur;
        }
    }
    return ret;
}

void clean(linked_list * ls){
    ls->size = 0;
    while (ls->size)
        pop_front(ls);
}

# endif