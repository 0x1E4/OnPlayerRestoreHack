# OnPlayerRestoreHack
Useful for detecting if player use Health/Armour Hack (99% accurate af)

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
