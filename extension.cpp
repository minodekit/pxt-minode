#include "pxt.h"
#include "minode-core/MiNodeComponent.h"
#include "minode-core/MiNodeConn.h"


using namespace pxt;
namespace minode {
    //%
    int extfun(int x, int y) {
        return x + y;
    }

    PinName testfun2() {
      return MiNodeConn::calcP0Name(A0);
    }
}
