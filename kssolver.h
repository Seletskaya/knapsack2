#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include "ksparser.h"
#pragma once
using namespace std;

struct elem{
    int w;
    int v;
};

struct S{
    int l, p, b, w;
};

class kssolver{
    ksparser *el;
    int N;
public:
	int*out;
        elem arr;
        kssolver(ksparser *);
};
