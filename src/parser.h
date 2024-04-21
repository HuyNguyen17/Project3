#ifndef PROJECT3_PARSER_H
#define PROJECT3_PARSER_H

#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <cstdio>
#include <chrono>
#include "rapidjson/document.h"

class Parser
{
public:
    Parser();
    ~Parser();
    void parseGame(rapidjson::Value::ConstValueIterator mainIter, graph& gamesGraph);
    bool parseJSONFromFile(std::string filename, rapidjson::Document& d);
//    void parseJSONData(const std::string* filename);
    graph parseToGraph(std::string filename);
private:
    string timestampToDate(long long timestamp);
};
#endif //PROJECT3_PARSER_H
