#include <csv2/reader.hpp>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    csv2::Reader<csv2::delimiter<','>, 
               csv2::quote_character<'"'>, 
               csv2::first_row_is_header<true>,
               csv2::trim_policy::trim_whitespace> csv;
    
    std::string csvContents;
    csvContents.assign(data, data + size);
    if(csv.parse(csvContents)){
        for(const auto row: csv){
            for(const auto cell: row){
                std::string cellVal;
                cell.read_value(cellVal);
            }
        }
    }

    return 0;
}
