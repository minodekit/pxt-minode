#ifndef MINODE_MODULE_POOL_H
#define MINODE_MODULE_POOL_H

#include "mbed.h"
#include <vector>

#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "MiNodeComponent.h"
#include "MiNodeConn.h"


template<class T>
class MiNodeModulePool {

public:
  MiNodeModulePool() {

  }

  ~MiNodeModulePool() {

    typename std::vector<T*>::iterator it;
    for(it = modules.begin(); it != modules.end(); it++) {
      T* pModule = *it;
      delete pModule;
    }

  }

  T* attach(ConnName conn) {

    typename std::vector<T*>::iterator it;
    T* findModule = NULL;
    for(it = modules.begin(); it != modules.end(); it++) {
      T* pModule = *it;
      if(conn == pModule->getConnector()) {
        findModule = pModule;
        break;
      }
    }

    if(findModule == NULL) {
      findModule = new T();
      findModule->attach(conn);
      modules.push_back(findModule);
    }

    return findModule;
  }

  T* attach(AnalogConnName conn) {

    typename std::vector<T*>::iterator it;
    T* findModule = NULL;
    for(it = modules.begin(); it != modules.end(); it++) {
      T* pModule = *it;
      if(conn == pModule->AgetConnector()) {
        findModule = pModule;
        break;
      }
    }

    if(findModule == NULL) {
      findModule = new T();
      findModule->attach(conn);
      modules.push_back(findModule);
    }

    return findModule;
  }

private:
  std::vector<T*> modules;

};


#endif
