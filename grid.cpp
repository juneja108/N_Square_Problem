module;

#include <memory> 
#include <print>

export module grid;

export namespace grid {
    /**
     * @brief A memory safe object that creates a grid of shape n^2, and provides utility functions
     * @author Shaurya Juneja
     */
    struct Grid { 
        int size;
        std::unique_ptr<std::unique_ptr<int[]>[]> data;

        Grid (int n) : size(n) { 
            data = std::make_unique<std::unique_ptr<int[]>[]>(n);

            // create the internal arrays
            for (int i = 0; i < n; i++) { 
                data[i] = std::make_unique<int[]>(n);
            }
        }

        /**
         * @brief Print out the entire 2D array with formatting
         */
        void deepPrint() {
            // every row
            for (int i = 0; i < size; i++) {
                // every column
                for (int j = 0; j < size; j++) { 
                    std::print("{} ", data[i][j]);
                }
                std::print("\n"); 
            }
        }

        /**
         * @brief Get the value of the cell @ (x,y)
         */
        int valueAt(int x, int y) { 
            return data[x][y];
        }

        /**
         * @brief Set value of the cell @ (x,y)
         */
        void set(int x, int y, int value) { 
            data[x][y] = value;
        }
        
        /**
         * @brief Get the value of cells in an entire row from the grid
         */
        std::unique_ptr<int[]> getRow(int x) {
            auto row = std::make_unique<int[]>(size);

            // for every column
            for (int i = 0; i < size; i++) { 
                row[i] = valueAt(x, i);
            }

            return row;
        }
        /**
         * @brief Get the values of cells in an entire column from the grid
         */
        std::unique_ptr<int[]> getColumn(int y) {
            auto column = std::make_unique<int[]>(size); 

            // for every row
            for (int i = 0; i < size; i++) {
                column[i] = valueAt(i, y);
            }

            return column;
        }
        /**
         * @brief Get the value of cells in an entire diagonal from the grid
         * @param left `true` if you want the data from the left diagonal and `false` if you want the data from the right diagonal
         */
        std::unique_ptr<int[]> getDiagonal(bool left) {
            auto diagonal = std::make_unique<int[]>(size);

            // for every row
            for (int i = 0; i < size; i++)
            {
                if (left == true)
                {
                    diagonal[i] = valueAt(i, i); // diagonals from the left follow the line of y=-x
                }
                else // right diagonal
                {
                    diagonal[i] = valueAt(i, size - 1 - i); // diagonals on the right follow the line y=x
                                                                // size - 1 is needed as indexing begins at 0
                }
            }

            return diagonal;
        }
    };

    std::unique_ptr<Grid> createGrid(int n) { 
        return std::make_unique<Grid>(n);
    }
}