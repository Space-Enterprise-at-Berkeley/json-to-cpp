#pragma once
#include <cstdint>
#include <type_traits>
#include <iostream>

typedef float f32;

class SupplyStatsV24 
{
public:

    template<bool f0set, bool f1set, bool f2set>
    class Builder_
    {
        private:
        f32 m_Supply24Voltage;
        f32 m_Supply24Current;
        f32 m_Supply24Power;

        public:
        Builder_(f32 Supply24VoltageIn, f32 Supply24CurrentIn, f32 Supply24PowerIn)
            : m_Supply24Voltage(Supply24VoltageIn), m_Supply24Current(Supply24CurrentIn), m_Supply24Power(Supply24PowerIn)
        {}

        Builder_() {}

        SupplyStatsV24 build() const
        {        
            static_assert( f0set &&  f1set &&  f2set, "All fields must be set before building."); // Added static assert
            return SupplyStatsV24(this->m_Supply24Voltage, this->m_Supply24Current, this->m_Supply24Power);
        }

            
        Builder_<true, f1set, f2set> withSupply24Voltage(f32 input) const 
        {
            static_assert(! f0set, "Cannot set field 'Supply24Voltage', it is already set");
            return Builder_<true, f1set, f2set>(input, this->m_Supply24Current, this->m_Supply24Power);
        }

            
        Builder_<f0set, true, f2set> withSupply24Current(f32 input) const 
        {
            static_assert(! f1set, "Cannot set field 'Supply24Current', it is already set");
            return Builder_<f0set, true, f2set>(this->m_Supply24Voltage, input, this->m_Supply24Power);
        }

            
        Builder_<f0set, f1set, true> withSupply24Power(f32 input) const 
        {
            static_assert(! f2set, "Cannot set field 'Supply24Power', it is already set");
            return Builder_<f0set, f1set, true>(this->m_Supply24Voltage, this->m_Supply24Current, input);
        }

            
    };

    using Builder = Builder_<false, false, false>;

private:
    float m_Voltage;
    float m_Current;
    float m_Power;

    SupplyStatsV24(float voltage, float current, float power)
        : m_Voltage(voltage), m_Current{current}, m_Power{power}
    {}
};

SupplyStatsV24 example()
{
    return SupplyStatsV24::Builder()
        .withSupply24Voltage(1)
        .withSupply24Current(1)
        .withSupply24Power(1)
        .build();
}