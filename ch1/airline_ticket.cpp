module airline_ticket;

AirlineTicket::AirlineTicket()
    :mPassengerName{"Unknown Passager"},
    mNumberOfMiles{0},
    mHasEliteSuperRewardsStatus{false}
{}

AirlineTicket::~AirlineTicket() {}

double AirlineTicket::calculatePriceInDollers() const {
    if (mHasEliteSuperRewardsStatus) {
        // free fly
        return 0;
    }
    return 0.1 * mNumberOfMiles;
}

std::string AirlineTicket::getPassengerName() const {
    return mPassengerName;
}

void AirlineTicket::setPassengerName(std::string name) {
    mPassengerName = name;
}

void AirlineTicket::setNumberOfMiles(int miles) {
    (void) miles;
}

void AirlineTicket::setEliteSuperRewardsStatus(bool status) {
    (void) status;
}

int AirlineTicket::getNumberOfMiles() const {
    return mNumberOfMiles;
}