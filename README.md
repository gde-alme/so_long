Project for 42 Lisboa.  
  
Brief explanation:  
-Uses Minilibx library to display image;
-Map is a txt file [1-Wall|0-Empty|C-Collectible|E-Exit|P-Player]
-One "frame" (struct) holds all important info
-Game is in reality several images displayed in sequence and in 
	between each display, the Player coords are re-arranged.

HOW TO USE:
-git clone git@github.com:gde-alme/so_long.git
-cd so_long/minilibx-linux
-./configure
-cd ..
-make
-/so_long map.ber
