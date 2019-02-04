#include <XCurses/Status.h>

namespace xcur {
Status::Status() :
    code(Status::Code::Ok)
{
}

Status::Status(int32_t _code) :
    code(_code)
{
}

Status& Status::operator=(const int32_t& right)
{
	this->code = right;
	return *this;
}

bool operator==(const Status& left, const int32_t& right)
{
	return left.code == right;
}

bool operator==(const Status& left, const Status& right)
{
	return left.code == right.code;
}

bool operator!=(const Status& left, const int32_t& right)
{
	return left.code != right;
}

bool operator!=(const Status& left, const Status& right)
{
	return left.code != right.code;
}
}
