//
// Created by thevlyou on 24. 10. 30.
//

#ifndef TESTSET_HPP
#define TESTSET_HPP

struct AccountInfo {
    int accountNum, balance;
};

struct CardInfo {
    int cardNum, pinNum;
    AccountInfo account[2];
};

namespace testset {
    inline CardInfo testAccount[2] = {{0, 2345, 0, 234, 1, 45}, {1, 4564, 0, 100, 1, 37}};
}

#endif //TESTSET_HPP
