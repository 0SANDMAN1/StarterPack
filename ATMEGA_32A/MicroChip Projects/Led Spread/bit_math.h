#define Set(Reg, Pin) Reg |= (1 << Pin)
#define Clr(Reg, Pin) Reg &=~ (1 << Pin)
#define Toggle(Reg, Pin) Reg ^= (1 << Pin)
#define Get(Reg, Pin) Reg &= (1 << Pin)