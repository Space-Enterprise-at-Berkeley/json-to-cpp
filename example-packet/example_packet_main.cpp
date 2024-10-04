#include "example_packet.h"

int main()
{
	auto empty = SupplyStatsV24::Builder()
        .withVoltage(1)
        .withCurrent(1)
        .withPower(1)
        .build();

	return 0;
}
