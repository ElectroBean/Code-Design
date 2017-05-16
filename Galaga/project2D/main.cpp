#include "Application2D.h"
#include <crtdbg.h>


int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	auto app = new Application2D();
	app->run("AIE", 1080, 720, false);
	delete app;

	return 0;
}