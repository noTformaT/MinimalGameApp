#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication {

public:
	/* Application constructor */
	Application();

	/* Application destructor */
	~Application();

public:
	/* Called to Settup our game settings */
	virtual VOID SetupGameSettings() override;

	/* Called to Initialize the Application */
	VOID Initialize() override;

	/* Game Loop - Called on a loop while the Application is running */
	VOID Update() override;
};