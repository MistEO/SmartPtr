#pragma once

struct RefCtrl
{
private:
	RefCtrl() = default;
	~RefCtrl() = default;

	int refCount;
	int weakCount;
};
