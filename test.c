#include <stdio.h>

/*
function(struct emp* );

struct empty
{
    char name[20];
    int age;
};

int main()
{
    struct emp e1 = ("employee", 30);
    function(&e1);
    return 0;
}

function (struct emp* e_ptr)
{
    printf("%s %d", e_ptr->name, e_ptr->age);
}
*/


int main()
{
    char* a = "A";
    printf("%d %d", sizeof(a), sizeof("A"));
    return 0;
}
