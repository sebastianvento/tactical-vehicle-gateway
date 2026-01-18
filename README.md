# Tactical Vehicle Gateway (TVG)

Tactical Vehicle Gateway is an advanced C++/Qt situational awareness system designed for real-time monitoring, filtering, and telemetry analysis of tactical assets. The application integrates robust data persistence, dynamic kinematic simulation, and a modern, reactive UI architecture.

## 🛠 Technical Highlights

* **Custom UI Components:** Features a bespoke `RangeSlider` widget developed from the ground up. By inheriting from `QWidget` and overriding low-level handlers (`paintEvent`, `mouseMoveEvent`), the project demonstrates a deep mastery of the Qt framework beyond standard library widgets.
* **Data Management & Persistence:** Implements `QJsonDocument` parsing for dynamic asset ingestion. The architecture utilizes a "Master-View" pattern—owning data in a `std::deque` while managing filtered results in a `std::vector<TacticalVehicle*>`—optimizing memory overhead and performance during high-frequency updates.
* **Kinematic Simulation Engine:** Includes a background simulation "heartbeat" that updates vehicle positions and distances to targets in real-time. It utilizes vector mathematics, including trigonometry (`std::cos`, `std::sin`) and Euclidean distance calculations.
* **Algorithmic Efficiency:** Employs static predicate functions and STL `std::sort` combined with lambda expressions to provide instantaneous sorting of assets based on fuel criticality, proximity, classification, or strategic priority.

## 📡 Operational Features

### 1. Situational Awareness (SA)
* **Multi-Dimensional Filtering:** A complex engine that evaluates boolean capabilities (SATCOM, Active Defense), string-based identity (Callsign/Track ID), and dynamic numerical ranges simultaneously.
* **Tactical Visualization:** Results are color-coded by affiliation (Friendly, Hostile, Neutral) and rendered in a monospaced format to ensure maximum readability in high-stress operational environments.
* **Standard Compliance:** Built-in support for STANAG 4569 protection levels (1-6) and designed for integration with APP-6/MIL-STD-2525 symbology.

### 2. Usability & Reliability
* **Reactive UI:** The interface is fully reactive; every input change triggers an immediate update of the situational picture without requiring manual refreshes.
* **Input Validation:** Robust error handling using `QCompleter` for rapid searching and `QValidator` for coordinate inputs ensures data integrity during critical mission phases.

## 🏗 System Architecture
The project is modularized into distinct layers of responsibility:
* **TacticalVehicle:** An efficient struct-based data model for individual assets.
* **TacticalVehicleData:** The backend controller responsible for JSON I/O and static sorting logic.
* **MainWindow:** The central orchestrator managing signals, slots, and the simulation heartbeat.
* **RangeSlider:** A reusable, standalone UI component for range-based data entry.

## 🚀 Getting Started

### Prerequisites
* Qt 6.x (or higher)
* C++17 compatible compiler (MSVC, GCC, or Clang)

### Build & Run
1. **Clone the repository:** `git clone https://github.com/sebastianvento/Tactical-Vehicle-Gateway.git`
2. Open `TacticalVehicleGateway.pro` in Qt Creator.
3. Ensure `vehicles.json` is located within the resource path (`:/data/`).
4. Build and run using: `qmake && make`

### Build Environment
* **Framework:** Qt 6.10.1 (recommended)
* **OS:** macOS
* **Compiler:** Apple Clang (C++17)
* **Build Tool:** qmake / make
