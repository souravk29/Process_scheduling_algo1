# 🖥️ Process Scheduler Simulator

[![C Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Contributions Welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)](#-contributing)

A **C-based Process Scheduling Simulator** that allows you to visualize and compare how different CPU scheduling algorithms work in real-time.  
It generates **Gantt charts** and displays key statistics such as **Turnaround Time, Waiting Time, and Throughput**.

---

## ✨ Features

- **Multiple Scheduling Algorithms**
  - First-Come, First-Served (**FCFS**)
  - Shortest Job First (**SJF**) _(Coming Soon)_
  - **Priority Scheduling** _(Coming Soon)_
  - **Round Robin (RR)** _(Coming Soon)_
  
- **📊 Gantt Chart Visualization** – Shows the process execution timeline clearly.

- **📈 Detailed Metrics** – Turnaround Time, Waiting Time, and Throughput.

- **📝 Interactive Input** – Enter process details like **Burst Time**, **Arrival Time**, and **Priority**.

---

## 🧮 Scheduling Algorithms Overview

| Algorithm      | Description |
|----------------|-------------|
| **FCFS**       | Processes are executed in the order they arrive. |
| **SJF** _(WIP)_ | Executes the process with the shortest burst time first. |
| **Priority** _(WIP)_ | Executes based on process priority (higher priority first). |
| **Round Robin** _(WIP)_ | Each process gets a fixed time slice and cycles through a queue. |

---

## 📦 Installation & Usage

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/PraTeekK123/Process_scheduling_algo1.git
cd Process_scheduling_algo1
