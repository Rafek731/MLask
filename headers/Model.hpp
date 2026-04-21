#pragma once
#include "Layer.hpp"
#include <Eigen/Core>
#include <memory>
#include <vector>

namespace mlask {
class Model {
  private:
    std::vector<std::unique_ptr<Layer>> layers_;

  public:
    void addLayer(std::unique_ptr<Layer> layer);
    Eigen::Matrix<type, Eigen::Dynamic, 1> forward(Eigen::Matrix<type, Eigen::Dynamic, 1> input) const;
};

} // namespace mlask
