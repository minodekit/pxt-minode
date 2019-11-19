#include "pxt.h"
#include "MiNode.h"
#include <math.h>

MiNode node;


#define clip(n, lower, upper) if (n < lower) n= lower; else if (n > upper) n= upper

using namespace pxt;
namespace minode {

	//%
	int getPin(ConnName connName)
  	{
    	int temp=0;

    	PinName pinName1 = MiNodeConn::calcP0Name(connName);

    	switch(pinName1)
    	{
      	case MICROBIT_PIN_P0:
        	temp = MICROBIT_ID_IO_P0;
        	break;
      	case MICROBIT_PIN_P1:
        	temp = MICROBIT_ID_IO_P1;
        	break;
      	case MICROBIT_PIN_P2:
        	temp = MICROBIT_ID_IO_P2;
        	break;
      	case MICROBIT_PIN_P12:
        	temp = MICROBIT_ID_IO_P12;
        	break;
      	case MICROBIT_PIN_P13:
        	temp = MICROBIT_ID_IO_P13;
        	break;
      	case MICROBIT_PIN_P14:
        	temp = MICROBIT_ID_IO_P14;
        	break;
      	case MICROBIT_PIN_P15:
        	temp = MICROBIT_ID_IO_P15;
        	break;
      	default:
        	temp = 0;
        	break;
    	}

    	return temp;
  	}

  	//%
  	int getanalogPin(AnalogConnName connName)
  	{
    	int temp=0;

    	PinName pinName1 = MiNodeConn::calcP0Name(connName);

    	switch(pinName1)
    	{
      	case MICROBIT_PIN_P0:
        	temp = MICROBIT_ID_IO_P0;
        	break;
      	case MICROBIT_PIN_P1:
        	temp = MICROBIT_ID_IO_P1;
        	break;
      	case MICROBIT_PIN_P2:
        	temp = MICROBIT_ID_IO_P2;
        	break;
      	default:
        	temp = 0;
        	break;
    	}

    	return temp;
  	}

  	//%
  	int getPinProperty(ConnName connName)
  	{
    	if (connName == A0 || connName == A1 || connName == A2)
    	{
      		return 1;
    	}
    	else
    	{
      		return 0;
    	}
  	}


    //%
    void rgbChooseColor(ConnName connName , MiNodeColor color) {
      MiNodeRGB* pRGB;

      pRGB = node.rgb.attach(connName);
      pRGB->chooseColor(color);
    }

    //% 
	void RGBSetColor(ConnName connName , int red, int green, int blue){
	    MiNodeRGB* pRGB;

	    pRGB = node.rgb.attach(connName);
	    pRGB->setRGB(red,green,blue);
	}

    //% 
	void HSLSetColor(ConnName connName , int hue, int saturation, int lightness){
	    MiNodeRGB* pRGB;
        int h;
        int s;
        int l;
        

	    pRGB = node.rgb.attach(connName);
        h = round(hue);
        s = round(saturation);
        l = round(lightness);
        
        h = h % 360;
        s = clip(0, 99, s);
        l = clip(0, 99, l);
        int c = div((((100 - abs(2 * l - 100)) * s) << 8), 10000); //chroma, [0,255]
        int h1 = div(h, 60);//[0,6]
        int h2 = div((h - h1 * 60) * 256, 60);//[0,255]
        int temp = abs((((h1 % 2) << 8) + h2) - 256);
        int x = (c * (256 - (temp))) >> 8;//[0,255], second largest component of this color
        int r$;
        int g$;
        int b$;
        if (h1 == 0) {
            r$ = c; g$ = x; b$ = 0;
        } else if (h1 == 1) {
            r$ = x; g$ = c; b$ = 0;
        } else if (h1 == 2) {
            r$ = 0; g$ = c; b$ = x;
        } else if (h1 == 3) {
            r$ = 0; g$ = x; b$ = c;
        } else if (h1 == 4) {
            r$ = x; g$ = 0; b$ = c;
        } else if (h1 == 5) {
            r$ = c; g$ = 0; b$ = x;
        }
        int m = div((div((l * 2 << 8), 100) - c), 2);
        int r = r$ + m;
        int g = g$ + m;
        int b = b$ + m;
	    pRGB->setRGB(r,g,b);
	}


	//%
  	int DHTGetTemperature(ConnName connName , DHTTemStyle style){
   	  MiNodeDHT* pDHT11;
   	  int dht_tempreature=0;

      pDHT11 = node.dht11.attach(connName);
      switch(style) {
        case MINODE_DHT_CELSIUS:
            dht_tempreature = pDHT11->getTemperature();
        break;
        case MINODE_FAN_FAHRENHEIT:
          	dht_tempreature = pDHT11->getFahrenheitTemperature();
        break;
        default:
        	dht_tempreature = pDHT11->getTemperature();
        break;
      }

  	  return dht_tempreature;
    }

    //%
 	int DHTGetHumidity(ConnName connName){
    	MiNodeDHT* pDHT11;
    	int dht_humidity=0;

    	pDHT11 = node.dht11.attach(connName);
    	dht_humidity = pDHT11->getHumidity();

    	return dht_humidity;
  	}

  	//%
  	void onDHTEvent(ConnName connName, Action body){
    	int id;
    	MiNodeDHT* pDHT11;

    	pDHT11 = node.dht11.attach(connName);
    	id = pDHT11->getId();

    	registerWithDal(id, MINODE_DHT_EVT_CHANGE, body);
  	}

  	//%
 	void onSwitchEvent(ConnName connName, SwitchEvent event, Action body)
  	{
    	int id;
    	MiNodeSwitch* pSwitch;

    	pSwitch = node.switches.attach(connName);
    	id = pSwitch->getId();

    	registerWithDal(id, event, body);
  	}

  	//%
  	bool switchIsOpened(ConnName connName)
  	{

    	MiNodeSwitch* pSwitch;
    	int isOpened;

    	pSwitch = node.switches.attach(connName);
    	isOpened = pSwitch->isOpened();

    	return isOpened ? true : false;
  	}

  	//%
  	void onRotaryEvent(AnalogConnName connName, Action body)
  	{
    	int id;
    	MiNodeRotary* pRotary;

    	pRotary = node.rotary.attach(connName);
    	id = pRotary->getId();

    	registerWithDal(id, MINODE_ROTARY_EVT_CHANGE, body);
  	}

  	//%
 	int RotaryGetPercentage(AnalogConnName connName)
  	{
    	MiNodeRotary* pRotary;
    	int rotaryPercentage=0;

    	pRotary = node.rotary.attach(connName);
    	rotaryPercentage = pRotary->getPercentage();

    	return rotaryPercentage;
  	}

  	//%
  	void onPIREvent(ConnName connName, Action body)
	{
	    int id;
	    MiNodePIR* pPir;

	    pPir = node.pir.attach(connName);
	    id = pPir->getId();

	    registerWithDal(id, MINODE_PIR_EVT_TRIG, body);
	}

	//%
	bool PIRIsTriggered(ConnName connName)
	{

	    MiNodePIR* pPir;
	    int triggered;

	    pPir = node.pir.attach(connName);
	    triggered = pPir->isTriged();

	    return triggered ? true : false;
	}

	//%
  	void onMICEvent(AnalogConnName connName, Action body)
  	{
    	int id;
    	MiNodeMIC* pMic;

    	pMic = node.mic.attach(connName);
    	id = pMic->getId();

    	registerWithDal(id, MINODE_MIC_EVT_NOISE, body);
  	}

  	//%
  	void onLightSensorEvent(AnalogConnName connName, Action body)
  	{
    	int id;
    	MiNodeLight* pLight;

    	pLight = node.light.attach(connName);
    	id = pLight->getId();

    	registerWithDal(id, MINODE_LIGHT_EVT_LEVEL_CHANGE, body);
  	}

  	//%
  	int LightSensorGetLevel(AnalogConnName connName)
  	{
    	MiNodeLight* pLight;
    	int lightLevel=0;

    	pLight = node.light.attach(connName);
    	lightLevel = pLight->getLightLevel();

    	return lightLevel;
  	}
}
