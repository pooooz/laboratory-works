#define _CRT_SECURE_NO_WARNINGS
#include "file_reader.h"
#include "constants.h"
#include <iostream>

#include <fstream>
#include <cstring>

Date convert(char* str) {
    Date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

int get_age(int day, int month, int year) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int age;

    age = (ltm->tm_year + 1900) - year;
    if (month > ltm->tm_mon + 1)
        age--;
    else if ((month == ltm->tm_mon + 1) && (day > ltm->tm_mday))
        age--;

    return age;
}

void read(const char* file_name, Employee* array[], int& size) {
    std::ifstream file(file_name);
    if (file.is_open()) {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        
        while (!file.eof()) {
            Employee* item = new Employee;
            file >> item->last_name;
            file >> item->first_name;
            file >> item->middle_name;
            file >> item->gender;
            if (strcmp(item->gender, "мужской") != 0 && strcmp(item->gender, "женский") != 0) {
                throw std::invalid_argument("Некорректно указан пол работника!");
            }
            file >> tmp_buffer;
            int dots_counter = 0;
            for (int i = 0; i < sizeof(tmp_buffer) / sizeof(char); i++) {
                if (tmp_buffer[i] == '.') {
                    dots_counter++;
                }
            }
            if (dots_counter != 2) {
                throw std::invalid_argument("Некорректно указана дата рождения работника");
            }
            item->birthdate = convert(tmp_buffer);
            item->age = get_age(item->birthdate.day, item->birthdate.month, item->birthdate.year);
            file >> item->work_experience;

            file.read(tmp_buffer, 1);
            file.getline(item->speciality, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();  
    }
    else {
        throw std::invalid_argument("Ошибка открытия файла");
    }
}