#ifndef Fibonacci_hpp
#define Fibonacci_hpp

class Fibonacci final {
    unsigned int _numberOfTerms = 0;
    unsigned int _computedResult = 0;

    unsigned int compute(const unsigned int term) const noexcept {
        if (term < 2) {
            return term;
        }

        const auto result = compute(term - 1) + compute(term - 2);

        return result;
    }

public:
    Fibonacci() = default;

    unsigned int operator()(const unsigned int numberOfTerms) noexcept {
        if (_numberOfTerms != numberOfTerms || _computedResult == 0) {
            _numberOfTerms = numberOfTerms;
            _computedResult = compute(_numberOfTerms);
        }

        return _computedResult;
    }
};

#endif
