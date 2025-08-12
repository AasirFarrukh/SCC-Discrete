# 🔗 Largest Strongly Connected Component Finder

A **C++** program that reads a **directed graph** dataset and computes the **largest Strongly Connected Component (SCC)** using **Kosaraju’s Algorithm**.  
Developed as the **final project** for the **Discrete Structures** course in **Semester 3**.

---

## 📌 Project Overview
The program:
1. Reads graph data from an input file (`web-Google.txt`).
2. Builds a directed graph using adjacency lists.
3. Performs:
   - **DFS traversal**
   - **Graph reversal**
   - **Kosaraju’s algorithm** to find SCCs
4. Outputs the **size of the largest SCC** in the graph.

This simulates **web graph analysis** (similar to Google’s link network dataset).

---

## 🧮 Algorithm Used
**Kosaraju’s Algorithm**:
1. Perform DFS on the original graph, storing vertices by finish time.
2. Reverse the graph (transpose).
3. Perform DFS on the reversed graph in decreasing finish time order.
4. Track component sizes and return the largest SCC size.

---

## 🎯 Learning Outcomes
- Implementation of Kosaraju’s algorithm.
- Understanding of DFS and graph transposition.
- Application of Discrete Structures concepts to real-world datasets.
- Working with large-scale graph data.

---

## 📜 License
This project is licensed under the MIT License — you can use and adapt it for educational purposes.
