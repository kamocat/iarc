#include <stdlib.h>
#include "../../drivers/avr_compiler.h"
#include "math.h"

int abs(int i){
	if(i < 0) {
		i *= -1;
		return i;
	}
	else {
		return i;
	}
}

/* Code taken from Craig McQueen*/
uint32_t mySqrt(uint32_t input){
	uint32_t op  = input;

	uint32_t res = 0;
	uint32_t one = 1uL << 30; // The second-to-top bit is set: use 1u << 14 for uint16_t type; use 1uL<<30 for uint32_t type


	// "one" starts at the highest power of four <= than the argument.
	while (one > op)
	{
		one >>= 2;
	}

	while (one != 0)
	{
		if (op >= res + one)
		{
			op = op - (res + one);
			res = res +  2 * one;
		}
		res >>= 1;
		one >>= 2;
	}

	/* Do arithmetic rounding to nearest integer */
	if (op > res)
	{
		res++;
	}

	return res;
}



/* This function is dumb.
 * Use a lookup table. -- Marshal
 */
//136 is 10 degrees, 4900 is full circle
int arctan2(int opp, int adj){

	//Catch divide by 0 just in case
	int ratio;

	if(adj == 0){
		if(opp > 0){
			return 1225;
		}
		else{
			return -1225;
		}
	}
	else if(opp == 0){
		if(adj > 0){
			return 0;
		}
		else{
			return 2450;
		}
	}

	if(abs(adj)>abs(opp)){

	ratio = (32 * adj)/opp;
		//45..
		if(abs(ratio) < 35){
			if(adj > 0){
				if(opp > 0){
					return 617;
				}
				else{
					return -617;
				}
			}
			else{
				if(opp > 0){
					return 1831;
				}
				else{
					return -1831;
				}
			}
		}


		//40..
		else if(abs(ratio) < 42){
			if(adj > 0){
				if(opp > 0){
					return 548;
				}
				else{
					return -548;
				}
			}
			else{
				if(opp > 0){
					return 1902;
				}
				else{
					return -1902;
				}
			}
		}


		//35..
		else if(abs(ratio) < 51){
			if(adj > 0){
				if(opp > 0){
					return 480;
				}
				else{
					return -480;
				}
			}
			else{
				if(opp > 0){
					return 1970;
				}
				else{
					return -1970;
				}
			}
		}


		//30..
		else if(abs(ratio) < 62){
			if(adj > 0){
				if(opp > 0){
					return 411;
				}
				else{
					return -411;
				}
			}
			else{
				if(opp > 0){
					return 2039;
				}
				else{
					return -2039;
				}
			}
		}

		//25..
		else if(abs(ratio) < 78){
			if(adj > 0){
				if(opp > 0){
					return 340;
				}
				else{
					return -340;
				}
			}
			else{
				if(opp > 0){
					return 2110;
				}
				else{
					return -2110;
				}
			}
		}


		//20..
		else if(abs(ratio) < 102){
			if(adj > 0){
				if(opp > 0){
					return 274;
				}
				else{
					return -274;
				}
			}
			else{
				if(opp > 0){
					return 2176;
				}
				else{
					return -2176;
				}
			}
		}


		//15..
		else if(abs(ratio) < 145){
			if(adj > 0){
				if(opp > 0){
					return 205;
				}
				else{
					return -205;
				}
			}
			else{
				if(opp > 0){
					return 2244;
				}
				else{
					return -2244;
				}
			}
		}


		//10 OR -10 ..
		else if(abs(ratio) < 244){
			if(adj > 0){
				if(opp > 0){
					return 137;
				}
				else{
					return -137;
				}
			}
			else{
				if(opp > 0){
					return 2313;
				}
				else{
					return -2313;
				}
			}
		}


		//5 OR -5 OR 175 OR -175
		else if(abs(ratio) < 733){
			if(adj > 0){
				if(opp > 0){
					return 69;
				}
				else{
					return -69;
				}
			}
			else{
				if(opp > 0){
					return 2381;
				}
				else{
					return -2381;
				}
			}
		}

	//0 OR 180
		else{
			if(adj > 0){
				return 0;
			}
			else{
				return 2450;
			}
		}



	}

	else{
		ratio = (32 * opp)/adj;
		//45..
		if(abs(ratio) < 35){
			if(adj > 0){
				if(opp > 0){
					return 617;
				}
				else{
					return -617;
				}
			}
			else{
				if(opp > 0){
					return 1833;
				}
				else{
					return -1833;
				}
			}
		}

		//50..
		else if(abs(ratio) < 42){
			if(adj > 0){
				if(opp > 0){
					return 685;
				}
				else{
					return -685;
				}
			}
			else{
				if(opp > 0){
					return 1765;
				}
				else{
					return -1765;
				}
			}
		}

		//55..
		else if(abs(ratio) < 51){
			if(adj > 0){
				if(opp > 0){
					return 754;
				}
				else{
					return -754;
				}
			}
			else{
				if(opp > 0){
					return 1696;
				}
				else{
					return -1696;
				}
			}
		}

		//60..
		else if(abs(ratio) < 62){
			if(adj > 0){
				if(opp > 0){
					return 822;
				}
				else{
					return -822;
				}
			}
			else{
				if(opp > 0){
					return 1628;
				}
				else{
					return -1628;
				}
			}
		}

		//65..
		else if(abs(ratio) < 78){
			if(adj > 0){
				if(opp > 0){
					return 889;
				}
				else{
					return -889;
				}
			}
			else{
				if(opp > 0){
					return 1559;
				}
				else{
					return -1559;
				}
			}
		}


		//70..
		else if(abs(ratio) < 102){
			if(adj > 0){
				if(opp > 0){
					return 959;
				}
				else{
					return -959;
				}
			}
			else{
				if(opp > 0){
					return 1493;
				}
				else{
					return -1493;
				}
			}
		}

		//75..
		else if(abs(ratio) < 145){
			if(adj > 0){
				if(opp > 0){
					return 1028;
				}
				else{
					return -1028;
				}
			}
			else{
				if(opp > 0){
					return 1424;
				}
				else{
					return -1424;
				}
			}
		}

		//80..
		else if(abs(ratio) < 244){
			if(adj > 0){
				if(opp > 0){
					return 1096;
				}
				else{
					return -1096;
				}
			}
			else{
				if(opp > 0){
					return 1356;
				}
				else{
					return -1356;
				}
			}
		}

		//85..
		else if(abs(ratio) < 733){
			if(adj > 0){
				if(opp > 0){
					return 1165;
				}
				else{
					return -1165;
				}
			}
			else{
				if(opp > 0){
					return 1287;
				}
				else{
					return -1287;
				}
			}
		}

		//90..
		else{
			if(adj > 0){
				if(opp > 0){
					return 1225;
				}
				else{
					return -1225;
				}
			}
			else{
				if(opp > 0){
					return 1225;
				}
				else{
					return -1225;
				}
			}
		}
	}
}



