#pragma once
#include <PipeReader.h>
#include <PipeWriter.h>
#include <Messages.h>

#include <thread>
#include <chrono>
#include <future>
#include <iostream>

#define COLOR_BLUE "\33[1;34m"
#define COLOR_GREEN "\33[1;32m"
#define COLOR_RED "\33[1;91m"
#define COLOR_NORMAL "\33[0;39m"
#define CLEAR_LINE "\33[A\033[2K"
#define CLEAR_SCREEN "\033[2J\033[1;1H"

class Client
{
public:
  Client(IReader&, IWriter&, std::string, std::string);

  bool connect();
  void sendMessage(std::string_view msg);
  void handleMessage(ByteArray msg);

private:
  bool mConnected{false};
  std::vector<User> mUsers;

  std::string mName;
  std::string mId;

  IReader& mReader;
  IWriter& mWriter;

  std::thread mReaderThread;
  std::promise<bool> mLoginPromise;
};