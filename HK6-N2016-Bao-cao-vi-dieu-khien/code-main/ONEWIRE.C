#ifndef ONE_WIRE_C
#define ONE_WIRE_C

/*
 * One wire (1-wire) driver for CCS C compiler. Suitable for use with devices
 * such as the DS18B20 1-wire digital temperature sensor.
 */

/*
 * onewire_reset()
 * Description: Initiates the one wire bus.
 */
// OK if just using a single permanently connected device
void onewire_reset() {
    output_low(ONE_WIRE_PIN);       // pull the bus low for reset
    delay_us(500);
    output_float(ONE_WIRE_PIN);     // float the bus high
    delay_us(500);                  // wait-out remaining initialisation window
    output_float(ONE_WIRE_PIN);
}


/*
 * onewire_write(int8 data)
 * Arguments: a byte of data.
 * Description: writes a byte of data to the device.
 */
void onewire_write(int8 data) {
    int8 count;

    for(count = 0; count < 8; ++count) {
        output_low(ONE_WIRE_PIN);
        delay_us(2);                // pull 1-wire low to initiate write time-slot.
        output_bit(ONE_WIRE_PIN, shift_right(&data, 1, 0)); // set output bit on 1-wire
        delay_us(60);               // wait until end of write slot.
        output_float(ONE_WIRE_PIN); // set 1-wire high again,
        delay_us(2);                // for more than 1us minimum.
    }
}

/*
 * onewire_read()
 * Description: reads and returns a byte of data from the device.
 */
int onewire_read() {
    int count, data;

    for(count = 0; count < 8; ++count) {
        output_low(ONE_WIRE_PIN);
        delay_us(2);                // pull 1-wire low to initiate read time-slot.
        output_float(ONE_WIRE_PIN); // now let 1-wire float high,
        delay_us(8);                // let device state stabilise,
        shift_right(&data, 1, input(ONE_WIRE_PIN)); // and load result.
        delay_us(120);              // wait until end of read slot.
    }
    return data;
} 

#endif /*ONE_WIRE_C*/
