# OnPlayerTeleport
This include detects a player who uses Teleport hacks, you can do what ever you want underneath OnPlayerTeleport callback, OnPlayerTeleport is called when the include detects a player use teleport hack also can detect if player using fly hack or airbreak.



## Example

```
public OnPlayerRestoreHack(playerid, type)
{
    switch(type)
    {
         case 1:
         {
               SendClientMessage(playerid, -1, "You are banned from server because Health Hack");
               Ban(playerid);
         }
         case 2:
         {
               SendClientMessage(playerid, -1, "You are banned from server because Armour Hack");
               Ban(playerid);
         }
     }
     return 1;
 }
 ```
 
 ## Credits
Y_Less - YSI\y_bit  
Ritzy2K - PlayerSpawned(playerid)
 
