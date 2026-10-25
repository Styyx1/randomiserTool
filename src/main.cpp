#include <random>
#include <print>
#include <cstdlib>

/*
This started as random int generator with the intention to manually type the max amount of options into the cli, 
but i decided to make a full mii generator with a single arg as well. 

will be expanded if i need other randomiser functions as well.
*/

int get_random_int(int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(1, max);
    return dist(rng);
}

std::string_view get_random_gender(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(1, 3);
    std::string_view gen = "Undefined";

    switch (dist(rng)){
        case 1:
        return "Male";
        case 2:
        return "Female";
        case 3:
        return "Non-Binary";
    };
    return gen;
}

void print_random_age(){
    std::println("Day: {}", get_random_int(28));
    std::println("Month: {}", get_random_int(12));
    std::println("Age: {}", get_random_int(85));
}

struct MiiOption{
    std::string_view m_name;
    int m_max;
};

void createMii(){

    constexpr std::array options {
        MiiOption{"Face Shape", 16},
        MiiOption{"Hair Style", 246},
        MiiOption{"Bangs", 83},
        MiiOption{"Hair Back", 111},
        MiiOption{"Eyebrows", 41},
        MiiOption{"Eyes", 76},
        MiiOption{"Nose", 31},
        MiiOption{"Mouth", 52},
        MiiOption{"Ears", 5},
        MiiOption{"Glasses", 52}
    };

    std::println("{:-^30}", "Mii Creator");
    std::println("{}", get_random_gender());

    std::println("{:-^30}", "Styles");
    for (const auto& option : options) {
        const int out = get_random_int(option.m_max);
        std::println("{}: {}", option.m_name, out);
    }

    std::println("{:-^30}", "Age");
    print_random_age();
}

void roll_dice(int sides = 6, int amount = 1){

    for (int i = 0; i < amount; ++i){
        std::println("Dice roll #{}, result is {}", i + 1, get_random_int(sides));
    }
        

}

int main(int argc, char** argv)
{

    if(argc > 1){

        auto farg = std::string_view(argv[1]);
        if(farg == "--mii" || farg == "-m"){
            createMii();
            return 0;
        }
        if(farg == "-d" || farg == "--dice"){

            //check if other args exist. 
            int sidearg = 6;
            int amountarg = 1;
            if(argc > 2){
                sidearg = std::clamp(std::stoi(argv[2]),2, 100);
            }
            if(argc > 3){
                amountarg = std::clamp(std::stoi(argv[3]),1, 10000);
            }
            roll_dice(sidearg, amountarg);
            return 0;
        }

    }
    for (int i = 1; i < argc; ++i) {

        const int argval = std::atoi(argv[i]);        

        // any arg not convertable to int returns 0, i need at least 1 for the get_random_int method
        if(argval < 1){
            std::println("Argument No. {} was, {}, which is wrong", i, argv[i]);
            continue;
        }
        const int out = get_random_int(argval);

        std::println("{}", out);
    }

    return 0;
}
