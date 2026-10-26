/*
 * FUN_004035c8 at 004035c8
 * undefined __cdecl FUN_004035c8(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, uint param_6)
 * Address ranges: 004035c8-004037c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_004035c8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,uint param_6)

{
  int iVar1;
  undefined4 local_7c [20];
  uint local_2c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0x1000400;
  local_18 = param_2;
  local_10 = param_4;
  local_14 = param_3;
  local_c = param_5;
  local_7c[0] = 100;
  if ((DAT_0042c358 == 0x10) || (DAT_0042c358 == 0x18)) {
    if (DAT_00438478 == 0) {
      local_2c = param_6;
    }
    else {
      local_2c = FUN_0040de93(param_6,0x18);
    }
  }
  else {
    local_2c = param_6;
  }
  if (param_1 == 0) {
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x14))(DAT_00438434,&local_18,0,0,local_8,local_7c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d680);
    }
  }
  else if (param_1 == 1) {
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x14))(DAT_00438438,&local_18,0,0,local_8,local_7c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d6d8);
    }
  }
  else if (param_1 == 2) {
    FUN_004028c2(DAT_00438418);
    iVar1 = (**(code **)(*DAT_00438418 + 0x14))(DAT_00438418,&local_18,0,0,local_8,local_7c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d6ac);
    }
  }
  return;
}

