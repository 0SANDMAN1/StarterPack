/*int add(int x, int y)
{
    return (x+y);
}
int main(void)
{
    int a;
    a = add(5,6);
    printf("%d", a);
    return 0;

}*/
/*int x = 10;
int add(void)
{
    printf("%d\n", x++);
}
int main(void)
{
    add();
    add();
    add();
}*/
int add()
{
    static int x = 10;
    x++;
    printf("%d\n", x);
}
int main(void)
{
    add();
    add();
}
