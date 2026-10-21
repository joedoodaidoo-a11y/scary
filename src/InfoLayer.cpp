#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>
using namespace geode::prelude;

class $modify(EvilInfoLayer, InfoLayer) {
	bool init(GJGameLevel* level, GJUserScore* score, GJLevelList* list) {
		if (!InfoLayer::init(level, score, list)) return false;

		if (auto title = typeinfo_cast<CCLabelBMFont*>(this->getChildByIDRecursive("title-label"))) {
			std::string levelName = title->getString();
			title->setString(("Evil " + levelName).c_str());
		}

		auto creatorButton = this->getChildByIDRecursive("creator-button");
		auto user = creatorButton ? creatorButton->getChildByType<CCLabelBMFont>(0) : nullptr;
		if (user) {
			std::string levelUsername = user->getString();
			if (levelUsername.rfind("By ", 0) == 0) {
				levelUsername = levelUsername.substr(3);
			}
			user->setString(("By Evil " + levelUsername).c_str());
		}

		return true;
	}
};
