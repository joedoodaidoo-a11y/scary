#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
using namespace geode::prelude;

class $modify(EvilProfilePage, ProfilePage) {
	bool init(int accountID, bool ownProfile) {
		if (!ProfilePage::init(accountID, ownProfile)) return false;

		if (m_usernameLabel) {
			std::string usernameString = m_usernameLabel->getString();
			m_usernameLabel->setString(("Evil " + usernameString).c_str());
		}

		return true;
	}
};
