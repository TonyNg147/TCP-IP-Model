#ifndef   STD
#define   STD
#include <iostream>
#endif    //STD
namespace logger{
    class Logger;
};
namespace COLOR{
    enum  Code{
        FG_RED          = 31,
        FG_GREEN        = 32,
        FG_YELLOW       = 33,
        FG_BLUE         = 34,
        FG_MAGNETA      = 35,
        FG_DEFAULT      = 39,
    };
    class Modifier{
            Code mCode;
        public:
            void setColor(const Code& code){
                mCode = code;
            };
            Modifier* getColorModifier();
            friend class logger::Logger;
    };
};