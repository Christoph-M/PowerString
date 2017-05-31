#include "PowerString.h"


namespace Power {
	String::String() :
		size_(256),
		length_(0),
		data_(new char[size_] { '\0' }),
		temp_(new char[size_] { '\0' })
	{
		this->IncInstCounter();
	}
	
	String::String(size_t size) :
		size_(size + 1),
		length_(0),
		data_(new char[size_] { '\0' }),
		temp_(new char[size_] { '\0' })
	{
		this->IncInstCounter();
	}

	String::String(const char* const data) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		length_ = strlen(data);
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, data, length_);
	}

	String::String(const char c) :
		size_(256),
		length_(255),
		data_(new char[size_] { '\0' }),
		temp_(new char[size_] { '\0' })
	{
		this->IncInstCounter();
		memset(data_, c, length_);
	}
	
	String::String(const char* const data, size_t size) :
		size_(size + 256),
		length_(size),
		data_(new char[size_] { '\0' }),
		temp_(new char[size_] { '\0' })
	{
		this->IncInstCounter();
		memcpy(data_, data, length_);
	}

	String::String(const char c, size_t size) :
		size_(size + 1),	// Why only + 1? -> To fill the new string with size amount of c
		length_(size),
		data_(new char[size_] { '\0' }),
		temp_(new char[size_] { '\0' })
	{
		this->IncInstCounter();
		memset(data_, c, length_);
	}

	String::String(const String& other) :
		size_(other.size_),
		length_(other.length_),
		data_(new char[other.size_] { '\0' }),
		temp_(new char[other.size_] { '\0' })
	{
		this->IncInstCounter();
		memcpy(data_, other.data_, other.length_);
	}

	String::String(const String& lhs, const String& rhs) :
		size_(lhs.length_ + rhs.length_ + 256),
		length_(lhs.length_ + rhs.length_),
		data_(new char[size_] { '\0' }),
		temp_(new char[size_] { '\0' })
	{
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, rhs.data_, rhs.length_);
	}

	String::String(const String& lhs, const char* const rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		size_t rhsLength = strlen(rhs);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, rhs, rhsLength);
	}

	String::String(const String& lhs, const char rhs) :
		size_(lhs.length_ + 257),
		length_(lhs.length_ + 1),
		data_(new char[size_] { '\0' }),
		temp_(new char[size_] { '\0' })
	{
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		data_[lhs.length_] = rhs;
	}

	String::String(const String& lhs, const int16_t rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		char buffer[INT16_MAX_CHR_COUNT];
		snprintf(buffer, INT16_MAX_CHR_COUNT, "%hd", rhs);
		size_t rhsLength = strlen(buffer);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
	}

	String::String(const String& lhs, const uint16_t rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		char buffer[UINT16_MAX_CHR_COUNT];
		snprintf(buffer, UINT16_MAX_CHR_COUNT, "%hu", rhs);
		size_t rhsLength = strlen(buffer);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
	}

	String::String(const int32_t rhs, const String& lhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		char buffer[INT32_MAX_CHR_COUNT];
		snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", rhs);
		size_t rhsLength = strlen(buffer);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
	}

	String::String(const String& lhs, const uint32_t rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		char buffer[UINT32_MAX_CHR_COUNT];
		snprintf(buffer, UINT32_MAX_CHR_COUNT, "%u", rhs);
		size_t rhsLength = strlen(buffer);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
	}

	String::String(const String& lhs, const int64_t rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		char buffer[INT64_MAX_CHR_COUNT];
		snprintf(buffer, INT64_MAX_CHR_COUNT, "%lld", rhs);
		size_t rhsLength = strlen(buffer);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
	}

	String::String(const String& lhs, const uint64_t rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		char buffer[UINT64_MAX_CHR_COUNT];
		snprintf(buffer, UINT64_MAX_CHR_COUNT, "%llu", rhs);
		size_t rhsLength = strlen(buffer);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
	}

	String::String(const String& lhs, const float rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		char buffer[FLOAT_MAX_CHR_COUNT];
		snprintf(buffer, FLOAT_MAX_CHR_COUNT, "%g", rhs);
		size_t rhsLength = strlen(buffer);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
	}

	String::String(const String& lhs, const double rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		char buffer[DOUBLE_MAX_CHR_COUNT];
		snprintf(buffer, DOUBLE_MAX_CHR_COUNT, "%g", rhs);
		size_t rhsLength = strlen(buffer);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 256;
		data_ = new char[size_] { '\0' };
		temp_ = new char[size_] { '\0' };
		this->IncInstCounter();
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
	}

	
	int String::IndexOf(const String& other, size_t begin, size_t end) const {
		if (begin >= length_ || end >= length_ || other.length_ > length_) return -1;
		for (size_t i = begin; i < end; ++i) {
			if (data_[i] != other.data_[0]) continue;
			if (memcmp(data_ + i, other.data_, other.length_) == 0) return i;
		}

		return -1;
	}

	int String::IndexOf(const char* const other, size_t begin, size_t end) const {
		if (begin >= length_ || end >= length_) return -1;
		const size_t otherLength = strlen(other);
		if (otherLength > length_) return -1;
		for (size_t i = begin; i < end; ++i) {
			if (data_[i] != other[0]) continue;
			if (memcmp(data_ + i, other, otherLength) == 0) return i;
		}

		return -1;
	}

	int String::IndexOf(size_t length, const char* const other, size_t begin, size_t end) const {
		if (begin >= length_ || end >= length_) return -1;
		if (length > length_) return -1;
		for (size_t i = begin; i < end; ++i) {
			if (data_[i] != other[0]) continue;
			if (memcmp(data_ + i, other, length) == 0) return i;
		}

		return -1;
	}

	int String::LastIndexOf(const String& other, size_t begin, size_t end) const {
		if (begin >= length_ || end >= length_ || other.length_ > length_) return -1;
		for (int i = end; i >= static_cast<int>(begin); --i) {
			if (data_[i] != other.data_[other.length_ - 1]) continue;
			int x = i - other.length_ + 1;
			if (x < 0) return -1;
			if (memcmp(data_ + x, other.data_, other.length_) == 0) return x;
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
			if (memcmp(data_ + x, other, otherLength) == 0) return x;
		}

		return -1;
	}

	int String::LastIndexOf(size_t length, const char* const other, size_t begin, size_t end) const {
		if (begin >= length_ || end >= length_) return -1;
		if (length > length_) return -1;
		for (int i = end; i >= static_cast<int>(begin); --i) {
			if (data_[i] != other[length - 1]) continue;
			int x = i - length + 1;
			if (x < 0) return -1;
			if (memcmp(data_ + x, other, length) == 0) return x;
		}

		return -1;
	}

	void String::Insert(size_t index, const String& other) {
		if (index > length_) return;
		size_t newLength = length_ + other.length_;
		this->CheckSizeAndReallocate(newLength);
		temp_[newLength] = '\0';
		memcpy(temp_ + index, other.data_, other.length_);
		memcpy(temp_ + index + other.length_, data_ + index, length_ - index);
		length_ = newLength;
		memcpy(data_ + index, temp_ + index, newLength - index + 1);
	}

	void String::Insert(size_t index, const char* const other) {
		if (index > length_) return;
		size_t otherLength = strlen(other);
		size_t newLength = length_ + otherLength;
		this->CheckSizeAndReallocate(newLength);
		temp_[newLength] = '\0';
		memcpy(temp_ + index, other, otherLength);
		memcpy(temp_ + index + otherLength, data_ + index, length_ - index);
		length_ = newLength;
		memcpy(data_ + index, temp_ + index, newLength - index + 1);
	}

	void String::Insert(size_t index, const char* const other, size_t length) {
		if (index > length_) return;
		size_t newLength = length_ + length;
		this->CheckSizeAndReallocate(newLength);
		temp_[newLength] = '\0';
		memcpy(temp_ + index, other, length);
		memcpy(temp_ + index + length, data_ + index, length_ - index);
		length_ = newLength;
		memcpy(data_ + index, temp_ + index, newLength - index + 1);
	}

	void String::Insert(size_t index, const char c) {
		if (index > length_) return;
		size_t newLength = length_ + 1;
		this->CheckSizeAndReallocate(newLength);
		temp_[newLength] = '\0';
		temp_[index] = c;
		memcpy(temp_ + index + 1, data_ + index, length_ - index);
		length_ = newLength;
		memcpy(data_ + index, temp_ + index, newLength - index + 1);
	}

	void String::Remove(size_t index, size_t count) {
		if (index >= length_) return;
		if (count > length_ - index) count = length_ - index;
		size_t newLength = length_ - count;
		temp_[newLength] = '\0';
		memcpy(temp_, data_, index);
		memcpy(temp_ + index, data_ + index + count, index - count);
		length_ = newLength;
		memcpy(data_, temp_, newLength + 1);
	}

	void String::RemoveAll(const String& other) {
		int index = 0;
		int nextIndex = this->IndexOf(other.data_);
		size_t i = 0;
		char* temp = temp_;
		while (nextIndex >= 0) {
			memcpy(temp, data_ + index, nextIndex - index);
			temp += nextIndex - index;
			index = nextIndex + other.length_;
			nextIndex = this->IndexOf(other.data_, index);
			++i;
		}
		memcpy(temp, data_ + index, length_ - index);
		size_t newLength = length_ - i * other.length_;
		temp_[newLength] = '\0';
		length_ = newLength;
		memcpy(data_, temp_, newLength + 1);
	}

	void String::RemoveAll(const char* const other) {
		size_t otherLength = strlen(other);
		int index = 0;
		int nextIndex = this->IndexOf(other);
		size_t i = 0;
		char* temp = temp_;
		while (nextIndex >= 0) {
			memcpy(temp, data_ + index, nextIndex - index);
			temp += nextIndex - index;
			index = nextIndex + otherLength;
			nextIndex = this->IndexOf(other, index);
			++i;
		}
		memcpy(temp, data_ + index, length_ - index);
		size_t newLength = length_ - i * otherLength;
		temp_[newLength] = '\0';
		length_ = newLength;
		memcpy(data_, temp_, newLength + 1);
	}

	void String::RemoveAll(const char* const other, size_t length) {
		int index = 0;
		int nextIndex = this->IndexOf(other);
		size_t i = 0;
		char* temp = temp_;
		while (nextIndex >= 0) {
			memcpy(temp, data_ + index, nextIndex - index);
			temp += nextIndex - index;
			index = nextIndex + length;
			nextIndex = this->IndexOf(other, index);
			++i;
		}
		memcpy(temp, data_ + index, length_ - index);
		size_t newLength = length_ - i * length;
		temp_[newLength] = '\0';
		length_ = newLength;
		memcpy(data_, temp_, newLength + 1);
	}

	void String::RemoveAll(const char c) {
		size_t count = 0;
		for (size_t i = 0; i < length_; ++i) if (data_[i] == c) ++count;
		if (count == 0) return;
		size_t newLength = length_ - count;
		temp_[newLength] = '\0';
		count = 0;
		for (size_t i = 0; i < length_; ++i) {
			if (data_[i] == c) continue;
			temp_[count] = data_[i];
			++count;
		}
		length_ = newLength;
		memcpy(data_, temp_, newLength + 1);
	}
	
	void String::Replace(size_t index, size_t count, const String& other) {
		if (index >= length_) return;
		if (count > length_ - index) count = length_ - index;
		size_t newLength = length_ - count + other.length_;
		this->CheckSizeAndReallocate(newLength);
		temp_[newLength] = '\0';
		memcpy(temp_ + index, other.data_, other.length_);
		memcpy(temp_ + index + other.length_, data_ + index + count, length_ - index - count);
		length_ = newLength;
		memcpy(data_ + index, temp_ + index, newLength - index + 1);
	}

	void String::Replace(size_t index, size_t count, const char* const other) {
		if (index >= length_) return;
		if (count > length_ - index) count = length_ - index;
		size_t otherLength = strlen(other);
		size_t newLength = length_ - count + otherLength;
		this->CheckSizeAndReallocate(newLength);
		temp_[newLength] = '\0';
		memcpy(temp_ + index, other, otherLength);
		memcpy(temp_ + index + otherLength, data_ + index + count, length_ - index - count);
		length_ = newLength;
		memcpy(data_ + index, temp_ + index, newLength - index + 1);
	}

	void String::Replace(size_t index, size_t count, const char* const other, size_t length) {
		if (index >= length_) return;
		if (count > length_ - index) count = length_ - index;
		size_t newLength = length_ - count + length;
		this->CheckSizeAndReallocate(newLength);
		temp_[newLength] = '\0';
		memcpy(temp_ + index, other, length);
		memcpy(temp_ + index + length, data_ + index + count, length_ - index - count);
		length_ = newLength;
		memcpy(data_ + index, temp_ + index, newLength - index + 1);
	}

	void String::Replace(size_t index, size_t count, const char c) {
		if (index >= length_) return;
		if (count > length_ - index) count = length_ - index;
		size_t newLength = length_ - count + 1;
		this->CheckSizeAndReallocate(newLength);
		temp_[newLength] = '\0';
		temp_[index] = c;
		memcpy(temp_ + index + 1, data_ + index + count, length_ - index - count);
		length_ = newLength;
		memcpy(data_ + index, temp_ + index, newLength - index + 1);
	}

	String::~String() {
		delete[](data_);
		delete[](temp_);
		--s_instanceCounter_;
	}

	size_t String::s_instanceCounter_ = 0;
	size_t String::s_totalInstancesCreated_ = 0;
}
