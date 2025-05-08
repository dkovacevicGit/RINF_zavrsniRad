# Mony Manager

**Mony Manager** is a lightweight Windows desktop application for managing personal or household budgets.
It helps users keep track of income and expenses, organize them by category, and get a clear monthly financial overview.

---

## ✨ Features

- Add, edit, and delete transactions
- Categorize income and expenses
- View monthly summaries
- Filter transactions by category and date
- Export data to CSV
- Simple and intuitive user interface
- Local storage – no cloud, no account required

---

## 🛠️ Technical Details

- **Language:** C++
- **Framework:** VCL (Visual Component Library) – Embarcadero C++ Builder
- **Database:** SQLite (local, embedded)
- **Data Access:** FireDAC (high-performance database library)
- **UI Components:** `TStringGrid`, `TDateTimePicker`, `TComboBox`, `TChart`, `TEdit`, `TLabel`, etc.
- **Configuration:** INI file for saving user preferences

The application is fully standalone – no installation or external dependencies required. Just run the `.exe` and start managing your budget.


---


## 📦 How to Build

1. Open the project in **Embarcadero C++ Builder**.
2. Make sure FireDAC and SQLite libraries are available.
3. Compile and run the project.
4. The app creates the SQLite database file on first launch.

---

## 📝 License

This project is provided for educational and personal use.

---

## 👤 Author

Created by Danijel Kovačević

