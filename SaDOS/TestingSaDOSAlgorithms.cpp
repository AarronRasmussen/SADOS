// TestingSaDOSAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <random>
#include <iterator>

struct Neuron {
    double i0;
    double i1;
    double w0;
    double w1;

    Neuron() {
        this->i0 = 0.0;
        this->i1 = 0.0;
        this->w0 = 0.0;
        this->w1 = 0.0;
    }

    Neuron(double i0, double i1, double w0, double w1) {
        this->i0 = i0;
        this->i1 = i1;
        this->w0 = w0;
        this->w1 = w1;
    }
};

struct Bias {
    double bias;

    Bias(double bias) {
        this->bias = bias;
    }
};

double totalNetInput(const Neuron& n, const Bias& b) {
    return (n.w0 * n.i0) + (n.w1 * n.i1) + b.bias * 1.0;
}

double logisticFunction(double netInput) {
    return 1.0 / (1.0 + (exp(-netInput)));
}

double totalError(const double& target, const double& output) {
    return .5 * pow((target - output), 2.0);
}

double calculateDelta(double target, double out, double inVal) {
    return -(target - out) * (out * (1.0 - out) * inVal);
}

double updateWeight(double weight, double delta, double learningRate) {
    return weight - (learningRate * delta);
}

int main() {
    //XOR gate 2 input, 2 hidden, 1 out
    double inputs[2] = {.05, .10};
    double weights[8] = {.15, .20, .25, .30, .40, .45, .50, .55};
    double learningRate = 0.5;
    
    auto h1 = Neuron(inputs[0], inputs[1], weights[0], weights[1]);
    auto h2 = Neuron(inputs[0], inputs[1], weights[2], weights[3]);

    auto b1 = Bias(.35);
    auto b2 = Bias(.60);

    double netH0 = totalNetInput(h1, b1);
    double netH1 = totalNetInput(h2, b1);

    std::cout << "Hidden Layer" << std::endl;

    std::cout << netH0 << std::endl;
    std::cout << netH1 << std::endl;

    double h0out = logisticFunction(netH0);
    double h1out = logisticFunction(netH1);

    std::cout << "Logistic Function netH1: " << h0out << std::endl;
    std::cout << "Logistic Function netH2: " << h1out << std::endl;

    auto o1 = Neuron(h0out, h1out, weights[4], weights[5]);
    auto o2 = Neuron(h0out, h1out, weights[6], weights[7]);

    double out01 = totalNetInput(o1, b2);
    double out02 = totalNetInput(o2, b2);

    std::cout << "Output neurons" << std::endl;

    std::cout << out01 << std::endl;
    std::cout << out02 << std::endl;

    double theBigSqusih1 = logisticFunction(out01);
    double theBigSquish2 = logisticFunction(out02);

    std::cout << "Logistic Function netO1: " << theBigSqusih1 << std::endl;
    std::cout << "Logistic Function netO2: " << theBigSquish2 << std::endl;

    std::cout << "Calculating total error of output" << std::endl;
    double Error0 = totalError(0.01, theBigSqusih1);
    double Error1 = totalError(0.99, theBigSquish2);

    std::cout << Error0 << std::endl;
    std::cout << Error1 << std::endl;

    double ErrorTotal = Error0 + Error1;

    std::cout <<"ErrorTotal: " << ErrorTotal << std::endl;

    double delta = calculateDelta(0.01, theBigSqusih1, h0out);
    std::cout << "Checking delta function: " << delta << std::endl;

    double updateW5 = updateWeight(weights[4], delta, learningRate);
    std::cout << "updated weight: " << updateW5 << std::endl;


    std::random_device rd;
    std::mt19937 n(rd());

    std::uniform_real_distribution<double> dist(0,1);

    std::vector<double> vec;
    for(int i = 0; i < 10; i++) {
        vec.push_back(dist(n));
    }

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<double>(std::cout, "\n"));
}
