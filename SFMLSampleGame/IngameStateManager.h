#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
#include "ICardOperator.h"
#include "BaseCard.h"
#include "IOpponent.h"
#include "EnumScreenFields.h"
#include "ButtonObject.h"
///Class managing the Ingame state of the match
class IngameStateManager : public BaseStateManager, public ICardOperator
{
	///holding sum of user's points, default 0
	int UserSumOfPoints = 0;

	///holding sum of AI's points, default 0
	int EnemySumOfPoints = 0;

	///holding number of lost rounds, default 0
	int RoundsLost = 0;

	///holding number of won rounds, default 0
	int RoundsWon = 0;

	///attritbute used to mark whether the current turn is for player or AI
	bool IsPlayerTurn;

	///Callback for shuffle state manager
	function<void(MatchState)> shuffleCallback;
	
	/// object responsible for functionality of AI
	shared_ptr<IOpponent> opponent;

	///vector holding cards in user's hand
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserHandCards; 

	///vector holding cards in AI's hand
	shared_ptr<vector<shared_ptr<IGuiElement>>> EnemyHandCards;

	///object responsible for managing layout for Play state of the program
	shared_ptr<PlayLayout> Layout;

	///gui element gholding currently selected card, default: no card selected
	shared_ptr<IGuiElement> CurrentSelectedCard = nullptr;

	///vector holding cards in lower user's battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerUserBattleField;

	///vector holding cards in upper user's battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperUserBattleField;

	///vector holding cards in lower Ai's battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerEnemyBattleField;

	///vector holding cards in upper Ai's battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperEnemyBattleField;

	///Rectangle responsible for showing sum of user's points
	shared_ptr<RectangleObject> UserPointsRec;

	///Rectangle responsible for showing sum of AI's points
	shared_ptr<RectangleObject> EnemyPointsRec;

	///Rectangle responsible for showing information about win/lost rounds in the game
	shared_ptr<RectangleObject> RoundsRectangle;

	///Rectangle responsible for showing number of AI's cards in hand
	shared_ptr<RectangleObject> EnemyCardsCounter;

	///Rectangle responsible for showing who's turn is 
	shared_ptr<RectangleObject> TurnDisplayer;

	///@brief method responsible for playing the card, managing the win/lose rules, managing gui elements for ingame state, initiating new rounds and games, clearing hands
	///@param "battlefield" representing value of EnumBattlefield Class
	void PlayCard(BattleField battlefield);

	///@brief method calculating sum of points in appropriate battlefields
	///@param "currentBattleField" vetor of battlefields from which method calculates points
	///@return sum of points for appropriate battlefields
	int CalculateSumOfPoints(shared_ptr<vector<shared_ptr<IGuiElement>>> currentBattleField);
	
	///@brief method used for appropriate placement of cards in given battlefields
	///@param "currentBattleField" used to specify battlefield for wchich cards should be arranged
	///@param "fieldX" used to specify postion x of given net's field (for rowmaker use)
	///@param "fieldX" used to specify postion y of given net's field (for rowmaker use)
	void ArrangeCards(shared_ptr<vector<shared_ptr<IGuiElement>>> currentBattleField, EnumScreenFields fieldX, EnumScreenFields fieldY);

	///@brief method responsibile for initiating new rounds, clearing battlefields, generating new cards for user and AI and arranging thei placement, multithread used for faster generation of cards
	void InitNewRound();

	///@brief method used to create and manage rectangle holding infromation about game status
	///@param "info" representing message to be displayed on rectangle
	void ManageGamesRectangle(string info);

	///@brief method used to create and manage rectangle holding infromation about rounds status
	///@param "info" representing message to be displayed on rectangle
	void ManageRoundsRectangle(string info);
public:

	///@brief method calling Play layout to draw window contents
	virtual void DrawWindowContents() override;

	///@brief constructor initializing gui elements and AI and ascribing appropriate values to the class attributes
	///@param "window" representing program's window
	///@param "currentManager" representing state manager 
	///@param "playLayout" representing play layout of the game
	///@param "userHandCards" vector representing cards in user's hand
	///@param "enemyHandCards" vector representing cards in Ai's hand
	///@param "callbackFunction" representing match state changing callback function
	///@param "roundsRectangle" representing rectangle informing about rounds status
	IngameStateManager(shared_ptr<RenderWindow> window, 
		shared_ptr<IStateOperator<MatchState>> currentManager,
		shared_ptr<PlayLayout> playLayout,
		shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards,
		shared_ptr<vector<shared_ptr<IGuiElement>>> enemyHandCards, function<void(MatchState)> callbackFunction,
		shared_ptr<RectangleObject> roundsRectangle);

	~IngameStateManager();

	///@brief method handling mouse events via Play layout HandleMouseEvent method
	///@param "evnt" parameter describing event type for mouse handling
	virtual void HandleMouseEvent(const Event& evnt) override;

	///@brief method responsible for handling events in Ingame state
	///@param "evnt" parameter describing event type for event handling
	virtual void HandleEvent(const Event& evnt) override;

	///@brief method used to mark current selcted card
	///@param "card" card for which operation should be performed
	///@param "click" parameter for specifying mouse button click 
	void PerformCardOperation(shared_ptr<IGuiElement> card, Mouse::Button click) override;

	///@breif method specyfing in wchich battlefield card should be put
	///@param "battlefield" representing values of EnumBattlefield class 
	virtual void WhichBattlefield(BattleField battlfield) override;
	
	///@brief method organizing gui elements for current state and passing them to layout, arranging cards, managing user's and AI's points,  
	void OrganizeCards();

	///@brief method initializing start of the game
	virtual void initialize() override;

	///@brief method reseting the round won/lost values
	void ResetRoundsScore();

	///@brief method updating text of rectangle informing about round status
	void UpdateRoundsRectangleText();
};

