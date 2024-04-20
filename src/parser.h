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
    static void parseGame(rapidjson::Value::ConstValueIterator mainIter, graph& gamesGraph);
    static bool parseJSONFromFile(const string& filename, rapidjson::Document& d);
    void parseJSONData(const std::string& filename, graph &g);
    static graph parseToGraph(const std::string& filename);
private:
    static string timestampToDate(long long timestamp);
};
#endif //PROJECT3_PARSER_H
