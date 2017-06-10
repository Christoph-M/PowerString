#include "PowerString.h"


namespace Power {
	String::String() :
		size_(s_defaultCapacity),
		length_(0),
		data_(static_cast<char*>(malloc(size_ * 2))),
		temp_(data_ + size_)
	{
		*data_ = '\0';
		this->IncInstCounter();
	}
	String::String(size_t size) :
		size_(size + 1),
		length_(0),
		data_(static_cast<char*>(malloc(size_ * 2))),
		temp_(data_ + size_)
	{
		*data_ = '\0';
		this->IncInstCounter();
	}
	String::String(const char* const data) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		length_ = strlen(data);
		size_ = length_ + s_defaultCapacity;
		data_ = static_cast<char*>(malloc(size_ * 2));
		this->IncInstCounter();
		temp_ = data_ + size_;
		memcpy(data_, data, length_);
		data_[length_] = '\0';
	}
	String::String(const char c) :
		size_(s_defaultCapacity),
		length_(1),
		data_(static_cast<char*>(malloc(size_ * 2))),
		temp_(data_ + size_)
	{
		*data_ = c;
		data_[1] = '\0';
		this->IncInstCounter();
	}	
	String::String(const char* const data, size_t length) :
		size_(length + s_defaultCapacity),
		length_(length),
		data_(static_cast<char*>(malloc(size_ * 2))),
		temp_(data_ + size_)
	{
		memcpy(data_, data, length_);
		data_[length_] = '\0';
		this->IncInstCounter();
	}
	String::String(const char c, size_t length) :
		size_(length + s_defaultCapacity),
		length_(length),
		data_(static_cast<char*>(malloc(size_ * 2))),
		temp_(data_ + size_)
	{
		memset(data_, c, length_);
		data_[length_] = '\0';
		this->IncInstCounter();
	}
	String::String(const String& other) :
		size_(other.size_),
		length_(other.length_),
		data_(static_cast<char*>(malloc(size_ * 2))),
		temp_(data_ + size_)
	{
		memcpy(data_, other.data_, other.length_);
		data_[length_] = '\0';
		this->IncInstCounter();
	}
	String::String(const String& lhs, const String& rhs) :
		size_(lhs.length_ + rhs.length_ + 1),
		length_(lhs.length_ + rhs.length_),
		data_(static_cast<char*>(malloc(size_ * 2))),
		temp_(data_ + size_)
	{
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, rhs.data_, rhs.length_);
		data_[length_] = '\0';
		this->IncInstCounter();
	}
	String::String(const String& lhs, const char* const rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		size_t rhsLength = strlen(rhs);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 1;
		data_ = static_cast<char*>(malloc(size_ * 2));
		this->IncInstCounter();
		temp_ = data_ + size_;
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, rhs, rhsLength);
		data_[length_] = '\0';
	}
	String::String(const String& lhs, const char rhs) :
		size_(lhs.length_ + 2),
		length_(lhs.length_ + 1),
		data_(static_cast<char*>(malloc(size_ * 2))),
		temp_(data_ + size_)
	{
		memcpy(data_, lhs.data_, lhs.length_);
		data_[lhs.length_] = rhs;
		data_[length_] = '\0';
		this->IncInstCounter();
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
		size_ = length_ + 1;
		data_ = static_cast<char*>(malloc(size_ * 2));
		temp_ = data_ + size_;
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
		data_[length_] = '\0';
		this->IncInstCounter();
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
		size_ = length_ + 1;
		data_ = static_cast<char*>(malloc(size_ * 2));
		temp_ = data_ + size_;
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
		data_[length_] = '\0';
		this->IncInstCounter();
	}
	String::String(const String& lhs, const int32_t rhs) :
		size_(0),
		length_(0),
		data_(nullptr),
		temp_(nullptr)
	{
		char buffer[INT32_MAX_CHR_COUNT];
		snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", rhs);
		size_t rhsLength = strlen(buffer);
		length_ = lhs.length_ + rhsLength;
		size_ = length_ + 1;
		data_ = static_cast<char*>(malloc(size_ * 2));
		temp_ = data_ + size_;
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
		data_[length_] = '\0';
		this->IncInstCounter();
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
		size_ = length_ + 1;
		data_ = static_cast<char*>(malloc(size_ * 2));
		temp_ = data_ + size_;
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
		data_[length_] = '\0';
		this->IncInstCounter();
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
		size_ = length_ + 1;
		data_ = static_cast<char*>(malloc(size_ * 2));
		temp_ = data_ + size_;
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
		data_[length_] = '\0';
		this->IncInstCounter();
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
		size_ = length_ + 1;
		data_ = static_cast<char*>(malloc(size_ * 2));
		temp_ = data_ + size_;
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
		data_[length_] = '\0';
		this->IncInstCounter();
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
		size_ = length_ + 1;
		data_ = static_cast<char*>(malloc(size_ * 2));
		temp_ = data_ + size_;
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
		data_[length_] = '\0';
		this->IncInstCounter();
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
		size_ = length_ + 1;
		data_ = static_cast<char*>(malloc(size_ * 2));
		temp_ = data_ + size_;
		memcpy(data_, lhs.data_, lhs.length_);
		memcpy(data_ + lhs.length_, buffer, rhsLength);
		data_[length_] = '\0';
		this->IncInstCounter();
	}

	
	int String::IndexOf(const String& other, size_t begin, size_t end) const {
		if (begin >= length_ || end > length_ || begin > end || other.length_ > length_) return -1;
		for (size_t i = begin; i < end - other.length_ + 1; ++i) {
			if (memcmp(data_ + i, other.data_, other.length_) == 0) return static_cast<int>(i);
		}
		return -1;
	}
	int String::IndexOf(size_t length, const char* const other, size_t begin, size_t end) const {
		if (begin >= length_ || end > length_ || begin > end || length > length_) return -1;
		for (size_t i = begin; i < end - length + 1; ++i) {
			if (memcmp(data_ + i, other, length) == 0) return static_cast<int>(i);
		}
		return -1;
	}

	int String::LastIndexOf(const String& other, size_t begin, size_t end) const {
		if (begin >= length_ || end > length_ || other.length_ > length_) return -1;
		for (int i = static_cast<int>(end); i >= static_cast<int>(begin) + static_cast<int>(other.length_) - 1; --i) {
			if (data_[i] != other.data_[other.length_ - 1]) continue;
			int x = i - static_cast<int>(other.length_) + 1;
			if (x < 0) return -1;
			if (memcmp(data_ + x, other.data_, other.length_) == 0) return static_cast<int>(x);
		}
		return -1;
	}
	int String::LastIndexOf(size_t length, const char* const other, size_t begin, size_t end) const {
		if (begin >= length_ || end > length_ || length > length_) return -1;
		for (int i = static_cast<int>(end); i >= static_cast<int>(begin) + static_cast<int>(begin) - 1; --i) {
			if (data_[i] != other[length - 1]) continue;
			int x = i - static_cast<int>(length) + 1;
			if (x < 0) return -1;
			if (memcmp(data_ + x, other, length) == 0) return static_cast<int>(x);
		}
		return -1;
	}

	void String::Insert(size_t index, const String& other) {
		if (index > length_) return;
		size_t newLength = length_ + other.length_;
		this->CheckSizeAndReallocate(newLength);
		memcpy(temp_, other.data_, other.length_);
		memcpy(temp_ + other.length_, data_ + index, length_ - index);
		memcpy(data_ + index, temp_, newLength - index);
		this->SetNewLength(newLength);
	}
	void String::Insert(size_t index, const char* const other, size_t length) {
		if (index > length_) return;
		size_t newLength = length_ + length;
		this->CheckSizeAndReallocate(newLength);
		memcpy(temp_, other, length);
		memcpy(temp_ + length, data_ + index, length_ - index);
		memcpy(data_ + index, temp_, newLength - index);
		this->SetNewLength(newLength);
	}
	void String::Insert(size_t index, const char c) {
		if (index > length_) return;
		size_t newLength = length_ + 1;
		this->CheckSizeAndReallocate(newLength);
		temp_[index] = c;
		memcpy(temp_ + 1, data_ + index, length_ - index);
		memcpy(data_ + index, temp_, newLength - index);
		this->SetNewLength(newLength);
	}

	void String::Remove(size_t index, size_t count) {
		if (index >= length_) return;
		if (count > length_ - index) count = length_ - index;
		memcpy(temp_, data_, index);
		memcpy(temp_ + index, data_ + index + count, index - count);
		length_ = length_ - count;
		memcpy(data_, temp_, length_);
		data_[length_] = '\0';
	}

	void String::RemoveAll(const String& other) {
		int index = 0;
		int nextIndex = static_cast<int>(this->IndexOf(other.data_));
		if (nextIndex < 0) return;
		size_t i = 0;
		char* temp = temp_;
		while (nextIndex >= 0) {
			memcpy(temp, data_ + index, nextIndex - index);
			temp += nextIndex - index;
			index = nextIndex + static_cast<int>(other.length_);
			nextIndex = static_cast<int>(this->IndexOf(other.data_, index));
			++i;
		}
		memcpy(temp, data_ + index, length_ - index);
		length_ = length_ - i * other.length_;
		memcpy(data_, temp_, length_);
		data_[length_] = '\0';
	}
	void String::RemoveAll(const char* const other, size_t length) {
		int index = 0;
		int nextIndex = static_cast<int>(this->IndexOf(other));
		if (nextIndex < 0) return;
		size_t i = 0;
		char* temp = temp_;
		while (nextIndex >= 0) {
			memcpy(temp, data_ + index, nextIndex - index);
			temp += nextIndex - index;
			index = nextIndex + static_cast<int>(length);
			nextIndex = static_cast<int>(this->IndexOf(other, index));
			++i;
		}
		memcpy(temp, data_ + index, length_ - index);
		length_ = length_ - i * length;
		memcpy(data_, temp_, length_);
		data_[length_] = '\0';
	}
	void String::RemoveAll(const char c) {
		size_t count = 0;
		for (size_t i = 0; i < length_; ++i) if (data_[i] == c) ++count;
		if (count == 0) return;
		size_t newLength = length_ - count;
		count = 0;
		for (size_t i = 0; i < length_; ++i) {
			if (data_[i] == c) continue;
			temp_[count] = data_[i];
			++count;
		}
		memcpy(data_, temp_, newLength);
		this->SetNewLength(newLength);
	}
	
	void String::Replace(size_t index, size_t count, const String& other) {
		if (index >= length_) return;
		if (count > length_ - index) count = length_ - index;
		size_t newLength = length_ - count + other.length_;
		this->CheckSizeAndReallocate(newLength);
		memcpy(temp_, other.data_, other.length_);
		memcpy(temp_ + other.length_, data_ + index + count, length_ - index - count);
		memcpy(data_ + index, temp_, newLength - index);
		this->SetNewLength(newLength);
	}
	void String::Replace(size_t index, size_t count, const char* const other, size_t length) {
		if (index >= length_) return;
		if (count > length_ - index) count = length_ - index;
		size_t newLength = length_ - count + length;
		this->CheckSizeAndReallocate(newLength);
		memcpy(temp_, other, length);
		memcpy(temp_ + length, data_ + index + count, length_ - index - count);
		memcpy(data_ + index, temp_, newLength - index);
		this->SetNewLength(newLength);
	}
	void String::Replace(size_t index, size_t count, const char c) {
		if (index >= length_) return;
		if (count > length_ - index) count = length_ - index;
		size_t newLength = length_ - count + 1;
		this->CheckSizeAndReallocate(newLength);
		temp_[index] = c;
		memcpy(temp_ + 1, data_ + index + count, length_ - index - count);
		memcpy(data_ + index, temp_, newLength - index);
		this->SetNewLength(newLength);
	}

	String::~String() {
		free(data_);
		--s_instanceCounter_;
	}

	size_t String::s_defaultCapacity = 256;
	size_t String::s_instanceCounter_ = 0;
	size_t String::s_totalInstancesCreated_ = 0;
}
