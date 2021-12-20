/*
 libagchess, a chess library in C++.
 Copyright (C) 2010-2011 Austen Green.
 
 libagchess is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 libagchess is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with libagchess.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef PGNDATABASE_H
#define PGNDATABASE_H

#include <fstream>
#include <string>
#include <vector>

#include "TagPair.h"
#include "StandardChessGame.h"


namespace AGChess {

    using namespace std;

    class PGNDatabase {
        
    public:
        PGNDatabase(const char* file);
        PGNDatabase(const std::string& file);
        ~PGNDatabase();
        
        int numberOfGames() const;
        StandardChessGame getGame(int index) const;
        GameHeaders headers(int index) const;
        string getGameText(int index) const;
        
    protected:
        mutable ifstream database;
        vector<unsigned long> gameIndexes;
        unsigned long numGames;
        
        void initializeGameIndexes();
        bool isstartempty(char c);
        void initWithFile(const char* file);
        
    };
    
}

#endif
