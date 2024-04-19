// Action.h
#pragma once
#include <string>

class Action {
private:
    std::string actionType; // Could be "attack", "defend", etc.
    int power;
    std::string uniqueIdentifier;

public:
    Action(const std::string& actionType, int power);
    virtual ~Action() = default;

    // Getters and setters
    std::string getActionType() const;
    void setActionType(const std::string& actionType);
    int getPower() const;
    void setPower(int power);
    std::string getUniqueIdentifier() const;
    // Additional functionality as needed
};
