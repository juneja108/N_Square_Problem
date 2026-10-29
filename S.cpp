module;

#include <string>
#include <cmath>
#include <stdexcept>

export module S; 

export namespace S {
    int factorial(int n) { 
        if (n < 0) { 
            throw std::invalid_argument("n must be in the set of whole numbers!");
        }

        int result = 1; 

        for (int k = 0; k < n; k++) { 
            result *= (k + 1);
        }

        return result;
    }

    /**
     * @brief Determines if a given n has more solutions 
     * Does n have more permutations than subsets?
     * 
     * @author Shaurya Juneja 
     */
    bool S(int n) {
        if (factorial(n) > std::pow(2, n)) return true; 
        else return false;
    }
}