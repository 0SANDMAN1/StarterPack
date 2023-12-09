volatile u32 

int main(void)
{
    TCCR0 &=~ (1 << WGM00 | 1 << WGM01); //Normal Mode
    TCCR0 |= (1 << CS00) | (1 << CS01); //N=64
    TIMSK |= (1 << TOIE0) | (1 << OCIE0);

    TCNT0 = 111;    

    while (1)
    {

    }
}

ISR(TIMER0_OVF_vect)
{
    TOV_Count ++;
    if (TOV_Count == 977)
    {
        TCNT0 = 111;
        DIO_ToggleChannel(DIO_Channel)
    }
}

ISR(TOV)