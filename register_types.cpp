#include "register_types.h"
#ifdef TOOLS_ENABLED
#include "client/zprofiling_client.h"
#include "server/zprofiling_server.h"
#endif

void register_zprofiler_types() {
#ifdef TOOLS_ENABLED
	ClassDB::register_class<ZProfilingClient>();
	ZProfiler::get_thread_profiler().set_thread_name("Main");
	ZProfilingServer::create_singleton();
#endif
}

void unregister_zprofiler_types() {
#ifdef TOOLS_ENABLED
	ZProfiler::get_thread_profiler().finalize();
	ZProfilingServer::destroy_singleton();
	ZProfiler::terminate();
#endif
}
