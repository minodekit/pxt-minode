#include "pxt.h"
#include "MiNode.h"

MiNode node;

using namespace pxt;
namespace minode {
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
}
