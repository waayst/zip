#pragma once
/*
Helpful methods happend to be only memory manage function.
Not RAII just for exersize.
*/

template <typename T>
void safeDelete(T* &ptr) {
	if (ptr != nullptr) {
		delete ptr;
		ptr = nullptr;
	}
}