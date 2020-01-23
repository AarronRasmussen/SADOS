//
//  Neuron.hpp
//  SaDOS
//
//  Created by Aarron Rasmussen on 1/9/20.
//  Copyright © 2020 Aarron Rasmussen. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <random>

class Neuron {
private:
    double inputSize;
    double weightSize;
    
    static double transformFunction(double x);
    static double transformFunctionDerivative(double x);
    void getRandomWeight(void);
    
    std::vector<double> inputs;
    std::vector<double> weights;
    
    double outPutVal;
    double bias;
    
public:
    Neuron(const int& inputTotal, const int& weightTotal);
    ~Neuron();
    
    void setOutPutVal(double val);
    double getOutPutVal(void) const;

    void setBias(double bias);
    double getBias(void) const;

    void feedForward(const std::vector<Neuron*>& prevLayer);

    friend std::ostream& operator<< (std::ostream& os, const Neuron& n);
};

#endif /* Neuron_hpp */
