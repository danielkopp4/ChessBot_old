#include <string>
#include <sstream>
#include <iostream>

#ifndef __location_hpp__
#define __location_hpp__

class Location {
public:
    Location() : rank_(-1), file_(-1) {}
    Location(int rank, int file) : rank_(rank), file_(file) {}
    
    int rank() const { return rank_; }
    int file() const { return file_; }
    std::string string() const { 
        std::stringstream ss;
        char start_file = 'a';
        ss << char(start_file + file_) << (rank_+1);
        return ss.str();
    }

    bool out_of_bounds(int bound) const {
        return (rank_ < 0 or rank_ >= bound) or (file_ < 0 or file_ >= bound);
    }

    bool operator==(const Location& other) const {
        return rank_ == other.rank_ and file_ == other.file_;
    }


    void set_rank(int rank) { rank_ = rank; }
    void set_file(int file) { file_ = file; }
private:
    int rank_;
    int file_;
};

#endif