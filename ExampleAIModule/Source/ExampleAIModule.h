#pragma once
#include <BWAPI.h>
#include "Metatype.h"
// Remember not to use "Broodwar" in any global class constructor!
namespace ExampleAI
{ 
class ExampleAIModule : public BWAPI::AIModule
{
	BWAPI::UnitType drone = BWAPI::UnitTypes::Zerg_Drone;
	BWAPI::UnitType pool = BWAPI::UnitTypes::Zerg_Spawning_Pool;
	BWAPI::UnitType hatch = BWAPI::UnitTypes::Zerg_Hatchery;
	BWAPI::UnitType overlord = BWAPI::UnitTypes::Zerg_Overlord;
	bool poolbuilt;
	int workers;
	int reservedMinerals;
	bool buildCommandGiven = false;
	std::vector<BWAPI::UnitType> buildOrder;
	std::vector<BWAPI::UnitType> fourPool{pool ,drone };
	std::vector<BWAPI::UnitType> ninePool{ drone,drone,drone,drone,drone, pool };
	std::vector<BWAPI::UnitType> twoHatch{ drone,drone,drone,drone,drone,overlord,drone,drone,hatch,pool };
public:
  // Virtual functions for callbacks, leave these as they are.
  virtual void onStart();
  virtual void onEnd(bool isWinner);
  virtual void onFrame();
  virtual void onSendText(std::string text);
  virtual void onReceiveText(BWAPI::Player player, std::string text);
  virtual void onPlayerLeft(BWAPI::Player player);
  virtual void onNukeDetect(BWAPI::Position target);
  virtual void onUnitDiscover(BWAPI::Unit unit);
  virtual void onUnitEvade(BWAPI::Unit unit);
  virtual void onUnitShow(BWAPI::Unit unit);
  virtual void onUnitHide(BWAPI::Unit unit);
  virtual void onUnitCreate(BWAPI::Unit unit);
  virtual void onUnitDestroy(BWAPI::Unit unit);
  virtual void onUnitMorph(BWAPI::Unit unit);
  virtual void onUnitRenegade(BWAPI::Unit unit);
  virtual void onSaveGame(std::string gameName);
  virtual void onUnitComplete(BWAPI::Unit unit);
  // Everything below this line is safe to modify.

};
}