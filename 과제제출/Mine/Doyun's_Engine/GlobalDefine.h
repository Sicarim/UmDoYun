#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstdlib>
#include <math.h>
#include <map>
#include <assert.h>
#include <functional>

using namespace std;

#define SAFE_DELETE( p ) { if( p ) { delete ( p ); ( p ) = NULL; } }
#define SAFE_DELETE_ARRAY( p ) { if( p ) { delete[] ( p ); ( p ) = NULL; } }
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }

#define ID_HINT                         40003
#define IDD_DIALOG1                     102
#define IDC_CHECK1                      1001
#define IDC_RADIO1                      1002
#define IDC_RADIO2                      1003
#define IDC_RADIO3                      1004
#define IDC_RADIO4                      1005
#define IDC_RADIO5                      1006
#define IDC_RADIO6                      1007
#define IDC_RADIO7                      1008
#define IDC_RADIO8                      1009