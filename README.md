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

![Game Start](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/3e8b251c-3417-4db9-9457-cd10b91ab255)

## In-Game Features

- **Score and Lives**: Your score and remaining lives are displayed at the top of the screen. If you run out of lives, the game ends, and a message box will appear.

- **Timer**: A timer tracks how long you play the game.

![Game Over](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/20840f43-361e-4638-8624-af65180acf13)

- **Enemies: Troopers**: Troopers move in a straight line toward you, shooting dangerous green bullets. Avoid getting hit.

![Troopers](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/03cc8951-b2c7-452d-9439-bdcb18b9f2ad)

- **Bullets**: Troopers fire green bullets at you.

![Green Bullets](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/1fe45d81-5195-4ae6-9603-9c93905ad2b3)

- **Explosions**: Colliding with Troopers or getting hit by their bullets results in an explosion and the loss of a life. Defeating Troopers adds to your score.

![Explosion](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/8403bf18-bae7-4577-a4c0-ef15fb2bf217)

## Power-Ups and Loot

- **Loot (UFO)**: An UFO named **Loot** appears at the top of the screen.

![Loot](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/57ef1651-1735-460c-bd23-081e7d65c6fc)

- **Power-Ups**: Loot offers several power-ups:

    - **Warped Apples**: Magical apples that revive you by adding 5 lives.

![Apple](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/1381e3ab-4067-4694-8787-90cd76849b8a)

    - **EMC Shield**: An electromagnetic shield that makes you invincible for 10 seconds.

![Shield](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/7713e7b6-3595-4f37-a60c-45b69f598477)

        - Sometimes the EMC Shield may not work properly due to the shield's decreased quality after you shoot Loot.

    - **Apple Shield**: Combines the powers of Warped Apples and EMC Shield.

![Apple Shield](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/d42a96d7-0877-4f32-9dcd-ae08917fa4be)

- Loot revives itself every 20 seconds after being defeated. It drops one of its items after each defeat, which you can collect and use.

## Player

- **Player**: This is you, the player:

    - You can shoot two types of bullets and also be invincible at times.

    - This is **the normal state**:
    ![Player](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/dcc4ccd7-5e43-4fb2-a625-6d2fe90b2590)

    - After being **killed by the enemies**, you will be revived and protected by a **yellow energy shield** that makes you almost invincible for 3 seconds. The shield looks like this:

    ![player-protected](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/58ce28df-6ead-49e7-9f93-e9142ad401dd)

    - This is the **EMC Shield**:
    ![player-shielded](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/f8fcf4d0-e8d9-4134-a2ca-11b65a83efa2)

    - This is the player's **main bullet**:
    ![laser](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/937821f2-96de-42c7-8561-744981575db3)

    - This is the **secondary bullet**:
    ![sphere](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/4e193362-0c25-44b4-8b65-b3871476c384)

## Controls

- **Controls**: Use WASD or Arrow keys to move around, and mouse click to shoot as shown in the image below:

![Controls](https://github.com/VnQuynh810/MyFirstGame-SDL2-/assets/161539796/0717951c-bfec-4417-9697-17ed662ea230)

Take down Loot and other enemies to progress through the game and score points!

## Sources and Download

- If you want to play the game immediately, you can download the `SpaceInvader.rar` file and open `Space Invader.exe` to start. The file is available [**here**](https://github.com/VnQuynh810/MyFirstGame-SDL2-/releases/tag/Fist-release).

### Sources

- **Videos**:
    - You can watch the [**game demo video here**](https://youtu.be/pZ5qH2xslNI).
    - I learned how to make a game by watching videos on [**This channel**](https://youtu.be/k1JGvJU707k?list=PLR7NDiX0QsfQQ2iFXsXepwH46wf3D4Y4C).
    - I learned the fundamentals of SDL from: [**LazyFool**](https://lazyfoo.net/tutorials/SDL/).

- **Music**:
    - [**Star Wars theme**](https://youtu.be/tGsKzZtRwxw).

## Code Explanation

- `ComFun.h` and `ComFun.cpp`:
    - Contains global variables to use throughout the program.
    - `bool CheckColli(const SDL_Rect& object1, const SDL_Rect& object2);`: Checks collision between two objects.
    - `SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string path)`: Loads texture to a surface.

- `Game.h` and `Game.cpp`:
    - `bool Game::Init()`: Initializes SDL.
    - `bool Game::LoadResources()`: Loads all game resources.
    - `void Game::Close()`: Frees the memory used by the game.
    - `void Game::Menu()`: Displays the game menu on the screen.
    - `void Game::Run()`: Contains the game's main logic.

- `BaseObj.h` and `BaseObj.cpp`: All objects created in the game are inherited from the `BaseObject` class in these files.
    - `virtual bool LoadImg(std::string path, SDL_Renderer* screen)`: Loads the image onto the renderer.
    - `void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL)`: Renders the object on the screen.

- `Player.h` and `Player.cpp`: Inherits `BaseObj` class, handles player input, and applies power-up effects.
- `Bullet.h` and `Bullet.cpp`: Manages bullet movement.
- `Enemies.h` and `Enemies.cpp`: Initializes enemy bullets and manages their movement.
- `Explosion.h` and `Explosion.cpp`: Manages explosion animations applied to the player.

### Power-ups Code

- `Loot.h` and `Loot.cpp`: Manages the UFO (Loot) movement and appearance.
- `PowerUps.h` and `PowerUps.cpp`

:
    - `void Init(PowerUpType type, SDL_Renderer* screen)`: Checks the current power-up type and loads its image.
    - `void ApplyEffect(Player& player)`: Applies the power-up effects to the player.

### Invincibility

In this code, a boolean variable named `invincible` is used to check if the player is in an invincible state.

```cpp
if (invincible) {
    player1.LoadImg("pic//player-protected.png", gScreen);
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - invincibleTime >= 3000) {
        player1.LoadImg("pic//player.png", gScreen);
        invincible = false; // End the invincibility state after 3 seconds
    }
}
```
`invincible = true` is set after getting hit by an object.

```cpp
bool is_col = CheckColli(player1.GetRect(), ...);
if (is_col && !invincible && ...) {
    ...
    invincible = true;
    invincibleTime = SDL_GetTicks();
    ...
}
```

### Conclusion

- I used a wide range of coding skills, such as classes, pointers, vectors, SDL_image, SDL_ttf, and SDL_mixer.
- I figured out how to create power-ups, player invincibility, and use music and fonts in SDL on my own.

---

Enjoy the game and best of luck in your space adventures!
