# Space Invader

Welcome to **Space Invader**! This is my first game developed using SDL 2.0 for my Advanced Programming course. Although the name may sound familiar, this is not the classic Space Invaders game; it's a unique take on a space shooter. 


## About the Game

**Space Invader** is an endless space shooter game designed for limitless fun and challenge. Try to achieve the highest score you can!

## Starting the Game

- **Launch the Game**: Run the `My_First_Game(SDL_Based).exe` file to start the game.
- **Menu Screen**: Upon launching, the game menu will appear on your screen.

![Menu](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/6a4a8c33-bade-40bb-adaa-11a58e678ccb)

- **Controls**:
  - To exit the game, press `ESC`.
  - To begin playing, press `X` on your keyboard.

![Game Start](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/9e5eadb4-4a9b-4d6c-8d78-b8636f1f48f7)

## In-Game Features

- **Score and Lives**: Your score and remaining lives are displayed at the top of the screen. If you run out of lives, the game ends, and a message box will appear.

![Game Over](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/20840f43-361e-4638-8624-af65180acf13)

- **Enemies: Troopers**: Troopers move in a straight line toward you, shooting dangerous green bullets. Avoid getting hit.

![Troopers](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/03cc8951-b2c7-452d-9439-bdcb18b9f2ad)


- **Bullets**: Troopers fire green bullets at you.

![Green Bullets](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/1fe45d81-5195-4ae6-9603-9c93905ad2b3)

- **Explosions**: Colliding with Troopers or getting hit by their bullets results in an explosion and losing a life. Defeating Troopers adds to your score.

![Explosion](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/8403bf18-bae7-4577-a4c0-ef15fb2bf217)

## Power-Ups and Loot

 ### **Loot (UFO)** 
 - An UFO named **Loot** appears at the top of the screen.

![Loot](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/57ef1651-1735-460c-bd23-081e7d65c6fc)

 ### **Power-Ups** Loot offers several power-ups:

   #### **Warped Apples**: Magical apples that revive you by adding 5 lives.

![Apple](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/1381e3ab-4067-4694-8787-90cd76849b8a)

   #### **EMC Shield**: An electromagnetic shield that makes you invincible for 10 seconds.

 * Sometimes the EMC won't work because the quality of the shield can be decreased after you shoot loot.

![Shield](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/7713e7b6-3595-4f37-a60c-45b69f598477)

   #### **Apple Shield**: Combines the powers of Warped Apples and EMC Shield.

![Apple Shield](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/d42a96d7-0877-4f32-9dcd-ae08917fa4be)

- Loot can revive himself every 20 seconds after being defeated. He drops one of his items after each defeat, which you can collect and use.

## Player

- **Player**: This is you, the player: You can shoot out 2 type of bullets and also be invincibily, this is **The normal state**:
![Player](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/dcc4ccd7-5e43-4fb2-a625-6d2fe90b2590)

- After being **killed by the enemies**, you will be revived and protected by a **Yellow energy shield** that make you almost **invincible for 3 seconds**, the shield look like this 
![player-protected](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/58ce28df-6ead-49e7-9f93-e9142ad401dd)

- And this the **EMC Shield**
![player-shielded](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/f8fcf4d0-e8d9-4134-a2ca-11b65a83efa2)

- This is player's **Main Bullet**
![laser](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/937821f2-96de-42c7-8561-744981575db3)

- And this is the **Secondary Bullet**
![sphere](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/4e193362-0c25-44b4-8b65-b3871476c384)

## Controls

- **Controls**: Use WASD or Arrow keys to move around, and mouse click to shoot as shown in the image below:

![image_2024-04-26_195415495](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/0717951c-bfec-4417-9697-17ed662ea230)

Take down Loot and other enemies to progress through the game and score points!

## Sources and Download

- If you want to play the game immediately you can download the `SpaceInvader.rar` or If you want to take a look at my **Source code** you can download `Space-Invader-source-code.rar` all in [**This link**]()

### Sources

* **Videos** : 
*   You can watch the [**Game demo video here**](https://youtu.be/3seHq7CD1KE). 
* I learn how to make a game watching videos in [**This channel**](https://youtu.be/k1JGvJU707k?list=PLR7NDiX0QsfQQ2iFXsXepwH46wf3D4Y4C).
* Learn the fundamentals of SDL from: [**LazyFool**](https://lazyfoo.net/tutorials/SDL/)

#### Music

 - [**Star Wars theme**](https://youtu.be/tGsKzZtRwxw)

## Code explaination

- In `ComFun.h` and `ComFun.cpp`:
> - Some global variables to use in Game.cpp
> 
> 

---

Enjoy the game and best of luck in your space adventures!
