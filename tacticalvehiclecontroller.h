#ifndef TACTICALVEHICLECONTROLLER_H
#define TACTICALVEHICLECONTROLLER_H

#include <vector>
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <QString>


class TacticalVehicleData;
struct TacticalVehicle;

/**
 * @class TacticalVehicleController
 * @brief Orchestrates filtering, simulation, and derived tactical views.
 */
class TacticalVehicleController
{
public:
    explicit TacticalVehicleController(TacticalVehicleData& data);
    std::vector<const TacticalVehicle*> filteredVehicles;
    // Computes filteredVehicles based on current UI state.
    // Does NOT update UI and does NOT own presentation logic.
    void applyFilter(
        bool hasSatCom,
        bool isAmphibious,
        bool isUnmanned,
        bool hasActiveDefense,

        bool callsignActive,
        const QString& callsign,

        bool trackIdActive,
        const QString& trackId,

        bool domainActive,
        const QString& domain,

        bool propulsionActive,
        const QString& propulsion,

        bool priorityActive,
        const QString& priority,

        bool protectionMinActive,
        int protectionMin,

        bool protectionMaxActive,
        int protectionMax,

        int fuelMin,
        int fuelMax,

        int distanceMin,
        int distanceMax,

        const QString& affiliation
        );
    void updateSimulation(double targetX, double targetY);

private:
    TacticalVehicleData& data;
};

#endif // TACTICALVEHICLECONTROLLER_H
