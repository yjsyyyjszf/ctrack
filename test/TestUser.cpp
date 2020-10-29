#include "User.h"
#include "gtest/gtest.h"
#include <string>

unsigned int User::counter = 0;

TEST(TestUser, user_id) {
    User* michael = new User("Michael");
    User* dwight = new User("Dwight");
    User* jim = new User("Jim");
    User* pam = new User("Pam");

    EXPECT_EQ(michael->getID(), 0);
    EXPECT_EQ(dwight->getID(), 1);
    EXPECT_EQ(jim->getID(), 2);
    EXPECT_EQ(pam->getID(), 3);

    delete michael;
    delete dwight;
    delete jim;
    delete pam;
}

TEST(TestUser, setting_and_getting_name) {
    User* jane = new User("Jane");

    // check original name
    EXPECT_EQ(jane->getName(), "Jane");

    // change name to John
    jane->setName("John");
    EXPECT_EQ(jane->getName(), "John");

    delete jane;
}

TEST(TestUser, setting_and_getting_group) {
    User* jane = new User("Jane");

    // checking default user group
    EXPECT_EQ(jane->getGroup(), "user");

    // change user group to developer
    jane->setGroup(0);
    EXPECT_EQ(jane->getGroup(), "developer");

    // change to tester
    jane->setGroup(1);
    EXPECT_EQ(jane->getGroup(), "tester");

    // change to manager
    jane->setGroup(2);
    EXPECT_EQ(jane->getGroup(), "manager");

    // change back to user
    jane->setGroup(3);
    EXPECT_EQ(jane->getGroup(), "user");

    // check default
    jane->setGroup(999);
    EXPECT_EQ(jane->getGroup(), "user");

    delete jane;
}
