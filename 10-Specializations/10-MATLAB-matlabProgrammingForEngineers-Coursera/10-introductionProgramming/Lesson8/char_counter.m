%  Write a function called char_counter that counts the number of a certain character in a text file. 
%  The function takes two input arguments, fname, a char vector of the filename and character,
%  the char it counts in the file. The function returns charnum, the number of characters found.
%  If the file is not found or character is not a valid char, the function return -1.
function charnum = char_counter(fname, character)

fid = fopen(fname, 'rt');

if fid < 0 || ~ischar(character)
    charnum = -1;
    return;
end

line = fgets(fid);
charnum = 0;
while ischar(line)
    charnum = charnum + length(strfind(line, character));
    line = fgets(fid);
end
fclose(fid);
end
