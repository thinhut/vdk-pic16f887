/*   Nhan vao gia tri nhiet do
     --> Dieu khien tat mo motor */
void OF_RELAY(float temperature, float temp_setup);

void OF_RELAY(float temperature, float temp_setup){
	if (temperature >= temp_setup){
		output_high(RELAY_SIG);
		delay_ms(1000);
	}
	else{
		output_low(RELAY_SIG);
		delay_ms(1000);
	}
}

