#include "../headers/Model.hpp"
#include <Eigen/Core>

namespace mlask {
void Model::addLayer(std::unique_ptr<Layer> layer) {
    layers_.push_back(std::move(layer));
}

Eigen::Matrix<type, Eigen::Dynamic, 1>
Model::forward(Eigen::Matrix<type, Eigen::Dynamic, 1> input) const {
    for (const std::unique_ptr<Layer> &layer : layers_) {
        input = layer->forward(input);
    }
    return input;
}
} // namespace mlask
