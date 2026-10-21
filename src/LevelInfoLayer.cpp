#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
using namespace geode::prelude;

static CCLabelBMFont* firstLabel(CCNode* node) {
	return node ? node->getChildByType<CCLabelBMFont>(0) : nullptr;
}

class $modify(EvilLevelInfoLayer, LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) return false;

		// make everything EEVILLLLLLLLLLLLLLLLLLLL
		if (auto difficultySprite = typeinfo_cast<CCSprite*>(this->getChildByID("difficulty-sprite"))) {
			difficultySprite->setColor(ccc3(255, 0, 0));
		}

		// Grandpa Demon mod support
		if (auto grdSprite = typeinfo_cast<CCSprite*>(this->getChildByID("grd-difficulty"))) {
			grdSprite->setColor(ccc3(255, 0, 0));
		}

		auto title = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("title-label"));
		if (title) {
			title->setColor(ccc3(255, 76, 76));
			std::string levelName = title->getString();
			title->setString(("Evil " + levelName).c_str());
		}

		auto creatorMenu = this->getChildByID("creator-info-menu");
		auto user = firstLabel(creatorMenu ? creatorMenu->getChildByID("creator-name") : nullptr);
		if (user) {
			user->setColor(ccc3(205, 0, 0));
			std::string levelUsername = user->getString();
			if (levelUsername.rfind("By ", 0) == 0) {
				levelUsername = levelUsername.substr(3);
			}
			user->setString(("By Evil " + levelUsername).c_str());
		}

		if (auto background = typeinfo_cast<CCSprite*>(this->getChildByID("background"))) {
			background->setColor(ccc3(106, 0, 0));
		}

		if (auto highObjects = this->getChildByID("high-object-indicator")) {
			highObjects->setVisible(false);
		}

		if (auto copy = this->getChildByID("copy-indicator")) {
			copy->setVisible(false);
		}

		if (auto daily = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("daily-label"))) {
			std::string dailyString = daily->getString();
			if (dailyString == "(Daily)") {
				daily->setString("(Devil Daily)");
				daily->setColor(ccc3(165, 0, 0));
				daily->setPosition(238, 259.5f);
			}
			else if (dailyString == "(Weekly)") {
				daily->setString("(Evil Weekly)");
				daily->setColor(ccc3(165, 0, 0));
				daily->setPosition(238, 259.5f);
			}
		}

		return true;
	}
};
