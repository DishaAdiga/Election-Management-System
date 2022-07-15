
A simple election management system that uses files to keep track of voters and count the votes inorder to declare the winner. 
The votes casted by a voter is stored in a file. 
The list of entries in the file is converted  into an array of vectors. 
The name of the party in the array represents a vote gained by that particular party. 
This particular array containing the names of the parties that have secured the votes is then represented as a hash map. 
All votes are inserted into a hash map and we keep a track of count of different names. 
Finally, we traverse the map and print the party with the maximum votes.
