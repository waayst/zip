#pragma once
template <typename T>
void safeDelete(T* &ptr) {
	if (ptr != nullptr) {
		delete ptr;
		ptr = nullptr;
	}
}