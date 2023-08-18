#define Add(x,y) x+y
#define SetBit(x,pos) x|(1<<pos)
#define ClearBit(x,pos) x&(~(1<<pos)
#define ToggleBit(x,pos) x^=(1<<pos)
int main()
{
    printf("%d", Add(5,6));
}
