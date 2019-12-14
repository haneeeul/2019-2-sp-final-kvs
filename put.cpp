#include <map>
#include "string.h"
extern map< string, string >m;

int put (string key, string value) {
	if (m.find(key) != m.end()) { // 존재하는 key는 삭제
		m.erase(key);
	}
	m.insert(make_pair(key, value));
	return 0;
}
