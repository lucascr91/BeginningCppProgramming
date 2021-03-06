#pragma once
#include <string>

class Account {
// protected: // Can be directly accessed from derived classes, but it's bad practice.
    std::string name;
    double balance;
public:
    // TODO: Should constexpr variables be public? Or should I stick to getters and setters?
    // These are compile time constants.
    static constexpr char DEF_NAME [] {"Generic Account"};
    static constexpr double DEF_BALANCE {0.00};

    Account(std::string name = DEF_NAME, double balance = DEF_BALANCE);
    Account(const Account &source);
    ~Account();

    Account &operator=(const Account &rhs);

    const std::string &get_name() const;
    void set_name(const std::string &name);
    double get_balance() const;
    void set_balance(double balance);

    bool deposit(double amount);
    bool withdraw(double amount);
};

std::ostream &operator<<(std::ostream &os, const Account &rhs);