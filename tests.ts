// tests go here; this will not be compiled when this package is used as a library

{

	/*
	 * Get the DHT11 module's temperature and show the number,the format of the temperarure is Celsius.The DHT11 module is connected to D12.
	*/
	basic.showNumber(minode.DHTGetTemperature(D12,MINODE_DHT_CELSIUS));
	basic.pause(100);

	/*
	 * Get the DHT11 module's humidity and show the number.The DHT11 module is connected to D12.
	*/
	basic.showNumber(minode.DHTGetHumidity(D12));
	basic.pause(100);

	/*
	 * If the PIR is triggered show a number on the LED matrix.The PIR module is connected to D13.
	*/
	if(minode.PIRIsTriggered(D13)){
		basic.showNumber(1);
	}
	basic.pause(100);

	/*
	 * Get the Rotary's percentage and show the number.The Rotary module is connected to A0.
	*/
	basic.showNumber(minode.RotaryGetPercentage(A0));
	basic.pause(100);

	/*
	 * Get the light sensor's lightness level and show the number. The Light Sensor module is connected to A1.
	*/
	basic.showNumber(minode.LightSensorGetLevel(A1));
	basic.pause(100);

	/*
	 * Get the MIC sensor's noise level and show the number.The MIC module is connected to A2.
	*/
	basic.showNumber(minode.MICGetLevel(A2));
	basic.pause(100);

	/*
	 * Set the color of RGB module to Green.The RGB module is connected to the D13.
	*/
	minode.RGBChooseColor(D13,MiNode_RGB_COLOR_GREEN);
	basic.pause(100);

	/*
	 * Control the Fan's speed from the fastest to the lowest.The FAN module is connected to D14.
	*/
	minode.FanControl_1(D14,100);
	basic.pause(1000)
	minode.FanControl_1(D14,80);
	basic.pause(1000)
	minode.FanControl_1(D14,60);
	basic.pause(1000)
	minode.FanControl_1(D14,40);
	basic.pause(1000)
	minode.FanControl_1(D14,20);
	basic.pause(1000)
	minode.FanControl_1(D14,0);
	basic.pause(1000)

	/*
	 * Control the Relay module open and close it after a while.The Relay module is connected to D15.
	*/
	minode.RelayControl(D15,1);
	basic.pause(500)
	minode.RelayControl(D15,0);
	basic.pause(100)

}