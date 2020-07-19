#pragma once
#include <thread>
#include <vector>
#include "SmNetDefine.h"
class SmNetClient
{
public:
	SmNetClient() : _server_thread(&SmNetClient::ThreadMain, this) {}
	~SmNetClient() {
		_server_thread.join();
	}
	void Stop();
private:
	void Start();
	std::thread _server_thread;
	void ThreadMain();
	// The io_context is required for all I/O
	//net::io_context ioc;

	net::io_context* _context = nullptr;
};

