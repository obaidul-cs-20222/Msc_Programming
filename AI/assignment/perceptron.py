# %%
import numpy as np 

# sigmoid activation function 
def activationFunction(model, type="sigmoid"): 
    return { 
        "sigmoid": 1 / (1 + np.exp(-model)) 
    }[type] 

# designing perceptron model 
def perceptronModel(weights, inputs, bias): 
    model = np.add(np.dot(inputs, weights), bias) 
    logic = activationFunction(model, type="sigmoid") 
    return np.round(logic) 

# computation model 
def compute(data, logicGate, weights, bias): 
    weights = np.array(weights) 
    output = np.array([perceptronModel(weights, datum, bias) for datum in data]) 
    return output 

# Print Output 
def printOutput(dataset, name, data): 
    print("Logic Function: {}".format(name.upper())) 
    print("X1\tX2\tX3\tY") 
    toPrint = ["{1}\t{2}\t{3}\t{0}".format(output, *datas) for datas, output in zip(dataset, data)] 
    for i in toPrint: 
        print(i) 

# main function 
def main(): 
    # 3 bit binary data 
    dataset = np.array([ 
        [0, 0, 0], 
        [0, 0, 1], 
        [0, 1, 0], 
        [0, 1, 1], 
        [1, 0, 0], 
        [1, 0, 1], 
        [1, 1, 0], 
        [1, 1, 1] 
    ]) 

    # Parameters of every Logic Gates 
    # weight parameters: w1, w2, w3 
    # bias parameter: b 
    logicGate = { 
        "and": compute(dataset, "and", [1, 1, 1], 1), 
        "or": compute(dataset, "or", [1, 1, 1], 1), 
        "nand": compute(dataset, "nand", [-1, -1, -1], 1), 
        "nor": compute(dataset, "nor", [-1, -1, -1], 1) 
    } 
    for gate in logicGate: 
        printOutput(dataset, gate, logicGate[gate]) 

if __name__ == '__main__': 
    main() 


# %%
import numpy as np

# Sigmoid activation function
def activationFunction(model, type="sigmoid"):
    return {
        "sigmoid": 1 / (1 + np.exp(-model))
    }[type]

# Designing perceptron model
def perceptronModel(weights, inputs, bias):
    model = np.add(np.dot(inputs, weights), bias)
    logic = activationFunction(model, type="sigmoid")
    return np.round(logic)

# Computation model
def compute(data, logicGate, weights, bias):
    weights = np.array(weights)
    output = np.array([perceptronModel(weights, datum, bias) for datum in data])
    return output

# Print Output
def printOutput(dataset, name, data):
    print("Logic Function: {}".format(name.upper()))
    print("X1\tX2\tY")
    toPrint = ["{1}\t{2}\t{0}".format(output, *datas) for datas, output in zip(dataset, data)]
    for i in toPrint:
        print(i)

# Main function
def main():
    # 2-bit binary data
    dataset = np.array([
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1]
    ])

    # Parameters of every Logic Gate
    # Weight parameters: w1, w2
    # Bias parameter: b
    logicGate = {
        "and": compute(dataset, "and", [1, 1], 1),
        "or": compute(dataset, "or", [1, 1], 1),
        "nand": compute(dataset, "nand", [-1, -1], 1),
        "nor": compute(dataset, "nor", [-1, -1], 1)
    }
    for gate in logicGate:
        printOutput(dataset, gate, logicGate[gate])

if __name__ == '__main__':
    main()



