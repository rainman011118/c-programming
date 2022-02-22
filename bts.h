#pragma once
#include<stdio.h>

struct node;//NOTE: I had to declare this here AND DEFINE it in the functions file, because it would not compile otherwise. The definition of the struct node (in main), is not visible to the compiler, so it must be declared here.  The alternative way is to define the whole struct here instead (with all it's members), and then you won't have to define it in the functions file.   

void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);


