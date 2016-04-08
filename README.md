***************************
Name- Sumeet Tulsani
***************************

* List of Bugs Found while testing ConnectX Game:

- Out of bound width and in bound height bug:
  This bug occurs in inbound function when width is greater than the maximum width or less than zero and 
  the height is in valid range. Firstly, when the width is passed to this function which is invalid it 
  sets the flag to false, which is correct but then it falls in another if which is used to check the 
  height passed to the function and if the height is in range it sets the flag back to true which causes
  a bug in the code. This function also results in failure of another functions like the 'at' function, 
  'placePiece' function and 'showBoard' function as they call inbound function.The location locationOutBounds
  test causes this bug to occur.

- Piece being placed outside the board bug:
  This bug occurs in placePiece function when value of column passed to this function is out of range column
  value. The code in placePiece function calls 'at' function which takes column value passed to the placePiece 
  function as the first parameter and i(which is less than height-1 and greather than zero) as the second 
  parameter. Then the 'at' function calls the inbound function by sending the column value as width and i as 
  height value for inbound function resulting into above described bug, thus the position is returned as valid
  which is then compared to 'EMPTY' to see if the location is empty on board. This wrong comparision is then 
  anded with the inbound condition which also returns valid everytime due to the bug present in the inbound
  function. This results in placing of piece in invalid location, which gives a double free() error, which is
  error in malloc() function calling abort() function due to heap overflow problem when column value is passed 
  as "-1". Other invalid locations does not produce double free() error but the code falls in if loop even if
  the condition is expected to fail. The placePieceOutBoard test causes this bug.
  
