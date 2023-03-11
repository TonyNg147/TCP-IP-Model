#include "./Color.h"
#include <string>
namespace logger{
    class Logger{
        public:
            enum LOG_SEVERITY{
                ERROR=0,
                WARNING,
                INFO,
                DEBUG
            };
        private:
            #define  SEVERITY_TOTAL  (4)
            COLOR::Modifier modifier;
            LOG_SEVERITY m_severity = LOG_SEVERITY::ERROR;
            std::string  m_logLevelStr[SEVERITY_TOTAL] 
                        = {"ERROR","WARNING","INFOR","DEBUG"};
        public:
            Logger(const LOG_SEVERITY&,const COLOR::Code& color);
            void setSeverity(const LOG_SEVERITY& severity);
            void setColor(const COLOR::Code& color);
            void loggout(const char* ,...);
    };
};
static logger::Logger _INFO(logger::Logger::INFO,COLOR::FG_BLUE);
static logger::Logger _WARN(logger::Logger::WARNING,COLOR::FG_RED);
static logger::Logger _CRITICAL(logger::Logger::ERROR,COLOR::FG_YELLOW);
static logger::Logger _DEBUG(logger::Logger::DEBUG,COLOR::FG_GREEN);
#define LOG_WARN_MASK     (0x000001)
#define LOG_ERROR_MASK    (0x000002)
#define LOG_INFO_MASK     (0x000003)
#define LOG_DEBUG_MASK    (0x000004)
#ifdef INFO
#define LOGGER(str) INFO.loggout(str)
#endif
#ifdef WARN

#ifdef MODE_WARN 
#define LOG_MASK 0x000001
#endif
#ifdef MODE_ERROR 
#define LOG_MASK 0x000002
#endif
#ifdef MODE_DEBUG
#define LOG_MASK 0x000004
#endif
#ifdef MODE_INFO
#define LOG_MASK 0x000003
#endif
#ifndef LOG_MASK
#define LOG_MASK 0x000000
#endif //LOG_MASK
#define LOG_VALID(MASK)  if (!LOG_MASK||(LOG_MASK==MASK))
template<typename... Args>
static void logWarn(const char* format,Args... args){
    LOG_VALID(LOG_WARN_MASK)
    _WARN.loggout(format,args...);
}
template<typename... Args> 
static void logInfo(const char* format,Args... args){
    LOG_VALID(LOG_INFO_MASK)
    _INFO.loggout(format,args...);
}
template<typename... Args>
static void logError(const char* format,Args... args){
    LOG_VALID(LOG_ERROR_MASK)
    _CRITICAL.loggout(format,args...);
} 
template<typename... Args>
static void logDebug(const char* format,Args... args){
    LOG_VALID(LOG_DEBUG_MASK)
    _DEBUG.loggout(format,args...);
} 
#endif