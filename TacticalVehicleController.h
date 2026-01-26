#ifndef TACTICALVEHICLECONTROLLER_H
#define TACTICALVEHICLECONTROLLER_H

#include <vector>
#include <QString>


class TacticalVehicleData;
struct TacticalVehicle;

/**
 * @struct FilterCriteria
 * @brief Aggregates all filter inputs resolved from UI state.
 *
 * Pure data container. No logic.
 */
struct FilterCriteria
{
    // --- Operational Capabilities ---
    bool hasSatCom = false;
    bool isAmphibious = false;
    bool isUnmanned = false;
    bool hasActiveDefense = false;

    // --- Identity Filters ---
    bool callsignActive = false;
    QString callsign;

    bool trackIdActive = false;
    QString trackId;

    // --- Strategic Classification ---
    bool domainActive = false;
    QString domain;

    bool propulsionActive = false;
    QString propulsion;

    bool priorityActive = false;
    QString priority;

    // --- Protection Constraints ---
    bool protectionMinActive = false;
    int protectionMin = 0;

    bool protectionMaxActive = false;
    int protectionMax = 0;

    // --- Telemetry Ranges ---
    int fuelMin = 0;
    int fuelMax = 100;

    int distanceMin = 0;
    int distanceMax = 10000;

    // --- Affiliation ---
    QString affiliation = "All Types";
};

/**
 * @class TacticalVehicleController
 * @brief Central logic controller for tactical vehicle processing.
 *
 * Responsibilities:
 *  - Evaluate filtering criteria against the vehicle database
 *  - Maintain derived filtered views for presentation
 *  - Advance simulation state and compute derived telemetry
 *
 * This class is intentionally UI-agnostic and operates purely
 * on data and primitive inputs resolved by MainWindow.
 */
class TacticalVehicleController
{
public:
    explicit TacticalVehicleController(TacticalVehicleData& data);

    /**
     * @section FILTERING_LOGIC
     * Computes filteredVehicles based on externally provided criteria.
     * Does NOT perform any UI updates or own presentation state.
     */
    void applyFilter(const FilterCriteria& criteria);
    bool isFilterActive() const;

    /**
     * @section SIMULATION_LOGIC
     * Advances vehicle positions and updates target-relative telemetry.
     */
    void updateSimulation(double targetX, double targetY);

    /**
     * @brief Derived view of vehicles matching current filter criteria.
     * Owned and maintained by the controller.
     */
    std::vector<const TacticalVehicle*> filteredVehicles;

private:
    /** Reference to the authoritative vehicle data store. */
    TacticalVehicleData& data;
};

#endif // TACTICALVEHICLECONTROLLER_H
