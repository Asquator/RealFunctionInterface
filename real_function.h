#ifndef REALFUNCTION_H
#define REALFUNCTION_H

#include <memory>
#include <ostream>

class RealFunction{

    friend std::ostream &operator<<(std::ostream &, const RealFunction &);

    public:
        using real_type = long double;

        /*asking the synthesized copy control operations*/
        RealFunction() = default;

        RealFunction(const RealFunction &) = default;
        RealFunction &operator=(const RealFunction &) = default;

        RealFunction(RealFunction &&) = default;
        RealFunction &operator=(RealFunction &&) = default;

        /**
         * @brief Dynamic virtual clone constructor
         * 
         * @return RealFunction* copy of the object
         */
        virtual RealFunction *clone() const = 0;

        std::shared_ptr<const RealFunction> getDerivative();

        /*polymorphic destructor*/
        virtual ~RealFunction();

        virtual real_type operator()(real_type) const = 0;

    private:
        bool validDerivative;
        std::shared_ptr<const RealFunction> derivative = nullptr;

        virtual std::unique_ptr<RealFunction> calculateDerivative() = 0;

    protected:
        virtual std::ostream &print(std::ostream &) const = 0;
};


#endif