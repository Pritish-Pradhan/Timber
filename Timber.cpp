#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>
void updateBranches(int seed);
using namespace sf;
const int NUM_BRANCHES = 6;
enum class Side{LEFT,RIGHT,NONE};
Side branchPosition[NUM_BRANCHES];
int main(){
	VideoMode vm(1920,1080);
	//VideoMode vm(1080,720);
	//VideoMode vm(960,580);
	//View view(FloatRect(0,0,1920,1080));
	RenderWindow window(vm,"Timber Game!!!!!",Style::Fullscreen);
	//window.setView(view);
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//for background
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0,0);
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//for tree
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810,0);
	//for branch---------------------------------------------------------------------------------------------------------------
	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");
	Sprite spriteBranches[NUM_BRANCHES];
	for(int i = 0; i < NUM_BRANCHES; i++){
		spriteBranches[i].setTexture(textureBranch);
		spriteBranches[i].setPosition(2000,2000);
		spriteBranches[i].setOrigin(220,20);
	} 
	//for Player----------------------------------------------------------------------------------------------------------------------------------
	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/player.png");
	
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(520, 700);
	Side playerSide = Side::LEFT;
	//for RIP---------------------------------------------
		
	Texture textureRIP;
	textureRIP.loadFromFile("graphics/rip.png");
	
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(600, 860);
	//For Axe-----------------------------------------------
	Texture textureAxe;
	textureAxe.loadFromFile("graphics/axe.png");
	
	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(700, 830);
	float AXE_PPOSITION_LEFT=800;
	float AXE_PPOSITION_RIGHT=1040;
	//For llog-----------------------------------------------
	
	Texture textureLog;
	textureLog.loadFromFile("graphics/log.png");
	
	Sprite spriteLog;
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(810, 920);
	//--------------------------------------------------------------------------------------for cloud
	Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");
	Sprite spriteCloud1,spriteCloud2,spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	spriteCloud1.setPosition(0,0);
	spriteCloud2.setPosition(0,150);
	spriteCloud3.setPosition(0,300);
	//--------------------------------------------------------------------------------------------------------------------------------------------------
	//for bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0,800);
	//----------------------------------------------------------------------------
	bool beeActive = false;
	float beeSpeed = 0.0f;
	//-----------------------------------------------------------------------------
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;
	//------------------------------------------------------------------------------
	Clock clock;
	bool paused  = true;
	
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = 1000;
	
	Font font;
	font.loadFromFile("fonts/ariana-violeta-font/ArianaVioleta-dz2K.ttf");
	//------------------------------------------------------------------------------Enter text
	Text messageText;
	messageText.setFont(font);
	messageText.setString("Press Enter to start");
	messageText.setCharacterSize(175);
	messageText.setPosition(900,540);
	messageText.setFillColor(Color::Yellow);
	FloatRect textRect = messageText.getLocalBounds();        //it will return top,left,width,height of messageTextto textRect
	messageText.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	//-------------------------------------------------------------------------------Score
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setString("Score : ");
	scoreText.setCharacterSize(120);
	scoreText.setPosition(20,10);
	//FloatRect textRect2 = scoreText.getLocalBounds();        //it will return top,left,width,height of scoreTextto textRect2
	//scoreText.setOrigin(textRect2.left+textRect2.width/2.0f,textRect2.top+textRect2.height/2.0f);
	scoreText.setFillColor(Color::Red);
	//---------------------------------------------------------------------------------Timer
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth,timeBarHeight));
	timeBar.setPosition(1150-timeBarStartWidth,980);
	timeBar.setFillColor(Color::Red);
	float timeRemaining = 6.0f;
	float timeBarStartWidthPerSecond = timeBarStartWidth/timeRemaining; 
	int score;
	bool acceptInput = false;
	//----------------------------------------------------------------------------------main window logic
	while(window.isOpen()){
		/*updateBranches(1);
		updateBranches(2);
		updateBranches(3);
		updateBranches(4);
		updateBranches(5);
		updateBranches(6);*/
		Event event1;
		while(window.pollEvent(event1)){
			if(event1.type == event1.Closed)
				window.close();
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
		if(Keyboard::isKeyPressed(Keyboard::Return)){//::isKeyPressed is static method (Return:Enter)
			paused = false;
			int score = 0;
			timeRemaining = 6.0f;
			
			
			for(int i=0;i<NUM_BRANCHES;i++){
				branchPosition[i]=Side::NONE;
			}
			spritePlayer.setPosition(600,700);
			spriteRIP.setPosition(680,2000);
		
		}
		acceptInput = true;
		if(acceptInput){
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				playerSide = Side::RIGHT;
				score+=1;
				timeRemaining=timeRemaining+0.15+2/score;
				spriteAxe.setPosition (AXE_PPOSITION_RIGHT,spriteAxe.getPosition().y);
				spritePlayer.setPosition (120,720);
				updateBranches(score);
				
				spriteLog.setPosition (810,720);
				logActive = true;
				acceptInput=false;
				//logSpeedX = 1111;
			}
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				playerSide = Side::LEFT;
				score+=1;
				timeRemaining=timeRemaining+0.15+2/score;
				spriteAxe.setPosition (AXE_PPOSITION_LEFT,AXE_PPOSITION_RIGHT);
				spritePlayer.setPosition (120,720);
				updateBranches(score);
				
				spriteLog.setPosition (810,720);
				logActive = true;
				acceptInput=false;
				//logSpeedX = 1111;
			}
		}
		//-------------------------------------------
		//----------------------------------------------------------for bee
		if(!paused){
			Time dt = clock.restart();
			timeRemaining = timeRemaining - dt.asSeconds();
			timeBar.setSize(Vector2f(timeBarStartWidthPerSecond*timeRemaining,timeBarHeight));
			//---------------------------------------------------------------------------for text "OUT of time"
			if(timeRemaining <= 0.0f){
				paused = true;
				messageText.setString("OUT of Time !!!");
				messageText.setCharacterSize(175);
				messageText.setPosition(900,540);
				messageText.setFillColor(Color::Red);
				FloatRect textRect = messageText.getLocalBounds();        //it will return top,left,width,height of messageTextto textRect
				messageText.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
			}
			if(!beeActive){
				srand((int)time(0));
				beeSpeed = rand()%200 + 200;		//generate number b/w 200 and 399
				
				srand((int)time(0));
				//float height = rand()%500 + 500;
				float height = rand()%960 + 500;
				spriteBee.setPosition(2000,height);
				beeActive = true;	
			}
			else{
				spriteBee.setPosition(spriteBee.getPosition().x - beeSpeed*dt.asSeconds(),spriteBee.getPosition().y);
				if(spriteBee.getPosition().x  < -100){
					beeActive = false;
				}
			}
			//------------------------------------------------------------for cloud1
			if(!cloud1Active){
				srand((int)time(0)*10);
				cloud1Speed = rand()%200+100;		
				
				srand((int)time(0)*10);
				float height = rand()%150;
				spriteCloud1.setPosition(0,0);
				cloud1Active = true;	
			}
			else{
				spriteCloud1.setPosition(spriteCloud1.getPosition().x + cloud1Speed*dt.asSeconds(),spriteCloud1.getPosition().y);
				if(spriteCloud1.getPosition().x  > 2010){
					cloud1Active = false;
				}
			}
			//----------------------------------------------------------------for cloud 2
			if(!cloud2Active){
				srand((int)time(0)*20);
				cloud2Speed = rand()%200+100;		
				
				srand((int)time(0)*20);
				float height = rand()%300 - 150;
				spriteCloud2.setPosition(0,150);
				cloud2Active = true;	
			}
			else{
				spriteCloud2.setPosition(spriteCloud2.getPosition().x + cloud2Speed*dt.asSeconds(),spriteCloud2.getPosition().y);
				if(spriteCloud2.getPosition().x  > 2010){
					cloud2Active = false;
				}
			}
			//------------------------------------------------------------------for cloud3
			if(!cloud3Active){
				srand((int)time(0)*30);
				cloud3Speed = rand()%200+100;		
				
				srand((int)time(0)*30);
				float height = rand()%450 - 150;
				spriteCloud3.setPosition(0,300);
				cloud3Active = true;	
			}
			else{
				spriteCloud3.setPosition(spriteCloud3.getPosition().x + cloud3Speed*dt.asSeconds(),spriteCloud3.getPosition().y);
				if(spriteCloud3.getPosition().x  > 2010){
					cloud3Active = false;
				}
			}
			//------------------------------------------------------------------------update score
			std::stringstream ss;
			ss<<"Score : "<<score;
			scoreText.setString(ss.str());
			for(int i = 0; i < NUM_BRANCHES; i++){
				float height = i*150;
				if(branchPosition[i] == Side::LEFT){
					spriteBranches[i].setPosition(610,height);
					spriteBranches[i].setRotation(180);
				}
				else if(branchPosition[i] == Side::RIGHT){
					spriteBranches[i].setPosition(1330,height);
					spriteBranches[i].setRotation(0);				
				}
				else{
					spriteBranches[i].setPosition(2550,height);
	
				}
			}
			if (logActive) {
				spriteLog.setPosition(spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
					spriteLog.getPosition().y + (logSpeedY * dt.asSeconds()));
				
				//Check if log has reached right/left edge
				if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000) {
					logActive = false;
					spriteLog.setPosition(810, 720);
				}
			}
			if(branchPosition[5] == playerSide){
				paused = true;
				acceptInput = false;
				//hide the player
				spritePlayer.setPosition(2000,720);
				//make RIP visible
				spriteRIP.setPosition(525,760);
				//update the msg text
				messageText.setString("SQUISHED!!!!");
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
				messageText.setPosition(900,540);
			}//end of  play death
		
		}//-------------------------------------------------------------------------------------pause end
		window.clear();
		window.draw(spriteBackground);
		window.draw(spriteTree);
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		window.draw(spritePlayer);
		window.draw(spriteRIP);
		window.draw(spriteAxe);
		window.draw(spriteLog);
		for(int i = 0; i < NUM_BRANCHES;i++){
			window.draw(spriteBranches[i]);
		}
		window.draw(spriteBee);
		if(paused){
			window.draw(messageText);			
		}
		window.draw(scoreText);
		window.draw(timeBar);
		window.display();
	}
	return 0;
}
void updateBranches(int seed){
	for(int j = NUM_BRANCHES-1; j > 0;j--){
		branchPosition[j] = branchPosition[j-1];	
	}
	srand((int)time(0)+ seed);
	int r = rand()%5;
	switch(r){
		case 0 :
			branchPosition[0] = Side::LEFT;
			break;
		case 1 :
			branchPosition[0] = Side::RIGHT;
			break;
		default :
			branchPosition[0] = Side::NONE;
			break;			
	}
}
