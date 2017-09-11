/*
 * util.h
 *
 * Created: 12/8/17 2:45:40 pm
 *  Author: bldh
 *  Place for handy functions needed throughout but not necessarily related to a specific function 
 */ 

//Set bit macro
#define set_bit(reg, bit) (reg |= 1 << bit)
//Clear bit macro
#define clear_bit(reg, bit) (reg &= ~(1<<bit))
//Read bit macro
#define read_bit(port, pin) ((*port >> pin) & 1)