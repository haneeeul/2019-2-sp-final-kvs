#include "string.h"
#include <map>
extern map< string, string > m;

string get (string key) {
	return m.find(key)->second;
}
