cmake_minimum_required(VERSION 2.6)
project(RType)

include_directories(include/)
include_directories(include/Socket/)
include_directories(include/Timer/)
include_directories(include/Library/)
include_directories(include/Thread/)
include_directories(include/Protocol/)
include_directories(include/Server/)
include_directories(include/Client/)

set(EXECUTABLE_OUTPUT_PATH ..)

if (NOT "${CMAKE_SYSTEM_NAME}" MATCHES "Windows")

	find_package(Threads)

	add_executable(server
									src/Server/main.cpp
									src/Server/Server.cpp
									src/Server/Client.cpp
									src/Server/Player.cpp
									src/Server/Game.cpp
									src/Socket/Select.cpp
									src/Server/EntityManager.cpp
									src/Server/AEntity.cpp
									src/Server/Protocol.cpp
									src/Server/HandleID.cpp
									src/Library/Library.cpp
									src/Timer/Time.cpp
									src/Timer/Timer.cpp
									src/Socket/SocketException.cpp
									src/Socket/TCPServer.cpp
									src/Socket/TCPSocketUnix.cpp
									src/Socket/UDPSocketUnix.cpp)

	target_link_libraries(server ${CMAKE_THREAD_LIBS_INIT})
	target_link_libraries(server ${CMAKE_DL_LIBS})

	add_executable(client
									src/Client/main.cpp
									src/Client/EndMenu.cpp
									src/Client/Entity.cpp
									src/Client/GameGui.cpp
									src/Client/GameWindow.cpp
									src/Client/Mouse.cpp
									src/Client/RType.cpp
									src/Client/StartMenu.cpp
									src/Client/JoinMenu.cpp
									src/Client/Picture.cpp
									src/Timer/Time.cpp
									src/Timer/Timer.cpp
									src/Client/Protocol.cpp
									src/Socket/SocketException.cpp
									src/Socket/TCPSocketUnix.cpp
									src/Socket/UDPSocketUnix.cpp)

	SET			(SFML_ROOT              /usr/)
	SET			(SFML_INCLUDEDIR        ${SFML_ROOT}include/)
	SET			(SFML_LIBRARYDIR        ${SFML_ROOT}lib/)

LINK_DIRECTORIES(${SFML_LIBRARYDIR})
INCLUDE_DIRECTORIES(${SFML_INCLUDEDIR})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
target_link_libraries(client ${SFML_LIBRARIES})
else (NOT "${CMAKE_SYSTEM_NAME}" MATCHES "Windows")

	find_library(WSOCK32_LIBRARY wsock32)

	add_executable(server
									src/Server/main.cpp
									src/Server/Server.cpp
									src/Server/Client.cpp
									src/Server/Player.cpp
									src/Server/Game.cpp
									src/Socket/Select.cpp
									src/Server/EntityManager.cpp
									src/Server/AEntity.cpp
									src/Server/HandleID.cpp
									src/Server/Protocol.cpp
									src/Library/Library.cpp
									src/Timer/Time.cpp
									src/Timer/Timer.cpp
									src/Socket/SocketException.cpp
									src/Socket/TCPServer.cpp
									src/Socket/TCPSocketWindows.cpp
									src/Socket/UDPSocketWindows.cpp)

	target_link_libraries(server wsock32 ws2_32)

	add_executable(client
									src/Client/main.cpp
									src/Client/EndMenu.cpp
									src/Client/Entity.cpp
									src/Client/GameGui.cpp
									src/Client/GameWindow.cpp
									src/Client/Mouse.cpp
									src/Client/RType.cpp
									src/Client/StartMenu.cpp
									src/Client/JoinMenu.cpp
									src/Client/Picture.cpp
									src/Timer/Time.cpp
									src/Timer/Timer.cpp
									src/Client/Protocol.cpp
									src/Socket/SocketException.cpp
									src/Socket/TCPSocketWindows.cpp
									src/Socket/UDPSocketWindows.cpp)

	SET		(SFML_ROOT			C:/sfml/)
	SET		(SFML_INCLUDEDIR	${SFML_ROOT}include/)
	SET		(SFML_LIBRARYDIR	${SFML_ROOT}lib/)

	LINK_DIRECTORIES(${SFML_LIBRARYDIR})
	INCLUDE_DIRECTORIES(${SFML_INCLUDEDIR})
	set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
	find_package(SFML 2 REQUIRED system window graphics network audio)
	target_link_libraries(client ${SFML_DLL_LIBRARY})
	target_link_libraries(client ${SFML_LIBRARIES})
	target_link_libraries(client wsock32 ws2_32)

endif (NOT "${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
