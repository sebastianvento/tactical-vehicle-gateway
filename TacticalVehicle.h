#ifndef TACTICALVEHICLE_H
#define TACTICALVEHICLE_H

#include <QString>

/**
 * @struct TacticalVehicle
 * @brief Represents a single unit within the Tactical Vehicle Gateway.
 *
 * This structure holds static identity markers, technical specifications,
 * and dynamic telemetry data used for real-time simulation and filtering.
 */
struct TacticalVehicle {

    // --- Identity & Classification ---
    QString callsign;       ///< Unique radio callsign (e.g., "Sabre 1-1")
    QString trackId;       ///< Unique system track identifier (e.g., "T-7201")
    QString type;          ///< Specific vehicle model or designation
    QString classification; ///< Broad asset category
    QString affiliation;    ///< Hostility status (Friendly, Hostile, Neutral, Unknown)
    QString priority;         ///< Strategic priority level
    QString domain;         ///< Operational environment (Land, Sea, Air, etc.)
    QString propulsion;     ///< Locomotion method (Wheeled, Tracked, etc.)

    // --- Technical Specifications ---
    int protectionLevel = 0;    ///< STANAG 4569 ballistic protection level (1-6)
    double maxSpeed = 0.0;      ///< Maximum rated speed (km/h)
    QString natoIcon;           ///< Path or ID for standard APP-6/MIL-STD-2525 symbol

    // --- Operational Capabilities (Boolean Flags) ---
    bool hasSatCom = false;           ///< Active Satellite Communication link
    bool isAmphibious = false;        ///< Capable of water-based operations
    bool isUnmanned = false;          ///< UxV / Autonomous operation capability
    bool hasActiveDefense = false;    ///< Hard-kill or soft-kill defense systems

    // --- Dynamic Telemetry & Simulation Data ---
    double posX = 0.0;               ///< Cartesian X coordinate (meters)
    double posY = 0.0;               ///< Cartesian Y coordinate (meters)
    double heading = 0.0;            ///< Navigational heading in degrees (0-359)
    double speed = 0.0;              ///< Current operational speed (km/h)
    double fuelLevel = 100.0;        ///< Remaining fuel percentage (0-100)
    double ammunitionLevel = 100.0;  ///< Remaining combat load percentage (0-100)
    double distanceToTarget = 0.0;   ///< Calculated Euclidean distance to mission target (m)
};

#endif // TACTICALVEHICLE_H
