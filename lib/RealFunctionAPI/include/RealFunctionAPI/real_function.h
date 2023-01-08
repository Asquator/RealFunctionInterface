#ifndef REAL_FUNCTION_H
#define REAL_FUNCTION_H

#include <memory>
#include <ostream>

namespace RealFunctionAPI{
class RealFunction{

    friend std::ostream &operator<<(std::ostream &, const RealFunction &);

    private:
        mutable std::shared_ptr<const RealFunction> derivative = nullptr;
        virtual std::unique_ptr<RealFunction> calculateDerivative() const = 0;
        virtual void print(std::ostream &) const = 0;


    public:
        using real_type = long double;

        /*asking the synthesized copy control operations*/
        RealFunction() = default;

        RealFunction(const RealFunction &);
        RealFunction &operator=(const RealFunction &);

        RealFunction(RealFunction &&) = default;
        RealFunction &operator=(RealFunction &&) = default;

         /*polymorphic destructor*/
        virtual ~RealFunction();

        /**
         * @brief Dynamic virtual clone constructor
         * @return RealFunction* copy of the object
         */

        const std::shared_ptr<const RealFunction> getDerivative() const;

        virtual RealFunction *clone() const = 0;

        virtual bool isDefined(real_type) const = 0;

        virtual real_type operator()(real_type) const = 0;

};


}

#endif