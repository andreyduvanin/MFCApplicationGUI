#pragma once

// Целевой объект команды Cudp2Socket

class Cudp2Socket : public CSocket
{
public:
	Cudp2Socket();
	virtual ~Cudp2Socket();
	virtual void OnReceive(int nErrorCode);
public:

};


