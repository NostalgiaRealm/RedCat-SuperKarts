/*
 * FUN_0040f551 at 0040f551
 * int __cdecl FUN_0040f551(undefined4 param_1)
 * Address ranges: 0040f551-0040f692
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0040f551(undefined4 param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 1:
    if (DAT_00432bfc == -1) {
      if (DAT_00432bf8 == -1) {
        iVar1 = 0;
      }
      else {
        FUN_004015a6((byte *)s_using_unknown_secondary_driver___004330e8);
        iVar1 = DAT_00432bf8 * 0xd8 + DAT_0043d7c8;
      }
    }
    else {
      FUN_004015a6((byte *)s_using_3dfx_driver__d_004330d0);
      iVar1 = DAT_00432bfc * 0xd8 + DAT_0043d7c8;
    }
    break;
  case 2:
    if (DAT_00432bf8 == -1) {
      iVar1 = 0;
    }
    else {
      FUN_004015a6((byte *)s_using_unknown_secondary_driver___004330ac);
      iVar1 = DAT_00432bf8 * 0xd8 + DAT_0043d7c8;
    }
    break;
  case 3:
    if (DAT_00432bfc == -1) {
      iVar1 = 0;
    }
    else {
      FUN_004015a6((byte *)s_using_3dfx_driver__d_00433094);
      iVar1 = DAT_0043d7c8 + DAT_00432bfc * 0xd8;
    }
    break;
  case 4:
    if (DAT_00432c00 == -1) {
      iVar1 = 0;
    }
    else {
      FUN_004015a6((byte *)s_using_user_defined_driver__d_0043310c);
      iVar1 = DAT_00432c00 * 0xd8 + DAT_0043d7c8;
    }
    break;
  default:
    iVar1 = 0;
  }
  return iVar1;
}

