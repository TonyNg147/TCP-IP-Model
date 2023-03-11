#include "Logger.h"
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif  //IOSTREAM
#include <stdarg.h>
#include <time.h>
namespace logger{
    #define toString(N) std::to_string(N)
    std::string padTime(const int& time){
        if (time<10) return std::string("0"+toString(time));
        return toString(time);
    };
     Logger::Logger(const LOG_SEVERITY& severity,const COLOR::Code& color)
        :m_severity{severity}
     {
         setColor(color);
     };
     void Logger::setColor(const COLOR::Code& color){
         modifier.setColor(color);
     };

     void Logger::loggout(const char* format,...){
        time_t now = time(0);
        struct tm now_t = *localtime(&now);
        std::string logMsg="";
        logMsg="["+toString(now_t.tm_year + 1900)
                +"-"+padTime(now_t.tm_mon + 1)
                +"-"+padTime(now_t.tm_mday)
                +" "+padTime(now_t.tm_hour)
                +":"+padTime(now_t.tm_min)
                +":"+padTime(now_t.tm_sec)+"] ";
        logMsg+=("["+m_logLevelStr[m_severity]+"] ");
        printf("\033[%dm%s\033[0m",modifier.mCode,logMsg.c_str());
        va_list arg;
        va_start(arg,format);
        vprintf(format,arg);
        va_end(arg);
        printf("\n");
     }
};
