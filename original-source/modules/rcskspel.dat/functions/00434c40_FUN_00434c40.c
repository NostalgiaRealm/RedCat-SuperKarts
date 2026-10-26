/*
 * FUN_00434c40 at 00434c40
 * undefined FUN_00434c40(void)
 * Address ranges: 00434c40-00434e4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00434c40(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_28 [40];
  
  iVar1 = FUN_00407cb0(DAT_006a5b60);
  if (iVar1 != -1) {
    (&DAT_0050510c)[iVar1 * 9] = 3;
    *(undefined4 *)(&DAT_00505124 + iVar1 * 0x24) = 0x40000000;
    *(undefined4 *)(param_1 * 0xd0 + 0x48 + DAT_0067ee20) = 0;
  }
  iVar2 = FUN_00407cb0(DAT_006a5b64);
  iVar1 = DAT_0067ee20;
  if (iVar2 != -1) {
    (&DAT_0050510c)[iVar2 * 9] = 3;
    *(undefined4 *)(&DAT_00505124 + iVar2 * 0x24) = 0x40000000;
    *(undefined4 *)(param_1 * 0xd0 + 0x48 + iVar1) = 0;
  }
  FUN_004afce0(s_Entering__>_mesh_damage_collisio_004eba14,param_1);
  if (DAT_006a5b58 == 0) {
    FUN_004afee0(s__s__d___collision_not_active_err_004eba68,
                 s_D__work_rcsk_Code_game_plr_car_c_004eba44,0x78e);
  }
  if (DAT_006a5b5c == 0) {
    FUN_004afce0(s_World_type_collision__004ebb68);
    FUN_004afce0(s_Handling_damage_for_object__d__004ebb80,param_1);
    FUN_004343d0(param_1,&DAT_006a5b58);
    FUN_004afce0(s_Passing_control_to_player_car_co_004ebba0);
    if (DAT_006a5b60 != DAT_0053be28) goto LAB_00434e39;
  }
  else {
    if (DAT_006a5b5c != 1) goto LAB_00434e39;
    FUN_004afce0(s_Object_type_collision__004eba8c);
    FUN_004afce0(s_Struct_object1____d__Struct_obje_004ebaa4,DAT_006a5b60,DAT_006a5b64);
    if (*(code **)(DAT_006a5b60 * 0xd0 + 0x5c + DAT_0067ee20) == FUN_00434c40) {
      FUN_004afce0(s_Handling_damage_for_object1___d__004ebad0,param_1);
      FUN_004343d0(DAT_006a5b60,&DAT_006a5b58);
    }
    if (*(code **)(DAT_006a5b64 * 0xd0 + 0x5c + DAT_0067ee20) == FUN_00434c40) {
      FUN_004afce0(s_Object2_has_collision_function___004ebaf4);
      FUN_00434870(auStack_28,&DAT_006a5b58);
      FUN_004afce0(s_Handling_damage_for_object2___d__004ebb18,DAT_006a5b64);
      FUN_004343d0(DAT_006a5b64,auStack_28);
    }
    FUN_004afce0(s_Passing_control_to_player_car_co_004ebb3c);
    if ((DAT_006a5b60 != DAT_0053be28) && (DAT_006a5b64 != DAT_0053be28)) goto LAB_00434e39;
  }
  FUN_004350b0(DAT_0053be28);
LAB_00434e39:
  FUN_004afce0(s_Returning__004ebbcc);
  return 1;
}

