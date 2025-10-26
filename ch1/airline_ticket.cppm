export module airline_ticket;

#include <string>

export class AirlineTicket {
public:
    AirlineTicket();
    ~AirlineTicket();

    double calculatePriceInDollers() const;

    std::string getPassengerName() const;
    void setPassengerName(std::string name);

    int getNumberOfMiles() const;
    void setNumberOfMiles(int miles);

    bool hasEliteSuperRewardsStatus() const;
    void setEliteSuperRewardsStatus(bool status);
private:
    std::string mPassengerName;
    int mNumberOfMiles;
    bool mHasEliteSuperRewardsStatus;
};