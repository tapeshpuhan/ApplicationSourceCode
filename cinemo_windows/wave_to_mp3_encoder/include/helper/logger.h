//
// Created by Tapeswar on 2/13/20.
//

#ifndef MP3ENCODER_LOGGER_H
#define MP3ENCODER_LOGGER_H

#include <cstdint>
#include <iostream>
#include <sstream>

constexpr std::int32_t kEnableInfoLogger{1};
constexpr std::int32_t kEnableWarningLogger{1};
constexpr std::int32_t kEnableErrorLogger{1};

class Logger
{
  public:
    template <typename LOG, typename... Args>
    static void LogError(const LOG& info, Args... args)
    {
        if (kEnableErrorLogger)
        {
            std::stringstream string_stream;
            LogMsgInfo(string_stream, info, args...);
        }
    }
    template <typename LOG, typename... Args>
    static void LogWarning(const LOG& info, Args... args)
    {
        if (kEnableWarningLogger)
        {
            std::stringstream string_stream;
            LogMsgInfo(string_stream, info, args...);
        }
    }
    template <typename LOG, typename... Args>
    static void LogInfo(const LOG& info, Args... args)
    {
        if (kEnableInfoLogger)
        {
            std::stringstream string_stream;
            LogMsgInfo(string_stream, info, args...);
        }
    }

  private:
    template <typename LOG>
    static void LogMsgInfo(std::stringstream& stream, const LOG& info)
    {
        stream << info;
        std::cout << stream.str() << std::endl;
    }
    template <typename LOG, typename... Args>
    static void LogMsgInfo(std::stringstream& stream, const LOG& info, Args... args)
    {
        stream << info;
        LogMsgInfo(stream, args...);
    }
};

#endif  // MP3ENCODER_LOGGER_H
