#include <iostream>

import airline_ticket;

int main() {
    AirlineTicket ticket;

    ticket.setPassengerName("John Doe");
    ticket.setNumberOfMiles(1500);
    ticket.setEliteSuperRewardsStatus(false);

    std::cout << "Passenger Name: " << ticket.getPassengerName() << std::endl;
    std::cout << "Ticket Price: $" << ticket.calculatePriceInDollers() << std::endl;

    return 0;
}