#pragma once

#include "app_utils/app.hpp"
#include "core/executables/plotter/csv.hpp"
#include <map>

struct measurement_element_t {
  struct time_and_duration {
    double time;
    double duration;
  };
  std::vector<time_and_duration> timeData;
  double meanDuration;
  double standardDeviation;

  std::string location;
  std::string_view fileAndLine;
  std::string_view function;
};

class Plotter : public App {
protected:
  virtual void Draw();

private:
  void processSessionData();

  bool sessionCsvValid;
  std::vector<session_row_t> sessionData;
  std::map<std::string, measurement_element_t> measurements;
};