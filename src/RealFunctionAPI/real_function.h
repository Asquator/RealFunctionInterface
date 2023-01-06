#ifndef REAL_FUNCTION_H
#define REAL_FUNCTION_H

#include <memory>
#include <ostream>

class RealFunction{

    friend std::ostream &operator<<(std::ostream &, const RealFunction &);

    private:
    
        std::shared_ptr<const RealFunction> derivative = nullptr;
        virtual std::unique_ptr<RealFunction> calculateDerivative() = 0;
        virtual std::ostream &print(std::ostream &) const = 0;


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
         * @return RealFunction* copy of the object
         */
        virtual RealFunction *clone() const = 0;

        /*polymorphic destructor*/
        virtual ~RealFunction();

        std::shared_ptr<const RealFunction> getDerivative();

        virtual bool isDefined(real_type) const = 0;

        
        virtual real_type operator()(real_type) const = 0;

};


#endif