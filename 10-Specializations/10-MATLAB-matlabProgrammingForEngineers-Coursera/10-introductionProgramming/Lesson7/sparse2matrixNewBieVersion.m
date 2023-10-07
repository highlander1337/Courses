function matrix = sparse2matrixNewBieVersion(cellvec)
  % How to call it
  % matrix = sparse2matrixNewBieVersion({[2 3], 0, [1 2 3], [2 2 -3]})
  % Where, the first element of the cell is a vector containing the dimensions of a sparse matrix
  % The second element of the cell is the default value of the sparse matrix
  % The following elements is vectors of values location and the value itself in the format [row coll value]
  
size_matrix = cellvec{1};
default_value = cellvec{2};
matrix = ones(size_matrix(1), size_matrix(2)).*default_value;
for i = 3:length(cellvec)
    row = cellvec{i}(1);
    coll = cellvec{i}(2);
    value = cellvec{i}(3);
    matrix(row, coll) = value;
end
end

% Turns out that my solutions was equal to the MOOC solution, so there is no Pro or Master version yet.
