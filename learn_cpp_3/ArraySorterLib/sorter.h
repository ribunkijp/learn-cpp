#ifndef SORTER_H
#define SORTER_H

#ifdef ARRAYSORTLIB_EXPORTS
#define ARRAYSORT_API __declspec(dllexport)
#else
#define ARRAYSORT_API __declspec(dllimport)
#endif






extern "C" ARRAYSORT_API void sort_array_ascending(int* arr, int size);





#endif