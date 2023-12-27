#include "DIO_Interface.h"

const DIO_PinStatus PinsStatusArray[TOTAL_PINS] = {
	OUTPUT,		/* Port A pin 0 ADC0 */
	OUTPUT,		/* Port A pin 1 ADC1 */
	INFREE,		/* Port A pin 2      */
	INFREE,		/* Port A pin 3      */
	OUTPUT,		/* Port A pin 4      */
	OUTPUT,		/* Port A pin 5      */
	OUTPUT,		/* Port A pin 6      */
	OUTPUT,		/* Port A pin 7 ADC7 */
	OUTPUT,		/* Port B pin 0      */
	OUTPUT,		/* Port B pin 1      */
	OUTPUT,		/* Port B pin 2 INT2 */
	OUTPUT,		/* Port B pin 3 OC0  */
	INPULL,		/* Port B pin 4 ss   */
	INPULL,		/* Port B pin 5 mosi */
	INPULL,		/* Port B pin 6 miso */
	INPULL,		/* Port B pin 7 clk  */
	OUTPUT,		/* Port C pin 0      */
	OUTPUT,		/* Port C pin 1      */
	OUTPUT,		/* Port C pin 2      */
	OUTPUT,		/* Port C pin 3      */
	OUTPUT,		/* Port C pin 4      */
	OUTPUT,		/* Port C pin 5      */
	OUTPUT,		/* Port C pin 6      */
	OUTPUT,		/* Port C pin 7      */
	OUTPUT,		/* Port D pin 0      */
	OUTPUT,		/* Port D pin 1      */
	OUTPUT,		/* Port D pin 2 INT0 */
	OUTPUT,		/* Port D pin 3 INT1 */
	OUTPUT,		/* Port D pin 4 OC1B */
	OUTPUT,		/* Port D pin 5 OC1A */
	OUTPUT,		/* Port D pin 6 ICP  */
	OUTPUT		/* Port D pin 7      */
};
