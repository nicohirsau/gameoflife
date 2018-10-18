#include "petridish.hpp"

Petridish::Petridish(int width, int height) {
    Width = width;
    Height = height;
    int d_dimension = Width * Height;
    CurrentCulture = new std::vector<bool>(d_dimension, false); //create new pointer with a initialized vector as value
    BufferCulture = new std::vector<bool>(d_dimension, false);

}

void Petridish::InitializeRandomCulture() {
    srand(time(NULL));
    int d_dimension = Width * Height;
    for (int i = 0; i <= d_dimension; i++) {
        SetCellValue(i%Width, i/Width, (rand() % 3 == 0), CurrentCulture);
    }
}

void Petridish::Update() {
    int d_dimension = Width * Height;
    for (int i = 0; i < d_dimension; i++) {
        int neighbour_count = GetNeighbourCount(i%Width, i/Width);
        bool is_cell_living = false;
        if (CurrentCulture->at(i)) {
            if(neighbour_count <= 1)
                is_cell_living = false;
            else if (neighbour_count >= 4)
                is_cell_living = false;
            else
                is_cell_living = true;
        }
        else if (neighbour_count == 3)
            is_cell_living = true;
        SetCellValue(i%Width, i/Width, is_cell_living, BufferCulture);
    }
}

int Petridish::GetNeighbourCount(int x, int y) {
    int n_count = 0;
    if (GetCellValue(x-1, y-1, CurrentCulture))
        n_count++;
    if (GetCellValue(x  , y-1, CurrentCulture))
        n_count++;
    if (GetCellValue(x+1, y-1, CurrentCulture))
        n_count++;
    if (GetCellValue(x-1, y  , CurrentCulture))
        n_count++;
    if (GetCellValue(x+1, y  , CurrentCulture))
        n_count++;
    if (GetCellValue(x-1, y+1, CurrentCulture))
        n_count++;
    if (GetCellValue(x  , y+1, CurrentCulture))
        n_count++;
    if (GetCellValue(x+1, y+1, CurrentCulture))
        n_count++;
    return n_count;
}

std::vector<bool> *Petridish::GetCulture() {
    return CurrentCulture; //return pointer of vector
}
void Petridish::ApplyBuffer() {
    delete CurrentCulture; //delete value/memory pointer is pointing at
    CurrentCulture = NULL; //delete pointer/memory-address

    //let currentculture pointer point to bufferculture value
    CurrentCulture = BufferCulture; 

    //assign bufferculture a new pointer with value
    BufferCulture = new std::vector<bool>(Width * Height, false); 
}

bool Petridish::GetCellValue(int x, int y, std::vector<bool> *culture) {
    return culture->at(Width * GetInboundYValue(y) + GetInboundXValue(x));
}

void Petridish::SetCellValue(int x, int y, bool value, std::vector<bool> *culture) {
    culture->operator[](Width * GetInboundYValue(y) + GetInboundXValue(x)) = value;
}

int Petridish::GetInboundXValue(int val) {
    int ret = val % Width;
    return (val >= 0) ? ret : ret + Width;
}
int Petridish::GetInboundYValue(int val) {
    int ret = val % Height;
    return (val >= 0) ? ret : ret + Height;
}

Petridish::~Petridish() {
    std::cout << std::endl << "Deconstructing Petridish instance...";
    delete CurrentCulture;
    delete BufferCulture;
    CurrentCulture = NULL;
    BufferCulture = NULL;
}
