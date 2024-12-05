# **Credit Card Fraud Detection System**

**Project Synopsis:** Credit card fraud is a significant problem in the financial industry, resulting in billions of dollars in losses annually. Traditional fraud detection systems often rely on manual reviews and simple rule-based systems, which can be time-consuming and ineffective. This project aims to develop a more efficient and accurate system using advanced data structures and algorithms
The project will focus on developing a robust and efficient system that can analyze large datasets of credit card transactions and detect fraudulent activities. The system will utilize a combination of data structures, including arrays, linked lists, and trees, to store and process transaction data.

**Data Structures Employed:**
- Hash-map: Used to store statistical data such as mean, standard deviation, and variance, and to maintain references to linked lists and BST nodes.
- Binary Search Tree (BST): Employed for efficient storage and retrieval of transaction amounts and statuses, allowing for quick look up and analysis of spending patterns.
- Linked List: Utilised to track transactions based on timestamp and location, supporting chronological ordering and traversal of transaction history.

**Data Flow and Integration:**
At program execution, a CSV file containing user details and transaction history is provided as input.
The data is parsed and stored in the appropriate data structures: hash-maps for storing user
statistics, linked lists for details.

**Fraud Detection:**
- if multiple failed transaction occur in a short span of time, they are a sign of potential fraud and will be flagged as the same.
Monitor the time intervals between consecutive transactions. Flag any transactions with unusually short time intervals as potential fraud.
- if the location of the current transaction is significantly different from the previous transaction’s location.
- if neither time nor location anomalies are detected, apply a z-score-based statistical method to compare the current transaction amount against the user’s spending pattern. If the z-score exceeds a predefined threshold, flag it as a potential fraud.

**Algorithms:**
1. Naive Bayes: Predicts whether a transaction is fraudulent based on historical data and probabilities.
2. Z-Score Calculation: Flags transactions significantly deviating from a user’s average spending.
3. Time Interval Analysis: Detects rapid consecutive transactions, which could indicate suspicious activity.
4. Location Anomaly Check: Flags geographically inconsistent transactions in short time intervals.