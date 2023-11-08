#pragma once

#include <cstddef>
#include <cstdint>
#include <iostream>

struct DiagService {
  std::string serviceName;
  std::uint16_t serviceId;
  bool supportSubFunc;
};

struct NonSubFuncService : public DiagService{ 
  NonSubFuncService() {
    supportSubFunc = false;
  }
};

struct SubFuncService : public DiagService {
  SubFuncService() {
    supportSubFunc = true;
  }
}; 


struct ReadDataByIdentifer : public NonSubFuncService {
  ReadDataByIdentifer() {
    this->serviceName = "ReadDataByIdentifer";
    this->serviceId = std::uint16_t(0x22);
    this->supportSubFunc = false;
  }
};

struct WriteDataByIdentifer : public NonSubFuncService {
  WriteDataByIdentifer() {
    this->serviceName = "WriteDataByIdentifer";
    this->serviceId = std::uint16_t(0x2E);
    this->supportSubFunc = false;
  }
};

struct ECUReset : public SubFuncService {
  ECUReset() {
    this->serviceName = "ECUReset";
    this->serviceId = std::uint16_t(0x11);
    this->supportSubFunc = true;
  }
};


