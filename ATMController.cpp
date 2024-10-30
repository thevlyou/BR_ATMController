//
// Created by thevlyou on 24. 10. 30.
//

#include "ATMController.hpp"

ATMController::ATMController() {

}

void ATMController::startATM() {
    checkCard();
    accountFunction();
}


void ATMController::checkCard() {
    int card;
    bool cardFound = false;

    while(controllerState == CONTROLLER_START) {
        std::cout << "\nInsert your card (If you want to exit, enter -1) :";
        std::cin >> card;

        if(card >= 0) {
            for(int i=0; i<std::size(testset::testAccount); i++) {
                if(card == testset::testAccount[i].cardNum) {
                    controllerState = CONTROLLER_CARD_CHECKED;
                    cardNum = i;
                    cardFound = true;
                    checkPIN();
                }
            }

            if(!cardFound) {
                std::cout << "\nWrong card\n";
            }

            cardFound = false;
        }
        else if(card < 0) {
            std::cout << "\nEnd testing\n";
            controllerState = CONTROLLER_NO_ACT;
            return;
        }
    }
}

void ATMController::checkPIN() {
    int pin;

    while(controllerState == CONTROLLER_CARD_CHECKED) {
        std::cout << "\nEnter your password (If you want to go back, enter -1) :";
        std::cin >> pin;

        if(pin == testset::testAccount[cardNum].pinNum) {
            controllerState = CONTROLLER_PIN_CHECKED;
            selectAccount();
        }
        else if(pin < 0) {
            controllerState = CONTROLLER_START;
            checkCard();
            return;
        }
        else {
            std::cout << "\nWrong pin\n";
        }
    }
}

void ATMController::selectAccount() {
    int num;
    bool accountFound = false;

    while(controllerState == CONTROLLER_PIN_CHECKED) {
        std::cout << "\nEnter your account (If you want to go back, enter -1) :";
        std::cin >> num;

        if(num >= 0) {
            for(int i=0; i<std::size(testset::testAccount[cardNum].account); i++) {
                if(num == testset::testAccount[cardNum].account[i].accountNum) {
                    controllerState = CONTROLLER_FUNCTION_READY;
                    accountFound = true;
                    accountNum = i;
                }
            }

            if(!accountFound) {
                std::cout << "\nWrong account\n";
            }

            accountFound = false;
        }
        else {
            controllerState = CONTROLLER_START;
            checkCard();
            return;
        }
    }
}

void ATMController::accountFunction() {
    int command = ACCOUNT_NO_ACT;

    while(controllerState == CONTROLLER_FUNCTION_READY) {
        switch(command) {
            case ACCOUNT_NO_ACT:
                std::cout << "\nEnter command (If you want to go back, enter -1) :";
                std::cin >> command;
                break;
            case ACCOUNT_SEE_BALANCE:
                seeBalance();
                command = ACCOUNT_NO_ACT;
                break;
            case ACCOUNT_DEPOSIT:
                deposit();
                command = ACCOUNT_NO_ACT;
                break;
            case ACCOUNT_WITHDRAW:
                withdraw();
                command = ACCOUNT_NO_ACT;
                break;
            case ACCOUNT_END_WORK:
                controllerState = CONTROLLER_PIN_CHECKED;
                command = ACCOUNT_NO_ACT;
                selectAccount();
                break;
            default:
                command = ACCOUNT_END_WORK;
                break;
        }
    }
}

void ATMController::seeBalance() {
    std::cout << "\nBalance of " << testset::testAccount[cardNum].account[accountNum].accountNum << " : " << testset::testAccount[cardNum].account[accountNum].balance << std::endl;
}

void ATMController::deposit() {
    int deposit;
    std::cout << "\nEnter deposit value : ";
    std::cin >> deposit;
    testset::testAccount[cardNum].account[accountNum].balance += deposit;
    std::cout << "\nBalance of " << testset::testAccount[cardNum].account[accountNum].accountNum << " : " << testset::testAccount[cardNum].account[accountNum].balance << std::endl;
}

void ATMController::withdraw() {
    int withdraw;
    std::cout << "\nEnter withdraw value : ";
    std::cin >> withdraw;
    testset::testAccount[cardNum].account[accountNum].balance -= withdraw;
    std::cout << "\nBalance of " << testset::testAccount[cardNum].account[accountNum].accountNum << " : " << testset::testAccount[cardNum].account[accountNum].balance << std::endl;
}