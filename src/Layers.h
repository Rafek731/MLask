#include"declarations.h"

namespace mlask {
    /**
     * Abstract class for all layers to inherit from
     */
     class Layer {
        protected:
        int_t in_features, out_features;
        public:
        virtual void info();
        virtual void forward();
    };

    /**
     * 
     */
    class Linear :public Layer{

    };

    
}