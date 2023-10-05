% For the purposes of this problem, a saddle point is defined as an element whose value is 
% greater than or equal to every element in its row, and less than or equal to every element
% in its column.

function indices = saddle(M)
% Vector containing the number of rows and collums o M
dims = size(M);

indices = [];
for ii = 1:dims(1)
    for jj = 1:dims(2)
        if M(ii,jj) >= M(ii,:)
            if M(ii,jj) <= M(:,jj)
                indices = [indices; ii jj];
            end
        end  
    end
end
end


% Example of how to call it
% create an interesting surface
[X,Y] = meshgrid(-15:0.5:10,-10:0.5:10);
Z = (X.^2-Y.^2)';
% find saddle points
indices = saddle(Z)
% plot surface
surf(Z);
hold on
% mark saddle points with red dots in the same figure
for ii = 1:size(indices,1)
    h = scatter3(indices(ii,2),indices(ii,1),Z(indices(ii,1),indices(ii,2)),'red','filled');
    h.SizeData = 120;
end
% adjust viewpoint
view(-115,14);
hold off
