#include"declarations.h"
#include"Mat.h"
#include"Vector.h"

using namespace mlask;

class ActivationFuction {
    virtual Vector operator()(Vector v);
    virtual void operator()(Vector& v);
};

class Relu {

};

class LeakyRelu {

};

class Softmax {

};

class Sigmoid {

};
