#include <XCurses/System/Status.h>

namespace xcur {
Status::Status() :
    code(Status::Code::Ok)
{
}

Status::Status(int32_t code) :
    code(code)
{
}

Status& Status::operator=(const int32_t& right)
{
    this->code = right;
    return *this;
}

bool Status::operator==(const int32_t& right) const
{
    return this->code == right;
}

bool Status::operator==(const Status& right) const
{
	return this->code == right.code;
}

bool Status::operator!=(const int32_t& right) const
{
    return !(*this == right);
}

bool Status::operator!=(const Status& right) const
{
    return !(*this == right);
}
}
