function [distance] = get_distance(c1, c2)
[~, ~, data] = xlsread('Distances.xlsx');
rows = data(:,1);
rows{1} = ' ';
colls = data(1,:);
colls{1} = ' ';
row = matches(rows, c1);
coll = matches(colls, c2);
if row == 0 || coll == 0
    distance = -1;
else
    distance = data{row, coll};

end