#ifndef _DATA_HANDLER_H
#define _DATA_HANDLER_H

//header for input and output operation
#include <fstream>
//header, which provides fixed-width integer types like uint8_t and uint32_t.
#include "stdint.h"
#include "data.hpp"

//Used for dynamic size arrays
#include <vector>
//for handling strings
#include <string>
//Contents of the map: Key: 1, Value: One Key: 2, Value: Two Key: 3, Value: Three Key: 4, Value: Four
#include <map>
#include <unordered_set>




class data_handler 
{
    //These are pointers to vectors of data * objects
    std::vector<data *> *data_array;
    std::vector<data *> *training_data;
    std::vector<data *> *test_data;
    std::vector<data *> *validation_data;

    int num_classes;
    int feature_vector_size;
    //Maps class labels (uint8_t) to integers, likely for counting or indexing purposes.
    std::map<uint8_t, int> class_map;

    const double TRAIN_SET_PERCENT = 0.75;
    const double TEST_SET_PERCENT = 0.2;
    const double VALIDATION_PERCENT = 0.05;

    public:
    //initialization
    data_handler();
    //cleaning up the resources.
    ~data_handler();

    //Reads feature vectors from a file specified by path.
    void read_feature_vector(std::string path);
    //Reads feature labels from a file specified by path.
    void read_feature_labels(std::string path);
    //Splits the dataset into training, testing, and validation subsets based on the defined proportions.
    void split_data();
    //Counts the unique classes in the dataset and updates num_classes and class_map.
    void count_classes();

    uint32_t convert_to_little_endian(const unsigned char* bytes);

    //Returning a pointer in this case means that the function does not return a copy of the 
    //vector but instead returns a direct reference to the memory where the training_data 
    //vector resides. This has the following implications:

    std::vector<data *> * get_training_data();
    std::vector<data *> * get_test_data();
    std::vector<data *> * get_validation_data();









};


#endif
