  // Copyright 2017 Lobanov Andrey

#include "include/application.h"
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>

Application::Application() {}

int ParseInt(const char* arg) {
  char* end;
  int value = strtol(arg, &end, 10);
  if (end[0] || value < 1) {
    throw std::string("ERROR: Incorrect size!");
  }
  return value;
}

float ParseFloat(const char* arg) {
  char* end;
  float value = strtof(arg, &end);
  if (end[0]) {
    throw std::string("ERROR: Wrong number format!");
  }
  return value;
}

Metric::TypeMetric ParseMetric(const char* arg) {
  Metric::TypeMetric typemetric;
  if (strcmp(arg, "L1") == 0)
    typemetric = Metric::L1;
  else if (strcmp(arg, "L2") == 0)
    typemetric = Metric::L2;
  else if (strcmp(arg, "L3") == 0)
    typemetric = Metric::L3;
  else if (strcmp(arg, "L4") == 0)
    typemetric = Metric::L4;
  else if (strcmp(arg, "LInf") == 0)
    typemetric = Metric::LInf;
  else
    throw std::string("ERROR: Incorrect type metric!");
  return typemetric;
}

void Application::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is the application for calculating the distances between vectors.\n"
    + "Please choose value of lengths of vector, their initial values and\n" +
    "provide arguments in the following format:\n\n" +

    "  $ " + appname + "\n<size> " +
    "<init1> <init2> <typemetric>\n\n" +

    "Where the first argument is the size of the vectors," +
    "should not be negative and not equal to zero,\n" +
    "The second and third arguments of the initial values ​​of the vectors,\n" +
    "the fourth argument is a type metric { L1, L2 ,L3, L4, LInf }";
}

bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 5) {
    help(argv[0], "ERROR: Should be 4 arguments.\n\n");
    return false;
  }
  return true;
}

std::string Application::operator()(int argc, const char** argv) {
  Arguments args;
  float distance;
  std::string str1, str2;
  if (!ValidateNumberOfArguments(argc, argv)) {
    return message_;
  }

  try {
      args.size = ParseInt(argv[1]);
      args.init1 = ParseFloat(argv[2]);
      args.init2 = ParseFloat(argv[3]);
      args.typemetric = ParseMetric(argv[4]);
  }
  catch (std::string& str) {
    return str;
  }
  std::vector<float> vector1(args.size);
  std::vector<float> vector2(args.size);
  for (int i = 0; i < args.size; i++) {
    vector1[i] = static_cast<float>(args.init1 * (i + 1));
    str1 += std::to_string(vector1[i]) + "\n";
  }
  for (int i = 0; i < args.size; i++) {
    vector2[i] = static_cast<float>(args.init2 + i * 0.5);
    str2 += std::to_string(vector2[i]) + "\n";
  }

  distance =
  DistanceBetweenVectors::CalculateDistance(vector1, vector2, args.typemetric);

  std::ostringstream stream;
  stream << "Size of vectors: " << args.size << "\n\nVector 1:\n"
         << str1 << "\nVector 2:\n" << str2 << "\nType metric: "
         << args.typemetric << "\n\nDistance between vectors: "
         << distance << "";
  message_ = stream.str();
  return message_;
}
