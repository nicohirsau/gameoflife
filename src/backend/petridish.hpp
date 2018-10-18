#ifndef PETRIDISH_H
#define PETRIDISH_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Petridish {
public:
    int Width;
    int Height;

    Petridish(int, int);
    ~Petridish();
    void InitializeRandomCulture();
    void Update();
    std::vector<bool> *GetCulture();
    void ApplyBuffer();
private:
    std::vector<bool> *CurrentCulture; //Value type with no pointer
    std::vector<bool> *BufferCulture;
    int GetNeighbourCount(int, int);
    bool GetCellValue(int, int, std::vector<bool> *culture);
    void SetCellValue(int, int, bool, std::vector<bool> *culture);
    int GetInboundXValue(int);
    int GetInboundYValue(int);
};

#endif