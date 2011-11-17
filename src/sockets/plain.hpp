/*
 * Copyright (c) 2011, Peter Thorson. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the WebSocket++ Project nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL PETER THORSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef WEBSOCKETPP_SOCKET_PLAIN_HPP
#define WEBSOCKETPP_SOCKET_PLAIN_HPP

#include "socket_base.hpp"

#include <boost/asio.hpp>
#include <boost/function.hpp>

#include <iostream>

namespace websocketpp {
namespace socket {

template <typename endpoint_type>
class plain {
public:
	boost::asio::io_service& get_io_service() {
		return m_io_service;
	}
	
	// Connection specific details
	template <typename connection_type>
	class connection {
	public:
		connection(plain<endpoint_type>& e) : m_socket(e.get_io_service()) {
			std::cout << "setup plain connection" << std::endl;
		}
		
		void async_init(socket_init_callback callback) {
			std::cout << "performing plain security handshake" << std::endl;
			//static_cast< connection_type* >(this)->websocket_handshake();
			callback(boost::system::error_code());
		}
		
		boost::asio::ip::tcp::socket& get_raw_socket() {
			return m_socket;
		}
		
		boost::asio::ip::tcp::socket& get_socket() {
			return m_socket;
		}
	private:
		boost::asio::ip::tcp::socket m_socket;
	};
protected:
	plain (boost::asio::io_service& m) : m_io_service(m) {
		std::cout << "setup plain endpoint" << std::endl;
	}
private:
	boost::asio::io_service& m_io_service;
};

	
} // namespace socket
} // namespace websocketpp

#endif // WEBSOCKETPP_SOCKET_PLAIN_HPP
