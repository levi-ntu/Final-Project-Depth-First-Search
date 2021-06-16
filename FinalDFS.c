#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define initial 0
#define visited 1

int n; // Number of nodes
int graph[MAX][MAX]; //Create the 2D array
int max_edge; //Declare the maximum edges
int check[MAX]; //To check whether the node is visited or not

int stack[MAX]; //Create a stack
int top = -1; //Record which node is the top node

void creat_graph();//Create a graph
void traversal();
void dfs(int v);
void update_stack(int v);
int pop();
int empty_stack();//Check the stack is empty or not

int main(void){
    creat_graph();
    traversal();
}

void creat_graph(void){
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    max_edge = n*(n-1);

    int begin, end;
    for (int j = 0; j < max_edge; j++)
    {
        printf("Enter the egde %d(-1, -1 to quit): ", j);
        scanf("%d %d", &begin, &end);
        if (begin == -1 && end == -1){
            break;
        }
        if (begin>=n || end>=n || begin<0 || end<0){
            printf("Invalid input\n");
            j--;//Input again
        }
        else{
            graph[begin][end] = 1;//Create a route
        }
    }
}
void traversal(void){
    int v;
    for (v = 0; v < n; v++){
        check[v] = initial;
    }
    printf("Enter the starting node: ");
    do
    {
        scanf("%d", &v);
    }
    while (v > n || v < 0);

    dfs(v); //Start the DFS
    printf("\n");
}
void dfs(int v){
    int i;
    update_stack(v);

    while(!empty_stack()){
        v = pop();
        if (check[v] == initial){
            printf("%d", v);
            check[v] = visited;
        }
        for (i = n-1; i >= 0; i--){
            if (graph[v][i] == 1 && check[i] == initial){
                update_stack(i);
        }
    }
    }
}
void update_stack(int v){
    if (top == MAX-1){
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = v;
}
int pop(){
    int v;
    if (top == -1){
        printf("Stack underflow\n");
        exit(1);
    }
    else{
        v = stack[top];
        top--;
        return v;
    }
}//Step back
int empty_stack(void){
    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
}//Check whether the stack is empty or not
