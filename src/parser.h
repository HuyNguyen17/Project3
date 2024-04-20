#ifndef PROJECT3_PARSER_H
#define PROJECT3_PARSER_H

void parseGame(rapidjson::Value::ConstValueIterator mainIter);
bool parseJSONFromFile(const string& filename, rapidjson::Document& d);
void parseJSONData(const std::string& filename);

string timestampToDate(long long timestamp);
#endif //PROJECT3_PARSER_H
