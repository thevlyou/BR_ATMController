//
// Created by thevlyou on 24. 10. 30.
//

#ifndef ATMCONTROLLER_HPP
#define ATMCONTROLLER_HPP

#include <iostream>
#include "testset.hpp"

enum ACCOUNT_FUNCTION {
    ACCOUNT_NO_ACT,
    ACCOUNT_SEE_BALANCE,
    ACCOUNT_DEPOSIT,
    ACCOUNT_WITHDRAW,
    ACCOUNT_END_WORK
};

enum CONTROLLER_STATE {
    CONTROLLER_NO_ACT,
    CONTROLLER_START,
    CONTROLLER_CARD_CHECKED,
    CONTROLLER_PIN_CHECKED,
    CONTROLLER_FUNCTION_READY,
    CONTROLLER_ERROR
};

class ATMController {
public:
    ATMController();

    void startATM();

    void checkCard();
    void checkPIN();
    void selectAccount();

    void accountFunction();
    void seeBalance();
    void deposit();
    void withdraw();
private:
    int controllerState = CONTROLLER_START;
    int cardNum = 0;
    int accountNum = 0;
};

#endif //ATMCONTROLLER_HPP
