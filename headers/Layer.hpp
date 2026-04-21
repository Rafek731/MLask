#pragma once
#include <Eigen/Core>
#include <Eigen/Dense>

namespace mlask {

using type = float;

class Layer {
  protected:
    using vectorIn_ = Eigen::Matrix<type, Eigen::Dynamic, 1>;
    using vectorOut_ = Eigen::Matrix<type, Eigen::Dynamic, 1>;

  public:
    virtual ~Layer() = default;
    virtual vectorOut_ forward(vectorIn_) const = 0;
    virtual vectorOut_ backward(vectorIn_) = 0;
    virtual void fit() = 0;
};
} // namespace mlask
