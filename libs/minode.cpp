#include "pxt.h"
#include "MiNode.h"

MiNode node;

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
