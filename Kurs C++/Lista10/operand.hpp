#ifndef OPERAND_H
#define OPERAND_H

#include "symbol.hpp"
#include <map>

namespace kalkulator
{
    class operand : public symbol
    {
        public:
            operand();
            virtual ~operand();
            virtual double get_wartosc();

            void execute();
    };
}


namespace kalkulator
{
    class liczba : public operand
    {
        public:
            const double wartosc;
            liczba(double wartosc);
            virtual ~liczba();

            double get_wartosc();
    };
}

namespace kalkulator
{
    class stala : public operand
    {
        public:
            const std::string nazwa;
            const double wartosc;

            double get_stala(std::string nazwa);
            stala(std::string, double);
            virtual ~stala();
            double get_wartosc();

        protected:

        private:
            static std::map<std::string, double> ZbiorStalych;
    };
}

namespace kalkulator
{
    class zmienna : public operand
    {
        public:
            const std::string nazwa;

            double get_zmienna(std::string);
            void dodaj_zmienna(std::string, double);

            zmienna(std::string);
            virtual ~zmienna();

            double get_Wartosc();

        private:
            static std::map<std::string, double> ZbiorStalych;
    };
}

#endif // OPERAND_H