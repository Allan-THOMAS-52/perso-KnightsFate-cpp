
#include "IngredientA.hpp"

IngredientA::IngredientA(std::string const& name,short int const& level,float const& currentXP
		,float const& sUM,float const& sIM,float const& sIO):Skill(name,level,currentXP,sUM,sIM,sIO){
	setExpNextLevel();

}

void IngredientA::setExpNextLevel(){
	m_expNextLev = m_skillImpMult*(float)pow((float)m_level,1.95) + m_skillImpOffset;
}

void IngredientA::passLevel(){
	if( m_currentExp >= m_expNextLev ){
		m_level++;
		m_currentExp = 0;
		setExpNextLevel();
	}
}

void IngredientA::useSkill(float const& baseXP){
	m_currentExp += m_skillUseMult*(baseXP*m_skillSpecMod);
	passLevel();
}

IngredientA::~IngredientA(){

}
