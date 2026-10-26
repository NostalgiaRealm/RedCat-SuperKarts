/*
 * FUN_00401cf3 at 00401cf3
 * undefined __stdcall FUN_00401cf3(void)
 * Address ranges: 00401cf3-00401e17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401cf3(void)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = 0;
  local_c = DAT_0042c350;
  local_10 = 0;
  local_8 = DAT_0042c354;
  local_24 = 0;
  local_1c = DAT_0042c350;
  local_20 = 0;
  local_18 = DAT_0042c354;
  if (DAT_0042c360 == 0) {
    FUN_004028c2(DAT_00438434);
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                      (DAT_00438434,&local_14,DAT_00438438,&local_24,0x1000000,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042c654);
    }
  }
  else {
    FUN_004028c2(DAT_00438434);
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438434 + 0x2c))(DAT_00438434,0,1);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____error_flipping_surfaces_0042c624);
    }
  }
  return;
}

