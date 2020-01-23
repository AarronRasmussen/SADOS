//
//  Net.hpp
//  SaDOS
//
//  Created by Aarron Rasmussen on 1/9/20.
//  Copyright © 2020 Aarron Rasmussen. All rights reserved.
//

#ifndef Net_hpp
#define Net_hpp

#include <stdio.h>
#include <vector>
#include "Neuron.hpp"
#include <ostream>

class Net {
private:
    double learningRate;
    std::vector<Neuron*> hiddenLayer;
    std::vector<Neuron*> outputLayer;

public:
    Net(const int& inputNum, const int& hiddenNum, const int& outputNum, const int& learningRate);
    void feedForward(const std::vector<double> &input);
    void backProp(const std::vector<double> &targetVals);
    double totalNetInput(const Neuron& n) const;
    void getResults(std::vector<double> &results) const;
};

#endif /* Net_hpp */
