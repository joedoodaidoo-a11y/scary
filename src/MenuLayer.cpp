#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;

class $modify(EvilMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;

		auto evilLabel1 = CCLabelBMFont::create("Evil", "goldFont.fnt");
		evilLabel1->setScale(1.0f);
		evilLabel1->setID("evil-label");
		evilLabel1->setPosition(107.5f, 307.f);
		evilLabel1->setColor(ccc3(106, 0, 0));
		this->addChild(evilLabel1);

		auto evilLabel2 = CCLabelBMFont::create("Evil", "goldFont.fnt");
		evilLabel2->setScale(0.7f);
		evilLabel2->setID("evil-label-2");
		evilLabel2->setPosition(46.5f, 154.f);
		evilLabel2->setColor(ccc3(197, 0, 0));
		this->addChild(evilLabel2);

		if (auto mainTitle = typeinfo_cast<CCSprite*>(this->getChildByID("main-title"))) {
			mainTitle->setColor(ccc3(255, 0, 0));
		}

		if (auto userText = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("player-username"))) {
			userText->setColor(ccc3(197, 0, 0));
		}

		return true;
	}
};
