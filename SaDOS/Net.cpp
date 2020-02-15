//
//  Net.cpp
//  SaDOS
//
//  Created by Aarron Rasmussen on 1/9/20.
//  Copyright © 2020 Aarron Rasmussen. All rights reserved.
//

#include "Net.hpp"

Net::Net(const int& inputNum, const int& hiddenNum, const int& outputNum, const int& learningRate) {
    this->learningRate = learningRate;
    outputLayer.reserve(outputNum);

    for(int i = 0; i < hiddenNum; i++) {
        hiddenLayer.push_back(new Neuron(inputNum, hiddenNum));
    }

    for(int i = 0; i < outputNum; ++i) {
        outputLayer.push_back(new Neuron(outputNum, outputNum));
    }

    std::cout << "Calling Net Constructor.." << std::endl;
}

void Net::feedForward(const std::vector<double> &input) {

}

void Net::backProp(const std::vector<double> &targetVals) {

}

void Net::getResults(std::vector<double> &results) const {

}
