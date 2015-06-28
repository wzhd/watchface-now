#include <pebble.h>

#define NUM_MAP_PATHS 58

static const struct GPathInfo MAP_PATHS[] = {
  { 5, (GPoint []){
      {81, 134},
      {82, 134},
      {84, 133},
      {85, 134},
      {81, 134},
    }
  },
  { 250, (GPoint []){
      {76, 130},
      {75, 129},
      {79, 128},
      {84, 126},
      {86, 125},
      {88, 124},
      {89, 123},
      {89, 122},
      {89, 120},
      {89, 119},
      {90, 118},
      {92, 117},
      {94, 117},
      {94, 119},
      {92, 122},
      {90, 125},
      {89, 126},
      {90, 126},
      {92, 125},
      {95, 124},
      {97, 123},
      {100, 123},
      {102, 122},
      {107, 118},
      {109, 117},
      {108, 117},
      {105, 117},
      {105, 116},
      {106, 113},
      {109, 108},
      {111, 106},
      {113, 104},
      {113, 102},
      {111, 101},
      {112, 99},
      {112, 98},
      {112, 99},
      {114, 100},
      {115, 98},
      {116, 97},
      {117, 97},
      {117, 96},
      {116, 96},
      {115, 96},
      {114, 96},
      {112, 96},
      {112, 94},
      {112, 87},
      {113, 83},
      {112, 84},
      {110, 85},
      {109, 83},
      {110, 82},
      {111, 79},
      {108, 79},
      {106, 79},
      {105, 79},
      {103, 79},
      {104, 78},
      {105, 77},
      {107, 75},
      {107, 76},
      {107, 77},
      {106, 78},
      {107, 78},
      {109, 77},
      {111, 77},
      {112, 75},
      {113, 73},
      {115, 70},
      {114, 67},
      {111, 63},
      {107, 61},
      {105, 60},
      {107, 57},
      {109, 52},
      {109, 48},
      {107, 45},
      {104, 46},
      {101, 44},
      {98, 43},
      {100, 46},
      {101, 47},
      {98, 49},
      {94, 52},
      {91, 54},
      {89, 54},
      {85, 55},
      {82, 54},
      {81, 50},
      {82, 45},
      {83, 42},
      {81, 39},
      {79, 38},
      {75, 38},
      {72, 34},
      {73, 31},
      {75, 29},
      {77, 26},
      {81, 26},
      {84, 26},
      {84, 27},
      {86, 28},
      {89, 29},
      {92, 29},
      {94, 31},
      {95, 32},
      {96, 33},
      {96, 32},
      {97, 31},
      {98, 29},
      {96, 28},
      {93, 26},
      {92, 25},
      {91, 25},
      {90, 26},
      {89, 25},
      {85, 21},
      {85, 22},
      {86, 23},
      {88, 24},
      {84, 22},
      {83, 22},
      {81, 23},
      {80, 23},
      {79, 24},
      {78, 25},
      {75, 25},
      {75, 23},
      {76, 23},
      {78, 22},
      {77, 21},
      {77, 20},
      {78, 20},
      {82, 17},
      {83, 16},
      {83, 17},
      {86, 17},
      {89, 16},
      {90, 15},
      {89, 14},
      {90, 13},
      {90, 12},
      {89, 12},
      {87, 13},
      {87, 14},
      {87, 15},
      {86, 16},
      {84, 16},
      {82, 15},
      {81, 14},
      {81, 13},
      {83, 12},
      {85, 11},
      {86, 10},
      {88, 9},
      {97, 11},
      {99, 12},
      {101, 13},
      {99, 13},
      {98, 13},
      {99, 14},
      {101, 13},
      {104, 13},
      {107, 14},
      {110, 17},
      {114, 20},
      {115, 20},
      {118, 20},
      {121, 22},
      {123, 23},
      {126, 26},
      {125, 27},
      {124, 26},
      {123, 25},
      {120, 23},
      {117, 22},
      {116, 22},
      {115, 22},
      {116, 23},
      {118, 25},
      {120, 27},
      {123, 31},
      {124, 36},
      {124, 37},
      {125, 37},
      {126, 36},
      {131, 40},
      {131, 42},
      {129, 42},
      {128, 43},
      {129, 45},
      {131, 47},
      {132, 49},
      {134, 53},
      {133, 55},
      {133, 56},
      {134, 56},
      {135, 54},
      {135, 53},
      {136, 54},
      {137, 57},
      {137, 59},
      {139, 73},
      {140, 80},
      {140, 83},
      {141, 77},
      {141, 73},
      {142, 73},
      {142, 74},
      {142, 73},
      {142, 70},
      {143, 73},
      {143, 76},
      {142, 77},
      {142, 79},
      {142, 80},
      {140, 84},
      {139, 85},
      {139, 88},
      {138, 91},
      {137, 93},
      {136, 92},
      {136, 91},
      {136, 90},
      {135, 92},
      {133, 97},
      {133, 98},
      {132, 99},
      {130, 101},
      {130, 102},
      {131, 102},
      {131, 103},
      {130, 105},
      {130, 104},
      {129, 104},
      {127, 105},
      {125, 108},
      {125, 110},
      {121, 115},
      {119, 118},
      {114, 121},
      {111, 123},
      {108, 125},
      {106, 127},
      {102, 128},
      {99, 128},
      {93, 130},
      {85, 131},
      {76, 130},
    }
  },
  { 5, (GPoint []){
      {93, 46},
      {91, 45},
      {92, 46},
      {93, 47},
      {93, 46},
    }
  },
  { 8, (GPoint []){
      {106, 42},
      {105, 39},
      {104, 37},
      {104, 39},
      {104, 42},
      {106, 43},
      {107, 43},
      {106, 42},
    }
  },
  { 5, (GPoint []){
      {99, 39},
      {96, 33},
      {97, 37},
      {99, 42},
      {99, 39},
    }
  },
  { 10, (GPoint []){
      {109, 35},
      {110, 33},
      {110, 30},
      {108, 29},
      {107, 29},
      {107, 31},
      {107, 33},
      {107, 35},
      {108, 36},
      {109, 35},
    }
  },
  { 11, (GPoint []){
      {102, 27},
      {100, 26},
      {99, 24},
      {99, 23},
      {97, 23},
      {95, 23},
      {94, 23},
      {95, 25},
      {97, 26},
      {100, 27},
      {102, 27},
    }
  },
  { 4, (GPoint []){
      {92, 15},
      {91, 14},
      {91, 15},
      {92, 15},
    }
  },
  { 3, (GPoint []){
      {93, 15},
      {93, 14},
      {93, 15},
    }
  },
  { 4, (GPoint []){
      {116, 124},
      {120, 122},
      {118, 123},
      {116, 124},
    }
  },
  { 9, (GPoint []){
      {122, 121},
      {126, 115},
      {128, 115},
      {127, 117},
      {125, 119},
      {124, 119},
      {123, 120},
      {122, 122},
      {122, 121},
    }
  },
  { 8, (GPoint []){
      {119, 119},
      {121, 118},
      {122, 117},
      {123, 116},
      {123, 117},
      {122, 118},
      {120, 119},
      {119, 119},
    }
  },
  { 7, (GPoint []){
      {103, 116},
      {103, 115},
      {103, 114},
      {104, 113},
      {104, 115},
      {103, 117},
      {103, 116},
    }
  },
  { 179, (GPoint []){
      {21, 116},
      {20, 115},
      {17, 112},
      {15, 108},
      {14, 105},
      {12, 101},
      {11, 98},
      {9, 95},
      {9, 93},
      {8, 93},
      {7, 93},
      {7, 92},
      {6, 91},
      {6, 89},
      {6, 88},
      {5, 83},
      {4, 81},
      {3, 78},
      {4, 77},
      {5, 78},
      {7, 79},
      {8, 78},
      {8, 75},
      {8, 73},
      {8, 72},
      {5, 70},
      {6, 70},
      {7, 69},
      {7, 66},
      {7, 62},
      {7, 63},
      {8, 64},
      {9, 66},
      {11, 67},
      {13, 66},
      {14, 64},
      {15, 62},
      {16, 61},
      {15, 60},
      {14, 59},
      {13, 59},
      {12, 59},
      {11, 59},
      {11, 58},
      {11, 55},
      {9, 55},
      {7, 57},
      {6, 61},
      {5, 63},
      {4, 62},
      {4, 58},
      {6, 56},
      {7, 53},
      {8, 51},
      {9, 50},
      {8, 48},
      {6, 46},
      {7, 44},
      {9, 42},
      {11, 42},
      {11, 41},
      {10, 40},
      {18, 29},
      {21, 25},
      {23, 26},
      {24, 28},
      {23, 34},
      {23, 38},
      {23, 42},
      {21, 43},
      {18, 44},
      {15, 44},
      {13, 44},
      {12, 44},
      {12, 45},
      {12, 47},
      {12, 49},
      {13, 50},
      {12, 51},
      {11, 53},
      {11, 54},
      {12, 53},
      {13, 52},
      {13, 51},
      {13, 50},
      {16, 49},
      {18, 48},
      {20, 47},
      {20, 48},
      {19, 49},
      {19, 51},
      {18, 53},
      {19, 53},
      {21, 52},
      {21, 51},
      {22, 52},
      {21, 54},
      {21, 55},
      {21, 56},
      {21, 57},
      {21, 58},
      {22, 59},
      {22, 60},
      {24, 62},
      {25, 63},
      {27, 64},
      {28, 65},
      {27, 66},
      {25, 67},
      {25, 69},
      {25, 70},
      {25, 72},
      {27, 74},
      {29, 73},
      {30, 71},
      {30, 70},
      {30, 69},
      {31, 69},
      {33, 68},
      {35, 68},
      {37, 68},
      {37, 67},
      {37, 65},
      {36, 62},
      {37, 60},
      {38, 58},
      {42, 55},
      {44, 54},
      {46, 53},
      {48, 54},
      {50, 57},
      {52, 59},
      {52, 61},
      {53, 63},
      {54, 65},
      {56, 67},
      {58, 69},
      {59, 69},
      {59, 70},
      {51, 68},
      {47, 67},
      {44, 68},
      {41, 68},
      {40, 67},
      {39, 66},
      {38, 66},
      {38, 67},
      {38, 69},
      {36, 69},
      {33, 70},
      {32, 73},
      {28, 78},
      {25, 82},
      {27, 81},
      {29, 80},
      {27, 82},
      {24, 85},
      {22, 88},
      {20, 89},
      {19, 90},
      {18, 91},
      {17, 94},
      {17, 95},
      {17, 100},
      {18, 104},
      {19, 106},
      {20, 107},
      {21, 109},
      {23, 109},
      {25, 110},
      {24, 110},
      {24, 112},
      {24, 114},
      {23, 114},
      {23, 115},
      {24, 116},
      {23, 115},
      {22, 116},
      {21, 116},
    }
  },
  { 8, (GPoint []){
      {9, 88},
      {9, 86},
      {8, 86},
      {7, 88},
      {6, 89},
      {7, 90},
      {8, 90},
      {9, 88},
    }
  },
  { 3, (GPoint []){
      {8, 80},
      {8, 81},
      {8, 80},
    }
  },
  { 16, (GPoint []){
      {17, 68},
      {17, 67},
      {18, 67},
      {20, 67},
      {19, 66},
      {18, 66},
      {19, 64},
      {20, 64},
      {20, 62},
      {17, 63},
      {16, 65},
      {15, 66},
      {16, 68},
      {16, 69},
      {17, 70},
      {17, 68},
    }
  },
  { 3, (GPoint []){
      {19, 60},
      {19, 61},
      {19, 60},
    }
  },
  { 5, (GPoint []){
      {32, 114},
      {32, 113},
      {33, 113},
      {33, 114},
      {32, 114},
    }
  },
  { 10, (GPoint []){
      {102, 112},
      {103, 111},
      {104, 111},
      {104, 110},
      {105, 105},
      {106, 105},
      {106, 107},
      {105, 109},
      {105, 111},
      {102, 112},
    }
  },
  { 4, (GPoint []){
      {28, 111},
      {28, 110},
      {29, 111},
      {28, 111},
    }
  },
  { 3, (GPoint []){
      {128, 106},
      {129, 105},
      {128, 106},
    }
  },
  { 6, (GPoint []){
      {107, 104},
      {107, 103},
      {108, 103},
      {108, 102},
      {109, 103},
      {107, 104},
    }
  },
  { 5, (GPoint []){
      {109, 100},
      {109, 99},
      {110, 100},
      {109, 101},
      {109, 100},
    }
  },
  { 5, (GPoint []){
      {92, 99},
      {93, 98},
      {93, 99},
      {92, 100},
      {92, 99},
    }
  },
  { 8, (GPoint []){
      {93, 97},
      {94, 97},
      {95, 96},
      {96, 95},
      {98, 94},
      {97, 96},
      {94, 98},
      {93, 97},
    }
  },
  { 3, (GPoint []){
      {81, 95},
      {82, 95},
      {81, 95},
    }
  },
  { 19, (GPoint []){
      {93, 94},
      {90, 94},
      {88, 93},
      {87, 91},
      {88, 88},
      {90, 87},
      {91, 86},
      {92, 83},
      {92, 81},
      {94, 81},
      {96, 81},
      {97, 88},
      {97, 89},
      {96, 91},
      {95, 91},
      {94, 92},
      {94, 93},
      {94, 94},
      {93, 94},
    }
  },
  { 3, (GPoint []){
      {111, 94},
      {110, 93},
      {111, 94},
    }
  },
  { 4, (GPoint []){
      {99, 94},
      {100, 93},
      {100, 94},
      {99, 94},
    }
  },
  { 5, (GPoint []){
      {82, 93},
      {82, 91},
      {82, 92},
      {82, 94},
      {82, 93},
    }
  },
  { 5, (GPoint []){
      {105, 93},
      {104, 92},
      {104, 91},
      {107, 93},
      {105, 93},
    }
  },
  { 5, (GPoint []){
      {108, 92},
      {108, 91},
      {109, 92},
      {109, 93},
      {108, 92},
    }
  },
  { 6, (GPoint []){
      {103, 89},
      {102, 88},
      {101, 88},
      {102, 87},
      {102, 86},
      {103, 89},
    }
  },
  { 7, (GPoint []){
      {105, 88},
      {103, 85},
      {103, 83},
      {105, 82},
      {106, 85},
      {106, 88},
      {105, 88},
    }
  },
  { 1, (GPoint []){
      {100, 86},
    }
  },
  { 4, (GPoint []){
      {111, 86},
      {112, 85},
      {112, 86},
      {111, 86},
    }
  },
  { 5, (GPoint []){
      {3, 85},
      {3, 82},
      {4, 84},
      {4, 85},
      {3, 85},
    }
  },
  { 4, (GPoint []){
      {101, 83},
      {103, 80},
      {102, 83},
      {101, 83},
    }
  },
  { 29, (GPoint []){
      {73, 82},
      {73, 81},
      {70, 78},
      {70, 79},
      {70, 80},
      {68, 80},
      {66, 80},
      {63, 76},
      {63, 74},
      {64, 72},
      {63, 71},
      {61, 69},
      {62, 68},
      {63, 69},
      {64, 70},
      {65, 70},
      {67, 70},
      {68, 69},
      {68, 67},
      {70, 64},
      {73, 64},
      {75, 65},
      {78, 67},
      {80, 69},
      {80, 71},
      {81, 74},
      {80, 78},
      {78, 81},
      {73, 82},
    }
  },
  { 5, (GPoint []){
      {5, 76},
      {6, 74},
      {7, 74},
      {7, 76},
      {5, 76},
    }
  },
  { 16, (GPoint []){
      {3, 74},
      {3, 72},
      {2, 71},
      {2, 65},
      {2, 63},
      {2, 61},
      {3, 60},
      {3, 61},
      {3, 63},
      {4, 66},
      {3, 69},
      {3, 70},
      {4, 72},
      {5, 73},
      {4, 73},
      {3, 74},
    }
  },
  { 4, (GPoint []){
      {5, 67},
      {5, 65},
      {6, 67},
      {5, 67},
    }
  },
  { 6, (GPoint []){
      {30, 66},
      {31, 63},
      {31, 64},
      {31, 65},
      {31, 67},
      {30, 66},
    }
  },
  { 4, (GPoint []){
      {1, 64},
      {1, 63},
      {2, 65},
      {1, 64},
    }
  },
  { 5, (GPoint []){
      {104, 64},
      {106, 62},
      {106, 63},
      {105, 64},
      {104, 64},
    }
  },
  { 7, (GPoint []){
      {8, 62},
      {8, 61},
      {9, 60},
      {10, 61},
      {10, 62},
      {9, 63},
      {8, 62},
    }
  },
  { 1, (GPoint []){
      {33, 63},
    }
  },
  { 7, (GPoint []){
      {31, 60},
      {31, 59},
      {31, 58},
      {32, 57},
      {32, 59},
      {31, 61},
      {31, 60},
    }
  },
  { 3, (GPoint []){
      {8, 59},
      {9, 60},
      {8, 59},
    }
  },
  { 6, (GPoint []){
      {91, 58},
      {92, 56},
      {94, 55},
      {96, 56},
      {94, 57},
      {91, 58},
    }
  },
  { 6, (GPoint []){
      {5, 56},
      {5, 51},
      {6, 49},
      {6, 52},
      {5, 55},
      {5, 56},
    }
  },
  { 8, (GPoint []){
      {21, 49},
      {21, 48},
      {21, 47},
      {22, 47},
      {23, 46},
      {23, 47},
      {22, 49},
      {21, 49},
    }
  },
  { 3, (GPoint []){
      {96, 29},
      {96, 30},
      {96, 29},
    }
  },
  { 4, (GPoint []){
      {86, 25},
      {87, 26},
      {86, 26},
      {86, 25},
    }
  },
  { 8, (GPoint []){
      {77, 17},
      {77, 16},
      {77, 14},
      {77, 12},
      {78, 12},
      {79, 14},
      {79, 17},
      {77, 17},
    }
  },
  { 5, (GPoint []){
      {74, 16},
      {75, 14},
      {76, 15},
      {76, 16},
      {74, 16},
    }
  },
  { 7, (GPoint []){
      {70, 10},
      {70, 9},
      {71, 8},
      {73, 8},
      {74, 9},
      {73, 10},
      {70, 10},
    }
  },
};
