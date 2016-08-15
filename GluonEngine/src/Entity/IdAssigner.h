#pragma once

class IDAssigner
{
public:
	static void Init()
	{
		s_LastAssignedID = 0;
	}

	static int GetNextID()
	{
		return s_LastAssignedID++;
	}

private:
	static int s_LastAssignedID;
};
