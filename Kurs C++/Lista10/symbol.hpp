#ifndef SYMBOL_H
#define SYMBOL_H

#include <stack>

namespace kalkulator
{
    class symbol
    {
        public:
            double result();

            symbol() = default;
            virtual ~symbol() = default;

            virtual void execute() = 0;

        protected:
            std::stack<symbol*> stos;
    };
}

#endif