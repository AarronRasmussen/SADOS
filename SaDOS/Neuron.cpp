//
//  Neuron.cpp
//  SaDOS
//
//  Created by Aarron Rasmussen on 1/9/20.
//  Copyright © 2020 Aarron Rasmussen. All rights reserved.
//

#include "Neuron.hpp"

Neuron::Neuron(const int& inputTotal, const int& weightTotal) {
    inputSize = inputTotal;
    weightSize = weightTotal;

    std::cout << "Neuron constructor called" << std::endl;
    getRandomWeight();
}

Neuron::~Neuron() {}

//static double transformFunction(double x);
//static double transformFunctionDerivative(double x);

void Neuron::getRandomWeight(void) {
    std::random_device rd;
    std::mt19937 n(rd());

    std::uniform_real_distribution<double> dist(0,1);

    for(int i = 0; i < weightSize; i++) {
        weights.push_back(dist(n));
    }

    std::cout << "Printing out random weights..." << std::endl;
    std::copy(weights.begin(), weights.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;
}

void Neuron::setOutPutVal(double val) {
    outPutVal = val;
}

double Neuron::getOutPutVal(void) const {
    return outPutVal;
}

void Neuron::setBias(double bias) {
    
}

double Neuron::getBias(void) const {
    return bias;
}

void Neuron::feedForward(const std::vector<Neuron*>& prevLayer) {

}

std::ostream& operator<< (std::ostream& os, const Neuron& n) {
    std::copy(n.inputs.begin(), n.inputs.end(), std::ostream_iterator<double>(os, ""));
    os << std::endl;
    std::copy(n.weights.begin(), n.weights.end(), std::ostream_iterator<double>(os, ""));
    os << std::endl;
    return os;
}
