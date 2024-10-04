#pragma once
#include <cstdint>
#include <type_traits>
#include <iostream>

class SupplyStatsV24 
{
public:
    template<bool f1set, bool f2set, bool f3set>
    class Builder_
    {
    private:
        float m_Voltage;
        float m_Current;
        float m_Power;

    public:
        Builder_(float voltage, float current, float power)
            : m_Voltage{voltage}, m_Current{current}, m_Power{power}
        {}

        Builder_() {}

        Builder_<true, f2set, f3set> withVoltage(float voltage) const
        {
            static_assert(! f1set, "Cannot set field voltage; it's already set.");
            return Builder_<true, f2set, f3set>{voltage, m_Current, m_Power};
        }

        Builder_<f1set, true, f3set> withCurrent(float current) const
        {
            static_assert(! f2set, "Cannot set field voltage; it's already set.");

            return Builder_<f1set, true, f3set>{m_Voltage, current, m_Power};
        }

        Builder_<f1set, f2set, true> withPower(float power) const
        {        
            static_assert(!f3set, "Cannot set field power; it's already set."); // Added static assert
            return Builder_<f1set, f2set, true>{m_Voltage, m_Current, power};
        }

        SupplyStatsV24 build() const
        {        
            static_assert(f1set && f2set && f3set, "All fields must be set before building."); // Added static assert
            return SupplyStatsV24{m_Voltage, m_Current, m_Power};
        }
    };

    using Builder = Builder_<false, false, false>;

private:
    float m_Voltage;
    float m_Current;
    float m_Power;

    SupplyStatsV24(float voltage, float current, float power)
        : m_Voltage{voltage}, m_Current{current}, m_Power{power}
    {}
};

SupplyStatsV24 example()
{
    return SupplyStatsV24::Builder()
        .withVoltage(1)
        .withCurrent(1)
        .withPower(1)
        .build();
}