#ifndef _INC_CRESOURCE_H
#define _INC_CRESOURCE_H
#pragma once

#include "../common/CAssoc.h"

class CAccount;
class CClient;
class CServerDef;
class CWebPageDef;

typedef CServerDef *CServerRef;

enum OF_TYPE	// option flags
{
	OF_NoDClickTarget			= 0x00001,
	OF_NoSmoothSailing			= 0x00002,
	OF_ScaleDamageByDurability	= 0x00004,
	OF_Command_Sysmsgs			= 0x00008,
	OF_PetSlots					= 0x00010,
	OF_OSIMultiSight			= 0x00020,
	OF_Items_AutoName			= 0x00040,
	OF_FileCommands				= 0x00080,
	OF_NoItemNaming				= 0x00100,
	OF_NoHouseMuteSpeech		= 0x00200,
	OF_MapBoundarySailing		= 0x00800,
	OF_Flood_Protection			= 0x01000,
	OF_Buffs					= 0x02000,
	OF_NoPrefix					= 0x04000,
	OF_DyeType					= 0x08000,
	OF_DrinkIsFood				= 0x10000,
	OF_NoDClickTurn				= 0x20000
};

enum EF_TYPE	// experimental flags
{
	EF_NoDiagonalCheckLOS		= 0x00001,
	EF_DynamicBackgroundSave	= 0x00002,
	EF_ItemStacking				= 0x00004,
	EF_ItemStackDrop			= 0x00008,
	EF_FastWalkPrevention		= 0x00010,
	EF_Intrinsic_Locals			= 0x00020,
	EF_Item_Strict_Comparison	= 0x00040,
	EF_AllowTelnetPacketFilter	= 0x00200,
	EF_Script_Profiler			= 0x00400,
	EF_UsePingServer			= 0x08000,
	EF_FixCanSeeInClosedConts	= 0x20000
};

enum MAGICFLAGS_TYPE
{
	MAGICF_NODIRCHANGE			= 0x0001,	// Not rotate player when casting/targeting
	MAGICF_PRECAST				= 0x0002,	// Precasting (cast spell before target prompt)
	MAGICF_IGNOREAR				= 0x0004,	// Magic damage ignore ar
	MAGICF_CANHARMSELF			= 0x0008,	// Magic can do damage on self
	MAGICF_STACKSTATS			= 0x0010,	// Different stat spells don't cancel each other out
	MAGICF_FREEZEONCAST			= 0x0020,	// No movement whilst casting
	MAGICF_SUMMONWALKCHECK		= 0x0040,	// Summoned creatures should be able to walk on the target location (e.g. water creatures to be summoned on water)
	MAGICF_NOFIELDSOVERWALLS	= 0x0080,	// Field spells cannot cross over blocking objects
	MAGICF_NOANIM				= 0x0100,	// Auto SPELLFLAG_NO_ANIM in every spell
	MAGICF_OSIFORMULAS			= 0x0200,	// Calculate spell damage and duration based on OSI formulas
	MAGICF_NOCASTFROZENHANDS	= 0x0400,	// Can't cast spells if got paralyzed holding something on hands
	MAGICF_POLYMORPHSTATS		= 0x0800,	// Polymorph spells give out stats based on base chars (old behaviour backwards)
	MAGICF_OVERRIDEFIELDS		= 0x1000	// Prevent cast multiple field spells on the same tile, making the new field tile remove the previous field
};

enum REVEALFLAGS_TYPE
{
	REVEALF_DETECTINGHIDDEN		= 0x01,		// Reveal when someone use Detecting Hidden skill
	REVEALF_LOOTINGSELF			= 0x02,		// Reveal when loot self bodies
	REVEALF_LOOTINGOTHERS		= 0x04,		// Reveal when loot others bodies
	REVEALF_SPEAK				= 0x08,		// Reveal when speak
	REVEALF_SPELLCAST			= 0x10		// Reveal when cast spells
};

enum CHATFLAGS_TYPE
{
	CHATF_AUTOJOIN				= 0x01,		// Auto join first static channel available (new chat system: join after client login / old chat system: join after open chat window)
	CHATF_CHANNELCREATION		= 0x02,		// Enable channel creation
	CHATF_CHANNELMODERATION		= 0x04,		// Enable channel moderation (old chat system only)
	CHATF_CUSTOMNAMES			= 0x08,		// Enable custom name selection when open chat window for the first time (old chat system only)
	CHATF_GLOBALCHAT			= 0x10		// Enable global chat system on clients >= 7.0.62.2 (INCOMPLETE)
};

enum RACIALFLAGS_TYPE
{
	RACIALF_HUMAN_STRONGBACK	= 0x001,	// Increase carrying capacity (+60 stones of weight)
	RACIALF_HUMAN_TOUGH			= 0x002,	// Regenerate hitpoints faster (+2 Hit Point Regeneration)
	RACIALF_HUMAN_WORKHORSE		= 0x004,	// Find more resources while gathering hides, ore and lumber
	RACIALF_HUMAN_JACKOFTRADES	= 0x008,	// Skill calculations always consider 20.0 minimum ability on untrained skills
	RACIALF_ELF_NIGHTSIGHT		= 0x010,	// Permanent night sight effect
	RACIALF_ELF_DIFFTRACK		= 0x020,	// Increase difficulty to be tracked while hidden/invisible
	RACIALF_ELF_WISDOM			= 0x040,	// Permanent max mana bonus (+20 Mana Increase)
	RACIALF_GARG_FLY			= 0x080,	// Enable gargoyle fly ability (FEATURE_AOS_UPDATE_B is required to enable gargoyle ability book)
	RACIALF_GARG_BERSERK		= 0x100,	// Increase ferocity in situations of danger (15% Damage Increase + 3% Spell Damage Increase for each 20hp lost)
	RACIALF_GARG_DEADLYAIM		= 0x200,	// Throwing calculations always consider 20.0 minimum ability when untrained
	RACIALF_GARG_MYSTICINSIGHT	= 0x400		// Mysticism calculations always consider 30.0 minimum ability when untrained
};

enum COMBATFLAGS_TYPE
{
	COMBAT_NODIRCHANGE			= 0x0001,	// Not rotate player when fighting (like was in 0.51a)
	COMBAT_FACECOMBAT			= 0x0002,	// Allow faced combat only (recommended)
	COMBAT_PREHIT				= 0x0004,	// Allow prehit for close combat. first hit is instant (delay 0.1sec)
	COMBAT_ELEMENTAL_ENGINE		= 0x0008,	// Use DAM*/RES* to split damage/resist into Physical/Fire/Cold/Poison/Energy (AOS) instead use old AR (pre-AOS)
	COMBAT_MAXITEMDURABILITY	= 0x0010,	// Make damageable items get destroyed when lose max durability instead current durability (OSI-like)
	COMBAT_DCLICKSELF_UNMOUNTS	= 0x0020,	// Unmount horse when dclicking self while in warmode
	COMBAT_ALLOWHITFROMSHIP		= 0x0040,	// Allow attacking opponents from ships
	COMBAT_NOPETDESERT			= 0x0080,	// Allow pet owner attack own pet without make it desert its owner
	COMBAT_ARCHERYCANMOVE		= 0x0100,	// Allow firing bow while moving
	COMBAT_STAYINRANGE			= 0x0200,	// Abort attack swing when out of range instead of waiting to come back in range
	COMBAT_ATTACKONNOTICE		= 0x0400,	// Make target instantly attack back when notice someone trying to attack it
	COMBAT_NPC_NOATTACKMSG		= 0x0800,	// Disable *is attacking* message on NPCs
	COMBAT_STACKARMOR			= 0x1000,	// If a region is covered by more than one armor part, all AR will count
	COMBAT_NOPOISONHIT			= 0x2000	// Disables old (55i like) poisoning style (0~100% chance based on Poisoning skill for monsters, or 50% chance for poisoned weapons)
};

enum TOOLTIPMODE_TYPE
{
	TOOLTIPMODE_SENDFULL		= 0x0,		// Always send full tooltip
	TOOLTIPMODE_SENDVERSION		= 0x1		// Send only tooltip version and wait for client to request full tooltip
};

#define DAMAGE_GOD			0x00001	// Nothing can block this.
#define DAMAGE_HIT_BLUNT	0x00002	// Physical hit of some sort.
#define DAMAGE_MAGIC		0x00004	// Magic blast of some sort. (we can be immune to magic to some extent)
#define DAMAGE_POISON		0x00008	// Or biological of some sort ? (HARM spell)
#define DAMAGE_FIRE			0x00010	// Fire damage of course (some creatures are immune to fire)
#define DAMAGE_ENERGY		0x00020	// lightning.
#define DAMAGE_GENERAL		0x00080	// All over damage. As apposed to hitting just one point.
#define DAMAGE_ACIDIC		0x00100	// damages armor
#define DAMAGE_COLD			0x00200	// cold or water based damage
#define DAMAGE_HIT_SLASH	0x00400	// sword
#define DAMAGE_HIT_PIERCE	0x00800	// spear.
#define DAMAGE_NODISTURB	0x02000	// victim won't be disturbed
#define DAMAGE_NOREVEAL		0x04000	// Attacker is not revealed for this
#define DAMAGE_NOUNPARALYZE	0x08000	// victim won't be unparalyzed
#define DAMAGE_FIXED		0x10000	// already fixed damage, don't do calcs ... only create blood, anim, sounds... and update memories and attacker

typedef DWORD DAMAGE_TYPE;

#define IsSetOF(flags)				(g_Cfg.m_iOptionFlags & flags)
#define IsSetEF(flags)				(g_Cfg.m_iExperimental & flags)
#define IsSetMagicFlags(flags)		(g_Cfg.m_iMagicFlags & flags)
#define IsSetCombatFlags(flags)		(g_Cfg.m_iCombatFlags & flags)

///////////////////////////////////////////////////////////
// CValueRangeDef

struct CValueRangeDef
{
	// Simple linearity

public:
	CValueRangeDef()
	{
		Init();
	}

public:
	INT64 m_iLo;
	INT64 m_iHi;

public:
	void Init()
	{
		m_iLo = LLONG_MIN;
		m_iHi = LLONG_MIN;
	}

	int GetRange() const
	{
		return static_cast<int>(m_iHi - m_iLo);
	}
	int GetLinear(int iPercent) const
	{
		// ARGS: iPercent = 0-1000
		const int iRange = GetRange();
		return static_cast<int>(m_iLo) + IMULDIV(iRange, iPercent, 1000);
	}
	int GetRandom() const
	{
		return static_cast<int>(m_iLo) + Calc_GetRandVal(GetRange());
	}
	int GetRandomLinear(int iPercent) const;

	bool Load(TCHAR *pszDef);
	const TCHAR *Write() const;
};

///////////////////////////////////////////////////////////
// CValueCurveDef

struct CValueCurveDef
{
	// Describe an arbitrary curve.
	// for a range from 0.0 to 100.0 (1000)
	// May be a list of probabilties from 0 skill to 100.0% skill.

public:
	CValueCurveDef() { };

public:
	CGTypedArray<int, int> m_aiValues;		// 0 to 100.0 skill levels

public:
	void Init()
	{
		m_aiValues.Empty();
	}

	int GetLinear(int iSkillPercent) const;
	int GetChancePercent(int iSkillPercent) const;
	int GetRandom() const;
	int GetRandomLinear(int iPercent) const;

	bool Load(TCHAR *pszDef);
	const TCHAR *Write() const;

private:
	CValueCurveDef(const CValueCurveDef &copy);
	CValueCurveDef &operator=(const CValueCurveDef &other);
};

///////////////////////////////////////////////////////////
// CCharRefArray

class CCharRefArray
{
	// List of Players and NPC's involved in the quest/party/account etc..

public:
	static const char *m_sClassName;

	CCharRefArray() { };

private:
	CGTypedArray< CGrayUID, CGrayUID> m_uidCharArray;

public:
	size_t FindChar(const CChar *pChar) const;
	size_t AttachChar(const CChar *pChar);
	size_t InsertChar(const CChar *pChar, size_t i);
	void DetachChar(size_t i);
	size_t DetachChar(const CChar *pChar);
	void DeleteChars();
	void WritePartyChars(CScript &s);

	CGrayUID GetChar(size_t i) const
	{
		return m_uidCharArray[i];
	}
	size_t GetCharCount() const
	{
		return m_uidCharArray.GetCount();
	}

	bool IsCharIn(const CChar *pChar) const
	{
		return (FindChar(pChar) != m_uidCharArray.BadIndex());
	}

	bool IsValidIndex(size_t i) const
	{
		return m_uidCharArray.IsValidIndex(i);
	}
	inline size_t BadIndex() const
	{
		return m_uidCharArray.BadIndex();
	}

private:
	CCharRefArray(const CCharRefArray &copy);
	CCharRefArray &operator=(const CCharRefArray &other);
};

///////////////////////////////////////////////////////////
// CRegionResourceDef

enum RRTRIG_TYPE
{
	// XTRIG_UNKNOWN	= some named trigger not on this list.
	RRTRIG_RESOURCEFOUND = 1,
	RRTRIG_RESOURCEGATHER,
	RRTRIG_RESOURCETEST,
	RRTRIG_QTY
};

class CRegionResourceDef : public CResourceLink
{
	// RES_REGIONRESOURCE
	// When mining/lumberjacking etc. What can we get?

public:
	static const char *m_sClassName;
	static const LPCTSTR sm_szLoadKeys[];
	static const LPCTSTR sm_szTrigName[RRTRIG_QTY + 1];

	explicit CRegionResourceDef(RESOURCE_ID rid);
	virtual ~CRegionResourceDef();

public:
	ITEMID_TYPE m_ReapItem;				// ITEMID_ORE_1 most likely
	CValueCurveDef m_ReapAmount;		// How much can we reap at one time (based on skill)
	CValueCurveDef m_Amount;			// How is here total
	CValueCurveDef m_Skill;				// Skill levels required to mine this.
	CValueCurveDef m_iRegenerateTime;	// TICK_PER_SEC once found how long to regen this type.

public:
	TRIGRET_TYPE OnTrigger(LPCTSTR pszTrigName, CTextConsole *pSrc, CScriptTriggerArgs *pArgs = NULL);
	bool r_LoadVal(CScript &s);
	bool r_WriteVal(LPCTSTR pszKey, CGString &sVal, CTextConsole *pSrc = NULL);

private:
	CRegionResourceDef(const CRegionResourceDef &copy);
	CRegionResourceDef &operator=(const CRegionResourceDef &other);
};

///////////////////////////////////////////////////////////
// CSpellDef

enum SPTRIG_TYPE
{
	SPTRIG_EFFECT = 1,
	SPTRIG_FAIL,
	SPTRIG_SELECT,
	SPTRIG_START,
	SPTRIG_SUCCESS,
	SPTRIG_TARGETCANCEL,
	SPTRIG_QTY
};

class CSpellDef : public CResourceLink	// 1 based spells. See SPELL_*
{
	// RES_SPELL

public:
	static const char *m_sClassName;
	static const LPCTSTR sm_szLoadKeys[];
	static const LPCTSTR sm_szTrigName[SPTRIG_QTY + 1];

	explicit CSpellDef(SPELL_TYPE id);
	virtual ~CSpellDef() { }

private:
	#define SPELLFLAG_DIR_ANIM			0x00000001	// Evoke type cast or directed. (animation)
	#define SPELLFLAG_TARG_ITEM			0x00000002	// Need to target an object
	#define SPELLFLAG_TARG_CHAR			0x00000004	// Needs to target a living thing
	#define SPELLFLAG_TARG_OBJ			(SPELLFLAG_TARG_ITEM|SPELLFLAG_TARG_CHAR)
	#define SPELLFLAG_TARG_XYZ			0x00000008	// Can just target a location.
	#define SPELLFLAG_HARM				0x00000010	// The spell is in some way harmfull.
	#define SPELLFLAG_FX_BOLT			0x00000020	// Effect is a bolt to the target.
	#define SPELLFLAG_FX_TARG			0x00000040	// Effect is at the target.
	#define SPELLFLAG_FIELD				0x00000080	// create a field of stuff. (fire,poison,wall)
	#define SPELLFLAG_SUMMON			0x00000100	// summon a creature.
	#define SPELLFLAG_GOOD				0x00000200	// The spell is a good spell. u intend to help to receiver.
	#define SPELLFLAG_RESIST			0x00000400	// Allowed to resist this.
	#define SPELLFLAG_TARG_NOSELF		0x00000800
	#define SPELLFLAG_DISABLED			0x00008000
	#define SPELLFLAG_SCRIPTED			0x00010000
	#define SPELLFLAG_PLAYERONLY		0x00020000	// casted by players only
	#define SPELLFLAG_NOUNPARALYZE		0x00040000	// casted by players only
	#define SPELLFLAG_NO_CASTANIM		0x00080000	// play no anim while casting (also override SPELLFLAG_DIR_ANIM)
	#define SPELLFLAG_TARG_NO_PLAYER	0x00100000	// if a char may be targetted, it may not be a player
	#define SPELLFLAG_TARG_NO_NPC		0x00200000	// if a char may be targetted, it may not be an NPC
	#define SPELLFLAG_NOPRECAST			0x00400000	// disable precasting for this spell
	#define SPELLFLAG_NOFREEZEONCAST	0x00800000	// disable freeze on cast for this spell
	#define SPELLFLAG_AREA				0x01000000	// area effect (uses local.arearadius)
	#define SPELLFLAG_POLY				0x02000000
	#define SPELLFLAG_TARG_DEAD			0x04000000	// allowed to targ dead chars
	#define SPELLFLAG_DAMAGE			0x08000000	// damage intended
	#define SPELLFLAG_BLESS				0x10000000	// Benefitial spells like Bless, Agility, etc
	#define SPELLFLAG_CURSE				0x20000000	// Curses just like Weaken, Purge Magic, Curse, etc
	#define SPELLFLAG_HEAL				0x40000000	// Healing spell
	DWORD m_dwFlags;

	DWORD m_dwGroup;
	CGString m_sName;

public:
	SOUND_TYPE m_sound;				// What noise does it make when done.
	ITEMID_TYPE m_idSpell;			// The rune graphic for this.
	ITEMID_TYPE m_idScroll;			// The scroll graphic item for this.
	ITEMID_TYPE m_idEffect;			// Animation effect ID
	LAYER_TYPE m_idLayer;			// Where the layer buff/debuff/data is stored.
	WORD m_wManaUse;				// How much mana does it need.
	WORD m_wTithingUse;				// Tithing points required for this spell.

	CValueCurveDef m_CastTime;		// In TICK_PER_SEC.
	CValueCurveDef m_Interrupt;		// Chance to interrupt a spell
	CValueCurveDef m_Effect;		// Damage or effect level based on skill of caster.100% magery
	CValueCurveDef m_Duration;		// Length of effect. in TICK_PER_SEC

	CGString m_sTargetPrompt;		// Targetting prompt (if needed)
	CGString m_sRunes;				// Letter Runes for Words of power.

	CResourceQtyArray m_Reags;		// What reagents does it take ?
	CResourceQtyArray m_SkillReq;	// What skills/unused reagents does it need to cast.

public:
	bool IsSpellType(DWORD dwFlags) const
	{
		return (m_dwFlags & dwFlags);
	}

	LPCTSTR GetName() const
	{
		return m_sName;
	}

	bool r_LoadVal(CScript &s);
	bool r_WriteVal(LPCTSTR pszKey, CGString &sVal, CTextConsole *pSrc);

	bool GetPrimarySkill(int *piSkill = NULL, int *piQty = NULL) const;

private:
	CSpellDef(const CSpellDef &copy);
	CSpellDef &operator=(const CSpellDef &other);
};

///////////////////////////////////////////////////////////
// CRandGroupDef

class CRandGroupDef : public CResourceLink
{
	// A spawn group.
	// RES_SPAWN or RES_REGIONTYPE

public:
	static const char *m_sClassName;
	static const LPCTSTR sm_szLoadKeys[];

	explicit CRandGroupDef(RESOURCE_ID rid) : CResourceLink(rid)
	{
		m_iTotalWeight = 0;
	}
	virtual ~CRandGroupDef() { }

private:
	int m_iTotalWeight;
	CResourceQtyArray m_Members;

public:
	CGString m_sCategory;
	CGString m_sSubsection;
	CGString m_sDescription;

private:
	int CalcTotalWeight();

public:
	virtual bool r_LoadVal(CScript &s);
	virtual bool r_WriteVal(LPCTSTR pszKey, CGString &sVal, CTextConsole *pSrc = NULL);

	CResourceQty GetMember(size_t i) const
	{
		return m_Members[i];
	}
	RESOURCE_ID GetMemberID(size_t i) const
	{
		return m_Members[i].GetResourceID();
	}

	size_t GetRandMemberIndex(CChar *pCharSrc = NULL, bool fTrigger = true) const;
	size_t BadMemberIndex() const
	{
		return m_Members.BadIndex();
	}

private:
	CRandGroupDef(const CRandGroupDef &copy);
	CRandGroupDef &operator=(const CRandGroupDef &other);
};

///////////////////////////////////////////////////////////
// CSkillClassDef

enum STAT_TYPE
{
	// Stats
	STAT_NONE = -1,
	STAT_STR,
	STAT_INT,
	STAT_DEX,
	STAT_FOOD,		// just used as a regen rate (as karma does not decay)
	STAT_BASE_QTY = STAT_FOOD,

	// Notoriety
	STAT_KARMA,		// g_Cfg.m_iMinKarma to g_Cfg.m_iMaxKarma - also used as the food consumption main timer.
	STAT_FAME,		// 0 to g_Cfg.m_iMaxFame
	STAT_QTY
};

const LPCTSTR g_Stat_Name[STAT_QTY + 1] =
{
	"STR",
	"INT",
	"DEX",
	"FOOD",
	"KARMA",
	"FAME",
	NULL
};

class CSkillClassDef : public CResourceLink // For skill def table
{
	// Similar to character class.
	// RES_SKILLCLASS

public:
	static const char *m_sClassName;
	static const LPCTSTR sm_szLoadKeys[];

	explicit CSkillClassDef(RESOURCE_ID rid) : CResourceLink(rid)
	{
		// If there was none defined in scripts
		Init();
	}
	virtual ~CSkillClassDef() { }

public:
	DWORD m_SkillSumMax;
	WORD m_StatSumMax;
	WORD m_SkillLevelMax[SKILL_QTY];
	WORD m_StatMax[STAT_BASE_QTY];
	CGString m_sName;

private:
	void Init();

public:
	bool r_LoadVal(CScript &s);
	bool r_WriteVal(LPCTSTR pszKey, CGString &sVal, CTextConsole *pSrc);

	LPCTSTR GetName() const
	{
		return m_sName;
	}

private:
	CSkillClassDef(const CSkillClassDef &copy);
	CSkillClassDef &operator=(const CSkillClassDef &other);
};

///////////////////////////////////////////////////////////
// CSkillDef

enum SKTRIG_TYPE
{
	// All skills may be scripted.
	// XTRIG_UNKNOWN	= some named trigger not on this list.
	SKTRIG_ABORT = 1,		// Some odd thing went wrong.
	SKTRIG_FAIL,			// We failed the skill check.
	SKTRIG_GAIN,			// Called when there is a chance to gain skill
	SKTRIG_PRESTART,		// Called before any hardcoded messages
	SKTRIG_SELECT,			// Just selecting params for the skill
	SKTRIG_START,			// Params for skill are done. (stroke)
	SKTRIG_STROKE,			// Not really a trigger! Just a stage.
	SKTRIG_SUCCESS,			// We passed the skill check
	SKTRIG_TARGETCANCEL,	// Called when a target cursor is cancelled
	SKTRIG_USEQUICK,		// Called when a 'quick' usage of the skill is made
	SKTRIG_WAIT,			// Called when a test is made to see if the character must wait before starting
	SKTRIG_QTY
};

enum SKF_TYPE
{
	SKF_SCRIPTED	= 0x001,	// Fully scripted, no hardcoded behaviour
	SKF_FIGHT		= 0x002,	// Considered a fight skill, maintains fight active
	SKF_MAGIC		= 0x004,	// Considered a magic skill
	SKF_CRAFT		= 0x008,	// Considered a crafting skill, compatible with MAKEITEM function
	SKF_IMMOBILE	= 0x010,	// Fails skill if character moves
	SKF_SELECTABLE	= 0x020,	// Allows skill to be selected from the skill menu
	SKF_NOMINDIST	= 0x040,	// You can mine, fish, chop, hack on the same point you are standing on
	SKF_NOANIM		= 0x080,	// Prevents hardcoded animation from playing
	SKF_NOSFX		= 0x100,	// Prevents hardcoded sound from playing
	SKF_RANGED		= 0x200,	// Considered a ranged skill (combine with SKF_FIGHT)
	SKF_GATHER		= 0x400,	// Considered a gathering skill, using SkillStrokes as SKF_CRAFT
	SKF_DISABLED	= 0x800		// Disabled skill, can't be used.
};

struct CSkillDef : public CResourceLink
{
	// For skill def table
	// RES_SKILL

public:
	static const LPCTSTR sm_szLoadKeys[];
	static const LPCTSTR sm_szTrigName[SKTRIG_QTY + 1];

	explicit CSkillDef(SKILL_TYPE iSkill);
	virtual ~CSkillDef() { };

private:
	CGString m_sKey;			// script key word for skill.

public:
	CGString m_sName;			// Fancy skill name
	CGString m_sTitle;			// Title one gets if it's your specialty.
	CGString m_sTargetPrompt;	// Targetting prompt (if needed)

	CValueCurveDef m_Delay;		// The base delay for the skill (tenth of seconds)
	CValueCurveDef m_Effect;	// Depends on skill

	CValueCurveDef m_AdvRate;	// ADV_RATE defined "skill curve" 0 to 100 skill levels.
	CValueCurveDef m_Values;	// VALUES= influence for items made with 0 to 100 skill levels.
	int m_GainRadius;			// GAINRADIUS= max. amount of skill above the necessary skill for a task to gain from it
	int m_Range;
	DWORD m_dwFlags;
	DWORD m_dwGroup;

	// Stat effects.
	// You will tend toward these stat vals if you use this skill a lot.
	BYTE m_Stat[STAT_BASE_QTY];			// STAT_STR, STAT_INT, STAT_DEX
	BYTE m_StatPercent;					// BONUS_STATS = % of success depending on stats
	BYTE m_StatBonus[STAT_BASE_QTY];	// % of each stat toward success at skill, total 100

public:
	bool r_LoadVal(CScript &s);
	bool r_WriteVal(LPCTSTR pszKey, CGString &sVal, CTextConsole *pSrc);

	LPCTSTR GetKey() const
	{
		return m_sKey;
	}
	LPCTSTR GetName() const
	{
		return GetKey();
	}

private:
	CSkillDef(const CSkillDef &copy);
	CSkillDef &operator=(const CSkillDef &other);
};

///////////////////////////////////////////////////////////
// CSkillKeySortArray

class CSkillKeySortArray : public CGObSortArray<CValStr *, LPCTSTR>
{
public:
	CSkillKeySortArray() { };

public:
	int CompareKey(LPCTSTR pszKey, CValStr *pVal, bool fNoSpaces) const
	{
		UNREFERENCED_PARAMETER(fNoSpaces);
		ASSERT(pszKey);
		ASSERT(pVal->m_pszName);
		return strcmpi(pszKey, pVal->m_pszName);
	}

private:
	CSkillKeySortArray(const CSkillKeySortArray &copy);
	CSkillKeySortArray &operator=(const CSkillKeySortArray &other);
};

///////////////////////////////////////////////////////////
// CMultiDefArray

struct CMultiDefArray : public CGObSortArray<CGrayMulti *, MULTI_TYPE>
{
	// Store the static components of a IT_MULTI
	// Sorted array
	int CompareKey(MULTI_TYPE id, CGrayMulti *pBase, bool fNoSpaces) const
	{
		UNREFERENCED_PARAMETER(fNoSpaces);
		ASSERT(pBase);
		return id - pBase->GetMultiID();
	}
};

///////////////////////////////////////////////////////////
// CResource

extern class CResource : public CResourceBase
{
	// Script defined resources (not saved in world file)

public:
	static const char *m_sClassName;
	static const CAssocReg sm_szLoadKeys[];

	CResource();
	~CResource();

public:
	CServTime m_timePeriodic;				// When to perform the next periodic update

	// Begin INI file options
	int m_fUseHTTP;
	bool m_fUseAuthID;
	int m_iMapCacheTime;					// Time in sec to keep unused map data.
	int m_iSectorSleepMask;					// The mask for how long sectors will sleep.
	bool m_fUseMapDiffs;					// Whether or not to use map diff files.

	CGString m_sWorldBaseDir;				// "e:\graysvr\worldsave\" = world files go here.
	CGString m_sAcctBaseDir;				// Where do the account files go/come from ?

	bool m_fSecure;							// Secure mode. (will trap exceptions)
	int m_iFreezeRestartTime;				// # seconds before restarting.

#ifdef _DEBUG
	#define DEBUGF_NPC_EMOTE		0x0001
	#define DEBUGF_ADVANCE_STATS	0x0002
	#define DEBUGF_EXP				0x0200	// experience gain/loss
	#define DEBUGF_LEVEL			0x0400	// experience level changes
	#define DEBUGF_SCRIPTS			0x0800	// debug flags for scripts
	#define DEBUGF_LOS				0x1000	// debug flags for AdvancedLOS
	#define DEBUGF_WALK				0x2000	// debug flags for Walking stuff
	#define DEBUGF_PACKETS			0x4000	// log packets to file
	#define DEBUGF_NETWORK			0x8000	// debug flags for networking
	WORD m_wDebugFlags;						// DEBUG In game effects to turn on and off.
#endif

	// Decay
	int m_iDecay_Item;						// Base decay time in minutes.
	int m_iDecay_CorpsePlayer;				// Time for a playercorpse to decay (mins).
	int m_iDecay_CorpseNPC;					// Time for a NPC corpse to decay.

	// Save
	int m_iSaveNPCSkills;					// Only save NPC skills above this
	int m_iSavePeriod;						// Minutes between saves.
	int m_iSaveBackupLevels;				// How many backup levels.
	int m_iSaveBackgroundTime;				// Speed of the background save in minutes.
	unsigned int m_iSaveSectorsPerTick;		// max number of sectors per dynamic background save step
	unsigned int m_iSaveStepMaxComplexity;	// maximum "number of items+characters" saved at once during dynamic background save
	bool m_fSaveGarbageCollect;				// Always force a full garbage collection.

	// Account
	int m_iDeadSocketTime;
	unsigned int m_iClientsMax;				// Maximum (FD_SETSIZE) open connections to server
	int m_iClientsMaxIP;					// Maximum (FD_SETSIZE) open connections to server per IP
	int m_iConnectingMax;					// max clients connecting
	int m_iConnectingMaxIP;					// max clients connecting

	bool m_fAutoAccountCreation;			// Automatically create accounts when client try to login on nonexistent account
	int m_iClientLingerTime;				// How long logged out clients linger in seconds.
	int m_iMinCharDeleteTime;				// How old must a char be ? (minutes)
	BYTE m_iMaxCharsPerAccount;				// Maximum characters allowed on an account.
	bool m_fMd5Passwords;					// Should MD5 hashed passwords be used?

	// Magic
	bool m_fReagentsRequired;
	int m_iWordsOfPowerColor;
	int m_iWordsOfPowerFont;
	bool m_fWordsOfPowerPlayer;				// Words of Power for players
	bool m_fWordsOfPowerStaff;				// Words of Power for staff
	bool m_fEquippedCast;					// Allow casting while equipped.
	bool m_fReagentLossFail;				// ??? Lose reags when failed.
	int m_iMagicUnlockDoor;					// 1 in N chance of magic unlock working on doors -- 0 means never
	int m_iSpellTimeout;					// Length of time (in seconds) for a player to choose a target when casting

	ITEMID_TYPE m_iSpell_Teleport_Effect_NPC;
	SOUND_TYPE m_iSpell_Teleport_Sound_NPC;
	ITEMID_TYPE m_iSpell_Teleport_Effect_Players;
	SOUND_TYPE m_iSpell_Teleport_Sound_Players;
	ITEMID_TYPE m_iSpell_Teleport_Effect_Staff;
	SOUND_TYPE m_iSpell_Teleport_Sound_Staff;

	// Ingame effects
	int m_iLightDay;						// Outdoor light level.
	int m_iLightNight;						// Outdoor light level.
	int m_iLightDungeon;
	int m_iGameMinuteLength;				// Length of the game world minute in real world (TICK_PER_SEC) seconds.
	bool m_fNoWeather;						// Turn off all weather.
	bool m_fCharTags;						// Show [NPC] tags over chars.
	bool m_fVendorTradeTitle;				// Show job title on vendor names.
	bool m_fFlipDroppedItems;				// Flip dropped items.
	WORD m_iItemsMaxAmount;					// Max amount allowed for stackable items.
	bool m_fMonsterFight;					// Will creatures fight amoung themselves.
	bool m_fMonsterFear;					// will they run away if hurt ?
	DWORD m_iBankMaxItems;					// Maximum number of items allowed in bank.
	int m_iBankMaxWeight;					// Maximum weight in stones allowed in bank.
	int m_iBackpackMaxWeight;				// Maximum weight in stones allowed in main backpack.
	int m_iVendorMaxSell;					// Max things a vendor will sell in one shot.
	unsigned int m_iMaxCharComplexity;		// How many chars per sector.
	unsigned int m_iMaxItemComplexity;		// How many items per meter.
	unsigned int m_iMaxSectorComplexity;	// How many items per sector.
	bool m_fGenericSounds;					// Do players receive generic (not them-devoted) sounds
	bool m_fAutoNewbieKeys;					// Are house and boat keys newbied automatically?
	int m_iStamRunningPenalty;				// Weight penalty for running (+N% of max carry weight)
	int m_iStaminaLossAtWeight;				// %Weight at which characters begin to lose stamina
	int m_iHitpointPercentOnRez;			// How many hitpoints do they get when they are rez'd?
	int m_iHitsHungerLoss;					// How many % of HP will loose char on starving
	WORD m_iMaxBaseSkill;					// Maximum value for base skills at char creation
	WORD m_iTrainSkillCost;
	WORD m_iTrainSkillMax;
	int m_iTrainSkillPercent;				// How much can NPC's train up to ?
	int m_fDeadCannotSeeLiving;
	int m_iMediumCanHearGhosts;				// At this Spirit Speak skill level players can understand ghosts speech instead hear 'oOOoO ooO'
	bool m_iMountHeight;					// Do not allow entering under roof being on horse?
	int m_iMoveRate;						// The percent rate of NPC movement
	int m_iArcheryMinDist;
	int m_iArcheryMaxDist;
	int m_iHitsUpdateRate;					// how often send my hits updates to visible clients
	int m_iSpeedScaleFactor;				// fight skill delay = m_iSpeedScaleFactor / ( (dex + 100) * Weapon Speed )
	int m_iCombatArcheryMovementDelay;		// delay (in tenths of second) to start next swing on Archery skill after the char stop moving
	int m_iCombatDamageEra;					// define damage formula to use on physical combat
	int m_iCombatHitChanceEra;				// define hit chance formula to use on physical combat
	int m_iCombatSpeedEra;					// define swing speed formula to use on physical combat
	WORD m_iSkillPracticeMax;				// max skill level a player can practice on dummies/targets upto
	bool m_iPacketDeathAnimation;			// packet 02c

	// Flags for controlling pvp/pvm behaviour of players
	int m_iCombatFlags;						// combat flags
	int m_iMagicFlags;						// magic flags
	int m_iRacialFlags;						// racial traits flags
	int m_iRevealFlags;						// reveal flags used for SPELL_REVEAL (mostly for backwards).

	// Criminal/Karma
	bool m_fAttackingIsACrime;				// Is attacking (even before hitting) a crime?
	bool m_fGuardsInstantKill;				// Will guards kill instantly or follow normal combat rules?
	bool m_fGuardsOnMurderers;				// should guards be only called on criminals ?
	int m_iGuardLingerTime;					// How long do guards linger about.
	int m_iSnoopCriminal;					// 1 in # chance of getting criminalflagged when succesfully snooping.
	bool m_iTradeWindowSnooping;			// 1 means opening a container in trade window needs to use snooping, 0 direct open.
	int m_iMurderMinCount;					// amount of murders before we get title.
	int m_iMurderDecayTime;					// Length of time (in seconds) to decay a murder count
	bool m_fHelpingCriminalsIsACrime;		// If I help (rez, heal, etc) a criminal, do I become one too?
	bool m_fLootingIsACrime;				// Looting a blue corpse is bad.
	int m_iCriminalTimer;					// How many minutes are criminals flagged for?
	int m_iPlayerKarmaNeutral;				// How much bad karma makes a player neutral?
	int m_iPlayerKarmaEvil;					// How much bad karma makes a player evil?
	int m_iMinKarma;						// Minimum karma level
	int m_iMaxKarma;						// Maximum karma level
	int m_iMaxFame;							// Maximum fame level

	// Other
	bool m_fNoResRobe;
	int m_iLostNPCTeleport;
	int m_iExperimental;
	int m_iOptionFlags;
	int m_iWoolGrowthTime;					// Length of time (in minutes) to regen wool on sheep NPCs
	unsigned int m_iAttackerTimeout;		// Length of time (in seconds) for a char to remember his attacker (used for attacker keyword)
	unsigned int m_iNotoTimeout;			// Length of time (in seconds) to cache character on notoriety list
	unsigned int m_iMaxSkill;

	int m_iDistanceWhisper;
	int m_iDistanceYell;

	CGString m_sSpeechSelf;
	CGString m_sSpeechPet;
	CGString m_sSpeechOther;
	CGString m_sCommandTrigger;

	CGString m_sEventsPet;
	CResourceRefArray m_pEventsPetLink;

	CGString m_sEventsPlayer;
	CResourceRefArray m_pEventsPlayerLink;

	CGString m_sEventsRegion;
	CResourceRefArray m_pEventsRegionLink;

	CGString m_sEventsItem;
	CResourceRefArray m_iEventsItemLink;

	// Third-party tools
	CGString m_sStripPath;
	bool m_fCUOStatus;
	bool m_fUOGStatus;

	int m_iWalkBuffer;
	int m_iWalkRegen;

	int m_iCommandLog;

	bool m_fUsecrypt;
	bool m_fUsenocrypt;

	bool m_fPayFromPackOnly;				// Pay only from main pack?
	int m_iOverSkillMultiply;				// Multiplier to get over skillclass
	bool m_fSuppressCapitals;				// Enable/Disable capital letters suppression

	#define ADVANCEDLOS_DISABLED	0x0
	#define ADVANCEDLOS_PLAYER		0x1
	#define ADVANCEDLOS_NPC			0x2
	int m_iAdvancedLos;

	int m_iFeatureT2A;
	int m_iFeatureLBR;
	int m_iFeatureAOS;
	int m_iFeatureSE;
	int m_iFeatureML;
	int m_iFeatureKR;
	int m_iFeatureSA;
	int m_iFeatureTOL;
	int m_iFeatureExtra;

	int m_iMaxLoopTimes;

	#define STAT_FLAG_NORMAL		0x0		// MAX* status allowed (default)
	#define STAT_FLAG_DENYMAX		0x1		// MAX* denied
	#define STAT_FLAG_DENYMAXP		0x2		//		.. for players
	#define STAT_FLAG_DENYMAXN		0x4		//		.. for npcs
	int m_iStatFlag;

	#define NPC_AI_PATH				0x001	// Enable advanced NPC pathfinding engine (this can significantly increase server CPU usage)
	#define NPC_AI_FOOD				0x002	// Enable basic NPC food search (objects + grass) when hungry
	#define NPC_AI_EXTRA			0x004	// Make NPCs human (brain_human) equip/unequip weapons on combat or light sources at night
	#define NPC_AI_ALWAYSINT		0x008	// Make NPC_AI_PATH consider all NPCs as smart as possible to find better paths
	#define NPC_AI_INTFOOD			0x010	// Enable advanced NPC food search (more intelligent and trusworthy) when hungry
	#define NPC_AI_COMBAT			0x040	// Make NPCs cast good spells in his friends while in combat
	#define NPC_AI_LOOTING			0x100	// Make NPCs loot nearby corpses and items on ground
	#define NPC_AI_MOVEOBSTACLES	0x200	// Make NPCs with CAN=mt_usehands able to move items blocking its way
	#define NPC_AI_PERSISTENTPATH	0x400	// Make NPCs try to follow its target even when it is unreachable instead give up
	#define NPC_AI_THREAT			0x800	// Make NPCs select combat target based on highest threat level (damage done) instead closest distance
	int m_iNpcAi;

	// Experience system
	bool m_bExperienceSystem;
	#define EXP_MODE_RAISE_COMBAT	0x01
	#define EXP_MODE_RAISE_CRAFT	0x02
	#define EXP_MODE_ALLOW_DOWN		0x04
	#define EXP_MODE_DOWN_NOLEVEL	0x08
	#define EXP_MODE_AUTOSET_EXP	0x10
	int m_iExperienceMode;
	int m_iExperienceKoefPVP;
	int m_iExperienceKoefPVM;
	bool m_bLevelSystem;
	#define LEVEL_MODE_LINEAR		0
	#define LEVEL_MODE_DOUBLE		1
	int m_iLevelMode;
	unsigned int m_iLevelNextAt;

	bool m_bAutoResDisp;

	char m_cCommandPrefix;

	PLEVEL_TYPE m_iDefaultCommandLevel;

	// Notoriety colors
	HUE_TYPE m_iColorNotoGood;
	HUE_TYPE m_iColorNotoGuildSame;
	HUE_TYPE m_iColorNotoNeutral;
	HUE_TYPE m_iColorNotoCriminal;
	HUE_TYPE m_iColorNotoGuildWar;
	HUE_TYPE m_iColorNotoEvil;
	HUE_TYPE m_iColorNotoInvul;
	HUE_TYPE m_iColorNotoInvulGameMaster;
	HUE_TYPE m_iColorNotoDefault;

	HUE_TYPE m_iColorInvis;
	HUE_TYPE m_iColorInvisSpell;
	HUE_TYPE m_iColorHidden;

	// Notoriety inheritance
	int m_iPetsInheritNotoriety;

	int m_iClientLoginMaxTries;
	int m_iClientLoginTempBan;
	int m_iMaxShipPlankTeleport;

	// Chat system
	CGString m_sChatStaticChannels;
	int m_iChatFlags;

	// MySQL support
	bool m_bMySql;
	CGString m_sMySqlHost;
	CGString m_sMySqlUser;
	CGString m_sMySqlPass;
	CGString m_sMySqlDB;

	// Network settings
	unsigned int m_iNetworkThreads;			// number of network threads to create
	unsigned int m_iNetworkThreadPriority;	// priority of network threads
	int m_fUseAsyncNetwork;					// 0=normal send, 1=async send, 2=async send for 4.0.0+ only
	int m_iNetMaxPings;						// max pings before blocking an ip
	int m_iNetHistoryTTL;					// time to remember an ip
	int m_iNetMaxPacketsPerTick;			// max packets to send per tick (per queue)
	unsigned int m_iNetMaxLengthPerTick;	// max packet length to send per tick (per queue) (also max length of individual packets)
	int m_iNetMaxQueueSize;					// max packets to hold per queue (comment out for unlimited)
	bool m_fUsePacketPriorities;			// true to prioritise sending packets
	bool m_fUseExtraBuffer;					// true to queue packet data in an extra buffer

	int m_iTooltipCache;
	int m_iTooltipMode;

	int m_iRegenRate[STAT_QTY];
	int m_iTimerCall;
	bool m_bAllowLightOverride;
	CGString m_sZeroPoint;
	bool m_bAllowBuySellAgent;

	bool m_NPCNoFameTitle;

	int m_iMaxPolyStats;

	// End INI file options.

	CResourceScript m_scpIni;						// Keep this around so we can link to it
	CResourceScript m_scpCryptIni;					// Encryption keys are in here

public:
	CResourceScript m_scpTables;

	CStringSortArray m_ResourceList;				// Sections lists

	CStringSortArray m_Obscene;						// Bad Names/Words etc.
	CGObArray<CGString *> m_Fame;					// fame titles (fame.famous)
	CGObArray<CGString *> m_Karma;					// karma titles (karma.wicked)
	CGObArray<CGString *> m_Runes;					// Words of power. (A-Z)

	CGTypedArray<int, int> m_NotoKarmaLevels;		// karma levels for noto titles
	CGTypedArray<int, int> m_NotoFameLevels;		// fame levels for noto titles
	CGObArray<CGString *> m_NotoTitles;				// Noto titles.

	CMultiDefArray m_MultiDefs;						// read from the MUL files. Cached here on demand.

	CObNameSortArray m_SkillNameDefs;				// const CSkillDef* Name sorted
	CGPtrTypeArray<CSkillDef *> m_SkillIndexDefs;	// Defined Skills indexed by number
	CGObArray<CSpellDef *> m_SpellDefs;				// Defined Spells
	CGPtrTypeArray<CSpellDef *> m_SpellDefs_Sorted;	// Defined Spells, in skill order

	CStringSortArray m_PrivCommands[PLEVEL_QTY];	// what command are allowed for a priv level?

public:
	CObNameSortArray m_Servers;						// Servers list. we act like the login server with this.
	CObNameSortArray m_Functions;					// subroutines that can be used in scripts.
	CResourceHashArray m_WebPages;					// These can be linked back to the script.
	CRegionLinks m_RegionDefs;

	// static definition stuff from *TABLE.SCP mostly.
	CGObArray<const CStartLoc *> m_StartDefs;
	CValueCurveDef m_StatAdv[STAT_BASE_QTY];
	CGTypedArray<CPointBase, CPointBase &> m_MoonGates;

private:
	RESOURCE_ID ResourceGetNewID(RES_TYPE restype, LPCTSTR pszName, CVarDefContNum **ppVarNum, bool fNewStyleDef);

public:
	bool r_LoadVal(CScript &s);
	bool r_WriteVal(LPCTSTR pszKey, CGString &sVal, CTextConsole *pSrc);
	bool r_GetRef(LPCTSTR &pszKey, CScriptObj *&pRef);

	bool LoadIni();
	bool Load(bool fResync);
	void Unload(bool fResync);
	void OnTick(bool fNow);

	bool LoadResourceSection(CScript *pScript);
	void LoadSortSpells();
	CResourceDef *ResourceGetDef(RESOURCE_ID_BASE rid) const;

	// Specialized resource accessors.

	bool CanUsePrivVerb(const CScriptObj *pObjTarg, LPCTSTR pszCmd, CTextConsole *pSrc) const;
	PLEVEL_TYPE GetPrivCommandLevel(LPCTSTR pszCmd) const;

	static STAT_TYPE FindStatKey(LPCTSTR pszKey);
	bool IsObscene(LPCTSTR pszText) const;

	CWebPageDef *FindWebPage(LPCTSTR pszPath) const;

	CServerRef Server_GetDef(size_t index);

	const CSpellDef *GetSpellDef(SPELL_TYPE spell) const
	{
		if ( (spell == SPELL_NONE) || !m_SpellDefs.IsValidIndex(static_cast<size_t>(spell)) )
			return NULL;
		return m_SpellDefs[static_cast<size_t>(spell)];
	}
	CSpellDef *GetSpellDef(SPELL_TYPE spell)
	{
		if ( (spell == SPELL_NONE) || !m_SpellDefs.IsValidIndex(static_cast<size_t>(spell)) )
			return NULL;
		return m_SpellDefs[static_cast<size_t>(spell)];
	}

	LPCTSTR GetSkillKey(SKILL_TYPE skill) const
	{
		if ( (skill == SKILL_NONE) || !m_SkillIndexDefs.IsValidIndex(static_cast<size_t>(skill)) )
			return NULL;
		return m_SkillIndexDefs[static_cast<size_t>(skill)]->GetKey();
	}

	bool IsSkillFlag(SKILL_TYPE skill, SKF_TYPE flags) const
	{
		const CSkillDef *pSkillDef = GetSkillDef(skill);
		return (pSkillDef && (pSkillDef->m_dwFlags & flags));
	}

	const CSkillDef *GetSkillDef(SKILL_TYPE skill) const
	{
		if ( (skill == SKILL_NONE) || !m_SkillIndexDefs.IsValidIndex(static_cast<size_t>(skill)) )
			return NULL;
		return m_SkillIndexDefs[static_cast<size_t>(skill)];
	}

	CSkillDef *GetSkillDef(SKILL_TYPE skill)
	{
		if ( (skill == SKILL_NONE) || !m_SkillIndexDefs.IsValidIndex(static_cast<size_t>(skill)) )
			return NULL;
		return m_SkillIndexDefs[static_cast<size_t>(skill)];
	}

	const CSkillDef *FindSkillDef(LPCTSTR pszKey) const
	{
		// Find the skill name in the alpha sorted list
		size_t i = m_SkillNameDefs.FindKey(pszKey);
		if ( i == m_SkillNameDefs.BadIndex() )
			return NULL;
		return static_cast<const CSkillDef *>(m_SkillNameDefs[i]);
	}
	const CSkillDef *SkillLookup(LPCTSTR pszKey);
	SKILL_TYPE FindSkillKey(LPCTSTR pszKey) const;

	int GetSpellEffect(SPELL_TYPE spell, int iSkillval) const;

	LPCTSTR GetRune(TCHAR ch) const
	{
		size_t index = static_cast<size_t>(toupper(ch)) - 'A';
		if ( !m_Runes.IsValidIndex(index) )
			return "?";
		return m_Runes[index]->GetPtr();
	}

	LPCTSTR GetNotoTitle(int index, bool fFemale) const;

	const CGrayMulti *GetMultiItemDefs(CItem *pItem);
	const CGrayMulti *GetMultiItemDefs(ITEMID_TYPE itemid);

	bool IsConsoleCmd(TCHAR ch) const;

	CPointMap GetRegionPoint(LPCTSTR pszCmd) const;		// Decode a teleport location number into X/Y/Z
	CRegionBase *GetRegion(LPCTSTR pszKey) const;		// Find a region with the given name/defname

	int Calc_MaxCarryWeight(const CChar *pChar) const;
	int Calc_CombatAttackSpeed(CChar *pChar, CItem *pWeapon);
	int Calc_CombatChanceToHit(CChar *pChar, CChar *pCharTarg);
	int Calc_StealingItem(CChar *pCharThief, CItem *pItem, CChar *pCharMark);
	bool Calc_CrimeSeen(CChar *pCharThief, CChar *pCharViewer, SKILL_TYPE SkillToSee, bool fBonus);
	int Calc_FameKill(CChar *pKill);
	int Calc_KarmaKill(CChar *pKill, NOTO_TYPE NotoThem);
	int Calc_KarmaScale(int iKarma, int iKarmaChange);
	LPCTSTR Calc_MaptoSextant(CPointMap pt);

	#define SysMessageDefault(pszKey)		SysMessage(g_Cfg.GetDefaultMsg(pszKey))
	LPCTSTR GetDefaultMsg(LPCTSTR pszKey);
	LPCTSTR GetDefaultMsg(int iKeyNum);

	typedef std::map<DWORD, DWORD> KRGumpsMap;
	KRGumpsMap m_mapKRGumps;

	bool SetKRDialogMap(DWORD rid, DWORD dwKRDialogID);
	DWORD GetKRDialogMap(DWORD dwKRDialogID);
	DWORD GetKRDialog(DWORD rid);

	bool GenerateDefname(TCHAR *pszObjectName, size_t iInputLength, LPCTSTR pszPrefix, TCHAR *pszOutput, bool fCheckConflict = true, CVarDefMap *vDefnames = NULL);
	bool DumpUnscriptedItems(CTextConsole *pSrc, LPCTSTR pszFilename);

private:
	CResource(const CResource &copy);
	CResource &operator=(const CResource &other);
} g_Cfg;

///////////////////////////////////////////////////////////
// CDialogDef

class CDialogDef : public CResourceLink
{
public:
	static const char *m_sClassName;
	static const LPCTSTR sm_szLoadKeys[];

	explicit CDialogDef(RESOURCE_ID rid);
	virtual ~CDialogDef() { };

public:
	// Temporary placeholders (valid only during dialog setup)
	size_t m_iControls;
	size_t m_iTexts;
	CObjBase *m_pObj;
	int m_x;
	int m_y;
	int m_iOriginX;		// Keep track of position when parsing
	int m_iOriginY;
	WORD m_iPage;		// Page to open the dialog in
	bool m_bNoDispose;	// Contains 'nodispose' control

	CGString m_sControls[1024];
	CGString m_sText[512];

public:
	bool GumpSetup(int iPage, CClient *pClientSrc, CObjBase *pObj, LPCTSTR pszArguments = "");
	size_t GumpAddText(LPCTSTR pszText);		// Add text to the text section, return insertion index

	bool r_LoadVal(CScript &s);
	bool r_WriteVal(LPCTSTR pszKey, CGString &sVal, CTextConsole *pSrc);
	bool r_Verb(CScript &s, CTextConsole *pSrc);

private:
	CDialogDef(const CDialogDef &copy);
	CDialogDef &operator=(const CDialogDef &other);
};

///////////////////////////////////////////////////////////
// CItemTypeDef

class CItemTypeDef : public CResourceLink
{
public:
	static const char *m_sClassName;

	explicit CItemTypeDef(RESOURCE_ID rid) : CResourceLink(rid) { }

public:
	int GetItemType() const;
	bool r_LoadVal(CScript &s);

private:
	CItemTypeDef(const CItemTypeDef &copy);
	CItemTypeDef &operator=(const CItemTypeDef &other);
};

#endif	// _INC_CRESOURCE_H
