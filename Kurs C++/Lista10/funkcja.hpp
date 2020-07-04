#ifndef FUNKCJA_H
#define FUNKCJA_H

#include "symbol.hpp    "
#include <map>

namespace kalkulator
{
    class funkcja : public symbol
    {
        public:

            enum funkcje
            {
                my_add,
                my_sub,
                my_mul,
                my_div,
                my_modulo,
                my_min,
                my_max,
                my_log,
                my_pow,
                my_abs,
                my_sgn,
                my_floor,
                my_ceil,
                my_frac,
                my_sin,
                my_cos,
                my_atan,
                my_acot,
                my_ln,
                my_exp
            };

            funkcja::funkcje dzialanie;

            funkcja::funkcje pobierzFunkcje(std::string);
            funkcja(funkcje);
            virtual ~funkcja();
            
            void execute();

        protected:

        private:
            std::pair<double, double> popTwo();
            double popOne();
            static std::map<std::string, funkcje> Zbior_funkcji;
    };
}

#endif // FUNKCJA_H