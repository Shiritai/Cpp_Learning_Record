#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct t_node {
    struct t_node * left, * right;
    int key, value;
} t_node;

typedef struct Map {
    t_node * root;
} Map;

Map * init(){
    Map * res = (Map *) malloc(sizeof(Map));
    res->root = NULL;
    return res;
}

t_node * __insert(t_node * this, int key, int value){
    if (!this){
        this = (t_node *) malloc(sizeof(t_node));
        this->key = key;
        this->value = value;
        this->left = this->right = NULL;
    }
    else {
        if (key < this->key)
            this->left = __insert(this->left, key, value);
        else if (key > this->key)
            this->right = __insert(this->right, key, value);
    }
    return this;
}

void insert(Map * this, int key, int value){
    this->root = __insert(this->root, key, value);
}

/* Return NULL if the map is empty */
int * get_max_key(Map * this){
    if (!this->root)
        return NULL;
    t_node * cur = this->root;
    while (cur->right)  cur = cur->right;
    int * res = (int *) malloc(sizeof(int));
    * res = cur->key;
    return res;
}

/* Return NULL if the map doesn't contains the given key */
int * get_value(Map * this, int key){
    t_node * cur = this->root;
    while (cur){
        if (cur->key == key){
            int * res = (int *) malloc(sizeof(int));
            * res = cur->value;
            return res;
        }
        if (key > cur->key)
            cur = cur->right;
        if (key < cur->key)
            cur = cur->left;
    }
    return NULL;
}

/* Return NULL if cannot find target t_node */
t_node * __get(t_node * this, int key){
    if (this){
        if (this->key == key)
            return this;
        if (key < this->key)
            return __get(this->left, key);
        if (key > this->key)
            return __get(this->right, key);
    }
    return NULL;
}


void __free_map(t_node * this){
    if (this){
        __free_map(this->left);
        __free_map(this->right);
        free(this);
    }
}

void free_map(Map * this){
    __free_map(this->root);
    this->root = NULL;
}

int __count_one(int number){
    char str[16];
    for (int i = 0; i < 16; str[i++] = '\0');
    sprintf(str, "%d", number);
    int res = 0;
    for (int i = 0, len = strlen(str); i < len; ++i)
        if (str[i] == '1')
            ++res;
    return res;
}

int __val(int input, Map * ref){
    if (!input)
        return 0;
    int ones = __count_one(input);
    int res = __val(input - 1, ref) + ones;
    t_node * find = __get(ref->root, input);
    if (find)
        find->value = res;
    return res;
}

int value_of_one(Map * this, int from, int to){
    return * get_value(this, to) - * get_value(this, from) + 1;
}

void compute_ones_in_map(Map * this){
    __val(* get_max_key(this), this);
}

void __print(t_node * this){
    if (this){
        __print(this->left);
        printf("%d --> %d\n", this->key, this->value);
        __print(this->right);
    }
}

void print(Map * this){
    __print(this->root);
}

int main(void){
    int n, n1, n2;
    scanf("%d", &n);
    Map * search_list = init();
    int * rec_list = (int *) malloc(sizeof(int) * (n << 1));
    int i = 0;
    while (n-- > 0){
        scanf("%d %d", &n1, &n2);
        rec_list[i++] = n1;
        rec_list[i++] = n2;
        insert(search_list, n1, -1);
        insert(search_list, n2, -1);
    }
    compute_ones_in_map(search_list);
    // print(search_list);
    int j = 0;
    do {
        printf("%d\n", value_of_one(search_list, rec_list[j], rec_list[j + 1]));
        j += 2;
    } while (j < i);
    free(rec_list);
    free_map(search_list);
}