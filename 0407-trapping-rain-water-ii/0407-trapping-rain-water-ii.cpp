class Solution {
private:
    class Cell{
        public:
        int height, row, col;
        Cell(int height,int row,int col):height(height), row(row), col(col){}

        bool operator<(const Cell& other) const{
            return height>=other.height;
        }

    };
    bool isValid(int row,int col,int  numRows,int numCols){
        return row>=0 && col>=0 && row<numRows && col<numCols;
    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // 4 direction up, down, left, right
        /*
                    
                        i-1,j
            i,j-1        i,j    i,j+1
                        i+1,j
        */

        int dRow[4]={-1,0,1,0};
        int dCol[4]={0,1,0,-1};
        
        int numRows=heightMap.size();
        int numCols=heightMap[0].size();

        vector<vector<bool>>visited(numRows,vector<bool>(numCols,false));

        priority_queue<Cell>boundary;

        // Add the first and last column of the matrix
        for(int i=0;i<numRows;i++){
            boundary.push(Cell(heightMap[i][0],i,0));
            boundary.push(Cell(heightMap[i][numCols-1],i,numCols-1));

            visited[i][0]=visited[i][numCols-1]=true;
        }

        // Add the first and last row of the matrix
        for(int i=0;i<numCols;i++){
            boundary.push(Cell(heightMap[0][i],0,i));
            boundary.push(Cell(heightMap[numRows-1][i],numRows-1,i));

            visited[0][i]=visited[numRows-1][i]=true;
        }

        int tolWater=0;

        while(!boundary.empty()){
            Cell currentCell=boundary.top();
            boundary.pop();

            int currentRow=currentCell.row;
            int currentCol=currentCell.col;
            int minBoundary=currentCell.height;

            for(int dir=0;dir<4;dir++){
                int neighRow=currentRow+dRow[dir];
                int neighCol=currentCol+dCol[dir];

                if(isValid(neighRow,neighCol,numRows,numCols) && !visited[neighRow][neighCol]){
                    int neighHeight=heightMap[neighRow][neighCol];
                    if(neighHeight<minBoundary){
                        tolWater+=minBoundary-neighHeight;
                    }
                    boundary.push(Cell(max(minBoundary,neighHeight),neighRow,neighCol));
                    visited[neighRow][neighCol]=true;
                }
            }
        }
        return tolWater;
    }
};