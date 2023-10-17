#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = { {"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"} };
    TwitterData* twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    //
    // Your code goes here
    std::map<std::string, TwitterData*> mapSceneOne;
    mapSceneOne[twitter_data[0].getUserName()] = twitter_data + 0;
    mapSceneOne[twitter_data[1].getUserName()] = twitter_data + 1;
    mapSceneOne[twitter_data[2].getUserName()] = twitter_data + 2;
    mapSceneOne[twitter_data[3].getUserName()] = twitter_data + 3;
    mapSceneOne [twitter_data[4].getUserName()]= twitter_data + 4;
   
    std::map<std::string, TwitterData*>::iterator i = mapSceneOne.begin();
    std::map<std::string, TwitterData*>::iterator finder = mapSceneOne.find("savage1");
    while (i != mapSceneOne.end())
    {
        std::cout << "Key: " << i->first << "   Value : " << i->second->print() << std::endl;
        ++i;
    }

    std::cout << "Print Record for Username Savage1: " << finder->second->print() << std::endl;
    mapSceneOne.erase("savage1");

    std::map<std::string, TwitterData*> mapSceneTwo;
    mapSceneTwo[twitter_data[0].getEmail()] = twitter_data + 0;
    mapSceneTwo[twitter_data[1].getEmail()] = twitter_data + 1;
    mapSceneTwo[twitter_data[2].getEmail()] = twitter_data + 2;
    mapSceneTwo[twitter_data[3].getEmail()] = twitter_data + 3;
    mapSceneTwo[twitter_data[4].getEmail()] = twitter_data + 4;

    std::map<std::string, TwitterData*>::iterator i2 = mapSceneTwo.begin();
    std::map<std::string, TwitterData*>::iterator finder2 = mapSceneTwo.find("kat@gmail.com");
    while (i2 != mapSceneTwo.end())
    {
        std::cout << "Key: " << i2->first << "   Value : " << i2->second->print() << std::endl;
        ++i2;
    }

    std::cout << "Print Record for email kat@gmail.com: " << finder2->second->print() << std::endl;
    mapSceneTwo.erase("kat@gmail.com");
    //


    return 0;
}