#include <a_samp>
#include <YSI\y_bit>

static
	Float:ac_Health,
	Float:ac_Armour,
	BitArray:ac_HeSafe<MAX_PLAYERS>,
	BitArray:ac_ArmSafe<MAX_PLAYERS>
;

forward OnPlayerRestoreHack(playerid, type); //type = type of hacks (1 = health hack / 2 = armour hack)

public OnPlayerSpawn(playerid)
{
	GetPlayerHealth(playerid, ac_Health);
	GetPlayerArmour(playerid, ac_Armour);
	
	Bit_Set(ac_ArmSafe, false);
	Bit_Set(ac_ArmSafe, false);
	
	#if defined asu_OnPlayerSpawn
		asu_OnPlayerSpawn(playerid);
	#endif
	return true;
}

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn asu_OnPlayerSpawn

#if defined asu_OnPlayerSpawn
    forward asu_OnPlayerSpawn(playerid);
#endif

public OnPlayerUpdate(playerid)
{
	static Float:gorengan, Float:bakwan;
	GetPlayerHealth(playerid, gorengan);
        GetPlayerArmour(playerid, bakwan);


    if(PlayerSpawned(playerid))
    {
    		if(gorengan != ac_Health && gorengan > 0)
    		{
    			if(gorengan > ac_Health && !Bit_Get(ac_HeSafe, playerid))
    			{
	            	       CallRemoteFunction("OnPlayerRestoreHack", "ii", playerid, 1);
	            	       Bit_Set(ac_HeSafe, playerid, false);
    			}
    			else
    			{
    				ac_Health = gorengan;
    				Bit_Set(ac_HeSafe, playerid, false);
    			}
    		}
    		else if(bakwan != ac_Armour)
    		{
    			if(bakwan > ac_Armour && !Bit_Get(ac_ArmSafe, playerid))
    			{
	            	        CallRemoteFunction("OnPlayerRestoreHack", "ii", playerid, 2);
	            	        Bit_Set(ac_ArmSafe, playerid, false);
    			}
    			else
    			{
    				ac_Armour = bakwan;
    				Bit_Set(ac_HeSafe, playerid, false);
    			}
		}
    	}
    }
    #if defined asu_OnPlayerUpdate
        asu_OnPlayerUpdate(playerid);
    #endif
    return true;
}

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate asu_OnPlayerUpdate

#if defined asu_OnPlayerUpdate
    forward asu_OnPlayerUpdate(playerid);
#endif

stock asu_SetPlayerHealth(playerid, Float:Health)
{
	GetPlayerHealth(playerid, ac_Health);
	Bit_Set(ac_HeSafe, playerid, true);
	return SetPlayerHealth(playerid, Health);
}

#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif

#define SetPlayerHealth asu_SetPlayerHealth

stock asu_SetPlayerArmour(playerid, Float:Armour)
{
	GetPlayerArmour(playerid, ac_Armour);
	Bit_Set(ac_ArmSafe, playerid, true);
	return SetPlayerArmour(playerid, Armour);
}

#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif

#define SetPlayerArmour asu_SetPlayerArmour

stock PlayerSpawned(playerid)
{
	new pState = GetPlayerState(playerid);
	
	return 0 <= playerid <= MAX_PLAYERS && pState != PLAYER_STATE_NONE && pState != PLAYER_STATE_WASTED && pState != PLAYER_STATE_SPECTATING;
}
