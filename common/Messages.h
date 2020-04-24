#pragma once
#include <cstdint>
#include <string>

enum class EMessage : uint8_t
{
  Error,
  Login,
  LoginStatus,
  Message
};

struct Login
{
  std::string name;
  std::string key;
  std::string path;
};

enum class ELoginStatus : uint8_t
{
  Failed = 0,
  Succeeded = 1
};

struct LoginStatus
{
  ELoginStatus status;
};

struct Message
{
  std::string name;
  std::string key;
  std::string message;
};