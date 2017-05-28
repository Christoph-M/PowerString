#include "String.h"


namespace Power {
	String::String(const char* const data) :
		length_(0),
		data_(nullptr)
	{
		length_ = strlen(data);
		data_ = new char[length_ + 1] { '\0' };
		this->IncInstCounter();
		memcpy(data_, data, length_);
	}

	String::String(const char* const data, size_t size) :
		length_(size - 1),
		data_(new char[size] { '\0' })
	{
		this->IncInstCounter();
		memcpy(data_, data, length_);
	}

	String::String(const String& other) :
		length_(other.length_),
		data_(new char[other.length_ + 1] { '\0' })
	{
		this->IncInstCounter();
		memcpy(data_, other.data_, other.length_);
	}

	
	int String::IndexOf(const String& other, size_t begin, size_t end) const {
		if (begin >= length_ || end >= length_ || other.length_ > length_) return -1;
		for (size_t i = begin; i < end; ++i) {
			if (data_[i] != other.data_[0]) continue;
			bool b = true;
			for (size_t f = 0; f < other.length_; ++f)
				if (data_[i + f] != other.data_[f]) {
					b = false;
					break;
				}
			if (b) return i;
		}

		return -1;
	}

	int String::IndexOf(const char* const other, size_t begin, size_t end) const {
		if (begin >= length_ || end >= length_) return -1;
		const size_t otherLength = strlen(other);
		if (otherLength > length_) return -1;
		for (size_t i = begin; i < end; ++i) {
			if (data_[i] != other[0]) continue;
			bool b = true;
			for (size_t f = 0; f < otherLength; ++f)
				if (data_[i + f] != other[f]) {
					b = false;
					break;
				}
			if (b) return i;
		}

		return -1;
	}

	int String::LastIndexOf(const String& other, size_t begin, size_t end) const {
		if (begin >= length_ || end >= length_ || other.length_ > length_) return -1;
		for (int i = end; i >= static_cast<int>(begin); --i) {
			if (data_[i] != other.data_[other.length_ - 1]) continue;
			int x = i - other.length_ + 1;
			if (x < 0) return -1;
			bool b = true;
			for (int f = other.length_ - 1; f >= 0; --f)
				if (data_[x + f] != other.data_[f]) {
					b = false;
					break;
				}
			if (b) return x;
		}

		return -1;
	}

	int String::LastIndexOf(const char* const other, size_t begin, size_t end) const {
		if (begin >= length_ || end >= length_) return -1;
		const size_t otherLength = strlen(other);
		if (otherLength > length_) return -1;
		for (int i = end; i >= static_cast<int>(begin); --i) {
			if (data_[i] != other[otherLength - 1]) continue;
			int x = i - otherLength + 1;
			if (x < 0) return -1;
			bool b = true;
			for (int f = otherLength - 1; f >= 0; --f)
				if (data_[x + f] != other[f]) {
					b = false;
					break;
				}
			if (b) return x;
		}

		return -1;
	}

	String String::Insert(size_t index, const String& other) const {
		if (index >= length_) index = length_ - 1;
		String newString = String("", length_ + other.length_ + 1);
		if (index == 0) {
			memcpy(newString.data_, other.data_, other.length_);
			memcpy(newString.data_ + other.length_, data_, length_);
		} else if (index == length_ - 1) {
			memcpy(newString.data_, data_, length_);
			memcpy(newString.data_ + length_, other.data_, other.length_);
		} else {
			memcpy(newString.data_, data_, index);
			memcpy(newString.data_ + index, other.data_, other.length_);
			memcpy(newString.data_ + index + other.length_, data_ + index, length_ - index);
		}
		return newString;
	}

	String String::Insert(size_t index, const char* const other) const {
		if (index >= length_) index = length_ - 1;
		size_t otherLength = strlen(other);
		String newString = String("", length_ + otherLength + 1);
		if (index == 0) {
			memcpy(newString.data_, other, otherLength);
			memcpy(newString.data_ + otherLength, data_, length_);
		} else if (index == length_ - 1) {
			memcpy(newString.data_, data_, length_);
			memcpy(newString.data_ + length_, other, otherLength);
		} else {
			memcpy(newString.data_, data_, index);
			memcpy(newString.data_ + index, other, otherLength);
			memcpy(newString.data_ + index + otherLength, data_ + index, length_ - index);
		}
		return newString;
	}

	String String::Remove(size_t index, size_t count) const {
		if (index >= length_) index = length_ - 1;
		if (count > length_ - index) count = length_ - index;
		String newString = String("", length_ - count + 1);
		if (index == 0) {
			memcpy(newString.data_, data_ + count, newString.length_);
		} else if (index == length_ - 1) {
			memcpy(newString.data_, data_, index);
		} else {
			memcpy(newString.data_, data_, index);
			memcpy(newString.data_ + index, data_ + index + count, index - count);
		}
		return newString;
	}

	String String::RemoveAll(const char c) const {
		size_t count = 0;
		for (size_t i = 0; i < length_; ++i) if (data_[i] == c) ++count;
		if (count == 0) return *this;
		String newString = String("", length_ - count + 1);
		count = 0;
		for (size_t i = 0; i < length_ - 1; ++i) {
			if (data_[i] == c) continue;
			newString.data_[count] = data_[i];
			++count;
		}
		return newString;
	}

	
	String::~String() {
		delete[](data_);
		--s_instanceCounter_;
	}

	size_t String::s_instanceCounter_ = 0;
	size_t String::s_totalInstancesCreated_ = 0;
}