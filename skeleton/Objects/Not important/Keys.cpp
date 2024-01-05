#include "Keys.h"

Keys::Keys() : map() {

}

void Keys::add(char key, std::function<void(void)> func) {
	auto it = map.find(key);
	if(it != map.end()) {
		it->second.push_back(func);
	} else {
		map.insert(std::pair<char, std::vector<std::function<void(void)>>>(key, std::vector<std::function<void(void)>>(1, func)));
	}
}

void Keys::remove(char key) {
	map.erase(key);
}

void Keys::keyPressed(unsigned char key) {
	auto it = map.find(key);
	if(it != map.end()) {
		for(auto& func : it->second) {
			func();
		}
	}
}
